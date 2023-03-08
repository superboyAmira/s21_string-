#include "s21_sprintf.h"

/*
main part sprintf.c
*/

int s21_sprintf(char *str, const char *format, ...) {
  s21_variety flags = {0};
  va_list(input);
  va_start(input, format);
  int cnt = 0;

  while (*format) {
    if (*format != '%') {
      *str++ = *format++;
      cnt++;
      continue;
    } else {
      format++;
      s21_memset(&flags, 0, sizeof(flags));
    }

    // parser
    format = parser_flags(&flags, format);
    format = parser_width(&flags, format);
    format = parser_precision(&flags, format);
    format = parser_lenght(&flags, format);
    // output
    flags.opt = *format;  // opt = 'c', 'd' etc...
    format++;
    char tmp[BUFF_SIZE] = {'\0'};

    parser_options(&flags, tmp, input);

    for (int i = 0; tmp[i] != '\0'; i++, str++) {
      *str = tmp[i];  // tmp -> str
      cnt++;
    }
    if (flags.opt == 'n') {
      int *res = va_arg(input, int *);
      *res = cnt;
    }
  }
  *str = '\0';
  va_end(input);
  return cnt;
}

/*
parse func
*/

const char *parser_flags(s21_variety *flags, const char *format) {
  while (*format == '-' || *format == '+' || *format == ' ') {
    switch (*format) {
      case '-':
        flags->flag_minus = true;
        break;
      case '+':
        flags->flag_plus = true;
        break;
      case ' ':
        flags->flag_space = true;
        break;
    }
    format++;
  }
  return format;
}

const char *parser_width(s21_variety *flags, const char *format) {
  char char_width[BUFF_SIZE] = {'\0'};

  if (s21_isdigit(*format)) {
    for (int cnt = 0; s21_isdigit(*format); cnt++, format++)
      char_width[cnt] = *format;
    flags->width = s21_atoi(char_width);
  }
  return format;
}

const char *parser_precision(s21_variety *flags, const char *format) {
  char char_precision[BUFF_SIZE] = {'\0'};
  if (*format == '.') {
    flags->precision_flag = 1;
    format++;
    if (s21_isdigit(*format)) {
      for (int cnt = 0; s21_isdigit(*format); cnt++, format++)
        char_precision[cnt] = *format;
      flags->precision = s21_atoi(char_precision);
    }
  }
  return format;
}

const char *parser_lenght(s21_variety *flags, const char *format) {
  while (*format == 'l' || *format == 'h') {
    switch (*format) {
      case 'l':
        flags->length = 'l';
        format++;
        break;
      case 'h':
        flags->length = 'h';
        format++;
        break;
    }
  }
  return format;
}

void parser_options(s21_variety *flags, char *tmp, va_list input) {
  switch (flags->opt) {
    case 'c':
      output_c(flags, tmp, input);
      break;
    case 'd':
    case 'i':
      output_d_i(flags, tmp, input);
      break;
    case 'f':
      output_f_lf(flags, tmp, input);
      break;
    case 's':
      output_s(flags, tmp, input);
      break;
    case 'u':
      output_u(flags, tmp, input);
      break;
    case '%':
      tmp[0] = '%';
      break;
    default:
      break;
  }
}

/*
output func
*/

void output_c(s21_variety *flags, char *tmp, va_list input) {
  if (flags->length == 'l') {  // https://russianblogs.com/article/174835879/
    wchar_t param = va_arg(input, wchar_t);
    if (flags->width > 0 && !flags->flag_minus) {
      for (int i = 0; i < flags->width; i++) {
        tmp[i] = ' ';
      }
      tmp[s21_strlen(tmp) - 1] = param;
    } else if (flags->flag_minus && flags->width) {
      tmp[0] = param;
      for (int i = s21_strlen(tmp); i < flags->width; i++) tmp[i] = ' ';
    } else {
      tmp[0] = param;
    }
  } else {
    char param = (char)va_arg(input, int);  // https://ru.manpages.org/va_arg/3
    if (flags->width > 0 && !flags->flag_minus) {
      for (int i = 0; i < flags->width; i++) {
        tmp[i] = ' ';
      }
      tmp[s21_strlen(tmp) - 1] = param;

    } else if (flags->flag_minus && flags->width) {
      tmp[0] = param;
      for (int i = 1; i < flags->width; i++) tmp[i] = ' ';
    } else {
      tmp[0] = param;
    }
  }
}

void output_d_i(s21_variety *flags, char *tmp, va_list input) {
  int64_t param = va_arg(input, int64_t);
  if (flags->length == 'h') {
    param = (int16_t)param;
  } else if (flags->length != 'l') {
    param = (int32_t)param;
  }
  s21_itoa_decimal(param, tmp, 0);
  add_precision(tmp, flags);
  add_flags(flags, tmp);
}

void add_precision(char *tmp, s21_variety *flags) {
  char t[BUFF_SIZE] = {'\0'};

  int start = 0;
  int length = s21_strlen(tmp);

  if (tmp[0] == '-') {
    t[0] = '-';
    length--;
    start = 1;
  }

  if (flags->precision > length) {
    for (int i = start; i < flags->precision - length + start; i++) {
      t[i] = '0';
    }
    s21_strncat(t, &tmp[start], s21_strlen(t) - 1);
    for (int i = 0; i < (int)s21_strlen(t); i++) {
      tmp[i] = t[i];
    }
  }
}

void add_flags(s21_variety *flags, char *tmp) {
  bool minus = false;
  char t[BUFF_SIZE] = {'\0'};
  if (flags->flag_plus) {  // +
    if (tmp[0] == '-') {
      t[0] = tmp[0];
      minus = true;
    } else {
      t[0] = '+';
    }
    s21_strcpy(t + 1, (minus) ? tmp + 1 : tmp);
    s21_strcpy(tmp, t);
  } else if (flags->flag_space && tmp[0] != '-') {  // " "
    t[0] = ' ';
    s21_strcpy(t + 1, tmp);
    s21_strcpy(tmp, t);
  }

  if (flags->width > (int)s21_strlen(tmp)) {
    int idx = flags->width - s21_strlen(tmp);
    if (!flags->flag_minus) {
      s21_memset(t, ' ', idx);
      s21_strcpy(t + idx, tmp);
    } else {
      s21_strcpy(t, tmp);
      s21_memset(t + s21_strlen(t), ' ', idx);
    }
    s21_strcpy(tmp, t);
  }
}

void output_f_lf(s21_variety *flags, char *tmp, va_list input) {
  double param = va_arg(input, double);

  if (flags->precision == 0 && flags->precision_flag == 0) flags->precision = 6;
  s21_dtoa(param, tmp, 0, flags);
  add_flags(flags, tmp);
}

void output_s(s21_variety *flags, char *tmp, va_list input) {
  if (flags->length == 'l') {
    wchar_t *param = va_arg(input, wchar_t *);
    int len = s21_mblen(param);
    wchar_t col[BUFF_SIZE] = {'\0'};
    if (flags->precision_flag) {  // .num
      if (len > flags->precision) {
        for (int i = 0; i < flags->precision; i++) col[i] = param[i];
      } else {
        for (int i = 0; i < len; i++) {
          col[i] = param[i];
        }
      }
      s21_wctomb(tmp, col, len, 0);
      // strcat(tmp,col);
    } else if (flags->width > len) {  // num or -num
      if (!flags->flag_minus) {
        for (int i = 0; i < flags->width - len; i++) {
          tmp[i] = ' ';
        }
        // strncat(tmp, (char *)param, flags->width - 1);
        s21_wctomb(tmp, param, len, flags->width - 1);
      } else {
        s21_wctomb(tmp, param, len, 0);
        // strcat(tmp, (char *)param);
        for (int i = len; i < flags->width; i++) {
          tmp[i] = ' ';
        }
      }
    } else {
      s21_wctomb(tmp, param, len, 0);
      // strcat(tmp, (char *)param);
    }
  } else {
    char *param = va_arg(input, char *);
    int len = s21_strlen(param);
    char col[BUFF_SIZE] = {'\0'};

    if (flags->precision_flag) {  // .num
      if (len > flags->precision) {
        for (int i = 0; i < flags->precision; i++) col[i] = param[i];
      } else {
        for (int i = 0; i < len; i++) {
          col[i] = param[i];
        }
      }
      s21_strcat(tmp, col);
    } else if (flags->width > len) {  // num or -num
      if (!flags->flag_minus) {
        for (int i = 0; i < flags->width - len; i++) {
          tmp[i] = ' ';
        }
        s21_strncat(tmp, param, flags->width - 1);
      } else {
        s21_strcat(tmp, param);
        for (int i = len; i < flags->width; i++) {
          tmp[i] = ' ';
        }
      }
    } else {
      s21_strcat(tmp, param);
    }
  }
}

void output_u(s21_variety *flags, char *tmp, va_list input) {
  if (flags->length == 'h') {
    short unsigned int param = (short unsigned int)va_arg(input, int);
    s21_utoa(param, tmp, 0);
    add_precision(tmp, flags);
  } else if (flags->length == 'l') {
    long unsigned int param = va_arg(input, long unsigned int);
    s21_utoa(param, tmp, 0);
    add_precision(tmp, flags);
  } else {
    unsigned int param = va_arg(input, unsigned int);
    s21_utoa(param, tmp, 0);
    add_precision(tmp, flags);
    add_flags(flags, tmp);
  }
}

/*
help func
*/

int s21_atoi(char *num) {
  int res = 0;
  int sign = 1;
  int overflow = 0;

  while (*num == ' ') num++;

  if (*num == '-') {
    num++;
    sign = -1;
  }

  if (*num == '+') {
    num++;
  }

  while (*num && *num >= '0' && *num <= '9') {
    res = res * 10 + (*num - '0');
    if (res < 0) {
      overflow = 1;
      break;
    }
    num++;
  }
  if (overflow)
    res = (sign > 0) ? INT32_MAX : INT32_MIN;
  else
    res *= sign;

  return res;
}

void s21_itoa_decimal(int64_t num, char *str, s21_size_t place) {
  if (num == 0) {
    str[place++] = '0';
    str[place] = '\0';
  } else {
    if (num < 0) {
      str[place++] = '-';
      num = -num;
    }
    for (int64_t divider = pow(10, cnt_digit_int(num) - 1); divider > 0;
         divider /= 10) {
      str[place++] = "0123456789"[num / divider];
      num %= divider;
    }
  }
}

void s21_dtoa(double num, char *str, s21_size_t place, s21_variety *flags) {
  long double fl_int = 0.0;
  long double fl_fract = modfl(
      num,
      &fl_int);  // разбивает число на целую и дробную части;
                 // целая часть помещается в left; возвращается дробная часть
  long int int_fract = (long int)round(fl_fract * powl(10, flags->precision));
  long int accuracy = (long int)powl(10, flags->precision - 1);

  s21_itoa_decimal((int)fl_int, str, place);
  s21_size_t length_str = s21_strlen(str);
  s21_strncat(str, ".", length_str);

  if (num != 0.0) {
    if (flags->precision == 0 && flags->precision_flag == 1) {
      str[length_str] = '\0';
    } else {
      for (int i = length_str + 1;
           i < (int)(length_str + 1 + flags->precision) || accuracy != 0 ||
           int_fract != 0;
           i++) {
        if (accuracy == 0) {
          break;
        }
        if ((int_fract / accuracy) == 0) {
          str[i] = '0';
        } else {
          str[i] = "0123456789"[int_fract / accuracy];
        }
        int_fract %= accuracy;
        accuracy /= 10;
      }
    }
  } else {
    if (flags->precision == 0 && flags->precision_flag == 1) {
      str[length_str] = '\0';
    } else {
      for (int i = length_str + 1; i < (int)(length_str + 1 + flags->precision);
           i++) {
        str[i] = '0';
      }
    }
  }
}

void s21_utoa(long long int num, char *str, s21_size_t place) {
  if (num == 0) {
    str[place++] = '0';
    str[place] = '\0';
  } else {
    for (long int divider = pow(10, cnt_digit_int(num) - 1); divider > 0;
         divider /= 10) {
      str[place++] = "0123456789"[num / divider];
      num %= divider;
    }
  }
}

long long int cnt_digit_int(long long int num) {
  long long int result = 0;
  if (num / 10 == 0) {
    result = 1;
  } else {
    while (num > 0) {
      num /= 10;
      result++;
    }
  }
  return result;
}

int s21_isdigit(char c) { return (c >= '0' && c <= '9'); }

s21_size_t s21_mblen(wchar_t *buff) {
  s21_size_t result = 0;
  while (*buff != '\0') {
    buff++;
    result++;
  }
  return result;
}

void s21_wctomb(char *dest, wchar_t *wsrc, int len, int place) {
  for (int i = place; i < (int)(len + s21_strlen(dest)); i++) {
    dest[i] = *wsrc++;
  }
}

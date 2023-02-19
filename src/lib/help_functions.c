#include "s21_string.h"

char *s21_itoa_decimal(int num, char *str, int place) { // convert int to string with radix 10
    bool isNegative = false;
    char num_string[BUFF_SIZE];
    int k = 0;

    if (num == 0) {
        str[place++] = '0';
        str[place] = '\0';
    } else {
        if (num < 0) {
            isNegative = true;
            num = -num;
        }

        while (num != 0) {
            int rem = 10;
            num_string[k++] = "0123456789"[num % rem];
            num /= 10;
        }
        if (isNegative) {
            num_string[k++] = '-';
        }

        s21_reverse(num_string, k);
        num_string[k] = '\0';
    }
    strcat(str, num_string);
    return str;
}

void s21_reverse(char string[], int length) {
    int start = 0;
    int end = length -1;
    char tmp[length];

    for (int i = 0; i < length; i++) {
        tmp[i] = string[i];
    }
    while (start < length) {
        string[start++] = tmp[end--];
    }
}

void s21_param(s21_format *parameters, char const *format) {
    switch (*format) {
        case '-':
            parameters->flag_minus = 1;
            break;
        case '+':
            parameters->flag_plus = 1;
            break;
        case ' ':
            parameters->flag_space = 1;
            break;
        case 'l':
            parameters->length = 'l';
            break;
        case 'h':
            parameters->length = 'h';
            break;
        case '.':
            parameters->point = 1;
            break;
    }
}

//long double f_res(char *str, va_list *input, s21_format parameters) {
//    long double val = va_arg(input, long double);
//    long double left = 0;
//    long double right = modfl(val, &left) // разбивает число на целую и дробную части; целая часть помещается в left; возвращается дробная часть
//    long long round_left = left;
//    int precision = ;
//    for (int i = 0; i < precision; i++) {
//        right *= 10;
//    }
//    right = roundl(right); // округляем right
//    return ;
//}

void s21_d_i_res(char *str, va_list *input, s21_format parameters, int chr_format, int chr_str, int cnt_num) {
    int param = 0;
    if (parameters.length = 'l') param = va_arg(input, long); // чтобы считывались большие значения
    else if (parameters.length = 'h') param = (short) va_arg(input, int); // еще один тип, занимает в памяти 2 байта 
    else param = va_arg(input, int);
    s21_itoa_decimal(param, str, chr_str);
    chr_format++;
    chr_str++;
    cnt_num++;
}

void s21_s_res(char *str, va_list *input, s21_format parameters, int chr_format, int chr_str, int cnt_num) {
    char *param = va_arg(input, char *);
    strcat(str, param);
    chr_str = strlen(str) - 1;
    chr_format++;
    cnt_num++;
}

void s21_u_res(char *str, va_list *input, s21_format parameters, int chr_format, int chr_str, int cnt_num) {
    unsigned long param = 0;
    if (parameters.length = 'l') param = va_arg(input, unsigned long); 
    else if (parameters.length = 'h') param = (short) va_arg(input, unsigned);
    else param = va_arg(input, unsigned);
    s21_itoa_decimal(param, str, chr_str); // не факт, что сработает 
    chr_format++;
    chr_str++;
    cnt_num++;
}

void s21_c_res(char *str, va_list *input, s21_format parameters, int chr_format, int chr_str, int cnt_num) {
    char param = (char)va_arg(input, int); // https://ru.manpages.org/va_arg/3
    str[chr_format] = param;
    chr_str++;
    cnt_num++;
}

void s21_proc_res(char *str, va_list *input, s21_format parameters, int chr_format, int chr_str, int cnt_num) {
    str[chr_str] = '%';
    chr_format++;
    cnt_num++;
}

void s21_n_res(char *str, va_list *input {
    int *res = va_arg(input, int*);
    *res = s21_strlen(str);
}

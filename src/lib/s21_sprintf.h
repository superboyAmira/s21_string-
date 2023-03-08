#ifndef SRC_LIB_S21_SPRINTF_H_
#define SRC_LIB_S21_SPRINTF_H_

#include <math.h>
#include <stdarg.h>
#include <stdbool.h>

#include "../s21_string.h"

#define s21_size_t unsigned long long
#define BUFF_SIZE 1000

typedef struct s21_variety {
  int flag_minus;  // выравнивание по левому краю
  int flag_plus;  // принудительное выставление знака
  int flag_space;  // если без знака, то вместо него - пробел
  int width;  // минимальное количество печатаемых символов
  int precision;  // минимальное количество записываемых цифр (символов после
                  // точки)
  int precision_flag;
  char length;  // длина l, h
  int point;    // точка

  char opt;
} s21_variety;

int s21_sprintf(char *str, const char *format, ...);

const char *parser_flags(s21_variety *flags, const char *format);
const char *parser_width(s21_variety *flags, const char *format);
const char *parser_precision(s21_variety *flags, const char *format);
const char *parser_lenght(s21_variety *flags, const char *format);
void parser_options(s21_variety *flags, char *tmp, va_list input);

void output_c(s21_variety *flags, char *tmp, va_list input);
void output_d_i(s21_variety *flags, char *tmp, va_list input);
void output_f_lf(s21_variety *flags, char *tmp, va_list input);
void output_s(s21_variety *flags, char *tmp, va_list input);
void output_u(s21_variety *flags, char *tmp, va_list input);

int s21_atoi(char *num);
void s21_itoa_decimal(int64_t num, char *str, s21_size_t place);
void s21_dtoa(double num, char *str, s21_size_t place, s21_variety *flags);
void s21_utoa(long long int num, char *str, s21_size_t place);
long long int cnt_digit_int(long long int num);
int s21_isdigit(char c);
s21_size_t s21_mblen(wchar_t *buff);
void s21_wctomb(char *dest, wchar_t *wsrc, int len, int place);

void add_precision(char *tmp, s21_variety *flags);
void add_flags(s21_variety *flags, char *tmp);

#endif  // SRC_LIB_S21_SPRINTF_H_

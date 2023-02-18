#include "../s21_string.h"
#include <stdarg.h>
#include <string.h> // must be deleted
#include <stdbool.h>
#include <math.h>
#define BUFF_SIZE 10000

void reverse(char string[], int length);
void s21_itoa_decimal(int num, char *str, s21_size_t place);
void double_to_string(double num, char *str, s21_size_t place);

int s21_sprintf(char *str, const char *format, ... ) {
    int cnt_num = 0;
    va_list(input);
    va_start(input, format);
    
    for (int chr_format = 0, chr_str = 0; format[chr_format] != '\0'; chr_format++) {
        if (format[chr_format] == '%') {
            if (format[chr_format + 1] == 'd' || format[chr_format + 1] == 'i') {
                int param = va_arg(input, int);
                s21_itoa_decimal(param, str, chr_str);
                chr_format++;
                chr_str++;
                cnt_num++;
            } else if (format[chr_format + 1] == 'c') {
                char param = (char)va_arg(input, int); // https://ru.manpages.org/va_arg/3
                str[chr_format] = param;
                chr_str++;
                cnt_num++;
            } else if (format[chr_format + 1] == 'f') {
                double param = va_arg(input, double);
                double_to_string(param, str, chr_str);
                chr_format++;
                chr_str++;
                cnt_num++;
            } else if (format[chr_format + 1] == 's') {
                char *param = va_arg(input, char *);
                strcat(str, param);
                chr_str = strlen(str) - 1;
                chr_format++;
                cnt_num++;
            // } else if (format[chr+1]) == 'u' { // беззнаковое число
            //     int param = va_arg(input, int);
            } else if (format[chr_format + 1] == '%') {
                str[chr_str] = '%';
                chr_format++;
                cnt_num++;
            } else {
                printf("Non-valid Format", stderr);
                break; // если после % непонятно что, то программа ломается
            }
        } else {
            str[chr_str] = format[chr_format];
            chr_str++;
        }
    }
    va_end(input);
    return cnt_num;
}

void s21_itoa_decimal(int num, char *str, s21_size_t place) { // convert int to string with radix 10
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
        
        reverse(num_string, k);
        num_string[k] = '\0';
    }
    strcat(str, num_string);
}

void reverse(char string[], int length) {
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

void double_to_string(double num, char *str, s21_size_t place) { // перевеодит дабл в строку
    long double fl_int = 0.0;
    long double fl_fract = modfl(num, &fl_int); // разбивает число на целую и дробную части; целая часть помещается в left; возвращается дробная часть
    int int_fract = (int)round(fl_fract * 1e+6);
    int k = (int)1e+5;

    s21_itoa_decimal((int)fl_int, str, place);
    s21_size_t length_str = strlen(str);
    strncat(str, ".", length_str);

    for (int i = length_str + 1; i < length_str + 7; i++) {
        if ((int_fract / k) == 0) {
            str[i] = '0';
        } else {
            str[i] = "0123456789"[int_fract / k];
        }
        int_fract %= k;
        k /= 10;
    }
}

int main (void) {
    char dest2[100];

    s21_sprintf(dest2, "abc %f", 1.04567);
    printf ("src: %s", dest2);

   return 0;
}
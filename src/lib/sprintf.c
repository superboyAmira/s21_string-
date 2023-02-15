#include "../s21_string.h"
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>
#define BUFF_SIZE 10000

void reverse(char string[], int length);
char *s21_itoa_decimal(int num, char *str, int place);
// long double float_res(input);

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
            // } else if (format[chr+1]) == 'f' {
            //     float_res(input);
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
        
        reverse(num_string, k);
        num_string[k] = '\0';
    }
    strcat(str, num_string);
    return str;
}

void reverse(char string[], int length)
{
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

// long double float_res(input) {
//     long double val = va_arg(input, float);
//     long double left = 0;
//     long double right = modfl(val, &left); // разбивает число на целую и дробную части; целая часть помещается в left; возвращается дробная часть
//     long long round_left = left;
//     int precision = ;
//     for (int i = 0; i < precision; i++) {
//         right *= 10;
//     }
//     right = roundl(right); // округляем right
//     return ;
// }

int main (void) {
    char dest2[100];

    s21_sprintf(dest2, "abc %s", "Hello");
    printf ("src: %s", dest2);

   return 0;
}
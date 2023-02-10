#include "../s21_string.h"
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>
#define BUFF_SIZE 10000

void reverse(char string[], int length);
char *s21_itoa_decimal(int num, char *str, int place);


int s21_sprintf(char *str, const char *format, ... ) {
    int cnt_num = 0; // if error -1

    va_list(input);
    va_start(input, format);
    for (int chr = 0; chr < strlen(format); chr++) {
        if (format[chr] == '%') {
            if (format[chr + 1] == 'd' && format[chr + 1] == 'i') {
                int param = va_arg(input, int);
                s21_itoa_decimal(param, str, chr);
                chr++;
                cnt_num++;
            } else {
                str[chr] = '%';
            }
        } else {
            str[chr] = format [chr];
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
 

int main (void) {
    char dest2[6]="";

    s21_sprintf(dest2, "abc %d%d", 12, 2);
    printf ("src: %s", dest2);

   return 0;
}
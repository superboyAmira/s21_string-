#include "s21_string.h"
#include <string.h>

char *s21_strncpy(char *dest, const char *src, s21_size_t n) { // Копирует до n символов из строки, на которую указывает src, в dest.
    char *ptr = dest;
    if (dest == s21_NULL) {
        ptr = s21_NULL;
    } else {
        for (s21_size_t count = 0; count < n; count++) {
            *dest = *src;
            dest++;
            src++;
        }
        *dest = '\0';
    }
    return ptr;
}

void *s21_memset(void *str, int c, s21_size_t n) { // Копирует символ c (беззнаковый тип) в первые n символов строки, на которую указывает аргумент str.
    if (str != s21_NULL && c >= 0) {
        for (s21_size_t ch = 0; ch < n; ch++) {
            ((unsigned char *)str)[ch] = c;
        }
    }
}

s21_size_t s21_strlen(const char *str) {
    s21_size_t result = 0;
    while (*str != '\0') {
        str++;
        result++;
    }
    return result;
}

int main (void)
{
   // Исходный массив
   char src[15]="1234567890";
   char src2[15]="1234567890";
   char dest[15]="";
    char dest2[15]="";
 
   // Заполняем массив символом ‘1’
    // strcpy(dest, src);
    s21_strncpy(dest2, src2, 3);
    s21_memset(dest, 'X', 5);
    s21_size_t res = s21_strlen(src);


   // Вывод массива src на консоль
   printf ("src: %d", res);

   return 0;
}
#include "../s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) { // Копирует n символов из src в dest.
    if (dest != s21_NULL && src != s21_NULL) {
        for (s21_size_t i = 0; i < n; i++) {
            ((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
        }
    }
    return dest;
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) { // Еще одна функция для копирования n символов из src в dest.
    if (dest != s21_NULL && src != s21_NULL) {
        for (s21_size_t i = 0; i < n; i++) {
            ((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
        }
    }
    return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) { // Копирует символ c (беззнаковый тип) в первые n символов строки, на которую указывает аргумент str.
    if (str != s21_NULL && c >= 0) {
        for (s21_size_t ch = 0; ch < n; ch++) {
            ((unsigned char *)str)[ch] = c;
        }
    }
}

char *s21_strcpy(char *dest, const char *src) { // Копирует строку, на которую указывает src, в dest.
    char *ptr = dest;
    if (dest == s21_NULL) {
        ptr = s21_NULL;
    } else {
        while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
        }
        *dest = '\0';
    }
    return ptr;
}

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
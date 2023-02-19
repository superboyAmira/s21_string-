#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUFF_SIZE 10000
#define s21_size_t unsigned long long
#define s21_NULL (void*)0 
#define flag short int
#define TRUE 1
#define FALSE 0

// структура для формата
typedef struct s21_variety {
    int flag_minus; // выравнивание по левому краю
    int flag_plus; // принудительное выставление знака
    int flag_space; // если без знака, то вместо него - пробел
    int width; // минимальное количество печатаемых символов
    int precision; // минимальное количество записываемых цифр (символов после точки)
    char length; // длина l, h
    int point; // точка
} s21_format;

s21_size_t s21_strlen(const char *str);
char *s21_strtok(char *str, const char *delim);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
int s21_sprintf(char *str, const char *format, ... );


#endif  // SRC_S21_STRING_H_
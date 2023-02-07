#ifndef SRC_S21_STRING_H
#define SRC_S21_STRING_H_

#include <stdio.h>
#include <stdlib.h>

#define s21_size_t unsigned long long
#define s21_NULL (void*)0 
#define flag short int
#define TRUE 1
#define FALSE 0

s21_size_t s21_strlen(const char *str);
char *s21_strtok(char *str, const char *delim);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);

#endif  // SRC_S21_STRING_H_
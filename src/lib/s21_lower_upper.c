#include "../s21_string.h"

void *s21_to_upper(const char *str) {
  char *cpy = s21_NULL;  // в верхний регистр
  if (str) {
    cpy = calloc(s21_strlen(str) + 1, sizeof(char));
    for (s21_size_t i = 0; i < s21_strlen(str); i++) {
      if (str[i] >= 'a' && str[i] <= 'z')
        cpy[i] = str[i] - 32;
      else
        cpy[i] = str[i];
    }
  }
  return (void *)cpy;
}

void *s21_to_lower(const char *str) {  // в нижний регистр
  char *cpy = s21_NULL;
  if (str) {
    cpy = calloc(s21_strlen(str) + 1, sizeof(char));
    for (size_t i = 0; i < s21_strlen(str); i++) {
      if (str[i] >= 'A' && str[i] <= 'Z')
        cpy[i] = str[i] + 32;
      else
        cpy[i] = str[i];
    }
  }
  return (void *)cpy;
}

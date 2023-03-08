#include "../s21_string.h"

void *s21_memchr(const void *arr, int c,
                 s21_size_t n) {  // ищет вхождение в массив символа с, n байт
  const char *res = arr;
  int is_got_symb = 0;
  for (s21_size_t i = 0; i < n && arr; i++) {
    if (res[i] == c) {
      is_got_symb = 1;
      res = (char *)arr + i;
      break;
    }
  }
  return is_got_symb ? ((void *)res) : s21_NULL;
}

char *s21_strchr(const char *str, int ch) {
  char *res = s21_NULL;
  if (str != s21_NULL) {
    for (int i = 0; i < (int)s21_strlen(str); i++) {
      if (str[i] == ch) {
        res = (char *)str + i;
        break;
      }
    }
  }
  return res;
}

char *s21_strpbrk(
    const char *str,
    const char *sym) {  // ищет первое вхождение одного из символов sym, в str
  const char *res = s21_NULL;
  int is_got_symb = 0;
  for (s21_size_t i = 0; i < s21_strlen(str); i++) {
    for (s21_size_t z = 0; z < s21_strlen(sym); z++) {
      if (str[i] == sym[z]) {
        res = str + i;
        is_got_symb = 1;
        break;
      }
    }
    if (is_got_symb == 1) break;
  }
  return (char *)res;
}

char *s21_strrchr(const char *str,
                  int ch) {  // ищет последнее вхождения символа ch
  const char *res = s21_NULL;
  for (int i = s21_strlen(str); i >= 0; i--) {
    if (str[i] == ch) {
      res = str + i;
      break;
    }
  }
  return (char *)res;
}

char *s21_strstr(
    const char *str1,
    const char *str2) {  // ищет первое вхождение строки str2 в str1
  char *res = s21_NULL;
  int checker = 0;
  if (str2[0] == '\0') {
    for (int i = 0; i < (int)s21_strlen(str1); i++) {
      res = (char *)str1;
    }
  } else {
    for (int i = 0; i < (int)s21_strlen(str1); i++) {
      if (str1[i] == str2[0]) {
        res = (char *)str1 + i;
        for (int z = 0; z < (int)s21_strlen(str2); z++) {
          if (str1[i + z] == str2[z]) {
            checker = 1;
          } else {
            checker = 0;
            break;
          }
        }
      }
      if (checker == 1)
        break;
      else
        res = s21_NULL;
    }
  }

  return res;
}

#include "../s21_string.h"

char *s21_strtok(char *str, const char *delim) { // Разбивает строку str на ряд токенов, разделенных delim.
  static char* mem = s21_NULL;

  if (str) mem = str;

  if (mem) {
    str = mem + s21_strspn(mem, delim);
    mem = str + s21_strcspn(str, delim);
    if (*mem != '\0') {
      *mem = '\0';
      ++mem;
    }
  }

  return *str != '\0' ? str : s21_NULL;
}

#include "../s21_string.h"
#include <string.h>
char *s21_strtok(char *str, const char *delim) { // Разбивает строку str на ряд токенов, разделенных delim.
  static char* mem = s21_NULL;

  if (str != s21_NULL) mem = str;

  if (mem != s21_NULL) {
    str = mem + strspn(mem, delim);
    mem = str + strcspn(str, delim);
    if (*mem != '\0') {
      *mem = '\0';
      ++mem;
    }
  }

  return *str != '\0' ? str : s21_NULL;
}

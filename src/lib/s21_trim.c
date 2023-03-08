#include "../s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *res = s21_NULL;
  if (src != s21_NULL) {
    if (trim_chars != s21_NULL || s21_strlen(trim_chars) != 0) {
      s21_size_t src_len = s21_strlen(src);
      s21_size_t trim_left_len = s21_strspn(src, trim_chars);
      s21_size_t trim_right_len = s21_strspn_reverse(src, trim_chars);
      s21_size_t res_len = src_len - trim_left_len - trim_right_len;
      res = (char *)malloc(sizeof(char) * (res_len + 1));
      if (res) {
        for (s21_size_t i = 0; i < res_len + 1; i++) {
          if (i < res_len)
            res[i] = src[i + trim_left_len];
          else
            res[i] = '\0';
        }
      }
    } else {
      res = s21_trim(src, "\t\n");
    }
  }
  return res;
}

s21_size_t s21_strspn_reverse(const char *str1, const char *str2) {
  s21_size_t len = 0;
  if ((str1 != s21_NULL) && (str2 != s21_NULL)) {
    for (s21_size_t i = s21_strlen(str1) - 1;; i--) {
      int res = 0;
      for (s21_size_t j = 0; j < s21_strlen(str2); j++) {
        if (str1[i] == str2[j]) {
          res = 1;
          len++;
          break;
        }
      }
      if (res == 0) break;
    }
  }
  return len;
}

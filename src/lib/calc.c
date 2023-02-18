#include "../s21_string.h"

s21_size_t s21_strlen(const char *str) {
    s21_size_t len = 0;
    if (str != s21_NULL) {
        for (; str[len] != '\0'; len++) continue;
    }
    return len;
}

s21_size_t s21_strspn(const char *str1, const char *str2) { // в первой str ведется поиск
    s21_size_t len = 0;
    if ((str1 != s21_NULL) && (str2 != s21_NULL)) {
        for (s21_size_t i = 0; i < s21_strlen(str1); i++) {
            int res = 0; // чтобы обнулялось при каждом входе в цикл
            for (s21_size_t j = 0; j < s21_strlen(str2); j++) {
                if (str1[i] == str2[j]) {
                    res = 1;
                    len++;
                    break; // завершил внутренний for
                }
            }
            if (res == 0) break; // если res == 0, значит, совпадения не нашлись и можно проверять дальше
        }
    }
    return len;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) { // начальный сегмент!
    s21_size_t len = 0;
    if ((str1 != s21_NULL) && (str2 != s21_NULL)) {
        while (*str1 != '\0') {
            if (s21_strchr(str2, *str1) != s21_NULL) break; // ищется первое вхождение каждого из символов str1 внутри str2
            // если совпадения найдены не были, то возвращается NULL
            else {
                str1++;
                len++;
            }
        }
    }
    return len;
}

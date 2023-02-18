#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    const unsigned char *twin1 = str1;
    const unsigned char *twin2 = str2;
    int dif = 0; // разница, которая в случае полной идентичности равна 0
    while (n > 0) {
        dif = *twin1 - *twin2;
        n--;
        twin1++;
        twin2++;
        if (dif != 0) break;
    }
    return dif;
}

int s21_strcmp(const char *str1, const char *str2) {
    int dif = 0;
    while (*str1 != '\0' || *str2 != '\0') {
        dif = *str1 - *str2;
        str1++;
        str2++;
        if (dif != 0) break;
    }
    return dif;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    int dif = 0;
    while (n > 0 && (*str1 != '\0' || *str2 != '\0')) { // если строчка закончилась, то дальше не проверяет
        dif = *str1 - *str2;
        n--;
        str1++;
        str2++;
        if (dif != 0) break;
    }
    return dif;
}

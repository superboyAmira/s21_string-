#include "../s21_string.h"

s21_size_t s21_strlen(const char *str) {
    s21_size_t result = 0;
    while (*str != '\0') {
        str++;
        result++;
    }
    return result;
}

char *s21_strtok(char *str, const char *delim) { // Разбивает строку str на ряд токенов, разделенных delim.
    s21_size_t cnt_res = 0;
    flag split_pssibl = TRUE;
    char buff_result[s21_strlen(str)];

    for (s21_size_t cnt_str = 0; cnt_str < s21_strlen(str); cnt_str++) {
        for (s21_size_t cnt_delim = 0; cnt_delim < s21_strlen(delim); cnt_delim++) {
            if (str[cnt_str] == delim[cnt_delim]) {
                if (cnt_res == 0) {
                    flag split_pssibl = FALSE;
                }
                break;
            } else {
                buff_result[cnt_res] = str[cnt_str];
                split_pssibl = TRUE;
                cnt_res++;
            }
        }
    }

    if (!split_pssibl) {
        *buff_result = s21_NULL;
    }
    
    return buff_result;
}
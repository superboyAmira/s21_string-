#include "../s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) { // Возвращает новую строку, в которой 
                                        // указанная строка (str) вставлена в указанную позицию (start_index) в данной строке (src).
                                                                        //  В случае какой-либо ошибки следует вернуть значение NULL
    char *result = s21_NULL;
    if (src != s21_NULL && str != s21_NULL && start_index <= s21_strlen(src)) {
        s21_size_t src_len = s21_strlen(src);
        s21_size_t str_len = s21_strlen(str);
        s21_size_t res_len = str_len + src_len;

        result = (char *)calloc(res_len + 1, sizeof(char));

        if (result != s21_NULL) {
            for (s21_size_t cnt_res = 0, cnt_src = 0; cnt_res < res_len; cnt_res++) {
                if (cnt_res == start_index) {
                    s21_size_t cnt_insrt = 0;
                    while (cnt_insrt < str_len) {
                        result[cnt_res] = str[cnt_insrt];
                        cnt_res++;
                        cnt_insrt++;
                    }
                    result[cnt_res] = src[cnt_src];
                    cnt_src++;
                } else {
                    result[cnt_res] = src[cnt_src];
                    cnt_src++;
                }
            }
            result[res_len] = '\0'; 
        }
    }
    return result;
}
// int main (void)
// {
//    // Исходный массив
//    char src[15]="12345";
//    char dest[15]="hi";
 
//    // Заполняем массив символом ‘1’
//     // strcpy(dest, src);
//     char *res = s21_insert(src, dest, 3);


//    // Вывод массива src на консоль
//    printf ("src: %s", res);

//    return 0;
// }
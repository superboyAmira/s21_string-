#include "s21_test_string.h"

START_TEST(strlen_test) {
  char *s1 = "0123456789";
  char *s2 = "";
  char *s3 = "a";
  ck_assert_int_eq(s21_strlen(s1), strlen(s1));
  ck_assert_int_eq(s21_strlen(s2), strlen(s2));
  ck_assert_int_eq(s21_strlen(s3), strlen(s3));
}
END_TEST

START_TEST(memchr_test) {
  char *s1 = "012a3456789";
  char *s2 = "";
  int i = 3;
  int c = '5';
  s21_size_t n[5] = {0, 3, 6, 10, 15};
  while (i >= 0) {
    ck_assert_ptr_eq(memchr(s1, c, n[i]), s21_memchr(s1, c, n[i]));
    ck_assert_ptr_eq(memchr(s2, c, n[i]), s21_memchr(s2, c, n[i]));
    i--;
  }
}
END_TEST

START_TEST(memcmp_test) {
  int i = 2;
  char *str1 = "Hello World !!!";
  char *str2 = "Hello Wirld !!!";
  char *str3 = "a";
  char *str4 = " ";
  s21_size_t n[3] = {1, 6, 10};
  while (i >= 0) {
    ck_assert_int_eq(memcmp(str1, str2, n[i]), s21_memcmp(str1, str2, n[i]));
    ck_assert_int_eq(memcmp(str3, str4, n[i]), s21_memcmp(str3, str4, n[i]));
    i--;
  }
}
END_TEST

START_TEST(memcpy_test) {
  int i = 2;
  char str1[100] = " ";
  char str2[100] = "Hello World !!!";
  char str3[100] = "123456";
  s21_size_t n[3] = {1, 6, 10};
  while (i >= 0) {
    ck_assert_ptr_eq(memcpy(str1, str2, n[i]), s21_memcpy(str1, str2, n[i]));
    ck_assert_ptr_eq(memcpy(str2, str3, n[i]), s21_memcpy(str2, str3, n[i]));
    i--;
  }
}
END_TEST

START_TEST(memmove_test) {
  int i = 2;
  char str1[100] = " ";
  char str2[100] = "Hello World !!!";
  char str3[100] = "123456";
  s21_size_t n[3] = {1, 6, 10};
  while (i >= 0) {
    ck_assert_ptr_eq(memmove(str1, str2, n[i]), s21_memmove(str1, str2, n[i]));
    ck_assert_ptr_eq(memmove(str2, str3, n[i]), s21_memmove(str2, str3, n[i]));
    i--;
  }
}
END_TEST

START_TEST(memset_test) {
  int i = 2;
  char str1[100] = " ";
  char str2[100] = "Hello World !!!";
  s21_size_t n[3] = {1, 6, 10};
  int c = '5';
  while (i >= 0) {
    ck_assert_ptr_eq(memset(str1, c, n[i]), s21_memset(str1, c, n[i]));
    ck_assert_ptr_eq(memset(str2, c, n[i]), s21_memset(str2, c, n[i]));
    i--;
  }
}
END_TEST

START_TEST(strcat_test) {
  char str1[100] = " ";
  char str2[100] = "Hello World !!!";
  char str3[100] = "123456";
  ck_assert_str_eq(strcat(str1, str2), s21_strcat(str1, str2));
  ck_assert_str_eq(strcat(str2, str3), s21_strcat(str2, str3));
}
END_TEST

START_TEST(strncat_test) {
  int i = 1;
  char str1[100] = " ";
  char str2[100] = "Hello World !!!";
  char str3[100] = "123456";
  s21_size_t n[3] = {1, 6};
  while (i >= 0) {
    ck_assert_str_eq(strncat(str1, str2, n[i]), s21_strncat(str1, str2, n[i]));
    ck_assert_str_eq(strncat(str2, str3, n[i]), s21_strncat(str2, str3, n[i]));
    i--;
  }
}
END_TEST

START_TEST(strchr_test) {
  char str1[100] = "Hello World !!!";
  char str2[100] = "123456";
  int c = '5';
  ck_assert_ptr_eq(strchr(str1, c), s21_strchr(str1, c));
  ck_assert_str_eq(strchr(str2, c), s21_strchr(str2, c));
}
END_TEST

START_TEST(strcmp_test) {
  char str1[100] = "123456";
  char str2[100] = "Hello World !!!";
  char str3[100] = "123456";
  char str4[100] = "12Hello World !!!";
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
  ck_assert_int_eq(strcmp(str1, str3), s21_strcmp(str1, str3));
  ck_assert_int_eq(strcmp(str1, str4), s21_strcmp(str1, str4));
}
END_TEST

START_TEST(strncmp_test) {
  int i = 2;
  s21_size_t n[3] = {1, 6, 10};
  char str1[100] = "123456";
  char str2[100] = "Hello World !!!";
  char str3[100] = "123456";
  char str4[100] = "12Hello World !!!";
  while (i >= 0) {
    ck_assert_int_eq(strncmp(str1, str2, n[i]), s21_strncmp(str1, str2, n[i]));
    ck_assert_int_eq(strncmp(str1, str3, n[i]), s21_strncmp(str1, str3, n[i]));
    ck_assert_int_eq(strncmp(str1, str4, n[i]), s21_strncmp(str1, str4, n[i]));
    i--;
  }
}
END_TEST

START_TEST(strcpy_test) {
  char str1[100] = "123456";
  char str2[100] = "Hello World !!!";
  char str3[100] = "789";
  ck_assert_str_eq(strcpy(str1, str2), s21_strcpy(str1, str2));
  ck_assert_str_eq(strcpy(str2, str3), s21_strcpy(str2, str3));
}
END_TEST

START_TEST(strncpy_test) {
  int i = 2;
  char str1[100] = "123456";
  char str2[100] = "Hello World !!!";
  char str3[100] = "789";
  s21_size_t n[3] = {1, 6, 10};
  while (i >= 0) {
    ck_assert_str_eq(strncpy(str1, str2, n[i]), s21_strncpy(str1, str2, n[i]));
    ck_assert_str_eq(strncpy(str2, str3, n[i]), s21_strncpy(str2, str3, n[i]));
    i--;
  }
}
END_TEST

START_TEST(strcspn_test) {
  char str1[100] = "123456";
  char str2[100] = "Hello3 World !!!";
  char str3[100] = "468";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
  ck_assert_int_eq(strcspn(str1, str3), s21_strcspn(str1, str3));
}
END_TEST

START_TEST(strpbrk_test) {
  char str1[100] = "123456";
  char str2[100] = "Hello3 World !!!";
  char str3[100] = "468";
  ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
  ck_assert_str_eq(strpbrk(str1, str3), s21_strpbrk(str1, str3));
}
END_TEST

START_TEST(strrchr_test) {
  char str1[100] = "1234536346";
  char str2[100] = "Hello World !!!";
  int c = '3';
  ck_assert_str_eq(strrchr(str1, c), s21_strrchr(str1, c));
  ck_assert_ptr_eq(strrchr(str2, c), s21_strrchr(str2, c));
}
END_TEST

START_TEST(strerror_test) {
  ck_assert_str_eq(strerror(500), s21_strerror(500));
  ck_assert_str_eq(strerror(1), s21_strerror(1));
  ck_assert_str_eq(strerror(-56), s21_strerror(-56));
  ck_assert_str_eq(strerror(-2147483648), s21_strerror(-2147483648));
}
END_TEST

START_TEST(strstr_test) {
  char str1[100] = "12345363462345";
  char str2[100] = "1234";
  char str3[100] = "23";
  char str4[100] = "\0";
  ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
  ck_assert_str_eq(strstr(str1, str3), s21_strstr(str1, str3));
  ck_assert_str_eq(strstr(str2, str4), s21_strstr(str2, str4));
  ck_assert_ptr_eq(strstr(str2, str1), s21_strstr(str2, str1));
}
END_TEST

START_TEST(strspn_test) {
  char str1[100] = "6651234536346";
  char str2[100] = "134";
  char str3[100] = "66512345363461234";
  char str4[100] = "1234";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
  ck_assert_int_eq(strspn(str3, str4), s21_strspn(str3, str4));
}
END_TEST

START_TEST(strtok_test) {
  char str1[100] = "123453636235";
  char str2[100] = "4";
  char str4[100] = "8888123456788888";
  char str[100] = "8";
  char a1[100] = "test1/test2/test3";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str1, str2));
  ck_assert_str_eq(strtok(str4, str), s21_strtok(str4, str));
  ck_assert_str_eq(strtok(a1, "/"), s21_strtok(a1, "/"));
}
END_TEST

START_TEST(trim_test) {
  char str1[100] = "  **  //QWERTYUI//  //  **";
  char str2[100] = " */";
  char *except = "QWERTYUI";
  ck_assert_str_eq(s21_trim(str1, str2), except);
}
END_TEST

START_TEST(insert_test) {
  char *s1 = "1234789";
  char *s2 = "56";
  s21_size_t s = 4;
  s21_size_t x = 0;
  char *ex = "123456789";
  char *ex1 = "561234789";
  ck_assert_str_eq((char *)s21_insert(s1, s2, s), ex);
  ck_assert_str_eq((char *)s21_insert(s1, s2, x), ex1);
}
END_TEST

START_TEST(to_lower_test) {
  char *str = "qWertYuiOp";
  char *except = "qwertyuiop";
  ck_assert_str_eq(s21_to_lower(str), except);
}
END_TEST

START_TEST(to_upper_test) {
  char *str = "qWertYuiOp";
  char *except = "QWERTYUIOP";
  ck_assert_str_eq(s21_to_upper(str), except);
}
END_TEST

START_TEST(common_int) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "This is a simple value %d";
  int val = -99990;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(precise_int) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%.5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%5d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(minus_width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(plus_width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%+12d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(many_flags_many_ints) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char format[] = "%10i %d %.4i %-10d %d";
  int val = 69;
  ck_assert_int_eq(
      s21_sprintf(str1, format, 5, val, -10431, 13, 5311, 0, -581813581),
      sprintf(str2, format, 5, val, -10431, 13, 5311, 0, -581813581));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flags_long_int) {  // работает с указателем
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%+.31li";
  long int val = 698518581899;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flags_short_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16.9hi";
  short int val = 6958;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(space_flag_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_short) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%hu";
  unsigned short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lu";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lu, %u, %hu, %.5u";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val, 14, 1441, 14414),
                   sprintf(str2, format, val, (unsigned)14,
                           (unsigned short)1441, (unsigned)14414));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%u";
  ck_assert_int_eq(s21_sprintf(str1, format, 0),
                   sprintf(str2, format, (unsigned)0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%c";
  char val = 'X';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(one_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% -5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_width_l) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%5lc";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_l) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lc";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5c%c%c%c%c Hello! ABOBA";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val, 'c', 'a', 'b', 'b'),
                   sprintf(str2, format, val, 'c', 'a', 'b', 'b'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-10c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.15s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%7ls";
  wchar_t val[] = L"69 IS MY FAVORITE NUMBER";
  // (void)setlocale(LC_ALL,"");s
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s%s%s%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  char *s1 = "";
  char *s2 = "87418347813748913749871389480913";
  char *s3 = "HAHAABOBASUCKER";
  ck_assert_int_eq(s21_sprintf(str1, format, val, s1, s2, s3),
                   sprintf(str2, format, val, s1, s2, s3));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(float_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.7f";
  long double val = 513515.131513;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(float_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%10f";
  float val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(float_precision_empty) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.f";
  double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(float_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% .0f %.10f %5f %f";
  float val = 0;
  double val1 = 0;
  float val3 = 5.5;
  double val4 = 9851.51351;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val3, val4),
                   sprintf(str2, format, val, val1, val3, val4));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(all_empty) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%c", '\t'), sprintf(str2, "%c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'),
                   sprintf(str2, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%s", "Drop Sega PLS"),
                   sprintf(str2, "%s", "Drop Sega PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"),
      sprintf(str2, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(width_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple wide char %5c";
  char w = 'c';
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
START_TEST(minus_wide_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple wide char %-5lc";
  unsigned long w = L'1';
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST
START_TEST(wide_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple wide char %ls";
  wchar_t w[] = L"12";
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(wide_string1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple wide char %.12ls";
  wchar_t w[] = L"12";
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(wide_string2) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple wide char %120ls ABOBA";
  wchar_t w[] = L"1";
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(wide_string3) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple wide char %-43ls";
  wchar_t w[] = L"1";
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(string_width_1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple wide char %3s";
  char w[] = "124245";
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(string_prec_1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple wide char %.10s";
  char w[] = "124245";
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(string_wide_prec_1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple wide char %.3ls";
  wchar_t w[] = L"124245";
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(string_common__1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple wide char %10s";
  wchar_t w[] = L"124245";
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(string_common__2) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple wide char %-10s";
  wchar_t w[] = L"124245";
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(non_valid) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  int b = 0, i = 0;
  char *format = "This is a simple wide char %15q";
  wchar_t w[] = L"1";
  b = s21_sprintf(str1, format, w), i = sprintf(str2, format, w);

  ck_assert_int_eq(b, i);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(procent) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  int b = 0, i = 0;
  char format[] = "This is a simple wide char %%";
  b = s21_sprintf(str1, format), i = sprintf(str2, format);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(b, i);
}
END_TEST;

START_TEST(n_specifier) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int ret = 0;
  char *format = "Hello, my sexy little aboba abobushka abobina %n";
  ck_assert_int_eq(s21_sprintf(str1, format, &ret),
                   sprintf(str2, format, &ret));

  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *s21_string_test_suite() {
  Suite *s21_string = suite_create("s21_string");
  TCase *s21_string_tests = tcase_create("S21_STRING");

  tcase_add_test(s21_string_tests, strlen_test);
  tcase_add_test(s21_string_tests, memcpy_test);
  tcase_add_test(s21_string_tests, memmove_test);
  tcase_add_test(s21_string_tests, memset_test);
  tcase_add_test(s21_string_tests, strcpy_test);
  tcase_add_test(s21_string_tests, strncpy_test);
  tcase_add_test(s21_string_tests, insert_test);
  tcase_add_test(s21_string_tests, strtok_test);

  tcase_add_test(s21_string_tests, memchr_test);
  tcase_add_test(s21_string_tests, memcmp_test);

  tcase_add_test(s21_string_tests, strcat_test);
  tcase_add_test(s21_string_tests, strncat_test);
  tcase_add_test(s21_string_tests, strchr_test);

  tcase_add_test(s21_string_tests, strcmp_test);
  tcase_add_test(s21_string_tests, strncmp_test);

  tcase_add_test(
      s21_string_tests,
      strcspn_test);  // Assertion 'strcspn(str1, str2) == s21_strcspn(str1,
                      // str2)' failed: strcspn(str1, str2) == 2,
                      // s21_strcspn(str1, str2) == 0

  tcase_add_test(s21_string_tests, strpbrk_test);
  tcase_add_test(s21_string_tests, strrchr_test);
  tcase_add_test(s21_string_tests, strerror_test);
  tcase_add_test(s21_string_tests, strspn_test);

  tcase_add_test(s21_string_tests, strstr_test);

  tcase_add_test(s21_string_tests, trim_test);
  tcase_add_test(s21_string_tests, to_lower_test);
  tcase_add_test(s21_string_tests, to_upper_test);

  tcase_add_test(s21_string_tests, common_int);
  tcase_add_test(s21_string_tests, precise_int);
  tcase_add_test(s21_string_tests, width_int);
  tcase_add_test(s21_string_tests, minus_width_int);
  tcase_add_test(s21_string_tests, plus_width_int);
  tcase_add_test(s21_string_tests, many_flags_many_ints);
  tcase_add_test(s21_string_tests, flags_long_int);
  tcase_add_test(s21_string_tests, flags_short_int);
  tcase_add_test(s21_string_tests, space_flag_int);
  tcase_add_test(s21_string_tests, unsigned_val);
  tcase_add_test(s21_string_tests, unsigned_val_width);
  tcase_add_test(s21_string_tests, unsigned_val_flags);
  tcase_add_test(s21_string_tests, unsigned_val_precision);
  tcase_add_test(s21_string_tests, unsigned_val_short);
  tcase_add_test(s21_string_tests, unsigned_val_long);
  tcase_add_test(s21_string_tests, unsigned_val_many);
  tcase_add_test(s21_string_tests, unsigned_zero);
  tcase_add_test(s21_string_tests, one_char);
  tcase_add_test(s21_string_tests, one_precision);
  tcase_add_test(s21_string_tests, one_flags);
  tcase_add_test(s21_string_tests, one_width);
  tcase_add_test(s21_string_tests, one_many);
  tcase_add_test(s21_string_tests, one_many_flags);
  tcase_add_test(s21_string_tests, string);
  tcase_add_test(s21_string_tests, string_precision);
  tcase_add_test(s21_string_tests, string_width);
  tcase_add_test(s21_string_tests, string_flags);
  tcase_add_test(s21_string_tests, string_long);
  tcase_add_test(s21_string_tests, string_many);
  tcase_add_test(s21_string_tests, float_precision);
  tcase_add_test(s21_string_tests, float_width);
  tcase_add_test(s21_string_tests, float_precision_empty);
  tcase_add_test(s21_string_tests, float_many);
  tcase_add_test(s21_string_tests, all_empty);
  tcase_add_test(s21_string_tests, test_one_char);
  tcase_add_test(s21_string_tests, test_many_char);
  tcase_add_test(s21_string_tests, test_one_string);
  tcase_add_test(s21_string_tests, test_many_string);
  tcase_add_test(s21_string_tests, width_char);
  tcase_add_test(s21_string_tests, minus_wide_char);
  tcase_add_test(s21_string_tests, wide_string);
  tcase_add_test(s21_string_tests, wide_string1);
  tcase_add_test(s21_string_tests, wide_string2);
  tcase_add_test(s21_string_tests, wide_string3);
  tcase_add_test(s21_string_tests, procent);
  tcase_add_test(s21_string_tests, non_valid);
  tcase_add_test(s21_string_tests, one_width_l);
  tcase_add_test(s21_string_tests, one_l);
  tcase_add_test(s21_string_tests, string_width_1);
  tcase_add_test(s21_string_tests, string_prec_1);
  tcase_add_test(s21_string_tests, string_wide_prec_1);
  tcase_add_test(s21_string_tests, string_common__1);
  tcase_add_test(s21_string_tests, string_common__2);
  tcase_add_test(s21_string_tests, n_specifier);

  suite_add_tcase(s21_string, s21_string_tests);
  return s21_string;
}

int main(void) {
  Suite *s21_string = s21_string_test_suite();
  SRunner *s21_string_runner = srunner_create(s21_string);
  srunner_set_fork_status(s21_string_runner, CK_FORK);
  srunner_run_all(s21_string_runner, CK_VERBOSE);
  int num_failed = srunner_ntests_failed(s21_string_runner);
  srunner_free(s21_string_runner);

  return num_failed == 0 ? 0 : 1;
}

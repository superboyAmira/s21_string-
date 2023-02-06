#include "s21_test_string.h"

START_TEST(strlen_test) {
    char buff[256] = "123456789";
    ck_assert_msg(s21_strlen(buff) == strlen(buff), "Error");
    // ck_assert_msg(s21_strlen(s21_NULL) == strlen(s21_NULL), "Error");
} END_TEST

Suite *s21_string_tests_create() {
    Suite *s21_string = suite_create("s21_string");
    TCase *s21_string_tests = tcase_create("S21_STRING");

    tcase_add_test(s21_string_tests, strlen_test);

    suite_add_tcase(s21_string, s21_string_tests);

    return s21_string;
}

int main() {
  Suite *s21_string = s21_string_tests_create();
  SRunner *s21_string_runner = srunner_create(s21_string);
  srunner_set_fork_status(s21_string_runner, CK_FORK);
  srunner_run_all(s21_string_runner, CK_VERBOSE);
  int num_failed = srunner_ntests_failed(s21_string_runner);
  srunner_free(s21_string_runner);

  return num_failed == 0 ? 0 : 1;
}
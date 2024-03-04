#include "tests.h"

START_TEST(err_0) {
  int err = 0;
  char *s21 = s21_strerror(err);
  char *gnu = strerror(err);
  ck_assert_str_eq(s21, gnu);
}

START_TEST(err_negative) {
  int err = -1;
  char *s21 = s21_strerror(err);
  char *gnu = strerror(err);
  ck_assert_str_eq(s21, gnu);
}

START_TEST(err_all) {
  for (int err = -512; err < 150; err++) {
    char *s21 = s21_strerror(err);
    char *gnu = strerror(err);
    ck_assert_str_eq(s21, gnu);
  }
}

Suite *test_strerror(void) {
  Suite *s = suite_create("suite_strerror");
  TCase *tc = tcase_create("tc_strerror");

  tcase_add_test(tc, err_0);
  tcase_add_test(tc, err_negative);
  tcase_add_test(tc, err_all);

  suite_add_tcase(s, tc);
  return s;
}
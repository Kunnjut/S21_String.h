#ifndef TESTS_H
#define TESTS_H

#include <check.h>
#include <string.h>

#include "../s21_string.h"

#define S21_BUF 256

Suite *test_memchr(void);
Suite *test_memcmp(void);
Suite *test_memcpy(void);
Suite *test_memset(void);
Suite *test_strchr(void);
Suite *test_strcspn(void);
Suite *test_strerror(void);
Suite *test_strlen(void);
Suite *test_strncat(void);
Suite *test_strncmp(void);
Suite *test_strncpy(void);
Suite *test_strpbrk(void);
Suite *test_strrchr(void);
Suite *test_strstr(void);
Suite *test_strtok(void);

#endif
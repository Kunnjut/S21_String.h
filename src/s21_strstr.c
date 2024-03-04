#include <stdio.h>

#include "s21_string.h"

char *s21_strstr(const char *str1, const char *str2) {
  const char *str1_ptr = s21_NULL, *str2_ptr = s21_NULL;

  if (str1 == s21_NULL || str2 == s21_NULL) return s21_NULL;
  while (*str1) {
    if (*str1 == *str2) {
      int trigger_out = 1;

      str2_ptr = str2;
      str1_ptr = str1;

      while (*str2_ptr && *str1_ptr) {
        trigger_out = trigger_out && (*str2_ptr == *str1_ptr);
        if (!trigger_out)
          break;     // Added break statement to exit loop if characters don't
                     // match
        ++str2_ptr;  // Increment pointers to move to next characters
        ++str1_ptr;
      }

      if (trigger_out)
        return (char *)str1;  // Cast str1 to char* before returning
    }
    ++str1;
  }
  return s21_NULL;
}
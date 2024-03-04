#include <stdio.h>

#include "s21_string.h"

char *s21_strncat (char *dest, const char *src, s21_size_t n) {
    int memlen;
    s21_size_t i = 0;
    memlen = s21_strlen(dest);
    while(src[i] != '\0' && (i < n)){
        dest[memlen + i] = src[i];
        i++;
    }
    dest[memlen + i] = '\0';
    return dest;
}
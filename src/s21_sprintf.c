#include "s21_string.h"
#include <stdarg.h>
#include <stdbool.h>

#define min 1
#define plus 2
#define space 3
#define hash 4
#define zero 5
#define h 1
#define l 2
#define L 3

struct parameters { //структура для форматирования, не закончена
  int flags;
  int widthDigit;
  int precision;
  int length;
  int c;
  int d;
  int f;
  int s;
  int u;
};

char *s21_itoa(int num, char *str);
int vprintf(char *str, const char *format, va_list args);

int sprintf(char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  int n = vprintf(str, format, args);
  va_end(args);
  return n;
}

int vprintf(char *str, const char *format, va_list args) {
  int written = 0;
  struct parameters optAndFlags = {0};
  while (*format) {
    if (*format != '%') {
      *str++ = *format++;
      written++;
    } else {
      format++;
      // getFlags(- / + / space / # / 0)
      if (*format == ' ') {
        optAndFlags.flags = space;
        format++;
      }
      // case '-': {
      //   break;
      // }
      // case '+': {
      //   break;
      // }

      // get width (digit / *)

      // get precision (.digit / .*)

      // get length (h / l / L)

      // case 'h': {
      //   break;
      // }
      // case 'l': {
      //   break;
      // }

      // get types (c, d, f, s, u, %, g, G, e, E, x, X, o, p) and write to str

      switch (*format) {
      case 'c': {
        char c = va_arg(args, int);
        *str++ = c;
        written++;
        break;
      }
      case 'd': {
        int num = va_arg(args, int);
        char *end = s21_itoa(num, str);
        written += end - str;
        str = end;
        break;
      }
      case 's': {
        const char *s = va_arg(args, const char *);
        s21_strncpy(str, s, s21_strlen(s));
        written += s21_strlen(s);
        str += s21_strlen(s);
        break;
      }
        // case 'f': {
        //   break;
        // }
        // case 'u': {

        //   break;
        // }

      case '%': {
        *str++ = *format++;
        written++;
        break;
      }
      }
    }
    format++;
  }
  *str = '\0';

  return written;
}

char *s21_itoa(int num, char *str) {
  int i = 0;
  int isNegative = 0;
  if (num < 0) {
    isNegative = 1;
    num = -num;
  }
  do {
    str[i++] = num % 10 + '0';
    num /= 10;
  } while (num != 0);

  if (isNegative)
    str[i++] = '-';

  for (int j = 0; j < i / 2; j++) {
    int temp = str[j];
    str[j] = str[i - j - 1];
    str[i - j - 1] = temp;
  }
  str[i] = '\0';
  return str;
}
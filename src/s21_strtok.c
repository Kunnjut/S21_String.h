// #include <stdio.h>
// #include <string.h>
#include "s21_string.h"

// int main() {
//   char str[] = "This is not a bag, this is feature. lalala";

//   printf("Разделение строки \"%s\" на лексемы.\n", str);
//   char* pch = s21_strtok(str, " ,.");  // во втором параметре указаны разделители
//                                    // (пробел, запятая, точка)
//   printf("Лексемы:%s\n", " ,.");
//   while (pch != NULL)  // пока есть лексемы
//   {
//     printf("%s\n", pch);
//     pch = s21_strtok(NULL, " ,.");
//   }
//   return 0;
// }

// char* s21_strtok(char* str, const char* delim) {
//   static char* local;
//   char* tok;
//   if (str) {
//     local = str;
//   }
//   // найти первое вхождение разделителя
//   // заменить на NULL
//   // local передвинуть на символ за разделителем
//   // tok устанавливаем на начало найденого токена
//   // возврат токена
// }

char* s21_strtok(char* str, const char* delim) {
  static char* local;
  char* tok = s21_NULL;
  int jd = 0;
  if (str) {
    local = str;
  }
      tok = local;
  for(; *local != '\0';local++){
    if (s21_strchr(delim, *local) != s21_NULL){
      if (jd == 0){
        tok++;
      }
      else{
        *local = '\0';
        local++;
        break;
      }
    }
    jd++;
  }
  if (tok == local) return (s21_NULL);
  return tok;
}
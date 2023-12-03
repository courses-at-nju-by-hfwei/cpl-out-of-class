//
// Created by hfwei on 2023/12/3.
//

#include <stdio.h>
#include <string.h>

int main(void) {
  const char *msg = "Hello World!";
  printf("msg: %s\n", msg);

  // move to '\0'
  msg += strlen("Hello World!");
  // move one step further
  msg++;
  printf("%s", msg);

  return 0;
}

void StrCpy3(char *dest, const char *src) {
  while ((*dest = *src) != '\0') {
    src++;
    dest++;
  }

  // printf("%s\n", src);
}

void StrCpy4(char *dest, const char *src) {
  while ((*dest++ = *src++) != '\0');

  // printf("%s\n", src);
}
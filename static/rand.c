//
// Created by hfwei on 2023/11/11.
//

#include <stdio.h>

int rand(void);

int main(void) {
  for (int i = 0; i < 10; ++i) {
    printf("%d\n", rand());
  }
}

int rand(void) {
  static unsigned int seed = 1;

  seed = seed * 1103515245 + 12345;
  return (int) ((seed / 65536) % 32768);
}
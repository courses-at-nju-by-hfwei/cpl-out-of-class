//
// Created by hfwei on 2023/10/14.
//

#include <stdio.h>

#define LEN 10
int numbers[LEN] = { 0 };

int main(void) {
  int len = -1;

  while (scanf("%d", &numbers[++len]) != EOF);

  for (int i = 0; i < len; i++) {
    printf("%d ", numbers[i]);
  }
  printf("\n");

  return 0;
}

// setvbuf(stdout, NULL, _IONBF, 0);
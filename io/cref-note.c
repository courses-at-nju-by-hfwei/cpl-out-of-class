//
// Created by hfwei on 2023/9/21.
//

#include <stdio.h>

// Example from c-reference: https://en.cppreference.com/w/c/io/fscanf
int main(void) {
  int a = 0;
  int b = 0;
  char c = 'a';

  scanf("%d", &a);
  scanf("%d", &b);
  printf("a = %d, b = %d\n", a, b);

  scanf("%d", &a);
  scanf(" %c", &c); // consume all consecutive whitespace after %d, then read a char
  printf("a = %d, c = %c\n", a, c);

  return 0;
}
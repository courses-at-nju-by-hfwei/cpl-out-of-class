//
// Created by hfwei on 2023/10/9.
//

#include <stdio.h>

#define NUM 5

int main(void) {
  int numbers[NUM] = {1968, 1961, 1969, 1954, 1969};

  int min = numbers[0];

  // syntax + semantics
  // syntax: for (init-clause; condition-expression; iteration-expression) loop-body
  // semantics:
  // iter 0: i = 1     i < 5
  // iter 1: min = 1961 ([1]) i = 2   i < 5
  // iter 2: min = 1961 ([1]) i = 3   i < 5
  // iter 3: min = 1954 ([3]) i = 4   i < 5
  // iter 4: min = 1954 ([4]) i = 5 exit the loop
  for (int i = 1;
       i < NUM;
       i++) {
    if (numbers[i] < min) {
      min = numbers[i];
    }
  }

  printf("min = %d\n", min);

  return 0;
}
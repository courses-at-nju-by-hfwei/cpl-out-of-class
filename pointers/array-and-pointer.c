//
// Created by hfwei on 2023/12/14.
//

#include <stdio.h>

int Sum(const int numbers[], size_t len);

int main(void) {
  int numbers[] = { 1, 1, 2, 3, 5, };

  // (1) sizeof: as the operand of sizeof
  size_t len = sizeof numbers / sizeof(numbers[0]);
  printf("len = %zu\n", len);
  printf("sizeof numbers : %zu\n", sizeof(numbers));

  // (2) &: as the operand of the address-of operator
  // int **ptr = &numbers;
  int (*ptr_numbers)[len] = &numbers;

  // (3) as the string literal used for array initialization
  // char msg = { 'H', 'i', '\0' };
  char msg[] = "Hi";
  printf("sizeof msg = %zu\n", sizeof msg);

  char *msg_ptr = "Hi";
  printf("sizeof msg_ptr = %zu\n", sizeof msg_ptr);

  // (4) as a function argument
  Sum(numbers, len);

  return 0;
}

// const int numbers: const int *numbers
int Sum(const int numbers[], size_t len) {
  printf("sizeof numbers = %zu\n", sizeof numbers);

  int sum = 0;
  for (int i = 0; i < len; ++i) {
    sum += numbers[i];
  }

  return sum;
}
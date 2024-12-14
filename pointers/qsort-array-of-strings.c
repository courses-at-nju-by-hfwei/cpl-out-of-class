// Created by hfwei on 2024/12/13.

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define ROWS 2
#define COLS 12

int CompareStrs(const void *left, const void *right);
int CompareStrsWrong(const void *left, const void *right);
void Print(char str_arr[][COLS], int rows);

int main(void) {
  char str_arr[ROWS][COLS] = {
      "abcdefghijk", "ABCDEFGHIJK"
  };

  qsort(str_arr, ROWS, COLS,
        CompareStrs);
  Print(str_arr, ROWS);

  qsort(str_arr, ROWS, COLS,
        CompareStrsWrong);
  Print(str_arr, ROWS);
}

int CompareStrs(const void *left, const void *right) {
  const char *left_str = left;
  const char *right_str = right;
  return strcmp(left_str, right_str);
}

int CompareStrsWrong(const void *left, const void *right) {
  char *const *left_str_ptr = left;
  char *const *right_str_ptr = right;
  char *left_str = *left_str_ptr; // for debug
  char *right_str = *right_str_ptr; // for debug
  return strcmp(*left_str_ptr, *right_str_ptr);
}

void Print(char str_arr[][COLS], int rows) {
  for (int i = 0; i < rows; ++i) {
    printf("%s\n", str_arr[i]);
  }
  printf("\n");
}
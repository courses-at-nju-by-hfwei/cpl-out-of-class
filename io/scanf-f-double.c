//
// Created by hfwei on 2024/9/24.
//

#define NUM 5

#include <stdio.h>

int main(void) {
  double data[NUM];
  for (int i = 0; i < NUM; i = i + 1) {
    scanf("%f", &data[i]);//投入对应数组中的变量地址
  }

  for (int i = 0; i < NUM; i++) {
    printf("%f\n", data[i]);
  }

  double minimum = data[0];
  for (int n = 0; n < NUM; n = n + 1) {
    if (minimum > data[n]) {
      minimum = data[n];
    }
  }
  printf("min = %.2f\n", minimum);
  return 0;
}
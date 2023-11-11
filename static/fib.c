//
// Created by hfwei on 2023/11/11.
//

#include <stdio.h>

long long Fib(int n);

int main(void) {
  int n;
  scanf("%d", &n);

  printf("Fib(%d) = %lld\n", n, Fib(n));
}

long long Fib(int n) {
  // (1) counting (and printing out) how many times Fib has been called
  // static int count = 0;
  // count++;
  // printf("count = %d\n", count);

  // (2) memo
  static long long fib[100] = {0};

  if (n <= 1) {
    return n;
  }

  if (fib[n] != 0) {
    return fib[n];
  }

  fib[n] = Fib(n - 1) + Fib(n - 2);
  return fib[n];
}
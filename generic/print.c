// Created by hfwei on 2024/12/14.

#include <stdio.h>
#include <limits.h>

void PrintInts(const int *integers, size_t len);
void PrintStrs(const char *str[], size_t len);

// (since C11)
// _Generic ( controlling-expression , association-list )
// See Section 9.7 of the textbook
#define Print(x, y) _Generic((x), \
    int *: PrintInts, \
    const char **: PrintStrs \
    )((x), (y))

int main(void) {
  int integers[] = {-2, 99, 0, -743, 2, INT_MIN, 4};
  int size_of_integers = sizeof integers / sizeof *integers;
//  PrintInts(integers, size_of_integers);
  Print(integers, size_of_integers);

  const char *names[] = {
      "Luo Dayou", "Cui Jian", "Dou Wei", "Zhang Chu",   "Wan Qing",
      "Li Zhi",    "Yao",      "ZuoXiao", "ErShou Rose", "Hu Mage",
  };
  size_t size_of_names = sizeof names / sizeof *names;
//  PrintStrs(names, size_of_names);
  Print(names, size_of_names);

  return 0;
}

void PrintInts(const int *integers, size_t len) {
  printf("\n");
  for (int i = 0; i < len; i++) {
    printf("%d ", integers[i]);
  }
  printf("\n");
}

void PrintStrs(const char *str[], size_t len) {
  printf("\n");
  for (int i = 0; i < len; i++) {
    printf("%s\n", str[i]);
  }
  printf("\n");
}
// Created by hengxin on 2024/12/04.

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*CompareFunction)(const void *, const void *);
typedef int CompFunc(const void *, const void *);

int CompareStrs(const void *left, const void *right);
int CompareStrsWrong(const void *left, const void *right);

int StrCmpStd(const char *s1, const char *s2);

void PrintStrs(const char *str[], size_t len);

int main() {
  /**
   * void qsort( void *ptr, size_t count, size_t size,
            int (*comp)(const void *, const void *) );
   * typedef int _Cmpfun(const void *, const void *);
   * void qsort( void *ptr, size_t count, size_t size, _Cmpfun *comp);
   */
  const char *names[] = {
      "Luo Dayou", "Cui Jian", "Dou Wei", "Zhang Chu",   "Wan Qing",
      "Li Zhi",    "Yao",      "ZuoXiao", "ErShou Rose", "Hu Mage",
  };
  size_t size_of_names = sizeof names / sizeof *names;

  qsort(names, size_of_names, sizeof *names, CompareStrs);
  PrintStrs(names, size_of_names);

  qsort(names, size_of_names, sizeof *names, CompareStrsWrong);
  PrintStrs(names, size_of_names);
}

int CompareStrs(const void *left, const void *right) {
  const char *const *pp1 = left;
  const char *const *pp2 = right;
  return strcmp(*pp1, *pp2);
}

// Why keep the original order???
// What are compared???
int CompareStrsWrong(const void *left, const void *right) {
  const char *pp1 = left;
  const char *pp2 = right;
  return strcmp(pp1, pp2);
}

int StrCmpStd(const char *s1, const char *s2) {
  for (; *s1 == *s2; s1++, s2++) {
    if (*s1 == '\0') {
      return 0;
    }
  }

  // just for debug
  const unsigned char s1_char = *((const unsigned char *)s1);
  const unsigned char s2_char = *((const unsigned char *)s2);

  return *((const unsigned char *)s1) - *((const unsigned char *)s2);
}

void PrintStrs(const char *str[], size_t len) {
  printf("\n");
  for (int i = 0; i < len; i++) {
    printf("%s\n", str[i]);
  }
  printf("\n");
}
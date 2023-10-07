//
// Created by hfwei on 2023/10/7.
//

#include <stdio.h>

// Example 2 from C17 (Page 234)
int main(void) {
  int i;
  double x; // original: float x;
  char name[50];

  // original: fscanf
  sscanf("56789 0123 56a72",
         "%2d%lf%*d %[0123456789]",
         &i, &x, name);

  // i = 56
  // x = 789.000000
  // name = 56
  printf("i = %d\n"
         "x = %f\n"
         "name = %s\n",
         i, x, name);

  return 0;
}
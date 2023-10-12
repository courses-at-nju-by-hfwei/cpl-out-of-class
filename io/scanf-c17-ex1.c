//
// Created by hfwei on 2023/10/7.
//

#include <stdio.h>

// Example 1 from C17 (Page 234)
int main(void) {
  int n;
  int i;
  double x; // original: float x;
  char name[50];

  // original: fscanf
  n = sscanf("25 54.32E-1 thompson",
             "%d%lf%49s",
             &i, &x, name);

  // n = 3
  // i = 25
  // x = 5.432000
  // name = thompson
  printf("n = %d\n"
         "i = %i\n"
         "x = %f\n"
         "name = %s\n",
         n, i, x, name);

  printf("\n");

  // UB (Undefined Behavior)
  // n = 3
  // wrong-i = 0.000000       (i = 25)
  // wrong-x = 893353198      (x = 5.432000)
  // name = thompson
  printf("n = %d\n"
         "wrong-i = %f\n"
         "wrong-x = %d\n"
         "name = %s\n",
         n, i, x, name);

  return 0;
}
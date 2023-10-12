//
// Created by hfwei on 2023/10/7.
//

#include <stdio.h>

// Example 4 from C17 (Page 235)
int main(void) {
  int d1 = 0, d2 = 0, n1 = 0, n2 = 0, i = 0;

  i = sscanf("123",
             "%d%n%n%d",
             &d1, &n1, &n2, &d2);

  printf("d1 = %d\n"
         "n1 = %d\n"
         "n2 = %d\n"
         "d2 = %d\n"
         "i = %d\n",
         d1, n1, n2, d2, i);

  // output
  // d1 = 123
  // n1 = 3
  // n2 = 3
  // d2 = 0
  // i = 1
  return 0;
}
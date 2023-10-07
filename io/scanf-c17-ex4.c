//
// Created by hfwei on 2023/10/7.
//

#include <stdio.h>

// Example 4 from C17 (Page 235)
int main(void) {
  int d1, d2, n1, n2, i;

  i = sscanf("123", "%d%n%n%d", &d1, &n1, &n2, &d2);

  printf("d1 = %d\n"
         "n1 = %d\n"
         "n2 = %d\n"
         "d2 = %d\n"
         "i = %d\n",
         d1, n1, n2, d2, i);

  return 0;
}
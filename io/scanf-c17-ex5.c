//
// Created by hfwei on 2023/10/7.
//

#include <stdio.h>

// Example 5 from C17 (Page 235)
int main(void) {
  int n = 0;
  int i = 0;

  // On Linux: n = 1  i = 42
  // On Windows: n = 0  i = 0 (Bug? See https://stackoverflow.com/q/77249663/1833118)
  n = sscanf("foo %bar 42",
             "foo%%bar%d",
             &i);

  printf("n = %d\n"
         "i = %d\n",
         n, i);
  return 0;
}
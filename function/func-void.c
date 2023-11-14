//
// Created by hfwei on 2023/11/14.
//

int f(void); // declaration: takes no parameters
int g(); // declaration: takes unknown parameters

int main(void) {
  f(1); // compile-time error
  g(2); // undefined behavior
}

int f(void) { return 1; } // actual definition
int g(a, b, c, d)int a, b, c, d; { return 2; } // actual definition
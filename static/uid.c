// file: uid.c
//
// Visualization: https://pythontutor.com/render.html#code=%23include%20%3Cstdio.h%3E%0A%0A//%20UID%3A%20Unique%20Identifier%0Aint%20GenerateUID%28%29%3B%0A%0Aint%20main%28%29%20%7B%0A%20%20for%20%28int%20i%20%3D%200%3B%20i%20%3C%2010%3B%20%2B%2Bi%29%20%7B%0A%20%20%20%20printf%28%22ID%3A%20%25d%5Cn%22,%20GenerateUID%28%29%29%3B%0A%20%20%7D%0A%0A%20%20return%200%3B%0A%7D%0A%0Aint%20GenerateUID%28%29%20%7B%0A%20%20static%20int%20id%20%3D%201%3B%0A%0A%20%20return%20id%2B%2B%3B%0A%7D&cumulative=true&curInstr=43&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
// Created by hfwei on 2023/11/11.

#include <stdio.h>

// UID: Unique Identifier

int GenerateUID();

int main() {
  for (int i = 0; i < 10; ++i) {
    printf("ID: %d\n", GenerateUID());
  }

  return 0;
}

int GenerateUID() {
  static int id = 0;
  return id++;
}
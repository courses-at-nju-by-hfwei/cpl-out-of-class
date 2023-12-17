//
// Created by hfwei on 2023/12/17.
//

#include <stdio.h>
#include <stdlib.h>

#define LEN 3
#define ROW 3
#define COL 4

int main(void) {
  // (1) One-Dimensional Array
  // Visualization: https://pythontutor.com/render.html#code=%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstdlib.h%3E%0A%0A%23define%20LEN%203%0A%0A//%20%281%29%20One-Dimensional%20Array%0Aint%20main%28void%29%20%7B%0A%20%20int%20*array%20%3D%20malloc%28LEN%20*%20sizeof%20*array%29%3B%0A%20%20if%20%28array%20%3D%3D%20NULL%29%20%7B%0A%20%20%20%20printf%28%22malloc%20failed%5Cn%22%29%3B%0A%20%20%20%20return%20EXIT_FAILURE%3B%20%20//%20return%201%3B%0A%20%20%7D%0A%0A%20%20//%20fill%20in%0A%20%20for%20%28int%20i%20%3D%200%3B%20i%20%3C%20LEN%3B%20%2B%2Bi%29%20%7B%0A%20%20%20%20array%5Bi%5D%20%3D%20i%20*%20i%3B%0A%20%20%7D%0A%0A%20%20//%20free%0A%20%20free%28array%29%3B%0A%0A%20%20return%200%3B%0A%7D&cppShowMemAddrs=true&cumulative=true&curInstr=0&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
  // malloc
  int *array = malloc(LEN * sizeof *array);
  if (array == NULL) {
    printf("malloc failed\n");
    return EXIT_FAILURE;
  }

  // fill in
  for (int i = 0; i < LEN; ++i) {
    array[i] = i * i;
  }

  // print
  for (int i = 0; i < LEN; ++i) {
    printf("%d ", array[i]);
  }
  printf("\n\n");

  // free
  free(array);

  // (2) Two-Dimensional Array
  // Visualization: https://pythontutor.com/render.html#code=%23include%20%3Cstdlib.h%3E%0A%0A%23define%20ROW%203%0A%23define%20COL%204%0A%0A//%20%282%29%20Two-Dimensional%20Array%0Aint%20main%28void%29%20%7B%0A%20%20int%20%28*table%29%5BCOL%5D%20%3D%20malloc%28ROW%20*%20sizeof%20*table%29%3B%0A%0A%20%20//%20fill%20in%0A%20%20for%20%28int%20i%20%3D%200%3B%20i%20%3C%20ROW%3B%20%2B%2Bi%29%20%7B%0A%20%20%20%20for%20%28int%20j%20%3D%200%3B%20j%20%3C%20COL%3B%20%2B%2Bj%29%20%7B%0A%20%20%20%20%20%20table%5Bi%5D%5Bj%5D%20%3D%20i%20*%20j%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%0A%20%20//%20free%0A%20%20free%28table%29%3B%0A%0A%20%20return%200%3B%0A%7D&cppShowMemAddrs=true&cumulative=true&curInstr=0&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
  // malloc
  int (*table)[COL] = malloc(ROW * sizeof *table);

  // fill in
  for (int i = 0; i < ROW; ++i) {
    for (int j = 0; j < COL; ++j) {
      table[i][j] = i * j;
    }
  }

  // print
  for (int i = 0; i < ROW; ++i) {
    for (int j = 0; j < COL; ++j) {
      printf("%d ", table[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  // free
  free(table);

  // (3) One-Dimensional Array of Pointers
  // Visualization: https://pythontutor.com/render.html#code=%23include%20%3Cstdlib.h%3E%0A%0A%23define%20LEN%203%0A%0A//%20%283%29%20One-Dimensional%20Array%20of%20Pointers%0Aint%20main%28void%29%20%7B%0A%20%20int%20*array_of_pointers%5BLEN%5D%3B%0A%20%20for%20%28int%20i%20%3D%200%3B%20i%20%3C%20LEN%3B%20%2B%2Bi%29%20%7B%0A%20%20%20%20array_of_pointers%5Bi%5D%20%3D%20malloc%28%28i%20%2B%201%29%20*%20sizeof%20*array_of_pointers%5Bi%5D%29%3B%0A%20%20%20%20for%20%28int%20j%20%3D%200%3B%20j%20%3C%20i%20%2B%201%3B%20%2B%2Bj%29%20%7B%0A%20%20%20%20%20%20array_of_pointers%5Bi%5D%5Bj%5D%20%3D%20i%20*%20j%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%0A%20%20//%20free%0A%20%20for%20%28int%20i%20%3D%200%3B%20i%20%3C%20LEN%3B%20%2B%2Bi%29%20%7B%0A%20%20%20%20free%28array_of_pointers%5Bi%5D%29%3B%0A%20%20%7D%0A%0A%20%20return%200%3B%0A%7D&cppShowMemAddrs=true&cumulative=true&curInstr=0&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
  // malloc and fill in
  int *array_of_pointers[LEN];
  for (int i = 0; i < LEN; ++i) {
    array_of_pointers[i] = malloc((i + 1) * sizeof *array_of_pointers[i]);
    for (int j = 0; j < i + 1; ++j) {
      array_of_pointers[i][j] = i * j;
    }
  }

  // print
  for (int i = 0; i < LEN; ++i) {
    for (int j = 0; j < i + 1; ++j) {
      printf("%d ", array_of_pointers[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  // free
  for (int i = 0; i < LEN; ++i) {
    free(array_of_pointers[i]);
  }

  // (4) Two-Dimensional Array with Potentially Non-Contiguous Memory
  // Visualization: https://pythontutor.com/render.html#code=%23include%20%3Cstdlib.h%3E%0A%0A%23define%20ROW%203%0A%23define%20COL%204%0A%0A//%20%284%29%20Two-Dimensional%20Array%20with%20Potentially%20Non-Contiguous%20Memory%0Aint%20main%28void%29%20%7B%0A%20%20int%20**matrix%20%3D%20malloc%28ROW%20*%20sizeof%20*matrix%29%3B%0A%20%20for%20%28int%20i%20%3D%200%3B%20i%20%3C%20ROW%3B%20%2B%2Bi%29%20%7B%0A%20%20%20%20matrix%5Bi%5D%20%3D%20malloc%28COL%20*%20sizeof%20*matrix%5Bi%5D%29%3B%0A%20%20%7D%0A%0A%20%20//%20fill%20in%0A%20%20for%20%28int%20i%20%3D%200%3B%20i%20%3C%20ROW%3B%20%2B%2Bi%29%20%7B%0A%20%20%20%20for%20%28int%20j%20%3D%200%3B%20j%20%3C%20COL%3B%20%2B%2Bj%29%20%7B%0A%20%20%20%20%20%20matrix%5Bi%5D%5Bj%5D%20%3D%20i%20*%20j%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%0A%20%20//%20free%0A%20%20for%20%28int%20i%20%3D%200%3B%20i%20%3C%20ROW%3B%20%2B%2Bi%29%20%7B%0A%20%20%20%20free%28matrix%5Bi%5D%29%3B%0A%20%20%7D%0A%20%20free%28matrix%29%3B%0A%0A%20%20return%200%3B%0A%7D&cppShowMemAddrs=true&cumulative=true&curInstr=48&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
  // malloc
  int **matrix = malloc(ROW * sizeof *matrix);
  for (int i = 0; i < ROW; ++i) {
    matrix[i] = malloc(COL * sizeof *matrix[i]);
  }

  // fill in
  for (int i = 0; i < ROW; ++i) {
    for (int j = 0; j < COL; ++j) {
      matrix[i][j] = i * j;
    }
  }

  // print
  for (int i = 0; i < ROW; ++i) {
    for (int j = 0; j < COL; ++j) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  // free
  for (int i = 0; i < ROW; ++i) {
    free(matrix[i]);
  }
  free(matrix);

  // (5) Two-Dimensional Array with Contiguous Memory
  // Visualization: https://pythontutor.com/render.html#code=%23include%20%3Cstdlib.h%3E%0A%0A%23define%20ROW%203%0A%23define%20COL%204%0A%0A//%20%285%29%20Two-Dimensional%20Array%20with%20Contiguous%20Memory%0Aint%20main%28void%29%20%7B%0A%20%20int%20*matrix%20%3D%20malloc%28ROW%20*%20COL%20*%20sizeof%20*matrix%29%3B%0A%0A%20%20//%20fill%20in%0A%20%20for%20%28int%20i%20%3D%200%3B%20i%20%3C%20ROW%3B%20%2B%2Bi%29%20%7B%0A%20%20%20%20for%20%28int%20j%20%3D%200%3B%20j%20%3C%20COL%3B%20%2B%2Bj%29%20%7B%0A%20%20%20%20%20%20matrix%5Bi%20*%20COL%20%2B%20j%5D%20%3D%20i%20*%20j%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%0A%20%20//%20free%0A%20%20free%28matrix%29%3B%0A%0A%20%20return%200%3B%0A%7D&cppShowMemAddrs=true&cumulative=true&curInstr=35&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
  // malloc
  int *matrix_contiguous = malloc(ROW * COL * sizeof *matrix_contiguous);

  // fill in
  for (int i = 0; i < ROW; ++i) {
    for (int j = 0; j < COL; ++j) {
      matrix_contiguous[i * COL + j] = i * j;
    }
  }

  // print
  for (int i = 0; i < ROW; ++i) {
    for (int j = 0; j < COL; ++j) {
      printf("%d ", matrix_contiguous[i * COL + j]);
    }
    printf("\n");
  }

  // free
  free(matrix_contiguous);

  return 0;
}
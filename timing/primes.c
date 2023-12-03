//
// Created by hfwei on 2023/10/11.
//

#include <stdio.h>
#include <stdbool.h>
#include <time.h>

int main(void) {
  int max = 0;
  scanf("%d", &max);

  // TODO: print primes between 1 and max
  int count = 0;

  time_t start = time(NULL);

  for (int number = 2; number <= max; number++) {
    // decide whether number is a prime
    // Since C99: bool (macro extended to _Bool; with macros true and false)
    // Since C23: will become keywords (bool, true, false); do not need stdbool.h
    bool is_prime = true;
    for (int factor = 2; factor * factor <= number; factor++) {
      if (number % factor == 0) {
        is_prime = false;
        break;  // test: number = 18
      }
    }

    if (is_prime) { // TODO: is_prime == 1; is_prime != 0
      count++;
      printf("%d ", number);  // TODO: comment this for performance
    }
  }

  printf("\ncount = %d\n", count);

  time_t end = time(NULL);
  printf("Time elapsed: %lld seconds\n", end - start);

  return 0;
}
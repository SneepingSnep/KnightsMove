#include "../headers/knights_tour.h"
#include <stddef.h>
#include <stdio.h>

int main() {
  for (size_t i = 0; i < SIZE; i++) {
    for (size_t j = 0; j < SIZE; j++) {
      printf("x ");
    }
    puts("");
  }
  return 0;
}
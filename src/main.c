#include "../headers/knights_tour.h"
#include "stdbool.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int input = 0;
int chssqrinterval[] = {8, 16, 32, 40, 48, 56, 64};
int loopstatus = 1;
int firstcordinate, secondcordinate;
board_t chess = {};
bool fuck = true;
int main() {
  srand(time(NULL));
  while (fuck) {
    size_t rando = rand() % 63;

    firstcordinate = (rando / 8);
    secondcordinate = (rando % 8);
    printf("%d ", firstcordinate);
    printf("%d\n", secondcordinate);
    chess[firstcordinate][secondcordinate] = 1;
    printf("rando numbo: %llu\n", rando);
    // for (size_t i = 0; i < SIZE; i++) {
    //   for (size_t j = 0; j < SIZE; j++) {
    //     if (((i + 1) * (j + 1)) == rando) {
    //       chess[i][j] = 1;
    //       loopstatus = 0;
    //       break;
    //     }
    //   }
    //   if (loopstatus == 0)
    //     break;
    //   puts("");
    // }
    for (size_t i = 0; i < SIZE; i++) {
      for (size_t j = 0; j < SIZE; j++) {

        printf("%llu ", chess[i][j]);
      }
      puts("");
    }
    printf("Want to try again?");
    scanf("%d", &input);
    if (input == 1) {
      break;
    }
  }
  return 0;
}

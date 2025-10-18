#include "../headers/knights_tour.h"
#include <stddef.h>
#define MOVE_COUNT 8 /**< Number of moves that a knight can make */
const int MOVES_X[MOVE_COUNT] = {2, 1, -1, -2, -2, -1, 1, 2};
const int MOVES_Y[MOVE_COUNT] = {1, 2, 2, 1, -1, -2, -2, -1};
bool move_is_possible(size_t move_id, size_t *x, size_t *y, board_t visited) {
  // Check om det er et lovligt move(Lovligt hvis vi ikke har været der, og vi
  // ikke ryger ud af brættet hvis vi gør det) hvis det er lovligt så ryk
  // derhend, og returner true (evt lav move her også) hvis det ikke er lovlig
  // returner false.
  int tempX = *x + MOVES_X[move_id];
  int tempY = *y + MOVES_Y[move_id];

  if ((int *)x + (int)MOVES_X[move_id] >= 0 &&
      (int *)y + (int)MOVES_Y[move_id] >= 0) {
    visited[tempX][tempY] = 1;
    return true;
  }

  return false;
}

void printBoard(board_t board) {
  for (size_t i = 0; i < SIZE; i++) {
    for (size_t j = 0; j < SIZE; j++) {

      printf("%-2llu ", board[i][j]);
    }
    puts("");
  }
}
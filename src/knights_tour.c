#include "../headers/knights_tour.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MOVE_COUNT 8 /**< Number of moves that a knight can make */
board_t visitedArr = {};
const int MOVES_X[MOVE_COUNT] = {2, 1, -1, -2, -2, -1, 1, 2};
const int MOVES_Y[MOVE_COUNT] = {1, 2, 2, 1, -1, -2, -2, -1};
bool move_is_possible(size_t move_id, size_t x, size_t y, board_t visited) {

  int tempX = (int)x + MOVES_X[move_id];
  int tempY = (int)y + MOVES_Y[move_id];

  if (tempX >= 0 && tempY >= 0 && tempX < SIZE && tempY < SIZE &&
      visited[tempX][tempY] == 0) {
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

unsigned int tour_greedy(size_t start_x, size_t start_y) {
  board_t chessarrvisited = {};
  size_t count = 1;
  bool fuck = 1;
  size_t xCord = start_x;
  size_t yCord = start_y;
  chessarrvisited[start_x][start_y] = 1;
  visitedArr[start_x][start_y] += 1;
  while (fuck) {
    for (size_t moves = 0; moves < MOVE_COUNT; moves++) {
      bool possible = move_is_possible(moves, xCord, yCord, chessarrvisited);
      if (possible) {
        xCord += MOVES_X[moves];
        yCord += MOVES_Y[moves];
        chessarrvisited[xCord][yCord] = 1;
        visitedArr[xCord][yCord]++;

        count++;
        break;
      } else if (!possible && moves == MOVE_COUNT - 1) {

        return count;
      }
    }
  }

  return 0;
}

void greedy_tour_from_each_square() {
  size_t solutionMatrix[SIZE][SIZE];
  for (size_t row = 0; row < SIZE; row++) {
    for (size_t col = 0; col < SIZE; col++) {
      unsigned int knightMoves = tour_greedy(row, col);
      solutionMatrix[row][col] = knightMoves;
    }
  }
  puts("Solutions matrix!!");
  printBoard(solutionMatrix);
  puts("");
  puts("How many times each square was visited");
  printBoard(visitedArr);
}
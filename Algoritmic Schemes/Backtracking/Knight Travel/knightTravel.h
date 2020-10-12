#ifndef __KNIGHT_TRAVEL_H__
#define __KNIGHT_TRAVEL_H__

void knightTravel(int num, int *success, int x, int y, int **board, int dim ,int *movX, int *movY);
int **createAndInitBoard(int dim);
void printBoard(int **board, int dim);

#endif

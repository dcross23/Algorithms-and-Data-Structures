#ifndef __EIGHT_QUEENS_H__
#define __EIGHT_QUEENS_H__

#include <stdio.h>

// Number of queens
#define QUEENS 8

//Struct to store solutions
typedef struct solution{
	int num;	//To store the solution number
	int numQueens;  //Number of queens of the solution
	char **sol; 	//Bidimension array to store the board with the solution
}Solution;


int solNumber;

void queensAlg(int currentQueen,int *success,int *x, int *rows,int *d, int *t, int numQueens);
void queensAlgAllSolutions(int currentQueen,int *solution, int *rows,int *d, int *t, int numQueens, FILE *niceFile);

Solution* createBoardSolution(int *solution, int numQueens);
void saveSolution(Solution *solution, FILE *niceFile);

#endif

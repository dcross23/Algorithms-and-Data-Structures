#include <stdio.h>
#include <stdlib.h>

#include "knightTravel.h"

#define DIM 8

int main(int argc, char **argv){
	//Posibble movements for the horse
	int movX[8]={-2,-2,-1,-1, 1, 1, 2,2};  //Mov in x
	int movY[8]={-1, 1,-2, 2,-2, 2,-1,1};  //Mov in y
	
	int success=0;	//Indicates if there is solution or not
	int dim;	//Dimension of the board
	int **board; 	//Board for the algorithm
	
	
	//Create board
	do{
		printf("Dimension of the board (>0)?:");
		scanf("%d%*c",&dim);
	}while(dim <= 0);
		
	board = createAndInitBoard(dim);
	
	
	//Set initial position
	int x0; //pos x initial
	int y0; //pos y initial
	
	printf("Set start position\n");
	do{
		printf(" row? (0-%d):",dim-1);
		scanf("%d%*c",&x0);
	}while(x0 < 0 || x0>=dim);
	
	do{
		printf(" column? (0-%d):",dim-1);
		scanf("%d%*c",&y0);
	}while(y0 < 0 || y0>=dim);
	
	
	//Algorithm
	printf("\n\033[0;31m       Initial position -> (%d,%d) \033[0m",x0,y0);
	board[x0][y0]=1; //Set initial position in the board
	knightTravel(2, &success, x0, y0, board, dim, movX, movY);
	
	if(success)
		printBoard(board,dim);   
	else
		printf("\nThere is no solution\n");            
	
	puts("");
	return 0;
}





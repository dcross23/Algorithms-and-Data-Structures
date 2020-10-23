#include <stdio.h>
#include <stdlib.h>

#include "knightTravel.h"

/* Backtraking algorithm to solve the knight travel problem. This problem consists on travelling
 *  all the chess boxes using a knight. 
 * 
 * This algorithm uses 2 arrays representing the possible movements for the knight (movX and movY).
 *  There are 8 possible movements for the knight, ignoring the ones that cause the knight to go out
 *  of the board.
 * The algorithm gets and initial position and calculates the next possible box using this movements,
 *  checking if the new position is inside the board and the box is free or not. If the box is free,
 *  it registers the movement in the board and searches recursively using this new position as the 
 *  "initial position" for the next movement.
 *	
 * The algorithm will end when the knight has visited the entire board (there is a solution) or when it 
 *  can no longer move because there are no more possible movements.
 */
void knightTravel(int num, int *success, int x, int y, int **board, int dim ,int *movX, int *movY){
	*success = 0;
	int j = -1;
	int xn, yn;

	do{
	    	j++;
	    	//Moves from x,y calculating the next possible box (xn,yn)
	    	xn = x + movX[j];
	    	yn = y + movY[j];
	    	
	    	if((xn<dim && xn>=0) && (yn<dim && yn>=0) && (board[xn][yn]==0)){
			board[xn][yn] = num;
			
		    if(num < dim*dim){
		    	knightTravel(num+1, success, xn, yn, board, dim, movX, movY);
		    	
		    	if(!(*success)){
		            board[xn][yn] = 0;
		    	}
		        
		    }else{
		        (*success) = 1;
		    }
	       }
	}while(!(*success) && (j<8));
}



/* 
 * Creates a new board and initializes it.
 */
int **createAndInitBoard(int dim){
	int i,j;
	
	//Create board
	int **board;
	board = malloc(dim * sizeof(int *));
	for(i=0; i<dim; i++){
		board[i] = malloc(dim * sizeof(int));
	}
	
	//Initializes it
	for(i=0; i<dim; i++){
		for(j=0; j<dim; j++){
			board[i][j]=0;
		}
	}
	
	return board;
}



/*
 * Prints the board.
 */
void printBoard(int **board, int dim){
	int i,j;
	
	printf("\n");
	for(j=0; j<(dim*5 + 1); j++){
		printf("-");
	}
	printf("\n");
	
	for(i=0; i<dim; i++){
		printf("| ");
		for(j=0; j<dim; j++){
			if(board[i][j] == 1){
				printf("\033[0;31m%2d \033[0m| ",board[i][j]);
			}else{
				printf("%2d | ",board[i][j]);
			}
		}
		
		printf("\n");
		for(j=0; j<(dim*5 + 1); j++){
		printf("-");
	}
		printf("\n");
	}
	printf("\n");	
}

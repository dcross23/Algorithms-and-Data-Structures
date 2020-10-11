#include <string.h>
#include <stdlib.h>

#include "eightQueens.h"

//Counter to store solution number
int solNumber = 1;

/* Gives 1 solution.
 * Backtraking algorithm that solves the N-queens problem. It uses a counter "currentQueen" that marks which queen
 *  is searching for a box to stay. To know in which boxes a queen can or cannot be it uses 3 arrays that store 
 *  what boxes in each row, diagonal or transversal diagonal are o are not busy.
 * 
 * The algorithm "ignores" colums because boxes are searched according to the next clear column. This is, each column
 *  can only have 1 queen, so when a queen is stored in a box, the algorithm works recursively with the rest of 
 *  the board ignoring the busy columns used before.
 * 
 * The algorithm finishes when all queens are placed (there is a solution) or when all posible combinations are tried.
 *  In case there is a solution, it will be returned as and array with the positions in the rows where the queens
 *  where places: for example, if solution[1] = 4 means that theres a queen in the box [1(row)][4(column)] in the board
 */
void queensAlg(int currentQueen,int *success,int *solution, int *rows,int *d, int *t, int numQueens){
	int j=-1;
	*success = 0;
	do{
		j++;
		if(rows[j] && d[currentQueen-j+(numQueens-1)] && t[currentQueen+j]){
			//If there is no queen in the box (row/diagonal/transversal diagonal), 
			//  it registers it in that box
			solution[currentQueen] = j;
			rows[j] = d[currentQueen-j+(numQueens-1)] = t[currentQueen+j] = 0;
			
			if(currentQueen == (numQueens-1)){
				//If the queen registered was the last queen, it means that all 
				// queens where correctly placed and it finishes
				*success = 1;
				
			}else{
				//If the queen registered wasnt the last queen, it means that there
				// are more queens that remain unplaced, so it continues
				queensAlg(currentQueen+1, success, solution, rows, d, t, numQueens);
				
				//If there is no success placing the queen in that box, it goes back,leaves 
				// free the box (row/diagonal/transversal diagonal) and continues with the next 
				// box 
				if(!(*success)){
					rows[j] = d[currentQueen-j+(numQueens-1)] = t[currentQueen+j] = 1;
				}
			}
		}
	
		//If there is no success or there are no more boxes remaining (j == (numQueens-1)), it finishes
	}while(!(*success) && j!=(numQueens-1));
}


/* Gives all posible solutions
 * Backtraking algorithm, same as before, but gives all posible solutions to N-queens problem.
 */
void queensAlgAllSolutions(int currentQueen,int *solution, int *rows,int *d, int *t, int numQueens, FILE *niceFile){
	int j;
	for(j=0; j<numQueens; j++){
		if(rows[j] && d[currentQueen-j+(numQueens-1)] && t[currentQueen+j]){
			solution[currentQueen] = j;
			rows[j] = d[currentQueen-j+(numQueens-1)] = t[currentQueen+j] = 0;
			
			if(currentQueen == (numQueens-1)){
				saveSolution(createBoardSolution(solution,numQueens),niceFile);
				solNumber++;
				
			}else{
				queensAlgAllSolutions(currentQueen+1, solution, rows, d, t, numQueens, niceFile);
			}
			
			rows[j] = d[currentQueen-j+(numQueens-1)] = t[currentQueen+j] = 1;
		}	
	}
}


/* Creates a Solution storing the number, the number of queens used and interpreting
 *  the solution array given by the algorithm transforming it to a bidimensional array
 *  simultating the chess board.
 */
Solution* createBoardSolution(int *solution, int numQueens){
	if(solution == NULL || numQueens <=0) return NULL;
	
	int i,j;
	Solution *sol = malloc(sizeof(struct solution));
	sol->num = solNumber;
	sol->numQueens = numQueens;
	
	sol->sol = malloc(numQueens * sizeof(char *));
	if(sol->sol == NULL)
		return NULL;
		
	for(i=0; i<numQueens; i++){
		(sol->sol)[i] = malloc(numQueens * sizeof(char));
		if((sol->sol)[i] == NULL)
			return NULL;
	}
	
	for(i=0; i<numQueens; i++){
		for(j=0; j<numQueens; j++){
			sol->sol[i][j]='_';
		}
		sol->sol[i][solution[i]]='X';
	}

	return sol;
}

/*
 * Saves a solution in a file. The file can be an external file or the standar output
 *  file to print via terminal the solution.
 */
void saveSolution(Solution *solution, FILE *niceFile){
	if(solution == NULL) return;

	if(niceFile != NULL){
		int i,j,k;
		
		fprintf(niceFile,"SOLUTION %d\n",solution->num);
	
		for(k=0; k<(solution->numQueens*4+1); k++){
			fprintf(niceFile,"-");
		}
		fprintf(niceFile,"\n");
		for(i=0; i<solution->numQueens; i++){
			fprintf(niceFile,"| ");
			
			for(j=0; j<solution->numQueens; j++){
				fprintf(niceFile,"%c | ",solution->sol[i][j]);
			}
			
			fprintf(niceFile,"\n");
			
			for(k=0; k<(solution->numQueens*4+1); k++){
				fprintf(niceFile,"-");
			}
			
			fprintf(niceFile,"\n");
		}
		fprintf(niceFile, "\n");
		
	}
}




#include <stdio.h>
#include <stdlib.h>

#include "eightQueens.h"

int main(int argc, char **argv){
		
	int currentQueen=0;		//Queen that is searching box to stay
	int success;			//For 1 solution, indicates if there is a solution or not for the problem
	int solution[QUEENS];		//Stores the box where each queen is per row (ej: if solution[0]=4, means
					//  that the queen is on row 4, column 0 
					
	int rows[QUEENS];		//Stores the rows that have/not have a queen 
	int diag[QUEENS*2 -1];		//Stores the diagonals that have/not have a queen
	int transDiag[QUEENS*2 -1];	//Stores the transversal diagonals that have/not have a queen

	int i,j,k;
	
	
	// ONE SOLUTION 
	for(i=0; i<QUEENS; i++){
		solution[i] = 0;
		rows[i] = 1;
	}
	for(i=0; i<(QUEENS*2 -1); i++){
		diag[i] = transDiag[i] = 1;
	}
	
	
	queensAlg(currentQueen, &success, solution, rows, diag, transDiag, QUEENS);
	
	Solution* sol = createBoardSolution(solution, QUEENS);
	
	if(sol != NULL){
		//Prints the solution via stdout (terminal)
		saveSolution(sol, stdout);
		
		//Stores solution to external file
		/*
		FILE *f = fopen("solutionQueensAlg.txt","w");
		saveSolution(sol, f);
		fclose(f);
		*/
	}
	
	
	//ALL SOLUTIONS	
	for(i=0; i<QUEENS; i++){
		solution[i] = 0;
		rows[i] = 1;
	}
	for(i=0; i<(QUEENS*2 -1); i++){
		diag[i] = transDiag[i] = 1;
	}
	
	
	//Prints all solutions via stdout (terminal)
	//queensAlgAllSolutions(currentQueen, solution, rows, diag, transDiag, QUEENS, stdout);
	
	FILE *f2 = fopen("allSolutions.txt","w");
	queensAlgAllSolutions(currentQueen, solution, rows, diag, transDiag, QUEENS, f2);
	fclose(f2);
	
	puts("");
	return 0;
}





#include <stdio.h>
#include <stdlib.h>

#include "mazeSolver.h"


int main(int argc, char **argv){
	
	FILE *f = fopen("maze.txt","r");
	
	if(f == NULL) return -1;
	
	Maze *maze = loadMaze(f);
	fclose(f);
	
	//Possible movements from a box to another
	int movX[4]={1,-1,0,0}; //Mov in X
	int movY[4]={0,0,1,-1}; //Mov in Y
	
	maze->movX = movX;
	maze->movY = movY;

	maze->maze[maze->xStart][maze->yStart] = '*';
	int success;
	mazeSolver(maze, &success, maze->xStart, maze->yStart);	
	
	if(!success){
		printf("There is not a suitable path");
	
	}else{
		printMaze(maze);
	}
	
	puts("");
	return 0;
}





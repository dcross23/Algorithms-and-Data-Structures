#ifndef __MAZE_SOLVER_H__
#define __MAZE_SOLVER_H__

#include <stdio.h>

//Struct with info of the maze
typedef struct maze{
	char **maze;
	int width,height;
	int xStart, yStart;
	int xEnd, yEnd;	
	int *movX, *movY;
}Maze;


void mazeSolver(Maze *maze, int *success, int x, int y);
void printMaze(Maze *maze);
Maze *loadMaze(FILE *f);

#endif

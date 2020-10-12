#include <stdio.h>
#include <stdlib.h>

#include "mazeSolver.h"

/* Backtracking algorithm to search for a valid path to solve a maze.
 * Just like the Knight Travel algorithm, it uses a board to store the
 *  maze and 2 arrays with the possible movements the "head" that 
 *  is searching for the path can move.
 * This movements just repeat until the algorithm finds the end or there
 *  are no more possible movements. 
 * In the first case,the algorithm finds a suitable path and returns 
 *  a success, so the maze and the path are printed.
 * In the second case, the algorithm tries all possibilities but it can
 *  not find a path, so it returns no success and finishes. 
 */
void mazeSolver(Maze *maze, int *success, int x, int y){
	*success = 0;
	int j=-1;
	int xn, yn;
	
	do{
		j++;
		xn = maze->movX[j] + x;
		yn = maze->movY[j] + y;
		
		if((xn>=0 && xn<maze->height) && (yn>=0 && yn<maze->width) && (maze->maze[xn][yn]==' ' || maze->maze[xn][yn]=='E')){
			maze->maze[xn][yn]='*';
			
			if(xn==maze->xEnd && yn==maze->yEnd){
				*success = 1;
			
			}else{
				mazeSolver(maze, success, xn, yn);
				
				if(!(*success)){
					maze->maze[xn][yn] =' ';
				} 
			}
		}
	}while((!(*success) && (j<4)));
}

/* Prints the maze showing the start, the end and the path
 */
void printMaze(Maze *maze){
	int i,j;
	printf("\033[1;35mStart -> \033[1;32m*\033[0m\n");
	printf("\033[1;35mEnd   -> \033[1;31m*\033[0m\n");
	printf("\033[1;35mPath  -> \033[0;36m*\033[0m\n\n");
	
	for(i=0; i<maze->height; i++){
		for(j=0; j<maze->width; j++){
			if(i == maze->xStart && j == maze->yStart){
				printf("\033[1;32m%c\033[0m",maze->maze[i][j]);
			
			}else if(i == maze->xEnd && j == maze->yEnd){
				printf("\033[1;31m%c\033[0m",maze->maze[i][j]);
			
			}else if(maze->maze[i][j] == '*'){
				printf("\033[0;36m%c\033[0m",maze->maze[i][j]);
			
			}else{
				printf("%c",maze->maze[i][j]);
			}
		}		
		puts("");
	}
}


/* Loads a maze from a txt file.
 * The maze has to be created using '#' character and the start 
 *  and end have to be marked as 'S' for start and 'E' for end.
 */
Maze *loadMaze(FILE *f){
	Maze *maze = malloc(sizeof(Maze));
	
	char * line = NULL;
    	size_t len = 0;
	int i,j, mazeWidth, mazeHeight;
	
	//Gets the width, height, start and end of the maze
	mazeWidth = mazeHeight = 0;
	while (getline(&line, &len, f) != -1) {	
		i=0;
		while(line[i] != '\n'){
			if(line[i] == 'S'){
				maze->xStart = mazeHeight;
				maze->yStart = i;
			}
			
			if(line[i] == 'E'){
				maze->xEnd = mazeHeight;
				maze->yEnd = i;
			}
			
			i++;
		}
		
		if(i > mazeWidth) mazeWidth = i;
		
		
		mazeHeight++;
	}
	
	//Creates the maze with the data
	maze->width = mazeWidth;
	maze->height = mazeHeight;
	
	maze->maze = malloc(maze->height * sizeof(char *));
	for(i=0; i<maze->height; i++){
		maze->maze[i] = malloc(maze->width * sizeof(char));
	}
	

	//Loads maze into the array
	fseek(f,0,SEEK_SET);
	for(i=0; i<maze->height; i++){
		getline(&line, &len, f);
		for(j=0; j<maze->width; j++){
			if(j<len && line[j] != '\n'){
				maze->maze[i][j] = line[j];
			}else{
				maze->maze[i][j] = ' ';
			}
		}
	}
	
	return maze;
}


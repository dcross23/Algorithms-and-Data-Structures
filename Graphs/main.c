#include "graph.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>


Graph *createExampleGraph();


int main(void){ 
	Graph* gT28 = createExampleGraph();

	initGraph(gT28);
	printGraph(gT28);	

	//Depth First Search ("Recorrido en profundidad")	
  	printf("\nDFS (\"Profundidad\"): \x1b[35;1m");
  	dfs(1,gT28);
  	printf("\x1b[0m");

	initGraph(gT28);
	printf("\nDFS with other start: \x1b[35;1m");
  	dfs(7,gT28);
  	printf("\x1b[0m");


	initGraph(gT28);
  	printf("\nFULL DFS (\"Profunidad mejorado\"): \x1b[35;1m");
  	fullDfs(7,gT28);
  	printf("\x1b[0m\n");


	//Breadth First Search ("Recorrido en amplitud")	
	initGraph(gT28);
 	printf("\nBFS (\"Amplitud\"): \x1b[35;1m");
  	bfs(1,gT28);
  	printf("\x1b[0m");
  	
  	initGraph(gT28);
 	printf("\nBFS with other start: \x1b[35;1m");
  	bfs(5,gT28);
  	printf("\x1b[0m");
  	
  	initGraph(gT28);
 	printf("\nFULL BFS (\"Amplitud mejorado\"): \x1b[35;1m");
  	fullBfs(5,gT28);
  	printf("\x1b[0m\n");
  	
  	printf("\n\x1b[32;1m========================================================================\x1b[0m\n");
  	
  	//Topological sort
  	printf("\nTopological Sort:\x1b[35;1m");
  	if(-1 == topologicalSort(gT28)){
  		printf("\n Cyclic graph, imposible to get topological sort\n");
  	}else{
  		int i, tSort;
		for(tSort=1; tSort<=gT28->order; tSort++){
	  		for(i=1; i<=gT28->order; i++){
	  			if(gT28->vertices[i].topSort == tSort)
	  				printf(" %d", i);
	  		}
	  	}  	
  	
  		printf("\n\x1b[33;3;4mGraph after topologicalSort algorithm:\x1b[0m\n");
  		printGraph(gT28);
  	}
  	
  	
  	printf("\n\nImproved topological Sort:\x1b[35;1m");
  	if(-1 == improvedTopSort(gT28)){
  		printf("\n Cyclic graph, imposible to get topological sort\n");
  	}else{
  		int i, tSort;
		for(tSort=1; tSort<=gT28->order; tSort++){
	  		for(i=1; i<=gT28->order; i++){
	  			if(gT28->vertices[i].topSort == tSort)
	  				printf(" %d", i);
	  		}
	  	}  	
  	
  		printf("\n\x1b[33;3;4mGraph after improvedTopSort algorithm:\x1b[0m\n");
  		printGraph(gT28);
  	}
  	
  	printf("\n\x1b[35;1;4m(Results are different but they are both correct)\x1b[0m\n\n");
  	
	return 0;
}


/**
 *Creates an example graph
 *
 *         1 -> 2
 *	 /  \  / \
 *	v   v v   v
 *	3 <- 4 <- 5
 *	 \  / \  /
 *        vv   vv
 *        6 <- 7
 * 
 */
Graph *createExampleGraph(){ 
	int i;
	GraphEdge *e;
	Graph *g;

	g=(Graph *)calloc(1,sizeof(Graph)); 

	g->order=7; // 7 vertices

	// edges vertex 1
	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
	e->vertex = 2;
	e->weight = 1;
	g->vertices[1].edges=e;

	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
	e->vertex = 3;
	e->weight = 1;
	g->vertices[1].edges->next=e;

	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
	e->vertex = 4;
	e->weight = 1;
	g->vertices[1].edges->next->next=e;
	e->next=NULL;


	// edges vertex 2
	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
	e->vertex = 4;
	e->weight = 1;
	g->vertices[2].edges=e;

	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
	e->vertex = 5;
	e->weight = 1;
	g->vertices[2].edges->next=e;
	e->next=NULL;


	// edges vertex 3
	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
	e->vertex = 6;
	e->weight = 1;
	g->vertices[3].edges=e;
	e->next=NULL;


	// edges vertex 4
	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
	e->vertex = 3;
	e->weight = 1;
	g->vertices[4].edges=e;

	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
	e->vertex = 6;
	e->weight = 1;
	g->vertices[4].edges->next=e;

	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
	e->vertex = 7;
	e->weight = 1;
	g->vertices[4].edges->next->next=e;
	e->next=NULL;


	// edges vertex 5
	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
	e->vertex = 4;
	e->weight = 1;
	g->vertices[5].edges=e;

	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
	e->vertex = 7;
	e->weight = 1;
	g->vertices[5].edges->next=e;
	e->next=NULL;


	// edges vertex 6
	g->vertices[6].edges=NULL;


	// edges vertex 7
	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
	e->vertex = 6;
	e->weight = 1;
	g->vertices[7].edges=e;
	e->next=NULL;

	return g;
}


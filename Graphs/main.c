#include "graph.h"
#include "OtherFiles/graphCreator.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>


int main(void){ 
	Graph* g = createExampleGraph1();

	initGraph(g);
	printGraph(g);	

	//Depth First Search ("Recorrido en profundidad")	
  	printf("\nDFS (\"Profundidad\"): \x1b[35;1m");
  	dfs(1,g);
  	printf("\x1b[0m");

	initGraph(g);
	printf("\nDFS with other start: \x1b[35;1m");
  	dfs(7,g);
  	printf("\x1b[0m");


	initGraph(g);
  	printf("\nFULL DFS (\"Profunidad mejorado\"): \x1b[35;1m");
  	fullDfs(7,g);
  	printf("\x1b[0m\n");


	//Breadth First Search ("Recorrido en amplitud")	
	initGraph(g);
 	printf("\nBFS (\"Amplitud\"): \x1b[35;1m");
  	bfs(1,g);
  	printf("\x1b[0m");
  	
  	initGraph(g);
 	printf("\nBFS with other start: \x1b[35;1m");
  	bfs(5,g);
  	printf("\x1b[0m");
  	
  	initGraph(g);
 	printf("\nFULL BFS (\"Amplitud mejorado\"): \x1b[35;1m");
  	fullBfs(5,g);
  	printf("\x1b[0m\n");
  	
  	printf("\n\x1b[32;1m========================================================================\x1b[0m\n");
  	
  	
  	//Topological sort
  	printf("\nTopological Sort:\x1b[35;1m");
  	if(-1 == topologicalSort(g)){
  		printf("\n Cyclic graph, imposible to get topological sort\n");
  	}else{
  		int i, tSort;
		for(tSort=1; tSort<=g->order; tSort++){
	  		for(i=1; i<=g->order; i++){
	  			if(g->vertices[i].topSort == tSort)
	  				printf(" %d", i);
	  		}
	  	}  	
  	
  		printf("\n\x1b[33;3;4mGraph after topologicalSort algorithm:\x1b[0m\n");
  		printGraph(g);
  	}
  	
  	
  	printf("\n\nImproved topological Sort:\x1b[35;1m");
  	if(-1 == improvedTopSort(g)){
  		printf("\n Cyclic graph, imposible to get topological sort\n");
  	}else{
  		int i, tSort;
		for(tSort=1; tSort<=g->order; tSort++){
	  		for(i=1; i<=g->order; i++){
	  			if(g->vertices[i].topSort == tSort)
	  				printf(" %d", i);
	  		}
	  	}  	
  	
  		printf("\n\x1b[33;3;4mGraph after improvedTopSort algorithm:\x1b[0m\n");
  		printGraph(g);
  	}
  	
  	printf("\n\x1b[35;1;4m(Results are different but they are both correct)\x1b[0m\n");
  	
  	printf("\n\x1b[32;1m========================================================================\x1b[0m\n");
  	
  	
  	//Shortest path algorithms
  	int firstV = 1; 
  	#ifndef WEIGHTED_GRAPHS
  	//No weighted graphs
  		printf(" ");
  		printf("\n\x1b[33;3;4mGraph after npPathsAlgorithm algorithm:\x1b[0m\n");
  		npPathsAlgorithm(firstV,g);
  		printGraph(g);
  		
  		//printf("\n\x1b[33;3;4mGraph after improvedNpPathsAlg algorithm:\x1b[0m\n");
  		//improvedNpPathsAlg(firstV, g);
  		//printGraph(g);
  		
		printf("\n\x1b[33;3;4mAll paths generated\x1b[0m\n");
		seeAllCostsAndPaths(firstV, g);  
		
  	#else
  	//Weighted graphs
  		printf(" ");
  		printf("\n\x1b[33;3;4mGraph after Dijkstra algorithm:\x1b[0m\n");
  		dijkstra(firstV,g);
  		printGraph(g);
  		
  		//printf("\n\x1b[33;3;4mGraph after improvedDijkstra algorithm:\x1b[0m\n");
  		//improvedDijkstra(firstV, g);
  		//printGraph(g);
  		
  		printf("\n\x1b[33;3;4mAll paths generated\x1b[0m\n");
		seeAllCostsAndPaths(firstV, g);  
  	#endif 	
  	
  	
  	printf("\n\n\x1b[32;1m========================================================================\x1b[0m\n");
  	
  	//Spanning trees
  	Graph *spanningTree;
  	
  	g = createExampleGraph2();
  	printf("\n\x1b[33;3;4mOriginal graph:\x1b[0m\n");
  	printGraph(g);
  	
  	spanningTree = prim(g);
  	printf("\n\x1b[33;3;4mSpanning tree graph generated after prim:\x1b[0m\n");
  	printGraph(spanningTree);
  	
  	//spanningTree = improvedPrim(g);
  	//printf("\n\x1b[33;3;4mSpanning tree graph generated after improvedPrim:\x1b[0m\n");
  	//printGraph(spanningTree);
  	
	return 0;
}




#include "graph.h"

#include <stdio.h>
#include "./OtherFiles/linkedListQueue.h"

#define COLOR_TEXT(text) "\x1b[36;1m"#text"\x1b[0m"


/**
 * Initiates the graph with default values.
 */
void initGraph(Graph *g){
	int i,j;
	GraphEdge *e;

	for(i=1; i<=g->order; i++){
		g->vertices[i].visited        = 0;
		g->vertices[i].entryDegree    = 0; 
		g->vertices[i].topologicalOrd = 0;
    		g->vertices[i].distance       = INF;
    		g->vertices[i].weight         = INF;
    		g->vertices[i].previous       = 0; 
	}

	for(i=1; i<=g->order; i++){
		e = g->vertices[i].edges;
	
		while(e!=NULL){
			j = e->vertex;
			(g->vertices[j].entryDegree)++;
			e = e->next;			
		}
	}
}


/**
 * Depth First Search. 
 * Starting from a vertex (firstVertex parameter), the graph is traversed
 *  until there are no more available ways, returning back to next node that
 *  can be reached (first node in first vertex edges list), and repeat
 *  the same process recursively.
 *
 * IMPORTANT!!! It depends on the first node choosen and the type of 
 *  graph (directed or not directed), so some vertices may not be visited.
 *
 * (Is similar to backtracking, starting from a node, travels the graph
 *  and return back when it can not advance more.
 */
void dfs(int firstVertex, Graph *g){ 
	GraphEdge *e;

	printf("%d ",firstVertex);
	g->vertices[firstVertex].visited = 1;
	
	e = g->vertices[firstVertex].edges;
	while (e != NULL){ 
		if (!g->vertices[e->vertex].visited)
			dfs(e->vertex, g);

		e = e->next;
	}
}

/**
 * Solves the problem of DFS when some vertices are not visited.
 * This improvement causes BFS to execute for every not visited
 *  vertex until all of them are visited. 
 *
 * This algorithm makes DFS executable for unconnected graphs.
 */
void fullDfs(int firstVertex, Graph *g){
	int i;
	
	initGraph(g);
	dfs(firstVertex, g);
	
	for(i=1; i<=g->order; i++){
		if(!(g->vertices[i].visited))
			dfs(i, g);
	}
}



/**
 * Breadth First Search. 
 * Starting from a vertex (firstVertex parameter), the graph is traversed
 *  until there are no more adyacent vertices. This is, for every reachable
 *  vertex, the algorithm will visit recursively the adyacent vertices 
 *  until it reaches a node with no more adyacent unvisited vertices.
 *
 * IMPORTANT!!! It depends on the first node choosen and the type of 
 *  graph (directed or not directed), so some vertices may not be visited.
 */
void bfs(int firstVertex, Graph *g){ 
	int v;
	GraphEdge *e;
	LLQueue q;
	createEmptyQueue(&q);
	
	queueAdd(firstVertex, &q);
	while (!isEmpty(&q)){
		queueRemove(&q, &v);
		
		if (!g->vertices[v].visited) {
			printf("%d ",v);
			g->vertices[v].visited=1;
			
			e = g->vertices[v].edges;
			while (e != NULL){
				queueAdd(e->vertex, &q);
				e = e->next;
			}
		}
	}
}

/**
 * Solves the problem of BFS when some vertices are not visited.
 * This improvement causes BFS to execute for every not visited
 *  vertex until all of them are visited. 
 *
 * This algorithm makes BFS executable for unconnected graphs.
 */
void fullBfs(int firstVertex, Graph *g){
	int i;

	initGraph(g);	
	bfs(firstVertex, g);
	
	for(i=1; i<=g->order; i++){
		if(!(g->vertices[i].visited))
			bfs(i, g);
	}
}


/**
 * Prints the graph as a table with all necesary info.
 */
void printGraph(Graph *g){  
	int i;
	GraphEdge *e;

	printf("\n\x1b[36;1mGraph order = %d\x1b[0m\n",g->order);
	printf("       %s \n", COLOR_TEXT(vis entD topO dist weight prev edges));
	printf("     %s \n", COLOR_TEXT(+----+----+----+----+------+----+----->));

	for(i=1;i<=g->order;i++){  
		printf("  %2d %s %2d %s %2d %s %2d %s", 
		       i, COLOR_TEXT(|),   g->vertices[i].visited, COLOR_TEXT(|),
		       g->vertices[i].entryDegree, COLOR_TEXT(|),
		       g->vertices[i].topologicalOrd, COLOR_TEXT(|));

		if (g->vertices[i].distance == INF) 
			printf("  * %s",COLOR_TEXT(|));
		else   
			printf(" %2d %s", g->vertices[i].distance, COLOR_TEXT(|));

		if (g->vertices[i].weight == INF) 
			printf("  *   %s",COLOR_TEXT(|));
		else  
			printf(" %2d   %s", g->vertices[i].weight, COLOR_TEXT(|));


		printf(" %2d %s",g->vertices[i].previous, COLOR_TEXT(|));
		
		e = g->vertices[i].edges;
		while (e != NULL){   
			printf(" ->%2d", e->vertex);	// Grafos no ponderados
			//printf(" ->%2d, %2d", p->v, p->peso); // Grafos ponderados
			e = e->next;
		}
		printf("\n");
	}

	printf("     %s \n\n", COLOR_TEXT(+----+----+----+----+------+----+----->));
}

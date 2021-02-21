#ifndef __GRAPHS_H__
#define __GRAPHS_H__


#define MAX_VERTEX 20 
#define INF 999999

/**
 * Stores info about the edges (vertex is the vertex from where the 
 *  edge originates) 
 */
typedef struct edge{
	int vertex;
	int weight;
	struct edge *next;
} GraphEdge;


/**
 * Stores info about the vertex and the edges that originate from this vertex.
 */
typedef struct{ 
	int visited;
	int entryDegree;
	int topologicalOrd;
	int distance;
	int weight;
	int previous;
	GraphEdge *edges;
} GraphVertex;


/**
 * Stores info of a graph (vertices and graph order).
 */
typedef struct graph{
	GraphVertex vertices[MAX_VERTEX];
	int order;
}Graph;


void printGraph(Graph *g);
void freeGraphLists(Graph *g);


void initGraph(Graph *g);

//Depth First Search        (in spanish, "Recorrido en profundidad")
void dfs(int firstVertex, Graph *g);
void fullDfs(int firstVertex, Graph *g);

//Breadth First Search      (in spanish, "Recorrido en amplitud")
void bfs(int firstVertex, Graph *g);
void fullBfs(int firstVertex, Graph *g);


#endif

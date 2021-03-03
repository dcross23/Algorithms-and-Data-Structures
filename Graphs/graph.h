#ifndef __GRAPHS_H__
#define __GRAPHS_H__


#define MAX_VERTEX 20 
#define INF 999999

#define WEIGHTED_GRAPHS 1  //Comment this for no weighted graphs


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
	int topSort;
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
//void freeGraphLists(Graph *g);


void initGraph(Graph *g);

//Depth First Search        (in spanish, "Recorrido en profundidad")
void dfs(int firstVertex, Graph *g);
void fullDfs(int firstVertex, Graph *g);

//Breadth First Search      (in spanish, "Recorrido en amplitud")
void bfs(int firstVertex, Graph *g);
void fullBfs(int firstVertex, Graph *g);

//Topological Sort  (only directed acyclic and not ponderated graphs)
int topologicalSort(Graph *g);
int improvedTopSort(Graph *g);


//Shortest Path Algorthims
void npPathsAlgorithm(int firstVertex, Graph *g);   //Not weighted graphs 
void improvedNpPathsAlg(int firstVertex, Graph *g); //Not weighted graphs

void dijkstra(int firstVertex, Graph *g);	    //Weighted graphs
static int searchMinDistNoVisVertex(Graph *g);
void improvedDijkstra(int firstVertex, Graph *g);   //Weighted graphs

int seeCostAndPath(int firstVertex, int lastVertex, Graph *g);
void seeAllCostsAndPaths(int firstVertex, Graph *g);

#endif

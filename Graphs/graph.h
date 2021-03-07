#ifndef __GRAPHS_H__
#define __GRAPHS_H__

#include "OtherFiles/kruskalHeap.h"

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


//Init graph function
void initGraph(Graph *g); //Line 20

//Depth First Search        (in spanish, "Recorrido en profundidad")
void dfs(int firstVertex, Graph *g);     //Line 58
void fullDfs(int firstVertex, Graph *g); //Line 80

//Breadth First Search      (in spanish, "Recorrido en amplitud")
void bfs(int firstVertex, Graph *g);     //Line 104
void fullBfs(int firstVertex, Graph *g); //Line 134

//Topological Sort  (only directed acyclic and not weighted graphs)
int topologicalSort(Graph *g); //Line 161
int improvedTopSort(Graph *g); //Line 203


//Shortest Path Algorthims
void npPathsAlgorithm(int firstVertex, Graph *g);   //Not weighted graphs  -> Line 255
void improvedNpPathsAlg(int firstVertex, Graph *g); //Not weighted graphs  -> Line 293

void dijkstra(int firstVertex, Graph *g);	    //Weighted graphs  -> Line 337
static int searchMinDistNoVisVertex(Graph *g);	//Needed for dijkstra  -> Line 369
void improvedDijkstra(int firstVertex, Graph *g);   //Weighted graphs  -> Line 393

int seeCostAndPath(int firstVertex, int lastVertex, Graph *g); //Line 436
void seeAllCostsAndPaths(int firstVertex, Graph *g);	       //Line 467


//Spanning tree algorithms
 //Prim
 Graph* prim(Graph *g);  //Line 493
  static int searchMinWeightNoVisVertex(Graph *g);  //Needed for prim -> Line 524
  static Graph* createNewGraph(Graph *g);           //Needed for prim -> Line 539
  static int insertInList(int v1, int v2, int weight, Graph *new);  //Needed for prim -> Line 569
 Graph* improvedPrim(Graph *g); //Line 600

//Kruskal
 Graph* kruskal(Graph *g); //Line 662
 static void createEdgesHeap(Graph *g, HeapK *hk); //Needed for kruskal -> Line 696
 static void acceptEdge(HeapElementK x, Graph *g); //Needed for kruskal -> Line 735
 

//Other functions
int isConnectedGraph(Graph *g); //Line 779 
void printGraph(Graph *g); //Line 821
#endif

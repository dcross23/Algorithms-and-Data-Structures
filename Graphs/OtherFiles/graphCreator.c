#include "graphCreator.h"

#include <stdlib.h>
/**
 *Creates an example graph (weights are not included in this drawing)
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
Graph *createExampleGraph1(){ 
	int i;
	GraphEdge *e;
	Graph *g;

	g=(Graph *)calloc(1,sizeof(Graph)); 

	g->order=7; // 7 vertices

	// edges vertex 1
	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
	e->vertex = 2;
	#ifndef WEIGHTED_GRAPHS
		e->weight = 1;
	#else
		e->weight = 2;
	#endif
	g->vertices[1].edges=e;

	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
	e->vertex = 3;
	#ifndef WEIGHTED_GRAPHS
		e->weight = 1;
	#else
		e->weight = 4;
	#endif
	g->vertices[1].edges->next=e;

	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
	e->vertex = 4;
	#ifndef WEIGHTED_GRAPHS
		e->weight = 1;
	#else
		e->weight = 1;
	#endif
	g->vertices[1].edges->next->next=e;
	e->next=NULL;


	// edges vertex 2
	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
	e->vertex = 4;
	#ifndef WEIGHTED_GRAPHS
		e->weight = 1;
	#else
		e->weight = 3;
	#endif
	g->vertices[2].edges=e;

	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
	e->vertex = 5;
	#ifndef WEIGHTED_GRAPHS
		e->weight = 1;
	#else
		e->weight = 10;
	#endif
	g->vertices[2].edges->next=e;
	e->next=NULL;


	// edges vertex 3
	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
	e->vertex = 6;
	#ifndef WEIGHTED_GRAPHS
		e->weight = 1;
	#else
		e->weight = 5;
	#endif
	g->vertices[3].edges=e;
	e->next=NULL;


	// edges vertex 4
	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
	e->vertex = 3;
	#ifndef WEIGHTED_GRAPHS
		e->weight = 1;
	#else
		e->weight = 2;
	#endif
	g->vertices[4].edges=e;

	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
	e->vertex = 6;
	#ifndef WEIGHTED_GRAPHS
		e->weight = 1;
	#else
		e->weight = 8;
	#endif
	g->vertices[4].edges->next=e;

	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
	e->vertex = 7;
	#ifndef WEIGHTED_GRAPHS
		e->weight = 1;
	#else
		e->weight = 4;
	#endif
	g->vertices[4].edges->next->next=e;
	e->next=NULL;


	// edges vertex 5
	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
	e->vertex = 4;
	#ifndef WEIGHTED_GRAPHS
		e->weight = 1;
	#else
		e->weight = 2;
	#endif
	g->vertices[5].edges=e;

	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
	e->vertex = 7;
	#ifndef WEIGHTED_GRAPHS
		e->weight = 1;
	#else
		e->weight = 6;
	#endif
	g->vertices[5].edges->next=e;
	e->next=NULL;


	// edges vertex 6
	g->vertices[6].edges=NULL;


	// edges vertex 7
	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
	e->vertex = 6;
	#ifndef WEIGHTED_GRAPHS
		e->weight = 1;
	#else
		e->weight = 1;
	#endif
	g->vertices[7].edges=e;
	e->next=NULL;

	return g;
}



/**
 *Creates a no directed graph (weights are not included in this drawing)
 *
 *         1 --- 2
 *	 /  \   / \
 *	3 -- 4 -- 5
 *	 \  / \  /
 *        6 --- 7
 * 
 */
Graph *createExampleGraph2(){
	int i;
	GraphEdge *e;
	Graph *g;
	
	g = (Graph *)calloc(1, sizeof(Graph));
	g->order = 7;
	
	// edges vertex 1
	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
		e->vertex = 2;
		e->weight = 2;
		g->vertices[1].edges=e;
	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
		e->vertex = 3;
		e->weight = 4;
		g->vertices[1].edges->next=e;
	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
		e->vertex = 4;
		e->weight = 1;
		g->vertices[1].edges->next->next=e;
	e->next = NULL;
	
	//edges vertex 2
	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
		e->vertex = 1;
		e->weight = 2;
		g->vertices[2].edges=e;
	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
		e->vertex = 4;
		e->weight = 3;
		g->vertices[2].edges->next=e;
	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
		e->vertex = 5;
		e->weight = 10;
		g->vertices[2].edges->next->next=e;
	e->next = NULL;
	
	//edges vertex 3
	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
		e->vertex = 1;
		e->weight = 4;
		g->vertices[3].edges=e;
	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
		e->vertex = 4;
		e->weight = 2;
		g->vertices[3].edges->next=e;
	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
		e->vertex = 6;
		e->weight = 5;
		g->vertices[3].edges->next->next=e;
	e->next = NULL;
	
	//edges vertex 4
	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
		e->vertex = 1;
		e->weight = 1;
		g->vertices[4].edges=e;
	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
		e->vertex = 2;
		e->weight = 3;
		g->vertices[4].edges->next=e;
	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
		e->vertex = 3;
		e->weight = 2;
		g->vertices[4].edges->next->next=e;
	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
		e->vertex = 5;
		e->weight = 7;
		g->vertices[4].edges->next->next->next=e;
	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
		e->vertex = 6;
		e->weight = 8;
		g->vertices[4].edges->next->next->next->next=e;
	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
		e->vertex = 7;
		e->weight = 4;
		g->vertices[4].edges->next->next->next->next->next=e;
	e->next = NULL;
	
	//edges vertex 5
	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
		e->vertex = 2;
		e->weight = 10;
		g->vertices[5].edges=e;
	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
		e->vertex = 4;
		e->weight = 7;
		g->vertices[5].edges->next=e;
	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
		e->vertex = 7;
		e->weight = 6;
		g->vertices[5].edges->next->next=e;
	e->next = NULL;
	
	//edges vertex 6
	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
		e->vertex = 3;
		e->weight = 5;
		g->vertices[6].edges=e;
	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
		e->vertex = 4;
		e->weight = 8;
		g->vertices[6].edges->next=e;
	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
		e->vertex = 7;
		e->weight = 1;
		g->vertices[6].edges->next->next=e;
	e->next = NULL;
	
	//edges vertex 7
	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
		e->vertex = 4;
		e->weight = 4;
		g->vertices[7].edges=e;
	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
		e->vertex = 5;
		e->weight = 6;
		g->vertices[7].edges->next=e;
	e = (GraphEdge *)calloc(1,sizeof(GraphEdge));
		e->vertex = 6;
		e->weight = 1;
		g->vertices[7].edges->next->next=e;
	e->next = NULL;

	return g;
}





















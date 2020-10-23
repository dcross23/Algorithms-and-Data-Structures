#include "arraysListsUtilities.h"

int *createArray(int size){
	if(size <=0) 
		return NULL;


	int *array;
	if(NULL == (array=malloc(size * sizeof(int)))){
		#ifdef DEBUG
			fprintf(stderr,"Error: Can not reserve memory for array\n");
		#endif
		return NULL;	
	}

	srand(time(NULL));
	for(int i=0; i<size; i++){
		array[i] = rand() % size;
	}
	return array;
}

int *createSortedArray(int size){
	if(size <=0) 
		return NULL;


	int *array;
	if(NULL == (array=malloc(size * sizeof(int)))){
		#ifdef DEBUG
			fprintf(stderr,"Error: Can not reserve memory for array\n");
		#endif
		return NULL;	
	}

	for(int i=0; i<size; i++){
		array[i] = i;
	}
	return array;

}

void printArray(int *array, int arraySize){
	int i;
	for(i=0; i<arraySize; i++){
		if(i == 0)
			printf("%d",array[i]);
		else
			printf(",%d",array[i]);
	}
}


void swap(int *array, int i, int j){
	typeof(array[0]) temp;
	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

/*=====================================================================================================================================================================================*/

Node* createNode(int info){
	Node *new=NULL;

	if( (new=malloc(sizeof(Node))) == NULL){
		return NULL;
	}
	new->info = info;
	new->next = NULL;
	return new;
}


void createList(Node **list, int numNodes){
	if(*list==NULL){
		int i;
		Node *new=NULL, *last=NULL;	
		
		srand(time(NULL));
		for(i=0; i<numNodes; i++){
			new = createNode( rand()%numNodes );	
			if(*list==NULL){
				*list=new;
				last=new;			
			}else{
				last->next = new;
				last=new;			
			}
			new=NULL;
		}	
	}
}

void printList(Node *list){
	Node *aux=list;
	while(aux!=NULL){
		printf("%d ", aux->info);
		aux = aux->next;	
	}
}
















//////////////////////////////////////////////////////
//			David Lass - CS201 Project 1 			//
// heap.h					 	 					//
// Heap header file. Define Heap object				//
// Each object has root and 2 double linked lists 	//
//////////////////////////////////////////////////////

#include "DlinkList.h"

typedef struct heapobject
    {

    node* root;
	node* nodePointer;
	
	DlinkList *queue;
	DlinkList *heapify;
	
    } heap;
	
extern heap *newHeap(node* rootNode);
extern void add(heap *h, node* addedNode);
extern void heapifys(heap *h, int direction);
extern int extract(heap *h, int direction);
extern int isEmptyH(heap *h);


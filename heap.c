//////////////////////////////////////////////////////
//			David Lass - CS201 Project 1 			//
// heap.c					 	 					//
// Heap c file. 									//
// Describes functions of heap 						//
//////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

static heap *newHeapt(void);

heap *newHeap(node* rootNode)			//function to create a new heap with single node
	{
	heap *q = newHeapt();
	q->root = rootNode;					//sets node as root of heap and creates new lists with it as an object
	q->nodePointer = rootNode;
	listnode *atq = newListNode(rootNode);
	q->queue = newDList(atq);
	q->heapify = newDList(atq);
	return q;
	}
	
void add(heap *h, node* addedNode)		//function to add node to a heap
	{
	node *temp = lastTreeNode(h->queue);//adds to the oldest node with an open slot
	if(!hasLeftC(temp))
	{									//chooses which side to add node too and adds it to the open slot queue
		setLeftC(temp, addedNode);
		listnode *atq = newListNode(addedNode);
		addFront(h->queue, atq);
		addFront(h->heapify, atq);
	}
	else
	{
		setRightC(temp, addedNode);
		removeBack(h->queue);
		removeBack(h->heapify);		
		listnode *atq = newListNode(addedNode);
		addFront(h->queue, atq);
		addFront(h->heapify, atq);
	}
	}
	
void heapifys(heap *h, int direction)		//function sorts the heap into either min heap
	{										//or max heap, depending on the direction provided
	while(!isEmpty(h->heapify))
	{										//loops until all nodes are bubbled down
		node *temp = firstTreeNode(h->heapify);
		if(temp->p != 0 && temp->p->r == temp)		//takes last added node, adds its parent to the queue
		{											
			listnode *abc = newListNode(temp->p);
			addBack(h->heapify, abc);}
	bubbleDown(temp, direction);			//bubbles down node and removes it from the queue
	removeFront(h->heapify);
	}
	h->heapify = h->queue;					//resets queue in case more nodes will be added
	}

int extract(heap *h, int direction)			//function that pops the value from the root node
	{										//replaces the root with the rightmost leaf, &bubbles down
	int i = h->root->val;
	
	if(firstTreeNode(h->heapify)!=h->root)	
	{										//checks that more than one node exists, replaces root with bottom right leaf
		node *temp = firstTreeNode(h->heapify);
		removeFront(h->heapify);
		h->root->val = temp->val;
		if(hasRightC(temp->p))
		{
			listnode *abc = newListNode(temp->p);
			addBack(h->heapify, abc);
			removeRightC(temp->p);
		}
		else
			removeLeftC(temp->p);
		bubbleDown(h->root, direction);		//bubbles new root down based on heap type
	}
	else
	{
		h->root=0;
	}
	
	return i;
	}

int isEmptyH(heap *h)						//function checks if heap is empty
	{return h->root==0;}

/*************** private methods *************/

static heap *newHeapt()					//function to guarentee memory 
    {
    heap *n = (heap *) malloc(sizeof(heap));
    if (n == 0) { fprintf(stderr,"out of memory"); exit(-1); }
    return n;
    }
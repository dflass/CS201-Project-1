//////////////////////////////////////////////////////
//			David Lass - CS201 Project 1 			//
// listnode.h					 	 				//
// List Node c file. 								//
// Defines functions for nodes in DLL				//
//////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include "listnode.h"

static listnode *newNode(void);

/*************** public interface *************/


listnode *newListNode(node *v)
    {
    listnode *p = newNode();
    p->val = v;
    return p;
    }
	
void setPrevN(listnode *current, listnode *p)
	{
	current->prev = p;
	p->next = current;
	}

void setNextN(listnode *current, listnode *n)
	{
	current->next = n;
	n->prev = current;
	}
	
void removeNextN(listnode *current)
	{
	current->next = 0;
	}

void removePrevN(listnode *current)
	{
	current->prev = 0;
	}
	
int hasNextN(listnode *current)
	{
		return(current->next != 0);
	}

int hasPrevN(listnode *current)
	{
		return(current->prev != 0);
	}


/*************** private methods *************/

static listnode *newNode()
    {
    listnode *n = (listnode *) malloc(sizeof(listnode));
    if (n == 0) { fprintf(stderr,"out of memory"); exit(-1); }
    return n;
    }

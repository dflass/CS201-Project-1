//////////////////////////////////////////////////////
//			David Lass - CS201 Project 1 			//
// listnode.h					 	 				//
// List Node header file. Define link list nodes	//
// Each has a treenode, previous and next list node	//
//////////////////////////////////////////////////////

#include "treenode.h"

typedef struct listnodeobject
    {

    node *val;

    struct listnodeobject *prev;		//previous node
	struct listnodeobject *next;		//next node
    } listnode;
	
	extern listnode *newListNode(node* value);
	extern void setPrevN(listnode *current, listnode *p);
	extern void setNextN(listnode *current, listnode *n);
	extern void removeNextN(listnode *current);
	extern void removePrevN(listnode *current);
	extern int hasNextN(listnode *current);
	extern int hasPrevN(listnode *current);
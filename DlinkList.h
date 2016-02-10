//////////////////////////////////////////////////////
//			David Lass - CS201 Project 1 			//
// DlinkList.h				 	 					//
// Double Link List headder. Define DLL object		//
// Each object has first and last node pointer		//
//////////////////////////////////////////////////////

#include "listnode.h"

typedef struct doubleLinkList
    {
    listnode *first;		//previous node
	listnode *last;		//next node
    } DlinkList;
	
	extern DlinkList *newDList(listnode *d);
	extern void addFront(DlinkList *dll, listnode *d);
	extern void addBack(DlinkList *dll, listnode *d);
	extern void removeFront(DlinkList *dll);
	extern void removeBack(DlinkList *dll);
	extern listnode *firstItem(DlinkList *dll);
	extern listnode *lastItem(DlinkList *dll);
	extern node *firstTreeNode(DlinkList *dll);
	extern node *lastTreeNode(DlinkList *dll);
	extern int isEmpty(DlinkList *dll);
	
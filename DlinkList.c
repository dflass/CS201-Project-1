//////////////////////////////////////////////////////
//			David Lass - CS201 Project 1 			//
// DlinkList.c				 	 					//
// Double Link List c filelength					//
// Describes functions of these lists			 	//
//////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include "DlinkList.h"


static DlinkList *newDouList(void);

/*************** public interface *************/


DlinkList *newDList(listnode *d)
    {DlinkList *p = newDouList();
    p->first = d;
	p->last = d;
    return p;}

void addFront(DlinkList *dll, listnode *d)
	{if(dll->first == 0)
	{
		dll-> first = d; dll->last	= d;
	}
	else
	{
		listnode *temp = dll->first;
		setPrevN(temp, d);
		dll->first=d;}}
		
void addBack(DlinkList *dll, listnode *d)
	{if(dll->last == 0)
	{
		dll-> first = d; dll->last	= d;
	}
	else
	{
		listnode *temp = dll->last;
		setNextN(temp, d);
		dll->last=d;}}
	
void removeFront(DlinkList *dll)
	{listnode *temp = dll->first;
	if(hasNextN(temp))
	{dll->first = temp->next;
	dll->first->prev = 0;}
	else
	{dll->first = 0; dll->last = 0;}}

void removeBack(DlinkList *dll)
	{listnode *temp = dll->last;
	if(hasPrevN(temp))
	{dll->last = temp->prev;
	dll->last->next = 0;}
	else
	{dll->first = 0; dll->last = 0;}}
	
listnode *firstItem(DlinkList *dll)
	{return dll->first;}
	
node *firstTreeNode(DlinkList *dll)
	{return dll->first->val;}
	
node *lastTreeNode(DlinkList *dll)
	{return dll->last->val;}

int isEmpty(DlinkList *dll)
	{return (dll->first==0);}

/*************** private methods *************/

static DlinkList *newDouList()
    {
    DlinkList *n = (DlinkList *) malloc(sizeof(DlinkList));
    if (n == 0) { fprintf(stderr,"out of memory"); exit(-1); }
    return n;
    }
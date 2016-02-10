//////////////////////////////////////////////////////
//			David Lass - CS201 Project 1 			//
// treenode.c					 	 				//
// Tree Node c file. 								//
// Defines functions for nodes of binary tree/heap	//
//////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include "treenode.h"

static node *newNode(void);

/*************** public interface *************/


node *newTreeNode(int v)
    {
    node *p = newNode();
    p->val = v;
    return p;
    }
	
void setLeftC(node *parent, node *left)
	{
	parent->l = left;
	left->p = parent;
	}

void setRightC(node *parent, node *right)
	{
	parent->r = right;
	right->p = parent;
	}
	
void removeLeftC(node *parent)
	{
	parent->l = 0;
	}

void removeRightC(node *parent)
	{
	parent->r = 0;
	}
	
int hasLeftC(node *parent)
	{
		return(parent->l != 0);
	}

int hasRightC(node *parent)
	{
		return(parent->r != 0);
	}
	
void bubbleDown(node *par, int direction)
	{
	while(hasLeftC(par) && (comp(par->val,par->l->val,direction) || (hasRightC(par) && (comp(par->val,par->r->val,direction)))))
	{
		if(!hasRightC(par))
		{
			int temp = par->val;
			par->val = par->l->val;
			par->l->val = temp;
			par=par->l;
		}
		else
		{
			if(comp(par->r->val,par->l->val,direction))
			{
				int temp = par->val;
				par->val = par->l->val;
				par->l->val = temp;
				par=par->l;
			}
			else
			{
				int temp = par->val;
				par->val = par->r->val;
				par->r->val = temp;
				par=par->r;
			}
		}
	}
	}
	
int comp(int c1, int c2, int dir)
	{
	if(dir==0)
		return c1>c2;
	else
		return c1<c2;
	}


/*************** private methods *************/

static node *newNode()
    {
    node *n = (node *) malloc(sizeof(node));
    if (n == 0) { fprintf(stderr,"out of memory"); exit(-1); }
    return n;
    }

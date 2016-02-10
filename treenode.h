//////////////////////////////////////////////////////
//			David Lass - CS201 Project 1 			//
// treenode.h					 	 				//
// Tree Node header file. Define binary tree nodes	//
// Each has int value, parent, left&right children	//
//////////////////////////////////////////////////////

typedef struct nodeobject
    {

    int val;

    struct nodeobject *p;		//parent 
	struct nodeobject *l;		//left child
	struct nodeobject *r;		//right child
    } node;


extern node *newTreeNode(int value);
extern void setLeftC(node *parent, node *left);
extern void setRightC(node *parent, node *rigth);
extern void removeLeftC(node *parent);
extern void removeRightC(node *parent);
extern int hasLeftC(node *parent);
extern int hasRightC(node *parent);

extern void bubbleDown(node *bub, int direction);

extern int comp(int c1, int c2, int dir);

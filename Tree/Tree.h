#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include "General.h"


typedef ElementType TreeEntry;

typedef struct tree_node {
TreeEntry entry ;
struct tree_node *left , *right ;
}TreeNode ;

typedef TreeNode *Tree ;


/*************      FunctionPrototype      *************/
void CreateTree (Tree *pt);
int TreeEmpty (Tree *pt);
int TreeFull (Tree *pt);
void InorderVisit (Tree *pt , void (*pVisit)(TreeEntry));
void ClearTree(Tree *pt);
int TreeSize(Tree *pt);
int TreeDepth(Tree *pt);
void InsertTree (Tree *pt ,TreeEntry *pe);
int FindItemTree (Tree * pt , TreeEntry *pe , KeyType key) ;
int DleteItemTree (Tree *pt , TreeEntry *pe , KeyType key ) ;


#endif // TREE_H_INCLUDED

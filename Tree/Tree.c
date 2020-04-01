#include <stdio.h>
#include <stdlib.h>
#include "General.h"
#include "Tree.h"



void CreateTree (Tree *pt){
*pt = NULL ;
}

int TreeEmpty (Tree *pt){
return !(*pt);
}

int TreeFull (Tree *pt){
return 0;
}

void InorderVisit (Tree *pt , void (*pVisit)(TreeEntry)){
    if (*pt){

        InorderVisit ( &(*pt)->left ,pVisit);
        (*pVisit)((*pt)->entry);
        InorderVisit ( &(*pt)->right,pVisit);

    }
}

void ClearTreeRecAux(Tree *pt){
	if (*pt){
		ClearTreeRecAux(&(*pt)->left);
		ClearTreeRecAux(&(*pt)->right);
		free(*pt);
	}
}


void ClearTree(Tree *pt){
	ClearTreeRecAux(pt);
	*pt=NULL;
}

int TreeSize(Tree *pt){
   if (!*pt)
      return 0;
   return (1+TreeSize(&(*pt)->left)+TreeSize(&(*pt)->right));
}




int TreeDepth(Tree *pt){
   if (!*pt)
      return 0;
    int a=TreeDepth(&(*pt)->left);
    int b=TreeDepth(&(*pt)->right);
    return (a>b)? 1+a : 1+b;
}


void InsertTree (Tree *pt ,TreeEntry *pe){

TreeNode *p , *curr , *prev ;
 p =(TreeNode*) malloc(sizeof(TreeNode));
 p->entry = *pe ;
 p->left = NULL ;
 p->right = NULL ;

 if (!*pt) *pt = p ;
 else {
    curr = *pt;
    while(curr)
    {
     prev = curr ;
     if (LT(pe->Key,curr->entry.Key))
        curr = curr->left;
     else
      curr = curr->right;
    }

    if (LT(pe->Key , prev->entry.Key))
         prev->left =p;
    else
        prev->right = p ;
    }
 }



int FindItemTree (Tree * pt , TreeEntry *pe , KeyType key) {

  int found = 0 ;
  TreeNode *p = *pt ;

   while(p && !(found = EQ( key ,p->entry.Key ))) {

    if (LT(key , p->entry.Key )) p = p->left;
        else p = p->right ;
   }

   if (found) {
    *pe = p->entry;
    return found ;
   }

}


int DleteItemTree (Tree *pt , TreeEntry *pe , KeyType key ){

int found = 0;
TreeNode *q = *pt , *r = NULL ;

while(q && !(found=EQ(key, q->entry.Key))){
      r=q;
      if(LT(key, q->entry.Key))
         q=q->left;
      else
         q=q->right;
   }
   if (found){
       *pe = q->entry ;
        if (!r)
        DleteNodeTree(pt);
     else if (LT(key , r->entry.Key))
        DleteNodeTree(&r->left);
     else
        DleteNodeTree(&r->right);
}
return found ;
}



void DleteNodeTree (Tree *pt ){

 TreeNode *q = *pt , *r ;
 if ( !(*pt)->left)
    *pt = (*pt)->right ;
 else if  ( !(*pt)->right)
    *pt = (*pt)->left;
 else
 {
     q = (*pt)->left ;
     if (!(q->right)) {
        (*pt)->entry = q->entry ;
        (*pt)->left = q->left ;
     }
     else {
            do {
                r = q ;
                q = q->right ;
            }while (q->right);

            (*pt)->entry = q->entry ;
            r->right = q->left ;
     }

 }

free(q);
}




#include "List.h"
#include <stdlib.h>

/***************************        ARRAY_ BASED_IMPLEMENTATION          *************************/
#ifdef  ARRAY_ BASED_IMPLEMENTATION
void CreatList(List*pl){
    pl->Size =0;
}

int ListEmpty(List *pl){
	return !pl->Size;
}


int ListFull(List *pl){
	return pl->Size==MAXLIST ;
}


int ListSize(List *pl){
	return pl->Size;
}


void DestroyList(List *pl){
	pl->Size=0;
}


void InsertList(int p,ListEntry e,List *pl){
    int i;
    for (i = pl->Size-1 ;i>= p; i--)
     pl->entry[i+1] = pl->entry[i];
     pl->entry[p] = e;
     pl->Size++;
}


void DleteList (int p , ListEntry *pe , List *pl) {
    int i;
  *pe  = pl->entry[p];
  for (i = p+1;i <= pl->Size-1; i++)
    pl->entry[i-1] = pl->entry[i];
  pl->Size--;

}


void RetrieveList (int p , ListEntry *pe , List*pl ){
 *pe = pl->entry[p];
}

void Replaclist(int p , ListEntry e , List*pl){
  pl->entry[p]= e ;
}


void TraverseList(List *pl ,void (*pf)(ListEntry)){
    int i ;
    for(i=0 ; i < pl->Size ; i++)
    (*pf)(pl->entry[i]);
}
#endif // ARRAY_


/*************************      LINKED_BASED_IMPLEMENTATION               ************************/


#ifdef LINKED_BASED_IMPLEMENTATION

void CreatList(List*pl){
    pl->head = NULL;
    pl->Size = 0;

}

int ListEmpty(List *pl){
 return pl->Size == 0;
}


int ListFull(List *pl){
  return 0;
}


int ListSize(List *pl){
  return pl->Size ;
}


void DestroyList(List *pl){
 ListNode *q  ;
 int i ;
 while (pl->head){
    q = pl->head->next;
    free(pl->head);
    pl->head = q ;
 }
pl->Size = 0;
}



void InsertList(int p,ListEntry e,List *pl){

ListNode *P , *q ;
int i;

P = (ListNode*) malloc(sizeof(ListNode));
P->entry = e;
P->next = NULL;

 if (p == 0) {
    P->next = pl->head;
    pl->head = P ;
 }
 else {

 for (q = pl->head , i =0 ; i <p-1 ;i++)
        q = q->next;

        P->next = q->next;
        q->next = P;
 }
pl->Size++;

}


void DleteList (int p , ListEntry *pe , List *pl) {
 ListNode *tmp  , *q ;
 int i;

 if (p==0) {
    *pe = pl->head->entry;
    tmp = pl->head->next;
    free(pl->head);
    pl->head = tmp;
    }
 else {
 for (q = pl->head , i=0 ; i <p-1 ;i++)
       q = q->next ;

 *pe = q->next->entry;
 tmp = q->next->next;
 free (q->next);
 q->next = tmp ;

 }
 pl->Size--;

}


void RetrieveList (int p , ListEntry *pe , List*pl ){
    int i ;
    ListNode *q ;
    for (q = pl->head , i =0 ; i <p ;i++)
    q = q->next ;

    *pe = q->entry ;

}

void Replaclist(int p , ListEntry e , List*pl){

    int i ;
    ListNode *q ;
    for (q = pl->head , i =0 ; i <p ;i++)
    q = q->next ;
    q->entry = e;

}


void TraverseList(List *pl ,void (*pf)(ListEntry)){
    ListNode *q = pl->head ;
    while (q){
    (*pf)(q->entry);
    q= q->next;
    }
}


#endif // LINKED_BASED_IMPLEMENTATION

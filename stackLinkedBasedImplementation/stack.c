#include<stdio.h>
#include <stdlib.h>
#include "stack.h"



void CreateStack (stack *ps){
 ps->top = NULL ;
 ps->size = 0 ;
}


void Push (stack *ps , StackEntry e ){

StackNode *pn = (StackNode*)malloc(sizeof(StackNode));
pn->entry = e;
pn->next = ps->top;
ps->top = pn;
ps->size++;

}


void Pop (stack *ps , StackEntry *pe){
 StackNode *pn ;
 *pe = ps->top->entry;
 pn = ps->top;
 ps->top = ps->top->next;
 free(pn);
 ps->size--;
}





int StackEmpty (stack *ps){
return ps->top == NULL ;
}



int StackFull (stack *ps){

return 0 ;
}



void ClearStack (stack *ps){

StackNode *pn = ps->top ;

while (pn){
    pn = pn->next ;
    free(ps->top);
    ps->top = pn;
}
ps->size = 0;

}


void TraverseStack (stack *ps , void (*pf)(StackEntry)){
    StackNode *pn = ps->top ;
while(pn){
    (*pf)(pn->entry);
    pn = pn->next;
}
}



/*

Same efficient code but more compact is:
for(StackNode *pn=ps->top; pn; pn=pn->next)
	(*pf)(pn->entry);

*/

/*
int StackSize (stack *ps){

StackNode *pn = ps->top ;
int size =0;
while (pn){
    pn = pn->next ;
   size++;
}

return size ;
}
*/

int  StackSize (stack *ps){

return ps->size;

}











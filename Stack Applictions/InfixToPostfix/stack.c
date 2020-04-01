
#include "stack.h"



void CreateStack(stack *ps ){
ps->top = 0 ;
}


int Push (StackEntry e , stack *ps){
    if (ps->top==MaxStack){
        return 0 ; }
        else {
        ps->entry[ps->top++]= e;
        return 1 ;
        }
}

int StackFull(stack *ps ){

return ps->top >= MaxStack ;
}



int Pop(StackEntry *pe ,stack *ps){
    if (ps->top == 0){
        return 0 ;
    }
    else {
      *pe = ps->entry[--ps->top];
      return 1 ;
    }
}



int StackEmpty (stack *ps){

return !(ps->top);

}


void StackTop(StackEntry *pe, stack *ps){

*pe = ps->entry[ps->top-1];
}


int StackSize (stack *ps ){

return ps->top ;

}



void ClearStack (stack *ps ){
 ps->top = 0;
}



void TraverseStack (stack *ps , void (*pf)(StackEntry) ){
  int i ;
  for( i = ps->top ; i > 0 ; i--){
        (*pf)(ps->entry[i-1]);
   }
}












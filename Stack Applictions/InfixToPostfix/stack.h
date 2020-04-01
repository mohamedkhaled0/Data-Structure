#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#define MaxStack 100


/***********************    Type Of Stack Elements      *******************/
typedef struct Element_Type {
 short int etype ;
 union  {
  double Double;
  int INT ;
  char CHAR ;
 }Data;

} ElementType ;

typedef ElementType StackEntry ;


/************          STRUCT DEFINATION          ******************/

typedef struct Stack {
int top ;
StackEntry entry[MaxStack];
}stack ;




/************          FUNCTION     ******************/

extern void CreateStack(stack *ps );
extern int Push ( StackEntry e , stack *ps);
extern int StackFull(stack *ps );
extern int Pop( StackEntry *pe ,stack *ps);
extern int StackEmpty (stack *ps) ;
extern void StackTop( StackEntry *pe, stack *ps);
extern int StackSize (stack *ps ) ;
extern void ClearStack (stack *ps );
extern void TraverseStack (stack *ps , void (*pf)(StackEntry) ) ;

#endif // STACK_H_INCLUDED

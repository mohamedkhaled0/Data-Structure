#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include<stdio.h>

#define StackEntry int
typedef struct Stacknode {

 StackEntry entry ;
 struct Stacknode *next ;
}StackNode;


typedef struct Stack {

StackNode *top ;
int size ;
}stack;


/******************              FUNCTION           ******************/


extern void CreatStack(stack *ps);
extern void Push (stack *ps , StackEntry e ) ;




#endif // STACK_H_INCLUDED

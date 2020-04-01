#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


/**************           Function Prototype              **********/
void InfixToPostfix (char infix[] , char postfix[] );
int IsDigit(char c);
int Precedent(char op1, char op2);
double EvaluatePostfix(char expr[]);
double Oper(char c, double op1, double op2);


/**************            Main Function               **********/
int main()
{

char infix[1000];
char postfix[10000];
while (1) {
printf ("Enter Infix Expression \n");
gets(infix);
InfixToPostfix(infix, postfix);
printf("%s \n", postfix);


char postfix1[3] = "55+";
double x = 0 ;
   x=EvaluatePostfix(postfix);
   printf("\n %f \n", x);
}
getch();

}




void InfixToPostfix (char infix[] , char postfix[] ){

int i, j;
ElementType op, c;
stack s;
CreateStack(&s);
for(i=0, j=0; (c.Data.CHAR=infix[i])!='\0'; i++)
	if(IsDigit(c.Data.CHAR))
	   postfix[j++]=c.Data.CHAR;
	else{
	   if(!StackEmpty(&s)){
	      StackTop(&op, &s);
	      while(!StackEmpty(&s) && Precedent(op.Data.CHAR, c.Data.CHAR)){
		   Pop(&op, &s);
		   postfix[j++]=op.Data.CHAR;
		   if(!StackEmpty(&s)) StackTop(&op, &s);
	      }
	   }
	   Push(c, &s);


	}
while(!StackEmpty(&s)){
	Pop(&op, &s);
	postfix[j++]=op.Data.CHAR;
}
postfix[j]='\0';


}





int IsDigit(char c){
   return(c>='0' && c<='9');
}



 int Precedent(char op1, char op2){
   if (op1=='$') return 1;

   if ((op1=='*') || (op1=='/'))
	return (op2!='$');

   if ((op1=='+') || (op1=='-'))
      return ( (op2!='$')&&(op2!='*')&&(op2!='/') );

   return 0;
}



double EvaluatePostfix(char expr[]){
   int i;
   char c ;
   ElementType k,op1,op2,val;
   stack s;
   CreateStack(&s);


   for(i=0; (c=expr[i])!='\0'; i++)
      if(IsDigit(c)){
        k.Data.Double =(int)(c-'0');
        Push(k,&s);
      }
      else{
          Pop(&op2, &s);
          Pop(&op1, &s);

          val.Data.Double=Oper(c, op1.Data.Double, op2.Data.Double);
          Push(val, &s);
      }
   Pop(&val, &s);
    return val.Data.Double;
}




 double Oper(char c, double op1, double op2){
   switch(c){
	case '+': return(op1+op2);
	case '-': return(op1-op2);
	case '*': return(op1*op2);
	case '/': return(op1/op2);
	case '$': return(pow(op1,op2));
   }
}






#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"


void Diplay (int x){
 printf("%d",x);
}
int main()
{
   Queue Q ;
   CreateQueue(&Q);
   int e = 5;
   int c = 0;
   //Append(e,&Q);
   //Serve(&c ,&Q );
   //printf("%d",c);
   Append(10 , &Q);
   Append(11 , &Q);
   Append (12 , &Q);
   TraverseQueue(&Q, &Diplay);


}

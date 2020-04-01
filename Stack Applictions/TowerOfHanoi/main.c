#include <stdio.h>
#include <stdlib.h>



void MoveDisks (int num , int start , int end ,  int  temp ){

 if ( num > 0 ){

    MoveDisks( num-1 , start,temp,end) ;
    printf("moved disk %d from %d to %d \n" ,num, start , end);
    MoveDisks( num-1 ,temp ,end ,start ) ;
 }

}
int main()
{
   MoveDisks(7, 1 , 2 , 3);
}

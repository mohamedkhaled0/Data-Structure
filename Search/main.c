#include <stdio.h>
#include <stdlib.h>
#include "General.h"
#include "List.h"



int SequentialSearch(KeyType target, List *pl);
void InsertOrder(ListEntry e, List *pl);
int BinarySearch (KeyType target , List *pl) ;

int main()
{
 ListEntry e1 , e2 , e3  ;
 e1.Key = 1 ;
 e2.Key = 2 ;
 e3.Key = 3 ;
 List L ;
 CreatList(&L);
 InsertList(0,e1,&L);
 InsertList(1,e2,&L);
 InsertList(2,e3,&L);

//int S = SequentialSearch(8,&L);
int S = BinarySearch(2,&L);

printf("%d",S);

}



int SequentialSearch(KeyType target, List *pl){
   int current, s=ListSize(pl);
   ListEntry currententry;
   for(current=0; current<s; current++){
      RetrieveList(current, &currententry, pl);
	if(EQ(target, currententry.Key))
	   return current;
   }
   return -1;
}




void InsertOrder(ListEntry e, List *pl){
   int current, s=ListSize(pl);
   ListEntry currententry;
   for(current=0; current<s; current++){
	RetrieveList(current, &currententry, pl);
	   if (LE(e.Key, currententry.Key))
		break;
	}
   InsertList(current, e, pl);
}



 int BinarySearch (KeyType target , List *pl){
 int middle , bottom = 0 , top = pl->Size - 1 ;
 while (bottom <= top ) {
        middle = (bottom + top ) / 2;
    if (EQ(pl->entry[middle].Key ,  target))
        return middle ;
    else if  (GT (pl->entry[middle].Key , target))
        top = middle - 1;
    else
       bottom = middle + 1 ;
 }
 return -1 ;

 }

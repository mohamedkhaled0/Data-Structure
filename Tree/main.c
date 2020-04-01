#include <stdio.h>
#include <stdlib.h>
#include "General.h"
#include "Tree.h"

void SimplePrint ( ElementType x ){
 printf("%d",x.Key);
}

int main()
{
    Tree T ;
    CreateTree(&T);

    ElementType A , B , C , D , E ;
    A.Key = 1 ;
    B.Key = 2 ;
    C.Key = 3 ;
    D.Key = 4 ;
    E.Key = 5 ;

    InsertTree(&T,&A);
    InsertTree(&T,&C);
    InsertTree(&T,&B);
    InsertTree(&T,&D);
    InsertTree(&T,&E);



    int x = TreeSize(&T);
    int y = FindItemTree(&T, &A ,6);
    DleteItemTree(&T ,&D, 2);
    printf("%d",D.Key);
    InorderVisit(&T, SimplePrint);
    //ClearTree(&T);



}

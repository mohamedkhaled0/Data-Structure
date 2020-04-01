#include "Queue.h"
#include <stdlib.h>

void CreateQueue (Queue *pq){
pq->Front = NULL ;
pq->Rear = NULL ;
pq->Size = 0;
}


void Append (QueueEntry e , Queue *pq){
    QueueNode *pn = (QueueNode*) malloc(sizeof(QueueNode));
    pn->next = 0;
    pn->entry = e ;

    if(!pq->Rear)
    pq->Front = pn;
    else
    pq->Rear->next = pn ;

   pq->Rear = pn ;
   pq->Size++;

}



void Serve (QueueEntry *pe , Queue *pq){
    QueueNode *pn = pq->Front ;
    *pe = pq->Front->entry ;
    pq->Front = pq->Front->next;
    free(pn);
    if (!pq->Front)
        pq->Rear = NULL ;

    pq->Size--;
}


int QueueEmpty (Queue *pq){
  return !(pq->Size);
}



int QueueFull(Queue *pq){

return 0;

}



int QueueSize(Queue* pq){
    return pq->Size ;

}


void ClearQueue (Queue *pq){
    while (pq->Front){
        pq->Rear = pq->Front->next;
        free(pq->Front);
        pq->Front = pq->Rear;

    }
 pq->Size = 0;
}



void TraverseQueue (Queue *pq , void (*pf)(QueueEntry)){
QueueNode *pn;
for(pn=pq->Front; pn; pn=pn->next)
		(*pf)(pn->entry);



}

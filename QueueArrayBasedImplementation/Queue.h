#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED


#define MaxQueue 100


typedef int ElementType ;
typedef ElementType QueueEntry ;



typedef struct queue {
int Rear ;
int Front ;
int Size ;
QueueEntry entry [MaxQueue];
} Queue;



/********                     Function                ****************/
void CreateQueue (Queue *pq);
void Append (QueueEntry e , Queue *pq);
void Serve (QueueEntry *pe , Queue *pq);
int QueueEmpty (Queue *pq);
int QueueFull(Queue *pq);
int QueueSize(Queue* pq);
void ClearQueue (Queue *pq);
void TraverseQueue (Queue *pq , void (*pf)(QueueEntry));




#endif // QUEUE_H_INCLUDED

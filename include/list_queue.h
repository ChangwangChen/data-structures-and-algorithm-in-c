#ifndef LIST_QUEUE_H
#define LIST_QUEUE_H

typedef int ElementType;

struct QueueRecord;
struct QueueHeader;
typedef struct QueueHeader *Queue;
typedef struct QueueRecord *QueueItem;

struct QueueRecord {
    ElementType Value;
    QueueItem Next;
};

struct QueueHeader {
    QueueItem Front;
    QueueItem Rear;
};

int IsEmptyQueue(Queue Q);
Queue CreateQueue();
void DisposeQueue(Queue Q);
void MakeEmptyQueue(Queue Q);
void Enqueue(ElementType X, Queue Q);
void Dequeue(Queue);
ElementType Front(Queue Q);
ElementType FrontAndDequeue(Queue Q);
void PrintQueue(Queue Q);

#endif //LIST_QUEUE_H

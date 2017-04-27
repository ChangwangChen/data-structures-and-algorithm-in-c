#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

typedef int ElementType;

struct QueueRecord;
typedef struct QueueRecord *Queue;

struct QueueRecord {
    int Capacity; //总容量
    int Front;
    int Rear;
    int Size; //当前使用的容量
    ElementType *Array;
};

int IsEmpty(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue(int MaxCount);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElementType X, Queue Q);
void Dequeue(Queue);
ElementType Front(Queue Q);
ElementType FrontAndDequeue(Queue Q);
void PrintQueue(Queue Q);

#endif //ARRAY_QUEUE_H

#include <stdlib.h>
#include "kernel/fatal.h"
#include "array_queue.h"

#define MIN_QUEUE_SIZE 10

int IsEmpty(Queue Q)
{
    return Q->Size == 0;
}

int IsFull(Queue Q)
{
    return Q->Size == Q->Capacity;
}

Queue CreateQueue(int MaxCount)
{
    Queue Q;

    if(MaxCount < MIN_QUEUE_SIZE) {
        Error("Queue size is too small!");
    }

    Q = malloc(sizeof(struct QueueRecord));
    if(Q == NULL) {
        FatalError("Out of space!");
    }

    Q->Array = malloc(sizeof(ElementType) * MaxCount);
    if(Q->Array == NULL) {
        FatalError("Out of space!");
    }

    Q->Capacity = MaxCount;
    MakeEmpty(Q);

    return Q;
}

void MakeEmpty(Queue Q)
{
    Q->Size = 0;
    Q->Front = 1;
    Q->Rear = 0;
}

void DisposeQueue(Queue Q)
{
    if(Q != NULL) {
        free(Q->Array);
        free(Q);
    }
}

/**
 * 判断队列的结尾位置
 *
 * @param int Value
 * @param Queue Q
 * @return static int
 */
static int Succ(int Value, Queue Q)
{
    if(++Value == Q->Capacity) {
        Value = 0;
    }

    return Value;
}

void Enqueue(ElementType X, Queue Q)
{
    if(IsFull(Q)) {
        Error("Full queue!");
    }else {
        Q->Size ++;
        Q->Rear = Succ(Q->Rear, Q);
        Q->Array[Q->Rear] = X;
    }
}

ElementType Front(Queue Q)
{
    if(!IsEmpty(Q)) {
        return Q->Array[Q->Front];
    }else {
        Error("Empty queue!");
        return 0; //avoid warning
    }
}

void Dequeue(Queue Q)
{
    if(IsEmpty(Q)) {
        Error("Empty queue!");
    }else {
        Q->Size --;
        Q->Front = Succ(Q->Front, Q);
    }
}

ElementType FrontAndDequeue(Queue Q)
{
    ElementType X = 0;

    if(IsEmpty(Q)) {
        Error("Empty queue!");
    }else {
        Q->Size --;
        X = Q->Array[Q->Front];
        Q->Front = Succ(Q->Front, Q);
    }

    return X;
}

void PrintQueue(Queue Q)
{
    if(IsEmpty(Q)) {
        printf("Empty Queue! \n");
    }else {
        int i, j;

        printf("Print Queue:");
        for(i = 1, j = Q->Front; i <= Q->Size; i++) {
            printf("%d ", Q->Array[j]);
            j = Succ(j, Q);
        }

        printf("\n");
    }
}





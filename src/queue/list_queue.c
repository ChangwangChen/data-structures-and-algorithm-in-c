#include <stdlib.h>
#include "kernel/fatal.h"
#include "list_queue.h"

int IsEmpty(Queue Q)
{
    return Q->Front == NULL;
}

Queue CreateQueue()
{
    Queue Q;
    Q = malloc(sizeof(struct QueueHeader));

    if(Q == NULL) {
        FatalError("Out of space.");
    }else {
        Q->Front = NULL;
        Q->Rear = NULL;

        MakeEmpty(Q);
        return Q;
    }
}

void MakeEmpty(Queue Q)
{
    if(Q == NULL) {
        Error("必须创建一个Queue.");
    }else {
        while(!IsEmpty(Q)) {
            Dequeue(Q);
        }

        Q->Rear = NULL;
    }
}

void Enqueue(ElementType X, Queue Q)
{
    QueueItem tmp;
    tmp = malloc(sizeof(struct QueueRecord));

    if(tmp == NULL) {
        FatalError("Out of space.");
    }else {
        tmp->Value = X;
        tmp->Next = NULL;

        if(Q->Rear == NULL) { //队列的尾指针为空，表明队列为空
            Q->Front = tmp;
            Q->Rear = tmp;
        }else {//队列尾不为空，表明队列不为空
            Q->Rear->Next = tmp;
            Q->Rear = tmp;
        }
    }
}

void Dequeue(Queue Q)
{
    if(IsEmpty(Q)) {
        Error("Empty Queue.");
    }else {
        QueueItem front = Q->Front;
        QueueItem tmp = Q->Front->Next;
        Q->Front = tmp;

        if(tmp == NULL) {
            Q->Rear = tmp;
        }

        free(front);
    }
}

void DisposeQueue(Queue Q)
{
    MakeEmpty(Q);
    free(Q);
}

ElementType Front(Queue Q)
{
    if(IsEmpty(Q)) {
        Error("Empty queue.");
    }else {
        return Q->Front->Value;
    }
}

ElementType FrontAndDequeue(Queue Q)
{
    ElementType X = 0;

    if(IsEmpty(Q)) {
        Error("Empty queue.");
    }else {
        QueueItem tmp = Q->Front;

        X = tmp->Value;
        Q->Front = tmp->Next;
        if(NULL == tmp->Next) {
            Q->Rear = NULL;
        }
        free(tmp);
    }

    return X;
}

void PrintQueue(Queue Q)
{
    if(IsEmpty(Q)) {
        printf("Empty Queue.");
    }else {
        printf("Print Queue:");

        QueueItem tmp;
        tmp = Q->Front;

        while(tmp != NULL) {
            printf("%d ", tmp->Value);
            tmp = tmp->Next;
        }

        printf("\n");
    }
}


#include <stdio.h>
#include "list_queue.h"

int main()
{
    Queue q;
    ElementType i;
    ElementType tmp;

    q = CreateQueue();
    PrintQueue(q);
    if(IsEmpty(q)) {
        printf("\nEmpty queue.\n");
    }
    printf("\n\n");

    for(i = 0; i < 10; i++) {
        printf("Push %d into queue. \n", i);
        Enqueue(i, q);
    }
    printf("\n\n");

    PrintQueue(q);
    printf("Front of queue: %d\n", Front(q));
    if(IsEmpty(q)) {
        printf("\nEmpty queue.\n");
    }
    printf("\n\n");

    for(i = 0; i < 9; i++){
        tmp = FrontAndDequeue(q);
        printf("Top of queue: %d\n", tmp);
        printf("Pop out of queue: %d\n", tmp);
    }

    printf("\n\n");
    PrintQueue(q);
    if(IsEmpty(q)) {
        printf("\nEmpty queue.\n");
    }
    printf("Front of queue: %d\n", Front(q));


    for(i = 10; i < 15; i++){
        printf("Push %d into queue. \n", i);
        Enqueue(i, q);
    }
    printf("\n\n");
    PrintQueue(q);
    if(IsEmpty(q)) {
        printf("\nEmpty queue.\n");
    }
    printf("Front of queue: %d\n", Front(q));


    printf("\n\nMake Empty queue!\n");
    MakeEmpty(q);
    if(IsEmpty(q)) {
        printf("\nEmpty queue.\n");
    }

    printf("\n\n");
    printf("%s ,%s", q->Front, q->Rear);


    DisposeQueue(q);
    return 0;
}
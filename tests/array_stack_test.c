#include <stdio.h>
#include "array_stack.h"

int main()
{
    ArrayStack s;
    ElementType i;
    ElementType tmp;

    s = CreateArrayStack(10);
    printf("Print Stack: ");
    PrintArrayStack(s);
    if(IsEmpty(s)) {
        printf("\nEmpty stack.\n");
    }
    if(IsFull(s)) {
        printf("\nFull stack.\n");
    }
    printf("\n\n");

    for(i = 0; i < 10; i++) {
        printf("Push %d into stack. \n", i);
        Push(i, s);
    }
    printf("\n\n");
    printf("Print Stack: ");
    PrintArrayStack(s);
    printf("Top of stack: %d\n", Top(s));
    if(IsEmpty(s)) {
        printf("\nEmpty stack.\n");
    }
    if(IsFull(s)) {
        printf("\nFull stack.\n");
    }
    printf("\n\n");

    for(i = 0; i < 5; i++){
        tmp = TopAndPop(s);
        printf("Top of stack: %d\n", tmp);
        printf("Pop out of stack: %d\n", tmp);
    }

    printf("\n\n");
    printf("Print Stack: ");
    PrintArrayStack(s);
    if(IsEmpty(s)) {
        printf("\nEmpty stack.\n");
    }
    if(IsFull(s)) {
        printf("\nFull stack.\n");
    }
    printf("Top of stack: %d\n", Top(s));


    printf("\n\nMake Empty Stack!\n");
    MakeEmpty(s);
    if(IsEmpty(s)) {
        printf("\nEmpty stack.\n");
    }
    if(IsFull(s)) {
        printf("\nFull stack.\n");
    }


    DisposeArrayStack(s);
    return 0;
}
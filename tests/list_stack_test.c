#include <stdio.h>
#include "list_stack.h"

int main()
{
    Stack s;
    ElementType i;
    ElementType tmp;

    s = CreateStack();
    printf("Print Stack: ");
    PrintStack(s);
    printf("\n\n");

    for(i = 0; i < 10; i++) {
        printf("Push %d into stack. \n", i);
        Push(i, s);
    }
    printf("\n\n");
    printf("Print Stack: ");
    PrintStack(s);
    printf("Top of stack: %d\n", Top(s));
    printf("\n\n");

    for(i = 0; i < 5; i++){
        tmp = Top(s);
        printf("Top of stack: %d\n", tmp);
        Pop(s);
        printf("Pop out of stack: %d\n", tmp);
    }

    printf("\n\n");
    printf("Print Stack: ");
    PrintStack(s);
    printf("Top of stack: %d\n", Top(s));


    printf("\n\nMake Empty Stack!\n");
    MakeEmpty(s);
    if(IsEmpty(s)) {
        printf("空stack\n");
    }else {
        printf("stack 非空！\n");
    }


    DisposeStack(s);
}
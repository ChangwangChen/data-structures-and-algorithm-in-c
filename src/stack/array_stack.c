#include <stdlib.h>
#include "array_stack.h"
#include "kernel/fatal.h"

#define EMPTY_TOS -1
#define MIN_STACK_SIZE 5

int IsEmpty(ArrayStack S)
{
    return S->TopOfStack == EMPTY_TOS;
}

int IsFull(ArrayStack S)
{
    return S->TopOfStack == S->Capacity - 1;
}

ArrayStack CreateArrayStack(int MaxStackSize)
{
    ArrayStack S;
    if(MaxStackSize < MIN_STACK_SIZE) {
        FatalError("Stack size is too small.");
    }else {
        //栈首
        S = malloc(sizeof(struct ArrayStackNode));
        if(S == NULL)
            FatalError("Out of space!");

        //栈
        S->Array = malloc(sizeof(ElementType) * MaxStackSize);
        if(S->Array == NULL)
            FatalError("Out of space!");

        S->Capacity = MaxStackSize;
        MakeEmpty(S);

        return S;
    }
}

void MakeEmpty(ArrayStack S)
{
    S->TopOfStack = EMPTY_TOS;
}

void DisposeArrayStack(ArrayStack S)
{
    if(S != NULL) {
        free(S->Array);
        free(S);
    }
}

void Push(ElementType X, ArrayStack S)
{
    if(IsFull(S)) {
        Error("Full stack!");
    }else {
        S->Array[++S->TopOfStack] = X;
    }
}

ElementType Top(ArrayStack S)
{
    if(IsEmpty(S)){
        FatalError("Empty stack!");
    }

    return S->Array[S->TopOfStack];
}

void Pop(ArrayStack S)
{
    if(IsEmpty(S)) {
        FatalError("Empty stack!");
    }else {
        S->TopOfStack--;
    }
}

ElementType TopAndPop(ArrayStack S)
{
    if(IsEmpty(S)) {
        FatalError("Empty stack!");
    }else {
        return S->Array[S->TopOfStack--];
    }
}

void PrintArrayStack(ArrayStack S)
{
    if(IsEmpty(S)) {
        printf("Empty stack!");
    }else {
        int index;

        for(index = S->TopOfStack; index >= 0; index--) {
            printf("%d ", S->Array[index]);
        }

        printf("\n");
    }
}





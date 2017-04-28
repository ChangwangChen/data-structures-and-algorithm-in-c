#include <stdlib.h>
#include "kernel/fatal.h"
#include "list_stack.h"

Stack CreateStack()
{
    Stack S;
    S = malloc(sizeof(struct Node));
    if(S == NULL) {
        FatalError("Out of space!");
    }else {
        //这里不知道有没有必要
        S->Element = NULL;
        S->Next = NULL;
        MakeEmptyStack(S);
        return S;
    }
}

void MakeEmptyStack(Stack S)
{
    if(S == NULL) {
        FatalError("必须先创建一个Stack！");
    }else {
        while(!IsEmptyStack(S)) {
            Pop(S);
        }
    }
}

int IsEmptyStack(Stack S)
{
    return S->Next == NULL;
}

void Push(ElementType X, Stack S)
{
    if(S == NULL) {
        FatalError("必须先创建一个Stack！");
    }else {
        PtrToNode Cell;
        Cell = malloc(sizeof(struct Node));
        if(Cell == NULL) {
            FatalError("Out of space!");
        }else {
            Cell->Element = X;
            Cell->Next = S->Next;

            S->Next = Cell;
        }
    }
}


void Pop(Stack S)
{
    if(S == NULL) {
        FatalError("必须先创建一个Stack！");
    }else {
        if(IsEmptyStack(S)) {
            FatalError("空Stack");
        }else {
            PtrToNode Tmp;

            Tmp = S->Next;
            S->Next = S->Next->Next;
            free(Tmp);
        }
    }
}

void DisposeStack(Stack S)
{
    MakeEmptyStack(S);
    free(S);
}

ElementType Top(Stack S)
{
    if(IsEmptyStack(S)) {
        FatalError("空stack");
    }else {
        return S->Next->Element;
    }
}

ElementType TopAndPop(Stack S)
{
    ElementType X;
    X = 0;
    if(IsEmptyStack(S)) {
        FatalError("空stack");
    }else {
        PtrToNode tmp;
        tmp = S->Next;
        X = tmp->Element;
        S->Next = tmp->Next;

        free(tmp);
    }

    return X;
}

void PrintStack(Stack S)
{
    if(IsEmptyStack(S)) {
        printf("空Stack");
    }else {
        PtrToNode Tmp;
        Tmp = S->Next;
        do{
            printf("%d ", Tmp->Element);
            Tmp = Tmp->Next;
        }while (Tmp);
        printf("\n");
    }
}
#include <stdlib.h>
#include "../includes/list.h"
#include "../includes/fatal.h"

List MakeEmpty(List L)
{
    if(L != NULL) {
        MakeEmpty(L);
    }else {
        L = malloc(sizeof(struct Node));
        if(L == NULL) {

        }
        L->Next = NULL;
    }

    return L;
}

int IsEmpty(List L)
{
    return L->Next == NULL;
}

int IsLast(Position P, List L)
{
    return P->Next == NULL;
}

Position Find(ElementType X, List L)
{
    Position P;
    P = L->Next;
    while(P != NULL && P->Element != X) {
        P = P->Next;
    }

    return P;
}


void Delete(ElementType X, List L)
{
    Position P, Tmp;
    P = FindPrevious(X, L);
    if(!IsLast(P, L)) {
        Tmp = P->Next;
        P->Next = Tmp->Next;
        free(Tmp);
    }
}

Position FindPrevious(ElementType X, List L)
{
    Position P;

    P = L;
    while(P->Next != NULL && P->Next->Element != X) {
        P = P->Next;
    }

    return P;
}

void Insert(ElementType X, List L, Position P)
{
    Position Tmp;
    Tmp = malloc(sizeof(struct Node));
    if(Tmp == NULL) {
        FatalError("Out of space!");
    }

    Tmp->Element = X;
    Tmp->Next = P->Next;
    P->Next = Tmp;
}

void DeleteList(List L)
{
    Position P, Tmp;
    P = L->Next;
    L->Next = NULL;

    while(P != NULL) {
        Tmp = P->Next;
        free(P);
        P = Tmp;
    }
}

Position Header(List L)
{
    return L;
}

Position First(List L)
{
    return L->Next;
}

Position Advance(Position P)
{
    return P->Next;
}

ElementType Retrieve(Position P)
{
    return P->Element;
}

void PrintList(const List L)
{
    Position P = Header(L);
    if(IsEmpty(L)) {
        printf("Empty List!\n");
    }else {
        do{
            P = Advance(P);
            printf("%d ", Retrieve(P));
        }while(!IsLast(P, L));
        printf("\n");
    }
}

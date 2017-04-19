typedef int ElementType;

#ifndef LIST_STACK_H
#define LIST_STACK_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

struct Node {
    PtrToNode Next;
    ElementType Element;
};

int IsEmpty(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
void PrintStack(Stack S);

#endif //LIST_STACK_H

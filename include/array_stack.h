#ifndef ARRAY_ArrayStack_H
#define ARRAY_ArrayStack_H

typedef int ElementType;

struct ArrayStackNode;
typedef struct ArrayStackNode *ArrayStack;

struct ArrayStackNode{
    int Capacity; //栈的空间总数
    int TopOfStack; //当前的栈顶位置
    ElementType *Array;
};

int IsEmpty( ArrayStack S );
int IsFull( ArrayStack S );
ArrayStack CreateArrayStack( int MaxElements );
void DisposeArrayStack( ArrayStack S );
void MakeEmpty( ArrayStack S );
void Push( ElementType X, ArrayStack S );
ElementType Top( ArrayStack S );
void Pop( ArrayStack S );
ElementType TopAndPop( ArrayStack S );
void PrintArrayStack(ArrayStack S);

#endif //ARRAY_ArrayStack_H

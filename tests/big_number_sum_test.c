//
// 链表实现的大数相加
//
#include <stdio.h>
#include <stdlib.h>
#include "list_stack.h"

int main()
{
    char ch;
    int num, i, j, tmp;
    Stack a, b, ret;
    printf("请输入第一个数(字母a结束)：");

    a = CreateStack();
    while('a' != (ch = getchar())) {
        num = atoi(&ch);
        Push(num, a);
    }

    getchar(); //换行符

    printf("请输入第二个数(字母a结束)：");
    b = CreateStack();
    while('a' != (ch = getchar())) {
        num = atoi(&ch);
        Push(num, b);
    }
    PrintStack(a);
    PrintStack(b);

    //开始计算
    ret = CreateStack();
    tmp = 0;
    while(!IsEmptyStack(a) && !IsEmptyStack(b)) {
        i = TopAndPop(a);
        j = TopAndPop(b);

        i += j + tmp;
        if(i < 10) {
            tmp = 0;
        }else {
            tmp = i / 10;
            i = i % 10;
        }

        Push(i, ret);
    }

    while(!IsEmptyStack(a)) {
        i = TopAndPop(a);

        i += tmp;
        if(i < 10) {
            tmp = 0;
        }else {
            tmp = i / 10;
            i = i % 10;
        }

        Push(i, ret);
    }

    while(!IsEmptyStack(b)) {
        i = TopAndPop(b);

        i += tmp;
        if(i < 10) {
            tmp = 0;
        }else {
            tmp = i / 10;
            i = i % 10;
        }

        Push(i, ret);
    }

    if(tmp) {
        Push(tmp, ret);
    }

    PrintStack(ret);

    free(a);
    free(b);
    free(ret);

    return 0;
}

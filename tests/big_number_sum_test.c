//
// 栈实现的大数相加
//
#include <stdio.h>
#include <stdlib.h>
#include "list_stack.h"

int ll2str(char *s, long long value);

int main()
{
    //测试 long long 类型转换成 string
    char s[21];
    long long value;
    size_t l;

    scanf("%lld", &value);

    l = ll2str(s, value);
    printf("您输入的是: %lld \n", value);
    printf("它的长度是: %d \n", l);
    printf("它转换成字符串是: %s \n", s);

    printf("\n\n");
    printf("下面测试大数相加:\n");
    //下面开始测试栈实现的大数相加
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

    DisposeStack(a);
    DisposeStack(b);
    DisposeStack(ret);

    return 0;
}

int ll2str(char *s, long long value) {
    char *p, aux;
    unsigned long long v;
    size_t l;

    v = (value < 0) ? -value : value;
    p = s;
    do{
        *p++ = '0' + (v%10);
        v /= 10;
    } while(v);
    if(value < 0) *p++ = '-';

    l = p - s;
    *p = '\0';

    p--; //这里不处理结束符 '\0'
    while( s < p) {
        aux = *s;
        *s = *p;
        *p = aux;

        p--;
        s++;
    }

    return l;
}

#include <stdio.h>
#include "list.h"

int main(int argc, char *argv[])
{
    List L;
    Position P;
    int i;

    L = MakeEmpty(NULL);
    P = Header(L);
    PrintList(L);

    for(i = 0; i < 10; i++) {
        Insert(i, L, P);
        PrintList(L);
        P = Advance(P);
    }

    for(i = 0; i < 10; i+=2) {
        Delete(i, L);
    }
    PrintList(L);

    DeleteList(L);
    PrintList(L);


    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*Lezione 1 del 11-3-24*/
    /*Scambiare tra di loro il valore delle variabili a=5, b=10*/
    int *a,*b;
    *a=5;
    *b=10;

    printf("A: %d, B: %d\n",*a,*b);

    a=&b;
    b=&a;

    printf("A: %d, B: %d\n",*a,*b);


    return 0;
}

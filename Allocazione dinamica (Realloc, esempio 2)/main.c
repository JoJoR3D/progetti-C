#include <stdio.h>
#include <stdlib.h>

/*
    Con la realloc() se si diminuisce lo spazio di memoria da allocare allora, lo spazio in eccesso viene deallocato (come la free()).
    Se invece si aumenta lo spazio da allocare, questo non viene inizialittato (quindi conterrà valori casuali (memoria sporca)).
*/

int main()
{
    int n=1;
    int m,i;
    int*p;


    p= (int*)calloc(n,sizeof(int));     /*Alloco 1 intero in memoria.*/

    p[0]=1;                             /*Valore intero allocato*/
                                        /*posso scrivere anche: *(p+0)=1*/

    printf("Intero presente nello spazio di memoria allocato:\n");
    for(i=0;i<n;i++)
        printf("%d\n",*(p+i));


    printf("\n\n");
    m=n+1;

    p= (int*)realloc(p,m*sizeof(int));  /*Aumento lo spazio allocato per allocare un altro intero.*/

    *(p+n)= 2;                          /*Valore secondo intero allocato*/
                                        /*posso scrivere anche: p[n]=2*/

    printf("I due interi presenti nello spazio di memoria allocato:\n");
    for(i=0;i<m;i++)
        printf("%d\n",*(p+i));

    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int*cont;
    int n=16,i;
    cont= (int*)malloc(n+sizeof(int));  /*Alloca 16 byte che possono contenere 4 interi (1 intero= 4byte).*/

    /*Mostro l'area di memoria allocata con la malloc()*/
    printf("\n\n");
    for(i=0;i<16;i++)
        printf("%d\n",*(cont+i)); /*Potrei scrivere anche: cont[i]*/



    /*Mostro l'area di memoria allocata con la calloc() (la calloc quando alloca la memoria la inizializza anche ponendo il valore zero*/
    printf("\n\n");
    int*cont1;
    cont1= (int*)calloc(n,sizeof(int));

    for(i=0;i<n;i++)
        printf("%d\n",*(cont1+i));



    /*Libero l'area di memoria allocata dalla calloc()*/
    free(cont1);
    printf("\n\n");
    for(i=0;i<n;i++)
        printf("%d\n",*(cont1+i));


    return 0;
}

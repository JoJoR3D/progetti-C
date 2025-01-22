#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[]={1,2,3,4,5,6,7,8,9,10};
    int N=10, M, i;
    int*p;

    p= (int*)malloc(N*sizeof(int)); /*Alloco uno spazio di memoria per contenere 10 interi*/

    for(i=0;i<N;i++)
        *(p+i)=a[i];

    printf("Spazio di memoria allocato per contenere %d interi\n",N);
    for(i=0;i<N;i++)
        printf("%d\n",*(p+i));




    printf("\n\n");

    M=N*2;

    p= (int*)realloc(p,M*sizeof(int));      /*Chiedo di allocare altro spazio per contenere altri 10 interi*/
    int b[]={11,12,13,14,15,16,17,18,19,20};

    for(i=0;i<N;i++)
        *(p+N+i)=b[i];  /*Assegno dalla posizione 10 dello spazio allocato, gli elementi dell'array b*/

    printf("Spazio di memoria riallocato per contenere %d interi\n",M);
    for(i=0;i<M;i++)
        printf("%d\n",*(p+i));

    return 0;
}

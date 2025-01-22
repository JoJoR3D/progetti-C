#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void num(int*, int, int*, float*, float*);


int main()
{
    int a, n=5, massimo;
    float media, radice_quadrata;

    num(&a,n,&massimo,&media,&radice_quadrata);

    printf("\nValore massimo: %d, Media: %.1f, Radice quadrata: %.1f\n",massimo, media, radice_quadrata);

    return 0;
}



void num(int*a, int n, int*max, float*avarage, float*square_root)
{
    int i=0;
    *max=0, *avarage=0, *square_root=0;

    printf("Inserisci %d valori:\n",n);

    while(i < n){
        scanf("%d",a);
        *square_root= *square_root + *a;

        if(*a > *max)
            *max= *a;

        *avarage= *avarage + *a;
        i++;
    }
    *avarage= (*avarage)/n;
    *square_root= sqrt(*square_root);
}

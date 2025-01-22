#include <stdio.h>
#include <stdlib.h>


int num_progres(int);


int main()
{
    int numero=1, serie;

    while(numero > 0){
        scanf("%d",&numero);

        if(numero > 0){
            serie= num_progres(numero);
            printf("Somma progressiva dei numeri da 1 a %d: %d\n\n",numero,serie);
        }
        else
            printf("\nFINE!");
    }

    return 0;
}


int num_progres(int n)
{
    return n*(n+1)/2;    /*Formula di Gauss bambino*/
}

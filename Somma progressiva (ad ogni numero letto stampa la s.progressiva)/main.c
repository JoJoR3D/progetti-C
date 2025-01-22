#include <stdio.h>
#include <stdlib.h>


/*
    Scrivere un programma in linguaggio C che legga da tastiera una sequenza di numeri positivi e ad
    ogni numero letto ne stampi la somma progressiva. Il programma termina quando si introduce un
    numero minore o uguale a zero.
*/


int somma_progressiva(int, int);


int main()
{
    int numero=1, num;

    while(numero > 0){
        printf("Inserisci numero: ");
        scanf("%d",&numero);

        if(numero > 0){
            num= somma_progressiva(numero,num);
            printf("Somma progressiva attuale: %d\n\n",num);
        }
        else
            printf("\nFine!");
    }

    printf("\nSomma progressiva totale: %d\n",num);

    return 0;
}


int somma_progressiva(int a, int b)
{
    return b= b + a;
}

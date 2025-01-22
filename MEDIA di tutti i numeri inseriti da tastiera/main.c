#include <stdio.h>
#include <stdlib.h>


/*
    Scrivere un programma in linguaggio C che legga da tastiera una sequenza di lunghezza ignota a
    priori di numeri interi positivi. Il programma, a partire dal primo numero introdotto, stampa ogni
    volta la media di tutti i numeri introdotti. Terminare quando il numero inserito è negativo.
*/


float leggi_da_tastiera(int*);
void media(int*, float*, int);


int main()
{
    int a;

    float avarage=leggi_da_tastiera(&a);

    printf("\n\nMedia finale dei valori inseriti da tastiera: %.1f\n",avarage);

    return 0;
}



float leggi_da_tastiera(int*A)
{
    int cont=1,tot=0;
    float Avarage=0.0;
    *A=0;

    while(*A >= 0){
        printf("Valore: ");
        scanf("%d",A);
        printf("Numeri inseriti %d\n",cont);

        if(*A >= 0){
            tot= tot + *A;
            media(&tot,&Avarage,cont);
            cont++;
        }
    }
    return Avarage;
}



void media(int*T, float*media, int Cont)
{
    *media=0.0;

    *media= (float)*T/Cont;
    printf("Media attuale: %.1f\n\n",*media);
}

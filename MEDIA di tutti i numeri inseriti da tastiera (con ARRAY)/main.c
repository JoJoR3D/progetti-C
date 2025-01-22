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
    int a[100];

    float avarage=leggi_da_tastiera(a);

    printf("\n\nMedia finale dei valori inseriti da tastiera: %.1f\n",avarage);

    return 0;
}



float leggi_da_tastiera(int*A)
{
    int i=0,cont=i+1;
    float Avarage=0.0;

    while(A[i-1] >= 0){
        printf("Valore da inserire: ");
        scanf("%d",&A[i]);
        printf("Numeri inseriti %d\n",i+1);
        if(A[i] >= 0){
            media(A,&Avarage,cont);
            cont++;
        }
        i++;
    }
    return Avarage;
}



void media(int*A, float*media, int Cont)
{
    int i=0,somma=0;
    *media=0.0;

    while(i < Cont){
        somma= somma + A[i];
        i++;
    }
    *media= (float)somma/Cont;
    printf("Media attuale: %.1f\n\n",*media);
}

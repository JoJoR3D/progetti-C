#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trova(char*, int*, int*);


int main()
{
    char*stringa= "Non so cosa fare in questa vita, mi sembra di sbagliare sempre tutto";
    int i,Indice,Dim;

    trova(stringa,&Indice,&Dim);

    printf("La parola di lunghezza minore presente nel testo si trova a partire dalla posizione: %d e ha una dimensione di: %d caratteri\n\nLa parola in questione e': ",Indice,Dim);

    for(i=Indice;i<=Indice+Dim;i++)
        printf("%c",stringa[i]);        /*Questo ciclo for serve per stampare la parola di lunghezza mainima.*/
    printf("\n");

    return 0;
}



void trova(char*testo, int*index, int*dim)
{
    int n= strlen(testo);
    int i,conta=0,conta_chiave=n;

    for(i=0;i<=n;i++){
        if(testo[i]!=' ' && testo[i]!= '\0')
            conta++;
        else{
            if(conta < conta_chiave){
                conta_chiave= conta;
                *index= i-conta;
            }
            conta=0;
        }
    }
    *dim= conta_chiave;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*
TRACCIA 21
Scrivere un programma per simulare l'inserimento di un PIN per il telefonino. Nella prima fase viene costruito il PIN di riferimento, che deve essere
di lunghezza 5 e deve essere costruito in modo casuale. Nella seconda fase l’utente inserisce il codice di tentativo e ha al massimo 3 tentativi per indovinarlo.
*/


void gene_pin(int*, int);
void inserire_pin(int*, int);


int main()
{
    int Pin[5];
    int n=5,i;

    gene_pin(Pin,n);

    printf("Generazione PIN: ");
    for(i=0;i<n;i++)
        printf("%d ",Pin[i]);

    inserire_pin(Pin,n);

    return 0;
}



void gene_pin(int*Pin, int n)
{
    int i=0;

    srand(time(NULL));

    while(i<5){
        Pin[i]= rand()%9;
        i++;
    }
}



void inserire_pin(int*Pin, int n)
{
    int pin[n],i=0,j=0,cont=0,tentativi=3;

    printf("\n\nInserire Pin per sbloccare il dispositivo. Hai 3 tentativi\n");
    while(i<3){
        while(j<5){
            scanf("%d",&pin[j]);

            if(pin[j] == Pin[j])
                cont++;
            else
                cont--;

            j++;
        }

        tentativi--;

        if(cont == n){
            printf("\nCorretto, smartphone sbloccato!\n");
            break;
        }
        else if(cont < n && tentativi > 0){
            printf("\nErrato, sono rimasti %d tentativi\n",tentativi);
            j=0;
        }
        else if(tentativi == 0)
            printf("\nEsauriti i tentativi, riavviare lo smartphone\n");

        i++;
        cont=0;
    }
}

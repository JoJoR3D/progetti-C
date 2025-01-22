#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    Generare un numero a caso e chiedere all'utente un numero fino a quando non e' uguale a quello
    generato casualmente. Dire ogni volta se il numero immesso e' > o < di quello iniziale.
*/


void num_random(int*,int*,int*);
void egual(int*, int*,int*,int*);


int main()
{
    int n_casual, number, I, F;

    num_random(&n_casual,&I,&F);

    egual(&number,&n_casual,&I,&F);

    return 0;
}



void num_random(int*A, int*Inizio, int*Fine)
{
    *Inizio=1, *Fine=20;
    srand(time(NULL));

    *A= *Inizio+rand()%*Fine;
}



void egual(int*A, int*B, int*Inizio, int*Fine)        /*A: numero inserito; B: numero generato*/
{
    int C;

    printf("Il numero generato casualmente e' pescato da un gruppo di numeri che inizia da %d e termina con %d\n",*Inizio,*Fine);
    printf("Inserisci valore: ");
    scanf("%d",A);
    printf("\n");

    while(*A != *B){        /*Rimane nel ciclo finquando il numero inserito non è UGUALE al numero generato casualmente*/
        if(*A > *B){        /*Il numero inserito e' MAGGIORE del numero generato casualmente*/
            C= *A - *B;

            if(C > 3)
                printf("ACQUA! Il numero inserito e' > del numero generato casualmente");
            else
                printf("FUOCO! Il numero inserito e' > del numero generato casualmente, ma ci sei andato molto vicino!");
        }

        else{               /*Il numero inserito e' MINORE del numero generato casualmente*/
            C= *B - *A;

            if(C > 3)
                printf("ACQUA! Il numero inserito e' < del numero generato casualmente");
            else
                printf("FUOCO! Il numero inserito e' < del numero generato casualmente, ma ci sei andato molto vicino!");
        }

        printf("\n\nInserisci valore: ");
        scanf("%d",A);
        printf("\n");
    }

    if(*A == *B){           /*Il numero inserito e' UGUALE al numero generato casualmente*/
        printf("BRAVO! Il numero inserito: %d e' == al numero generato casualmente: %d",*A,*B);
        printf("\n");
    }
}

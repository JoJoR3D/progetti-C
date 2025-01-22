#include <stdio.h>
#include <stdlib.h>

/*
    Si scriva un programma in linguaggio C che legga da tastiera un numero intero A, lo riduca ad un
    valore compreso tra 0 e 127 mediante sottrazione ripetuta di un adeguato numero di volte del
    valore 128 (non si utilizzi l’operatore modulo o and), lo interpreti come caratteri ASCII e lo stampi
    sul video.
*/

int main()
{
    int A;
    printf("Inserire valore: ");
    scanf("%d", &A);

    if (A > 127) {
        while (A > 127) {
            A = A - 128;
            printf("Valore di A: %d\n",A);
        }
    }
    else{
        printf("\nValore di A: %d, Raprresentazione ASCII del valore di A: %c\n", A,(char)A);
        return 1;
    }

    printf("\nValore finale di A: %d, Raprresentazione ASCII del valore di A: %c\n", A,(char)A);
}


/*
    NOTA BENE: Se stampo un valore negativo, ad esempio: -10, lui farà 256-10= 'simbolo della divisione'.
               Questo perchè per il tipo char abbiamo a disposizione 8 bit= 256, quindi ogni volta scalerà il valore negativo inserito a 256 e stamperà il relativo
               carattere ASCII.
*/

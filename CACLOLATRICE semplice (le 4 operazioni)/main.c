#include <stdio.h>
#include <stdlib.h>
#include <math.h>       /*Serve per usare la function pow*/
#include "Lib.c"
#include "Prot.h"


/*CALCOLATRICE per il calcolo di: addizione, sottrazione, moltiplicazione, divisione e potenza*/



int main()
{
    float a,b;
    char segno;

    printf("Inserisci dati per il calcolo\n");

    printf("\nPrimo termine\n");
    scanf("%f",&a);

    fflush(stdin);                               /*Serve per pulire il Buffer. Senza mi salta lo scanf o la function getchar per inserire il segno*/

    printf("\nSegno del operazione\n");
    /*scanf("%c",&segno);*/                      /*Posso usare la scanf oppure la function getchar che serve per immettere da tastiera un carattere*/
    segno=getchar();

    printf("\nSecondo termine\n");
    scanf("%f",&b);


    if(segno == '/')
        printf("\nRisultato di (%d%c%d):\n%.3f", (int)a,segno,(int)b,(oper(segno,a,b)));    /*Uso il cast a int per stampare 'a' e 'b' come interi senza virgola (lo stesso per gli altri printf)*/
    else if(segno == '^')
        printf("\nRisultato di (%d%c%d):\n%.1f", (int)a,segno,(int)b,(oper(segno,a,b)));
    else
        printf("\nRisultato di (%d%c%d):\n%d", (int)a,segno,(int)b,((int)oper(segno,a,b))); /*La function oper ritorna un float, ma nel caso di operazioni come:
                                                                                              addiz., sottraz., o moltiplic. non ho bisogno di un risultato con la virgola,
                                                                                              quindi eseguo un cast a int alla function oper per ottenere come risultato di
                                                                                              queste tre operazioni un valore intero.*/

    return 0;
}

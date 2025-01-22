#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Libreria.c"
#include "Prot.h"


int main()
{
    int n=50;
    char string[n];     /*Stringa*/
    char Stringa;       /*Carattere*/
    int i;

    printf("Inserire stringa: ");
    gets(string);                              /*Inserisco la stringa da convertire*/

    printf("\nStringa convertita: ");

    if(strlen(string) <= n){                   /*Controllo per evitare che venga data in input una stringa di dimensione più grande rispetto alla dimensione della stringa dichiarata: string[50] (in questo caso la dimensione è 50)*/
        for(i=0;i<strlen(string);i++){         /*Tramite un ciclo for (con dimen. < della lungh. della stringa) passo un carattere alla volta della stringa (string[i]) alla function 'convertire'*/
            Stringa= convertire(string[i]);    /*La function 'convertire' converte ciascun carattere se è maiuscolo in minuscolo e viceversa*/
            printf("%c",Stringa);}             /*Viene stampato un carattere alla volta per comporre la stringa convertita.*/
    }
    else
        printf("Errore, la stringa inserita e' troppo grande");

    return 0;
}

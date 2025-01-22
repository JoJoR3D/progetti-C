#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Library.c"
#include "Protot.h"


int main()
{
    char stringa[][50]={"Paolo","GianlucaeLuca","Chiara"};

    char comper[50];

    int i,j;

    int m= strlen(&stringa[1][0]);    /*Passo alla variabile 'm' la lunghezza della stringa più lunga del array 2D di stringhe.*/

    printf("Array di stringhe:\n\n");
    for(i=0;i<3;i++){
        for(j=0;j<m;j++){
            printf("%c",stringa[i][j]);
        }
        printf("\n");
    }
    /*
    for(i=0;i<3;i++){                 Il ciclo for per stampare l'array 2D di stringhe posso farlo anche così. Gli passo l'indirizzo base di ogni riga, e stampa il contenuto di quella riga
            puts(stringa[i]);
    }
    */

    confronto(stringa,m,comper); /* L'indirizzo base comper lo posso scrivere anche come &comper[0] */

    int misu= strlen(comper);    /*Passo a 'misu' la lunghezza della stringa presente nell'array 1D comper. Nell'array comper vi è la stringa più lunga ritornatami dalla function confronto*/

    printf("\n");

    printf("La stringa piu' lunga del array di stringhe e': ");
    for(i=0;i<misu;i++)
        printf("%c",comper[i]);

    return 0;
}

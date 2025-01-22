#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char stringa[][50]={"Paolo","GianlucaeLuca","Chiara"};

    char comper[50];

    int i,j;

    int m= strlen(&stringa[1][0]);      /*Passo alla variabile 'm' la lunghezza della stringa più lunga del array 2D di stringhe.*/

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

    strcpy(comper,&stringa[0][0]);   /* La '&' perchè la strcpy ha come parametri (entrambi) un puntatore, quindi devo assegnargli l'indirizzo della stringa[i][j]. comper è giaà un indirizzo base, è l'indirizzo base del array comper*/
                                    /* L'indirizzo base comper lo posso scrivere anche come &comper[0] */
                                    /* Uso la è commerciale perchè per l'array 2D stringa non posso usare il suo nome come indirizzo base (cioè: stringa), ma devo usare l'indirizzo della stringa, usando la '&', perchè indico l'indice della riga e della colonna.....*/
                                    /*...oppure posso passare l'indirizzo della prima stringa: stringa[0], quindi: strcpy(comper,stringa[0]); */

    for(i=1;i<3;i++){
        for(j=0;j<m;j++){
                if(strlen(&stringa[i][j]) > strlen(comper))  /* La '&' perchè la strlen ha come parametro un puntatore (const char *_Str), quindi devo assegnargli l'indirizzo della stringa*/
                    strcpy(comper,&stringa[i][j]);           /* La '&' perchè la strcpy ha come parametri (entrambi) un puntatore, quindi devo assegnargli l'indirizzo della stringa[i][j]. comper è già un indirizzo base, è l'indirizzo base del array comper (poso scriverlo anche come &comper[0]*/
        }                                                    /* Uso la è commerciale perchè per l'array 2D stringa non posso usare il suo nome come indirizzo base (cioè: stringa), ma devo usare l'indirizzo della stringa, usando la '&', perchè indico l'indice della riga e della colonna.....*/
    }                                                        /* ....oppure posso usare ad esempio il ciclo for di sotto in alternativa.*/
    /*
    for(i=1;i<3;i++){                                        In alternativa al ciclo for di sopra posso usare questo ciclo for.
        if(strlen(stringa[i]) > strlen(comper))              comper è l'indirizzo base del array comper; stringa[i] è l'indirizzo base di ogni riga dell'array 2D stringa.
            strcpy(comper,stringa[i]);
    }
    */


    int misu= strlen(comper);    /*Passo a 'misu' la lunghezza della stringa presente nell'array 1D comper. Nell'array comper vi è la stringa più lunga ritornatami dalla function confronto*/
                                 /* L'indirizzo base comper lo posso scrivere anche come &comper[0] */
    printf("\n");

    printf("La stringa piu' lunga del array di stringhe e': ");
    for(i=0;i<misu;i++)
        printf("%c",comper[i]);

    return 0;
}






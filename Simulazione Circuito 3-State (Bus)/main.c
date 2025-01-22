#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct bus{
    char testo[50];
    char carattere;
    int valore;
};


typedef struct bus Bus;




int main()
{
    printf("Cosa si vuole trasferire sul BUS?\n\n0 per testo, 1 per carattere, -1 per valore\n");

    Bus t_state[1];       /*Dimensione 1 perchè testo, carattere e valore della struct si trovano tutti su un unica riga*/
    int num,i;
    scanf("%d",&num);

    while(num !=0 && num !=1 && num !=-1){   /*E' un controllo, se si immette un valore diverso da 0,1 0 -1 il ciclo si ripete fin quando non immetto un valore che sia 0,1 o -1*/
        printf("\n\nErrore, rinserire\n");
        scanf("%d",&num);
    }


    srand(time(NULL));
    int numero= rand()%2;       /*Genera i numeri pseudocasuali o 0 o 1*/


    while(numero == 0){         /*Se viene generato il valore 0 entro nel while*/

    if(numero == 0){
        printf("\n\nIl BUS e' occupato\n");
        printf("\nAttendere...");
    }

    numero= rand()%2;       /*Rigenero i numeri pseudocasuali o 0 o 1. Se viene generato 0 ripeto il while, se viene generato 1 esco dal while*/

    }
    if(numero == 1)                         /*Se numero è == 1 vu dire che il Bus è libero*/
        printf("\n\nIl BUS e' libero\n\n");



    fflush(stdin);          /*Pulisco il buffer. Senza non mi fa immettere la stringa testo*/

    if(numero == 1){        /*E se il Bus è libero posso proseguire per trasferire dati sul Bus*/

        if(num == 0){
            printf("\nE' stato selezionato 0, immettere il testo che si vuole trasferire tramite bus:\n");
            for(i=0;i<1;i++)
                gets(t_state[i].testo);     /* trans[i] è l'indirizzo del array testo dove inserire il testo da tastiera (Il nome del array è già un indirizzo). E' la stessa cosa di quando uso un semplice array.*/
            }

        else if(num == 1){
            fflush(stdin);      /*Pulisco il buffer. Senza non mi fa immettere il carattere*/

            printf("\nE' stato selezionato 1, immettere il carattere che si vuole trasferire tramite bus:\n");
            for(i=0;i<1;i++)
                scanf("%c",&t_state[i].carattere);        /* &trans[i] perchè devo dare l'indirizzo del array dove mettere il carattere. E' la stessa cosa di quando uso lo scanf per un carattere, uso la & senza però [i],*/
            }                                           /*qui lo uso perchè il carattere che voglio immettere si trova in un array di STRUCT*/

        else if(num == -1){
            printf("\nE' stato selezionato -1, immettere il valore che si vuole trasferire tramite bus:\n");
            for(i=0;i<1;i++)
                scanf("%d",&t_state[i].valore);           /* &trans[i] perchè devo dare l'indirizzo del array dove mettere il valore. E' la stessa cosa di quando uso lo scanf per un valore numerico, uso la & senza però [i],*/
            }                                           /*qui lo uso perchè il valore che voglio immettere si trova in un array di STRUCT*/
    }




    if(num == 0)
        printf("\n\nLa stringa e' giunta alla destinazione e sara' mostrata a video\n\n");
    if(num == 1)
        printf("\n\nIl carattere e' giunto alla destinazione e sara' mostrato a video\n\n");
    if(num == -1)
        printf("\n\nIL valore e' giunto alla destinazione e sara' mostrato a video\n\n");

    for(i=0;i<1;i++){                           /*Se dobbiamo trasferire un testo (num==0) un carattere (num==1) o un valore (num==-1),  sarà poi mostrato a video*/
        if(num == 0)
            printf("%s",t_state[i].testo);

        else if(num == 1)
            printf("%c",t_state[i].carattere);

        else if(num == -1){
            printf("%d",t_state[i].valore);
            if(t_state[i].valore==0)
                printf("\n\nSi e' verificato un ERRORE");} /*Se inserisco invece di un valore un carattere o altro nella scanf di sopra, mi verrà stampato zero, */
    }                                                     /*quinidi vuol dire che ho immesso qualcosa di diverso da un numero e per questo mi stampa ERRORE*/

    return 0;
}

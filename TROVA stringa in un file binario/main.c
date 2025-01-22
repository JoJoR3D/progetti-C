#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Esercizio: scrivere un programma che prende tre argomenti, i cui primi due sono stringhe e il terzo e il nome di un file. Questo programma deve controllare
    se nel file appare la prima stringa. Se appare, al suo posto deve mettere la seconda stringa. Occorre controllare che le due stringhe siano uguali.
*/


int compara(char*, char*, int);


int main()
{
    char file[]="file.dat";     /*.dat indica un tipo di file generico che può contenere vari tipi di dato*/
    char*s;
    char*s1="anna";             /*E' la stringa da trovare nel file binario*/
    char*s2="0000";             /*E' la stringa da sostituire alla stringa "anna" solo se viene trovata nel file*/
    int i=0,n=5,caratteri=0;    /*n==5 indica quante stringhe verrano inserite nel file*/

    int len= strlen(s1);        /*contiene la lunghezza della stringa da trovare.*/

    /*
        Il puntatore 's', all'inizio del programma ha un valore casuale, dove il
        programma non puo' scrivere perche' o appartiene ad altri programmi, o va
        oltre la memoria.
        Per questo lo inizializzo allocando dinamicamente una porzione di memoria da riservare al programma
    */

    s=malloc(len);



    /*---------------------SCRITTURA STRINGHE IN FILE BINARIO---------------------*/

    FILE*x;
    x=fopen(file,"w");

    if(x == NULL){
        printf("Si e' verificato un'errore\n");
        exit(1);
    }

    while(i < n){
        gets(s);                                /*Inserisco da tastiera la stringa da scrivere nel file*/
        fflush(stdin);
        fwrite(s,sizeof(char),strlen(s),x);     /*Scrivo la stringa inserita nel file binario. Inserisco 1 carattere alla volta della stringa.
                                                  Se la stringa 's' è lunga=5 (strlen(s)=5) allora inserisco un carattere alla volta (sizeof(char)).
                                                  RICORDA:
                                                  fwrite(s,sizeof(char),strlen(s),x);
                                                  1) 's' è il puntatore alla stringa;
                                                  2) sizeof(char) è il tipo di dato da inserire (stringa di caratteri);
                                                  3) strlen(s) indica la lunghezza della stringa e quindi indica quanti caratteri inserire nel file
                                                */
        caratteri=caratteri+strlen(s);          /*conta quanti caratteri sono presenti nel file.
                                                  Poichè le stringhe nel file binario vengono scritte uno di seguito all'altra (tutte unite), per trovare la
                                                  stringa da cercare ("anna"), devo eseguire il confronto carattere per carattere.
                                                */

        i++;
    }

    fclose(x);






    /*---------------------TROVA LA STRINGA E SOSTITUISCILA---------------------*/

    printf("\n\n");
    FILE*y;
    y=fopen(file,"r+");         /*Apro il file sia in lettura e sia in scrittura*/
    int posizione,confronto;

    if(y == NULL){
        printf("Si e' verificato un'errore\n");
        exit(1);
    }

    i=0;
    while(i < caratteri){                       /*Questo ciclo mi permette di ciclare su tutti i caratteri del file.*/
        posizione=ftell(y);                     /*Salvo la posizione del carattere che fread() leggerà*/
        fread(s,sizeof(char),len,y);            /*fread() legge un numero di caratteri (len) è li passa al puntatore 's'*/
        fflush(stdin);
        printf("%s\n",s);
        printf("%s\n",s1);
        confronto= compara(s,s1,len);           /*confronta i caratteri di 's' con i caratteri di 's1'.*/

        if(confronto == len){                   /*Se i caratteri di 's' sono == a quelli di 's1', confronto() ritorna un valore == a len.*/
            fseek(y,posizione,SEEK_SET);        /*Poichè dopo l'fread il cursore del file si sposta in avanti per puntare al prossimo carattere,
                                                  uso fseek() per riportare il cursore al carattere letto (quindi quello precedente).
                                                */
            fwrite(s2,sizeof(char),len,y);      /*A partire da questa posizione scrivo la stringa 's2' di lunghezza len.*/
            fseek(y,posizione+1,SEEK_SET);      /*Sposto il cursore del file al carattere successivo del file.*/
        }
        else
            fseek(y,posizione+1,SEEK_SET);      /*Se confronto mi ritorna un valore != da len vuol dire che i caratteri letti da fread() non sono uguali a quelli
                                                  di 's1', quindi per andare avanti, sposto il cursore al prossim carattere del file.
                                                */

        i++;                                    /*Incremento i.*/
    }

    fclose(y);








    /*---------------------LETTURA STRINGHE IN FILE BINARIO---------------------*/

    FILE*z;
    z=fopen(file,"r");

    if(z == NULL){
        printf("Si e' verificato un'errore\n");
        exit(1);
    }

    printf("\n\nLettura file:\n");
    i=0;
    while(i < caratteri){
        fread(s,sizeof(char),1,z);      /*Ogni volta che fread() legge 1 carattere del file lo stampo.*/
        printf("%c",*s);
        i++;
    }
    printf("\n");

    fclose(z);

    return 0;
}








/*  FUNCTION:
    Compara carattere per carattere delle stringhe 's' e 't'.
    Esempio:
    Se la stringa da trovare è "anna" (len=4), e la stringa contenuta in 's' è "anna",
    confronto carattere per carattere.
    Se i caratteri sono uguali, ogni volta il contatore viene incrementato.
    Alla fine viene ritornato il valore del contatore.

    Nel main, se confronto (a cui passo questa function) è == a 'len', la stringa 's' viene sovrascritta con la stringa 's2'.
*/


int compara(char*s, char*t, int n)
{
    int i,cont=0;

    for(i=0;i<n;i++){
        if(s[i] == t[i])
            cont++;
    }

    return cont;
}

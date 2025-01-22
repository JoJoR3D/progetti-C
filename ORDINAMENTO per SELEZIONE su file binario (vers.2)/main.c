#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.c"
#include "prot.h"


/*
    P.S. Ci sono probelmi con alcuni numeri. Il file non li legge correttamente e di conseguenza poi viene sbagliato l'ordinamento dei valori.
         I valori che non vengono letti correttamente sono il 10 e il 26. Non capisco il prechè.
         Ho provato ache ad usare un file .txt invece del .dat, ma non cambia nulla.
         Quando deve leggere il valore 10, legge un valore lunghissimo (sempre diverso).
         Quando deve leggere il valore 26, non lo legge ma rilegge il valore precedente. Ad esempio alla posizione 8 (byte) del file vi è il valore 14, cerca il
         valoe minore, lo trova e scambia alla posizione 8 inserendo il valore minore, ad esempio 13, e al posto del 13 mette il 14.
         Poi prosegue e legge il valore alla posizione successiva, ovvero la 12 (byte. Di 4 in 4 perchè ogni intero in memoria occupa 4byte). A questa posizione vi è
         il valore 26, ma non legge questo valore ma legge il valore 13 (quello della posizione precedente). Cioè legge il valore 13 anche se si trova alla posizione
         12 (byte) che dovrebbe contenere il valore 26.
*/


int main()
{
    /*---------------SCRITTURA DEI VALORI CASUALI SU FILE BINARIO---------------*/

    int var,var2,var_max,i,j,n=10,cerca=1,pos,pos2,pos_minimo=-1;
    int a[n];
    char file[]= "file.dat";        /*File generico che può contenere qualsiasi tipo di dato.*/

    FILE*x;
    x=fopen(file,"w");

    srand(time(NULL));

    for(i=0;i<n;i++)
        a[i]=0;         /*Inizializzo l'array 'a' con tutti zero. Questo mi servirà per far funzionare la function cerca ()*/

    if(x == NULL){
        printf("Si e' verificato un'errore\n");
        exit(1);
    }

    /*
      Apro il file binario in scrittura e scrivo nel file dei numeri casuali.
      Ogni numero generato viene salvato in un array per evitare che venga rigenerato di nuovo lo stesso numero.
      Se la function trova() ritorna cerca==1 vuol dire che il numero generato è presente nell'array, quindi è stato già generato in precedenza, quindi bisogna
      generare un nuovo numero.
      Una volta generato il valore, questo verrà scritto nel file.
    */

    i=0;
    while(i < n){
        while(cerca == 1){
            var= 11+rand()%20;               /*Genera 10 valori casuali da 11 a 20*/
            cerca= trova(a,var,n);
        }
        fwrite(&a[i],sizeof(int),1,x);
        printf("%d\n",a[i]);
        i++;
        fseek(x,4*i,SEEK_SET);              /*Avanzo nel file per scrivere i valori uno di seguito all'altro*/
        cerca=1;
    }

    fclose(x);









    /*
        SPIEGAZIONE DEL ORDINAMENTO PER SELEZIONE (SELECTION SORT):
        1) Leggo il primo valore del file.
        2) Attribuisco questo valore a 'var_max'.
        3) Assegno a 'pos' la posizione del valore nel file. -4 perchè dopo l'fread() il puntatore del file viene spostato di una posizione in modo da puntare al
           prossimo intero del file binario. -4 perchè un intero in memoria occupa 4byte.
        4) Ad esempio al primo ciclo, dopo aver letto il primo valore e varlo salvato in 'var', questo ciclo while legge il secondo valore del file (var2) e lo
           confronta con 'var', il minore viene salvato in var_max.
           Questo ciclo continua a leggere tutti i valori del file finchè non trova il valore più piccolo del file.
        5) Una volta trovato il valore più piccolo, viene salvata la posizione di questo valore in 'pos_minimo'.
        6) Se pos_minimo ha un valore diverso da -1, vuol dire che allora contiene l'indirizzo del valore più piccolo trovato.
        7) Mi porto alla posizione del valore letto dal ciclo esterno (var) (punto 3).
        8) A questa posizione assegno il valore più piccolo trovato (var_max).
        9) Mi riposrto alla posizione del valore più piccolo trovato (pos_minimo).
        10) A questa posizione assegno il valore letto al punto 1 (var).
        11) Avanzo al prossimo intero (4byte) in modo che il ciclo esterno possa leggere il prossimo valore del file.
    */



    /*---------------ORDINAMENTO DEI VALORI NEL FILE BINARIO---------------*/

    printf("\n\n\n");

    FILE*z;
    z=fopen(file,"r+");

    if(z == NULL){
        printf("Si e' verificato un'errore\n");
        exit(1);
    }

    i=0,j=1;
    while(i < n){
        fread(&var,sizeof(int),1,z);                /*(1)*/
        printf("VAR: %d\n",var);
        var_max=var;                                /*(2)*/

        fseek(z,4*i,SEEK_SET);
        pos=ftell(z);                               /*(3)*/
        printf("POS %d\n\n",pos);

        while(j < n){                               /*(4)*/
            fseek(z,4*j,SEEK_SET);
            fread(&var2,sizeof(int),1,z);
            fseek(z,4*j,SEEK_SET);
            pos2=ftell(z);

            if(var2 < var_max){
                pos_minimo=pos2;                    /*(5)*/
                var_max=var2;
                printf("VAR2: %d, POS2: %d\n",var2,pos2);
            }

            j++;
            /*fseek(z,4*j,SEEK_SET);*/
        }
        printf("VAR_MAX: %d, POS_MINIMO: %d\n",var_max,pos_minimo);

        if(pos_minimo != -1){                       /*(6)*/
            fseek(z,pos,SEEK_SET);                  /*(7)*/
            fwrite(&var_max,sizeof(int),1,z);       /*(8)*/

            fseek(z,pos_minimo,SEEK_SET);           /*(9)*/
            fwrite(&var,sizeof(int),1,z);           /*(10)*/
        }

        i++;
        j=i+1;
        fseek(z,4*i,SEEK_SET);                      /*(11)*/
        pos_minimo=-1;                              /*Resetto pos_minimo impostandolo a -1*/
        printf("\n\ni %d, j %d\n\n",i,j);
    }

    fclose(z);








    /*---------------LETTURA DEI VALORI ORDINATI NEL FILE BINARIO---------------*/

    printf("\n\n");
    FILE*y;
    y=fopen(file,"r");

    if(y == NULL){
        printf("Si e' verificato un'errore\n");
        exit(1);
    }

    printf("VALORI ORDINATI NEL FILE BINARIO\n");
    i=0;
    while(i < n){
        fread(&var,sizeof(int),1,y);
        printf("%d\n",var);
        i++;
        fseek(x,4*i,SEEK_SET);
    }

    fclose(y);

    return 0;
}

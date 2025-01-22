#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
    L’utente inserisce una sequenza di caratteri, terminata dal carattere ‘#’. Il programma visualizza i
    caratteri, trasformando tutte le lettere minuscole in maiuscole.
    Eventuali caratteri diversi dalle lettere minuscole e dal ‘#’ devono essere visualizzati come ‘_’; il
    carattere ‘#’ deve essere anch’esso visualizzato.
*/


void insert_string(char[], int*);
void min_max(char[], int);


int main()
{
    char stringa[50];
    int i,n,dim_array=50;

    for(i=0;i<=dim_array;i++)
        stringa[i]= ' ';        /*Serve per pulire l'allocazione di memroia che ho riservato per l'array stringa. Questo perchè, a fine programma, */
                                /*a volte stampa caratteri a caso presenti in questo spazio di allocazione riservato alla stringa.*/
    insert_string(stringa,&n);

    min_max(stringa,n);

    puts(stringa);

    return 0;
}



void insert_string(char s[], int*i)
{
    *i=0;
    char c;

    printf("Inserisci la stringa. Termina inserendo il carattere '#'\n");
    while(c != '#'){    /*Questo ciclo mi consente di inserire da tastiera la stringa*/
        c= getchar();
        s[*i]= c;
        *i= *i+1;       /*Mi ritorna la dimensione della stringa inserita da tastiera*/
    }
}



void min_max(char s[], int n)
{
    int i=0,j=0,dim_min,cont=0;
    char min[]= {'a','b','c','d','e','f','g','h','i','l','m','n','o','p','q','r','s','t','u','v','z'};
    char max[]= {'A','B','C','D','E','F','G','H','I','L','M','N','O','P','Q','R','S','T','U','V','Z'};

    dim_min= strlen(min);

    while(i < n){
        while(j < dim_min){
            if(s[i] == min[j]){     /*Se un carattere della stringa è == a min (caratteri minuscoli) questo viene sostituito con max (caratteri maiuscoli). Questo per ogni carattere della stringa.*/
                s[i] = max[j];
                cont=1;             /*Se il carattere dellla stringa viene sostituito con il carattere max, cont viene posto = 1*/
            }                       /*Invece cont==0 significa che il carattere della stringa non è stato sostituito, quindi viene eseguito l'if sotto*/

            j++;
        }
        if(cont == 0 && s[i] != '#' && s[i] != ' ')     /*Se il carattere della stringa è già Maiuscolo ma non è il carattere '#' oppure il carattere 'spazio' */
            s[i] = '_';                                 /*questo viene sostituito con il carattere '_' */

        cont=0;
        j=0;
        i++;
    }
}


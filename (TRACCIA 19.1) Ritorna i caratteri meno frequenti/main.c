#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
TRACCIA 19

Sviluppare una function C che, dati come parametri di input un array di char e il suo size, determina e restituisce come parametro di output il
carattere meno frequente.

N.B. Se ci sono più caratteri meno frequenti (ad esempio il carattere 'a' e il carattere 'b' sono entrambi presenti una sola volta nel testo), li ritorna.
*/


void usually(char*, char*, char*);


int main()
{
    char*array= "Carmela ha un quaderno e poi un telefono con una vibrazzione zanzarosa, però è grande";
    /*char alf[]= {'a','b','c','d','e','f','g','h','i','l','m','n','o','p','q','r','s','t','u','v','z'};*/
    char*alf= "abcdefghilmnopqrstuvz";
    int i,n=strlen(alf);
    char caratteri[n];                      /*Non posso dichiararlo come una costante stringa (char*caratteri) perchè non possono essere modificare una volta assegnatoi una stringa*/

    for(i=0;i<n;i++)
        caratteri[i]= 'x';                  /*Pulisco il contenuto di 'caratteri' riempiendolo con un carattere a caso*/

    usually(array,alf,caratteri);

    printf("I caratteri che si ripetono meno volte in array sono:\n");

    for(i=0;i<n;i++){
        if(caratteri[i] != 'x')
            printf("%c\n",caratteri[i]);
    }

    return 0;
}



void usually(char*stringa, char*Alf, char*car)
{
    int i,j,n,m,index;
    n= strlen(stringa);
    m= strlen(Alf);
    int conta=0,conta_chiave=n;

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(Alf[i] == stringa[j])
                conta++;
        }
        if(conta <= conta_chiave){
            conta_chiave= conta;
            index= i;
        }
        if(conta_chiave <= 1)
            car[index]= Alf[index];

        conta=0;
    }
}

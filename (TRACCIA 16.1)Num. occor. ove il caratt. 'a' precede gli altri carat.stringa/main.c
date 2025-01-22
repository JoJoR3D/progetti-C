#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trova(char*, char*, int, int, int[]);
int search(char, char[], int);


int main()
{
    char*caratteri= "mamma ha preparato la cena ma non mi ha avvisato";
    char*alfa= "abcdefghilmnopqrstuvz";
    int n= strlen(caratteri);
    int m= strlen(alfa),i;
    int occorenze[m];

    for(i=0;i<m;i++)
        occorenze[i]= 0;    /*Metto il valore 0 ad ogni posizione del array occorenze per pulirlo.*/

    trova(caratteri,alfa,n,m,occorenze);

    printf("Numero occorenze in cui, nella stringa caratteri, il carattere 'a' precede gli altri ventuno caratteri:\n");
    for(i=0;i<m;i++){
        printf("%c: %d\n",alfa[i],occorenze[i]);
    }

    return 0;
}



/*Questa function poteva essere uguale al'esercizio TRACCIA 16 originale, perchè anche se invece di un array di caratteri ho una stringa, devo sempre confrontare
  un carattere della stringa (caratteri) con il carattere 'a' e no con un'array di caratteri o una stringa.
  Quindi non c'è bisogno dello strncmp ma posso benissomo fare un semplice confronto: if Car[i]=='a' .
*/

void trova(char*Car, char*Alf, int n, int m, int occ[])
{
    int i,index;
    char carattere= 'a';
    char*a;
    a= &carattere;

    for(i=0;i<n;i++){
        if(Car[i]!= ' ' && Car[i+1]!= ' '){
            if(strncmp(a,&Car[i],1)==0){
                index= search(Car[i+1],Alf,m);
                occ[index]= occ[index]+1;
            }
        }
    }
}



int search(char chiave, char a[], int n)
{
    int i,indice;

    for(i=0;i<n;i++){
        if(chiave == a[i])
            indice= i;
    }
    return indice;
}

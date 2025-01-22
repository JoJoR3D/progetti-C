#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
    Si scriva un programma in linguaggio C che acquisisca da tastiera una parola (cioè una stringa di
    caratteri priva di separatori) e la stampi a video se e solo se tale parola è palindroma, ossia
    leggibile nello stesso modo da destra a sinistra e viceversa (es. OSSESSO).
    Per determinare la lunghezza della parola si può utilizzare la funzione strlen(s) contenuta nel
    file header <string.h>.
*/


void leggi_da_tastiera(char*);
int Palindromo(char*, int);



int main()
{
    char stringa[100];
    int n,valore;

    leggi_da_tastiera(stringa);
    n= strlen(stringa);
    valore= Palindromo(stringa,n);

    if(valore == 1)
        printf("La parola %s e' palindroma",stringa);
    else
        printf("La parola %s NON e' palindroma",stringa);

    return 0;
}



void leggi_da_tastiera(char*s)
{
    gets(s);
}



int Palindromo(char*s, int n)
{
    int i=0, j=n-1, divide_in_due= (n-1)/2;

    while(i <= divide_in_due){
        if(s[i] == s[j])        /*Al primo ciclo confronto il primo carattere con l'ultimo carattere della parola, poi il secondo con il penultimo e così via.*/
            return 1;
        else
            return 0;

        i++;
        j--;
    }
}

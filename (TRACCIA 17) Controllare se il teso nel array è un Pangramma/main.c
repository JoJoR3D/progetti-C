#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
TRACCIA 17

Sviluppare una function C che, dati come parametri di input un array di char e il suo size, determina e restituisce come parametro di un dato logico che indica
se il testo nell’array è un pangramma, ovvero è un testo che contiene, almeno una volta, tutte le 21 lettere dell’alfabeto italiano.
*/

int pangramma(char*, char*);


int main()
{
    char*array= "Carmela ha un quaderno e poi un telefono con una vibrazzione zanzarosa, però è grande";
    /*char alf[]= {'a','b','c','d','e','f','g','h','i','l','m','n','o','p','q','r','s','t','u','v','z'};*/
    char*alf= "abcdefghilmnopqrstuvz";

    int Pan= pangramma(array,alf);

    if(Pan == 1)
        printf("Array contiene tutte le 21 lettere dell'alfabeto italiano (Pangramma)\n");
    else
        printf("NO Pangramma\n");

    return 0;
}



int pangramma(char*stringa, char*Alf)
{
    int i,j,n,m,conta=0;
    n= strlen(stringa);
    m= strlen(Alf);

    /*
        N.B. Uso il comando 'break' perchè quando trovo un carattere di Alf in stringa, interrompo il ciclo for interno (j) perchè mi basta che quel carattere di Alf
             venga trovato una sola volta in stringa. Senza il break il ciclo continuerebbe e quando ritrovo di nuovo quel carattere di Alf in stringa incrementa
             di nuovo cont, ma questo non farebbe funzionare correttamente il programma.
    */

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(Alf[i] == stringa[j]){
                conta++;
                break;
            }
        }
    }

    if(conta == m)
        return 1;
    return 0;
}

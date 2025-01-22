#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*CONVERTE TUTTA LA STRINGA IN MAIUSCOLO o in MINUSCOLO*/


int convert(char);


int main()
{
    int n=50;
    char String[n];
    char string;
    int i;

    gets(String);

    if(strlen(String) < n){
        for(i=0;i<strlen(String);i++){
            string= convert(String[i]);
            printf("%c",string);}
    }
    else
        printf("ERRORE la stringa e' troppo grande");

    return 0;
}

/*

CONVERTE TUTTA LA STRINGA IN MINUSCOLO


int convert(char stringa)
{
    return (stringa|32);    OR bit a bit
}


ESEMPIO:

'A' in codice ASCII è 65= 1000001 OR
    codice ASCCII di 32=  0100000 =

'a' in codice ASCII è 97= 1100001 OR

L'OR bit a bit ritorna 1 in quelle posizioni in cui almeno una delle due variabili di partenza presenta 1 e
uno 0 in tutte le altre posizioni (ossia le posizioni in cui entrambe le variabili presentano '0').

Se il carattere che giunge in input alla function convert è già Minuscolo anche facendo l'operazione di OR con 32, questo carattere rimarrà invariato.
Esempio:

'a' in codice ASCII è 97= 1100001 OR
    codice ASCCII di 32=  0100000 =

'a' in codice ASCII è 97= 1100001

il carattere ricevuto è 'a' (minuscolo con codice ASCII 97), facendo l'OR con 32 rimane sempre 'a' (minuscolo con codice ASCII 97).

*/




/*CONVERTE TUTTA LA STRINGA IN MAIUSCOLO*/

int convert(char stringa)
{
    char s= (stringa-32);   /*Sottraggo al codice ASCII del carattere ricevuto in input il valore 32*/
    if((int)s >= 65)        /*Se il carattere ricevuto è già maiuscolo, ritorno semplicemente questo carattere senza fare nulla*/
        return s;
    return stringa;         /*Se invece il carattere ricevuto è minuscolo, sottraggo al codice ASCII di quel carattere il valore 32 per ottenere
                              il codice ASCII corrispondente al carattere Maiuscolo.*/
}


/*
ESEMPIO:

'a' in codice ASCII è 97= 1100001 sottrazione
    codice ASCII di 32=   0100000 =

'A' in codice ASCCI è 65= 1000001

Precisando che nella tabella ASCII i caratteri MAIUSCOLI del alfabeto partano dal codice 65 fino al 90, mentre i caratteri MINUSCOLI del alfabeto partano dal codice 97 fino a 122.
Da un carattere Maiuscolo ad uno Minuscolo o viceversa c'è sempre una differenza di 32.
Ora visto che devo SOLO convertire tutta la stringa in MAIUSCOLO, se un carattere è già Maiuscolo non devo fare nulla, ecco perché ad esempio se alla function covert arriva
il carattere 'A' che è già maiuscolo (codice ASCII= 65), se sottraggo a 65 il valore 32 ottengo 33 che corrisponde al carattere '!'. Quindi se la function convert riceve un carattere già
Maiuscolo, non fa nulla e ritorna semplicemente quel carattere.

*/


/*

SITO per il bit a bit: https://it.wikipedia.org/wiki/Operazione_bit_a_bit

Tabella codice ASCII: https://www.oppo.it/tabelle/tabella_ascii.htm#:~:text=ASCII%20(si%20pronuncia%20%22askii%22,grafici%20e%20di%20lingue%20straniere.

*/


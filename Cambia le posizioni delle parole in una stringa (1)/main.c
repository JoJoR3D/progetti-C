#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Libreria.c"
#include "Prototipi.h"


/*
    Questo programma prende due parole, una dal inizio della stringa (i=0) e una dalla fine della stringa (j=n-1) e le scambia tra loro carattere per carattere.
    Poi passa a scambiare la seconda parola a partire dal inizio della stringa con la penultima parola a partire dalla fine della stringa.
    E così via fino a quando non si arriva alla metà della stringa (int divide_in_due).

    N.B. Se divide_in_due è= 20, e una parola ha il primo carattere all'indice 15 e l'ultimo carattere all'indice 24, questa non verrà considerata e il
         programma terminerà.
*/



int main()
{
    char stringa[]= "Vestiti da sera che c'e il mio pezzo preferito"/*"Giancarlo e Maria lavorano duro in ufficio"*//*"Mi concedo un altro rischio da affrontare"*//*"Mamma cucina pasta con la salsa"*//*"Alice nel paese delle meraviglie con il gatto matto"*//*"Corro e non mi importa"*//*"salto felice nella giungla"*/;
    int n;
    n= strlen(stringa);

    puts(stringa);

    swap_position(stringa,n);

    puts(stringa);

    int m=strlen(stringa);

    printf("\n%d %d",n,m);

    return 0;
}

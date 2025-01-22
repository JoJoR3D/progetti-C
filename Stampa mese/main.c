#include <stdio.h>
#include <stdlib.h>


int main()
{
    char mese[][10]= {"Gennaio","Febbraio","Marzo","Aprile","Maggio","Giugno","Luglio","Agosto","Settembre","Ottobre","Novembre","Dicembre"};

    /*
    char*mese[]= {"Gennaio","Febbraio","Marzo","Aprile","Maggio","Giugno","Luglio","Agosto","Settembre","Ottobre","Novembre","Dicembre"};   POSSO DICHIARARE L'ARRAY 2D ANCHE IN QUESTO MODO.
                                                                                                                                            Un puntatore che punta ad ogni riga del array 2D.
                                                                                                                                            Quindi e come se avessi tanti array che compongono un array 2D.
                                                                                                                                            In questo modo non devo indicare neanche il numero di colonne.
    */

    int numero;

    printf("Inserisci numeri da 0 a 11 per mostrare il mese corrispondente\n");

    scanf("%d",&numero);


    if(numero >= 0  && numero <=11)
        printf("Il mese corrispondente e' %s", &mese[numero][0]);  /*Va al indirizzo base della stringa e la stampa tutta.*/
    else
        printf("\nERRORE");

    return 0;
}

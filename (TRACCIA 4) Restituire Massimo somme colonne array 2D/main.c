#include <stdio.h>
#include <stdlib.h>

double max(double [][3], int, int);

int main()
{
    double a[][3]={{2,5,7},
                   {6,1,3}};
    int n=2,m=3;

    double somma= max(a,n,m);

    printf("%e",somma);     /*%e oppure %E è il codice di formato per il double.*/
                            /*se invece del tipo double avvessi usato il tipo int avrei ottenuto come risulato, con questi valori, 10. Con double ottengo: 1.000000e+001*/
    return 0;
}



double max(double a[][3], int n, int m)
{
    int i,j;
    double som=0,cont=0;

    for(j=0;j<m;j++){               /*Tengo fissa la colonna*/
        for(i=0;i<n;i++){           /*e scorro la riga*/
            cont= cont+a[i][j];     /*Ad ogni ciclo calcolo la somma delle colonne.*/
        }
        if(cont > som)      /*Se la somma ottenuta è maggiore del valore contenuto in som (al primo ciclo som è == 0) allora som viene aggiornata.*/
            som= cont;

        cont=0;     /*Dopo aver terminato la somma di una colonna, azzero il contenuto di cont per poter sommare i valori della prossima colonna.*/
    }
    return som;
}

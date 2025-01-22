#include <stdio.h>
#include <stdlib.h>

int n=3, m=4;                           /*Dichiaro n (righe) e m(colonne) nel prototipo in questo modo vale per tutto il programma. Mi basta modificare i valori qui per cambiarli in tutto il programma.*/
void write(int a[][m], int n, int m);
void read(int a[][m], int n, int m);
int max(int a[][m], int n, int m);



int main()
{
    int array[n][m];

    write(array,n,m);
    read(array,n,m);
    int massimo= max(array,n,m);

    printf("\nLa somma di riga maggiore e': %d",massimo);
    return 0;
}




int max(int a[][m], int n, int m)
{
    int i,j,cont=0,som=0;

    for(i=0;i<n;i++){               /*Tengo fissa la riga*/
        for(j=0;j<m;j++){           /*e scorro la colonna*/
            cont= cont+a[i][j];     /*Ad ogni ciclo calcolo la somma delle colonne.*/
        }
        if(cont > som)          /*Se la somma ottenuta è maggiore del valore contenuto in som (al primo ciclo som è == 0) allora som viene aggiornata.*/
            som= cont;

        cont=0;                 /*Dopo aver terminato la somma di una colonna, azzero il contenuto di cont per poter sommare i valori della prossima colonna.*/
    }
    return som;
}




void write(int a[][m], int n, int m)    /*Inserisco da riga di comando i valori del array 2D.*/
{
    int i,j;

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
        printf("\n");
    }
}



void read(int a[][m], int n, int m)     /*Stampa a schermo i valori presenti nel array 2D (che ho precedentemente inserito da riga di comando).*/
{
    int i,j;

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

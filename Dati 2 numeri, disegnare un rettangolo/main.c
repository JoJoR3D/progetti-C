#include <stdio.h>
#include <stdlib.h>

/*
    Chiedere 2 numeri interi (a,b) e disegnare un rettangolo di dimensioni a*b usando il carattere " * ".
*/


void build(int, int, char*, int);


int main()
{
    int A,B;

    printf("Inserire Primo valore: ");
    scanf("%d",&A);
    printf("Inserire Secondo valore: ");
    scanf("%d",&B);

    int n_col= B;
    char rett[A][B];

    printf("\n");

    build(A,B,&rett[0][0],n_col);

    return 0;
}




void build(int A, int B, char*pa, int n_col)
{
    int i,j,riga,colonna;

    /*
      Questo if e else mi consentono di avere i due lati superiore e inferiore maggiori rispetto ai due lati destro e sinistro.
      Ciò dipende però dai valori che do in input. Se do in input il valore: 60 e come secondo valore: 30, questo if e else faranno
      in modo che 60 corrisponda alle colonne (indice 'j', lato superiore e inferiore), mentre 40 corrisponderà alle righe
      (indice 'i', lato sinistro e destro).
    */

    if(A > B){
        colonna= A;
        riga= B;
    }
    else{
        colonna= B;
        riga= A;
    }

    for(i=0;i<riga;i++){
        for(j=0;j<colonna;j++){
            if(i==0 || i==riga-1)                       /*In questo modo disegna i margini superiori e inferiori*/
                printf("%c ",*(pa+n_col*i+j)= '*');
            else if(j==0 || j==colonna-1)               /*In questo modo disegna il margine destro e sinistro*/
                printf("%c ",*(pa+n_col*i+j)= '*');
            else                                        /*In questo modo rimane vuota (inserendo il carattere spazio) l'area del rettangolo*/
                printf("%c ",*(pa+n_col*i+j)= ' ');
        }
        printf("\n");
    }
}

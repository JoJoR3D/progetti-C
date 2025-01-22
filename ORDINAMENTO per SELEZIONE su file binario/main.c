#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.c"
#include "prot.h"



int main()
{
    /*---------------SCRITTURA DEI VALORI CASUALI SU FILE BINARIO---------------*/

    FILE*x;
    x=fopen("file.dat","w");

    srand(time(NULL));

    int var,i,n=10,cerca=1;
    int a[n];

    for(i=0;i<n;i++)
        a[i]=0;

    if(x == NULL){
        printf("Si e' verificato un'errore\n");
        exit(1);
    }

    /*Apro il file binario in scrittura e scrivo nel file dei numeri casuali.
      Ogni numero generato viene salvato in un array per evitare che venga rigenerato di nuovo lo stesso numero.
      Se la function trova() ritorna cerca==1 vuol dire che il numero generato è presente nell'array, quindi è stato già generato in precedenza, quindi bisogna
      generare un nuovo numero.
      Una volta generato il valore, questo verrà scritto nel file.
    */

    i=0;
    while(i < n){
        while(cerca == 1){
            var= (1+rand()%10)+10;      /*Genera valori casuali da 11 a 20*/
            cerca= trova(a,var,n);
        }
        fwrite(&var,sizeof(int),1,x);
        /*printf("%d\n",var);*/
        i++;
        fseek(x,4*i,SEEK_SET);  /*Avanzo nel file per scrivere i valori uno di seguito all'altro. 4 perchè un intero in memoria occupa 4byte*/
        cerca=1;
    }

    fclose(x);

    printf("Array disordinato\n");
    for(i=0;i<n;i++)
        printf("%d\n",a[i]);






    /*---------------ORDINAMENTO DEI VALORI CASUALI DEL ARRAY---------------*/

    /*Questa function ordina gli elementi dell'array 'a'.*/
    selection_sort(a,n);

    printf("\n\nArray ordinato\n");
    for(i=0;i<n;i++)
        printf("%d\n",a[i]);






    /*---------------SCRITTURA DEI VALORI ORDINATI DEL ARRAY NEL FILE BINARIO---------------*/

    FILE*y;
    y=fopen("file.dat","w");

    if(y == NULL){
        printf("Si e' verificato un'errore\n");
        exit(1);
    }

    printf("\n\nScrittura dei valori ordinati dell'array 'a' nel file binario\n");
    i=0;
    while(i < n){
        fwrite(&a[i],sizeof(int),1,y);
        printf("%d\n",a[i]);
        i++;
        fseek(y,4*i,SEEK_SET);
    }

    fclose(y);


    return 0;
}




#include <stdio.h>
#include <stdlib.h>

int max(int*, int);


int main()
{
    int a[]={3,7,5,10,8};
    int n=5;

    int Max= max(a,n);

    printf("%d",Max);

    return 0;
}




int max(int*a, int n)
{
    int i;
    int mass= a[0];
    int second_max;

    for(i=1;i<n;i++){
        if(a[i] > mass){
            second_max= mass;   /*Prima che mas venga aggiornato con il nuovo valore più grande, salvo il suo valore attuale in un'altra variabile. In questo modo, al termine del ciclo,*/
            mass= a[i];         /*la variabile second_max avrà il penultimo valore più grande dell'array mentre, la variabile mas conterrà il valore più grande del array.*/
        }
        else if(i == n-1){          /*Questo else if serve nel caso in cui il secondo elemento più grande si trovi all'ultima posizione del array.*/
            if(a[i] > second_max)   /*Senza questo controllo second_max non verrebbe aggiornato nel caso in cui il secondo elemento più grande si trovi al'ultima posizione.*/
                second_max= a[i];
        }
    }

    return second_max;
}

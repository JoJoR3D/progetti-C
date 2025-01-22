#include <stdio.h>
#include <stdlib.h>

void trova(char[], char[], int, int, int[]);
int search(char, char[], int);


int main()
{
    char caratteri[]= {'c','a','r','o','l','i','n','a','c','a','m','m','i','n','a','n','e','l','p','r','a','t','o'};
    char alfa[]= {'a','b','c','d','e','f','g','h','i','l','m','n','o','p','q','r','s','t','u','v','z'};
    int n= 23;
    int m= 21,i;
    int occorenze[m];

    for(i=0;i<m;i++)
        occorenze[i]= 0;    /*Metto il valore 0 ad ogni posizione del array occorenze per pulirlo.*/

    trova(caratteri,alfa,n,m,occorenze);

    printf("Numero occorenze in cui, nel array di char, il carattere 'a' precede gli altri ventuno caratteri:\n");
    for(i=0;i<m;i++){
        printf("%c: %d\n",alfa[i],occorenze[i]);
    }

    return 0;
}



void trova(char Car[], char Alf[], int n, int m, int occ[])
{
    int i,index;

    for(i=0;i<n;i++){
        if(Car[i] == 'a'){
            index= search(Car[i+1],Alf,m);
            occ[index]= occ[index]+1;
        }
    }
}



int search(char chiave, char a[], int n)
{
    int i,indice;

    for(i=0;i<n;i++){
        if(chiave == a[i])
            indice= i;
    }
    return indice;
}

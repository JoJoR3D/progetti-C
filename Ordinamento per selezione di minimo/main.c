#include <stdio.h>
#include <stdlib.h>

void min(int*a, int n, int*index);
void swap(int*a,int*b);
void ord(int*a, int n);


int main()
{
    int a[]={3,9,1,7,5};
    int n= 5,i;

    ord(a,n);

    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    return 0;
}



void min(int*a, int n, int*index)
{
    int i, min=a[0];
    *index= 0;

    for(i=1;i<n;i++){
        if(a[i] < min){
            min= a[i];
            *index= i;
        }
    }
}



void swap(int*a,int*b)
{
    int t;
    t= *a;
    *a= *b;
    *b= t;
}



void ord(int*a, int n)
{
    int i,indice_min;

    for(i=0;i<n-1;i++){
        min(&a[i],n-i,&indice_min);
        swap(&a[i],&a[indice_min+i]);
    }
}

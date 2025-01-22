#include <stdio.h>
#include <stdlib.h>

void max(int*a, int n, int*index);
void swap(int*a,int*b);
void ord(int*a, int n);


int main()
{
    int a[]={6,9,1,7,5};
    int n= 5,i;

    ord(a,n);

    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    return 0;
}



void max(int*a, int n, int*index)
{
    int i, max=a[0];
    *index= 0;

    for(i=1;i<n;i++){
        if(a[i] > max){
            max= a[i];
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
    int i,indice_max;

    for(i=n-1;i>0;i--){
        max(&a[0],i+1,&indice_max);
        swap(&a[i],&a[indice_max]);
    }
}

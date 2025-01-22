#include <stdio.h>
#include <stdlib.h>

void merge_sort(int*, int);
void fusione6(int[], int, int[], int, int[]);
void ord(int[], int);
void swap(int*, int*);


int main()
{
    int i;
    int a[]={13,45,20,19,1,33};
    int n= 6;
    /*int c[n];*/

    merge_sort(a,n);

    /*for(i=0;i<n;i++)
        printf("%d\n", a[i]);*/

    return 0;
}







void merge_sort(int*a, int n)
{
    int right;
    int left;
    int center;
    int ciclo=0;
    int conto;
    int mediano;

    if(ciclo == 0){
        right= 0;
        left= n-1;
        /*printf("%d %d",right, left);*/
        center= (right + left)/2;
        /*int mediano= center;*/
        conto= 0;}

    else{
        if(a[center] < a[center-1]){
        right= 0;
        left= center;
        /*printf("%d %d",right, left);*/
        center= (right + left)/2;
        mediano= center+1;}

    else if(a[center] > a[center+1]){
        right= center;
        left= n-1;
        /*printf("%d %d",right, left);*/
        center= (right + left)/2;
        mediano= center+1;}
    }

    ciclo++;


    /*int*right= &a[0];
    int*left= &a[n-1];
    printf("%d %d",right, left);
    int center= (right + left)/2;*/

    /*int c[n];*/

    if(mediano == 1){
        ord(a,center);
        ord(&a[center],n);

        int i;

        for(i=0;i<n;i++)
            printf("%d\n", a[i]);}
        /*a[0];*/
        /*ord(merge_sort(a,center), merge_sort(&a[center],n));*/

    if(/*a[0] + center-1*/a[center] < a[center-1]/*center+1 + n-1*/ /*&& conto == 0*/)
        /*ord(a,center);*/
        /*n--;*/
        merge_sort(a,center);
    /*return fusione6(a,center-1,&center+1,n-1,c);*/

    else if(a[center] > a[center+1])
        /*ord(&a[center],n);*/
        /*n--;*/
        merge_sort(&a[center],n);
    /*return fusione6(&center+1,center-1,&center+1,n-1,c);*/

    printf("%d\n\n\n",mediano);
}










void ord(int a[], int n)
{
    int i;

    for(i=0;i<n;i++){
        if(a[i] > a[i+1])
           swap(&a[i],&a[i+1]);
    }
}



void swap(int*a, int*b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}





/* SECONDA VERSIONE Algoritmo di Fusione con uso del WHILE (variante più elegante) (non sta nelle slide, vedi screenshot del 19-10-2021) */

void fusione6(int a[], int n_a, int b[], int n_b, int c[])
{
    int i_a=0, i_b=0, i_c=0;
    while(i_a < n_a && i_b < n_b){
        if(a[i_a] < b[i_b]){
            c[i_c] = a[i_a++];
        }
        else{
            c[i_c] = b[i_b++];
        }
        i_c++;                  /*Posizione POSTFISSA (i_c++) del ++ prima si usa il valore e poi lo si incrementa. Posizione PREFISSA (++i_c) invece prima si incrementa e poi si usa il valore */
    }
    while(i_a < n_a){
        c[i_c++] = a[i_a++];
    }
    while(i_b < n_b){
        c[i_c++] = b[i_b++];
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Per info vedi slide: P1-11-03-C
  Percorso slide: C:\Users\Giuse\OneDrive\Desktop\Università\Programmazione I Parte II CIARAMELLA\ANNO 2021-22\Lez. del 23-11*/

void ord_sel_min(char*array[], int n);
void ord_sel_max(char*array[], int n);

int min_val_ind(char*a[], int n);
int max_val_ind(char*a[], int n);
void scambiare(char**a, char**b);

void fusione(char*a[], int n_a, char*b[], int n_b, char*c[]);




int main()
{
    /*E' un puntatore che punta ad ogni stringa dell'array*/

    char*s[]= {"Peppe","Anna","Bianca","Laura"};
    char*t[]= {"Salvatore","Luca","Tatore","Angelo"};
    int n=4,i;
    char*z[n+n];

    ord_sel_min(s,n);
    ord_sel_max(t,n);
    fusione(s,n,t,n,z);

    for(i=0;i<n;i++)
        printf("%s ",s[i]);
    printf("\n");
    for(i=0;i<n;i++)
        printf("%s ",t[i]);
    printf("\n");
    for(i=0;i<n+n;i++)
        printf("%s ",z[i]);

    ord_sel_min(z,n+n);     /*Ordina l'array di stringhe 'z' che contiene i due array 's' e 't' ordinati dopo la fusione di questi due utlimi array.*/

    printf("\n\n");
    for(i=0;i<n+n;i++)
        printf("%s ",z[i]);
    printf("\n");

    return 0;
}




void ord_sel_min(char*array[], int n)
{
    int i;

    for(i=0;i<n;i++){
        int codice=min_val_ind(&array[i],n-i);
        if(i>0)
            codice=codice+i;    /*Perchè l'indice è relativo è non assoluto, a ogni ciclo il minimo viene trovato su una porzione dell'array (n-i),*/
                                /*perchè dopo aver trovato il minimo, in un ciclo, e averlo scambiato, l'array viene accorciato in avanti (&array[i],n-i) per non considerare più la porziona già ordinata.*/
        scambiare(&array[i],&array[codice]);
    }
}


void ord_sel_max(char*array[], int n)
{
    int i;

    for(i=n-1;i>0;i--)
        scambiare(&array[i],&array[max_val_ind(&array[0],i+1)]);
}


int min_val_ind(char*a[], int n)
{
    int i;
    int i_max=0;

    for(i=1;i<n;i++){
        if(strcmp(a[i],a[i_max])<0)
            i_max= i;
    }

    return i_max;
}


int max_val_ind(char*a[], int n)
{
    int i;
    int i_max=0;

    for(i=1;i<n;i++){
        if(strcmp(a[i],a[i_max])>0)
            i_max= i;
    }

    return i_max;
}


void scambiare(char**a, char**b)
{
    char*t;
    t= *a;
    *a= *b;
    *b= t;
}


void fusione(char*a[], int n_a, char*b[], int n_b, char*c[])
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

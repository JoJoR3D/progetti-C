#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
TRACCIA 6
Scrivere una funzione che dati in input due array ordinati (rispetto al campo
matricola) di elementi della seguente struttura
struct studente {char *nome; char *cognome; int matricola;};
restituisca in output l’array fusione dei due array. La fusione deve avvenire in base
al campo matricola.
*/


struct studente{
    char *nome;
    char *cognome;
    int matricola;
};

typedef struct studente Array;

void fusione(Array*, int, Array*, int, Array*);
void ordinato(Array*, Array*, int, int*, Array*);



int main()
{
    Array studenti_1[1]= {{"Marco","Pezzella",345}};
    Array studenti_2[1]= {{"Peppe","Improta",423}};

    int i,n=2;
    Array Fusione[n];
    /*Array Ord[n];*/

    for(i=0;i<n-1;i++){
        printf("Array studenti_1\n%s %s %d\n\n",studenti_1[i].nome, studenti_1[i].cognome, studenti_1[i].matricola);
        printf("Array studenti_2\n%s %s %d\n",studenti_2[i].nome, studenti_2[i].cognome, studenti_2[i].matricola);}

    fusione(studenti_1,n-1,studenti_2,n-1,Fusione);
    /*ordinato(studenti_1,studenti_2,n,campo,Ord);*/

    printf("\nFusione dei due array\n");
    for(i=0;i<n;i++)
        printf("%s %s %d\n",Fusione[i].nome, Fusione[i].cognome, Fusione[i].matricola);

    return 0;
}



void fusione(Array*a, int n_a, Array*b, int n_b, Array*c)
{
    int i_a=0, i_b=0, i_c;
    for(i_c=0; i_c<n_a+n_b; i_c++){

        if(i_a<n_a && i_b<n_b){ /*All'interno del ciclo for, con questo if, facciamo un controllo, SE l'indice di a è minore di na e l'indice di b è minore di nb, questo ci garantisce che NESSUNO DEI DUE ARRAY è TERMINATO.*/
            if(a[i_a].matricola < b[i_b].matricola){  /*Confronta il primo elem. dell'array a con l'array b, l'elemento più piccolo viene copiato nell'array c (es. a[0]=1, b[0]=2, copia l'1 nell'array c, poi prosegue confrontando b[0]=2 con a[1]=3, copia 2 nell'array c e prosegue*/
                c[i_c].matricola= a[i_a].matricola;
                c[i_c].nome= a[0].nome;
                c[i_c].cognome= a[0].cognome;
                i_a++;
            }
            else{
                c[i_c].matricola= b[i_b].matricola;
                c[i_c].nome= b[0].nome;
                c[i_c].cognome= b[0].cognome;
                i_b++;
            }
        }
            else if(i_b>=n_b){ /*quando uno dei due Array è TERMINATO. Se è terminato l'array b, nell'array c vado ad inserire i restanti valori presenti nell'array a.*/
                c[i_c].matricola= a[i_a].matricola;
                c[i_c].nome= a[0].nome;
                c[i_c].cognome= a[0].cognome;
                i_a++;
            }
            else{
                c[i_c]= b[i_b]; /*Se è TERMINATO l'array a, nell'array c vado a mettere i restanti valori presenti nell'array b, questi valori dell'array b saranno sicuramnet più piccoli di quelli che abbiamo inserito nell'array c*/
                c[i_c].nome= b[0].nome;
                c[i_c].cognome= b[0].cognome;
                i_b++;
            }
    }
    /*printf("\n\nArray c");
    for(i_c=0;i_c<n_a+n_b;i_c++)
        printf("\n%d", c[i_c]);
    printf("\n");*/
}



void ordinato(Array*s, Array*t, int n, int*c, Array*ord)
{
    int i=0;

    while(i<n){
        if(c[i] == s[0].matricola){
            ord[i].nome= s[0].nome;
            ord[i].cognome= s[0].cognome;
            ord[i].matricola= s[0].matricola;
        }
        else if(c[i] == t[0].matricola){
            ord[i].nome= t[0].nome;
            ord[i].cognome= t[0].cognome;
            ord[i].matricola= t[0].matricola;
        }
        i++;
    }
}

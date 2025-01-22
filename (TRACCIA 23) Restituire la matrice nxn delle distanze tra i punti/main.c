#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*
TRACCIA 23
Scrivere una function C che ha come input un array di struct (struct punto, con campo ascissa e campo ordinata) che individuano punti nel piano, e il suo size n
e che fornisce in output la matrice nxn delle distanze, dove sono memorizzate le distanze di ogni punto da tutti gli altri. La function deve fare uso di un'altra
function, anch'essa da scrivere) che restituisce la distanza tra due qualunque punti del piano.

N.B. Questo esercizio è simile al esercizio con TRACCIA 2.
*/

struct punto{
    float ascissa;
    float ordinata;
};

typedef struct punto Punto;
int n=4;

float distanza(float, float, float, float);
void matrice(Punto*, int, float[][n]);



int main()
{
    Punto array[]= {{5.1,2.9},{7.3,9.7},{6.6,5.3},{6.9,7.4}};
    int i,j;
    float Matrice[n][n];

    matrice(array,n,Matrice);

    printf("Matrice nxn delle distanze\n\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%.1f ",Matrice[i][j]);
        }
        printf("\n");
    }

    return 0;
}



float distanza(float x1, float y1, float x2, float y2)
{
    return sqrt(((x2*x2) - (x1*x1)) + ((y2*y2) - (y1*y1)));
}

/*
Quando eseguo il programma mi viene stamapa la matrice delle distanze, ma alcuni suoi valori che mi vengono mostrati sono del tipo: -1.$
Questo perchè il risultato del calcolo della distanza ha dato come risultato: calcolo impossibile, questo perchè eseguendo i calcoli è uscito un numero negativo sotto la
radice, e la radice di un numero negativo da come risultato: calcolo impossibile (l'ho eseguito sulla calcolatrice).
*/



void matrice(Punto*a, int n, float matrice[][n])
{
    int i,j;
    float calc;

    /*
    Con i=0 calcolo prima la distanza tra la prima coordinata (ascissa: 5.1, ordinata: 2.9) e tutte le altre (facendo incrementare il ciclo interno j);
    Poi con i=1 calcolo la distanza tra la seconda coordinata (ascissa: 7.3, ordinata: 9.7) e tutte le altra (facendo incrementare il ciclo interno j);
    E così via fino a quando i==n.
    */

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            calc= distanza(a[i].ascissa,a[i].ordinata,a[j].ascissa,a[j].ordinata);
            matrice[i][j]= calc;
        }
    }
}

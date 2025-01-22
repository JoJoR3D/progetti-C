#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*
TRACCIA 2
Sviluppare una function C che, dato come parametro di input un array di tipo struct punto {double x; double y;} e il suo size, determina e restituisce
come parametri di output gli indici dei due punti che hanno distanza minima tra loro. I campi x e y contengono l’ascissa e l’ordinata, rispettivamente, di un punto.

N.B. Questo esercizio è simile al esercizio con TRACCIA 23.
*/


struct punto{
    float ascissa;
    float ordinata;
};

typedef struct punto Punto;
int n=4;

float distanza(float, float, float, float);
void dist_min(Punto*, int, int*, int*);



int main()
{
    Punto array[]= {{5.1,2.9},{7.3,9.7},{6.6,5.3},{6.9,7.4}};
    int indice_1,indice_2;

    dist_min(array,n,&indice_1,&indice_2);

    printf("I due punti con distanza minima sono:\n");
    printf("(%.1f,%.1f)\n",array[indice_1].ascissa, array[indice_1].ordinata);
    printf("(%.1f,%.1f)\n",array[indice_2].ascissa, array[indice_2].ordinata);

    return 0;
}




float distanza(float x1, float y1, float x2, float y2)
{
    return sqrt(((x2*x2) - (x1*x1)) + ((y2*y2) - (y1*y1)));
}





void dist_min(Punto*a, int n, int*index1, int*index2)
{
    int i,j;
    float calc, distanza_min=99.9;

    /*
    Con i=0 calcolo prima la distanza tra la prima coordinata (ascissa: 5.1, ordinata: 2.9) e tutte le altre (facendo incrementare il ciclo interno j);
    Poi con i=1 calcolo la distanza tra la seconda coordinata (ascissa: 7.3, ordinata: 9.7) e tutte le altra (facendo incrementare il ciclo interno j);
    E così via fino a quando i==n.
    */

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            calc= distanza(a[i].ascissa,a[i].ordinata,a[j].ascissa,a[j].ordinata);

    /*
    Perchè calc != 0.0 ??
    Alcuni valori che mi ritorna la function distanza sono: 0.0 perchè viene calcolata la distanza tra due stessi punti, ad esempio al primo ciclo:
    con i=0 e j=0 viene calcolata la distanza tra le stesse coordinate, ovvero {5.1,2.9} e {5.1,2.9} e questo mi ritorna come risultato del calcolo della
    distanza: 0.0
    Quindi questo valore lo escludo perchè calcola la distanza tra due stessi punti.
    */

            if(calc < distanza_min && calc != 0.0){
                distanza_min= calc;
                *index1= i;
                *index2= j;
            }
            /*printf("%.1f %.1f\n\n",calc,distanza_min);*/
        }
    }
}

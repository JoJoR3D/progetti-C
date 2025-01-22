#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*
TRACCIA 3
Sviluppare una function C che, dato come parametro di input un array di tipo struct punto {ouble x; double y;} e il suo size, determina e restituisce
come parametro di output la massima distanza tra i punti. I campi x e y contengono l’ascissa e l’ordinata, rispettivamente, di un punto.

N.B. Questo esercizio è simile al esercizio con TRACCIA 2 e TRACCIA 23.
*/


struct punto{
    float ascissa;
    float ordinata;
};

typedef struct punto Punto;
int n=4;

float distanza(float, float, float, float);
void dist_min(Punto*, int, float*);



int main()
{
    Punto array[]= {{5.1,2.9},{7.3,9.7},{6.6,5.3},{6.9,7.4}};
    float Distanza_massima;

    dist_min(array,n,&Distanza_massima);

    printf("La massima distanza tra i punti e': ");
    printf("%.1f\n",Distanza_massima);

    return 0;
}




float distanza(float x1, float y1, float x2, float y2)
{
    return sqrt(((x2*x2) - (x1*x1)) + ((y2*y2) - (y1*y1)));
}




void dist_min(Punto*a, int n, float*distanza_max)
{
    int i,j;
    float calc;
    *distanza_max=0.0;

    /*
    Con i=0 calcolo prima la distanza tra la prima coordinata (ascissa: 5.1, ordinata: 2.9) e tutte le altre (facendo incrementare il ciclo interno j);
    Poi con i=1 calcolo la distanza tra la seconda coordinata (ascissa: 7.3, ordinata: 9.7) e tutte le altra (facendo incrementare il ciclo interno j);
    E così via fino a quando i==n.
    */

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            calc= distanza(a[i].ascissa,a[i].ordinata,a[j].ascissa,a[j].ordinata);

            if(calc > *distanza_max){
                *distanza_max= calc;
            }
            /*printf("%.1f %.1f\n\n",calc,distanza_min);*/
        }
    }
}

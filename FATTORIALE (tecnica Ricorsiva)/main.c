#include <stdio.h>
#include <stdlib.h>

float fatt(float);

int main()
{
    float a;

    do{
        printf("Inserire valore: ");
        scanf("%f",&a);
        if(a >= 0)
            printf("Fattoriale del valore inserito: %.1f\n\n",fatt(a));
        else
            printf("Errore!\n");
    }while(a >= 0);

    return 0;
}


float fatt(float n)
{
    if(n == 1 || n == 0)
        return 1;
    else
        return n * fatt(n-1);
}


/*
    Nota bene: il calcolatore riesce a rappresentare massimo il fattoriale di 12, da 13 in poi escono valori errati.
               Questo perché per il tipo int abbiamo a disposizione 4 byte (32 bit), 2 elevato a 32= 4.294.967.296
               Il fattoriale di 12 è: 479.001.600
               Mentre il fattoriale di 13 è: 6.227.020.800
               Quindi per questo il calcolatore non riesce a calcolare il fattoriale da 12 in poi, perché con il tipo int (4 byte) possiamo
               rappresentare massimo il  valore 4.294.967.296

               Invece se usassimo il tipo float invece del tipo int potremmo rappresentare il fattoriale di 12,13,ecc.. questo perchè per il tipo
               float abbiamo a disposizione il doppio dei bit del tipo int, ovvero 64 bit (8 byte).
*/

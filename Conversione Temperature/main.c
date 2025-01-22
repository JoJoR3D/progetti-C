#include <stdio.h>
#include <stdlib.h>


/*
    Testo:
    L’utente inserisce una temperatura in Celsius e il calcolatore la converte in Fahrenheit ed in Kelvin.
    Se la temperaura inserita è minore dello zero assoluto, il calcolatore segnala un errore.
    Se l’utente inserisce una temperatura uguale allo zero assoluto il programma termina dopo la
    conversione, altrimenti si ricomincia daccapo.
    Ricordiamo che:
    Fahrenheit = (9/5) · Celsius + 32
    Kelvin = Celsius + 273,15
*/


void change_temperature(float*, float*, float*);



int main()
{
    float Celsius, Fahrenheit, Kelvin, Zero_Assoluto_Celsius= -273.15;

    do{

        printf("Inserire la temperatura in Celsius (Zero Assoluto -273.15): ");
        scanf("%f",&Celsius);
        if(Celsius >= Zero_Assoluto_Celsius){
            change_temperature(&Celsius,&Fahrenheit,&Kelvin);
            printf("Fahrenheit: %.2f\nKelvin: %.2f\n\n", Fahrenheit, Kelvin);
            if(Celsius == Zero_Assoluto_Celsius)
                printf("La temperatura inserita e' uguale allo Zero Assoluto Celsius: -273.15\n");
        }
        else{
            printf("ERRORE! La temperature inserita e' inferiore allo Zero Assoluto Celsius: -273.15\n");
            return 1;
        }

    }while(Celsius > Zero_Assoluto_Celsius);

    return 0;
}



void change_temperature(float*C, float*F, float*K)
{
    *F= (((*C) * 9)/5) + 32;
    *K= (*C) + 273.15;
}

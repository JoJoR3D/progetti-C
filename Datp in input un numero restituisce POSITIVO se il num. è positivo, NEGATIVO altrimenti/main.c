#include <stdio.h>
#include <stdlib.h>


int main()
{
    short num;                      /*Il tipo short è di 2 byte = 16 bit*/

    printf("Inserire numero: ");
    scanf("%d",&num);

    num= num>>15;                   /*Il primo bit indica il segno del numero: 0 se positivo, 1 se il numero è negativo.
                                      Essendo il tipo short di 16 bit, shiftando verso destea di 15 posizioni alla fine avrò una stringa di bit con tutti zeri (se il numero shiftato è positivo),
                                      o una stringa di bit con tutti zeri e come primo bit 1 (se il numero shiftato è negativo)*/

    if(num == 0)
        printf("\nPOSITIVO");
    else
        printf("\nNEGATIVO");

    printf("\n\n%d",num);           /*Se il numero shiftato era Positivo questo printf stamperà il valore 0, se era negativo stamperà il valore 1*/

    return 0;
}


/*ESEMPIO:

  num= 4, in bit del tipo short: 0000000000000100

  num>>15= 0000000000000000

  num == 0? SI! Allora è POSITIVO.


  Altro ESEMPIO:

  num= -4, in bit del tipo short: 1000000000000100

  num>>15= 000000000000001

  num == 0? NO! è uguale a 1, Allora è NEGATIVO.
*/

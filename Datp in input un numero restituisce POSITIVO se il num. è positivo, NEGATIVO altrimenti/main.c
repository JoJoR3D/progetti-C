#include <stdio.h>
#include <stdlib.h>


int main()
{
    short num;                      /*Il tipo short � di 2 byte = 16 bit*/

    printf("Inserire numero: ");
    scanf("%d",&num);

    num= num>>15;                   /*Il primo bit indica il segno del numero: 0 se positivo, 1 se il numero � negativo.
                                      Essendo il tipo short di 16 bit, shiftando verso destea di 15 posizioni alla fine avr� una stringa di bit con tutti zeri (se il numero shiftato � positivo),
                                      o una stringa di bit con tutti zeri e come primo bit 1 (se il numero shiftato � negativo)*/

    if(num == 0)
        printf("\nPOSITIVO");
    else
        printf("\nNEGATIVO");

    printf("\n\n%d",num);           /*Se il numero shiftato era Positivo questo printf stamper� il valore 0, se era negativo stamper� il valore 1*/

    return 0;
}


/*ESEMPIO:

  num= 4, in bit del tipo short: 0000000000000100

  num>>15= 0000000000000000

  num == 0? SI! Allora � POSITIVO.


  Altro ESEMPIO:

  num= -4, in bit del tipo short: 1000000000000100

  num>>15= 000000000000001

  num == 0? NO! � uguale a 1, Allora � NEGATIVO.
*/

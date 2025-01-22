#include <stdio.h>
#include <stdlib.h>


int somma(int);


int main()
{
    int s;

    scanf("%d",&s);

    printf("La somma dei primi %d numeri e': %d",s,somma(s));
}



int somma(int n)
{
    if(n == 1)
        return 1;

    else
        return n + somma(n-1);
}


/*
ESEMPIO somma dei primi 6 numeri naturali:

6 + somma(5)= 6 + 15= 21

5 + somma(4)= 5 + 10= 15

4 + somma(3)= 4 + 6= 10

3 + somma(2)= 3 + 3= 6

2 + somma(1)= 2 + 1= 3
*/


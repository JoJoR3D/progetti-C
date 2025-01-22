#include <stdio.h>
#include <stdlib.h>


int fat(int);


int main()
{
    int n;

    scanf("%d",&n);

    printf("Il fattoriale di %d e': %d",n,fat(n));

    return 0;
}


int fat(int n)
{
	if(n == 1)
		return 1;

	else
		return n*fat(n-1);
}



/*
ESEMPIO fattoriale di 6:

6*fat(5)= 6*120= 720

5*fat(4)= 5*24= 120

4*fat(3)= 4*6= 24

3*fat(2)= 3*2= 6

2*fat(1)= 2*1= 2
*/




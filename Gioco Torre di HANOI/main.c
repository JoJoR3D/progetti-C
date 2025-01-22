#include <stdio.h>
#include <stdlib.h>


void hanoi(int, int, int, int);


int main()
{
    /*voglio spostare 3 dischi dal paletto 1 al paletto 3, e uso il paletto 2 come temporaneo*/
    hanoi(6,1,3,2);

    return 0;
}



void hanoi(int n, int from, int to, int temp)
{
    printf("\n\n1n=%d\n\n",n);

    if(n == 1){
        printf("C %d --> %d, n=%d from=%d, to=%d, temp=%d\n", from,to,n,from,to,temp);
        return;                                 /*Quando vado nel caso base, poi devo ritornare alla funzione*/
    }

    printf("\n\n2n=%d\n\n",n);
    hanoi(n-1,from,temp,to);            /*Sposto n-1 dischi dal paletto from al paletto temp. Il paleto to qui è una variabile temporanea che non viene usata.*/

    printf("\nCACCA\n");
    printf("\n\n3n=%d\n\n",n);
    hanoi(1,from,to,temp);     /*Sposto 1 disco dal paletto from al paletto to. Il paleto temp qui è una variabile temporanea che non viene usata.*/

    printf("\n\n4n=%d\n\n",n);
    hanoi(n-1,temp,to,from);          /*Sposto n-1 dischi dal paletto temp al paletto to. Il paleto from qui è una variabile temporanea che non viene usata.*/
}




/*
SPIEGAZIONE;

HANOI(2,1,3,2);

voglio spostare 3 dischi dal paletto 1 al paletto 3, e uso il paletto 2 come temporaneo

2 è il numero di dischi,
1 è il paletto uno,
3 è il paletto tre,
2 è il paletto temporaneo.


Entro nella funzione:

n è == 2

1) quindi chiamata alla funzione: hanoi(n-1,from,temp,to); cioè(hanoi(1,1,2,3);) ritorno nella funzione

e ora n==1 quindi stampa: 1 --> 2 (cioè sposto n-1 dischi dal paletto 1(from) al paletto 2(temp). Il paletto 3(to) qui rappresenta la variabile temporanea e non viene utilizzato).


Il return del if mi riporta al punto dove ero arrivato prima della chiamata, cioè sotto: hanoi(n-1,from,temp,to); ( punto 1) )

2) quindi eseguo il printf: 1 --> 3 (cioè sposto 1 discho dal paletto 1(from) al paletto 3(to). Il paletto 2(temp) qui rappresenta la variabile temporanea e non viene utilizzato).


3) proseguo nella funzione è arrivo ad un'altra chiamata alla funzione stessa: hanoi(n-1,temp,to,from); (cioè: hanoi(1,2,3,1)) ritorno nella funzione

e n==1 quindi stampa: 2 --> 3 (cioè sposto n-1 dischi dal paletto 2(temp) al paletto 3(to). Il paletto 1(from) qui rappresenta la variabile temporanea e non viene utilizzato).


Il return del if mi riporta al punto dove ero arrivato prima della chiamata, cioè sotto: hanoi(n-1,temp,to,from); ( punto 3) )

nella funzione non ci sono altri passaggi, quindi termina!



Ricapitolando a schermo avrò:

1 --> 2
1 --> 3
2 --> 3

*/

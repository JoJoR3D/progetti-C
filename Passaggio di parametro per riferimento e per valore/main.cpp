#include <iostream>


/*
Link spiegazione passaggio per valore o per riferimento:
https://yasb.altervista.org/blog/2016_06_01/passaggio-parametro-riferimento-c/?doing_wp_cron=1689327947.1166520118713378906250
*/

int f1(int);
int f(int*);


int main()
{
    /*PASSAGGIO PER VALORE*/
    /*
        Qui la variabile a nel main vale 3 prima della chiamata a funzione e rimane tale anche dopo. Questo nonostante la funzione f1 modifichi il valore di 'a'
        al suo interno. Nella chiamata a funzione presente nel main l’esecutore passa alla funzione e sostituisce al parametro formale 'a' il numero 3
        ( parametro attuale ).
        La funzione aveva precedentemente allocato lo spazio necessario per 'a' (da non confondere con lo spazio che era stato allocato per la variabile 'a' del main.
        Quindi in generale:
        Nel passaggio per valore la funzione chiamata fa una copia locale del parametro e quindi modifica la copia locale lasciando intatta quella del main.
        Lo spazio in memoria allocato per la copia locale viene liberato all’uscita della funzione.
    */

    int a=3;
    int b=f1(a);
    printf("Con il passaggio del argomento per valore, il valore della variabile nel main non viene modificato anche dopo la chiamata alla funzione f1\n\n");
    printf("Valore di a (prima della chiamata della funzione f1): %d\n",a);
    printf("Valore di b (dopo la chiamata della funzione f1): %d\n\n\n\n",b);




    /*PASSAGGIO PER RIFERIMENTO*/
    /*
        Qui la funzione chiamata (f) non fa una copia locale della variabile 'x' ma lavora direttamente con quella presente nel main.
        Rispetto a prima la differenza sta nel fatto che il parametro 'x' è una variabile di tipo: int * e cioè un puntatore a intero.
        A questa varibile viene passato l’indirizzo della variabile 'x' (cioè: &x).
        Quindi la variabile 'x' nel main (che è di tipo intero) risulterà modificata; la funzione infatti modifica l’elemento puntato da 'x' (cioè: *x)
        che nella funzione è un puntatore a intero.
    */

    int x=3;
    int c=f(&x);
    printf("Con il passaggio del argomento per riferimento, il valore della variabile nel main viene modificato con la chiamata alla funzione f1\n\n");
    printf("Valore di x (prima della chiamata della funzione f): %d\n",x);
    printf("Valore di c (dopo la chiamata della funzione f): %d\n",c);

    return 0;
}


/*PASSAGGIO PER VALORE*/
int f1(int a)
{
    a= a+1;

    return a;
}


/*PASSAGGIO PER RIFERIMENTO*/
int f(int*a)
{
    *a= *a+1;

    return *a;
}

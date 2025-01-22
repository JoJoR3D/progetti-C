void swap(int*, int*);              /*Senza inserire il prototipo di questa funz. anche qui, il compilatore mi da dei warning*/




/*VERSIONE PASSAGGIO (elementi array) PER VALORE*/

void ord(int a[], int n)
{
    int i=0, cont= 0;

    while(1){                       /*while(1) indice che il ciclo si ripeter� al infinito a meno che non venga interrotto con il comando break.*/

        if(a[i] > a[i+1]){          /*Al primo ciclo: Se il primo elemento del array � > del secondo elemento questo viene scambiato tramite lo swap.*/
            swap(&a[i],&a[i+1]);
            cont++;}                /*Ogni volta che viene fatto lo swap, viene incrementato il contatore.*/

        i++;                        /*Viene incrementato l'indici per puntare al prossimo elemento del array.*/

        if(i+1>=n && cont != 0){    /*Se i+1 � >= n vuol dire che sono arrivato alla fine dell'array e quindi devo ripristinare gli indici per ricominciare dal inizio*/
            i=0;                    /*per poter eventualmente fare altri scambi per ordinare l'array.*/

            cont= 0;                /*cont != 0 vuol dire che in questo ciclo � stato eseguito almeno uno swap. Poi poich� sto ricominciando dal inizio del array, azzero il cont.*/
            n=n-1;                  /*Dopo il primo ciclo sicuramente al ultima posizione del array ci sar� l'elemento pi� grande, quindi al ciclo successivo sar� inutile
                                      fare il confronto con questo elemento perch� � il pi� grande e il suo posto � l'ultima posizione.
                                      Quindi dopo la prima iterazione il massimo si trover� in ultima posizione, quella sua definitiva; dopo la seconda iterazione il secondo massimo
                                      si trover� in penultima posizione, anch'essa la sua definitiva; dopo la terza iterazione il terzo massimo si trover� in terz'ultima posizione,
                                      anch'essa la sua definitiva e cos� via.
                                      Quindi ad ogni iterazione viene ridotta la dimensione del array, in questo modo si evita di riconfrontare gli elementi gi� ordinati.*/
        }

        else if(i+1>=n && cont == 0)  /*Invece se i+1 � >= n ma il cont � == 0, vuol dire che in questo ciclo non � stato eseguito nessuno swap,*/
            break;                    /*quindi l'array � ORDIANTO e posso quindi interrompere il ciclo while con il comando break.*/
    }
}






void swap(int*a, int*b)         /* '*a': contiene l'indirizzo di un elemento del array; '*b': contiene l'indirizzo di un altro elemento del array;*/
{
    int t;
    t= *b;                      /* ad 't' assegno 'b' */
    *b= *a;                     /* ad '*b' assegno '*a' */
    *a= t;                      /* ad '*a' assegno 't' */
}
                                /*Ad esempio:
                                  il primo elem. del array � a[0]= 11 e supponiamo che la sua locazione di memoria (indirizzo) sia: 65789.
                                  Ora supponendo che ci troviamo al primo ciclo con i=0, perch� nella chiamata alla void swap ho messo: &a[i]? Perch�:
                                  *a � un puntatore (un indirizzo) che contiene l'indirizzo di memoria di a[0], cio�: 65789.
                                  Quindi ad *a sto passando l'indirizzo del elemento del array a[0] cio�: 65789.
                                  Quindi con la void swap sto scambiando le LOCAZIONI DI MEMORIA.

                                  Quindi se:
                                  a[0] ha come locazione di memoria= 65789 (cha contiene il valore 11) e
                                  a[1] ha come locazione di memoria= 66890 (cha contiene il valore 10),

                                  facendo lo swap ora:
                                  a[0] ha come locazione di memoria 66890 (che contiene il valore 10), mentre
                                  a[1] ha come locazione di memoria 65789 (che contiene il valore 11).

                                  Cosa accade nella function SWAP?
                                  *a= 65789;
                                  *b= 66890;

                                  t= 66890;

                                  *b= 65789;
                                  *a= 66890;
                                */

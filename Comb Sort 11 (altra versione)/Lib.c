void swap(int*, int*);              /*Senza inserire il prototipo di questa funz. anche qui, il compilatore mi da dei warning*/




/*VERSIONE PASSAGGIO (elementi array) PER RIFERIMENTO*/

void ord(int*a, int n)
{
    int i=0, cont= 0, gap= n;           /*La variabile gap serve per calcolare il passo (in pratica la distanza tra un elem. a[i] e un altro elem. del array a[i+gap].*/
    float fat_riduzione= 1.25;


    while(1){                           /*while(1) indice che il ciclo si ripeterà al infinito a meno che non venga interrotto con il comando break.*/

        if(gap != 1){                   /*Se il gap è == 1 allora il passo (gap) d'ora in avanti sarà sempre di 1.*/
            gap= gap/fat_riduzione;
        }

        if(gap == 9 || gap == 10)       /*L'intervallo viene impostato ad 11 ogni qualvolta esso debba diventare 9 o 10.*/
            gap= 11;


        i=0;                            /*Usciti dal ciclo while di sotto se i+gap NON è >=n && cont NON è == 0 && gap NON è == 1,
                                          viene calcolato il nuovo gap, poi viene rinizializzato i=0 e cont=0 per poter ripetere il ciclo while di sotto.*/
        cont= 0;


        while(i+gap<n){                         /*Quando i+gap è >= n esco dal while*/
            if(a[i] > a[i+gap]){                /*Al primo ciclo: Se il primo elemento del array è > del secondo elemento questo viene scambiato tramite lo swap.*/
                swap(&a[i],&a[i+gap]);
                cont++;}                        /*Ogni volta che viene fatto lo swap, viene incrementato il contatore.*/

            i++;                                /*Viene incrementato l'indice per puntare al prossimo elemento del array.*/
        }

        if(i+gap>=n && cont == 0 && gap == 1)  /*Se i+gap è >= n ed il cont è == 0 e gap== 1, vuol dire che in questo ciclo non è stato eseguito nessuno swap,*/
            break;                             /*quindi l'array è ORDIANTO e posso quindi interrompere il ciclo while più esterno con il comando break
                                                 (cioè terminare il programma).
                                                 E' importante mettere gap == 1 perchè, può capitare che al termine di un ciclo, con l'array ancora da ordinare,
                                                 non sia stato eseguito nessuno swap (cont==0). Quindi senza gap==1 il programma potrebbe terminare ritornandomi
                                                 un array non ordinato del tutto.
                                                 Quindi con gap==1, quando al termine di un ciclo non ci sarà nessuno swap, e il ciclo while più esterno sarà interrotto
                                                 (quindi terminerà il programma), l'array sarà sicuramente ordinato*/
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
                                  il primo elem. del array è a[0]= 11 e supponiamo che la sua locazione di memoria (indirizzo) sia: 65789.
                                  Ora supponendo che ci troviamo al primo ciclo con i=0, perchè nella chiamata alla void swap ho messo: &a[i]? Perché:
                                  *a è un puntatore (un indirizzo) che contiene l'indirizzo di memoria di a[0], cioè: 65789.
                                  Quindi ad *a sto passando l'indirizzo del elemento del array a[0] cioè: 65789.
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

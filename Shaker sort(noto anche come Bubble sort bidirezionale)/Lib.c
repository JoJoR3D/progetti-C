void swap(int*, int*);




/*PASSAGGIO DEGLI ELEMENTI DEL ARRAY PER RIFERIMENTO. Invece per valore sarebbe: void shaker(int a[], int n)*/
void shaker(int*a, int n)
{
    int i, cont=0, flag=0;

    while(1){                       /*while(1) indice che il ciclo si ripeterà al infinito a meno che non venga interrotto con il comando break.*/

        /*flag= n%2;*/                /*Modulo della divisione per 2. Se il 'n è pari il resto della divisione sarà 0, altrimenti se 'n' è dispari il resto sarà
                                      diverso da 0. Quando il resto è 0 viene eseguito il PRIMO ciclo; quando il rsto della divisione è diverso da 0, viene
                                      eseguito il SECONDO ciclo.*/


        /*PRIMA CORSA*/
        if(flag == 0){

            printf("\nIndici PRIMA CORSA\n");

            for(i=0;i<n-1;i++){                 /*Questo primo ciclo (PRIMA CORSA) verso destra spostera l'elemento più grande nella sua posizione corretta alla fine della lista.*/
            printf("%d %d\n",i,i+1);
                if(a[i] > a[i+1]){              /*Al primo ciclo: Se il primo elemento del array è > del secondo elemento questo viene scambiato tramite lo swap.*/
                    swap(&a[i],&a[i+1]);
                    cont++;}                    /*Ogni volta che viene fatto lo swap, viene incrementato il contatore.*/
            }printf("\n");
            flag= 1;                            /*Impostando il flag= 1 ciò mi permette al successivo ciclo di eseguire la SECONDA CORSA*/

            n=n-1;                              /*Solo in questo ciclo viene ridimensionato l'array per poter evitare, ai successivi cicli, di riconfrontare gli elementi già ordinati.
                                                Questo perchè nel primo ciclo (PRIMA CORSA) sicuramente al ultima posizione del array ci sarà l'elemento più grande, quindi al ciclo successivo sarà inutile
                                                fare il confronto con questo elemento perchè è il più grande e il suo posto è l'ultima posizione.
                                                Quindi dopo la prima iterazione il massimo si troverà in ultima posizione, quella sua definitiva; dopo la seconda iterazione il secondo massimo
                                                si troverà in penultima posizione, anch'essa la sua definitiva; dopo la terza iterazione il terzo massimo si troverà in terz'ultima posizione,
                                                anch'essa la sua definitiva e così via.
                                                Quindi ad ogni iterazione viene ridotta la dimensione del array, in questo modo si evita di riconfrontare gli elementi già ordinati.*/
        }



        /*SECONDA CORSA che inverte l'esecuzione del ciclo for (anche qui se uso un while) permettendo di analizzare l'array da destra verso sinistra,
          invece che da sinistra verso destra come avviene nelle PRIMA CORSA.*/
        else if(flag != 0){

            i=n-1;

            printf("\nIndici SECONDA CORSA\n");

            while(i>0){                         /*Invece questo SECONDO ciclo verso sinistra sposterà l'elemento più piccolo nella sua posizione corretta all'inizio della lista.*/
            printf("%d %d\n",i,i-1);
                if(a[i] < a[i-1]){

                    swap(&a[i],&a[i-1]);
                    cont++;}
                    i--;
            }flag= 0;                           /*Impostando il flag= 0 ciò mi permette al successivo ciclo di eseguire la PRIMA CORSA*/

            printf("\n");                      /*In questo SECONDO ciclo (SECONDA CORSA) invece l'array non viene ridimensionato perchè, il ciclo scorrendo verso sinistra, non colloca
                                                 gli elementi più grandi alla fine del array ma, posizionerà in ordine, gli elementi più piccoli al inizio dell'array.*/
        }






        if(/*(i+1>=n || i<=0) &&*/ cont != 0){      /*Se i+1 è >= n vuol dire che sono arrivato alla fine dell'array e quindi devo ripristinare gli indici per ricominciare dal inizio*/
                                                    /*per poter eventualmente fare altri scambi per ordinare l'array.*/

            cont= 0;                                /*cont != 0 vuol dire che in questo ciclo è stato eseguito almeno uno swap. Poi poichè sto ricominciando dal inizio del array, azzero il cont.*/
            /*if(flag == 0)
                n=n-1;*/
        }

        else if(/*(i+1>=n || i<=0) &&*/ cont == 0)  /*Invece se i+1 è >= n ma il cont è == 0, vuol dire che in questo ciclo non è stato eseguito nessuno swap,*/
            break;                                  /*quindi l'array è ORDIANTO e posso quindi interrompere il ciclo while con il comando break.*/


    }
}








void swap(int*a, int*b)         /* '*a': contiene l'indirizzo di un elemento del array; '*b': contiene l'indirizzo di un altro elemento del array;*/
{
    int t;
    t= *b;                      /* ad 't' assegno 'b' */
    *b= *a;                     /* ad '*b' assegno '*a' */
    *a= t;                      /* ad '*a' assegno 't' */
}

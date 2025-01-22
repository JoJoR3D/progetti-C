#include <stdio.h>
#include <stdlib.h>


/*Calcolo il mediano, in modo da dividere l'array in una parte SINISTRA e una parte DESTRA. Eseguo la fusione degli elementi della parte sinistra uno ad uno, poi al
  ciclo successivo a due a due e così via fin quando j+1 (secondo elemento del confronto per la fusione) non è >= di mediano.
  Eseguo lo stesso procedimento per la parte destra fin quando j+coppia non è >= di n.*/


void merge(int*, int, int*);
void fusione6(int*, int, int*, int, int*, int, int, int);




int main()
{
    int a[]={38,27,43,3,9,82,10,44,2,21,78,33,67,81,11,77,7,8,19,40}/*{7,3,10,2,6,1,9,4,8}*/;
    int n= 20/*9*/, i;
    int c[n];                       /*Conterrà i valori ordinati dell'array 'a'.*/

    for(i=0;i<n;i++)
        c[i]=0;                      /*Pongo il valore 0 ad ogni posizione dell'array c*/

    printf("Locazioni di memoria array a\n");
    for(i=0;i<n;i++)
        printf("%d\n",&a[i]);        /*Stampo le locazioni di memoria dell'array a*/

    printf("\n");

    printf("Locazioni di memoria array c\n");
    for(i=0;i<n;i++)
        printf("%d\n",&c[i]);        /*Stampo le locazioni di memoria dell'array c*/

    printf("\nElementi presenti nell'array 'a' dichiarato nel main\n");
    for(i=0;i<n;i++)
        printf("%d\n",a[i]);

    printf("\n");


    merge(a,n,c);                    /*Chiamata della funzione merge*/


    printf("\nArray C dopo l'operazione di fusione mediante merge sort\n");
    for(i=0;i<n;i++)
        printf("%d\n",c[i]);

    return 0;
}







void merge(int*a, int n, int*c)
{
    int i=0, j=0, dim_c=0, ciclo=0;

    int inizio= 0;
    int fine= n-1;
    int mediano= (inizio+fine)/2;                           /*Calcolo il mediano che corrisponde all'indice dell'array 'a'*/

    printf("\nVALORE MEDIANO: %d\n", mediano);

    int coppia= 1;                                          /*Coppia indica quanti elementi vengono confrontati. Ad ogni ciclo viene incrementato di 1.
                                                              Esempio: PARTE SINISTRA, al primo ciclo vengono confrontati gli elementi uno ad uno fino a mediano-1,
                                                              al ciclo successivo a due a duee così via fin quando l'elemento j+coppia non è >= di 'mediano'.*/
    int dim_i= 0 /*1*/;
    int dim_j= 0 /*2*/;




    /*Parte SINISTRA del array (va dal primo elemento dell'array 'a' fino a mediano-1*/

    while(j+coppia < mediano /*|| i+coppia < mediano*/){          /*Quando j+coppia è >= di mediano vuol dire che non è possibile prendere più coppie da confrontare.*/

        printf("\n\n%d Ciclo parte SINISTRA\n\n", ciclo);

        while(j+1 < mediano && j+coppia < mediano){

            if(ciclo == 0 && j+coppia < mediano)

                fusione6(&a[0],i+1,&a[0],j+2,c,i,j+1,dim_c); /*Es. con n=8, al I°ciclo il primo &a[0] è 7, mentre il secondo &a[0] è 3.*/
                                                             /*Al secondo ciclo il primo &a[0] indica la porzione che include 3,7.
                                                               Il secondo &a[0] indica la porzione che include 2,11.
                                                               Poi non li prende a tre a tre perchè l'elemento j+coppia (seconda porzione) è == mediano.*/

            else if(ciclo == 0 && j+coppia >= mediano)       /*Se il secondo elemento del confronto (j+coppia) è >= mediano allora la dimensione della seconda porzione da confrontare per la fusione arriva fino a mediano.*/

                fusione6(&a[0],i+1,&a[0],mediano,c,i,j+1,dim_c);

            else if(ciclo != 0 && j+coppia+1 >= mediano)     /*il +1 vicino a j+coppia perchè arrivato all'ultimo raggruppamento deve eseguire questo if perchè il secondo gruppo di confronto deve avere dimensione mediano. Senza il +1 non eseguirebbe questo if ma quello sotto.*/
                                                             /*in oltre devo prima scrivere prima questo if e poi quello sotto perchè se fosse il contrario, al ultimo raggruppamento da svolgere farebbe l'altro if e no questo.*/
                fusione6(&a[0],dim_i,&a[0],mediano,c,i,j+coppia /*j+2*/,dim_c); /*j+coppia+1 se è >= di mediano significa che non c'è il secondo gruppo perchè non ci sono elementi da raggruppare*/

            else if(ciclo != 0 && j+coppia < mediano)

                fusione6(&a[0],dim_i,&a[0],dim_j,c,i,j+coppia /*j+2*/,dim_c);


            /*La condizione j+1 < mediano nel ciclo while interno serve a evitare di fare, ad esempio: prendendo l'array: 6,1,8,5,3
              al primo ciclo chiamo la void fusione ed eseguo la fusione tra 6 (elemento i) e 1 (elemento j) e nel array c verrà copiato in ordine: 1, 6;
              poi chiamo la void fusione ed eseguo la fusione tra 8 (elemento i) e 5 (elemento j) e nel array c verrà copiato in ordine: 5, 8;
              poi devo eseguire la fusione tra 3 (elemento i) e l'elemento j che però non c'è quindi eseguo un controllo: j+1 è < di mediano? NO perchè è >= di mediano,
              quindi questa chiamata alla void fusione non viene eseguita (il valore 3 quindi non viene inserito nel array c perchè non viene eseguita la chiamata alla
              funzione fusione).
              Quindi poi nel array a: 6,1,8,5,3 vengono copiati gli elementi ordinati dell'array c: 1,6,5,8.
              L'array a ora ha i seguenti elementi così ordinati: 1,6,5,8,3 (l'elemento 3 rimane alla sua posizione di origine).


              Invece la seconda condizione del while interno: j+coppia < mediano, serve ad evitare che all'interno di questo while durante i cicli si verifichi che ad esempio:
              ciclo= 3, quindi ciclo è >=1? SI, allora: i=j+coppia+coppia; j=i; (vedi sotto).
              Supponiamo che dopo questo passaggio j sia= 6. Verifico la condizione del while interno: j+1 < mediano? 6+1 < 9? SI, allora rimango nel ciclo while.
              Però quando poi vado ad eseguire, ad esempio: l'else if(ciclo != 0 && j+coppia < mediano); chiamando la function fusione al valore j viene sommato coppia
              (j+coppia indica la posizione del array dalla quale considerare l'inizio della seconda coppia).
              Quindi j+coppia= 6+4= 10 (il valore di coppia al ciclo 3 è 4). Alla posizione 10 del array ci sarà un elemento che non fa parte della porzione del array di
              sinistra, poichè l'array di sinistra ha dimensione 10 (elementi da 0 a 9), quindi il confronto viene fatto con un elemento che non fa parte dell'array.
              Mettendo come seconda condizione del while: j+coppia < mediano, questo non si verificherà.
            */



            /*if(ciclo == 0 || ciclo == 1){
                i=i+2, j=j+2;
                dim_c= dim_c+2;
            }*/
            if(ciclo == 0){
                i=i+2, j=j+2;
                dim_c= dim_c+2;
            }
            else if(ciclo >= 1){
                i=j+coppia+coppia; j=i;
                dim_c= i /*dim_c+coppia*/;            /*Indica ad ogni ciclo la posizione dell'array 'c' dalla quale poter inserire i valori ordinati*/
            }


            printf("\n\ndim_c= %d, i= %d, j= %d\n\n", dim_c,i,j);

            if(i >= dim_i || j >= dim_j){
                dim_i= i+coppia;
                dim_j= i+coppia+coppia;
                printf("\n\ndim_i= %d, dim_j= %d\n\n",dim_i,dim_j);
            }

            if(dim_j > mediano)       /*Se dal if di sopra dovesse uscire una dimensione (dim_j) del secondo gruppo (j) maggiore di 'n', a dim_j sarà assegnato proprio 'n'. */
                dim_j= mediano;       /*Se dim_j avesse una dimensione maggiore potrebbe considerare valori che non fanno parte del nostro array dato in input.*/

            else if(dim_i > mediano)  /*Stesso discorso per la dimensione (dim_i) del primo gruppo (i).*/
                dim_i= mediano;

        }

            ciclo++;

            coppia= coppia+1;

            /*dim_i= dim_i+1;
            dim_j= dim_j+2;*/

            dim_i= 0+coppia;
            dim_j= 0+coppia+coppia;


            if(dim_j > mediano)       /*Se dal if di sopra dovesse uscire una dimensione (dim_j) del secondo gruppo (j) maggiore di 'n', a dim_j sarà assegnato proprio 'n'. */
                dim_j= mediano;       /*Se dim_j avesse una dimensione maggiore potrebbe considerare valori che non fanno parte del nostro array dato in input.*/

            else if(dim_i > mediano)  /*Stesso discorso per la dimensione (dim_i) del primo gruppo (i).*/
                dim_i= mediano;


            /*Assegno all'array 'a' gli elementi ordinati mediante fusione dell'array 'c'. Questo perchè ad ogni cilo lavoro sull'array 'a'.
              Se non lo facessi ad ogni ciclo, lavorando sul array 'a', lavorerei sempre sugli stessi elementi alle stesse posizioni.*/
            for(i=0;i<mediano;i++){
                if(c[i] != 0)
                    a[i]= c[i];
                printf("FF %d\n",a[i]);}


            if(ciclo == 0 || ciclo == 1){
                j= 0, /*j+coppia*/ i= 0, dim_c= 0;
            }
            else{
                j= 0, i= 0, dim_c= 0;
            }

            /*if(ciclo == 8){                           Serve a verificare che senza la condizione j+coppia < n nel ciclo while interno, viene considerato un elemento
                for(z=0;z<n;z++){                       al di fuori del array che altera il contenuto del array stesso.
                    printf("\n\nARRAY %d\n",a[z]);
                }
            }*/
    }








    /*Parte di DESTRA dell'array (va da mediano fino a n-1)*/

    i= mediano;
    j= mediano;
    dim_c= mediano;

    ciclo=0;
    coppia= 1;
    dim_i= mediano /*mediano+1*/  /*3*/;
    dim_j= mediano /*mediano+2*/  /*4*/;


    while(j+coppia < n){        /*Quando j+coppia è >= di n vuol dire che non è possibile prendere più coppie da confrontare.*/

        printf("\n\n%d Ciclo parte DESTRA\n\n", ciclo);

        while(j+1 < n && j+coppia < n){

            if(ciclo == 0 && j+coppia < n)

                fusione6(&a[0],i+1,&a[0],j+2,c,i,j+1,dim_c);

            else if(ciclo == 0 && j+coppia >= n)

                fusione6(&a[0],i+1,&a[0],n,c,i,j+1,dim_c);

            else if(ciclo != 0 && j+coppia+1 >= n)  /*il +1 vicino a j+coppia perchè arrivato all'ultimo raggruppamento deve eseguire questo if perchè il secondo gruppo di confronto deve avere dimensione mediano. Senza il +1 non eseguirebbe questo if ma quello sotto.*/
                                                    /*in oltre devo prima scrivere prima questo if e poi quello sotto perchè se fosse il contrario, al ultimo raggruppamento da svolgere farebbe l'altro if e no questo.*/
                fusione6(&a[0],dim_i,&a[0],n,c,i,j+coppia /*j+2*/,dim_c); /*j+coppia+1 se è >= di mediano significa che non c'è il secondo gruppo perchè non ci sono elementi da raggruppare*/

            else if(ciclo != 0 && j+coppia < n)

                fusione6(&a[0],dim_i,&a[0],dim_j,c,i,j+coppia/*j+2*/,dim_c);


            /*La condizione j+1 < n nel ciclo while interno serve a evitare di fare, ad esempio: prendendo l'array: 6,1,8,5,3
              al primo ciclo chiamo la void fusione ed eseguo la fusione tra 6 (elemento i) e 1 (elemento j) e nel array c verrà copiato in ordine: 1, 6;
              poi chiamo la void fusione ed eseguo la fusione tra 8 (elemento i) e 5 (elemento j) e nel array c verrà copiato in ordine: 5, 8;
              poi devo eseguire la fusione tra 3 (elemento i) e l'elemento j che però non c'è quindi eseguo un controllo: j+1 è < di 'n'? NO perchè è >= di n,
              quindi questa chiamata alla void fusione non viene eseguita (il valore 3 quindi non viene inserito nel array c perchè non viene eseguita la chiamata alla
              funzione fusione.
              Quindi poi nel array a: 6,1,8,5,3 vengono copiati gli elementi ordinati dell'array c: 1,6,5,8.
              L'array a ora ha i seguenti elementi così ordinati: 1,6,5,8,3 (l'elemento 3 rimane alla sua posizione di origine).


              Invece la seconda condizione del while interno: j+coppia < n, serve ad evitare che all'interno di questo while durante i cicli si verifichi che ad esempio:
              ciclo= 3, quindi ciclo è >=1? SI, allora: i=j+coppia+coppia; j=i; (vedi sotto).
              Supponiamo che dopo questo passaggio j sia= 17. Verifico la condizione del while interno: j+1 < n? 17+1 < 20? SI, allora rimango nel ciclo while.
              Però quando poi vado ad eseguire, ad esempio: l'else if(ciclo != 0 && j+coppia < n); chiamando la function fusione al valore j viene sommato coppia
              (j+coppia indica la posizione del array dalla quale considerare l'inizio della seconda coppia).
              Quindi j+coppia= 17+4= 21 (il valore di coppia al ciclo 3 è 4). Alla posizione 21 del array ci sarà un elemento che non fa parte del array, poichè l'array
              ha dimensione 20 (elementi da 9 a 19. La porzione di destra parte dalla posizione 9 dell'array a fino alla posizione 19), quindi il confronto viene
              fatto con un elemento che non fa parte dell'array.
              Mettendo come seconda condizione del while: j+coppia < n, questo non si verificherà.
            */


            /*if(ciclo == 0 || ciclo == 1){
                j=j+2, i=i+2;
                dim_c= dim_c+2;
            }*/
            if(ciclo == 0){
                i=i+2, j=j+2;
                dim_c= dim_c+2;
            }
            else if(ciclo >= 1){
                i=j+coppia+coppia; j=i;
                dim_c= i /*dim_c+coppia*/;        /*Indica ad ogni ciclo la posizione dell'array 'c' dalla quale poter inserire i valori ordinati*/
            }


            printf("\n\ndim_c= %d, i= %d, j= %d\n\n", dim_c,i,j);

            if(i >= dim_i || j >= dim_j){
                dim_i= i+coppia;
                dim_j= i+coppia+coppia;
                printf("\n\ndim_i= %d, dim_j= %d\n\n",dim_i,dim_j);
            }


            if(dim_j > n)       /*Se dal if di sopra dovesse uscire una dimensione (dim_j) del secondo gruppo (j) maggiore di 'n', a dim_j sarà assegnato proprio 'n'. */
                dim_j= n;       /*Se dim_j avesse una dimensione maggiore potrebbe considerare valori che non fanno parte del nostro array dato in input.*/

            else if(dim_i > n)  /*Stesso discorso per la dimensione (dim_i) del primo gruppo (i).*/
                dim_i= n;


        }

            ciclo++;

            coppia= coppia+1;

            /*dim_i= dim_i+1;
            dim_j= dim_j+2;*/

            dim_i= mediano+coppia;
            dim_j= mediano+coppia+coppia;


            if(dim_j > n)       /*Se dal if di sopra dovesse uscire una dimensione (dim_j) del secondo gruppo (j) maggiore di 'n', a dim_j sarà assegnato proprio 'n'. */
                dim_j= n;       /*Se dim_j avesse una dimensione maggiore potrebbe considerare valori che non fanno parte del nostro array dato in input.*/

            else if(dim_i > n)  /*Stesso discorso per la dimensione (dim_i) del primo gruppo (i).*/
                dim_i= n;


            /*Assegno all'array 'a' gli elementi ordinati mediante fusione dell'array 'c'. Questo perchè ad ogni cilo lavoro sull'array 'a'.
              Se non lo facessi ad ogni ciclo, lavorando sul array 'a', lavorerei sempre sugli stessi elementi alle stesse posizioni.*/
            for(i=mediano;i<n;i++){
                if(c[i] != 0)
                    a[i]= c[i];
                printf("FF %d\n",a[i]);
            }


            if(ciclo == 0 || ciclo == 1){
                i=mediano, j=mediano, dim_c= mediano;
            }
            else{
                i=mediano, j=mediano, dim_c= mediano;
            }


            /*if(ciclo == 4){                           Serve a verificare che senza la condizione j+coppia < n nel ciclo while interno, viene considerato un elemento
                for(i=0;i<n;i++){                       al di fuori del array che altera il contenuto del array stesso.
                    printf("\n\nARRAY %d\n",a[i]);
                }
            }*/

    }



    /*Dopo aver ordinato la PARTE DI SINISTRA e poi la PARTE DI DESTRA, eseguo una fusione per ordinare entrambe le parti nell'array c.*/

    printf("\n\nFUSIONE FINALE TRA LA PORZIONE DI SINISTRA E QUELLA DI DESTRA\n");

    if(j+coppia >= n){
        dim_c=0;
        fusione6(&a[0],mediano,&a[0],n,c,0,mediano,dim_c);
        printf("\nFINE funzione merge\n\n");
    }
}








void fusione6(int*a, int n_a, int*b, int n_b, int*c, int first_porzione, int second_porzione, int dim_c)
{
    int i_a= first_porzione, i_b= second_porzione, i_c= dim_c, i;

    printf("\n\ni_a= %d i_b= %d i_c= %d n_a= %d n_b= %d\n", i_a,i_b,i_c,n_a,n_b);

    printf("\nPrimo %d Secondo %d\n\n\n", a[i_a],b[i_b]);


    while(i_a < n_a && i_b < n_b){
        if(a[i_a] < b[i_b]){
            printf("\n\n1 A: %d, i:%d, n:%d, B: %d, i:%d, n:%d\n\n", a[i_a], i_a, n_a, b[i_b], i_b, n_b);
            c[i_c] = a[i_a++];
        }
        else{
            printf("\n\n2 A: %d, i:%d, n:%d, B: %d, i:%d, n:%d\n\n", a[i_a], i_a, n_a, b[i_b], i_b, n_b);
            c[i_c] = b[i_b++];
        }
        i_c++;                  /*Posizione POSTFISSA (i_c++) del ++ prima si usa il valore e poi lo si incrementa. Posizione PREFISSA (++i_c) invece prima si incrementa e poi si usa il valore */
    }
    while(i_a < n_a){
        /*for(i=0;i<9;i++)
            printf("AA %d\n",a[i]);*/
        printf("\n\n3 A: %d, i:%d, n:%d, B: %d, i:%d, n:%d\n\n", a[i_a], i_a, n_a, b[i_b], i_b, n_b);
        c[i_c++] = a[i_a++];
    }

    while(i_b < n_b){
        printf("\n\n4 A: %d, i:%d, n:%d, B: %d, i:%d, n:%d\n\n", a[i_a], i_a, n_a, b[i_b], i_b, n_b);
        c[i_c++] = b[i_b++];
    }

    printf("\n\n");

    for(i=0;i<20;i++)
            printf("CC %d\n",c[i]);     /*Uso questo ciclo for solo per visualizzare l'array 'c' al termine della function fusione, ma posso anche toglierlo.*/

    printf("\n\n");
}



/*ESEMPIO:

  Divido l'array in due parti calcolando l'elemento mediano, in questo modo ho la porzione di sinistra che parte dal primo elemento fino a mediano-1,
  mentre la porzione di destra parte da mediano fino a n-1.

  Parto dalla porzione di SINISTRA:
  Confronto un elemento per volta fino a mediano-1, poi ricomincio confrontando una coppia di elementi fino a mediano-1 e così via fin quando il primo elemento
  della seconda coppia non è >= di mediano.
  Esempio:
  Confronto il primo elemento della porzione di sinistra (i) con il secondo elemento (j), il più piccolo viene copiato nell'array 'c'. Poi contronto il terzo elemento (i) con
  il quarto (j) e così via fin quando il secondo elemento del confronto (j) non è >= di mediano.
  Poi ricomincio il ciclo confrontando la coppia composta dal prim e secondo elemento, con la coppia composta dal terzo e quarto elemento. Poi prosguo confrontando la
  coppia composta dal quinto e sesto elemento, con la coppia composta dal settimo e ottavo elemento e così via fin quando il primo elemento della seconda coppia
  non è >= di mediano.
  Quindi fin quancdo che il primo elemento della seconda coppia non è >= di mediano, ad ogni ciclo il raggruppamento degli elementi presi viene incrementato di uno.
  N.B.: Se è >= di mediano allora la seconda coppia han dimensione == a mediano, ciò signiica che la seconda coppia non c'è perche non ci sono più elementi da
  raggruppare.

  Stesso raggionamento per la porzione di DESTRA: Confronto un elemento per volta fino a n-1, poi ricomincio confrontando una coppia di elementi fino a n-1 e così
  via fin quando il primo elemento della seconda coppia non è >= di n.

  Dopo aver ordinato le due metà dell'array viene eseguito un'altra chiamata della void fusione sulle due porzioni del array per ordinarle.

  Mediante quest algortimo si ha un risparmio di tempo rispetto ad eseguire un algoritmo di ordinamento su tutto l'array perchè il problema (ovvero l'ordinamento) viene
  suddiviso in sotto problemi (si ordina prima una metà, poi l'altra e infine si ordina tutto, ma in quest'ultimo ordinamento su tutto l'array ci vorrà meno tempo perchè
  l'array è già parzialmente ordinato.
*/







/*Prototipi di void fusione*/

/*void fusione6(int*a, int n_a, int*b, int n_b, int*c, int first_porzione, int second_porzione, int dim_c)
{
    int i_a= first_porzione, i_b= second_porzione, i_c= dim_c;

    printf("\n\ni_a= %d i_b= %d i_c= %d n_a= %d n_b= %d\n", i_a,i_b,i_c,n_a,n_b);

    printf("\nPrimo %d Secondo %d\n\n\n", a[i_a],b[i_b]);


    while(i_a < n_a && i_b < n_b){
        if(a[i_a] < b[i_b]){
            c[i_c] = a[i_a++];
        }
        else{
            c[i_c] = b[i_b++];
        }
        i_c++;
    }
    while(i_a < n_a && i_a+1 < n_a){
        if(i_a+1 >= n_a)
            c[i_c++] = a[i_a++];

        else if(i_a < n_a){
        if(a[i_a] < a[i_a+1]){
            c[i_c] = a[i_a];
        }
        else{
            c[i_c] = a[i_a+1];
        }
        i_c++, i_a++;}
    }

    while(i_b < n_b && i_b+1 < n_b){
        if(i_b+1 >= n_b)
            c[i_c++] = b[i_b++];

        else if(i_b < n_b){
        if(b[i_b] < b[i_b+1]){
            c[i_c] = b[i_b];
        }
        else{
            c[i_c] = b[i_b+1];
        }
        i_c++, i_b++;}
    }
}*/









/*
void fusione6(int*a, int n_a, int*b, int n_b, int*c, int first_porzione, int second_porzione, int dim_c, int ciclo)
{
    int i_a= first_porzione, i_b= second_porzione, i_c= dim_c;

    printf("\n\ni_a= %d i_b= %d i_c= %d n_a= %d n_b= %d\n", i_a,i_b,i_c,n_a,n_b);

    printf("\nPrimo %d Secondo %d\n\n\n", a[i_a],b[i_b]);


    while(i_a < n_a && i_b < n_b){
        if(a[i_a] < b[i_b]){
            c[i_c] = a[i_a++];
        }
        else{
            c[i_c] = b[i_b++];
        }
        i_c++;
    }
    while(i_a < n_a){
        if(ciclo == 0)
            c[i_c++] = a[i_a++];

        else if(i_a+1 < n_a && ciclo > 0){
        if(a[i_a] < a[i_a+1])
            c[i_c++] = a[i_a++];
        else{
            swap(&a[i_a],&a[i_a+1]);
            c[i_c++] = a[i_a+1];}
        }
        else
            c[i_c++] = a[i_a++];
    }

    while(i_b < n_b){
        if(ciclo == 0)
            c[i_c++] = b[i_b++];

        else if(i_b+1 < n_b && ciclo > 0){
        if(b[i_b] < b[i_b+1])
            c[i_c++] = b[i_b++];
        else{
            swap(&b[i_b],&b[i_b+1]);
            c[i_c++] = b[i_b+1];}
        }
        else
            c[i_c++] = b[i_b++];
    }
}
*/

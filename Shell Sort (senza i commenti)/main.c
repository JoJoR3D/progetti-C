#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Lib.c"
#include "Prot.h"

/*
LINK SITO 1: https://it.wikipedia.org/wiki/Shell_sort
LINK SITO 2: https://it.wikibooks.org/wiki/Implementazioni_di_algoritmi/Shell_sort

Lo Shell sort è una estensione dell'insertion sort, tenendo presenti due osservazioni:
1) L'Insertion sort è efficiente se l'input è già abbastanza ordinato.
2) L'Insertion sort è inefficiente, generalmente, in quanto muove i valori di una sola posizione per volta.

Lo Shell sort è simile all'insertion sort, ma funziona spostando i valori di più posizioni per volta man mano che risistema i valori, diminuendo gradualmente
la dimensione del passo sino ad arrivare ad uno. Alla fine, lo Shell sort esegue un insertion sort, ma per allora i dati saranno già piuttosto ordinati.

Consideriamo un valore piccolo posizionato inizialmente all'estremità errata di un array dati di lunghezza n. Usando l'insertion sort, ci vorranno circa
n confronti e scambi per spostare questo valore lungo tutto l'array fino all'altra estremità. Con lo Shell sort, si muoveranno i valori usando passi di
grosse dimensioni, cosicché un valore piccolo andrà velocemente nella sua posizione finale con pochi confronti e scambi.

L'idea dietro lo Shell sort può essere illustrata nel seguente modo:
1) sistema la sequenza dei dati in un array bidimensionale (con un numero h di colonne),
2) ordina i valori presenti all'interno di ciascuna colonna dell'array,
3) ripeti dal punto 1 con un diverso numero h (minore del precedente) fino a portare h ad 1.

L'effetto finale è che la sequenza dei dati viene parzialmente ordinata. La procedura viene eseguita ripetutamente, ogni volta con un array più piccolo, cioè,
con un numero di colonne h più basso. Nell'ultima passata, l'array è composto da una singola colonna(h=1) trasformando di fatto quest'ultimo giro in un
insertion sort puro e semplice. Ad ogni passata i dati diventano sempre più ordinati, finché, durante l'ultima lo diventano del tutto.
Comunque, il numero di operazioni di ordinamento necessarie in ciascuna passata è limitato, a causa dell'ordinamento parziale ottenuto nelle passate precedenti.
*/





int main()
{
    int n, m, n_col, i, j;          /*'n' sono le colonne, 'm' sono le righe, 'n_col' mi serve per la dichiarazione a puntatori (Mappa di Memorizzazione).*/
    int riga, colonna, tot, ciclo= 0;

    printf("Inserire dimensione di colonne-righe-n_col\n");

    printf("Colonna: ");
    scanf("%d",&n);
    printf("Riga: ");
    scanf("%d",&m);
    printf("N_col(uguale a colonna): ");
    scanf("%d",&n_col);

    int a[m][n];

    printf("\nInserisci elementi\n\n");

    for(i=0;i<m;i++){
        printf("%d riga\n",i);
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }


    printf("\nStampa array\n\n");

        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }

    srand(time(NULL));



    while(n >= 1){                          /*'n' è il numero di colonne che inserisco manualmente con lo scanf. Finchè 'n' non sarà == 1 il ciclo while si ripeterà.*/

        shell_sort(&a[0][0],n_col,n,m);     /*Chiamata della function che ordina l'array colonna per colonna.*/

        visualizza(&a[0][0],n_col,n,m);     /*Chiamata della function che visualizza l'array ordinato.*/

        if(n==1)
            break;                          /*Quando n==1 interrompo il ciclo while con il comando break.
                                              Se invece uso il comando exit(1), se dopo questo while, nel main ci sono altre istruzioni NON le esegue.
                                              Invece il comando break interrompe solo il ciclo while, poi se ci sono altre istruzioni nel main queste vengono eseguite.*/



        /*Se al Primo ciclo ho inserito, ad esempio, n=4 e m=4, 4*4= 16 valori, quindi nel secondo ciclo devo inserire
          dei valori di 'n' e 'm' che mi permettano di contenere 16 valori, ad esempio: n=2, m=8, 2*8= 16 valori.
          E questo vale anche per i successivi cicli finchè non inserirò che 'n' (num.colonne) è == 1.*/



        /*INSERIMENTO MANUALE, AD OGNI CICLO, DEL NUOVO VALORE DI 'n'(colonna), 'm'(riga) e 'n_col'. */

        /*scanf("%d",&n);                       Inserisco altri valori di n,m e n_col finquando 'n' non sarà uguale a 1.
        scanf("%d",&m);
        scanf("%d",&n_col);*/



        /*Questo di sotto (ciclo do while) invece è un modo per inserire, ad ogni ciclo, AUTOMATICAMENTE LA NUOVA DIMENSIONE di 'm' (riga) e 'n' (colonna).*/


        printf("\nInserire nuova dimensione di colonne-righe-n_col\n");

        riga= 0;                /*Come detto sopra, poichè uso un ciclo do while(sotto), posso anche non inizializzare a 0 le variabili riga e colonna.*/
        colonna= 0;

        int vet[50];            /*Conterrà i valori di 'n'(colonna) ad ogni ciclo, per evitare che vengano generati, in cicli diversi, lo stesso valore per colonna.*/
        tot= n*m;               /*Il valore di riga moltiplicato per il valore di colonna deve essere == a tot per il discorso fatto sopra.*/


        /*Salvo nel array vet il valore di 'n'(colonna), e poi pongo il valore 0 nelle restanti posizione del array vet, però solo al primo ciclo (==0).
          Ai cicli successivi ci pernserà il corpo del do while a memoriazzare i successivi valori generati per 'n'(colonna).*/

        if(ciclo == 0){
            for(j=0;j<50;j++){
                vet[0]=n;
                if(j != 0)
                    vet[j] = 0;
            }
        }


        /*Questo ciclo do while, come spiegato sopra, serve per generare automaticamente, ad ogni ciclo, i nuovi valori per riga(m) e colonna(n).*/

        do
        {
            riga= 2+rand()%100;                     /*Genera valori pseudocasuali da 2 a 99. Ma può generare anche il valore 1: 2+99%100= 101%100= 1*/
            colonna= 1+rand()%100;

            while(riga == 1 || colonna > n){        /*Infatti se viene generato il valore 1, per la riga, viene generato nuovamente un altro valore.*/
                if(riga == 1)
                    riga= 2+rand()%100;             /*Con 1 sola riga l'algoritmo non ordina in maniera corretta i valori del array 'a'. Il valore 1 come riga non mi serve!*/
                else if(colonna > n)                /*L'ALGORITMO, PER FUNZIONARE CORRETTAMENTE, AD OGNI CILO IL VALORE DI COLONNA DEVE DIMINUIRE, quindi mi assicuro*/
                    colonna= 1+rand()%100;}         /*che venga generato nel ciclo in corso un valore più piccolo rispetto ai cicli precedenti.*/

            for(j=0;j<50;j++){
                if(vet[j] == colonna)               /*Se il valore generato per colonna è già presente nel array vet, allora viene generato un altro valore.*/
                    colonna= 1+rand()%100;
                else if(vet[j] == 0 && (riga*colonna) == tot)   /*Salvo il valore di colonna nel array vet nelle posizioni dove c'e 0 se anche riga*colonna è ==tot.*/
                    vet[j]= colonna;                            /*Senza riga*colonna ==tot, ad ogni ciclo do while che si avrà, il valore di colonna sarà salvato nel array,*/
            }                                                   /*invece così sarà salvato solo il valore di colonna corretto e che di conseguenza farà terminare il do while.*/
        }
        while((riga*colonna) != tot/*&& riga == m && colonna == n*/);



        /*Assegno i valori pseudocasuali di riga e colonna generati dal ciclo do while alle variabili 'm'(riga) e 'n'(colonna)
          che saranno passati alle due function presenti nel corpo del ciclo while di sopra.*/

        m=riga;
        n=colonna;
        n_col= colonna;

        printf("%d %d %d\n",colonna, riga, n_col);

        ciclo++;                /*Incremento il valore della variabile ciclo (mi serviva solo al primo ciclo per prre il valore 0 in ogni posizione del array vet,
                                  tranne alla prima posizione del array dove viene memorizzato il valore di 'n'(colonna) del primo ciclo.*/
    }

    return 0;
}





/*
ESEMPIO


PRIMO CICLO:

scanf (Colonne)'n'= 4 numero di colonne;
scanf (Righe)'m'= 4 numero di righe;
scanf 'n_col'= 4 deve essere uguale al numero di colonne;

scanf per inserire i valori:

Prima riga:
23
12
78
12

Seconda riga:
6
45
87
43

Terza riga:
1
12
47
39

Quarta riga:
2
20
38
29


Ora mi stampa i valori inseriti su 4 righe e 4 colonne:

23 12 78 12
6  45 87 43
1  12 47 39
2  20 38 29


Ora entro nel while del main (n=4 è >= 1? SI!), chiamo la funzione shell_sort che ordina i valori di ciascuna colonna, poi chiamo la funtion visualizza che stampa
l'array ordinato in base ai valori di 'n'(colenne) e 'm'(righe):

1  12 38 12
2  12 47 29
6  20 78 39
23 45 87 43


if(n==1)? No allora vado avanti.


Ora il ciclo do while genererà nuovi valori per 'n'(colonne) e 'm'(righe). Il valore di N_col sarà uguale a 'n':
N.B. Poichè prima ho inserito tramite scanf n=4 e m=4, cioè 4*4= 16 valori, ora devono essere generati dei valori di 'n' e 'm' che mi permettano di contenere 16 valori,
     ad esempio: n=2, m=8, 2*8= 16 valori.
     P.S.Il valore generato per 'n'(colonne) non potrà essere uguale al valore dei cicli precedenti (in questo caso, non potrà essere
     uguale a 4) e in oltre dovrà essere un valore minore rispetto a quello dei cicli precedenti (in questo caso al ciclo precedente il valore 'n' è 4, quindi ora il
     nuovo valore dovrà essere un valore minore di 4).

     I nuovi valori generati nel ciclo do while sono:

Colonne 'n'= 2 numero di colonne;
Righe   'm'= 8 numero di righe;
        'n_col'= 2 deve essere uguale al numero di colonne;




SECONDO CICLO:

while(n=2 >= 1)? SI! allora rimango nel ciclo while e chiamo nuovamente la funzione che ordina i valori di ciascuna colonna, , poi chiamo la funtion visualizza che stampa
l'array ordinato in base ai valori di 'n'(colenne) e 'm'(righe):

N.B. (è un processo automatico del compilatore):
Per stampare l'array ordinato nel formato (2*8), il compilatore unisce la prima e la terza colonna del array precedente (formato 4*4) che ora rappresentano la prima colonna
del array 2*8 e la ordina, poi uniscela seconda e la quarta colonna del array precedente (formato 4*4) che ora rappresentano la seconda colonna del array 2*8 e la ordina:

1  12
2  12
6  12
23 20
38 29
47 39
78 43
87 45


if(n==1)? No allora vado avanti.


Ora il ciclo do while genererà nuovi valori per 'n'(colonne) e 'm'(righe). Il valore di N_col sarà uguale a 'n':
N.B. Poichè prima sono stati generati dal ciclo do while i valori n=2 e m=8, cioè 2*8= 16 valori, ora devono essere generati dei valori di 'n' e 'm' che mi
     permettano di contenere 16 valori,
     ad esempio: n=1, m=16, 1*16= 16 valori.
     P.S.Il valore generato per 'n'(colonne) non potrà essere uguale al valore dei cicli precedenti (in questo caso, non potrà essere uguale a 4 o a 2) e in oltre
     dovrà essere un valore minore rispetto a quello dei cicli precedenti (in questo caso al ciclo precedente il valore 'n' è 2 e al ciclo prima ancora era 4,
     quindi ora il nuovo valore dovrà essere un valore minore di 2).

     I nuovi valori generati nel ciclo do while sono:

Colonne 'n'= 1 numero di colonne;
Righe   'm'= 16 numero di righe;
        'n_col'= 1 deve essere uguale al numero di colonne;





TERZO CICLO:

while(n=1 >= 1)? SI! allora rimango nel ciclo while e chiamo nuovamente la funzione che ordina i valori di ciascuna colonna, , poi chiamo la funtion visualizza che stampa
l'array ordinato in base ai valori di 'n'(colenne) e 'm'(righe):

N.B. (è un processo automatico del compilatore):
Per stampare l'array ordinato nel formato (1*16), il compilatore unisce le due colonne del array precedente (formato 2*8) in un unica colonna e la ordina:

1
2
6
12
12
12
20
23
29
38
39
43
45
47
78
87

if(n==1)? Si allora termina il ciclo while e di conseguenza il programma. Quello di sopra è l'array ordinato finale.
*/

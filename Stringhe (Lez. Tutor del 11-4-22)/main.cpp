#include <iostream>
#include <limits>
#include <string.h>  /*Stiamo includendo la libreria string*/
#include <vector>


using namespace std;


int main()
{
    /*
        Utilizzando il tipo string per dichiarare l'array, stiamo creando un'array di stringhe che è chiamato ARRAY FRASTAGLIATO,
        dove ogni stringa ha una propria lunghezza che termina al terminatore;
        Ad esempio:
        char s[50]= {"Peppe","Gianmarco"};
        In questo caso anche se la prima stringa ha lunghezza 5 e la seconda lunghezza 9 il numero di colonne, quindi lo spazio occupato in memroia, sarà di 50byte.
        Quindi nel caso della prima stringa abbiamo uno sperco in memoria di 45byte, mentre per la seconda stringa di 41byte.

        Invece con
        string s[]= {"Peppe","Gianmarco"};
        la prima stringa occuperà in memoria 5byte, mentre la seconda 9byte;
    */
    printf("\n\nRITORNA IL MESE CORRISPONDENTE\n");
    string mesi[]= {"Gennaio","Febbraio","Marzo","Aprile","Maggio","Giugno","Luglio","Agosto","Settembre","Ottobre","Novembre","Dicembre"};
    int num;

    do{
        printf("Inserisci il numero corrispondente al mese che vuoi visualizzare: ");
        scanf("%d",&num);

        if(num >= 1 && num <= 12){
            printf("Il mese corssipondente e': ");
            cout << mesi[num-1] << endl;
        }
        else
            cout << "ERRORE!" << endl;
    }while(num < 1 || num > 12);

    printf("\n\n");






    printf("METODO APPEND per aggiungere una stringa alla fine di un'altra stringa\n");
    string anni{"duemilaventi"};
    string agg_anni(" duemilaventicinque");
    anni.append(agg_anni);

    cout << anni << endl;

    printf("\n\n");







    printf("\nALLOCAZIONE DINAMICA DI UN ARRAY DI STRINGHE");

    /*
        string*mesi= new string[n]
        string*mesi è un puntatatore alla classe string.
        Si utilizza la parola (new) per l'allocazione dinamica in C++.
        L'allocazione dinamica è contigua (i dati vengono memorizzati, in memoria, uno di seguito al altro).
        Con questo comando sto dicendo di allocare n elementi (string[n]) e ciascuno di questi deve essere
        una stringa.
        Quindi NEW andrà a trovare lo spazio in memoria sufficiente per allocare in modo contiguo le n stringhe.

        NEW restituisce un indirizzo nel quale vengono allocati i dati memorizzati in memoria.
        Questo indirizzo lo memorizzo in un puntatore (per questo abbiamo string*mesi), in questo modo potrò accedere ai
        dai memorizzati a quella locazione di memoria.

        N.B.
        Quando voglio inizializzare un'array di stringhe allocato dinamicamente tramite NEW, devo usare solo LE PARENTESI GRAFFE (con le tonde mi da errore).

        N.B.
        In C, invece di new, abbiamo malloc e calloc.
        Possono essere usate anche in C++, ma se in un programma si comincia ad utilizzare malloc, calloc e free (serve per deallocare),
        allora e buona norma non utilizzare anche new e le altre funzioni di allocazione dinamica del C++. Lo stesso vale viceversa.
        Questo perchè malloc,calloc e free lavorano in memoria in maniera diversa rispetto a new, quindi è buona norma non mischiare le funzioni
        di allocazione di namica del C con quelle del C++ nello stesso programma (si potrebbe incorrere in problemi).

        L'equivalente della funzione free() del C, in C++ è delete().

        N.B.
        In questo caso abbiamo allocato delle stringhe, ma possiamo allocare anche altri tipi di dati come gli interi:
        int*a= new int[n]
    */
    printf("\n\nRITORNA IL MESE CORRISPONDENTE\n");
    int n= 12;
    string *Mesi= new string[n] {"Gennaio","Febbraio","Marzo","Aprile","Maggio","Giugno","Luglio","Agosto","Settembre","Ottobre","Novembre","Dicembre"};
    int Num;

    do{
        printf("Inserisci il numero corrispondente al mese che vuoi visualizzare: ");
        scanf("%d",&Num);

        if(Num >= 1 && Num <= 12){
            printf("Il mese corssipondente e': ");
            cout << Mesi[Num-1] << endl;
        }
        else
            cout << "ERRORE!" << endl;
    }while(Num < 1 || Num > 12);

    printf("\n\n");










    /*
        Come visto sopra, usando string per dichiarare un0array di stringhe, ho dovuto specificare quante stringhe
        avrei dovuto allocare (string[n]).
        Utilizzando VECTOR non ho bisogno di specificare questo parametro, sarà vector a capire quanto spazio allocare.
        Vector è un contenitore dove inserire, in questo caso, delle stringhe (ma può contenere anche altri tipi di dati come gli int).
        N.B.
        Bisogna includere la libreria vector.
        N.B.
        Vector è un tipo come string. Non è un comando, come NEW, per l'allocazione dinamica.

        N.B.
        Quando voglio inizializzare un'array di stringhe tramite VECTOR, devo usare solo LE PARENTESI GRAFFE
        (con le tonde mi da errore).

        Dopo vector, tra parentesi angolari <>, bisogna dichiarare il tipo di dato da allocare dinamicamente. Dopo va dichiarato l'oggetto che è
        di tipo vector di stringhe.
    */
    printf("\n\nRITORNA IL MESE CORRISPONDENTE\n");
    vector <string> m {"Gennaio","Febbraio","Marzo","Aprile","Maggio","Giugno","Luglio","Agosto","Settembre","Ottobre","Novembre","Dicembre"};
    int N;

    do{
        printf("Inserisci il numero corrispondente al mese che vuoi visualizzare: ");
        scanf("%d",&N);

        if(N >= 1 && N <= 12){
            printf("Il mese corssipondente e': ");
            cout << m[N-1] << endl;
        }
        else
            cout << "ERRORE!" << endl;
    }while(N < 1 || N > 12);

    printf("\n\n");






    printf("\nSIZEOF di un tipo string\n");
    string p;
    cout << sizeof(p) << endl;  /*Restituisce 32byte perché sto facenso il sizeof di un'oggeto di tipo string che essesndo una classe avrà a suo interno sicuramente altri parametri.*/
    string z;
    cout << sizeof(&z) << endl; /*Restituisce 8byte perchè qui sto chiedendo il sizeof di un'indirizzo di memoria. Nei PC moderni ogni cella di memoria ha una dimensione di 64bit ovvero 8byte.*/

    printf("\n\n");








    /*
        Spiegazione programma:
        La function createArray dichiara un array con dimensione 'N' passato come argomento.
        Tramite un ciclo for, nell'array 'a' vengono inseitit 'N' valori casuali generati tramite una rand() (genera valori da 0 a 9).
        La function poi ritorna un puntatore all'indirizzo base dell'array 'a'.

        Nel main viene inserito da tastiera, mediante scanf(), il valore 'N' passoto alla function createArray.
        Viene poi dichiarato un puntatore alla variabile b, alla quale viene assegnata la chiamata alla function createArray.
        Quindi 'b' dovrebbe contenere il puntatore che punta all'indirizzo base dell'array 'a'.

        Ma questo codice non funziona perchè?
        Nella function createArray viene dichiarato un array 'a' che poi viene inizializzato mediante ciclo for.
        La function poi ritorna un puntatore che punta all'indirizzo base dell'array 'a'.
        Dopo il return però tutte le variabili dichiarate nella function, compreso l'array 'a' (che è dichiarato come variabile locale), vengono liberate.
        Quindi nel main il puntatore alla variabile 'b', punta a una zona di memoria dove non vi è più l'array poichè dopo il return della function,
        tutte le variabile dichiarate nella function vengono liberate (quindi 'b' punta a qualcosa che non esiste più).

        SOLUZIONE:
        Per far funzionare questo programma, bisogna dichiarare l'array 'a' no nella function, ma nella parte del precompilatore (variabile globale),
        oppure nel main per poi passare l'array alla function come parametro.

        Altra possibilità che consente di dichiarare l'array nelle function è quello di usare l'allocazione dinamica per allocare l'array.
        Questo perchè, quando alloco dinamicamente, la memoria allocata persiste finquando non la libero utilizzando, in C, free(), oppure
        quando chiudo il programma.
        Perchè quando genero un programma, il main e le funzioni inserite nel programma vencono allocate sullo stack. Quando chiamo una funzione, dopo il return,
        cioè quando la funzione termina, si ritorna nel main al punto successivo alla chiamata della funzione, e nello stack l'area allocata per la funzione non
        c'è più, quindi tutte le variabili dichiarate nella funzione vengono deallocate.
        Nel nostro esempio la function ritorna un puntatore all'array dichiarato nella function, ma il programma mi ritornerà un errore di "segmentation fault"
        poichè quell'area puntata non esiste più.

        Invece usando l'allocazione dinamica, le veriabili dichiarate vengono allocate non nello stack, ma nell'heap e li rimangono fino al termine del programma o
        finquando quall'area di memoria non viene liberata mediante, ad esempio, l'uso di una free().
        N.B. Quando termino il programma (cioè chiudo il programma), anche lo steck viene liberato.

        Ad esempio posso dichiarare l'array 'a' dinamicamente nella function:
        int*a= new int[N];



        PROGRAMMA:
        int*createArray(unsigned int N)
        {
            int a[N];
            for(int k=0; k<N; k++)
                a[k]= rand()%10;
            return a;
        }

        int main()
        {
            unsigned int N;
            printf("Enter N>0: ");
            scanf("%u", &N);
            int*b= createArray(N);
            for(int k=0; k<N; k++)
                printf("%d\n",b[k]);

            return 0;
        }
    */

    return 0;
}

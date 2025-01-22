#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string*vect(int);
void lello(char*);
void lello1(vector <string>);



int main()
{
    int i,n=3;
    string*s= new string[n];

    for(i=0;i<n;i++)
        /*cin >> s[i];*/    /*Smette di legerre dopo aver inserito uno spazio*/
        getline(cin,s[i]);  /*Smette di legerre dopo aver che si è andati a capo*/

    printf("\nStringhe inserite:\n");
    for(i=0;i<n;i++)
        cout << s[i] << endl;








    printf("\n\nSTRINGSTREAM\n");
    /*
        L'intestazione standard <sstream> definisce un tipo chiamato stringstreamche consente di trattare una stringa come un flusso, consentendo quindi
        operazioni di estrazione o inserimento da/a stringhe nello stesso modo in cui vengono eseguite su cine cout. Questa funzione è molto utile per
        convertire le stringhe in valori numerici e viceversa. Ad esempio, per estrarre un numero intero da una stringa possiamo scrivere:

        string mystr ("1204");
        int myint;
        stringstream(mystr) >> myint;

        N.B. bisogna includere la libreria <sstream>

        Link sito: https://cplusplus.com/doc/tutorial/basic_io/
    */

    string mystring("2000");
    int myint;
    stringstream(mystring) >> myint;
    cout << myint << endl;

    printf("\n\n");

    string m;
    int prezzo,quant;

    printf("Prezzo unita' merce: ");
    getline(cin,m);
    stringstream(m) >> prezzo;

    printf("Quantita' merce: ");
    getline(cin,m);
    stringstream(m) >> quant;

    printf("Prezzo finale della marce acquistata: ");
    cout << prezzo*quant << endl;
















    printf("\n\nVettore:\n");

    vector <string> t {"Peppe"};    /*'t' è un puntatore che contiene l'indirizzo base del vettore di stringhe.*/

    cout << t[0] << endl;   /*passo l'indirizzo del primo elemento del vettore di stringhe. Anche se il vettore contiene una sola stringa devo comunque passare
                              l'indirizzo del primo elemnto (t[0]).
                              Come detto 't' è un puntatore che contiene l'indirizzo base (primo elemento del vettore) del vettore di stringhe.*/




    printf("\n\nDichiarazione dinamica di un array di stringhe in una function che mi ritorna un puntatore all'array di stringhe:\n");

    int N=2;
    string*v= vect(N);          /*'v' punta all'indirizzo del puntatore che punta all'indirizzo base dell'array di stringhe 'stringa'.
                                  Quindi 'v' punta all'indirizzo della prima e della seconda stringa dell'array di stringhe dichiarato nella function vect.
                                  Senza il puntatore a 'v', il ciclo for di sotto stamperebbe solo i primi due caratteri della prima stringa dell'array di
                                  stringhe dichiarato nella function vect (cioè: 'M' e 'i'). Perchè è come se gli passassi solo l'indirizzo della prima stringa.
                                */
    for(i=0;i<N;i++){
        cout << v[i] << endl;
    }





    printf("\n\nPasso ad una void una stringa da stampare:\n");

    char serp[]= "Romeo";

    lello(serp);






    printf("\n\nPasso ad una void una vector di stringhe da stampare:\n");

    vector <string> tetto {"Rotto"};

    lello1(tetto);
    /*cout << tetto.at(0) << endl;*/    /*tramite metodo .at() per accedere ai campi di una stringa*/

    return 0;
}




string*vect(int n)      /*Ritorna l'indirizzo del puntatore che punta all'indirizzo base dell'array di stringhe 'stringa'.*/
{
    string*stringa= new string[n] {"Milan","Lumezzane"}; /*alloco dinamicamente l'array di stringhe 'stringa'.*/
    return stringa;     /*Ritorna un puntatore che punta all'indirizzo base dell'array di stringhe 'stringa'.*/
}


void lello(char*s)
{
    cout << s << endl;  /*Essendo 's' un puntatore alla stringa che passo come parametro, a cout passo l'indirizzo della stringa ('s') per poter stampare la stringa.*/
}


void lello1(vector <string> s)
{
    cout << s[0] << endl;   /*passo l'indirizzo del primo elemento del vettore di stringhe. Anche se il vettore contiene una sola stringa devo comunque passare
                              l'indirizzo del primo elemnto (s[0]).
                              Come detto 's' è un puntatore che contiene l'indirizzo base (primo elemento del vettore) del vettore di stringhe.*/
}


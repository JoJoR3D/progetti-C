#include <iostream>

using namespace std;

/*
N.B.
I TEMPLATE possono eesere usati oltre che per definire i metodi,
ma anche per le classi.
I metodi, possono essere dichiarati all'interno della classe,
fuori dalla classe sempre nel precompilatore,
o in un altro file (header.h).
Però se si utilizzano i template per definire le classi e i
metodi di questa classe, i metodi devono trovarsi nello stesso file.
Non possono essere definiti in un file header.h
*/


template <typename T> class calcola{
public:
    T add(T x, T y);
    T molt(T x, T y);
};

/*Definisco i metodi della classe fuori dalla classe in questo modo.
  questa istruzione: T calcola<T>::nome del metodo con definizione
  dei parametri serve per indicare che il metodo appartiene alla classe
   calcola.
*/

template <typename T> T calcola<T>::add(T x, T y){
    return x+y;
}

template <typename T> T calcola<T>::molt(T x, T y){
    return x*y;
}


/*
    Nell’implementazione delle classi si usa l’operatore di
    risoluzione di visibilità (scope resolution) costituito
    dai due punti doppi "::" per individuare le operazioni
    proprie della classe e distinguere eventuali
    funzioni con lo stesso nome di altre classi.
*/



int main()
{
    int x=3, y=7;

    calcola<int> *punt= new calcola<int>;

    /*Usa new per allocare per poter utilizzare il puntatore.
      Se non lo faccio il compilatore mi da un warning ma compila
      lo stesso.
      Questo è il modo per allocare dinamicamente i template.
    */

    cout << "Somma: " << punt->add(x,y) << endl;
    cout << "Moltiplicazione: " << punt->molt(x,y) << endl;

    return 0;
}

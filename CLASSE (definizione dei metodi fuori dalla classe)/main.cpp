#include <iostream>

using namespace std;

class calcola{
public:
    int add(int x, int y);
    int molt(int x, int y);
};


/*Definisco i metodi della classe fuori dalla classe in questo modo.
  questa istruzione: int calcola::nome del metodo con definizione
  dei parametri serve per indicare che il metodo appartiene alla
  classe calcola.
*/


int calcola::add(int x, int y)
{
    return x+y;
}


int calcola::molt(int x, int y)
{
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
    int x=4, y=8;

    calcola *punt= new calcola;

    /*Usa new per allocare per poter utilizzare il puntatore.
      Se non lo faccio il compilatore mi da un warning ma compila
      lo stesso.
      Questo è il modo per allocare dinamicamente i template.
    */

    cout << "Somma: " << punt->add(x,y) << endl;
    cout << "Moltiplicazione: " << punt->molt(x,y) << endl;

    return 0;
}


/*
Abbiamo appena visto che per "implementare" un metodo al di fuori
della sua classe bisogna usare:

nome_classe::nome_metodo

Il simbolo :: è chiamato SCOPE RESOLUTION OPERATOR. Esso informa il
compilatore  che tale metodo appartiene alla classe nome_classe,
ovvero che esso è nello scope (ambito di visibilità) di nome_classe.

Il namespace è una regione dichiarativa il cui obiettivo è
"localizzare" i nomi degli identificatori evitando collissioni di
nome. Gli elementi dichiarati in un namespace sono separati dagli
elementi dichiarati in un altro namespace.
*/

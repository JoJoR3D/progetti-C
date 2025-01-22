#include <iostream>

using namespace std;

/*
In C++ le classi astratte si hanno mediante l'implementazione di un metodo VIRTUAL PURO.
Quando la classe contiene almeno un metodo virtual puro, allora questa diventa classe astratta.
Un metodo virtual puro è un metodo senza IMPLEMENTAZIONE.

Come dichiarere un metodo virtual puro?
virtual - tipo di ritorno - nome del metodo - parametri - =0;
Esempio:
virtual void show() =0;

=0 indica al compilatore che questo medoto non ha implementazione.
*/


class Strumento{
public:
    virtual void show()=0;  /*VIRTUAL PURO*/
};


class Batteria: public Strumento{       /*La classe derivata Batteria eredita dalla classe Base Strumento*/
public:
    void show(){
        cout << "Suono la batteria" << endl;
    };
};


class Chitarra: public Batteria{        /*La classe derivata Chitarra eredita dalla classe derivata Batteria*/
};




int main()
{
    /*Strumento a;      Il compilatore ci restituisce errore perchè Strumento è una classe ASTRATTA.
    a.show();*/

    Batteria b;
    b.show();

    Chitarra c;
    c.show();   /*La classe Chitarra eredita il metodo show() dalla classe Batteria, ma non lo ridefinisce (non faccio l'override), quindi stamperà sempre: "Suono la batteria"*/

    /*
    COME ABBIAMO DETTO la classe astratta non può essere instanziata (non posso creare ad esempio nel main una variabile di tipo classe astratta), però
    posso utilizzare un PUNTATORE ad una classe astratta per poter applicare il polimorfismo.
    Cioè posso aver un puntatore di tipo classe base che punta a una classe derivata e attraverso questo puntatore posso richiamare i metodi della classe
    derivata attraverso il polimorfismo (virtual,override, ecc...).
    E' possibile richiamare i metodi della classe derivata, poichè nella classe base i metodi sono stati definiti 'Virtual'
    (VIRTUAL FUNCTION Lez. Tutor Prog II del 9-5-22).
    */

    Batteria*punt;
    punt=&c;
    punt->show();

    /*
    Ricordiamo che è possibile dichiarere il metodo o i metodi presenti nella classe base 'virtual'.
    In questo modo anche se abbiamo un puntatore della classe base (tipo) che punta a una classe derivata, e sia la classe base che derivata hanno un metodo
    con stesso nome e num. di parametri, andando a chiamare il metodo della classe derivata con il puntatore verrà chiamato proprio questo metodo e no
    quello della classe base, poichè il puntatore sarà in grado di vedere anche i metodi della classe derivata e non solo quelli della classe base
    (cosa che con l'UPCASTING non è possibile ed è per questo che per ovviare a ciò dovevo eseguire il cast alla classe derivata, ma ora utilizzando 'virtual'
    questo non è più necessario).
    */

    return 0;
}

#include <iostream>

using namespace std;


class Strumenti{

public:
    virtual void suona()=0;
};


class Violino : public Strumenti{

public:
    void suona() override{
        cout << "Il Violino" << endl;
    }
};


class Batteria : public Strumenti{

public:
    void suona() override{
        cout << "La Batteria" << endl;
    }
};



/*
POLIMORFISMO. Puntatore di tipo classe base.
In questo modo posso usare questa funzione per entrambi
gli strumenti da suonare (Violino e Batteria).
Senza il Polimorfismo avrei dovuto dichiarare tante funzioni quanti sono
gli strumenti da suonare:

void Suonare_Strumento(Violino viol){...};

void Suonare_Strumento(Batteria batt){...};

Questo è possibile perchè il puntatore a classe base, avendo il metodo
suona() virtual, è in grado di accedere e quindi vedere tutti i metodi,
ecc... delle sue sottoclassi (Violino, Batteria). Lo abbiamo
visto quando abbiamo parlato di Upcasting e Metodi Virtual (Virtual function).
*/

void Suonare_Strumento(Strumenti *s){
    cout << "Sto suonando " << endl;
    s->suona();                         /*I metodi dichiarati public possono essere chiamati anche dal main. suona() è un metodo public*/
}





int main()
{
    Violino v;
    Strumenti *pt;  /*Anche se Strumenti è una classe astratta perchè ha un metodo virtual puro, posso comunque dichiarere un puntatore di tipo classe astratta*/
    pt= &v;
    pt->suona();

    Suonare_Strumento(&v); /*Passo al puntatore di classe base (Strumenti *s) un oggetto (v) della sottoclasse Violino*/

    printf("\n");

    Batteria b;
    pt= &b;
    pt->suona();

    Suonare_Strumento(&b);  /*Passo al puntatore di classe base (Strumenti *s) un oggetto (b) della sottoclasse Batteria*/

    return 0;
}

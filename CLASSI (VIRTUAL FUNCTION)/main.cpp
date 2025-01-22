#include <iostream>

using namespace std;


class square{
private:
    int x;

public:

    virtual int area(int x){
        return (x*x);
    };

    int y=area(x);

    virtual void view(int y){
        cout << "Area quadrato: " << y << endl;
    };
};



class square2 : public square{
private:
    int y;

public:

    int area(int y){
        return (y*y);
    };

    int x=area(y);

    void view(int x){
        cout << "Area quadrato2: " << x << endl;
    };
};



int main()
{
    square a;
    a.view(a.area(6));

    square*punt;
    square2 b;
    punt=&b;

    punt->view(punt->area(2));

    return 0;
}



/*
VIRTUAL FUNCTION:
Invece di usare il cast del puntatore della classe base (tipo) che punta a una classe derivata (VEDI esercizio: CLASSI (UPCASTING)),
è possibile dichiarere il metodo o i metodi presenti nella classe base 'virtual'.
In questo modo anche se abbiamo un puntatore della classe base (tipo) che punta a una classe derivata, e sia la classe base che derivata
hanno un metodo con stesso nome e num. di parametri, andando a chiamare il metodo della classe derivata con il puntatore verrà chiamato
proprio questo metodo e no quello della classe base, poichè il puntatore sarà in grado di vedere anche i metodi della classe derivata e
non solo quelli della classe base (cosa che con l'UPCASTING non è possibile ed è per questo che per ovviare a ciò dovevo eseguire il cast
alla classe derivata, ma ora utilizzando 'virtual' questo non è più necessario).
*/

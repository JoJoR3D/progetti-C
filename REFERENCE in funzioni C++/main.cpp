#include <iostream>

using namespace std;


/*
    E' possibile utilizzare il reference '&' invece del
    puntatore '*' come parametri di un metodo, grazie al
    compilatore del C++.
    In questo modo possiamo evitare di usare i puntatori (in qeusto
    caso nel metodo swapVar) e la '&' nel main quando richiamiamo
    il metodo.
    Il compilatore vedendo il reference nel prototipo della funzione
    sa che quando nella chimata della funzione passo x,y
    sa che deve passare l'indirizzo.
*/

template <typename X> void swapVar(X &var, X &var1)
{
    X temp= var;
    var= var1;
    var1= temp;
}



int main()
{
    int x= 10, y=8;
    swapVar<int>(x,y);

    cout << "X: " << x << " Y: " << y << endl;

    return 0;
}

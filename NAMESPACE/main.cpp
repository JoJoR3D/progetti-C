#include <iostream>

using namespace std;


namespace s{
    void func(int x){
        cout << "X: " << x << endl;
    };
}


/*using namespace s;*/



/*
Posso anche definire il prototipo della funzione nel namespace e
poi dichiararla prima del main utilizzando '::' (Scope resolution operator)

namespace s{
    void func(int x);
}

void s::func(int x){
        cout << "X: " << x << endl;
}

*/


int main()
{
    int x=15;

    /*Usando using namespace s:
    func(x);
    */

    /*Senza usare using:*/
    s::func(x);

    return 0;
}

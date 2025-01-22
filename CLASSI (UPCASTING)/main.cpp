#include <iostream>

using namespace std;


class square{
private:
    int x;

public:

    int area1(int x){
        return (x*x);
    };

    int y=area1(x);

    void view1(int y){
        cout << "Area quadrato1: " << y << endl;
    };
};



class square2 : public square{
private:
    int y;

public:

    int area2(int y){
        return (y*y);
    };

    int x=area2(y);

    void view2(int x){
        cout << "Area quadrato2: " << x << endl;
    };
};



class rettangolo : public square{
private:
    int b,h;

public:

    int area(int b, int h){
        return b*h;
    };

    int y=area(b,h);

    void view(int y){
        cout << "Area rettangolo: " << y << endl;
    };
};



int main()
{
    square t;
    t.view1(t.area1(10));

    square2 z;              /*suqare2 ha ereditato dalla superclasse square i metodi 'area' e 'view'*/
    z.view2(z.area2(8));

    square*punt;
    punt=&z;
    punt->view1(punt->area1(3));


    /*
    UPCASTING:

    punt->view2(punt->area2(3));

    Ritorna errore perchè puntando ad un oggetto della classe derivata (square 2 z) con un puntatore alla classe base(square*punt)
    si può accedere solo ai membri della classe base (square) che sono stati ereditati dalla classe derivata (square2),
    quindi tutto quello che poi viene aggiunto nella classe derivata (metodi, membri,ecc..) il puntatore non lo vede.
    Infatti i metodi view2() e area2() sono stati aggiunti nella classe derivata square2 e non ereditati dalla superclasse 'square'.


    punt->view1(punt->area1(3));

    Non ritorna errore appunto perchè il puntatore alla classe base (square*punt) che punta alla classe derivata ('square2' punt=&z), richiama
    i metodi ereditati dalla superclasse 'square' (metodi superclasse ereditati: area1(); view1();).
    */


    ((square2*)punt)->view2(((square2*)punt)->area2(5));

    /*
    Operazione di CAST:
    Però vi è un modo per ovviare a ciò, ovvero basta fare un cast del puntatore alla classe derivata (istruzione rigo di sopra). In questo modo
    il blocco di memoria del puntatore della classe base viene ampliato e quindi il puntatore è in grado di vedere anche tutto quello che è stato
    dichiarato nella classe derivata (metodi, ecc...).
    */






    rettangolo r;
    r.view(r.area(2,4));    /*OVERLOADING: anche se il metodo area() della suqperclasse square e della sottoclasse rettangolo hanno lo stesso nome, il
                                           compilatore capisce quale dei due chiamare poichè si differenziano per il numero di parametri.
                                           area() della superclasse ha un solo parametro di input, mentre area() della sottoclasse ha due parametri di input.*/

    return 0;
}

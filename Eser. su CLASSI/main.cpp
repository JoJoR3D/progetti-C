#include <iostream>

using namespace std;

class Frutta{       /*CLASSE BASE*/

public:
    Frutta(){       /*COSTRUTTORE DI DEFAULT*/
    };


    void restituisci(int codice, int prezzo){
        cout << codice << " " << prezzo << endl;
    };


    ~Frutta(){};    /*DISTRUTTORE*/


private:
    int codice, prezzo;

};



class Banana : public Frutta{           /*CLASSE DERIVATA  che Eredita (public) dalla Classe Base Frutta*/

public:

    void stampa(int c, int p){
        cout << c << " " << p << endl;
    };

    ~Banana(){};    /*DISTRUTTORE*/

};




int main()
{
    Frutta f;
    Banana b;
    int c=111,p=55;

    f.restituisci(120,33);
    b.stampa(c,p);
    b.restituisci(345,89);  /*Essendo restituisci() un metodo public della classe base Frutta, posso chiamarla madante la classe derivata Banana.*/

    return 0;
}

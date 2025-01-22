#include <iostream>
#include <cstring>

using namespace std;


class Stringa{

private:
    char s[50];

public:
    Stringa operator= (char*x);
    friend Stringa operator+ (Stringa&a, Stringa&b);
    void view();
};


Stringa Stringa::operator= (char*x){
    strcpy(s,x);

    return *this;
}



/*Uso il le variabili 'a' e 'b' di tipo Stringa (classe Stringa) per accedere all'attributo privato (char s[50]) della classe Stringa.*/

Stringa operator+ (Stringa&a, Stringa&b){
    strcat(a.s,b.s);

    return a;
}



void Stringa::view(){
    cout << s << endl;
}





int main()
{
    Stringa s1,s2;
    s1= "Cassa";
    s2= "Panca";

    s1 + s2;
    s1.view();

    return 0;
}

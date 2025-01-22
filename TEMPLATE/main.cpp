#include <iostream>

using namespace std;

/*
TEMPLATE:
Definire un metodo o una classe, o ecc.. associando un tipo
generico (non definito). Cioè posso non specificare il tipo del
metodo ma posso associargli un tipo generico.

In questo modo possiamo avere un metodo che a seconda del tipo
che definiamo ci ritorna un determinato valore di quel tipo.
Così non devo creare lo stesso metodo per ogni tipo, ma mi basta
indicare un tipo generico (TEMPLATE) al momento della definizione
del metodo per poi richiamare questo metodo e associargli il tipo
di cui ho bisogno.

Come si usa?
Si utilizza la parola chiave:
templete <typename X> prima della definizione del metodo; oppure
template <class X>; E' la stessa cosa.

Mentre nella chiamata nel main:

int i,j;
swaper<int>(i,j); "Tra le parentesi angolari indichiamo il tipo
della funzione template"
*/


template <typename X> void swapvar(X *a, X *b)
{
    X temp= *a;
    *a= *b;
    *b= temp;
}


/*
N.B. Se un metodo ha uno o più tipi, è possibile usare più tipi
generici in base a quanto sono i parametri del metodo.
*/

template <typename X,typename Y> void show(X a, Y b)
{
    cout << "A: " << a << " B: " << b << endl;
}





int main()
{
    int i=3,j=5;
    swapvar<int>(&i,&j);    /*Il tipo poi va indicato tra le parentesi angolari*/

    cout << "I: " << i << " J: " << j << endl;

    float a=2.3, b=5.8;
    swapvar<float>(&a,&b);

    cout <<"A: " << a << " B: " << b << endl;

    char car1='a', car2='b';
    swapvar<char>(&car1,&car2);

    cout <<"W: " << car1 <<" Z: " << car2 << endl;


    int var1= 78;
    float var2= 44.4;
    show<int,float>(var1,var2);

    return 0;
}

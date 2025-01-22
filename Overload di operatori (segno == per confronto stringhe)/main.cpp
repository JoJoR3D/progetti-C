#include <iostream>
#include <cstring>

using namespace std;

/*
Link: https://learn.microsoft.com/it-it/cpp/cpp/friend-cpp?view=msvc-170

In alcune circostanze, è utile per una classe concedere l'accesso a livello di membro alle funzioni
che non sono membri della classe o a tutti i membri di una classe separata. Queste funzioni e classi
gratuite sono note come amici, contrassegnate dalla friend parola chiave . Solo l'implementatore
della classe può dichiarare i rispettivi elementi friend. Una funzione o una classe non può dichiararsi
come un amico di qualsiasi classe. In una definizione di classe usare la friend parola chiave e il
nome di una funzione non membro o di un'altra classe per concedere l'accesso ai membri privati e
protetti della classe. In una definizione di modello un parametro di tipo può essere dichiarato come .friend

Una friend funzione è una funzione che non è membro di una classe, ma ha accesso ai membri privati e
protetti della classe. Le funzioni Friend non sono considerate membri della classe; sono normali funzioni
esterne a cui vengono assegnati privilegi di accesso speciali. Gli amici non sono inclusi nell'ambito
della classe e non vengono chiamati usando gli operatori di selezione dei membri (. e ->), a meno che
non siano membri di un'altra classe. Una friend funzione viene dichiarata dalla classe che concede l'accesso.
La friend dichiarazione può essere inserita in qualsiasi punto della dichiarazione di classe.
Non è interessato dalle parole chiave di controllo di accesso.
*/


/*VERSIONE 1*/

class Stringa{

private:
    char s[50];

public:
    Stringa operator= (char*t);
    friend int operator== (Stringa&a, Stringa&b);   /*La funzione operator accetta un solo argomento, no due come in questo caso. Per questo si usa il qualificatore friend*/
                                                    /*Link: https://stackoverflow.com/questions/11229074/overloading-operator-complaining-of-must-take-exactly-one-argument#comment14749805_11229074*/
                                                    /*FUNZIONE ESTERNA ALLA CLASSE (NON MEMBRO)*/
    void view();
};


Stringa Stringa::operator= (char*t){
    strcpy(s,t);

    return *this;
}

void Stringa::view(){
    cout << s << endl;
}


int operator== (Stringa&a, Stringa&b){
    if(strcmp(a.s,b.s)== 0)
        return 1;
    else
        return 0;
}





int main()
{
    Stringa s1,s2;
    s1= "Franco";
    s2= "Franca";
    s1.view();
    s2.view();

    cout << " " << endl;

    if(s1 == s2)
        cout << "Le due stringhe sono uguali" << endl;
    else
        cout << "Le due stringhe sono diverse" << endl;

    return 0;
}





/*
VERSIONE 2 (ALTERNATIVA):

class Stringa{

private:
    char s[50];

public:
    Stringa operator= (char*t);
    int operator== (Stringa&a);         Come sovraccarico dell'operatore membro , dovrebbe accettare solo un argomento (Stringa s2="Franca"), l'altro è this (this è un puntatore implicito all’oggetto della classe: Stringa s1="Franco" dichiarato nel main).
                                        Link: https://stackoverflow.com/questions/11229074/overloading-operator-complaining-of-must-take-exactly-one-argument#comment14749805_11229074
    void view();
};


Stringa Stringa::operator= (char*t){
    strcpy(s,t);

    return *this;
}

void Stringa::view(){
    cout << s << endl;
}


int Stringa::operator== (Stringa&a){
    printf("\n\n1: %s, 2: %s\n\n",a.s,s);
    if(strcmp(a.s,s)== 0)               Confronto tra l'argomento (Stringa s2="Franca")e l'oggetto della classe (Stringa s1="Franco"). Quindi strcmp esegue un confrontro tra Stringa s2 (a.s) e Stringa s1 (s)
        return 1;
    else
        return 0;
}
*/

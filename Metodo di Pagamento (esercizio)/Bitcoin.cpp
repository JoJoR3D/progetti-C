#pragma once

#include <iostream>
#include "MetodoPagamento.cpp"

using namespace std;


class Bitcoin : public MetodoPagamento{

public:
    void paga(float totale) override{
        cout << "Sto pagando " << totale << " euro con Bitcoin" << endl;
    }

    /*N.B. Tipicamente, ma non � necessario, si specifica che si
           sta eseguendo l'override di un metodo di classe base,
           scrivendo la parola 'override'.
           Questo per� si pu� usare solo se il metodo della classe
           base � virtual o virtual puro.
    */
};

#pragma once

#include <iostream>
#include "MetodoPagamento.cpp"

using namespace std;


class CartaDiCredito : public MetodoPagamento{

public:
    void paga(float totale) override{
        cout << "Sto pagando " << totale << " euro con Carta di credito" << endl;
    }

    /*N.B. Tipicamente, ma non è necessario, si specifica che si
           sta eseguendo l'override di un metodo di classe base,
           scrivendo la parola 'override'.
           Questo però si può usare solo se il metodo della classe
           base è virtual o virtual puro.
    */
};


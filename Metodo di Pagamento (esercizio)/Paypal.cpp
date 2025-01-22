#pragma once

/*
pragma once è un comando (direttiva al compilatore) che evita di
includere più volte lo stesso file main().
Ad esempio nel main() abbiamo incluso il file (classe)
MetodoPagamento.cpp, ora lo abbiamo incluso anche in questo file (classe)
Paypal.cpp che poi andremo ad includere nel main():
In questo modo il file (classe) MetodoPagamento.cpp nel main() sarebbe
incluso due volte (uno incluso direttamente nel main e uno
indirettamente nel file Paypal).
Per evitare di include un file pià volte nel main si usa il comando
pragma once che sta ad indicare che se un file è stato già incluso
nel main() non lo includere un'altra volta.

Lo stesso vale, ad esempio per #include <iostream>.
Se lo includiamo in un file e anche nel main(), verrà incluso
due volte, ma grazie a #pragma once verrà incluso una sola
volta e no due volte.

Ricorda che: Il comando include non va a fare altro che un copia
e incolla nel file principale del progetto.
Nel caso di iostream copierà nel main le funzioni che la classe
iostream contiene.

#pragma once è un header guards. Definizione Wikipedia:
Nei linguaggi C e C++, le #include guard sono delle particolari
direttive che vengono usate nei file header per evitare problemi
di doppia definizione in fase di linking.
*/

#include <iostream>
#include "MetodoPagamento.cpp"

using namespace std;


class Paypal : public MetodoPagamento{

public:                     /*Se non definisco nulla di default è private*/
    void paga(float totale) override{
        cout << "Sto pagando " << totale << " euro con Paypal" << endl;
    }

    /*N.B. Tipicamente, ma non è necessario, si specifica che si
           sta eseguendo l'override di un metodo di classe base,
           scrivendo la parola 'override'.
           Questo però si può usare solo se il metodo della classe
           base è virtual o virtual puro.
    */

};


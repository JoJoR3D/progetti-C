#pragma once
#include <iostream>

using namespace std;


class MetodoPagamento{

public:
/*
Il metodo paga è troppo generico, poichè per ogni metodo di pagamento
c'è una diversa operazione da eseguire. Per payPal devo fare il login
sulla sua piattaforma, per la carta di credito devo fare il login
sull'app della banca. Quindi non sapendo come devo definire il metodo
paga(), lo definisco VIRTUAL PURO.
in questo modo saranno le sottoclassi (payPal,carta di credito,ecc..)
a implementare il metodo paga() (overraid) come serve a loro

Ricorda che una classe che contiene un metodo virtual puro è definita
classe astratta e in quanto tale il metodo virtual puro non può essere
istanziato (allocato) nel main. Quindi non posso definire un oggetto
di classe astratta.
*/

 virtual void paga(float totale_carrello)=0;
};

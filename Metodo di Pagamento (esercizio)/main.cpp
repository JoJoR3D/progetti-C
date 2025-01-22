#include <iostream>
#include "MetodoPagamento.cpp"
#include "Paypal.cpp"
#include "CartaDiCredito.cpp"
#include "Bitcoin.cpp"

using namespace std;


/*
Funzione che esegue il pagamento. Gli passo il totale da pagare
e il metodo di pagamento scelto per pagare il totale del carrello.

Uso il template per indicare un tipo generico per il metodo di
pagamento. In questo modo posso usare questa funzione per entrambi
i metodi di pagamento (Paypal e CartaDiCredito).
Senza il template avrei dovuto dichiarare tante funzioni quanti sono
i metodi di pagamento disponibili:

void effettuaPagamento(float totale, Paypal ppl){...};

void effettuaPagamento(float totale, CartaDiCredito cc){...};
*/

template <typename X> void effettuaPagamento(float totale, X x){

    x.paga(totale);     /*I metodi dichiarati public possono essere chiamati anche dal main. paga() è un metodo public*/
}


/*
Altro modo per effettuare il pagamento è usare il POLIMORFISMO.
Ovvero usiamo un puntatore di tipo classe base.
Il POLIMORFISMO va usato con i PUNTATORI (in questo caso, ad esempio,
non posso fare: MetodoPagamento m, ma devo usare il
Puntatore).

Questo è possibile perchè il puntatore a classe base, avendo il metodo
paga() virtual, è in grado di accedere e quindi vedere tutti i metodi,
ecc... delle sue sottoclassi (Paypal, CartaDiCredito, Bitcoin). Lo abbiamo
visto quando abbiamo parlato di Upcasting e Metodi Virtual (Virtual function).

POLIMORFISMO più forme, perchè nel nostro esempio: effettua
pagamento, il metodo paga() può assumere comportamenti diversi in base a quello che gli passo.
Usando il metodo Paypal verrà eseguita una operazioe,
usando Carta di credito verrà eseguita un'operazione diversa.
Ogni metodo di pagamento esegue una diversa operazione per
eseguire il pagamento.
Una classe, o una funzione, può agire in modi diversi in base
all'istanza particolare che gli passo. L'istanza deve ovviamente
essere una sottoclasse della superclasse che ho specificato.
*/

void effettuaPagamento_1(float totale, MetodoPagamento *m){

    m->paga(totale);    /*I metodi dichiarati public possono essere chiamati anche dal main. paga() è un metodo public*/
}




int main()
{
    float totale_carrello= 1983.99;

    /*MetodoPagamento a;    Ritorna errore perchè MetodoPagamento è una classe astratta*/

    Paypal pa;
    /*pa.paga(totale_carrello);*/

    CartaDiCredito cdc;
    /*cdc.paga(totale_carrello);*/

    effettuaPagamento<Paypal>(totale_carrello,pa);  /*Il tipo poi va indicato tra le parentesi angolari*/
    effettuaPagamento<CartaDiCredito>(totale_carrello,cdc);

    cout << "\n" << endl;

    effettuaPagamento_1(totale_carrello,&pa);   /*Passo al puntatore di classe base (MetodoPagamento *m) un oggetto (pa) della sottoclasse Paypal*/
    effettuaPagamento_1(totale_carrello,&cdc);  /*Passo al puntatore di classe base (MetodoPagamento *m) un oggetto (pa) della sottoclasse CartaDiCredito*/

    cout << "\n" << endl;

    Bitcoin bit;
    effettuaPagamento_1(totale_carrello,&bit);

    return 0;
}

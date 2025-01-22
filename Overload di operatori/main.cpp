#include <iostream>
#include <cstring>

using namespace std;

/*
Link Overload di operatori: https://www.edatlas.it/scarica/1845/Capitolo6/ContenutiDigitali/5ClassiOverloadingOperatori.pdf

L’operator overloading (sovraccarico dell’operatore) indica la possibilità di definire nuove funzionalità
ai vari operatori del linguaggio (++, – –, =, ecc.), in modo che il compilatore sia in grado
di comprendere il loro impiego nei nuovi tipi di dati creati dal programmatore.
L’operator overloading non è altro che un function overloading applicato a funzioni particolari
chiamate operator seguite dall’operatore a cui si riferiscono. Di seguito vengono presentati due
esempi di overloading degli operatori associati ad una classe.
Il tipo string consente di dichiarare variabili non numeriche. Per poter utilizzare questo tipo
occorre inserire nel programma la direttiva #include <string>, che rende disponibile la libreria del
linguaggio C++.
Nel linguaggio C e nelle versioni meno recenti di C++ questo tipo di dato non era disponibile
e le stringhe venivano memorizzate in array di caratteri. Ancora oggi, per compatibilità con
programmi e funzioni del passato, si ha a disposizione la libreria <cstring> con tutte le funzioni
per la manipolazione di array di caratteri, quali strcpy per la copia di array di caratteri o strcmp
per il loro confronto, presenti nella libreria <string.h> del linguaggio C.
Supponiamo quindi di non disporre del tipo string e di voler implementare la classe Stringa per
la gestione degli array di caratteri. Per le diverse manipolazioni degli array si impiegano le
funzioni di libreria, mentre con l’operator overloading si possono definire gli operatori per le
usuali operazioni di assegnazione, confronto, ecc.

Il problema principale consiste nella definizione dell'ambito di visibilità degli operatori sovraccaricati.
Alcuni operatori infatti possono essere sovraccaricati solo come membri di classe
(assegnamento, assegnamento di copia e spostamento) perchè per la loro implementazione è richiesto l'uso
del membro this, altri solo come funzioni esterne alla classe
(ad esempio gli operatori << e >> di inserimento ed estrazione da flusso).
*/

/*
ESERCIZIO:
Definire l’operatore = per l’assegnazione di array di caratteri.
Il progetto introduce una nuova classe Stringa e sovraccarica l’operatore = di assegnazione
in modo che si possano assegnare array di caratteri anche ad oggetti di questo tipo. Il
diagramma della classe Stringa è il seguente:
L’attributo s rappresenta un array di caratteri.
Il primo metodo rappresenta l’operator overloading per l’operazione di assegnazione di array
di caratteri, il secondo consente di visualizzare un oggetto dichiarato come istanza della
classe Stringa.

Per poter utilizzare la funzione predefinta strcpy per la copia tra stringhe, occorre inserire nel
programma la direttiva:
#include <cstring>

La funzione operator = ha un valore di ritorno per consentire anche assegnazioni ripetute
come:
s1 = s2 = "Napoli";

Il valore di ritorno è un oggetto di classe Stringa. La funzione operator = è una funzione
membro della classe Stringa; per indicare che il valore di ritorno è la classe stessa si usa
l’istruzione.

return *this;
La parola riservata this del linguaggio C++ indica l’indirizzo della classe di appartenenza
(quindi this è un puntatore implicito all’oggetto della classe). La parola this può essere
tradotta in questo contesto come oggetto corrente per la funzione membro che si sta
definendo.

Si deve osservare che l’overloading dell’operatore = proposto in questo esempio consente di
assegnare valori costanti (racchiusi tra doppi apici) ad un oggetto di tipo Stringa.
L’assegnazione tra due oggetti dello stesso tipo Stringa, come nella seguente istruzione:
s2 = s1;
è invece garantita dall’operatore di assegnazione di default per la classe Stringa.
*/


class Stringa{

private:
    char s[50];

public:
    Stringa operator= (char*sorgente);  /*FUNZIONE MEMBRO perchè per la loro implementazione è richiesto l'uso del membro this*/
    void Mostra();

};



Stringa Stringa::operator= (char*sorgente){
    strcpy(s,sorgente);

    return *this;   /*Puntatore implicito all'oggetto (char s[50]) della classe. Quindi assegno all'oggetto s la stringa di caratteri= "Piero" (sorgente).*/
}


void Stringa::Mostra(){
    cout << s << endl;
}




int main()
{
    Stringa s1,s2;
    s1= "Piero";        /*Grazie all'overloading di operator= posso assegnare la stringa di caratteri: "Piero", all'oggetto (char s[50]) della classe*/
    s2= "Filippo";
    s1.Mostra();
    s2.Mostra();

    s1 = s2;
    s1.Mostra();

    return 0;
}

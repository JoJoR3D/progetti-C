#include <iostream>
#include <string>

/*Vedi appunti con nome: APPUNTI C++*/

/*
  Realizzare una classe studente che permetta al docente di inserire uno studente, la sua matricola e il voto dell'esame sostenuto.
  Poi permettere di visualizzare i dati inseriti.
*/



using namespace std;

class Studente{

public:

    /*COSTRUTTORE DI DEFAULT
    Studente(){}
    */


    /*CONSTRUTTORE CON PARAMETRI*/
    Studente(const char*nome, const char*cognome, const char*matricola, unsigned int voto){
        this->nome=nome;
        this->cognome=cognome;
        this->matricola=matricola;
        this->voto=voto;

        mioArray= new int[100];
    }


    /*COSTRUTTORE DI COPIA*/
    Studente(Studente *s){
        nome= s->nome;              /*Assegno a nome la stringa s->nome*/
        cognome= s->cognome;
        matricola= s->matricola;
        voto= s->voto;
    }




    /*Questa void mi serve per per indicare nome,cognome e matricolo dello studente al quale voglio inserire il voto dell'esame sostenuto.*/
    /*InserisciDati è come se fosse un metodo SET. (vedi: Appunti C++)*/

    void InserisciDati(const char*nome, const char*cognome, const char*matricola, unsigned int voto){
        this->nome=nome;    /*this-> è un puntatore che punta all'oggeto a cui appartiene. Quinid ad s1 (nel main), poichè s1 è l'oggetto della classe Studente.*/
                            /*Utilizzo this-> perchè il parametro di input char*nome l'ho chiamato uguale all'ATTRIBUTO string nome della classe Studente.*/
        this->cognome=cognome;
        this->matricola=matricola;
        this->voto=voto;
    }



    /*DISTRUTTORE*/
    /*~Studente(){}*/


    /*DISTRUTTORE PER ELIMINARE LA VARIABILE ALLOCATA DINAMICAMENTE*/
    ~Studente() { delete[] mioArray; }
    /*Gli new operatori e delete possono essere usati anche per i tipi predefiniti, incluse le matrici. Se l'oggetto fa riferimento a una matrice, posizionare parentesi vuote ([]) prima  del oggetto da deallocare.*/







    /*Metodo GET*/
    /*Anche se gli attributi: nome,cognome,matricola e voto sono privati, posso accedervi perchè gli attributi privati sono accessibili solo nella classe nella quali sono stati dichiarati*/
    string getNome() {return nome;}

    string getCognome() {return cognome;}

    string getMatricola() {return matricola;}

    unsigned int getVoto() {return voto;}


private:
    /*Questo è il data hiding*/
    string nome, cognome, matricola;
    unsigned int voto;
    int *mioArray;
};





int main()
{
    /*PRIMA VERSIONE

    const int N_stud= 2; numeri di studenti per i quali dobbiamo inserie i voti

    Studente s1[N_stud]; s1 è un'oggetto della classe Studente

    s1[0].InserisciDati("Peppe","Riccio","123456",26);
    cout << "Nome s1: " << s1[0].getNome() << endl;

    s1[1].InserisciDati("Luca","Bianchi","123457",28);
    cout << "Nome s1: " << s1[1].getCognome() << endl;
    */


    /*SECONDA VERSIONE con COSTRUTTORE DI DEFAULT

    Studente s1; s1 è un'oggetto della classe Studente


    COSTRUTTORE:
    Quando dichiaramo un'oggetto (s1) della classe Studente, prima di inizializzarlo (rigo sotto) questo contiene dati casuali,
    e ciò in alcuni casi può creare dei problemi.
    Quindi per inizializzare un'oggetto appena lo creiamo utilizziamo il costruttore.
    Quello che fa il costruttore è andare ad inizializzare tutti gli attributi della classe con i loro valori di default.
    Quindi inizializza i membri della classe con i loro valori di default. Ad esempio: ho un attributo di tipo int, allora verrà inizializzato con zero;
    ho un float allora lo inizializza con 0.0; ho una string allora lo inizializza con una stringa vuota; ho un bitset allora lo inizializza con tutti zeri.


    s1.InserisciDati("Mario","Rossi","123",30);
    cout << "S1: " << s1.getNome() << " " << s1.getCognome() << endl;


    Studente s2;

    s2.InserisciDati("Peppe","Pascoli","124",29);
    cout << "S2: " << s2.getNome() << " " << s2.getCognome() << endl;
    */




    /*TERZA VERSIONE con COSTRUTTORE CON PARAMETRI*/

    Studente s1("Mario","Rossi","123",30); /*COSTRUTTORE CON PARAMETRI*/

    cout << "S1: " << s1.getNome() << " " << s1.getCognome() << " " << s1.getVoto() << endl;



    Studente s2("Peppe","Pascoli","124",29); /*COSTRUTTORE CON PARAMETRI*/

    cout << "S2: " << s2.getNome() << " " << s2.getCognome() << " " << s2.getVoto() << endl;


    Studente s3(s1); /*COSTRUTTORE DI COPIA, il compilatore capisce di chiamare il COSTRUTTORE DI COPIA poichè gli ho passato un puntatore ad uno studente (s1 puntatore allo studente s1)*/

    cout << "S3: " << s3.getNome() << " " << s3.getCognome() << " " << s3.getVoto() << endl;


    /*CREAZIONE DI UN OGGETTO IN MANIERA DINAMICA e poi LIBERIAMO LO SPAZIO ALLOCATO MEDIANTE delete*/
    Studente*s4= new Studente("Giuseppe","Cirillo","126",25);

    cout << "S4: " << s4->getNome() << " " << s4->getCognome() << " " << s4->getVoto() << endl;

    delete s4;



    return 0;
}

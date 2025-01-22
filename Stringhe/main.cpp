#include <iostream>
#include <limits>
#include <string.h>  /*Stiamo includendo la libreria string*/

using namespace std; /*namespace std è una classe di iostream che contiene i metodi cout e endl per poter stampare così come tanti altri metodi.*/
                     /*Se nel compilatore non scrivessi: using namespace std;, ogni volta che dovrei stampare usando cout e endl dovrei anteporre a questi due std::
                       ovvero: std::cout << s << std::endl;
                     */
                     /* Link: https://www.mrw.it/programmazione/perche-bisogna-scrivere-using-namespace-std_8060.html
                        La dichiarazione using namespace std in C++ viene utilizzata per specificare che si desidera utilizzare le funzioni e le classi presenti
                        all'interno del namespace std.
                        Il namespace std contiene molte delle funzioni e delle classi standard fornite dal compilatore C++, tra cui input/output, stringhe,
                        vettori, algoritmi e molto altro. Senza la dichiarazione using namespace std, sarebbe necessario qualificare ogni funzione o classe
                        con il prefisso std:: ogni volta che si desidera utilizzarle.
                     */
                     /*Quindi si usa using namespace std per utilizzare le classi presenti nelle librerie incluse al progetto.
                       Ad esempio, anche per la dichiarazione delle stringhe, senza using namespace std; per dichiarare una stringa utilizzando
                       la classe string, dovrei fare:
                       std::string s= "Questa e' una stringa";
                     */

int main()
{
    const char*s= {"Hello Word!"};  /*1*/
    char a[]= {"Peppe"};            /*2*/
    cout << s << endl;
    cout << a << endl;

    a[2]= 'P';
    cout << a << endl;

    cout << (int)a[2] << endl;

/*1) In C++ le stringhe costanti vanno dichiarate con const che precede il char,
     altrimenti il compilatore darà un warning.
     Il warning serve ad avvisare che si sta dichiarando una stringa costante che non
     postrà essere modificata altrimetni si avrà un errore di segmentation fault (cioè si
     sta tentando di accedere ad un'area di memoria a cui non si può accedere.
     Usando const invece, se si prova a modificare la stringa constante, il compilatore non
     compila il programma e segnala subito l'errore (evitando così di scrivere in un'area di
     memoria a cui non dovremmo accedere).

  2) Invece se dichiaro un stringa sotto forma di array di stringhe, non ho questo problema,
     poichè questa stringa è modificabile non essendo una costante stringa.
*/

    cout << "\n\n" << endl;

    char b[50]= {"Ciao!"};

    cout << sizeof(b) << endl;
    cout << strlen(b) << endl;

    /*Il sizeof di b mi ritornerà 50byte perchè ho allocato 50byte ospitare massimo 49 caratteri + il carattere terminatore.
      Un char in memoria occupa 1 byte.
      Anche se non ho occupato tutti i 50 byte (la stringa "Ciao!" + il terminatore occupa 6 byte), la funzione sizeof mi ritorna
      quanta memoria ho chiesto di occupare per dichiarare l'arrya b di stringhe, ovvero 50 byte.

      Per sapere la lunghezza della stringa contenuta nell'array b dobbiamo usare la funzione strlen(), che mi ritornerà 5 byte (considera solo i
      caratteri inseriti senza considerare il terminatore.
    */

    const char*v= "T";

    cout << sizeof(v) << endl;

    /*Il sizeof di v mi ritorna 8 bit, perchè il singolo carattere inserito, come detto, in memoria occupa 1 byte (8 bit).
    */


    char t[]= "L";

    cout << sizeof(t) << endl;

    /*Il sizeof di v mi ritorna 2 byte, perchè il singolo carattere inserito, come detto, in memoria occupa 1 byte (8 bit), ma
      esendo un'array di stringa e no un puntatore a char come nel esempio di sopra, dobbiamo considerare anche il carattere terminatore
      che anche esso occupa in memoria 1 byte.
    */


    printf("\n\nInizializzazione Stringhe in C++\n");







    /*ALTRE INIZIALIZZAZIONI IN C++ PER LE STRINGHE*/

    /*Includendo la libreria string, questa presenta delle classi, tra cui anche la classe string, che contengono metodi (funzioni). Noi possiamo utilizzare questi metodi presenti nelle classi
      per svolgere alcune operazioni. Ad esempio è possibile usare un metodo presente in questa libreria per concatenare due stringhe.
    */

    /*
    INIZIALIZZAZIONE:
    dopo aver incluso la libreria string, possiamo usare il tipo string per dichiarare una stringa:
    */

    string mystring;
    mystring= "This is a string";
    cout << mystring << endl;

    /*OPPURE:
      string mystring ("This is a string");  questo tipo di metodo è chiamato COSTRUTTORE.
      string mystring {"This is a string"};  questo tipo di metodo è chiamato LISTA DI INIZIALIZZAZIONE.
    */

    /*Quindi string è la classe, mentre mystring è la variabile che in C++ è detto OGGETTO. L'oggetto è l'istanza di una classe.
    */






    printf("\n\nAccedere ai campi di una stringa\n");

    /*ACCEDERE AI CAMPI DI UNA STRINGA*/

    cout << mystring[5] << endl;
    cout << mystring.at(6) << endl; /*metodo at*/

    /*Il primo caso però è pericoloso perchè non fa nessun controllo per verificare che l'indice inserito appartenga all'area di memoria allocata per la stringa mystring*/

    cout << mystring.size() << endl;

    /*Come possiamo vedere usando il metodo size(), la stringa mystring ha lunghezza 16. Se noi, ad esempio, provassimo ad accedere alla posizione 19
      (cout << mystring[19] << endl;) per vedere il contenuto il compilatore non ci darebbe nessun errore per indicarci che quell'area di memoria non appartiene
      alla stringa allocata, poichè come abbiamo visto, la stringa è stata allocata in memoria per occupare 16 byte (ogni carattere della stringa in memoria
      occupa 1 byte).

      Invece se usiamo il metodo .at(), se provassimo ad accedere alla posizione 19 otterremo un errore che ci indica che siamo usciti fuori dal range.
      ("std::out_of_range");
    */

    /*Per ottenere la lunghezza dells stringa, oltre al metodo .size(), possiamo usare anche il metodo .length(). Sono equivalenti.*/


    /*Per prendere solo una SOTTOSTRINGA della stringa, possiamo usare il metodo .assign() a cui dobbiamo passare in ordine:
      1. la stringa;
      2. la posizione della stringa da cui iniziare a leggere la sottostringa;
      3. quanti caratteri leggere.

      Esempio:
      string sottostringa;
      sottostringa.assign(mystring,5,4);
      cout << sottostringa << endl;

      Ciò significa: vai alla posizione 5 della stringa mystring e prendi 4 caratteri (posizione: 6,7,8,9).

      In string eseistono vari metodi che si chiamano .assign(), e ognuno vuole un tot. e determinati parametri in input
      E' possibile avere metodi (funzioni) con lo stesso nome mediante OVERLOADING.

      OVERLOADING:
      In programmazione, è detta overloading (o sovraccarico) la creazione di una famiglia di funzioni/subroutine aventi tutte lo stesso nome, ma che
      accettino un diverso insieme di argomenti (signature), e che eventualmente restituiscano un diverso valore di ritorno.
    */

    printf("\nSottostringa\n");
    string sottostringa;
    sottostringa.assign(mystring,5,4);
    cout << sottostringa << endl;

    printf("\n\nCONCATENAZIONE STRINGA MEDIANTE METODO DELLA CLASSE STRING\n");

    /*Ora usiamo un metodo: .append() della classe string per eseguire la concatenazione tra due stringhe*/

    string s1("Hello"), s2(" World!");

    s1.append(s2); /*concatena alla stringa s1, la stringa s2 passata mediante il metodo .append()*/

    cout << s1 << endl;


    printf("\n\nALTRO MODO PER CONCATENARE LE STRINGHE E' MEDIANTE L'OPERATORE '+='\n");

    string s3("Hello"), s4(" World!");

    s3 += s4; /*concatena alla stringa s3, la stringa s4 mediante l'operatore '+=' */

    cout << s3 << endl;



    printf("\nSe volessimo mettere uno spazio, potremmo fare:\n");

    string s5("Hello"), s6("World!");

    s5 += ' ' + s6; /*concatena alla stringa s5, la stringa s6 mediante l'operatore '+=' */

    cout << s5 << endl;


    printf("\n\nAltro modo:\n");

    /*Questo tipo di concatenazione non funziona, da errore, perchè stiamo provando a concatenare
      due stringhe letterali (una stringa letterale è una sequenza di caratteri racchiusa tra doppio apice):
      string s1= "Hello" + " World!";
    */

    /*Però possiamo ovviare a ciò antecedendo alle due stringhe e sommando la classe string()
      Questo serve per indicare al compilatore che si sta concatenando a una stringa vuota (che è un oggetto),
      una stringa ("Hello") e poi essendoci un'altra stringa (" World!), si concatena anche questa:
    */

    string s7= string() + "Hello" + " World!";

    cout << s7 << endl;


    printf("\n\nConcatenare un oggetto 's' a una stringa letterale:\n");

    /*Quindi non possiamo concatenare due stringhe letterali senza assegnarle ad un oggetto.
      Però possiamo concatenare un oggetto s a una stringa letterale. Ad esempio:
    */

    string s8("Ciao");

    s8 += " Mondo!";

    cout << s8 << endl;

    printf("\n\n");






    printf("PER IL CONFRONTO TRA STRINGHE, INVECE DI strcmp(), E' POSSIBILE USARE IL SIMB. DI < o >\n");

    string str9("ABC");
    string str10("DEFG");
    cout << str9.size() << endl;
    cout << str10.size() << endl;

    /*Ritorna quale stringa viene prima in base all'ordine alfabetico dei caratteri che la compongono*/
    if(str9 < str10)
        cout << str9 << endl;
    else if(str9 > str10)
        cout << str10 << endl;

    printf("\n\n");






    printf("METODO PER INSERIRE CARATTERI IN UNA STRINGA\n");

    str9.insert(1,str10); /*Inserisce a partire dalla posizione 1 della stringa str9 la stringa str10*/
    cout << str9 << endl;

    printf("\n\nMETODO PER ELIMINARE CARATTERI IN UNA STRINGA\n");

    str9.erase(1,3); /*Elimina i caratteri dalla posizione 1 alla 3 della stringa str9*/
    cout << str9 << endl;

    printf("\nInserire i caratteri eliminati dalla stringa str9, alla stringa pe partendo dalla posizione 2\n");
    string reins= str9.erase(1,3); /*Elimina i caratteri dalla posizione 1 alla 3 della stringa str9*/
    cout << str9 << endl;
    string pe("Cacciatore");
    pe.insert(2,reins);
    cout << pe << endl;

    printf("\n\nMETODO PER REPLICARE I CARATTERI IN UNA STRINGA\n");

    string str11("Contadino");
    string str12("palla");
    str11.replace(1,4,str12); /*Rimpiazza i caratteri della str11 dalla posizione 1 alla 4 con la stringa str12*/
    cout << str11 << endl;

    /*
        N.B.
        Con il metodo .erase() e .replace(), possiamo indicare come secondo parametro da passare (int)string::npos.
        Il secondo parametro indica fino a quale posizione della stringa arrivare per, ad esempio usando il metodo .erase(), eliminare i caretteri della stringa.
        (int)string::npos indica fino alla fine della stringa
    */
    printf("\nSECONDO PARAMETRO (int)string::npos\n");
    string stringa("Pallavolo");
    stringa.erase(2,(int)string::npos);   /*Elimina i caratteri dells tringa partendo dalla posizione 2 fino alla fine della stringa*/
    cout << stringa << endl;





    printf("\n\n");

    printf("UN ATTRIBUTO DELLA CLASSE STRING E' 'NPOS' CHE VALE -1 E INDICA LA FINE DELLA STRINGA (significa fino alla fine)\n");

    string str90("Vai a fare in culo");
    string str91;

    printf("string::npos: ");
    int i= str90.find("in");            /*'i' conterrà la posizione dalla quale si trova la stringa "in". Se la stringa non è presente in str90, allora i sarà= -1 (che sarebbe il valore di npos)*/
    cout << (int)string::npos << endl;  /*cioè vuol dire che si è arrivati fino alla fine della stringa str90 è non si è trovata la stringa "in".*/

    if(i != (int)string::npos){         /*Se 'i' è diverso da -1*/
        printf("Posizione dalla quale si trova la stringa da trovare: ");
        cout << i << endl;
        printf("Dimensione della stringa str90: ");
        cout << str90.size() << endl;
        printf("Dimensione della stringa str91: ");
        cout << str91.size() << endl;

        /*Assega a str91 la sottostringa rimanente della stringa str90. Cioè partendo dalla stringa da trovare ("in") fino alla fine della stringa str90*/
        /*str90: Accedi alla stringa str90, e stampa la sottostringa,
          i+str91.size(): partendo da 'i' che è 11 + il size di str91 che è 0 (perchè è una stringa vuota). Quindi stampa i caratteri partendo dalla posizione 11,
          str90.size(): fino al size di str90, cioè fino alla fine della stringa.
        */

        str91.assign(str90, i+str91.size(), str90.size());
        printf("Sottostringa: ");
        cout << str91 << endl;
    }
    else
        cout << "Non trovato" << endl;





    /*
        Utilizzando il tipo string per dichiarare l'array, stiamo creando un'array di stringhe che è chiamato ARRAY FRASTAGLIATO,
        dove ogni stringa ha una propria lunghezza che termina al terminatore;
        Ad esempio:
        char s[50]= {"Peppe","Gianmarco"};
        In questo caso anche se la prima stringa ha lunghezza 5 e la seconda lunghezza 9 il numero di colonne, quindi lo spazio occupato in memroia, sarà di 50byte.
        Quindi nel caso della prima stringa abbiamo uno sperco in memoria di 45byte, mentre per la seconda stringa di 41byte.

        Invece con
        string s[]= {"Peppe","Gianmarco"};
        la prima stringa occuperà in memoria 5byte, mentre la seconda 9byte;
    */
    printf("\n\nRITORNA IL MESE CORRISPONDENTE\n");
    string mesi[]= {"Gennaio","Febbraio","Marzo","Aprile","Maggio","Giugno","Luglio","Agosto","Settembre","Ottobre","Novembre","Dicembre"};
    int num;

    do{
        printf("Inserisci il numero corrispondente al mese che vuoi visualizzare: ");
        scanf("%d",&num);

        if(num >= 1 && num <= 12){
            printf("Il mese corssipondente e': ");
            cout << mesi[num-1] << endl;
        }
        else
            cout << "ERRORE!" << endl;
    }while(num < 1 || num > 12);

    printf("\n\n");






    printf("METODO APPEND per aggiungere una stringa alla fine di un'altra stringa\n");
    string anni{"duemilaventi"};
    string agg_anni(" duemilaventicinque");
    anni.append(agg_anni);

    cout << anni << endl;






    printf("\n\nMETODI CIN e GETLINE\n");

    /*
        CIN è un metodo che legge i caratteri inseriti da tastiera, ma quando si inserisce lo spazio, CIN si interrompe e non legge più.

        Ad esempio:
        string name;
        cin >> name;
        Da tastiera inserisco la stringa "Mario Rossi". CIN legge solo "Mario" perchè si ferma allo spazio.

        Per ignorare la stringa "Rossi" rimasta nel buffer, è possibile usare il metodo. ignore():
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); ha la stessa funzionalità di fflush(stdin);
        N.B. Bisogna però aggiungere la libreria <limits>

        Invece il metodo GETLINE prende tutta la stringa inserita da tastiera finquando non incontra '\n', cioè fin quando non si preme invio.
    */

    string name;
    cin >> name;
    cout << name << endl;

    /*Se nella stringa name da tastiera inserisco, ad esempio, "Mario Rossi", CIN leggerà solo Mario e Rossi riamrrà nel buffer.
      Quando poi dichiaro la stringa name1 e uso CIN, essendoci nel buffer la stringa "Rossi", il sistema andrà a leggere e mostrare a
      schermo questa stringa.
      Come detto sopra, per evitare ciò posso usare il medoto .ignore() per svuotare il buffer.
    */
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    string name1;
    cin >> name1;
    cout << name1 << endl;

    /*Qui invece CIN legge fino al primo spazio, poi usando GETLINNE, legge la stringa dopo il primo spazio fino a che non si preme invio ('\n').
      N.B.
      Eseiste un altro metodo .getline() che vuole tre parametri di input, dove il terzo parametro è l'assegnazione del delimitatore.
      Di default il delimitatore, come abbiamo detto, è l'invio ('\n'), ma possiamo cambiarlo utilizzando il metodo .getline() con tre parametri in input.
    */
    string name2;
    cin >> name2;
    cout << name2 << endl;
    getline(cin,name2);
    cout << name2 << endl;

    return 0;
}

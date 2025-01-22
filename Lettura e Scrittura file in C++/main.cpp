#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

/*Link sito: https://ticoprof.wordpress.com/2020/03/25/lettura-e-scrittura-di-file-di-testo-in-cplusplus/*/

void write_f(char*);
void read_f(char*);


int main()
{
    char var[50];
    int num;

    printf("Si vuole leggere o scrivere nel file? 1 per leggere, 2 per scrivere: ");
    scanf("%d",&num);

    if(num == 2){
        write_f(var);
    }
    else{
        read_f(var);
    }

    return 0;
}






void write_f(char*var)
{
    int ciclo=1,agg=1,cont=0;
    /*Apre un file per la scrittura. Se non c'è un file con questo nome, lo crea.
      ios::app serve per scrivere in coda e non sovrascrivere il file.
    */
    ofstream fout("miofile.txt", ios::app);

    while(agg == 1){
        /*Per uscire dal ciclo, dopo la stringa inserita da tastiera, bisogna inserire uno spazio e poi il simbolo "/"*/
        while(ciclo == 1){                  /*Si ferma solo quando inserisco 0*/
            cin>>var;                       /*cin è lo scanf del C*/
            fout<<var<<' ';                 /*Scrive la stringa nel file, e ad ogni spazio inserite, lo inserisce nel file. Senza <<' ' le parole della stessa stringa le mette tutte attaccate.*/
            if(strcmp(var,"/") == 0)        /*Se è sato inserito il simbolo "/", pongo ciclo==0 per uscire dal while interno.*/
                ciclo=0;
        }
        printf("\nSi vuole aggiungere un'altra stringa? 1 per SI, 2 per NO: ");
        scanf("%d",&cont);
        if(cont == 1)
            ciclo=1;

        fout<<'\n';             /*Se devo inserire un'altra stringa, vado a capo nel file per inserire la stringa.*/
        agg=cont;
    }

    fout.close();               /*Chiusura del file. Dopo ogni operazione di lettura o scrittura, il file va chiuso.*/
}



void read_f(char*var)
{
    /*Apre il file per la lettura.*/
    ifstream fin("miofile.txt");

    while(fin.get(*var)){           /*Legge tutto il file fino alla fine.*/
        fin>>var;                   /*Legge le stringhe presenti nel file.*/
        cout << var << ' ';         /*Stampa a schermo le stringhe presenti nel file. Senza lo spazio (<< ' ') stampa attaccate tutte le parole della stringa.*/
        if(strcmp(var,"/") == 0)    /*Ogni stringa nel file termina con il simbolo "/", quando legge questo simbolo, va a capo per leggere e stampare la prossima stringa.*/
            cout << '\n';
    }

    fin.close();                    /*Chiusura del file. Dopo ogni operazione di lettura o scrittura, il file va chiuso.*/
}

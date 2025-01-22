#include <stdio.h>
#include <stdlib.h>

/*
    Questo programma converte in binario ogni singolo carattere dato in input dalla tastiera.
*/


void binary_code(unsigned char*, unsigned char*, unsigned char*);


int main()
{
    unsigned char Carattere, primo, secondo;
    int i,j;

    /*
        Per un char abbiamo a disposizione 8 bit. 2 elevato all'ottava= 256 possibili valori.
        Nel array di char 2D ogni riga rappresenta una stringa di bit che parte dal valore 0 fino al valore 15.
        Combinando le stringhe di bit presenti nell'array 2D è possibile rappresentare i valori da 0 fino a 255.
        Ad esempio, inserisco il caratere: 'i' questo in bit è: 01101001. Come posso stampare questa sequenza di bit?
        Richiamo la function binary_code che assegna a due variabili unsigned char il valore binario del carattere 'i'.
        swap verso destra (*t= *t>>4;) ottengo il vaore binario: 00000110 che è il numero 6;
        swap verso sinistra (*v= *v<<4;) ottengo il vaore binario: 10010000, poi eseguo un nuovo swap verso destra a questo valore (*v= *v>>4;)
        e ottengo il valore binario: 00001001 che è il numero 9;
        Poi nel main tramite un ciclo for innestato stampo i caratteri del array 2D presenti
        alla posizione riga 6 (primo==i): 0110 e alla posizione riga 9 (secondo==i): 1001.
        Unendo questi due valori 01101001 stampo a video la rappresentazione binaria del carattere 'i' che avevo dato in input.

        N.B. Uso il tipo unsigned char perchè altrimenti il primo bit (bit 1) dei valori da 8 (1000) fino a 15 (1111) viene letto come bit segno.
             Il valore 1 in bit segno rappresenta il segno meno, quindi mi ritornerebbe un valore negativo.
             Ad esempio il valore 14 che in bit è: 1110, leggendo il primo bit 1 come bit segno la stringa 1110 indicherebbe il valore -6 invece di 9.
             Usando invece il tipo unsigned char, tutti i valori in bit vengono letti come valori positivi.
    */

    char binario[][4]={ {'0','0','0','0'},
                        {'0','0','0','1'},
                        {'0','0','1','0'},
                        {'0','0','1','1'},
                        {'0','1','0','0'},
                        {'0','1','0','1'},
                        {'0','1','1','0'},
                        {'0','1','1','1'},
                        {'1','0','0','0'},
                        {'1','0','0','1'},
                        {'1','0','1','0'},
                        {'1','0','1','1'},
                        {'1','1','0','0'},
                        {'1','1','0','1'},
                        {'1','1','1','0'},
                        {'1','1','1','1'}
    };

    int n=16, m=4;                                  /*'n' è il numero di righe, mentre 'm' il numero di colonne*/

    printf("Inserire sequenza di caratteri: ");

    do{
        Carattere= getchar();
        binary_code(&Carattere,&primo,&secondo);
        printf("%c: ",Carattere);

        for(i=0;i<n;i++){
            if(primo == i){
                for(j=0;j<m;j++){
                    printf("%c",binario[i][j]);
                }
            }
        }
        for(i=0;i<n;i++){
            if(secondo == i){
                for(j=0;j<m;j++){
                    printf("%c",binario[i][j]);
                }
            }
        }
        printf("    Valore numerico della stringa di bit: %d\n",Carattere);

    }while(Carattere != 35);                        /*Il ciclo termina quando inserisco come ultimo carattere '#' e premo il testo invio.*/

    return 0;
}



/*Questa function mi serve per poter estrapolare e stampare a video la rappresentazione binaria del carattere dato in input.*/

void binary_code(unsigned char*c, unsigned char*t, unsigned char*v)
{
    *t= *c;
    *v= *c;

    *t= *t>>4;
    *v= *v<<4;
    *v= *v>>4;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int trova(char*,char*);


int main()
{
    char*stringa= "correndo, saltellando e sorseggiando felice ma poi mi sveglio e ho le pezze al culo";
    char*vocali= "aeiou";

    int find= trova(vocali,stringa);

    if(find <= 0)
        printf("Nessuna parola presente nella stringa contiene almeno cinque vocali.\n");
    else
        printf("Il numero di parole presenti nella stringa che contengono almeno cinque vocali sono: %d\n",find);

    return 0;
}



int trova(char*chiave,char*testo)
{
    int i,j,n,m,conta=0,conta_chiave=0;
    n= strlen(chiave);
    m= strlen(testo);

    /*
        Tengo fisso l'indice 'i' (testo) e scorro l'indice 'j' (vocali).
        Ad esempio, al primo ciclo scorro ogni carattere della stringa vocali sul primo carattere della prima parola della stringa testo.
        Cioè confronto il carattere 'a' di vocali con il carattere 'c' della parola "correndo". Se sono uguali (if(chiave[j] == testo[i])) allora incremento conta,
        altrimenti no.
        Poi confronto il secondo carattere di vocali (j=1) ovvero 'e' sempre con il carattere 'c' della parola "correndo". E così via per i restanti 3 caratteri della
        stringa vocali.

        Terminato il ciclo for interno, incremento i (i=1) e ora confronto il carattere 'a' di vocali con il carattere 'o' della parola "correndo". E così via.
        Terminato di confrontare ogni carattere di vocali con ogni singolo carattere della parola "correndo", arrivo al carattere 'spazio'.
        Essendo testo=='spazio' (if(testo[i]!= ' ' && testo[i]!= '\0')) eseguo l'else.

        N.B. testo[i]!='\0' mi serve quando nel ciclo for esterno i è == m, cioè al carattere terminatore, ed essendo testo[i]=='al terminatoe', viene eseguito l'else.
             Senza l'uguale a i<=m e alla seconda condizione del if: testo[i]!= '\0', non verrebbe considerato l'ultimo carattere del'ultima parola della stringa testo.
    */

    for(i=0;i<=m;i++){
        if(testo[i]!= ' ' && testo[i]!= '\0'){
            for(j=0;j<n;j++){
                if(chiave[j] == testo[i])
                    conta++;
            }
        }
        else{
            if(conta >= 5){
                conta_chiave++;
            }
            conta=0;
        }
    }
    return conta_chiave;
}

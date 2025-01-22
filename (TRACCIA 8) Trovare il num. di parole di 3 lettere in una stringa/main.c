#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num_parole(char*,char*);


int main()
{
    char*stringa= "Nel mezzo del cammin di nostra vit";
    char*chiave= "abc";

    int cont= num_parole(chiave,stringa);

    printf("Il numero di parole di tre lettere contenute nel testo e': %d\n",cont);

    return 0;
}



int num_parole(char*chiave,char*testo)
{
    int i,n,m,conta=0,conta_chiave=0;
    n=strlen(chiave);
    m=strlen(testo);

    /*Esempio:
      i=0; testo[i]= "N"; conta=1
      i=1; testo[i]= "e"; conta=2
      i=2; testo[i]= "l"; conta=3
      i=3; testo[i]= " "; conta=4

      testo[i]== 'spazio', Se quindi conta-1== 3 è uguale a n (è la lunghezza della chiave), n==3 quindi conta_chiave viene incrementato;
      Se conta-1 dovesse essere diverso da 'n', allora conta_chiave non viene incrementato.

      N.B. 'conta' tiene il conto del numero di caratteri di una parola compreso lo spazio o il terminatore se si arriava all'ultima parola della stringa,
            per questo il ciclo for termina con i<=m se fosse solo i<m il ciclo si fermerebbe al carattere 't' del ultima parola "vit", quindi non entra nel
            if(testo[i]==' ' || testo[i]=='\0') e di conseguenza con considererebbe questa parola per il conteggio.
            Invece con i<=m il ciclo for arriva fino al carattere terminatore "\0", quindi esegue l'if(testo[i]==' ' || testo[i]=='\0') e considera questa parola per
            verificare se conta-1 è == n.

    N.B. conta-1 perchè 'conta' conteggia anche lo spazio o il carattere terminatore se il ciclo arriva al ultima parola della stringa.
         Ad esempio: Con la prima parola della stringa: "Nel", conta==4 perchè conta anche lo spazio per poi eseguire l'if(testo[i]==' ' || testo[i]=='\0').
         Quindi faccio conta-1 in modo che 'conta' contenga esattamente la lunghezza della parola considerata.

    N.B. 'conta' viene azzerato solo se si entra in questo if(testo[i]==' ' || testo[i]=='\0')
    */

    for(i=0;i<=m;i++){
        conta++;
        if(testo[i]==' ' || testo[i]=='\0'){
            if(conta-1==n)
                conta_chiave++;
        conta=0;
        }
    }

    return conta_chiave;
}

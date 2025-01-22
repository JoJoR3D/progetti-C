#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int trova(char*,char*);


int main()
{
    char*stringa= "Vado di corsa perchè devo mangiare per poi tornare a lavorare";
    char*chiave= "are";

    int tot= trova(chiave,stringa);

    printf("Il numero di parole che terminano in 'are' nella stringa sono: %d\n",tot);

    return 0;
}



int trova(char*chiave,char*testo)
{
    int i,n,m,conta_chiave=0;
    n=strlen(chiave);           /*Ritorna la lunghezza di chiave che è 3*/
    m=strlen(testo);

    /*
     N.B. Eseguiamo un ciclo for che va da i=0 a i<=m-n. Cioè la dimensione è la lunghezza della stringa - la lunghezza della chiave, questo per evitare di far
          scorrere la chiave oltre la dimensione della stringa.
          Senza l'uguale ad i<=m-n il ciclo non arriva fino alla fine della stringa ma si ferma prima.
          Ad esempio se la chiave è lunga 3, scorre la chiave sulla stringa e salta gli ultimi 3 caratteri della stringa se non metto l'uguale.

     Per eseguire la ricerca della chiave solo sugli ultimi 3 caratteri di ogni parola della stringa 'testo' ho messo questo if di controllo:
     if(testo[i+3] == ' ' || testo[i+3] == '\0')
     Solo quando 'i+3' è uguale allo 'spazio' o al 'carattere terminatore' viene eseguito successivamente lo strncmp.

     Ad esempio:
     Al primo ciclo i=0; testo[0]= 'V' della parola 'Vado';
     if(testo[0+3] == ' ' || testo[0+3] == '\0')
        testo[3] corrisponde al carattere 'o' della parola 'Vado', non essendo == allo 'spazio' o al 'terminatore' NON si entra nel if e di conseguenza NON si esegue
        lo strncmp.

    Viene incrementato i e ci ritroviamo al secondo ciclo.
    Al secondo ciclo i=1; testo[1]= 'a' della parola 'Vado';
     if(testo[1+3] == ' ' || testo[1+3] == '\0')
        testo[4] corrisponde al carattere 'spazio' quindi si entra nel if e di conseguenza si esegue lo strncmp.

        if(strncmp(chiave,&testo[1],n)==0)
            Si esegue un confronto tra la chiave= "are" e la parola della stringa 'testo' con dimensione 'n'(che è uguale a tre).
            Quindi testo[1] e 'a' ha dimensione 1 deve essere 3, quinid 'ado' ora ha dimensione 3.
            Come detto eseguiamo  il confronto carattere per carattere tra la chiave: "are" e il testo: "ado".
            Non sono uguali quindi conta_chiave NON viene incrementato.

    Viene incrementato i e ci ritroviamo al terzo ciclo e così via.

    N.B. conta_chiave conta il numero di parole che terminano in "are" presenti nella stringa 'testo'.
    */

    for(i=0;i<=m-n;i++){
        if(testo[i+3] == ' ' || testo[i+3] == '\0'){
            if(strncmp(chiave,&testo[i/*+3*/],n)==0){
                conta_chiave++;
                /*i=i+3;*/
                printf("Posizione chiave nel testo: %d\n",i);   /*Ogni volta che la chiave è stata trovata nel testo, mi stampo l'indice 'i' che indica la posizione di partenza della chiave "are" nel testo.*/
        }
            }
    }
    return conta_chiave;
}

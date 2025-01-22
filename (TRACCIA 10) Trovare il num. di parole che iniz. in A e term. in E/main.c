#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int trova(char*,char*,char*);


int main()
{
    char*stringa= "Ancora non se se andare al mare o in montagna questa estate";
    char*chiave_in= "a";
    char*chiave_fin= "e";

    int tot= trova(chiave_in,chiave_fin,stringa);

    printf("Il numero di parole che iniziano per 'a' e terminano per 'e' sono: %d\n",tot);

    return 0;
}



int trova(char*chiave_i,char*chiave_f,char*testo)
{
    int i,n,m,v,conta_chiave=0;
    n=strlen(chiave_i);
    m=strlen(testo);
    v=strlen(chiave_f);

    /*
        if(testo[i-1] == ' ' || i == 0) cosa significa? testo[i-1] significa che se il carattere perecedente a i-1 è uno spazio vuol dire che ora 'i' è uguale ad un carattere
            che corrisponde al PRIMO carattere di una parola.
            Mentre i == 0 vale solo al primo ciclo. Se non mettessi i==0 ma solo testo[i] == 'spazio', in questo modo NON verrebbe considerata la prima parola del testo ("Ancora").

            Ad esempio:
            Primo ciclo i==0;
            if(testo[i-1] == ' ' || i == 0)
                testo[i-1] non è == 'spazio' ma i è == 0, quindi entro in questo if:
                if(strncmp(chiave_i,&testo[i],n)==0)
                    eseguo un confronto tra chiave_i che è 'a' e testo[i] che è 'A'. La strncmp non restituisce 0 perchè i due caratteri non sono uguali (uno è minuscolo
                    e l'altro è maiuscolo).


            Altro esempio:
            i==17 (ovvero corrisponde al carattere 'a' della parola "andare")
            if(testo[i-1] == ' ' || i == 0)
                testo[16] è == 'spazio' quindi posso entrare in questo if;
                    if(strncmp(chiave_i,&testo[i],n)==0)
                        eseguo un confronto tra chiave_i che è 'a' e testo[i] che è 'a'. La strncmp restituisce 0 perchè i due caratteri sono uguali.

                    Questo while serve per raggiungere l'ULTIMO carattere della parola considerata (in questo caso il carattere 'e' della parola "andare").
                    testo[i] != '\0' come seconda condizione del while serve quando raggiungo l'ultima parola.
                    Terminato il ciclo while i==23 è corrisponde al carattere 'spazio'.
                    if(strncmp(chiave_f,&testo[i-1],v)==0)
                        eseguo un confronto tra chiave_f che è 'e' e testo[23-1 ovvero: 22] che è 'e'. La strncmp restituisce 0 perchè i due caratteri sono uguali.
                        Di conseguenza conta_chiave viene incrementato.


        N.B. Eseguiamo un ciclo for che va da i=0 a i<=m-n. Cioè la dimensione è la lunghezza della stringa - la lunghezza della chiave, questo per evitare di far
          scorrere la chiave oltre la dimensione della stringa.
          Senza l'uguale ad i<=m-n il ciclo non arriva fino alla fine della stringa ma si ferma prima.
          Ad esempio se la chiave è lunga 3, scorre la chiave sulla stringa e salta gli ultimi 3 caratteri della stringa se non metto l'uguale.
    */

    for(i=0;i<=m-n;i++){
        if(testo[i-1] == ' ' || i == 0){
            if(strncmp(chiave_i,&testo[i],n)==0){
                while(testo[i] != ' ' && testo[i] != '\0'){
                    i++;
                }
                if(strncmp(chiave_f,&testo[i-1],v)==0)
                    conta_chiave++;                     /*contiene il num. di parole presenti nel testo che iniziano per il carattere 'a' e terminano per 'e'*/
            }
        }
    }
    return conta_chiave;
}

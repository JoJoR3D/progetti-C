#include <stdio.h>
#include <stdlib.h>

/*SPIEGAZIONE:
  Genero una struct con dei campi, poi nel main dichiaro un array di struct contenenti due valori:
  1 valore: nome,
            codice,
            prezzo;

  2 valore: nome,
            codice,
            prezzo;

  Creo una function void write che inserisce i valori nel array di struct e poi creo una function uguaglianza che controlla che ogni campo dei due valori del array
  siano uguali (ritorna 1) oppure no (ritorna 0)*/


struct prodotto{
    char*nome;
    int codice;
    int prezzo;
};

typedef struct prodotto Prodotto;



int uguaglianza(Prodotto[], int);
void write(Prodotto[], int);


int main()
{
    Prodotto merce[2] /*= {{"CD",127,20},{"CD",127,20}}*/;
    int n=2,i;
    Prodotto *punt;
    printf("Indirizzo del puntatore punt %d\nIndirizzo della variabile punt %d\n",*punt,punt);
    punt= &merce[0];
    printf("Indirizzo base del array merce %d %d\n\n",*punt,&merce[0]);

    write(merce,n);

    printf("\nRISTAMPA\n");
    for(i=0;i<n;i++)
        printf("1:%s %d %d\n",/*&merce[0]*//*merce*//*&merce[i]*/&(punt+i)->nome,(punt+i)->codice,(punt+i)->prezzo);/*La '&' per il nome indica l'indirizzo base dal quale stampare la stringa, infatti invece di &merce[0]
                                                                                                                      o di &merce[i] o di &(punt+i)->nome posso usare semplice mente il nome del array: merce che è esso stesso
                                                                                                                      indirizzo base del array.
                                                                                                                      Per accedere ai valori di codice e prezzo non uso la '&' perchè non sono stringhe ma valori interi.
                                                                                                                      Se usassi la'&', ad es: &(punt+i)->prezzo oppure &merce[i].prezzo (è la stessa cosa) mi stamperebbe la posizione in memoria della variabile prezzo.

                                                                                                                      &(punt+i)->prezzo si usa l'operatore freccetta perchè sarebbe : &(*punt+i).prezzo ma siccome questa scrittura non è consentita si usa l'operatore freccetta
                                                                                                                      e si elimina l'asterisco.

                                                                                                                      &merce[i].prezzo non ha bisogno del operatore freccetta perchè &merce[i] è l'indirizzo base del array quindi è la NOTAZIONE
                                                                                                                      STANDARD e no la NOTAZIONE A PUNTATORE come qui: &(punt+i)->prezzo */
    printf("\n");


    int valore= uguaglianza(merce,n);

    if(valore == 0)
        printf("ERRORE! %d",valore);
    else
        printf("UGUALI! %d",valore);

    return 0;
}



int uguaglianza(Prodotto a[], int n)
{
    int i;
    Prodotto *punt;
    Prodotto *punt1;
    punt= &a[0];
    punt1= &a[1];

    for(i=0;i<n;i++){
        if((punt+i)->nome != (punt1+i)->nome || (punt+i)->codice != (punt1+i)->codice || (punt+i)->prezzo != (punt1+i)->prezzo)
            return 0;
        else
            return 1;
    }
}



void write(Prodotto a[], int n)
{
    int i;
    Prodotto *punt;
    punt= &a[0];
    printf("Posizioni in memoria:\nIndirizzo base array merce primo elemento contenente(nome,codice,prezzo): %d\nIndirizzo base array merce secondo elemento contenente(nome,codice,prezzo): %d\nIndirizzo di memoria della voce prezzo del primo elemento: %d\nIndirizzo di memoria della voce prezzo del secondo elemento: %d\n\n",&a[0],&a[1],&(punt+0)->prezzo,&(punt+1)->prezzo);

    for(i=0;i<n;i++){
        printf("%d campo array:\n",i+1);
        printf("Inserisci stringa: ");
        scanf("%s",&(punt+i)->nome);
        fflush(stdin);
        printf("Inserisci codice: ");
        scanf("%d",&(punt+i)->codice);
        fflush(stdin);
        printf("Inserisci prezzo: ");
        scanf("%d",&(punt+i)->prezzo);
        fflush(stdin);
        printf("\nSTAMPA\n");
        printf("%s %d %d\n",&(punt+i)->nome,(punt+i)->codice,(punt+i)->prezzo); /* &(punt+i)->nome oppure &punt[i].nome oppure &a[i].nome è lo stesso*/
                                                                                /* Ad &(punt+i)->nome ci vuole la freccia e non l'operatore punto perchè sarebbe: &(*punt+i).nome non è consentito e quindi diventa &(punt+i)->nome*/
        printf("\n");
    }
}

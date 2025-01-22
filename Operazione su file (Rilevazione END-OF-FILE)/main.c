#include <stdio.h>
#include <stdlib.h>


/*Link Operazioni su file: https://www.diag.uniroma1.it//~liberato/struct/file/index.shtml*/



int main()
{
    /*Apro il File per scrivere il numero che indica quanti elementi conterrà il File*/

    int m,n,i;

    printf("Inserire quanti elementi si vogliono inserire nel file\n");
    scanf("%d",&m);

    FILE*fd;



    fd=fopen("File.txt","w");

    if(fd == NULL){
        printf("ERRORE!");
        exit(1);}


    fprintf(fd,"%d\n",m);


    fclose(fd);





    /*Riapro il File, questa volta, in append mode per scrivere consecutivamente un tot numero di elementi*/

    printf("\nInserire gli elementi:\n\n");

    for(i=0;i<m;i++){

    printf("Inserire %d elemento:\n",i);

    scanf("%d",&n);


    fd=fopen("File.txt","a");

    if(fd == NULL){
        printf("ERRORE!");
        exit(1);}


    fprintf(fd,"%d\n",n);


    fclose(fd);
    }





    /*Apro nuovamente il file per poter stampare gli elementi inseriti*/

    int x=100;
    int vet[x];
    int y;


    fd=fopen("File.txt","r");

    if(fd == NULL){
        printf("ERRORE!");
        exit(1);
    }

    fscanf(fd,"%d",&y);

    if(y >= x)
        printf("Il FILE contiene troppi elementi");
    else{
        for(i=0;i<y;i++)
            fscanf(fd,"%d",&vet[i]);}

    printf("\n\nStampo gli elementi presenti nel file\n");
    for(i=0;i<y;i++)
        printf("%d\n",vet[i]);

    fclose(fd);





    /*Apro nuovamente il file per verificare se ci sono altri elementi*/

    /*Rilevazione END-OF-FILE:
      Il programma di lettura di array da file non contiene nessun meccanismo di rilevazione di errori su file. Per esempio, non si accorge se il file è più corto del dovuto,
      ossia contiene meno elementi di quelli specificati come primo intero. Inoltre, non contiene nessun controllo sul fatto che il file potrebbe contenere dei caratteri, che quindi non sono interpretabili come interi.
      A seconda di come è specificato il formato del file da cui leggere, queste situazioni possono venire considerate o meno degli errori da parte di chi ha scritto il file. Per il momento, assumiamo che entrambe le situazioni vanno interpretate come errori.

      Il modo in cui le funzioni di accesso a file comunicano un eventuale errore è attraverso il valore di ritorno. Per esempio, errori in apertura del file si rilevano mettendo il valore di ritorno della funzione fopen in una variabile,
      e controllando il valore di questa variabile. Per le operazioni di lettura da file si usa lo stesso metodo: fscanf è in effetti una funzione che ritorna un valore intero, che indica se ci sono stati o meno degli errori in scrittura.
      Per controllare se ci sono stati errori, dobbiamo quindi memorizzare il valore di ritorno della funzione fscanf in una variabile, e poi controllare se il valore di questa variabile indica se ci sono stati errori.

      Per il momento, diciamo che la funzione fscanf ritorna il valore EOF nel caso in cui si è tentato di leggere qualcosa da un file, ma il file è già finito. In altre parole, se si è letto tutto il contenuto di un file,
      e si usa fscanf per leggere ancora, questa funzione ritorna il valore EOF. Questo EOF è una macro di cui non ci interessa il valore.

      Si noti che EOF è il valore di ritorno della funzione fscanf, e non il valore che viene memorizzato nelle variabili da leggere. In altre parole, se si vuole leggere un intero da file, controllando che non si sia arrivati alla fine del file,
      occorre controllare se il valore di ritorno di fscanf vale EOF.


      Il seguente programma legge un vettore da file. Ci si ferma solo nel caso in cui si sia arrivati a leggere cento elementi,
      oppure quando si cerca di leggere un intero ma il file è terminato. Si noti che, in questo caso, il numero iniziale che indica quanti interi ci sono su file non è necessario.
      Infatti, il numero di elementi letti viene determinato leggendo via via gli interi da file, incrementando ogni volta il numero di elementi letti fino a che non si arriva alla fine del file.

      In questo caso, se si incontra la fine del file, non si deve stampare un messaggio di errore.
      Infatti, la fine del file indica semplicemente che non c'è altro da leggere, ossia che siamo arrivati all'ultimo elemento del vettore. In questo caso, la fine del file viene usata per indicare quanti elementi da leggere ci sono.
      Al contrario, nel caso in cui si fosse per esempio specificato che il file deve contenere esattamente cento elementi, allora trovare EOF prima del centesimo elemento sarebbe stato un errore.
      Si può dire che incontrare la fine di un file durante una operazione di lettura può essere o non essere un errore, a seconda di come è stato specificato il formato del file.*/


    int res,c;

    fd=fopen("File.txt","r");

    if(fd == NULL){
        printf("ERRORE!");
        exit(1);
    }

    for(c=0;c<100;c++){
        res=fscanf(fd,"%d",&vet[c]);

        if(res == EOF)              /*Se res == EOF vuol dire che a quella posizione del file non ci sono più elementi e quindi interrompe il ciclo senza fallo arriavare alla fine,*/
            break;                  /*cioè a 100 che è la dimensione del array che deve contenere gli elementi del file*/


        printf("\n%d elemento: %d",c,vet[c]);   /*Ogni volta che viene letto un elemento dal file e inserito nel array vet tramite la fscanf, questo elemento del arrya vet poi viene stampato a video.
                                                  In questo modo evito di dover poi fare un altro ciclo for a parte per stampare l'array vet.*/
    }


    fclose(fd);

    return 0;
}

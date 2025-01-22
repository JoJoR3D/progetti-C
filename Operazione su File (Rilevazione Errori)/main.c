#include <stdio.h>
#include <stdlib.h>

/*LINK Operazione su File: https://www.diag.uniroma1.it//~liberato/struct/file/index.shtml


  Rilevazione errori:

  Oltre alla fine del file, esistono altri errori possibili quando si cerca di leggere da file. Alcuni errori sono dovuti per esempio a problemi di livello hardware,
  altri a livello di sistema operativo, ecc. Di questo tipo di errori non ci interessiamo.

  Un errore di cui invece parliamo è il fallimento di conversione. Quando si cerca di leggere da file un intero, la funzione fscanf deve convertire una stringa in
  intero. Infatti, un file di testo è una sequenza di caratteri, ossia una stringa. Se vogliamo un intero, dobbiamo convertire i caratteri che si trovano su file
  in un intero.

  Questa conversione non è sempre possibile. Si pensi per esempio alla situazione in cui su file sono memorizzati i caratteri abe mds. Questa sequenza non
  corrisponde a nessun intero. Se si cerca di leggere un intero, deve essere possibile capire che la conversione da stringa a intero è fallita.

  Errori di questo genere si riflettono sul valore di ritorno della funzione fscanf. Questa funzione, in generale, può leggere più di un oggetto per volta.
  Per esempio, può leggere, con una chiamata sola, un intero, una stringa, e un reale. Il valore di ritorno della funzione è il numero di oggetti che sono è stato
  possibile convertire. Il valore EOF viene ritornato solo nel caso in cui si è incontrata la fine del file prima ancora di riuscire a convertire anche un solo
  intero.

  La funzione fscanf ritorna il numero di oggetti che è stato possibile leggere (convertire da stringa al tipo dell'oggetto),
  oppure EOF se il file è finito prima di poter leggere il primo oggetto.


  Esempio fscanf ha i seguenti possibili valori di ritorno:

  fscanf(fd, "%d", &x);

  1
  un intero è stato letto e memorizzato in x;

  0
  non è stato possibile leggere l'intero, perchè quello che sta scritto su file non è interpretabile come un intero;

  EOF
  si è incontrata la fine del file prima di poter leggere un intero da memorizzare in x.

  Da questa schema è chiaro che, nel caso di lettura di un solo intero, è sempre possibile capire quale errore si è verificato semplicemente guardando il valore
  di ritorno della funzione fscanf.

  Questo programma è l'ultima versione del programma di lettura di un array da file. Questa volta è stato aggiunto un controllo sulla lettura: se la conversione
  in intero è fallita allora la funzione fscanf ritorna il valore 0, e in questo caso il programma termina.
  */


int main()
{
    int n= 100;
    int vet[n];
    int i,z,res;

    FILE*fd;

    fd=fopen("File.txt","r");

    if(fd == NULL){
        printf("ERRORE!\n");
        exit(1);
    }

    fscanf(fd,"%d",&z);

    if(n < 100)
        printf("Troppi elementi da memorizzare nel array vet\n");
    else{
        for(i=0;i<z;i++){
            res=fscanf(fd,"%d",&vet[i]);
            printf("RES: %d\n", res);       /*fscanf può dare come valori di ritorno: 0,1,o EOF*/
            if(res==EOF)
               break;
            else if(res==0){
                printf("Non riesco a leggere un intero da file\n");
                exit(1);}
            }
    }

    printf("\n\nRES: %d", res);

    for(i=0;i<z;i++)
        printf("\n%d",vet[i]);

    fclose(fd);

    return 0;
}

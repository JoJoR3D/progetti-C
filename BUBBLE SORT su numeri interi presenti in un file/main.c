#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bubble_sort(int*, int*);

int main()
{
    char file[]= "file.dat";
    int dim=10, valore, i=0;

    /*---------------Scrittura di 10 valori nel file generati casualmente ---------------*/

    FILE*x;
    x=fopen(file,"w");

    if(x == NULL){
        printf("Si e' verificato un errore\n");
        exit(1);
    }

    srand(time(NULL));

    while(i < dim){
        valore= rand()%10;
        fwrite(&valore,sizeof(int),1,x);
        printf("%d elemento del file: %d\n",i+1,valore);
        i++;
    }

    fclose(x);





    /*---------------Esecuzione del Bubble Sort ---------------*/

    FILE*k;
    k=fopen(file,"r+");                        /*Apro il file in lettura e scrittura*/
    int stato=1,flag=1,posizione;
    int ele[dim];

    if(k == NULL){
        printf("Si e' verificato un errore\n");
        exit(1);
    }

    /*
        Se stato è ==0 vuol dire che non stati fatti scambi. Quando viene eseguito uno scambio, il flag viene incrementato.
        N.B.: Quando i è >= dim-1 (non ci sono più dati da controllare) e flag è > di 0 vuol dire che tutti gli elementi sono stati ordinati.

        Procedimento:
        1) Leggo, tramite l'fread() due elementi per volta (ad ele[i] assegno il primo elemento e ad ele[i+1] assegno il secondo elemento letto);
        2) Chiamo al funzione bubble_sort() che mi ritorna stato=1 se il primo elemento 'i' è > del secondo elemento 'i+1', altrimenti ritorna stato=0;
        3) Se stato è==1, poichè dopo ogni freed(), questa funzione sposta in automatico il cursore (puntatore) sul elemento successivo del file,
           uso fseek() per ritornare indietro di due interi in modo da poter scambiare i due valori.
           (due interi perchè chiamo freed due volte. Dopo il primo freed() il cursore punta al secondo elementodel file; mentre dopo il secondo freed()
           il cursore punta al terzo elemento del file)(Ricorda che ogni intero occupa 4byte, 4*2=8byte cioè due interi).
        4) Dopo essere ritornato, tramite l'fseek(), al primo elemento del file sostituisco, tramite fwrite(), il primo elemento del file con il secondo elemento
           del file (salvato in ele[i+1]), poi poichè dopo ogni ferite() il cursore (puntatore) viene spostato sul elemento successivo del file,
           ora punto al secondo elemento, e sostituisco questo con il primo elemento (salvato in ele[i]).

        5) incremento la i++; Ora i è == 1.

        6) N.B.
           Come detto, freed() e fwrite(), dopo aver letto o scritto un valore ad una posizione in automatico spostano il cursore di una posizione in avanti,
           in modo da puntare al elemento successivo del file.
           Quindi dopo i due fwrite(), il cursore si trova al terzo elemento del file.

           Ma poichè il successivo confronto deve essere eseguito tra il secondo e il terzo elemento del file, uso fseek() per spostare il cursore al secondo
           elemento del file fseek(s,4*i,SEEK_SET).

           N.B.
           SEEK_SET è un comando che serve per spostare il cursore alla posizione iniziale del file.
           Ritorno alla posizione iniziale (SEEK_SET) e poi per andare avanti(cioè al prossimo valore presente nel file)
           moltiplico i byte occupati da un solo intero (4byte) per il valore 'i'.

           Quindi:
           fseek(s,4*i,SEEK_SET) dove 4*1= 4byte ovvero il secondo elemento del file.


            Esempio:
            Su un file contenente 5 interi i confronti effettuati ad ogni ciclo saranno:
            1) 1 elemento con 2 elemento;
            2) 2 elemento con 3 elemento;
            3) 3 elemento con 4 elemento;
            4) 4 elemento con 5 elemento;




        7) Incremento flag ogni qual volta stato è == 1.

           Esempio:
           Primo elemento del file: 8;
           Secondo elemento del file: 5;

           8>5?SI, stato=1;
           Fseek()per portare il puntatore al primo elemento (8);
           Fwrite()per sostiruire il primo elemento (8) con il secondo elemento del file (5);
           L'fwrite() di prima sposta il puntatore al secondo elemento del file;
           Tramite l'altro fwrite() sostituisco il secondo elemento del file (5), con il primo elemento (8);

           Ora gli elementi del file sono così ordinati:
           Primo elemento del file: 5;
           Secondo elemento del file: 8;


         8) Se stato è ==0 e NO ==1, prima cosa incremento i++; Ora i è == 1.
            Poi se stato è==0 (non avvieno lo scambio tra i due elementi), quindi al termine del secondo freed() il cursore viene spostato al terzo elemento del file.
            Tramite fseek(), sposto il cursore indietro di un intero per puntare al secondo elemento poichè il prosimo confronto deve essere tra il secondo
            e terzo elemento del file. (fseek(s,4*i,SEEK_SET))
            Per fare questo porto il cursore al primo elemenot del file (SEEK_SET), poi mi sposto di un intero e moltiplico i byte occupati da
            un solo intero (4byte) per il valore 'i'.

            Esempio:
            Ho eseguito il confronto tra il primo e secondo elemento del file. Dopo i due freed() il cursore viene spostato al terzo elemento del file.
            Ma poichè il successivo confronto deve essere eseguito tra il secondo e il terzo elemento del file, uso fseek() per spostare il cursore al secondo
            elemento del file fseek(s,4*i,SEEK_SET) (COME FATTO AL PUNTO 6).


        9) Se ho eseguito il confronto tra tutti gli elementi del file (i>=dim-1), però flag è > di 0 ciò vuol dire che è stato eseguito uno scambio tra due elementi del
           file, quindi è probabile che gli elementi del file non siano ancora ordinati in maniera crescente.
           Allora tramite fseek() mi riporto al primo elemento del file (fseek(k,0,SEEK_SET)), poi pongo i=0 e flag=0;

        10) Il ciclo while termina quando i è >= di dim-1, flag è > di 0.
            Quando si sono controllati tutti gli elementi del file (i>=dim-1) e non sono stati eseguiti scambi (flag==0) vuol dire che tutti gli elementi del file
            sono stati ordinati e quindi il programma può terminare.
    */

    i=0;
    while(i < dim-1 || flag > 0){
        printf("\nFTELL %d\n",posizione=ftell(k)); /*Mi ritorna un intero (espresso in byte) che indica la posizione del cursore nel file.
                                                     Ad esempio se ritorna 12, vuol dire che il cursore si trova al 4 intero del file.
                                                     Se, ad esempio, mi ritornava 4, vuol dire che il cursore si trova al 2 elemento del file.*/
        fread(&ele[i],sizeof(int),1,k);
        fread(&ele[i+1],sizeof(int),1,k);
        printf("ELE: %d, ELE1: %d\n",ele[i],ele[i+1]);

        stato=bubble_sort(&ele[i],&ele[i+1]);
        /*printf("Stato: %d\n",stato);*/

        if(stato == 1){
            fseek(k,-8,SEEK_CUR);               /*SEEK_CUR è un comando che serve per spostare il cursore alla posizione desiderata.*/
            fwrite(&ele[i+1],sizeof(int),1,k);
            fwrite(&ele[i],sizeof(int),1,k);
            i++;
            fseek(k,4*i,SEEK_SET);
            flag=flag+1;
        }
        else{
            i++;
            fseek(k,4*i,SEEK_SET);          /*SEEK_SET è un comando che serve per spostare il cursore alla posizione iniziale del file.
                                              Ritorno alla posizione iniziale (SEEK_SET) e poi moltiplico i byte occupati da un solo
                                              intero (4byte) per il valore 'i'.
                                            */
        }

        if(i>=dim-1 && flag>0){
            fseek(k,0,SEEK_SET);            /*SEEK_SET è un comando che serve per spostare il cursore alla posizione iniziale del file.*/
            i=0;
            flag=0;
            printf("\nFINE ciclo\n\n");
        }
    }

    fclose(k);





    /*---------------Lettura del file contenente i dati ordinati in seguito al Bubble sort---------------*/

    printf("\n\n");
    FILE*q;
    q=fopen(file,"r");

    if(q == NULL){
        printf("Si e' verificato un errore\n");
        exit(1);
    }

    i=0;
    while(i < 10){
        fread(&valore,sizeof(int),1,q);
        printf("Dati ordinati: %d\n",valore);
        i++;
    }

    fclose(q);

    return 0;
}





int bubble_sort(int*x, int*y)
{
    if(*x > *y)
        return 1;
    else
        return 0;
}

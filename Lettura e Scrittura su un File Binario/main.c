#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void scambio(int*, int*);
int bubble_sort(int*, int*);

int main()
{
    /*-------------------------------------------------ESERCIZIO 1---------------------------------------------------------------*/

    /*---------------Scrittura su file---------------*/
    FILE*fd;
    int x=17;

    fd=fopen("file.dat","w");       /*.dat indica un tipo di file generico che può contenere un qualsiasi tipo di dato*/

    if(fd == NULL){
        printf("Si e' verificato un'errore\n");
        exit(1);
    }

    fwrite(&x,sizeof(int),1,fd); /*
                                    &x: indirizzo della variabile contenete il valore da scrivere sul file binario;
                                    sizeof(int): numero di byte occupati in memoria dal dato;
                                    1: numero di elementi da scrivere sul file;
                                    fd: descrittore del file.
                                 */

    fclose(fd);




    /*---------------Lettura del file---------------*/
    FILE*fc;
    int y;

    fc=fopen("file.dat","r");

    if(fc == NULL){
        printf("Si e' verificato un'errore\n");
        exit(1);
    }

    fread(&y,sizeof(int),1,fc);

    printf("Esercizio 1\n%d",y);

    fclose(fc);









    /*-------------------------------------------------ESERCIZIO 2---------------------------------------------------------------*/

    /*---------------Scrittura di più elementi su file---------------*/
    char file[]="file1.dat";
    int a[]= {10,15,19,24,25};
    int n=5,i;

    FILE*fx;

    fx=fopen(file,"w");

    if(fx == NULL){
        printf("Si e' verificato un'errore\n");
        exit(1);
    }

    for(i=0;i<n;i++)
        fwrite(&a[i],sizeof(int),n,fx); /*
                                            &a[i]: indirizzo base array che contiene i valori da scrivere sul file binario;
                                            sizeof(int): numero di byte occupati in memoria dal dato;
                                            n: numero di elementi da scrivere sul file;
                                            fx: descrittore del file.
                                        */

    fclose(fx);





    /*---------------Lettura di più elementi da file---------------*/
    printf("\n\n");
    FILE*fy;

    fy=fopen(file,"r");

    if(fy == NULL){
        printf("Si e' verificato un'errore\n");
        exit(1);
    }

    /*La funzione feof ritorna 0 se non è stata raggiunta la fine del file, altrimenti restituisce un valore diverso da zero.*/

    printf("Esercizio 2\n");
    while(!feof(fy)){                   /*Legge un file fino alla fine*/
        fread(&a[i],sizeof(int),n,fy);
        printf("%d\n",a[i]);
    }

    fclose(fy);












    /*-------------------------------------------------ESERCIZIO 3---------------------------------------------------------------*/

    /*---------------Scrittura di più elementi su file---------------*/
    char File[]="file2.dat";
    int A[]= {23,19,39,44,95};
    int m=5;

    FILE*fv;

    fv=fopen(File,"w");

    if(fv == NULL){
        printf("Si e' verificato un'errore\n");
        exit(1);
    }

    for(i=0;i<m;i++)
        fwrite(&A[i],sizeof(int),m,fv); /*
                                            &a[i]: indirizzo base array che contiene i valori da scrivere sul file binario;
                                            sizeof(int): numero di byte occupati in memoria dal dato;
                                            n: numero di elementi da scrivere sul file;
                                            fx: descrittore del file.
                                        */
    fclose(fv);






    /*---------------Lettura di più elementi da file e li passa ad un array---------------*/
    printf("\n\n");
    int c[m];
    FILE*f;

    f=fopen(File,"r");

    if(f == NULL){
        printf("Si e' verificato un'errore\n");
        exit(1);
    }

    fread(c,sizeof(int),m,f);       /*Legge tutti i valori presenti nel file aperto e li passa all'array 'c'.*/

    fclose(f);

    printf("Esercizio 3\n");
    for(i=0;i<m;i++)                /*Stampo a schermo i valori memorizzati nell'array 'c'.*/
        printf("%d\n",c[i]);















    /*-------------------------------------------------ESERCIZIO 4---------------------------------------------------------------*/

    /*---------------Scrittura di elementi generati casualmente su file---------------*/
    printf("\n\n");

    srand(time(NULL));
    char file3[]= "file3.dat";
    int dim=10;
    int var[dim];

    FILE*T;

    T=fopen(file3,"w");

    if(T == NULL){
        printf("Si e' verificato un errore\n");
        exit(1);
    }

    for(i=0;i<dim;i++){
        var[i]= rand()%10;
        fwrite(&var[i],sizeof(int),1,T);
    }

    fclose(T);




    /*---------------Lettura degli elementi di un file passati a una variabile tramite un ciclo while---------------*/

    FILE*L;

    L=fopen(file3,"r");

    if(L == NULL){
        printf("Si e' verificato un errore\n");
        exit(1);
    }

    printf("Esercizio 4\n");
    i=0;
    while(i<dim){
        fread(&var[i],sizeof(int),1,L);
        printf("%d\n",var[i]);
        i++;
    }

    fclose(L);














    /*-------------------------------------------------ESERCIZIO 5---------------------------------------------------------------*/

    /*---------------Lettura e Scrittura contemporanea su file---------------*/

    /*printf("\n\n");
    int var1,var2;
    FILE*p;

    p=fopen(file3,"r+");

    printf("Esercizio 5\n");
    i=0;
    while(i < dim){
        fread(&var1,sizeof(int),dim,p);
        printf("Valore letto: %d\n",var1);
        var2= var1*2;

        fwrite(&var2,sizeof(int),dim,p);
        printf("Valore raddoppiato e scritto su file: %d\n",var2);
        printf("\n");
        i++;
    }

    fclose(p);*/

    /*
        A prima vista, può sembrare che questo programma raddoppia tutti i numeri del file. Quello che succede, invece, è che tutti i numeri in posizione pari
        (il secondo, il quarto, ecc) sono stati sostituiti dal doppio del numero che li precede (per esempio, nella seconda posizione ora c'è il doppio del primo
        numero).

        Per analizzare il motivo di questo comportamento, occorre introdurre un concetto nuovo, che è quello di posizione all'interno del file.

        L'effetto della operazione di lettura fread(&var1, sizeof(int), dim, p) è quello di leggere i primo quattro byte del file e metterli in una variabile
        intera (il numero di byte letti dipende ovviamente dal tipo della variabile). Questa operazione di lettura ha anche l'effetto di spostare la posizione
        corrente all'interno del file in avanti, al primo byte che segue quelli letti.

        La lettura del secondo elemento ha ancora come effetto quello di spostare la posizione corrente in avanti.

        Per essere precisi, possiamo dire che l'operazione di lettura si comporta come segue:
        1)legge il dato che si trova a partire dalla posizione corrente.
        2)sposta la posizione corrente in avanti, al primo byte che segue quelli letti.

        Questo descrive cosa fa esattamente l'operazione di lettura. Il motivo per cui due successive operazioni di lettura leggono i dati in sequenza è che la
        prima, dopo aver letto, sposta la posizione in avanti, per cui la seconda operazione legge il secondo dato e non legge di nuovo il primo.

        La stessa cosa succede quando si scrive: dopo aver scritto qualcosa, la posizione corrente avanza ancora. In altre parole, se si apre un file in scrittura,
        la posizione corrente è all'inizio del file. Quando si scrive, si scrive a partire dalla posizione corrente, e la posizione viene spostata nello stesso
        modo della lettura. Questo è il motivo per cui, quando si fanno più operazioni di scrittura su file, le cose vengono scritte in sequenza: in realtà,
        la funzione fwrite scrive sempre a partire dalla posizione corrente, solo che avanza questa posizione dopo aver scritto. Questo fa sí che la successiva
        operazione di scrittura scriva di seguito invece di sovrascrivere il dato scritto prima.

        Vediamo ora cosa succede quando si esegue il programma di sopra. Supponiamo che nel file siano scritti, in forma binaria, i tre numeri 12, 9 e 28.
        Quando si apre, la posizione corrente è all'inizio del file:

        1)Si legge il primo intero a partire dalla posizione corrente, e si sposta in avanti la posizione. Ora x vale quanto letto da file, cioè 12.

        2)Si assegna a var2 il doppio del valore di var1, cioè 24. Questo numero viene scritto in forma binaria nel file. La scrittura avviene a partire dalla posizione
        corrente, e sposta in avanti la posizione corrente. In questo momento, la posizione corrente è sopra il quinto byte del file, ed è a partire da questa
        posizione che si va a scrivere. La posizione avanza ancora di quattro, dato che si sta scrivendo un intero.

        3)Ora si legge un intero, a partire dalla posizione corrente, per cui si legge 48. Si sposta la posizione corrente, che ora è sulla fine del file.

        4)Il numero che si va a scrivere sul file è il doppio di quello letto, per cui si scrive 96. Questo numero viene scritto sotto la posizione corrente
        del file, e quindi si aggiungono quattro byte in coda al file. Lo stato del file alla fine è il seguente:

        5)A questo punto si cerca di leggere di nuovo, ma l'operazione fallisce perchè il file è finito. (anche se nel mio programma, una volta arrivato alla fine
          del file, ricomincia dall'inizio e prosegue fin quando 'i' non è >= di 'dim'.
          dim è 10 perchè nel file3 ci sono 10 valori generati casualmente (fatto nel esercizio 4)., però poichè ad ogni operazione di raddoppio del valore letto,
          come detto, la sua scrittura sovrascrive il valore presente alla posizione corrente e al termine della scrittura il cursore si posiziona al valore presente
          dopo quello scritto, e come se leggesse solo 5 valori (perchè ad ogni scrittura salta un valore, come detto, legge solo i valori alla posizione pari) su 10
          e poichè per terminare il ciclo 'i' deve essere >= di 'dim', arrivato all'ultimo valore del file, il cursore si riposiziona all'inizio del file e continua
          così finquando 'i' non sarà >= di 'dim'

        RICAPITOLANDO:
        L'effetto che ne risulta è che il programma legge un numero, poi lo raddoppia e poi lo scrive. Però la scrittura avviene sulla posizione corrente dopo
        la lettura, per cui si scrive il doppio sulla posizione successiva. Quindi, per esempio, viene letto il primo numero e il doppio viene scritto sul secondo.

        L'esercizio 6 ci mostra come riposizionare il cursore su un file.
    */











     /*-------------------------------------------------ESERCIZIO 6---------------------------------------------------------------*/

    /*---------------Lettura e Scrittura contemporanea su file e modifica posizione cursore---------------*/

    /*
        Le operazioni di lettura e scrittura hanno come effetto quello di spostare la posizione corrente nel file. È però anche possibile spostare la posizione
        corrente in modo arbitrario, senza leggere e scrivere. La funzione che si usa si chiama fseek.
    */

    printf("\n\n");
    int var1[dim];

    FILE*s;
    s=fopen(file3,"r+");            /*Apro il file il lettura e scrittura*/

    printf("Esercizio 6\n");
    i=0;
    while(i < dim){
        fread(&var1[i],sizeof(int),1,s);
        printf("Valore letto: %d\n",var1[i]);
        var1[i]= var1[i]*2;

        fseek(s,-4,SEEK_CUR);   /*Terminato di leggere il valore intero tramite fread(), questa mi porta in automatico sul secondo intero, ma poicheè devo cambiare il
                                  primo valore letto con il suo doppio, ritorno indietro di 4byte (-4 perchè un int in memoria occupa 4byte).
                                */

        fwrite(&var1[i],sizeof(int),1,s);
        printf("Valore raddoppiato e scritto su file: %d\n",var1[i]);
        printf("\n");

        i++;
        fseek(s,4*i,SEEK_SET);  /*Ritorno alla posizione iniziale (SEEK_SET) e poi per andare avanti (cioè ai prossimi valori presenti nel file)
                                  moltiplico i byte occupati da un intero (4) per il valore 'i'.

                                  Se i=0, quando comincio a leggere il file sono già posizionato sul primo intero.
                                  Se i=1, vuol dire che mi sto spostando sul secondo intero del file (4*1=4byte);
                                  Se i=2, vuol dire che sto sul terzo intero del file (4*2=8byte);
                                  e così via....
                                  Questo perchè ogni intero in binario occupa 4 byte, quindi da 1 a 4 byte vuol dire che sto selezionando il primo intero;
                                  da 5 a 8 byte vuol dire che sto selezionando il secondo intero;
                                  da 9 a 12 byte vuol dire che sto selezionando il terzo intero;
                                  e così via....

                                  Quindi 4byte vuol dire che sto selezionando il primo intero.
                                  Quindi 8byte vuol dire che sto selezionando il secondo intero.
                                  Quindi 12byte vuol dire che sto selezionando il terzo intero.
                                  e così via....

                                  N.B.
                                  freed() e fwrite(), dopo aver letto o scritto un valore ad una posizione in automatico spostano il cursore di una posizione in avanti,
                                  ma in questo esercizio, dopo aver letto il secondo valore del file, non vanno avanti a leggere gli altri valori ma leggono sempre il
                                  secondo valore. Per questo mi sposto usando questa fseek(s,4*i,SEEK_SET) .
                                */
    }

    fclose(s);





    /*---------------Lettura file---------------*/

    printf("\n\n");
    FILE*w;
    int u;
    w=fopen(file3,"r");

    if(w == NULL){
        printf("Si e' verificato un erorre\n");
        exit(1);
    }

    printf("Lettura dei dati raddoppiati\n");
    i=0;
    while(i < dim){
        fread(&u,sizeof(int),1,w);
        printf("%d\n",u);
        i++;
    }

    fclose(w);











    /*-------------------------------------------------ESERCIZIO 7---------------------------------------------------------------*/

    /*---------------Scambio elementi a coppie---------------*/

    /*
        Risolviamo il seguente esercizio: dato un file binario che contiene una sequenza di numeri interi, scambiare il primo intero con il secondo,
        il terzo con il quarto, ecc.
    */

    /*---------------Scrittura casuale dei dati nel file-------------------*/

    printf("\n\n");
    char file4[]="file4.dat";
    int dimens= 10, V, V1;
    FILE*o;

    o=fopen(file4,"w");

    if(o == NULL){
        printf("Si e' verificato un errore/n");
        exit(1);
    }

    printf("Esercizio 7\n");
    i=0;
    while(i < dimens){
        V= rand()%10;
        fwrite(&V,sizeof(int),1,o);
        printf("Valori inseriti casualmente: %d\n",V);
        i++;
    }

    fclose(o);




    /*---------------Lettura e scambio dei dati nel file-------------------*/

    FILE*r;
    r=fopen(file4,"r+");

    if(r == NULL){
        printf("Si e' verificato un errore\n");
        exit(1);
    }

    printf("\n");
    i=0;
    dimens= dimens/2;                                   /*Dimezzo la dimensione perchè leggo due elementi alla volta*/
    while(i < dimens){
        fread(&V,sizeof(int),1,r);
        fread(&V1,sizeof(int),1,r);

        /*scambio(&V,&V1);*/                                /*Scambio i due elementi letti*/
        fseek(r,-8,SEEK_CUR);

        fwrite(&V1,sizeof(int),1,r);
        fwrite(&V,sizeof(int),1,r);

        i++;
        fseek(r,8*i,SEEK_SET);  /*Come fatto nel esercizio 6, ritorno alla posizione iniziale (SEEK_SET) e poi per andare avanti(cioè ai prossimi valori presenti nel file)
                                  moltiplico i byte occupati da due interi (4+4=8) per il valore 'i'.
                                  Du einteri perchè leggo due numeri alla volta.

                                  N.B.
                                  freed() e fwrite(), dopo aver letto o scritto un valore ad una posizione in automatico spostano il cursore di una posizione in avanti,
                                  ma in questo esercizio, dopo aver letto il secondo valore del file, non vanno avanti a leggere gli altri valori ma leggono sempre il
                                  secondo valore. Per questo mi sposto usando questa fseek(s,4*i,SEEK_SET).
                                */

    }

    fclose(r);






    /*---------------Lettura del file con i dati scambiati-------------------*/

    printf("\n\n");
    FILE*e;
    e=fopen(file4,"r");

    if(e == NULL){
        printf("Si e' verificato un errore\n");
        exit(1);
    }

    i=0;
    while(i < 10){
        fread(&V,sizeof(int),1,e);
        printf("Lettura valori dopo lo scambio: %d\n",V);
        i++;
    }

    fclose(e);
















    /*-------------------------------------------------ESERCIZIO 8---------------------------------------------------------------*/

    /*---------------Bubble sort su elementi presenti in un file (ordinare in maniera crescente)---------------*/

    printf("\n\n\nEsercizio 8\n");
    FILE*k;
    k=fopen(file4,"r+");                        /*Apro il file in lettura e scrittura*/
    int stato=1,flag=1;
    int ele[dim],posizione;

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
        printf("Stato: %d\n",stato);

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

    printf("\n");
    FILE*q;
    q=fopen(file4,"r");

    if(q == NULL){
        printf("Si e' verificato un errore\n");
        exit(1);
    }

    i=0;
    while(i < dim){
        fread(&V,sizeof(int),1,q);
        printf("Dati ordinati: %d\n",V);
        i++;
    }

    fclose(q);























    /*-------------------------------------------------ESERCIZIO 9---------------------------------------------------------------*/

    /*---------------Trova il massimo e sostituisce il valore con Zero---------------*/

    /*SVOLTO IN UN FILE A PARTE*/


    return 0;
}















int bubble_sort(int*x, int*y)
{
    if(*x > *y)
        return 1;
    else
        return 0;
}



void scambio(int*x, int*y)
{
    int t;
    t=*x;
    *x=*y;
    *y= t;
}

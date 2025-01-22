#include <string.h>

/*
    N.B.
    il file "t1.txt" contiene l'indice del'acqua;
    il file "t2.txt" contiene il ciclo;
    il file "text.txt" contiene i valori generati casualmente.
*/


/*Cerca nel file: Nome_utente (file che contiene tutti i nomi dei player che si sono registrsti) i nomi dei player.
  Se il nome inserito è già presente nel file (vuol dire che questo nickname è stato già usato), la function ritorna flag=1;
  invece se il nome non è stato trovato nel file (vuol dire che questo nickname non è stato mai ustato) allora la function ritorna flag=0.
*/

int find_name(char string[])
{
    char s[50];
    int flag=0;

    FILE*fc;
    fc=fopen("Nome_utente.txt","r");

    if(fc == NULL){
        printf("\nSi e' verificato un errore\n");
        exit(1);
    }

    while(!feof(fc)){
        fscanf(fc,"%s",s);
        if(strcmp(s,string)==0)
            flag=1;
    }

    return flag;
}



/*Mostra l'elenco dei nickname registrati degli utenti (sono presenti nel file: Nome_utente).*/

void view_name()
{
    char s[50];

    FILE*fc;
    fc=fopen("Nome_utente.txt","r");

    if(fc == NULL){
        printf("\nSi e' verificato un errore\n");
        exit(1);
    }

    printf("Elenco nomi utenti gia' utilizzati\n");
    while(!feof(fc)){
        fscanf(fc,"%s",s);
        printf("%s\n",s);
    }
}



/*Scrive nel file: Nome_utente (file che contiene tutti i nomi dei player che si sono registrsti) il nuovo nickname.*/

void write_name(char string[])
{
    FILE*fc;
    fc=fopen("Nome_utente.txt","a");

    if(fc == NULL){
        printf("\nSi e' verificato un errore\n");
        exit(1);
    }

    fprintf(fc, "\n%s", string);
    fclose(fc);
}



/*Se si inserisce un nuovo nickname (nuovo player), allora viene creato un file con lo stesso nome del nickname.
  Questo file conterrà quante partite ha vinto il player.
*/

void new_player(char string[])
{
    int p=0;

    FILE*fc;
    fc=fopen(string,"a");

    if(fc == NULL){
        printf("\nSi e' verificato un errore\n");
        exit(1);
    }

    fprintf(fc, "%d", p);
    fclose(fc);
}



/*Scriverà il nuovo punteggio nel file del player che ha disputato la partita solo se il player ha vinto la partita.*/

void write_score(char string[])
{
    int p=0;

    FILE*fc;
    fc=fopen(string,"r");

    if(fc == NULL){
        printf("\nSi e' verificato un errore\n");
        exit(1);
    }

    fscanf(fc, "%d", &p);
    fclose(fc);

    p=p+1;              /*Incremento il punteggio del player. Ad esempio se era 2 (cioè 2 partite vinte), ora diventerà 3 (cioè 3 partite vinte).*/

    FILE*fd;
    fd=fopen(string,"w");

    if(fd == NULL){
        printf("\nSi e' verificato un errore\n");
        exit(1);
    }

    fprintf(fd, "%d", p);
    fclose(fd);
}

/*
void let_name(char string[], int*flag, int*p)
{
    *flag=0;
    char s[50];
    int i=0;

    FILE*fc;
    fc=fopen("Nome_utente.txt","r+");

    if(fc == NULL){
        printf("\nSi e' verificato un errore\n");
        exit(1);
    }

    while(!feof(fc)){
        fscanf(fc,"%s",s);
        if(strcmp(s,string)==0){
            fscanf(fc,"%d",p);
            printf("\n\ntreno %s %d\n\n",s,*p);
            *flag=1;
        }
    }

    fclose(fc);
}



void NewScore(int pos, int p)
{
    printf("\n\nPO %d\n\n",pos);
    FILE*fc;
    fc=fopen("Nome_utente.txt","w");

    if(fc == NULL){
        printf("\nSi e' verificato un errore\n");
        exit(1);
    }

    while(!feof(fc)){
        fscanf(fc,"%s",s);
        if(strcmp(s,string)==0)
            putw(p,fc);
    }

    fclose(fc);
}
*/



/*Quando inizio la partita (ciclo == 0), mi viene chiesto se sono un nuovo utente, o se mi sono già registrato in precedenza. Rispondo (scelta) 1 per SI e
  (scelta) 2 per NO.
  Se premo 1 (scelta == 1) allora mi verrà richiesto di inserire il mio nome utente che ho già usato in precedenza. Se ho sbagliato ad inserire il
  nome utente il flag viene impostato a 1 per rimanere nel ciclo perchè find_name ritorna flag=0 quando non trova il nickname nel file. E repeat
  viene impostato =0 per evitare che venga pitetuta la domanda: "E' un'utente gia' registrato? Risponda 1 per SI! e 2 per NO!".
  In questo modo potrò riporovare fin quando non inserisco il nome utente corretto (tutti i nomi utenti registrati si trovano nel file: Nome_utente
  e ogni utente ha un prprio file che contiene il proprio punteggio).

  Se invece premo 2 (scelta == 2) allora mi verrà richiesto di inserire il nickname che vorrò usare per la partita.
  Scritto il nickname, verrà eseguito una ricerca nel file: Nome_utente tramite la function find_name questo per controllare se il nickname inserito
  è stato già usato da un altro utente. Se find_name ritorna flag==0 vuol dire che il nickname non è stato trovato nel file (quindi non è stato mai
  usato), quindi questo nickname verrà scritto nel file: Nome_utente tramite la function write_name e poi verrà creato un nuovo file con lo stesso
  nome del nickname tramite la function new_player che conterrà il punteggio del utente (ovverro quante partite ha vinto).
  Invece se find_name ritrona flag==1 vuol dire che il nickname inserito è stato già utilizzato, quindi dovrò inserire un nickname diverso.

  Inoltre se sbaglio ad inserire il nome utente sia con scelta uguale a 1 o 2, tramite la function view_name(), vengono mostrati i nickname già
  utilizzati e salvati nel file: Nome_utente.
  In questo modo è più facile per l'utente recuperare il proprio nick (se non lo ricorda), o crearne uno nuovo.

  Una volta inserito il nome utente verrà richiesto: "Salve, desidera un po' d'acqua?". Ai cicli successivi (ciclo > 0) verrà richiesto:
  "Desidera ancora un po' d'acqua?"
  A queste domande si risponde 1 per confermare e 2 per negare.
  Se si seleziona 1, verrà stampato: SI!. Se invece si seleziona 2, verrà stampato: NO! e il gioco termina mostrando se il giocatore ha vinto o
  perso la partita.

  N.B.
  Sono quando il ciclo è == 0, alla domada: "Salve, desidera un po' d'acqua?" Si potrà rispondere solo 1 (SI!), perchè se si rispondesse 2 (NO!)
  il gioco terminerebbe e si perderebbe sempre perché al primo ciclo, anche se venisse generato il valore massimo (che è 9), l'acqua non uscirebbe
  mai dal bicchiere.
  Il bicchiere può contenere massimo 10ml mentre i valori generati (randomicamente), vanno da 0 a 9.
  Quindi con ciclo == 0, se si decisse di non inserire acqua nel bicchiere, anche se verrebbe generato il valore 9 (che è il valore più alto
  che può essere generato) l'acqua non uscirebbe MAI dal bicchiere, quindi l'utnete perderebbe la partita sempre!
*/

void riemp(int ciclo, int*risp, char stringa[50])
{
    *risp=-1;
    int flag=1,scelta=0,repeat=0;

    if(ciclo == 0){
        while(flag == 1){
            if(repeat == 0){
                printf("\nE' un'utente gia' registrato? Risponda 1 per SI! e 2 per NO!\n");
                scanf("%d",&scelta);
                fflush(stdin);
            }

            if(scelta == 1){    /*Indica che il player ha già registato il suo nickname, quindi il nick è presente nel file: Nome_utente.*/
                printf("\nInserisca il proprio nome utente: ");
                gets(stringa);
                flag=find_name(stringa);    /*Controlla che il nome inserito non sia presente nel file: Nome_utente. Flag=1 nome trovato nel file, Flag=0 NO!*/
                if(flag == 1){
                    printf("\nNome utente trovato. Let's play!\n");
                    flag=0;
                }
                else{
                    printf("\nNome utente NON trovato.\n");
                    view_name();            /*Mosta tutti i nickname presenti nel file: Nome_utente.*/
                    printf("\nRitentare: ");
                    flag=1;
                    repeat=1;
                }
            }
            else if(scelta == 2){   /*Indica che il player vuole registrare un nuovo nickname*/
                printf("\nScriva il suo nome per iniziare la partita: ");
                gets(stringa);
                flag=find_name(stringa);
                if(flag == 0){
                    write_name(stringa);    /*Scrive nel file: Nome_utente (file che contiene tutti i nomi dei player che si sono registrsti) il nuovo nickname.*/
                    new_player(stringa);    /*Se si inserisce un nuovo nickname (nuovo player), allora viene creato un file con lo stesso nome del nickname.
                                              Questo file conterrà quante partite ha vinto il player.*/
                }
                else{
                    printf("\nNome utente gia' utilizzato.\n");
                    view_name();
                    printf("\nReinserire un nome utente diverso: ");
                    repeat=1;
                }
            }
        }

        printf("\nSalve, desidera un po' d'acqua?\n");
    }

    else if(ciclo > 0)
        printf("\nDesidera ancora un po' d'acqua?\n");


    printf("1 per confermare, 2 per negare. Risposta: ");
    if(ciclo == 0){
        printf("\n(Nota: Ad inizio gioco si puo' solo confermare)\n");
        while(*risp != 1){
            scanf("%d",risp);
            if(*risp != 1)
                printf("\n\nReinserire risposta, grazie: ");
        }
    }
    else{
        while(*risp != 1 && *risp != 2){
            scanf("%d",risp);
            if(*risp != 1)
                printf("\n\nReinserire risposta, grazie: ");
        }
    }

    if(*risp == 1)
        printf("\nSI!\n");
    else
        printf("\nNO!\n");
}



/*A questa function viene passata la risposta della function riemp (risposta == 1 indica che l'utente ha scelto di aggiungere del acqua nel bicchiere,
  risposta == 2 l'utente ha scelto di non aggiungere altra acqua.
  Con risp == 1 vine generato randomicamente un valore da 0 a 9 che indica quanti ml di acqua verranno aggiunti.
  Poi la quantità d'acqua aggiunta (cioè il valore generato) viene scritto nel file: "text.txt" (però grazie alle function qui sotto, tale valore
  verrà scritto nel file solo lo stesso valore non è stato già generato in precedenza).

  Con rispo == 2, il gioco termina e il programma ritorna comunque quanti ml (valore generato) sarebbero stati aggiunti nel bicchiere se si fosse
  risposto 1 e no 2.
  Se la quantità d'acqua che sarebbe stata aggiuta non sarebbe fuoriuscita dal bicchiere, allora l'utente ha perso la partita;
  invece se la quantità d'acuqa che sarebbe stata aggiuta sarebbe fuoriuscita dal bicchiere, allora l'utente ha vinto la partita.

  SPIEGAZIONE:
  Ad esempio, a partita già avviata, il gioco mi chiede se voglio inserire altra acqua, però mi avverte che può essere aggiunta un massimo di 4ml.
  A questo putno posso rispondere si o no.
  Se rispondo 1 (SI! cioè voglio aggiungere altra acqua) il gioco genera un valore casuale, se il valore generato è maggiore di 4ml ho perso,
  invece se è minore o uguale a 4ml ho vinto.
  Se rispondo 2 (NO! cioè non voglio aggiungere altra acqua) il gioco genera un valore casuale, se il valore generato è maggiore di 4ml ho vinto
  (perchè l'acqua sarebbe fuoriuscita dal bicchiere), invece se è minore o uguale a 4ml ho perso (perchè l'acqua non sarebbe fuoriuscita dal
  bicchiere).
*/

int quant_riemp(int risp)
{
    int valore,flag=1,ciclo=read("t2.txt");

    ciclo=ciclo+1;

    srand(time(NULL));

    if(risp == 1 || risp == 2){
        while(flag == 1){
            valore= rand()%10;
            /*printf("\nVALORE di prova: %d\n", valore);*/
            flag=lettura(valore,"text.txt");
        }

        if(risp == 1)
            printf("\nQuantita' d'acqua aggiunta: %dml\n",valore);
        else
            printf("\nQuantita' d'acqua che sarebbe stata aggiunta: %dml\n",valore);

        if(ciclo <= 10){
            write(ciclo,"t2.txt");

            FILE*fc;
            fc= fopen("text.txt","a");

            if(fc == NULL){
                printf("\nSi e' verificato un errore\n");
                exit(1);
            }

            fprintf(fc, "\n%d", valore);
            fclose(fc);
            /*printf("\nVALORE: %d\n", valore);*/
        }
    }

    /*append(x,"text.txt");*/
    return valore;
}



/*Apre il file e legge tutti i valori presenti fino ad arrivare all'ultimo valore (Il file contiene i valori generati dalla function random).
  Questo per controllare se il nuovo valore generato dalla funzione random è stato già generato in precedenza.
  Se si allora il ciclo while viene interrotto (break), e il flag 'y' viene impostato == 1 (y=1).
  Con flag==1, nella function: quant_riemp, viene generato un altro valore. Questo si ripete finquando non viene generato un valore diverso da quelli già generati
  in precedenza.*/

int lettura(int valore, char file[])
{
    int x,y=0,ciclo=read("t2.txt");
    /*printf("\n\nCICLO %d\n\n",ciclo);*/

    FILE*fc;

    fc= fopen(file,"r");

    if(fc == NULL){
        printf("\nSi e' verificato un errore\n");
        exit(1);
    }

    /*
      La funzione feof() restituisce un valore logico vero nel caso in cui è raggiunta la fine del file e zero in tutti
      gli altri casi. Il prototipo della feof è il seguente:
      int feof(FILE *pf);
      Il ciclo while prosegue finquando non si raggiunge la fine del file. Quando si raffiunge la fine, feof == fine file, quindi la condizione del while
      non è più rispettata e il ciclo termina.

      N.B.
      Questa funzione si può usare SOLO PER LA LETTURA DEI FILE NO PER LA SCRITTURA.
      (se la si usa per la scrittura, non si ferma e scrive all'infinito fin quando non si chiude il prompt)
    */

    while(!feof(fc)){
        fscanf(fc, "%d", &x);
        if(x == valore && ciclo != 10){
            y=1;
            break;
        }

        /*printf("NUMERI: %d\n", x);*/
    }

    fclose(fc);
    return y;
}


/*
void write_ciclo(int ciclo)
{
    FILE*fc;
    fc=fopen("t2.txt","w");

    if(fc == NULL){
        printf("\nSi e' verificato un errore\n");
        exit(1);
    }

    fprintf(fc, "%d", ciclo);
    fclose(fc);
}



int read_ciclo()
{
    int c=0;

    FILE*fc;
    fc=fopen("t2.txt","r");

    if(fc == NULL){
        printf("\nSi e' verificato un errore\n");
        exit(1);
    }

    fscanf(fc, "%d", &c);
    fclose(fc);
    return c;
}
*/


/*Apre il file e scrive il valore -1 in coda. Il -1 serve alla function lettura per indicare che dopo questo valore, nel file, non ci sono altri valori.*/

/*void append(int x, char file[])
{
    FILE*fc;

    fc= fopen(file,"a");

    if(fc == NULL){
        printf("Si e' verificato un errore\n");
        exit(1);
    }

    fprintf(fc,"\n%d",x);
    fclose(fc);
}*/



void write(int i, char file[])
{
    FILE*fc;

    fc= fopen(file,"w");

    if(fc == NULL){
        printf("\nSi e' verificato un errore\n");
        exit(1);
    }

    fprintf(fc,"%d\n",i);
    fclose(fc);
}



int read(char file[])
{
    int x=0;
    FILE*fc;

    fc= fopen(file,"r");

    if(fc == NULL){
        printf("\nSi e' verificato un errore\n");
        exit(1);
    }

    fscanf(fc,"%d",&x);
    fclose(fc);
    return x;
}



/*Questa function mi stampa a video, ad ogni ciclo, il bicchiere del player con la quantità d'acqua che viene incrementata ogni qual volta il player decide di
  aggiungere altra acqua.

  Inolte la function mi ritorna due valor: acqua_mancance e la quantità d'acqua aggiunta in eccesso.

  Se l'indice (che indica il livello del acqua) è >= 3 vuol dire che l'acqua non è ancora fuoriuscita dal bicchiere.
  Quindi ogni qualvolta l'utente inserisce altra acqua  e questa rimane a un livello >=3, verrà indicato al player quanta altra acqua può essere ancora aggiunta (acqua
  mancante= *indice-2-1; Meno 2 e meno 1 perchè se ad esempio l'attuale livello del acqua è indice: 4, acqua mancante sarà: 4-2-1= 1ml. Cioè può essere aggiunta solo
  1 altro ml di acqua. Oltre l'acqua uscirebbe dal bicchiere.                          .
  Se acqua_mancante è =2ml e il player decide di inserire altra acqua, se viene inserita ad esmepio un valore di 3ml, il player ha perso perchè l'acqua è fuoriuscita
  dal bicchiere poichè è stato aggiunto 1 ml in più d'acqua.

  Quando l'acqua fuoriesce dal bicchiere l'indice (livello del acqua) sarà < 3 viene stampata la Quantita' d'acqua aggiunta in eccesso, nel nostro esempio, 1 ml.
  Ad esempio attuale livello del acuqa ha indice: 5, acqua_mancante= 3. Il player decide di aggiungere alta acqua ed esce un valore pari a 7.
  In questo caso l'acuqa fuoriesce dal bicchiere perchè la quantità d'acqua che poteva essere aggiunta era 3, invece è stata aggiunta 7.
  Quindi a schermo ci verrà mostrato la Quantita' d'acqua aggiunta in eccesso, ovvero 4. Si ottiene: (valore-(*acqua_mancante)); il valore idica la quantità d'acqua
  aggiunta: 7, meno acqua_mancante= 3 e otteniamo la quantità d'acqua aggiunta in eccesso ovvero 4.
*/

void visualizza(char*pa, int n_col, int n, int m, int valore, int*indice, int*acqua_mancante, char c, char c1)
{
    int i,j,pointer,flag=1;
    pointer=read("t1.txt");
    *indice= pointer-valore;
    /*printf("\nINDICE%d\n", *indice);*/
    char acqua= 'x';

    /*Ad inizio gioco, nel file "t1,txt" (che contine l'indice a partire del quale va inserita l'acqua nel bicchiere) viene registrato il valore 13
      (fondo del bicchiere).
      L'indice viene aggiornato ad ogni iterazione. A tale valore viene sottratta la precedente posizione che indica fin dove è arrivata l'acuqa, meno l'attuale
      valore generato che indica quanta altra acqua deve essere aggiunta nel bicchiere (*indice= pointer-valore;).
      Cioè l'acqua potà essere inserita a partire dalla posizione 3 fino ad arrivare alla posizione 13 (Alla posizione 14 vi è la struttura finale del bicchiere).

      Indice deve essere maggiore di 2 perche alla riga 2 vi è la struttura del bicchiere (bordo bicchiere), oltre il quale l'acqua non può andare.
      Di conseguenza l'acqua non può essere inserita alla posizione 0, 1 e 2.
    */

    if(*indice >= 3){
        *acqua_mancante=((*indice)-2)-1;
        printf("\nWARNING! Quantita' d'acqua che puo' essere ancora inserita: %dml\n", *acqua_mancante);

        printf("\n");
        for(i=0;i<n;i++){
            /*printf("\nII %d\n\n",i);*/
            for(j=0;j<m;j++){
                if(i < *indice){
                    printf("%c  ",*(pa+n_col*i+j));
                }
                else if(i >= *indice){
                    /*printf("\nI %d FLAG %d\n\n",i,flag);*/
                    if(i >= *indice && flag == 1){
                        write(i,"t1.txt");
                        /*printf("\nIIIIIII %d\n\n",i);*/
                        flag=0;
                    }
                    if(*(pa+n_col*i+j) != c && *(pa+n_col*i+j) != c1)
                        *(pa+n_col*i+j)= acqua;

                    printf("%c  ",*(pa+n_col*i+j));
                }
            }
            printf("\n");
        }
    }
    else
        printf("\nQuantita' d'acqua aggiunta in eccesso: %dml\n", (valore-(*acqua_mancante)));
}



/*Riscrive (inserendo lo spazio vuoto) i file che contengono i valori generati (text) e il ciclo (t2) quando si compila il programma (cioè si ricomincia a giocare
  una nuova sessione).
  Tramite questa funzione (rewrite), i file vengono riscritti sia se si termina la sessione di gioco osia se la si interrompe prima che termini.
  Chiamando questa funzione all'inizio del gioco, anche se precedentemente il gioco era stato interrotto prima della sua fine (o anche se si era terminata
  la sessione), quando si ricompilare per rigiocare, i due file verranno resettari per evitare che contengano valori della sessione di gioco precedente.
*/

void rewrite(char file[])
{
    char c= ' ';
    int i,l=read("t2.txt");
    FILE*fc;

    fc=fopen(file,"w");

    if(fc == NULL){
        printf("\nSi e' verificato un errore!\n");
        exit(1);
    }

   for(i=0;i<l;i++){
        fprintf(fc,"%c\n",c);
    }

    fclose(fc);
}



void cont_versa(char*pa, int n_col, int n, int m, char c, char c1)
{
    char file1[]= {"t1.txt"};
    char file2[]= {"t2.txt"};
    char stringa[50];
    int risp,valore,indice=read(file1),ciclo,acqM=((indice-2)-1)/*,flag,punteggio*/;

    while(indice > 3){
        ciclo=read(file2);  /*Legge a che ciclo ci troviamo dal file t2*/
        /*riemp() mi ritorna risp (1 aggiungi acqua, 2 no altra acqua) e scelta (1 utente già registrato, 2 nuovo utente)*/
        riemp(ciclo,&risp,stringa);

        if(risp == 1){
            valore= quant_riemp(risp);                          /*Mi ritrona quant'aqua deve essere aggiunta*/
            visualizza(pa,n_col,n,m,valore,&indice,&acqM,c,c1); /*Visualizza il bicchiere con l'acuqa e mi ritorna acqua_mancante (quant'aqua può essere ancora aggiunta)*/
        }

        /*Se risp==2 vuol dire che non voglio aggiungere altra acuqa.
          Il programma si interrmope e mi ritorna il valore: che indica quanta acqua sarebbe stata giunta se avessi risposto 1 (voglio altra acqua).
          Se il valore è > del acqua mancante, assegno indice==3 per andare al if sotto che mi indica che ho vinto. Perchè?
          Se il valore è, ad esempio: 5 (acuqa che andrebbe aggiunta nel bicchiere)e l'acqua_mancante è: 3 (acqua che può essere ancora aggiunta) ho vinto perchè
          se avessi risposto 1 (Si!) l'acqua sarebbe fuoriuscita dal bicchiere perchè averi aggiunto 2ml in più rispetto alla capienza del bicchiere
          (valore-acqM= 5-3= 2ml).

          Se invece il valore è < di acqM assegno indice==2 e ho perso. Perchè?
          Se risp==2 e il valore è, ad esempio: 5 (acuqa che andrebbe aggiunta nel bicchiere)e l'acqua_mancante è: 7 (acqua che può essere ancora aggiunta) ho pesro
          perchè  se avessi risposto 1 (Si!) l'acqua non sarebbe fuoriuscita dal bicchiere perchè mancherebbero ancora 2ml iper raggiungere la capienza del bicchiere
          e il programma mi ritorna: "Game over! Il liquido NON sarebbe fuoriuscito dal bicchiere!";

          Finisco nel else if(indice <= 2) anche quando do come risp 1 perchè vuol dire che è stata aggiunta troppa acqua e che quindi è fuoriuscita dal bicchiere.
          Il programma mi ritorna: "Game over! Il liquido e' fuoriuscito dal bicchiere!".
          */

        else if(risp == 2){
            valore= quant_riemp(risp);
            if(valore > acqM)
                indice=3;
            else
                indice=2;

            break;
        }
    }
    if(indice == 3){
        printf("\nYOU WIN!\n");
        write_score(stringa);               /*Se il player ha vinto aggiorno il conto delle sue vittorie nel suo file*/
        /*let_name(stringa,&flag,&punteggio);
        if(flag != 0){
            punteggio++;
            NewScore(flag,punteggio);
        }*/
    }
    else if(indice <= 2){
        if(risp == 1)
            printf("\nGame over! Il liquido e' fuoriuscito dal bicchiere!\n");
        else
            printf("\nGame over! Il liquido NON sarebbe fuoriuscito dal bicchiere!\n");

        /*let_name(stringa,&flag,&punteggio);
        if(flag != 0){
            punteggio=punteggio+1;
            NewScore(flag,punteggio);
        }*/
    }
}

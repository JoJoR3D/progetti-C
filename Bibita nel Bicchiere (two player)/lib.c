#include <string.h>

/*Prima function chiamata nel main che ritorna la scelta del giocatore:
  ritorna 0 se il giocatore vuole giocare in modalità Singolplayer;
  ritorna 1 se il giocatore vuole giocare in modalità Multiplayer (uno contro uno).
*/

int Modpartita()
{
    int ModMultiplayer;
    printf("\nPer modalita' singolplayer inserire valore 0, per modalita' multiplayer inserire valore 1: ");
    scanf("%d",&ModMultiplayer);

    return ModMultiplayer;
}



/*Mi ritorna quanti nickname sono presenti nel file: Nome_utente (fil che salva i nickname scelti dai player)*/

int cont_num_nick(char file[])
{
    int p=0;
    char s[50];

    FILE*fc;
    fc=fopen(file,"r");

    if(fc == NULL){
        printf("\nSi e' verificato un errore in cont_num_nick\n");
        exit(1);
    }

    while(fscanf(fc,"%s",s) != EOF){   /*Cicla fin quando non arriva alla fine del file*/
        p++;                            /*Ad ogni nickname letto (grazie alla fscanf nella condizione del while) nel file: Nome_utente, viene incrementato il valore p*/
    }

    return p;                           /*Mi ritorna quanti nick sono presenti nel file: Nome_utente*/
}



/*Pulisce il contenuto di stringa. Stringa contiene il nick scelto dal utente.*/

void ripulisci_stringa(char s[])
{
    int i=0;

    while(s[i] != '\0'){
        s[i]= ' ';
        i++;
    }
}



/*Se il player seleziona scelta==1 vuol dire che vuole utilizzare un nick già registrato.
  Ma se il nick inserito non è mai stato registrato (quindi non è presente nel file: Nome_utente), il player può ritentare per indicare un nick già presente
  nel file Nome_utente (ritentare==1), oppure può salvare il nick inserito che non risulta registrato, cioè decide di registrarlo e usarlo per giocare la partita
  (ritentare==2).

  contNumNick mi ritorna quanti nickname sono presenti nel file: Nome_utente (fil che salva i nickname scelti dai player).

  Se contNumNick > 0:
  1)Se il player seleziona ritentare=1, al player viene richiesto di: "Inserisca il proprio nome utente: "; (nella function riemp()). Se inserisce un nome utente
    non presente nel file: Nome_utente, gli verrà chiesto di riprovare premendo 1 o di salvare questo nick inserito premendo 2.

   N.B. Se non mettessi *blocco=1, il sistema andrebbe nel blocco if (ovvero: if(flag == 0 && player == 2 && ModMultiplayer == 1) nella function riemp()) per
        verificare che il nick inserito dal player 2 non sia uguale a quello del player 1. Essendo diversi, poiche come abbiamo detto il nick inserito non è presente
        nel file: Nome_utente, il sistema pone il flag=0 facendomi uscire dal blocco while (function riemp()) e questo non fa salvare il nick scelto dal player 2.

  2)Se il player seleziona ritentare=2, il nick inserito in stringa viene salvato. Per farlo salto al blocco: else if(*scelta == 2) ponento *scelta=2, e
    salto l'if(opzione == 0) ponendo opzione=1 (nella function riemp()), questo perchè il nome utente l'ho già inserito.
    Poi al player viene richiesto: "Salve nome_utente, desidera un po' d'acqua?\n"); (nella function riemp()).
    Anche qui vale il discorso del *blocco impostato a 1.

  Se contNumNick è == 0, vuol dire che nel file: Nome_utente non è stato ancora mai registrato nessun nickname.
  Allora quello che viene fatto è lo stesso che accade con ritentare==2:
  Viene salvato il nome utente inserito. Per farlo salto al blocco: else if(*scelta == 2) ponento *scelta=2, e salto l'if(opzione == 0) ponendo opzione=1
  (nella function riemp()), questo perchè il nome utente l'ho già inserito.
*/

void reinserire_nick(char stringa[], int contNumNick, int*flag, int*repeat, int*blocco, int*scelta, int*opzione)
{
    int ritentare;

    if(contNumNick > 0){
        printf("\nRitentare nome utente non trovato. Oppure si vuole registrare il nome utente inserito? Se SI premere 2 altrimenti 1: ");
        scanf("%d",&ritentare);

        if(ritentare == 1){     /*Riprovo ad inserire un altro nome utente*/
            *flag=1;
            *repeat=1;
            *blocco=1;
            ripulisci_stringa(stringa); /*Pulisce il contenuto di stringa. Stringa contiene il nick scelto dal utente.*/
            fflush(stdin);              /*Pulische il buffer*/
        }

        /*Viene salvato il nome utente inserito. Per farlo salto al blocco: else if(*scelta == 2) ponento *scelta=2, e salto l'if(opzione == 0) ponendo opzione=1
          (nella function riemp()), questo perchè il nome utente l'ho già inserito.*/

        else if(ritentare == 2){
            *repeat=1;
            *scelta=2;
            *opzione=1;
            *blocco=1;
            *flag=1;
        }
    }
    else if(contNumNick == 0){
        printf("\nNon ci sono nomi utenti registrati. Il nick inserito: '%s' ora e' stato salvato!\n",stringa);
        *repeat=1;
        *scelta=2;
        *opzione=1;
        *flag=1;
    }
}



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
        printf("\nSi e' verificato un errore find_name\n");
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
        printf("\nSi e' verificato un errore view_name\n");
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
        printf("\nSi e' verificato un errore write_name\n");
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
        printf("\nSi e' verificato un errore new_player\n");
        exit(1);
    }

    fprintf(fc, "%d", p);
    fclose(fc);
}



/*Scriverà il nuovo punteggio nel file del player che ha disputato la partita solo se il player ha vinto la partita.*/

void write_score(char file[])
{
    int p=0;

    FILE*fc;
    fc=fopen(file,"r");

    if(fc == NULL){
        printf("\nSi e' verificato un errore write_score1\n");
        exit(1);
    }

    fscanf(fc, "%d", &p);
    fclose(fc);

    p=p+1;              /*Incremento il punteggio del player. Ad esempio se era 2 (cioè 2 partite vinte), ora diventerà 3 (cioè 3 partite vinte).*/

    FILE*fd;
    fd=fopen(file,"w");

    if(fd == NULL){
        printf("\nSi e' verificato un errore write_score2\n");
        exit(1);
    }

    fprintf(fd, "%d", p);
    fclose(fd);
}



/*Leggerà il conentuto del file che contiene quante partite ha giocato questo player per poi incrementarlo a fine partita e scriverlo nello stesso file*/

void write_Npartita(char file[])
{
    int p=0;

    FILE*fc;
    fc=fopen(file,"r");

    /*puts(file);*/

    if(fc == NULL){
        printf("\nSi e' verificato un errore write_Npartita1\n");
        exit(1);
    }

    fscanf(fc, "%d", &p);
    fclose(fc);

    p=p+1;

    FILE*fd;
    fd=fopen(file,"w");

    if(fd == NULL){
        printf("\nSi e' verificato un errore write_Npartita2\n");
        exit(1);
    }

    fprintf(fd, "%d", p);
    fclose(fd);
}



/*Con scelta==2 (cioè crea un nuovo nick), questa function, crea il file che conterrà quante partite ha giocato a questo gioco il player.
  Ogni player avrà il suo file.
*/

void crea_file(char file[], char dest[])
{
    /*Concatena alla stringa dest= "Partite_giocate_da_", la stringa file che contiene il nick utilizzato dla player. Esempio:
      Nick player: pe, usando la strcat dest conterrà la stringa ("Partite_giocate_da_pe").
      Questo file conterrà il numero di partite disputate dal player: "pe" a questo gioco.
    */

    strcat(dest,file);

    FILE*fc;
    fc=fopen(dest,"w");

    /*puts(dest);*/

    if(fc == NULL){
        printf("\nSi e' verificato un errore crea file\n");
        exit(1);
    }

    fclose(fc);
}



/*Con scelta==1 (cioè nick già esistente), questa function andrà a trovare il file del player che contiene il numero di partite disputate.*/

void Read(char file[], char dest[])
{
    int p=0;

    strcat(dest,file);

    FILE*fc;
    fc=fopen(dest,"r");

    /*puts(dest);*/

    if(fc == NULL){
        printf("\nSi e' verificato un errore Read\n");
        exit(1);
    }

    fscanf(fc, "%d", &p);
    fclose(fc);
}



/*Function chiamata nella function: singolplayer
  Scelta==2 vuol dire che il player sta registrando un nuovo nick name. Quindi la function crea_file() crea il file che conterrà il numero di volte che il
  player ha giocato a questo gioco (Ad esempio se il nick del player è: pe, questo player avrà 2 file, uno che contiene quante partite ha vinto ("pe.txt")
  e un file che conterrà uqnate partite ha gicato a questo gioco (Partite_giocate_da_pe.txt").

  Invece se scelta è ==1 vuol dire che il player ha già un suo nick registrato nel file: Nome_utente.
  Quindi la funzione Read() andrà a trovare il file: Partite_giocate_da_nickname.txt.

  Poi sia con scelta==1 o ==2, verrà aggiornato il punteggio nel file: Partite_giocate_da_pe.txt
*/

void file_Npartite_singol_player(char stringa[], char dest[], int scelta)
{
    if(scelta == 2)
        crea_file(stringa,dest);
    else
        Read(stringa,dest);

    write_Npartita(dest);
}



/*Function chiamata nella function: multiplayer
  Scelta==2 vuol dire che il player sta registrando un nuovo nick name. Quindi la function crea_file() crea il file che conterrà il numero di volte che il
  player ha giocato a questo gioco (Ad esempio se il nick del player è: pe, questo player avrà 2 file, uno che contiene quante partite ha vinto ("pe.txt")
  e un file che conterrà uqnate partite ha gicato a questo gioco (Partite_giocate_da_pe.txt").

  Invece se scelta è ==1 vuol dire che il player ha già un suo nick registrato nel file: Nome_utente.
  Quindi la funzione Read() andrà a trovare il file: Partite_giocate_da_nickname.txt.

  Poi sia con scelta==1 o ==2, verrà aggiornato il punteggio nel file: Partite_giocate_da_pe.txt

  N.B. turno==1 indica il primo player, mentre turno==2 indica il secondo player.
*/

void file_Npartite_multi_player(char stringa1[], char stringa2[], char dest1[], char dest2[], int scelta, int turno)
{
    if(scelta == 2){
        if(turno == 1)
            crea_file(stringa1,dest1);
        else
            crea_file(stringa2,dest2);
    }
    else{
        if(turno == 1)
            Read(stringa1,dest1);
        else
            Read(stringa2,dest2);
    }

    if(turno == 1)
        write_Npartita(dest1);
    else
        write_Npartita(dest2);
}



/*Serve per salvare, in una stringa, il nome utente scelto dai due player.
  Mi serve per aggiornare, a fine partita, il punteggio del player che ha vinto.
  Uso questa function perchè: La functionn riemp() (che chiamo nella function multiplayer())mi ritorna, tra le altre cose, il nome (la stringa) del primo player.
  Ma se si gioca in modalità uno contro uno, poi la function riemp() viene richiamata per il secondo player, quindi mi ritorna il nome del secondo player.
  Però in questo modo il nome del secondo player va  a sovrascrivere quello del primo player, quindi non ho più il nome del primo player.
  Se quindi poi a vincere è il primo player, la vittoria andrebbe assegnata comunque al secondo plyaer perchè ho solo quella stringa.
  Invece mediante questa function back_string(), vado a salvare le stringhe dei due player in due stringhe che ho chiamato destinazione1 e destinazione2 nella
  function cont_versa().

  N.B.
  Ricorda che per ogni nome utente viene creato un file ciascuno, che contiene il loro punteggio che viene aggiornato ad ogni partita in caso di vittoria.
*/

void back_string(char s[], char v[])
{
    strcpy(v,s);
}



/*Seve per confornatare, in modalità uno contro uno, il nome utente del primo player con quello del secondo plyaer.
  Se il secondo plyaer ha scelto lo stesso nome del primo player, la funtion mi ritorna 1 e il secondo player è invitato a scegliere un altro nome utente.
*/

int conf_string(char s[], char v[])
{
    if(strcmp(s,v)==0)
        return 1;
    return 0;
}



/*Se il player seleziona scelta=1 vuol dire che vuole utilizzare un nome_utente già presente nel file: Nome_utente.*/

void scelta_1(char stringa[], char dest[], int*opzione, int*repeat, int*scelta, int*flag, int SM_player, int player, int ModMultiplayer)
{
    int blocco,contNumNick,confronto;

    if(*scelta == 1){       /*Indica che il player ha già registato il suo nickname, quindi il nick è presente nel file: Nome_utente.*/
        if(*opzione == 0){
            printf("\nInserisca il proprio nome utente: ");
            gets(stringa);
        }

        if(SM_player == 1){
            *flag=find_name(stringa);    /*Controlla che il nome inserito non sia presente nel file: Nome_utente. Flag=1 nome trovato nel file, Flag=0 NO!*/
            blocco=0;
            if(*flag == 1 && player == 1){
                printf("\nNome utente trovato. Let's play!\n");
                *flag=0;     /*Se sta ciclando il player==2 non pongo il flag==0 perchè altrimenti non eseguirebbe il controllo del if(flag == 1 && player == 2)*/
            }
            else if(*flag == 0){
                printf("\nNome utente NON trovato.\n");
                view_name();                                    /*Mosta tutti i nickname presenti nel file: Nome_utente.*/
                contNumNick= cont_num_nick("Nome_utente.txt");  /*Mi ritorna quanti nickname sono presenti nel file: Nome_utente (fil che salva i nickname scelti dai player)*/
                reinserire_nick(stringa,contNumNick,flag,repeat,&blocco,scelta,opzione);
            }

            /*Con player==2 questo blocco verifica che il player 2 non abbia usato lo stesso nickname scelto dal player 1*/

            if(*flag == 1 && player == 2 && blocco == 0 && ModMultiplayer == 1){
                confronto=conf_string(stringa,dest);    /*Verifica che il secondo player non scelga lo stesso nome del primo player.*/

                if(confronto == 1){
                    view_name();
                    printf("\nNome gia' utilizzato, ritentare: ");
                    *flag=1;
                    *repeat=1;
                }
                else{
                    SM_player=0;
                    *opzione=1;
                    *flag=0;
                }
            }
        }
    }
}



/*Se il player seleziona scelta=2 vuol dire che vuole registrare un nuovo nome_utente.*/

void scelta_2(char stringa[], char dest[], int*opzione, int*repeat, int*scelta, int*flag, int SM_player, int player, int ModMultiplayer)
{
    int confronto;

    if(*scelta == 2){  /*Indica che il player vuole registrare un nuovo nickname*/
        if(opzione == 0){
            printf("\nScriva il suo nome per iniziare la partita: ");
            gets(stringa);
        }

        if(SM_player == 1){
            *flag=find_name(stringa);    /*Verifica che il nome utente inserito non sia già presente nel file: Nome_utente.*/
            if(*flag == 0){
                write_name(stringa);    /*Scrive nel file: Nome_utente (file che contiene tutti i nomi dei player che si sono registrsti) il nuovo nickname.*/
                new_player(stringa);    /*Se si inserisce un nuovo nickname (nuovo player), allora viene creato un file con lo stesso nome del nickname.
                                          Questo file conterrà quante partite ha vinto il player.*/
            }
            else{
                printf("\nNome utente gia' utilizzato.\n");
                view_name();
                printf("\nReinserire un nome utente diverso: ");
                *repeat=1;
            }

            /*Con player==2 questo blocco verifica che il player 2 non abbia usato lo stesso nickname scelto dal player 1*/

            if(*flag == 0 && player == 2 && ModMultiplayer == 1){
                confronto=conf_string(stringa,dest);

                if(confronto == 1){
                    view_name();
                    printf("\nNome gia' utilizzato, ritentare: ");
                    *flag=1;
                    *repeat=1;
                }
                else{
                    SM_player=0;
                    *opzione=1;
                    *flag=0;
                }
            }
        }
    }
}



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

            ------------------------------------------------------------------------------------------------

  MULTIPLAYER:
  Se gioco in modalità Multiplayer (due giocatori uno contro uno), SM_player è impostato a 1 ,player è == 2 e ModMultiplayer == 1. Esempio:
  Inizio la partita multiplayer, inizia il primo giocatore. Player è ==1.
  Il giocatore inserisce il suo nome utente se è già registrato (scelta==1), oppure un nuovo nome utente per registrarsi (scelta==2).
  Poi fa la sua mossa per aggiungere un pò d,acqua.

  Poi tocca al secondo player.  Player è ==2.
  Il giocatore inserisce il suo nome utente se è già registrato (scelta==1), oppure un nuovo nome utente per registrarsi (scelta==2).
  Se seleziona scelta==1, viene verificato se il nick è presente nel file: Nome_utente (find_name ritorna flag==1 se trova il nick, altrimenti ritorna 0)
  Se flag==0, allora viene richiesto di ritentare e reinserire il nick.
  Se flag==1, viene eseguto il blocco if che contiene la chiamata alla function conf_string() (assegnata alla variabile confronto) che controlla che il nome utente
  del secondo player, non sia lo stesso usato dal primo player. Se fosse così (confronto==1), il secondo player deve reinserire un nome utente diverso.
  Poi si prosegue e il player fa la sua mossa per aggiungere un pò d,acqua.

  E così via, a turni, i due player sceglieranno se aggiungere altra acuqa ognuno al proprio bicchiere, oppure no.
  Alla fine si vedrà chi de due ha vinto, oppure se entrambi hanno perso.

            ------------------------------------------------------------------------------------------------

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

  N.B.
  Se gioco in modalità SINGOLPLAYER, la variabile ModMultiplayer è impostata == 0, quindi non vengono attivati i blocchi:
  if(flag == 1 && player == 2 && blocco == 0 && ModMultiplayer == 1) se scelta è == 1, oppure
  if(flag == 0 && player == 2 && ModMultiplayer == 1) se scelta è == 2.
*/

void riemp(int ciclo, int*risp, char stringa[50], char dest[50], int SM_player, int player, int ModMultiplayer, int*scelta)
{
    *risp=-1;
    int flag=1,repeat=0,opzione=0;

    if(ciclo == 0){
        while(flag == 1){
            if(repeat == 0){
                printf("\nE' un'utente gia' registrato? Risponda 1 per SI! e 2 per NO!\n");
                scanf("%d",scelta);
                fflush(stdin);
            }

            if(*scelta == 1)
                scelta_1(stringa,dest,&opzione,&repeat,scelta,&flag,SM_player,player,ModMultiplayer);
            else if(*scelta == 2)
                scelta_2(stringa,dest,&opzione,&repeat,scelta,&flag,SM_player,player,ModMultiplayer);
        }
        printf("\nSalve %s, desidera un po' d'acqua?\n",stringa);
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
            if(*risp != 1 && *risp != 2)
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
  Poi la quantità d'acqua aggiunta (cioè il valore generato) viene scritto nel file: "valori_1.txt" (però grazie alle function qui sotto, tale valore
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

int quant_riemp(int risp, char file[], char file1[])
{
    int valore,flag=1,ciclo=read(file);

    ciclo=ciclo+1;

    srand(time(NULL));

    if(risp == 1 || risp == 2){
        while(flag == 1){
            valore= rand()%10;
            /*printf("\nVALORE di prova: %d\n", valore);*/
            flag=lettura(valore,file1);
        }

        if(risp == 1)
            printf("\nQuantita' d'acqua aggiunta: %dml\n",valore);
        else
            printf("\nQuantita' d'acqua che sarebbe stata aggiunta: %dml\n",valore);

        if(ciclo <= 10){
            write(ciclo,file);

            FILE*fc;
            fc= fopen(file1,"a");

            if(fc == NULL){
                printf("\nSi e' verificato un errore quant_riemp\n");
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
    int x,y=0,ciclo=read(file);
    /*printf("\n\nCICLO %d\n\n",ciclo);*/

    FILE*fc;

    fc= fopen(file,"r");

    if(fc == NULL){
        printf("\nSi e' verificato un errore lettura\n");
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
        printf("\nSi e' verificato un errore write\n");
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
        printf("\nSi e' verificato un errore read\n");
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

void visualizza(char*pa, int n_col, int n, int m, int valore, int*indice, int*acqua_mancante, char c, char c1, char file[])
{
    int i,j,pointer,flag=1;
    pointer=read(file);
    *indice= pointer-valore;
    /*printf("\nINDICE%d\n", *indice);*/
    char acqua= 'x';

    /*Ad inizio gioco, nel file "indice_1,txt" (che contine l'indice a partire del quale va inserita l'acqua nel bicchiere) viene registrato il valore 13
      (fondo del bicchiere).
      L'indice viene aggiornato ad ogni iterazione. A tale valore viene sottratta la precedente posizione che indica fin dove è arrivata l'acuqa, meno l'attuale
      valore generato che indica quanta altra acqua deve essere aggiunta nel bicchiere (*indice= pointer-valore;).
      Cioè l'acqua potà essere inserita a partire dalla posizione 3 fino ad arrivare alla posizione 13 (Alla posizione 14 vi è la struttura finale del bicchiere).

      L'indice deve essere maggiore di 2 perche alla riga 2 vi è la struttura del bicchiere (bordo bicchiere), oltre il quale l'acqua non può andare.
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
                        write(i,file);
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
    int i,l=read(file);
    FILE*fc;

    fc=fopen(file,"w");

    if(fc == NULL){
        printf("\nSi e' verificato un errore rewrite!\n");
        exit(1);
    }

   for(i=0;i<l;i++){
        fprintf(fc,"%c\n",c);
    }

    fclose(fc);
}



/*
void cont_versa(char*pa, int n_col, int n, int m, char c, char c1, int*flag, int*cambio_player, int turno)
{
    int ModMultiplayer= Modpartita();

    if(ModMultiplayer == 0)
        singolplayer(pa,n_col,n,m,c,c1,ModMultiplayer);
    else if(ModMultiplayer == 1)
        multiplayer(pa,n_col,n,m,c,c1,flag,cambio_player,turno,ModMultiplayer);
}
*/



/*Function che viene utilizzata solo quando si gioca in modalità Singolplayer*/

void singolplayer(char*pa, int n_col, int n, int m, char c, char c1, int ModMultiplayer)
{
    char file_indice[]= {"indice_1.txt"};
    char file_ciclo[]= {"ciclo_1.txt"};
    char file_valore[]= {"valori_1.txt"};
    char stringa[50], dest[50]= {"Partite_giocate_da_"};
    int risp,valore,indice=read(file_indice),ciclo,acqM=((indice-2)-1);

    int SM_player=1,player=1,scelta;
    char destinazione[50];

    while(indice > 3){
        ciclo=read(file_ciclo); /*Legge a che ciclo ci troviamo dal file ciclo_1*/
        /*riemp() mi ritorna risp (1 aggiungi acqua, 2 no altra acqua) e scelta (1 utente già registrato, 2 nuovo utente)*/
        riemp(ciclo,&risp,stringa,destinazione,SM_player,player,ModMultiplayer,&scelta);

        if(risp == 1){
            valore= quant_riemp(risp,file_ciclo,file_valore);               /*Mi ritrona quant'aqua deve essere aggiunta*/
            visualizza(pa,n_col,n,m,valore,&indice,&acqM,c,c1,file_indice); /*Visualizza il bicchiere con l'acuqa e mi ritorna acqua_mancante (quant'aqua può essere ancora aggiunta)*/
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
            valore= quant_riemp(risp,file_ciclo,file_valore);
            if(valore > acqM)
                indice=3;
            else
                indice=2;

            break;
        }
    }

    if(indice == 3){
        printf("\nYOU WIN!\n");
        write_score(stringa);                               /*Se il player ha vinto aggiorno il conto delle sue vittorie nel suo file*/

        file_Npartite_singol_player(stringa,dest,scelta);   /*Crea o trova il file che conterrà il numero di partite giocate dal player*/
    }

    else if(indice <= 2){
        if(risp == 1)
            printf("\nGame over! Il liquido e' fuoriuscito dal bicchiere!\n");
        else
            printf("\nGame over! Il liquido NON sarebbe fuoriuscito dal bicchiere!\n");

        file_Npartite_singol_player(stringa,dest,scelta);   /*Crea o trova il file che conterrà il numero di partite giocate dal player*/
    }
}



/*Function che viene utilizzata solo quando si gioca in modalità Multiplayer*/

void multiplayer(char*pa, int n_col, int n, int m, char c, char c1, int*flag, int*cambio_player, int turno, int ModMultiplayer)
{
    char file1[]= {"indice_1.txt"};
    char file2[]= {"ciclo_1.txt"};
    char file3[]= {"indice_2.txt"};
    char file4[]= {"ciclo_2.txt"};
    char file5[]= {"valori_1.txt"};
    char file6[]= {"valori_2.txt"};
    char file_indice[50];
    char file_valore[50];
    char file_ciclo[50];

    char stringa[50], dest1[50]= {"Partite_giocate_da_"}, dest2[50]= {"Partite_giocate_da_"};
    char destinazione1[50];
    char destinazione2[50];

    int risp,valore,indice,indice_1=read(file1),indice_2=read(file3),ciclo,acqM,SM_player=1,player,scelta;

    if(turno == 1){                     /*Tutno del primo player*/
        indice= indice_1;
        ciclo= read(file2);
        strcpy(file_indice,file1);
        strcpy(file_valore,file5);
        strcpy(file_ciclo,file2);
        acqM=((indice-2)-1);
        player=1;
    }
    else if(turno == 0){            /*Turno del secondo player*/
        indice= indice_2;
        ciclo= read(file4);
        strcpy(file_indice,file3);
        strcpy(file_valore,file6);
        strcpy(file_ciclo,file4);
        acqM=((indice-2)-1);
        player=2;
    }

    while(indice > 3 && *cambio_player == 0){
        /*riemp() mi ritorna risp (1 aggiungi acqua, 2 no altra acqua) e scelta (1 utente già registrato, 2 nuovo utente)*/
        riemp(ciclo,&risp,stringa,destinazione1,SM_player,player,ModMultiplayer,&scelta);
        if(turno == 1 && ciclo == 0){
            back_string(stringa,destinazione1); /*Salva in destinazione1 il nick del primo player*/
        }
        else if(turno == 0 && ciclo == 0){
            back_string(stringa,destinazione2); /*Salva in destinazione1 il nick del secondo player*/
        }

        if(risp == 1){
            valore= quant_riemp(risp,file_ciclo,file_valore);               /*Mi ritrona quant'aqua deve essere aggiunta*/
            visualizza(pa,n_col,n,m,valore,&indice,&acqM,c,c1,file_indice); /*Visualizza il bicchiere con l'acuqa e mi ritorna acqua_mancante (quant'aqua può essere ancora aggiunta)*/
            if(turno==1)
                write(indice,file1);
            else
                write(indice,file3);
        }

        /*Se risp==2 vuol dire che non voglio aggiungere altra acuqa.
          Il programma si interrmope e mi ritorna il valore: che indica quanta acqua sarebbe stata giunta se avessi risposto 1 (voglio altra acqua).
          Se il valore è > del acqua mancante, leggo l'indice dal file indice di ciascun player per a quali delle 3 condizioni del if andare. Perchè?
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
            valore= quant_riemp(risp,file_ciclo,file_valore);
            if(valore > acqM){
                /*indice=3;*/
                if(turno==1)             /*Turno player_1*/
                    write(indice,file1); /*Scrivo l'attuale indice del player nel suo file indice per vedere a queli delle 3 condizioni del if (qui sotto) andare*/
                else                     /*Turno player_2*/
                    write(indice,file3); /*Scrivo l'attuale indice del player nel suo file indice per vedere a queli delle 3 condizioni del if (qui sotto) andare*/
            }
            else{
                indice=2;
                if(turno==0)             /*Turno player_2*/
                    write(indice,file3); /*Scrivo l'attuale indice del player nel suo file indice per vedere a queli delle 3 condizioni del if (qui sotto) andare*/
                else                     /*Turno player_1*/
                    write(indice,file1); /*Scrivo l'attuale indice del player nel suo file indice per vedere a queli delle 3 condizioni del if (qui sotto) andare*/
            }
            *flag=1;
        }
        *cambio_player=1;   /*Indica che, ad esempio, il player_1 ha fatto la sua mossa e che ora tocca al player_2 fare la sua mossa*/
    }


    if(indice == 3){
        if(turno == 1)
            write_score(destinazione1);  /*Scrive il punteggio nel file del player 1*/
        else
            write_score(destinazione2);  /*Scrive il punteggio nel file del player 2*/

        printf("\nWIN!\n");

        file_Npartite_multi_player(destinazione1,destinazione2,dest1,dest2,scelta,turno); /*Crea o trova il file che conterrà il numero di partite giocate dal player*/

        *flag=1;        /*Indica che il player ha terminato la sua partita. Se è il turno di player1 con flag==1 vuol dire che ha terminato la partita e che d'ora in
                          poi il turno sarà sempre di player2.
                          Vieceversa se è il turno di player2 con flag==1 vuol dire che ha terminato la partita e che d'ora in poi il turno sarà sempre di player1.*/
    }
    else if(indice <= 2){
        if(risp == 1)
            printf("\nGame over! Il liquido e' fuoriuscito dal bicchiere!\n");
        else
            printf("\nGame over! Il liquido NON sarebbe fuoriuscito dal bicchiere!\n");

        file_Npartite_multi_player(destinazione1,destinazione2,dest1,dest2,scelta,turno); /*Crea o trova il file che conterrà il numero di partite giocate dal player*/

        *flag=1;
    }

    /*Se rispondo 2 (non voglio aggiunger più acqua), ed ad esempio hanno vinto entrambi i player perchè l'acqua, al termine del gioco, non è fuoriuscita dal
      bicchiere, quando vado nella function winnerIS() leggo l'indice di entrambi i player che indica a che livello è arrivata l'acqua nei propri bicchiere.
      Se l'indice del player 1 è inferiore a quello del player 2, vuol dire che il player 1 è riuscito ad aggiungere più acqua nel bicchiere senza farla fuoriuscire
      rispetto al player 2.
      Viceversa se l'indice del player 2 è inferiore a quello del player 1, allora a vincere è il player 2.

      Esempio:
      Ricordando che l'acqua può arrivare massimo fino al livello 3 (indice 3) del bicchiere (se l'indice è <=2 allora l'acqua fuoriesce dal bicchiere e il player
      ha perso.
      Entrambi i player hanno vinto perchè l'acqua nel bicchiere è > del indice 3.
      L'acqua del player 1 è arrivata all'indice 4 e quella del player 2 all'indice 5, a a vincere è il player 1 perchè ha riempito il bicchiere con più acqua, rispetto
      al player 2, senza farla fuoriuscire dal bicchiere.
    */

    else if(indice >= 3 && risp == 2){
        if(turno == 1)
            write_score(destinazione1);
        else
            write_score(destinazione2);

        printf("\nWIN!\n");

        file_Npartite_multi_player(destinazione1,destinazione2,dest1,dest2,scelta,turno); /*Crea o trova il file che conterrà il numero di partite giocate dal player*/

        *flag=1;
    }
}





/*Function che stabilisce i turni di gioco dei vari giocatori e che chiama la function cont_versa() che scrive il punteggio nel file utente del vincitore e
  indica se il singolo giocatore o i due giocatori hanno vinto o perso.

  N.B.
  Questa function viene utilizzata solo quando si gioca in modalità Multiplayer.
*/

void function_finale(char*pa, char*ve, int n_col, int n, int m, char c, char c1) /*"pa" è il bicchiere del primo player, mente "ve" è il bicchiere del secondo player*/
{
    int round=1, turno=round%2, flag_1=0, flag_2=0, cambio_player=0, ModMultiplayer=1;

    while(flag_1 == 0 || flag_2 == 0){
        while(cambio_player == 0){ /*Quando cambio_player sarà==1 vuol dire che è finito il turno di un player e che ora tocca al altro lplayer fare la sua mossa.*/
            if(turno == 1 && flag_1 == 0){
                printf("\n\n------------------------------------------------------- PLAYER 1 -------------------------------------------------------\n\n");
                multiplayer(pa,n_col,n,m,c,c1,&flag_1,&cambio_player,turno,ModMultiplayer);
            }
            else if(turno == 0 && flag_2 == 0){
                printf("\n\n------------------------------------------------------- PLAYER 2 -------------------------------------------------------\n\n");
                multiplayer(ve,n_col,n,m,c,c1,&flag_2,&cambio_player,turno,ModMultiplayer);
            }
        }

        if(flag_1 == 0 && flag_2 == 0){
            round++;
            turno= round%2;     /*Modulo==1 vuol dire che è il turno del primo player, Modulo==0 è il turno del secondo player*/
        }
        else if(flag_1 == 1)    /*flag_1==1 vuol dire che il player_1 ha terminato le mosse da fare (risp==2) e d'ora in poi srà sempre il turno del player_2*/
            turno=0;
        else if(flag_2 == 1)    /*flag_2==1 vuol dire che il player_2 ha terminato le mosse da fare (risp==2) e d'ora in poi srà sempre il turno del player_1*/
            turno=1;

        cambio_player=0;

        if(flag_1 == 1 && flag_2 == 1) /*Entrambi i player non hanno più mosse da fare e ora tocca stabilire chi ha vinto, perso o se hanno pareggiato.*/
            winnerIS();
        /*printf("\n\nFLAG_uno: %d  FLAG_due: %d, CAMBIO: %d, TURNO: %d  ROUND: %d\n\n",flag_1,flag_2,cambio_player,turno,round);*/
    }
}



/*Ritorna il risultato finale della partita per stabilire, in caso di partita uno contro uno, chi tra i due giocatori ha vinto, perso o
  se hanno entrambi pareggiato o perso.

  N.B.
  Questa function viene utilizzata solo quando si gioca in modalità Multiplayer.
*/

void winnerIS()
{
    int indice1=read("indice_1.txt"), indice2=read("indice_2.txt");

    /*printf("\n\nIndice uno: %d, Indice due: %d\n\n",indice1,indice2);*/

    /*Se a termine della partita, per entrami i player, l'acqua non è fuoriuscita dal bicchiere, vince chi ha riempito di più il bicchiere.
      Se hanno raggiunto lo stesso lovello allora termina in pareggio.
    */

    if((indice1 >= 3 && indice2 >= 3) && (indice1 < indice2))
        printf("\n\nThe WINNER finale is PLAYER 1\n");
    else if((indice1 >= 3 && indice2 >= 3) && (indice2 < indice1))
        printf("\n\nThe WINNER finale is PLAYER 2\n");
    else if((indice1 >= 3 && indice2 >= 3) && (indice1 == indice2))
        printf("\n\nPAREGGIO!\n");

    /*Se l'acqua nel bicchiere del player 1 non è fuoriuscita, mentre quella del player 2 si, allora a vincere è il player 1;
      Se l'acqua nel bicchiere del player 1 è fuoriuscita, mentre quella del player 2 no, allora a vincere è il player 2;
      Se l'acqua nel bicchiere di entrambi i player è fuoriuscita dal bicchiere, allora hanno perso entrambi.
    */

    else if(indice1 >= 3 && indice2 < 3)
        printf("\n\nThe WINNER is PLAYER 1\n");
    else if(indice1 < 3 && indice2 >= 3)
        printf("\n\nThe WINNER is PLAYER 2\n");
    else if(indice1 < 3 && indice2 < 3)
        printf("\n\nPERSO ENTRAMBI!\n");
}


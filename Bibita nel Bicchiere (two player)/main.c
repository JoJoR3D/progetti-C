#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "prot.h"
#include "lib.c"


/*
    SPIEGAZIONE GIOCO:

    A questo gioco è possibile giocare in versione singolplayer e in versione multiplayer.
    In versione multiplayer ogni player durante il proprio turno potrà scegliere di aggiungere acqua al proprio bicchiere.
    Il gioco termina o quando il player decide di non aggiungere altra acqua o quando viene aggiunta troppa acqua e questa fuoriesce dal bicchiere.
*/





/*COSE DA FARE:
  Resettare i file una volta finita la sessione di gioco; FATTO!!!

  Inserire automaticamente, ad avvio gioco il valore 13 (dim iniziale righe array 2D) nel file t1.txt; FATTO!!!

  Si vince se l'acqua arriva al livello 3. FATTO!!

  Implementare tasto NO (RIsposta: 2) (se sto ad esempio, al indice 5, per vincere dovrebbe uscire un Valore= 3. Se dico NO, il gioco si interrompe e mi mostra
  quale valore sarebbe uscito se avessi detto si. Se il Valore uscito sarebbe stato 3 (acqua mancante), allora o perso, se invece è superiore a 3 allora
  ho vinto perchè se avessi risposto SI avrei perso perchè l'acqua sarebbe uscita dal bicchiere); FATTO!!!

  Riscrivere i file che contengono i valori generati (text) e il ciclo (t2) quando si compila il programma (cioè si ricomincia a giocare).
  Attualmente i file vengono riscritti solo se si termina la sessione di gioco. Se la si interrompe prima che termini, i file non vengono riscritti. FATTO!!!

  Indicare quanti ml mancano per vincere. FATTO!!!

  Possibilità di giocare a turni tra due giocatori. FATTO!!!

  Salvare il record migliore dei giocatori in un file. FATTO!!!

  Impediere che il secondo player usi lo stesso nick (salvato nel file Nome_utente) inserito dal  primo player. FATTO!!!

  Controllare perchè quando do risposta==2 (scelta==2), viene stampato ritentare. FATTO!!!

  Controllare se seclgo di creare un nuovo nome utente. FATTO!!!

  Indicare a fine partita chi dei due player ha vinto,o se hanno pareggiato o perso entrambi. FATTO!!!

  Chiedere a inizio gioco se si vuole giocare singol player o Multiplayer (uno contro uno). FATTO!!!

  In modalità Multiplayer: se entrambi gli utenti hanno vinto, alla fine verificare però chi ha aggiunto maggior acqua nel bicchiere.
  Chi ha più acqua nel bicchiere ha vinto.  FATTO!!!

  Indicare nel file utente, quante partite ha giocato e quante ne ha vinte. FATTO!!! però ogni utente ha due file: 1 indica quante partite ha giocato, mentre l'altro
  indica quante partite ha vinto a questo gioco.

  Se si inizia la partita ma nessuno si è mai registrato ma si iniza il gioco come se il player fosse già registrato (scelta==1), qualsiasi nick inserirebbe, il
  programma direbbe che non è presente. Questo perchè nel file: Nome_utente non è registrato alcun nome. FATTO!!!

  Migliorare il codice. FATTO!!!
*/




int main()
{
    /*DISEGNO BICCHIERE*/

    int i,j,n_col=8,m=8,n=14,ModMultiplayer;
    char carattere= '|';
    char carattere1= '-';

    /*Riscrive (inserendo lo spazio vuoto) i file che contengono i valori generati (text) e il ciclo (t2) quando si compila il programma (cioè si ricomincia a giocare
      una nuova sessione).
      Tramite questa funzione (rewrite), i file vengono riscritti sia se si termina la sessione di gioco osia se la si interrompe prima che termini.
      Chiamando questa funzione all'inizio del gioco, anche se precedentemente il gioco era stato interrotto prima della sua fine (o anche se si era terminata
      la sessione), quando si ricompilare per rigiocare, i due file verranno resettari per evitare che contengano valori della sessione di gioco precedente.
    */

    rewrite("valori_1.txt");
    rewrite("ciclo_1.txt");
    rewrite("valori_2.txt");
    rewrite("ciclo_2.txt");

    /*Ad inizio gioco, nel file "t1,txt" (che contine l'indice a partire del quale va inserita l'acqua nel bicchiere) viene registrato il valore 13
      (fondo del bicchiere).
      L'indice viene aggiornato ad ogni iterazione. A tale valore viene sottratta la precedente posizione che indica fin dove è arrivata l'acuqa, meno l'attuale
      valore generato che indica quanta altra acqua deve essere aggiunta nel bicchiere (*indice= pointer-valore; Vedere function visualizza).
      Cioè l'acqua potà essere inserita a partire dalla posizione 3 fino ad arrivare alla posizione 13 (Alla posizione 14 vi è la struttura finale del bicchiere).
    */

    write(13,"indice_1.txt");
    write(13,"indice_2.txt");

    char bicchiere[][8]=
    {
        {'-','-','-','-','-','-','-','-',},
        {'|',' ',' ',' ',' ',' ',' ','|'},
        {'|','-','-','-','-','-','-','|'},
        {'|',' ',' ',' ',' ',' ',' ','|'},
        {'|',' ',' ',' ',' ',' ',' ','|'},
        {'|',' ',' ',' ',' ',' ',' ','|'},
        {'|',' ',' ',' ',' ',' ',' ','|'},
        {'|',' ',' ',' ',' ',' ',' ','|'},
        {'|',' ',' ',' ',' ',' ',' ','|'},
        {'|',' ',' ',' ',' ',' ',' ','|'},
        {'|',' ',' ',' ',' ',' ',' ','|'},
        {'|',' ',' ',' ',' ',' ',' ','|'},
        {'|',' ',' ',' ',' ',' ',' ','|'},
        {'-','-','-','-','-','-','-','-',}
    };

    char bicchiere2[][8]=
    {
        {'-','-','-','-','-','-','-','-',},
        {'|',' ',' ',' ',' ',' ',' ','|'},
        {'|','-','-','-','-','-','-','|'},
        {'|',' ',' ',' ',' ',' ',' ','|'},
        {'|',' ',' ',' ',' ',' ',' ','|'},
        {'|',' ',' ',' ',' ',' ',' ','|'},
        {'|',' ',' ',' ',' ',' ',' ','|'},
        {'|',' ',' ',' ',' ',' ',' ','|'},
        {'|',' ',' ',' ',' ',' ',' ','|'},
        {'|',' ',' ',' ',' ',' ',' ','|'},
        {'|',' ',' ',' ',' ',' ',' ','|'},
        {'|',' ',' ',' ',' ',' ',' ','|'},
        {'|',' ',' ',' ',' ',' ',' ','|'},
        {'-','-','-','-','-','-','-','-',}
    };

    /*VISUALIZZA BICCHIERE*/

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
           printf("%c  ",bicchiere[i][j]);
        }
        printf("\n");
    }

    ModMultiplayer= Modpartita();   /*Ritorna la scelta del giocatore: 0 per giocare in modalità Singolplayer, 1 per modalità Multiplayer (uno contro uno).*/

    if(ModMultiplayer == 1)
        function_finale(&bicchiere[0][0],&bicchiere2[0][0],n_col,n,m,carattere,carattere1);
    else
        singolplayer(&bicchiere[0][0],n_col,n,m,carattere,carattere1,ModMultiplayer);

    return 0;
}

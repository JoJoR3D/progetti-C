#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "prot.h"
#include "lib.c"


/*
    SPIEGAZIONE GIOCO:

    A questo gioco è possibile giocare in versione singolplayer
    Il player potrà scegliere di aggiungere acqua al proprio bicchiere.
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

  Possibilità di giocare a turni tra due giocatori. FATTO in progetto versione multiplayer!

  Salvare il record migliore dei giocatori in un file. FATTO!!!
*/




int main()
{
    /*DISEGNO BICCHIERE*/

    int i,j,n_col=8,m=8,n=14;
    char carattere= '|';
    char carattere1= '-';

    /*Riscrive (inserendo lo spazio vuoto) i file che contengono i valori generati (text) e il ciclo (t2) quando si compila il programma (cioè si ricomincia a giocare
      una nuova sessione).
      Tramite questa funzione (rewrite), i file vengono riscritti sia se si termina la sessione di gioco osia se la si interrompe prima che termini.
      Chiamando questa funzione all'inizio del gioco, anche se precedentemente il gioco era stato interrotto prima della sua fine (o anche se si era terminata
      la sessione), quando si ricompilare per rigiocare, i due file verranno resettari per evitare che contengano valori della sessione di gioco precedente.
    */

    rewrite("text.txt");
    rewrite("t2.txt");

    /*Ad inizio gioco, nel file "t1,txt" (che contine l'indice a partire del quale va inserita l'acqua nel bicchiere) viene registrato il valore 13
      (fondo del bicchiere).
      L'indice viene aggiornato ad ogni iterazione. A tale valore viene sottratta la precedente posizione che indica fin dove è arrivata l'acuqa, meno l'attuale
      valore generato che indica quanta altra acqua deve essere aggiunta nel bicchiere (*indice= pointer-valore; Vedere function visualizza).
      Cioè l'acqua potà essere inserita a partire dalla posizione 3 fino ad arrivare alla posizione 13 (Alla posizione 14 vi è la struttura finale del bicchiere).
    */

    write(13,"t1.txt");

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

    /*VISUALIZZA BICCHIERE*/

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
           printf("%c  ",bicchiere[i][j]);
        }
        printf("\n");
    }

    cont_versa(&bicchiere[0][0],n_col,n,m,carattere,carattere1);

    return 0;
}


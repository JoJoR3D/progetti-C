
/*Lo scopo della function shell_sort è quello di ordinare ciascuna colonna del array che gli viene passato dal main.*/

void shell_sort(int*a, int n_col, int n, int m)             /*'n' sono le colonne, mentre 'm' sono le righe.*/
{
    int i, j, z=0, el_da_ins, cont=0;

    while(z < n && cont != 1)
    {
        for(z=0;z<n;z++){                                   /*Con questo ciclo for tengo fissa la colonna (n), mentre con il for più interno scorro le righe (m)*/
            for(i=1;i<m;i++){                               /* 'i' inizia da 1 e non da 0, perchè si presume che il primo elemento dell'array sia già ordinato; ad ogni ciclo la 'i' si incrementa */

                el_da_ins= *(a+n_col*i+z);                  /*el_da_ins è uguale all'elemento presente alla posizione a[1], perchè 'i' è uguale a 1 */
                j=i-1;                                      /* j=i-1, ovvero j=0 */
                while(j>=0 && el_da_ins < *(a+n_col*j+z)){  /*Quando entro in questo while è per scambiare due valori. el_da_ins è minore dell'elemento presente alla posizione a[0]?, a[0] perchè 'j' è uguale a 0 */
                    *(a+n_col*(j+1)+z)= *(a+n_col*j+z);     /* a[0+1] è uguale a[0] */
                    j--;                                    /*decremento j, era uguale a 0, decrementando j=-1, essendo -1, 'j' è maggiore uguale di zero? NO, esco dal while */
                    cont=1;                                 /*Se sono entrato in questo while è perchè devo scambiare i due valori perché el_da_ins (che è a[i], cioè
                                                              a[1]) è < di a[j] (cioè a[0]). Quindi ogni qual volta eseguo lo scambio pongo cont=1.*/
                }
                *(a+n_col*(j+1)+z)= el_da_ins;              /* a[-1+1] cioè a[0] è uguale a el_da_ins; finito questo primo ciclo, vado avanti incrementando 'i' che ora è uguale a 2; e cosi via */
            }
        }
    }                                                       /*Quando z è == n (cioè si sono verificati tutti gli elementi della colonna n) && cont è == 0 (cioè
                                                              cont è == 0 quando non si entra mai nel ciclo while più interno per eseguire lo scampio tra due valori*/


    /*printf("\nStampa array ordinato\n\n");*/              /*La stampa del array ordinato basato sul nuovo numero di colonne (n) e righe (m) che dichiaro tramite
                                                              scanf nel ciclo while del main, devo per forza dichiararla qui e no nel main perchè se la dichiaro
                                                              nel main mi considera i primi valori di (n) e (m) che ho dato e no quelli che aggiorno ad ogni ciclo.

                                                              HO TROVATO UNA SOLUZIONE A QUESTO PROBLEMA: Ho creato una function 'visualizza' che stampa, ogni volta,
                                                              l'array ordinato.*/

    /*for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d ",*(a+n_col*i+j));
        }
        printf("\n");
    }*/
}




/*Lo scopo della function visualizza è quello di stampare l'array ordinato ottenuto dalla function shell_sort.*/

void visualizza(int*a, int n_col, int n, int m)
{
    int i,j;

    printf("\nStampa array ordinato\n\n");

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d ",*(a+n_col*i+j));
        }
        printf("\n");
    }
}

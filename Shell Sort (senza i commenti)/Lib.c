
/*Lo scopo della function shell_sort � quello di ordinare ciascuna colonna del array che gli viene passato dal main.*/

void shell_sort(int*a, int n_col, int n, int m)             /*'n' sono le colonne, mentre 'm' sono le righe.*/
{
    int i, j, z=0, el_da_ins, cont=0;

    while(z < n && cont != 1)
    {
        for(z=0;z<n;z++){                                   /*Con questo ciclo for tengo fissa la colonna (n), mentre con il for pi� interno scorro le righe (m)*/
            for(i=1;i<m;i++){                               /* 'i' inizia da 1 e non da 0, perch� si presume che il primo elemento dell'array sia gi� ordinato; ad ogni ciclo la 'i' si incrementa */

                el_da_ins= *(a+n_col*i+z);                  /*el_da_ins � uguale all'elemento presente alla posizione a[1], perch� 'i' � uguale a 1 */
                j=i-1;                                      /* j=i-1, ovvero j=0 */
                while(j>=0 && el_da_ins < *(a+n_col*j+z)){  /*Quando entro in questo while � per scambiare due valori. el_da_ins � minore dell'elemento presente alla posizione a[0]?, a[0] perch� 'j' � uguale a 0 */
                    *(a+n_col*(j+1)+z)= *(a+n_col*j+z);     /* a[0+1] � uguale a[0] */
                    j--;                                    /*decremento j, era uguale a 0, decrementando j=-1, essendo -1, 'j' � maggiore uguale di zero? NO, esco dal while */
                    cont=1;                                 /*Se sono entrato in questo while � perch� devo scambiare i due valori perch� el_da_ins (che � a[i], cio�
                                                              a[1]) � < di a[j] (cio� a[0]). Quindi ogni qual volta eseguo lo scambio pongo cont=1.*/
                }
                *(a+n_col*(j+1)+z)= el_da_ins;              /* a[-1+1] cio� a[0] � uguale a el_da_ins; finito questo primo ciclo, vado avanti incrementando 'i' che ora � uguale a 2; e cosi via */
            }
        }
    }                                                       /*Quando z � == n (cio� si sono verificati tutti gli elementi della colonna n) && cont � == 0 (cio�
                                                              cont � == 0 quando non si entra mai nel ciclo while pi� interno per eseguire lo scampio tra due valori*/


    /*printf("\nStampa array ordinato\n\n");*/              /*La stampa del array ordinato basato sul nuovo numero di colonne (n) e righe (m) che dichiaro tramite
                                                              scanf nel ciclo while del main, devo per forza dichiararla qui e no nel main perch� se la dichiaro
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




/*Lo scopo della function visualizza � quello di stampare l'array ordinato ottenuto dalla function shell_sort.*/

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

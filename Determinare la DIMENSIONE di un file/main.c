#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main()
{
    int*s;
    int i,n,posizione=0;
    printf("Inserire il numero di interi che si vorrebbe inserire nel file binario: ");
    scanf("%d",&n);
    n=n*4;          /*Se voglio inserire ad esempio 3 interi, ogni intero occupa 4 byte, per questo moltiplico il numero di interi da inserire (n) per 4byte.
                      'n' mi serve per allocare uno spazio di memoria sufficiente per contenere un tot numero di interi.*/

    s=(int*)malloc(n*sizeof(int));
    int dim= n/4;                   /*Diviso per 4 perchè ogni intero occupa in memoria 4byte.
                                      'dim' mi consente di inserire il numero di interi che ho scelto all'inizio.*/

    printf("\nInserisci %d valori:\n",dim);
    for(i=0;i<dim;i++){
        scanf("%d",&s[i]);          /*Inserisco i 10 interi nella porzione di memoria allocata dinamicamente*/
    }

    printf("\n\n");
    FILE*x;
    x=fopen("file.dat","w");

    if(x == NULL){
        printf("Si e' verificato un'errore\n");
        exit(1);
    }

    i=0;
    while(i < dim){
        posizione=ftell(x);                 /*Salvo la posizione del cursone nel file che punta ad un intero*/
        fwrite(&s[i],sizeof(int),1,x);
        printf("Posizione: %d, Valore nel file: %d\n",posizione,s[i]);
        fseek(x,posizione+4,SEEK_SET);      /*Avanzo il cursore di 4byte in modo che possa leggere il prossimo intero*/
        i++;
    }
    posizione=posizione+4;                  /*Aggiungo 4byte alla posizione perchè ad inizio ciclo posizione=ftell(x) parte a contare il primo intero da 0,
                                              poi conta il secondo intero da 4 byte e cos' via.
                                              Quindi, ad esempio, se nel file sono presenti 3 interi, all'inizio del ciclo alla lettura del primo intero
                                              posizione sarà=0, alla lettura del secondo intero posizione sarà=4, e infine alla lettura del terzo intero posizione
                                              sarà=8.
                                              Essendo 3 interi, il numero di byte occupati è 12byte (3*4byte), ma poichè la lettura del primo intero parte da zero,
                                              è come se il primo intero non venisse considerato, per questo alla fine posizione ritorna= 8byte.
                                              Ed è per questo che alla fine aggiungo a posizione altri 4byte. In questo modo ora posizione contiene il nuemro di
                                              byte corrispondenti a 3 interi ovvero: 12byte.
                                            */

    printf("\nIl file contiene %d interi che occupano in memoria %d byte\n",dim,posizione);

    fclose(x);





    /*--------------------LETTURA DEI VALORI PRESENTI NEL FILE BINARIO--------------------*/

    printf("\n\n");
    int var;
    FILE*y;
    y=fopen("file.dat","r");

    if(y == NULL){
        printf("si e' verificato un'errore\n");
        exit(1);
    }

    printf("Lettura dei valori presenti nel file binario\n");
    i=0;
    while(i < dim){
        fread(&var,sizeof(int),1,y);
        i++;
        fseek(y,i*4,SEEK_SET);      /*Per leggere il successivo intero del file, avanzo di 4byte. Ogni volta parto dall'inizio del file (SEEK_SET), e per
                                      raggiungere la posizione successiva moltiplico 4byte per il valore 'i'.
                                      Ad esempio se 'i' è == 2, vuol dire che sto al terzo ciclo while e che quindi dovrei leggere il 3 intero del file. Iinfatti
                                      moltiplicando i=2*4byte ottengo 8byte che corrisponde al terzo intero.
                                      Ricorda:
                                      Da 0 a 3 byte corrisponde al primo intero del file;
                                      Da 4 a 7 byte corrisponde al secondo intero del file;
                                      Da 8 a 11 byte corrisponde al terzo intero del file;
                                      ecc...
                                    */
        printf("%d\n",var);
    }

    fclose(y);










    /*-----------------------SECONDO METODO PER DETERMINARE LA DIMENSIONE DI UN FILE-----------------------*/

    /*
        Un secondo metodo per determinare la dimensione di un file consiste nell'uso della funzione stat. Questa funzione ha due parametri: il primo è il
        nome di un file (che non deve necessariamente essere stato aperto), e l'indirizzo di una variabile di tipo struct stat.
        Questa funzione modifica la struttura mettendoci i valori di alcune caratteristiche del file. In particolare, il campo st_size della struttura
        contiene la dimensione del file, ossia il numero di byte che contiene.

        Per usare la funzione stat è necessaria la definizione della struttura struct stat, che si trova nel file header sys/stat.h.
    */


    printf("\n\n\nSECONDO METODO PER DETERMINARE LA DIMENSIONE DI UN FILE\n");
    struct stat punt;
    int size;

    stat("file.dat",&punt);     /*Chiamo la funzione stat*/

    FILE*z;
    z=fopen("file.dat","r");

    if(z == NULL){
        printf("Si e' verificato un'errore\n");
        exit(1);
    }

    printf("Dimensione in byte del file binario: ");
    size=punt.st_size;      /*Passo alla variabile size (di tipo int), la chiamata al metodo .st_size contenuta nella struct passata alla variabile punt*/
    printf("%d\n",size);    /*Il campo st_size della struttura contiene la dimensione del file, ossia il numero di byte che contiene il file.*/

    return 0;
}

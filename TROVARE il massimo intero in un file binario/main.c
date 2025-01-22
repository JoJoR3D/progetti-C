#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char file[]="file.dat";     /*.dat è un file generico che può contenere qualsiasi tipo di dati*/
    int i=0,valore,n=10;

    srand(time(NULL));


    /*-----------------SCRITTURA DI VALORI GENERATI CASUALMENTE SU UN FILE BINARIO-----------------*/

    printf("SCRITTURA dei valori nel file binario:\n");
    FILE*x;
    x=fopen(file,"w");

    if(x == NULL){
        printf("Si e' verificato un'errore\n");
        exit(1);
    }

    while(i < n){
        valore= 1+rand()%9;                 /*Genera valori casuali da 1 a 9*/
        fwrite(&valore,sizeof(int),1,x);
        i++;
        printf("%d\n",valore);
    }

    fclose(x);





    /*-----------------TROVARE IL VALORE MASSIMO IN UN FILE E SOSTITUISCILO CON IL VALORE ZERO-----------------*/

    int posizione,max=0,zero=0;
    FILE*y;
    y=fopen(file,"r+");     /*Apertura del file in lettura e scrittura*/

    if(y == NULL){
        printf("Si e' verificato un'errore\n");
        exit(1);
    }

    i=0;
    while(i < n-1){
        fread(&valore,sizeof(int),1,y); /*Leggo i valori del file uno alla volta*/

        if(valore > max){               /*Se il valore letto è maggiore di max salvo il valore e la posizione.*/
            max=valore;
            posizione=ftell(y);         /*Mi ritorna un intero (espresso in byte) che indica la posizione del cursore nel file.
                                          Ad esempio se ritorna 12, vuol dire che il cursore si trova al 4 intero del file.
                                          Se, ad esempio, mi ritornava 4, vuol dire che il cursore si trova al 2 elemento del file.
                                        */
        }

        i++;
    }

    printf("\nPOSIZIONE in byte valore massimo: %d\nValore massimo: %d\n",posizione,max);

    /*Poichè dopo l'fread() il cursore avanza per puntare al prossimo valore del file, la variabile posizione non conterrà la posizione del
      valore massimo ma la posizione del valore successivo (questo per effetto del fread()).
      Per questo uso fseek() per portarmi, partendo dal'inizio del file(SEEK_SET), al byte indicato da posizione a cui tolgo 4byte (4 perchè ogni intero nel
      file binario, così come in memoria, occupa 4byte).
      In questo modo ora posizione contiene la posizione del valore massimo e no la posizione del valore successivo a quello
      massimo.
    */
    fseek(y,posizione-4,SEEK_SET);
    fwrite(&zero,sizeof(int),1,y);

    fclose(y);






    /*-----------------LETTURA DEI VALORI DAL FILE BINARIO-----------------*/

    printf("\n\nLETTURA valori:\n");
    FILE*z;
    z=fopen(file,"r+");

    if(z == NULL){
        printf("Si e' verificato un'errore\n");
        exit(1);
    }

    i=0;
    while(i < n){
        fread(&valore,sizeof(int),1,z);
        i++;
        printf("%d\n",valore);
    }

    fclose(z);

    return 0;
}

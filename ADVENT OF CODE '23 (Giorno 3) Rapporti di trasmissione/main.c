#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
20492 è troppo bassa
23161 è troppo bassa
24762 è troppo bassa
392940 non è la risposta giusta
393627 non è la risposta giusta
397246 non è la risposta giusta

525181 E' LA RISPOSTA CORRETTA!!!
*/

int main()
{
    char c[140][300];
    char*ptr;
    char numb[4];
    int rit,flag=0,somma=0,indice=0,cont=0;

    int i,j;

    /*Inizializzo l'array 2D con spazi vuoti*/
    for(i=0;i<140;i++){
        for(j=0;j<300;j++)
            c[i][j]= ' ';
    }

    i=0,j=0;


    FILE*fp;

    fp=fopen("input.txt","r");

    if(fp == NULL){
        printf("Si e' verificato un'errore\n");
        exit(1);
    }


    /*Leggo carattere per carattere del file e lo copio nell'array 2D c.*/

    while(!feof(fp)){
        fscanf(fp,"%c",&c[i][j]);
        printf("%c",c[i][j]);

        if(c[i][j] == '\n'){
            i++;
            j=0;
        }
        else
            j++;
    }

    fclose(fp);




    i=0,j=0;
    printf("\n\nRIGA %d\n",i);

    /*
    Quando trovo un numero, vedo se nelle sue vicinanze (sopra,sotto,diagonale) vi è un simbolo (i simboli sono quelli da 35 a 45, 47 e da 58 a 140 Tabella ASCII).
    il numero lo salvo nell'array numb. Se il numero è adiacente a un simbolo, viene attivato il flag=1.
    Quando il carattere letto non è più un numero, esco dal if e vado nell'else. Se il flag è ==1 (numero adiacente a un simbolo), il carattere numerico viene
    convertito in un numero intero (funzione strtol) e sommato alla variabile somma.
    Se il flag è == 0 il carattere numerico non viene convertito.
    A prescindere dal flag, quando si entra nel else la variabiòe numb viene ripulita ponendo tutte le sue posizioni uguale a zero.

    Il ciclo termina quando vengono letti un certo numero di spazi vuoti (cont < 4). Questo perche l'array 2D 'c' all'inizio è stato inizializzato con spazi vuoti.
    Quindi se ci sono un tot di spazi vuoti vuol dire che non ci sono più caratteri.
    cont è < 4 perchè nel file, in alcune righe ci sono anche degli spazi vuoti come caratteri, ma in genere non sono più di 2 o 3.
    */

    while(cont < 4/*i < 140*/){
        if(c[i][j] >= 48 && c[i][j] <= 57){
            printf("CAR: %c %d\n",c[i][j],i);
            if(i > 0){
                if((c[i+1][j] >= 35 && c[i+1][j] <= 45 && i+1 < 140) || (c[i+1][j] == 47 && i+1 < 140) || (c[i+1][j] >= 58 && c[i+1][j] <= 64 && i+1 < 140))
                    flag=1;
                else if((c[i][j+1] >= 35 && c[i][j+1] <= 45) || c[i][j+1] == 47 || (c[i][j+1] >= 58 && c[i][j+1] <= 64))
                    flag=1;
                else if((c[i][j-1] >= 35 && c[i][j-1] <= 45) || c[i][j-1] == 47 || (c[i][j-1] >= 58 && c[i][j-1] <= 64))
                    flag=1;
                else if((c[i+1][j+1] >= 35 && c[i+1][j+1] <= 45 && i+1 < 140) || (c[i+1][j+1] == 47 && i+1 < 140) || (c[i+1][j+1] >= 58 && c[i+1][j+1] <= 64 && i+1 < 140))
                    flag=1;
                else if((c[i+1][j-1] >= 35 && c[i+1][j-1] <= 45 && i+1 < 140) || (c[i+1][j-1] == 47 && i+1 < 140) || (c[i+1][j-1] >= 58 && c[i+1][j-1] <= 64 && i+1 < 140))
                    flag=1;

                else if((c[i-1][j] >= 35 && c[i-1][j] <= 45) || c[i-1][j] == 47 || (c[i-1][j] >= 58 && c[i-1][j] <= 64))
                    flag=1;
                else if((c[i-1][j-1] >= 35 && c[i-1][j-1] <= 45) || c[i-1][j-1] == 47 || (c[i-1][j-1] >= 58 && c[i-1][j-1] <= 64))
                    flag=1;
                else if((c[i-1][j+1] >= 35 && c[i-1][j+1] <= 45) || c[i-1][j+1] == 47 || (c[i-1][j+1] >= 58 && c[i-1][j+1] <= 64))
                    flag=1;

                numb[indice]= c[i][j];
                indice++;
            }
            else if(i == 0){    /*Vale solo per il primo rigo (i==0)*/
                if((c[i+1][j] >= 35 && c[i+1][j] <= 45) || c[i+1][j] == 47 || (c[i+1][j] >= 58 && c[i+1][j] <= 64))
                    flag=1;
                else if((c[i][j+1] >= 35 && c[i][j+1] <= 45) || c[i][j+1] == 47 || (c[i][j+1] >= 58 && c[i][j+1] <= 64))
                    flag=1;
                else if((c[i][j-1] >= 35 && c[i][j-1] <= 45) || c[i][j-1] == 47 || (c[i][j-1] >= 58 && c[i][j-1] <= 64))
                    flag=1;
                else if((c[i+1][j+1] >= 35 && c[i+1][j+1] <= 45) || c[i+1][j+1] == 47 || (c[i+1][j+1] >= 58 && c[i+1][j+1] <= 64))
                    flag=1;
                else if((c[i+1][j-1] >= 35 && c[i+1][j-1] <= 45) || c[i+1][j-1] == 47 || (c[i+1][j-1] >= 58 && c[i+1][j-1] <= 64))
                    flag=1;

                 numb[indice]= c[i][j];
                 indice++;
            }
        }
        else if(c[i][j] == 0){
            cont++;
            printf("\nCONTTTTTTTTTTTTTTTTTTTT :%d\n",cont);

            if(cont == 4)
                break;
        }
        else{
            if(flag == 1){
                rit=strtol(numb,&ptr,10);
                somma= somma + rit;
                printf("RIT: %d, SOMMA: %d, Indice: %d\n",rit,somma,i);
            }
            indice=0;
            flag=0;
            cont=0;
            numb[0]=0;
            numb[1]=0;
            numb[2]=0;
            numb[3]=0;
        }

        if(c[i][j] == '\n' && i < 140){
            i++;
            j=0;
            printf("\nRIGA :%d\n",i);
        }
        else
            j++;
    }

    printf("\nSOMMA FINALE: %d, Indice: %d\n",somma,i);

    return 0;
}

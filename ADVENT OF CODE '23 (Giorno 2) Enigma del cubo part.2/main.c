#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*2278 RISPOSTA CORRETTA!!!*/


int main()
{
    /*char*s[]= {"red","green","blue"};*/
    char*numb[]= {"0","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20"};
    char t[50];
    char*ptr;

    int red[100][20];
    int green[100][20];
    int blue[100][20];

    /*char*rr="30";
    printf("%d",*rr);*/

    int i,j,indice=-1,indiceJred=0,indiceJgreen=0,indiceJblue=0,contenitore=0,cont=0,operazione=0,rit;

    for(i=0; i<100; i++){
        for(j=0; j<20; j++){
            red[i][j]=0;
            green[i][j]=0;
            blue[i][j]=0;
        }
    }

    i=0;


    FILE*fp;

    fp= fopen("input.txt","r");

    if(fp == NULL){
        printf("Si e' verificato un'errore\n");
        exit(1);
    }

    /*Leggo gli elementi dal file*/

    while(!feof(fp)){
        fscanf(fp,"%s",t);
        printf("STRINGA: ");
        puts(t);

        if(t[0] >= 48 && t[0] <= 57){
            for(i=0;i<20;i++){
                if(t[0] == *numb[i] && (strcmp(&t[1],":")<0)){ /*Trova il valore numerico prima del colore*/
                    rit=strtol(t,&ptr,10);                     /*Trasforma il carattere numerico in un intero*/
                    contenitore= rit;
                    printf("\nContenitore: %d\n",contenitore);
                    operazione=1;
                    break;
                }
            }
        }

        if(operazione == 0/*cont == 1*/){                             /*Associa il valore numerico trovato al suo colore*/
            printf("\nIndice: %d\n",indice);
            if(t[0] == 'r'){
                printf("\nDentro 1\n");
                red[indice][indiceJred]= contenitore;
                indiceJred++;
                printf("\n%d\n",red[indice][indiceJred]);
            }
            else if(t[0] == 'g'){
                printf("\nDentro 2\n");
                green[indice][indiceJgreen]= contenitore;
                indiceJgreen++;
                printf("\n%d\n",green[indice][indiceJgreen]);
            }
            else if(t[0] == 'b'){
                printf("\nDentro 3 %c\n",t[0]);
                blue[indice][indiceJblue]= contenitore;
                indiceJblue++;
                printf("\n%d\n",blue[indice][indiceJblue]);
            }
        }


        if(strcmp(&t[0],"Game")==0){
            indice++;
            indiceJred=0,indiceJgreen=0,indiceJblue=0;
            printf("\nIII: %d\n",indice);
        }

        printf("\nCont: %d, Operazione: %d",cont,operazione);
        /*if(operazione == 1)
            cont=1;
        else if(operazione == 0)
            cont=0;*/
        if(operazione == 1)
            operazione=0;

        printf("\n\n\n");
    }

    fclose(fp);




    /*Stampo i tre array dei tre colori contenenti i valori numerici*/

    printf("\nRED\n");

    for(i=0; i<100; i++){
        printf("%d) ",i);
        for(j=0; j<20; j++)
            printf("%d ",red[i][j]);
        printf("\n");
    }

    printf("\n\nGREEN\n");

    for(i=0; i<100; i++){
        printf("%d) ",i);
        for(j=0; j<20; j++)
            printf("%d ",green[i][j]);
        printf("\n");
    }

    printf("\n\nBLUE\n");

    for(i=0; i<100; i++){
        printf("%d) ",i);
        for(j=0; j<20; j++)
            printf("%d ",blue[i][j]);
        printf("\n");
    }

    printf("\n\n");






    /*Eseguo i calcoli richiesti dalla traccia*/


    int maxRed=red[0][0],maxGreen=green[0][0],maxBlue=blue[0][0],somma=0;


    for(i=0;i<100;i++){
        for(j=0;j<20;j++){
            if(red[i][j] > maxRed)
                maxRed= red[i][j];
            if(green[i][j] > maxGreen)
                maxGreen= green[i][j];
            if(blue[i][j] > maxBlue)
                maxBlue= blue[i][j];
        }
        somma= somma + (maxRed*maxGreen*maxBlue);
        maxRed=0, maxGreen=0, maxBlue=0;
    }

    printf("\nSomma: %d\n",somma);

    return 0;
}

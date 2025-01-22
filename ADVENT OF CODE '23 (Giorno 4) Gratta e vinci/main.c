#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
1525 risposta troppo bassa
49860 risposta troppo alta

25010 QUESTA E' LA RISPOSTA GIUSTA
*/


int main()
{
    char car[213][117];
    char numb[3];
    char*ptr;
    int i=0,j=0,indice=0,indiceJ,rit=0,rit2=0,punti=0,somma=0,cont=0,in=0,card=0;

    FILE*fp;
    fp=fopen("input.txt","r");

    if(fp == NULL){
        printf("\nSi e' verificato un'errore\n");
        exit(1);
    }

    while(!feof(fp)){
        fscanf(fp,"%c",&car[i][j]);
        printf("%c",car[i][j]);

        if(car[i][j] == '\n'){
            i++;
            j=0;
        }
        else
            j++;
    }

    fclose(fp);



    i=0,j=0;

    while(car[i][j] != '?'){
        if(car[i][j] == ':'){
            j=j+2;
            printf("\n\n\nCARD: %d",++card);
            while(cont < 10){
                /*printf("\nCARATTERE_1: %c\n",car[i][j]);*/
                while(car[i][j] == ' '){
                    j++;
                }
                while(car[i][j] != ' '){
                    if(car[i][j] >= 48 && car[i][j] <= 57){
                        numb[indice]= car[i][j];
                        indice++;
                    }
                    if(car[i][j+1] == ' '){
                        rit=strtol(numb,&ptr,10);
                        cont++;
                        printf("\nCONT: %d, RIT: %d\n",cont,rit);
                    }
                    j++;
                }
                indiceJ= j;
                /*printf("\nINDICE: %d\n",indiceJ);*/
                numb[0]= ' ';
                numb[1]= ' ';
                indice=0;

                while(car[i][j] != '|'){
                    j++;
                }

                j=j+2;

                while(car[i][j] != '\n'){
                    if(car[i][j] >= 48 && car[i][j] <= 57){
                        numb[indice]= car[i][j];
                        /*printf("\nCARATTERE: %c, Indice: %d\n",numb[indice],indice);*/
                        indice++;
                        in=1;
                    }
                    if(car[i][j+1] == '\n' || (car[i][j] == ' ' && in > 0)){
                        rit2=strtol(numb,&ptr,10);
                        numb[0]= ' ';
                        numb[1]= ' ';
                        indice=0;
                        printf("\nRIT2: %d\n",rit2);

                        if(rit == rit2){
                            if(punti < 2)
                                punti++;
                            else
                                punti= punti*2;

                            printf("\nPUNTIIIIIIIIIIIIIIIIIII: %d\n",punti);
                            break;
                        }
                        else{
                            rit2=0;
                            in=0;
                        }
                    }
                    j++;
                }

                if(cont == 10){
                    i++;
                    j=0;
                    cont=0;
                    somma=somma + punti;
                    printf("\nSomma card %d: %d\n",card,somma);
                    punti=0;
                    break;
                }
                else{
                    j= indiceJ+1;
                    /*printf("\nDENTRO: %d\n\n\n\n",j);*/
                }
            }
        }
        else
            j++;
    }

    return 0;
}

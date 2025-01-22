#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
SPIEGAZIONE:

Non esistono i "punti". Invece, i gratta e vinci ti fanno solo vincere più gratta e vinci pari al numero di numeri vincenti che hai.
Nello specifico, vinci copie dei gratta e vinci sotto la carta vincente pari al numero di partite. Quindi, se la carta 10 avesse 5 numeri corrispondenti,
vinceresti una copia ciascuna delle carte 11, 12, 13, 14 e 15.
Le copie dei gratta e vinci vengono valutate come i normali gratta e vinci e hanno lo stesso numero di carta della carta copiata.
Quindi, se vinci una copia della carta 10 e ha 5 numeri corrispondenti,
vincerai una copia delle stesse carte vinte dalla carta 10 originale: carte 11, 12, 13, 14 e 15.
Questo processo si ripete fino a quando nessuna delle copie ti fa vincere altre carte.
(Le carte non ti faranno mai copiare una carta oltre la fine del tavolo.)
*/

/*Ho rinominato la variabile 'punti' del GIORNO 4 in 'win_carte' qui in GIORNO 4 parte 2*/

/*
1242393 risposta troppo bassa
9903605 risposta troppo bassa

9924412 QUESTA E' LA RISPOSTA GIUSTA!!!
*/


/*win_carte=win_carte-2 non va bene. RISOLTO!!!*/



void conteggio(int i, int win_carte, int risultato[], int copia);



int main()
{
    char car[214][117];
    char numb[3];
    char*ptr;
    int risultato[213];
    int i=0,j=0,indice=0,indiceJ,rit=0,rit2=0,win_carte=i+1,somma=0,cont=0,in=0,card=0,dentro=0;
    int copia=0,carta=0,flag=0,ciclo=0;


    for(i=0;i<213;i++)
        risultato[i]= 0;    /*Pulisco il contenuto di risultato[]*/

    i=0;


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
            carta++;
        }
        else
            j++;
    }

    fclose(fp);

    printf("\n\nCARTA: %d\n\n",carta);  /*Indica quante sono il numero di Carte in input*/

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
                        /*printf("\nCONT: %d, RIT: %d\n",cont,rit);*/
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
                        /*printf("\nRIT2: %d\n",rit2);*/

    /*Aumenta copia quando ad esempio, la secondultima carta: 210 ha 4 carte uguali. Ciò significa che vince 4 carte successive, ma le carte successive sono solo
      due, ovvero: 211 e 212. Ciò significa che vince due volte la carta 211 e due la 212, quindi copia sarà == 2 (perchè deve ricontare altre due ovlte le
      carte 211 e 212).
      Se la carta 210 aveva 6 carte uguali allora vince tre volte la carta 211 e tre la 212, quindi copia sarà == 4 (perchè deve ricontare altre quattro volte
      le carte 211 e 212).
    */

                        if(rit == rit2){
                            if(win_carte < carta)
                                win_carte++;
                            else
                                copia++;

                            /*printf("\nPUNTIIIIIIIIIIIIIIIIIII: %d, COPIE: %d\n",win_carte, copia);*/
                            dentro=1;
                            break;
                        }
                        else{
                            rit2=0;
                            in=0;
                        }
                    }
                    j++;
                }

                j= indiceJ+1;

                if(cont == 10/*car[i][j] == '|'*/){
                    i++;
                    j=0;
                    /*cont=0;*/
                    break;
                }
            }
            cont=0;

            int x= win_carte;
            int y= copia;

            printf("\nWIN_C %d, I: %d\n",win_carte,i);

            while(win_carte > i || copia > 0){   /*Se la carta (i) è 1, allora saranno copiate le carte (punti) fino al minimo di 2*/
                printf("\nCarta %d, win_carte: %d, Copia: %d\n",i,win_carte,copia);
                if(win_carte > i){
                    risultato[win_carte]= risultato[win_carte]+1;
                    win_carte--;
                    flag=1;
                }


        /*Si entra qui sotto quando ad esempio, la secondultima carta: 210 ha 4 carte uguali.
          Ciò significa che vince 4 carte successive, ma le carte successive sono solo due, ovvero: 211 e 212. Ciò significa che vince due volte la carta 211 e
          due la 212, quindi copia sarà == 2 (perchè deve ricontare altre due ovlte le carte 211 e 212).
          Se la carta 210 aveva 6 carte uguali allora vince tre volte la carta 211 e tre la 212, quindi copia sarà == 4 (perchè deve ricontare altre quattro volte
          le carte 211 e 212).
        */

                if(win_carte == i && copia > 0 && flag == 1){
                    win_carte++;
                    risultato[win_carte]= risultato[win_carte]+1;
                    copia--;
                    /*win_carte= x;
                    copia--;*/
                }
                else if(win_carte == i && copia > 0 && flag == 0){
                    if(ciclo == 0)
                        win_carte= win_carte-copia;

                    ciclo++;
                    risultato[win_carte]= risultato[win_carte]+1;
                    win_carte++;
                    copia--;
                    /*win_carte= x;
                    copia--;*/
                }

                /*dentro=1;*/
            }
            flag=0;
            ciclo=0;

            if(i >= 1){
                if(dentro == 1)
                    conteggio(i,x,risultato,y); /*Verifica le copie della carta in gioco (i) e per ogni numero corrispondente distribuisce altrettanti copie delle carte successive*/

                risultato[i]= risultato[i]+1;   /*Conta la carta stessa del ciclo in corso*/
            }

            win_carte= i+1;
            dentro=0;
            copia=0;
        }
        else
            j++;
    }

    printf("\n\n");
    for(i=0;i<213;i++){
        printf("Riga %d: %d\n",i,risultato[i]);
        somma= somma + risultato[i];
    }

    printf("\nSomma %d\n",somma);

    return 0;
}







/*Verifica le copie della carta in gioco (i) e per ogni numero corrispondente distribuisce altrettanti copie delle carte successive*/

void conteggio(int i, int win_carte, int risultato[], int copia)   /*'i' indica la carta; risultato[i] contiene il numero di copie di quella carta*/
{
    int x= win_carte;
    int y= risultato[i];
    int z= copia;
    int copie= y;   /*SERVE SOLO PER IL PRINTF*/
    int flag=0;

    printf("\nCOPIE: %d\n\n",copie);

    while(y > 0){   /*Ad esempio, se la carta 3 ha sue 7 copie (y==7) deve ripetere questo ciclo per 7 volte*/
        /*printf("COPIE: %d, win_carte: %d\n",copie,win_carte);*/
        /*risultato[win_carte]= risultato[win_carte]+1;
        win_carte--;*/

        if(win_carte > i){
            risultato[win_carte]= risultato[win_carte]+1;
            win_carte--;
            flag=1;
        }

        /*Si entra qui quando ad esempio, la secondultima carta: 210 ha 4 carte uguali. Ciò significa che vince 4 carte successive, ma le carte successive sono solo
          due, ovvero: 211 e 212. Ciò significa che vince due volte la carta 211 e due la 212, quindi copia sarà == 2 (perchè deve ricontare altre due ovlte le
          carte 211 e 212).
          Se la carta 210 aveva 6 carte uguali allora vince tre volte la carta 211 e tre la 212, quindi copia sarà == 4 (perchè deve ricontare altre quattro volte
          le carte 211 e 212).
        */

        if(win_carte == i && copia > 0 && flag == 1){
            win_carte++;
            risultato[win_carte]= risultato[win_carte]+1;
            copia--;
        }

        /*if(win_carte == i && copia > 0){
            win_carte= x;
            copia--;
        }*/
        else if(win_carte == i && copia == 0){
            y--;
            copia= z;
            copie--;
            win_carte= x;
            flag=0;
        }
    }
}

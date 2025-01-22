#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
49411930 risposta troppo bassa;
77391590 risposta troppo bassa;
81114278 risposta troppo bassa;
81695684 risposta troppo bassa;
91585199 NON L'HO PROVATA
103040583 non è la risposta giusta
84888519 non è la risposta giusta
85359353 non è la risposta giusta
84969179 non è la risposta giusta
83481471 non è la risposta giusta
85226727 non è la risposta giusta
84697917 non è la risposta giusta

84289137 QUESTA E' LA RISPOSTA GIUSTA.
*/

int main()
{
    char c[141][141];
    char*ptr;
    char numb[4];
    char numb2[4];
    int rit,rit2,somma=0,indice=0,indice2=0,indiceI=0,indiceJ=0,find=0,find_one=0,find_two=0,sblocco=0,prova=0;

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
        Quando trovo il carattere '*', controllo se alla riga i-1, vi sono i due numeri o un solo numero vicino a questo simbolo (anche in diagonale).
        Se è no proseguo a controllare alla riga 'i'(stessa riga dove si trova l'asterisco), altrimenti in fine controllo alla riga i+1.
        Se trovo i due numeri in prossimità dell'asterisco li moltiplico e li aggiungo alla somma.
        Se non trovo nessun numero, o anche un solo numero, proseguo senza considerarlo.
    */

    while(/*cont < 4*//*i < 140*/c[i][j] != '?'){   /*Alla fine del file ho messo il simbolo '?' per indicare la sua fine.*/
        if(c[i][j] == '*'){
            indice=0;
            indice2=0;
            find=0;
            find_one=0;
            find_two=0;
            prova=0;
            numb[0]=0;
            numb[1]=0;
            numb[2]=0;
            numb[3]=0;
            numb2[0]=0;
            numb2[1]=0;
            numb2[2]=0;
            numb2[3]=0;
            printf("CAR: %c I: %d, J: %d\n",c[i][j],i,j);

            while(find < 3){

                sblocco=0;

                if(i > 0 && prova == 0){
                    indiceI=i-1;
                    /*indiceJ=j-3;*/
                    indiceJ= j;
                }
                else if(i == 0 && prova == 0)
                    prova=1;

                if(prova == 1){
                    indiceI=i;
                    /*indiceJ=j-3;*/
                    indiceJ= j;
                    prova=2;
                }
                else if(prova == 2){
                    indiceI=i+1;
                    /*indiceJ=j-3;*/
                    indiceJ= j;
                    prova++;
                }

                printf("\nPROVA: %d, IndiceI: %d, IndiceJ: %d\n",prova,indiceI,indiceJ);

                if(c[indiceI][indiceJ-3] >= 48 && c[indiceI][indiceJ-3] <= 57 && (c[indiceI][indiceJ-2] >= 48 && c[indiceI][indiceJ-2] <= 57) && (c[indiceI][indiceJ-1] >= 48 && c[indiceI][indiceJ-1] <= 57) && (c[indiceI][indiceJ-4] < 48 || c[indiceI][indiceJ-4] > 57)){
                    sblocco=1;
                    indiceJ= indiceJ-3;
                }
                else if(c[indiceI][indiceJ-2] >= 48 && c[indiceI][indiceJ-2] <= 57 && (c[indiceI][indiceJ-1] >= 48 && c[indiceI][indiceJ-1] <= 57) && (c[indiceI][indiceJ-3] < 48 || c[indiceI][indiceJ-3] > 57)){
                    sblocco=2;
                    indiceJ= indiceJ-2;
                }
                else if(c[indiceI][indiceJ-1] >= 48 && c[indiceI][indiceJ-1] <= 57 && (c[indiceI][indiceJ-2] < 48 || c[indiceI][indiceJ-2] > 57)){
                    sblocco=3;
                    indiceJ= indiceJ-1;
                }
                else if(c[indiceI][indiceJ] >= 48 && c[indiceI][indiceJ] <= 57){
                    sblocco=4;
                    indiceJ= indiceJ;
                }
                else if(c[indiceI][indiceJ+1] >= 48 && c[indiceI][indiceJ+1] <= 57){
                    sblocco=5;
                    indiceJ= indiceJ+1;
                }

                printf("\nSBLOCCO: %d, INDICEJ: %d, Find_one: %d, Find_two: %d\n",sblocco,indiceJ,find_one,find_two);




                while(sblocco != 0){
                    if(c[indiceI][indiceJ] >= 48 && c[indiceI][indiceJ] <= 57 && find_one == 0 /*&& (sblocco == 1 || sblocco == 3)*/){
                        numb[indice]= c[indiceI][indiceJ];
                        printf("\nNUMB: %c, Indice: %d, IndiceI: %d, IndiceJ: %d",numb[indice],indice+1,indiceI,indiceJ);
                        indice++;
                        /*
                        Esempio:
                        ....34.....
                        ......*.67.
                        .......41..
                        */
                        if((c[indiceI][indiceJ+1] < 48 || c[indiceI][indiceJ+1] > 57) && c[indiceI][indiceJ+1] != '*' && ((c[indiceI+1][indiceJ+1] != '*' && c[indiceI-1][indiceJ+1] != '*') || (c[indiceI][indiceJ+2] < 48 || c[indiceI][indiceJ+2] > 57))){
                            find++;
                            find_one=1;
                            find_two=0;
                            sblocco=0;
                            printf("\nAAAAAAAA\n");
                        }
                        else if(c[indiceI][indiceJ+1] == '*' && (c[indiceI][indiceJ+2] >= 48 && c[indiceI][indiceJ+2] <= 57)){  /*Vuol dire che sulla stessa riga vi è l'altro numero di parte. Es: 34*67 */
                            find_one=1;
                            find++;
                            find_two=0;
                            printf("\nBBBBBBBB\n");
                        }
                        /*
                        Esempio:
                        689.589.*..
                        ...*.......
                        */
                        else if(c[indiceI][indiceJ+1] == '.' && (c[indiceI+1][indiceJ+1] == '*' || c[indiceI-1][indiceJ+1] == '*') && (c[indiceI][indiceJ+2] >= 48 && c[indiceI][indiceJ+2] <= 57)){
                            printf("\nCCCCCCCCCC: %c\n",c[indiceI][indiceJ+2]);
                            find_one=1;
                            find++;
                            find_two=0;
                        }
                        else if(indice >= 3){
                            printf("\nCOMPLETO UNO: %c%c%c\n",numb[0],numb[1],numb[2]);
                            find_one=1;
                            find++;
                            sblocco=0;
                            find_two=0;
                        }
                    }

                    else if(c[indiceI][indiceJ] >= 48 && c[indiceI][indiceJ] <= 57 && find_two == 0 /*&& (sblocco == 2 || sblocco == 3)*/){
                        /*if(sblocco == 3)
                            indiceJ= j+1;*/

                        numb2[indice2]= c[indiceI][indiceJ];
                        printf("\nNUMB2: %c, Indice2: %d, IndiceI: %d, IndiceJ: %d",numb2[indice2],indice2+1,indiceI,indiceJ);
                        indice2++;
                        if(/*c[indiceI][indiceJ+1] == '.' ||*/ (c[indiceI][indiceJ+1] < 48 || c[indiceI][indiceJ+1] > 57) /*&& indice2 < 3*/){
                            find++;
                            find_one=1;
                            sblocco=0;
                        }
                        else if(indice2 >= 3){
                            printf("\nCOMPLETO DUE: %c%c%c\n",numb2[0],numb2[1],numb2[2]);
                            find_two=1;
                            find++;
                            sblocco=0;
                            find_one=0;
                        }
                    }
                    /*indiceI++;*/
                    if(indiceJ < 140/*(c[indiceI][indiceJ+1] >= 48 && c[indiceI][indiceJ+1] <= 57) || c[indiceI][indiceJ+1] == '.' || c[indiceI][indiceJ+1] == '*'*/)
                        indiceJ++;
                    else
                        break;
                }



                if(find < 2 && prova < 3){
                    indice=0;
                    indice2=0;
                    /*find_two=0;*/
                    if(prova < 2)
                        prova++;

                    printf("\nINCREMENTO PROVA %d, INDICE I: %d, FIND: %d\n",prova,i,find);
                }
                else if(find < 2 && prova == 3){
                    break;
                }
                else if(find == 2){
                    rit=strtol(numb,&ptr,10);
                    rit2=strtol(numb2,&ptr,10);
                    printf("\nRIT: %d, RIT2: %d\n",rit,rit2);
                    rit= rit*rit2;
                    somma= somma + rit;
                    printf("\nRIT: %d, SOMMA: %d, Indice: %d\n",rit,somma,i);

                    /*indice=0;
                    indice2=0;
                    find_one=0;
                    find_two=0;
                    prova=0;
                    numb[0]=0;
                    numb[1]=0;
                    numb[2]=0;
                    numb[3]=0;
                    numb2[0]=0;
                    numb2[1]=0;
                    numb2[2]=0;
                    numb2[3]=0;*/
                    find++;
                }
            }
            j++;
            prova=0;
        }
        else{
            if(c[i][j] == '\n' && i < 140){
                i++;
                j=0;
                printf("\n\n\n\nRIGAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA :%d\n",i);
            }
            else
                j++;
        }
    }

    printf("\nSOMMA FINALE: %d, Indice: %d\n",somma,i);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char*s[]= {"red","green","blue"};
    char*numb[]= {"0","1","2","3","4","5","6","7","8","9"};
    char t[50];
    char*ptr;

    char cont[3];
    int cont_red=0,cont_green=0,cont_blue=0;

    int i=0,j=0,saveNgame=0,index=0,indice=0,indice_s=0,l,controllo=0,rit=0,pos_colore,blocco=0;


    FILE*fp;

    fp= fopen("input.txt","r+");

    if(fp == NULL){
        printf("Si e' verificato un'errore\n");
        exit(1);
    }

    /*Copio tutto il file in stringa*/

    while(!feof(fp)){
        fscanf(fp,"%s",t);
        puts(t);
        /*strcat(stringa,t);*/

    /*while(t[i] != '\0'){*/

        /*while(t[i] != "Game"){*/
        if(t[i] == ':'){
            saveNgame= strtol(&t[i-1],&ptr,10); /*Serve per estrarre il numero del Game*/
            printf("SAVEN: %d, I: %d\n",saveNgame,i);
            index=1;                            /*Mi indica a che Game (riga) mi trovo*/
        }
            /*printf("\nBLOCCO %d, INDEX %d, RIT %d\n",blocco,index,rit);*/

            if(blocco == 1 /*t[i] >= 48 && t[i] <= 57*/){
            /*Rivela il numero prima del colore*/
            cont[0]= t[i];
            rit=strtol(cont,&ptr,10);                       /*Ricava il valore numerico dal carattere rilevato al ciclo precedente*/
            printf("\nRIT: %d\n",rit);
            }

            if((strcmp(&t[i],"red")==0) || (strcmp(&t[i],"green")==0) || (strcmp(&t[i],"blue")==0)){
            l=strlen(&s[0][0]);
            /*printf("\nLunghezza stringa: %d, J: %d, I: %d\n",l,j,i);*/

            while(j < l && rit != 0){                       /*rileva il colore a cui fa riferimento il valore numerico trovato sopra*/
                if(t[i] == s[indice_s][j]){
                    j++;
                    i++;
                    pos_colore= indice_s;
                }
                else{
                    indice_s++;
                    j=0;
                    l=strlen(&s[indice_s][j]);
                }
            }

            printf("\nPOS_COLORE: %d\n",pos_colore);

            if(pos_colore == 0)
                cont_red= cont_red + rit;
            else if(pos_colore == 1)
                cont_green= cont_green + rit;
            else if(pos_colore == 2)
                cont_blue= cont_blue + rit;

            printf("\nRed: %d, Green: %d, Blue: %d\n\n\n\n",cont_red,cont_green,cont_blue);
            }

            /*if(strcmp(&t[i],"Game")==0){
                i= indice;
                blocco=0;
            }*/
        /*}*/

        i++;
        controllo=0, pos_colore=0, indice=0;

        if(index == 1)
            blocco=1;

        if(rit != 0)
            blocco=0, index=0;

        rit=0;
    }

    fclose(fp);

    return 0;
}

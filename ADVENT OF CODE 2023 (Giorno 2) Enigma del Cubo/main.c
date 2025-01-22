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






    /*Eseguo i calcoli richiesti dalla traccia, ovvero trova i Game dove è possibile estrarre solo 12 cubi rossi, 13 cubi verdi e 14 cubi blu*/

    int indice_r[100];
    int indice_g[100];
    int indice_b[100];
    int dim_r=0,dim_g=0,dim_b=0,flag=0;


    for(i=0;i<100;i++){
        indice_r[i]=0;
        indice_g[i]=0;
        indice_b[i]=0;
    }


    indice=0,i=0,j=0;

    printf("\n\nGAME REED\n");

    for(i=0;i<100/*red[i][0]!=0*/;i++){
        for(j=0;red[i][j]!=0;j++){
            if(red[i][j] <= 12){    /*Solo se tutti i valori di quella riga sono minori di 12 il flaf rimarrà zero*/
                flag=0;
            }
            else{
                flag=1;
                break;
            }
        }
        if(flag == 0){
            indice_r[indice]= i+1;
            indice++;
            dim_r++;
            flag=1;
            printf("%d %d %d\n",indice_r[indice-1],indice-1,dim_r-1);
        }
        /*else
            flag=0;*/
    }

    printf("\n\nGAME GREEN\n");
    indice=0,i=0,j=0;

    for(i=0;i<100/*green[i][0]!=0*/;i++){
        for(j=0;green[i][j]!=0;j++){
            if(green[i][j] <= 13){
                flag=0;
            }
            else{
                flag=1;
                break;
            }
        }
        if(flag == 0){
            indice_g[indice]= i+1;
            indice++;
            dim_g++;
            flag=1;
            printf("%d\n",indice_g[indice-1]);
        }
        /*else
            flag=0;*/
    }

    printf("\n\nGAME BLUE\n");
    indice=0,i=0,j=0;

    for(i=0;i<100/*blue[i][0]!=0*/;i++){
        for(j=0;blue[i][j]!=0;j++){
            if(blue[i][j] <= 14){
                flag=0;
            }
            else{
                flag=1;
                break;
            }
        }
        if(flag == 0){
            indice_b[indice]= i+1;
            indice++;
            dim_b++;
            flag=1;
            printf("%d\n",indice_b[indice-1]);
        }
        /*else
            flag=0;*/
    }






    /*
        Trova i Game comuni ai tre colori. Indice_r,indice_g e indice_b contengono i game dove i cubi rossi sono massimo 12 (indice_r), dove i cubi verdi sono
        massimo 13(indice_g) e i cubi blu massimo 14(indice_b)
    */


    i=0,j=0,flag=0;
    int somma=0,z;

    for(i=0;i<100;i++){
        if(indice_r[i] != 0){
            /*printf("\nRED: %d, ",indice_r[i]);*/
            for(j=0;j<100;j++){
                /*printf("\nGREEN: %d, ",indice_g[j]);*/
                if(indice_r[i] == indice_g[j] && indice_g[j] != 0){
                    flag=1;
                    break;
                }
                else if(indice_g[j] == 0)
                    break;
            }
            if(flag == 1){
                for(z=0;z<100;z++){
                    /*printf("BLUE: %d\n",indice_b[z]);*/
                    if(indice_r[i] == indice_b[z] && indice_b[z] != 0){
                        printf("\nINDICE ESTRATTO: %d\n",indice_r[i]);
                        somma= somma + indice_r[i];
                        break;
                    }
                    else if(indice_b[z] == 0)
                        break;
                }
            }
            flag=0;
        }
        else if(indice_r[i] == 0)
            break;
    }
    printf("\n\nSOMMA: %d\n",somma);







    /*int somma_r=0,somma_g=0,somma_b=0;

    if(dim_r < dim_g && dim_r < dim_b){
        for(i=0;i<dim_r;i++){
            somma_r= somma_r + indice_r[i];
        }

        printf("\n\nSOMMA ROSSO: %d",somma_r);
    }
    else if(dim_g < dim_r && dim_g < dim_b){
        for(i=0;i<dim_g;i++)
            somma_g= somma_g + indice_g[i];

        printf("\n\nSOMMA VERDE: %d",somma_g);
    }
    else if(dim_b < dim_r && dim_b < dim_g){
        for(i=0;i<dim_b;i++)
            somma_b= somma_b + indice_b[i];

        printf("\n\nSOMMA BLUE: %d",somma_b);
    }*/





    /*i=1,indice=0;

    while(somma_b != 14){
        somma_b= somma_b + blue[i];

        if(somma_b != 14 && blue[i] != 0){
            somma_b= blue[indice];
            i++;
            indice_b_indice=indice;
            indice_b_i=i;
        }
        else if(blue[i] == 0){
            indice++;
            somma_b= blue[indice];
            i=indice+1;
        }
    }
    printf("\n\nSOMMA BLUE: %d %d %d",somma_b,indice_b_indice+1,indice_b_i+1);*/

    printf("\n");

    return 0;
}

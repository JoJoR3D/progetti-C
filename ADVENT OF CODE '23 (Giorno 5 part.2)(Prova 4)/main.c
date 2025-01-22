#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.c"
#include "prot.h"
#include <time.h>

/*

*/



int main()
{
    /*double seme[]={79,14,55,13};*/
    double seme[]={3082872446,316680412,2769223903,74043323,4131958457,99539464,109726392,353536902,619902767,648714498,3762874676,148318192,1545670780,343889780,4259893555,6139816,3980757676,20172062,2199623551,196958359};
    char valori[195][32];/*[32][29]*/
    char numb[11];
    char str[11];

    double seed,SEME,pos=0,/*posizione=8000000000,*/posizione_finale=8000000000/*100*/; /*E' uno dei valori più alti possibili per un double.*/
    int i=0,j=0;
    int numeri=0,dentro=0,indice=0,indice_seme=0,numeri_semi=0,blocco,index=0,IN;
    double x=1;
    char intervalloDest[11],intervalloOrig[11],LunghIntervallo[11];
    /*char*ptr;*/

    read_file(valori);


    i=0,j=0;
    seed= seme[indice_seme];
    SEME= seed;
    indice_seme= indice_seme+2;
    x= intervallo_input(seme,20,index);  /*RICORDA DI CAMBIARE IL VALORE 4 IN 20 QUI E SOTTO QUANDO PASSO ALL'ALTRO FILE DI INPUT*/
    printf("\nX: %.0f\n",x);

    sprintf(str,"%f",seed);     /*converte un qualsiasi tipo in un tipo char. Ad esempio qui converte un double in un char.*/
    printf("Stringa di caratteri: %s\n",str);

    conv_float_to_int(str);

    i=0,j=0;
    printf("Stringa di caratteri: %s\n",str);


    while(x > 0){

        /*printf("\n\nX: %.0f, index: %d\n\n",x,index);*/
        /*printf("\n\nX: %d, index: %d\n\n",x,index);*/

        while(SEME <= x){

        /*blocco=0;*/

        if(valori[i][j] == '?'){
            i=0;
            j=0;
            numeri_semi++;

            if(seed < posizione_finale)
                posizione_finale= seed;

            seed= ++SEME;
            /*indice_seme++;*/

            sprintf(str,"%f",seed);     /*converte un qualsiasi tipo in un tipo char. Ad esempio qui converte un double (seed) in un char (str).*/
            conv_float_to_int(str);
            printf("Stringa di caratteri: %s\n",str);

            printf("\n\n\n\n\n\n\n\nPOSIZIONE FINALE= %.0f, SEED= %.0f\n\n\n\n\n\n\n",posizione_finale,seed);
            /*sleep(2);*/
            /*printf("\n\n\n\n\n\n\n\nPOSIZIONE FINALE= %d, SEED: %d, X: %d\n\n\n\n\n\n\n",posizione_finale,seed,x);*/
        }

        printf("\nCarattere= %c",valori[i][j]);

        if(valori[i][j] == ':'){
            blocco=0;
            i++;
            j=0;
            clearArray(intervalloDest,11);     /*function pulizia*/
            clearArray(intervalloOrig,11);
            clearArray(LunghIntervallo,11);

        /*printf("\nCarattere= %c",valori[i][j]);*/

            while((valori[i][j] >= 48 && valori[i][j] <= 57) || valori[i][j] == ' '){
                while(dentro == 0){
                    numeri++;
                    while(valori[i][j] != ' ' && valori[i][j] != '\n'){
                        if(numeri == 1){
                            intervalloDest[indice]= valori[i][j];
                            printf("\n%c",intervalloDest[indice]);
                        }
                        else if(numeri == 2){
                            intervalloOrig[indice]= valori[i][j];
                            printf("\n%c",intervalloOrig[indice]);
                        }
                        else if(numeri == 3){
                            LunghIntervallo[indice]= valori[i][j];
                            dentro=1;
                            printf("\n%c",LunghIntervallo[indice]);
                        }
                        indice++;
                        j++;
                    }
                    if(numeri == 1){
                        intervalloDest[indice]= '\0';
                    }
                    else if(numeri == 2){
                        intervalloOrig[indice]= '\0';
                    }
                    else if(numeri == 3){
                        LunghIntervallo[indice]= '\0';
                    }

                    printf("\n");
                    indice=0;
                    j++;
                }
                /*printf("\nDest: %.0f, Origine: %.0f, Lunghezza Intervallo: %.0f, SEED: %.0f, X: %.0f, Index: %d\n",intervalloDest,intervalloOrig,LunghIntervallo,seed,x,index);*/
                /*printf("\nDest: %d, Origine: %d, Lunghezza Intervallo: %d, SEED: %d, X: %d, Index: %d\n",intervalloDest,intervalloOrig,LunghIntervallo,seed,x,index);*/
                numeri=0;
                dentro=0;
                /*double origine=atof(intervalloOrig),destinazione=atof(intervalloDest),intervallo=atof(LunghIntervallo);*/

                /*Function che esegue i calcoli*/
                /*pos= calcoli(destinazione,origine,intervallo,seed);*/

                printf("\nDest: %s, Orig: %s, Interv: %s\n",intervalloDest,intervalloOrig,LunghIntervallo);
                printf("Stringa di caratteri: %s\n",str);

                char p[11];

                calcoli_1(intervalloDest,intervalloOrig,LunghIntervallo,str,p,&IN);

                /*devo convertire il valore char di pos in un double (function atof))*/

                /*int z;

                printf("\n\n");

                for(z=0;p[z]!='\0';z++)
                    printf("\n%d-Valore: %d\n",z+1,p[z]);*/

                if(IN == 1){
                    pos= atof(p);    /*PROBLEMA qui, non converte bene char in double*/
                }

                printf("\n\n\n\n\n\n\nPOS: %.0f\n\n\n\n\n\n\n\n",pos);



                /*printf("\nPOS: %.0f\n",pos);*/
                /*printf("\nPOS: %d\n",pos);*/

                if(pos > 0 && blocco == 0){
                    seed= pos;
                    sprintf(str,"%f",seed);     /*converte un qualsiasi tipo in un tipo char. Ad esempio qui converte un double in un char.*/
                    conv_float_to_int(str);
                    blocco=1;
                    printf("\nPos: %.0f\n",pos);
                    /*printf("\nPos: %.0f, Intervallorig: %.0f, I: %d, J: %d, INDEX: %d\n",pos,intervalloOrig,i,j,index);*/
                    /*printf("\nPos: %d, Posizione: %d, I: %d, J: %d\n",pos,seed,i,j);*/
                }

                i++;
                j=0;
                pos=0;
            }
        }
        else if(valori[i][j] == '\n'){
            /*printf("\n2\n");*/
            i++;
            j=0;
        }
        else{
            /*printf("\n3, I: %d, J: %d\n",i,j);*/
            j++;
        }
    }
    index=index+2;
    x= intervallo_input(seme,20,index); /*RICORDA DI CAMBIARE IL VALORE 4 IN 20 QUI E SOPRA QUANDO PASSO ALL'ALTRO FILE DI INPUT*/
    seed= seme[indice_seme];
    SEME= seed;
    indice_seme= indice_seme+2;
    printf("\nX: %.0f\n",x);
    /*printf("\n\nX: %.0f, index: %d\n\n",x,index);*/
    /*printf("\n\nX: %d, index: %d\n\n",x,index);*/

    sprintf(str,"%f",seed);     /*converte un qualsiasi tipo in un tipo char. Ad esempio qui converte un double in un char.*/
    conv_float_to_int(str);
    printf("Stringa di caratteri: %s\n",str);
    }

    printf("\n\n\n\n\n\n\n\nPOSIZIONE FINALE= %.0f, SEED: %.0f\n\n\n\n\n\n\n",posizione_finale,seed);

    return 0;
}

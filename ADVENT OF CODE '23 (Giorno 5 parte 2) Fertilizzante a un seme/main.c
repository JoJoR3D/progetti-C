#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

*/



void clearArray(char[], int);
double calcoli(double, double, double, double);
/*int calcoli(int, int, int, int);*/
/*int intervallo_input(int[], int, int);*/
double intervallo_input(double[], int, int);
void read_file(char[][32/*29*/]);



int main()
{
    /*int seme[]={79,14,55,13};*/
    double seme[]={3082872446,316680412,2769223903,74043323,4131958457,99539464,109726392,353536902,619902767,648714498,3762874676,148318192,1545670780,343889780,4259893555,6139816,3980757676,20172062,2199623551,196958359};
    char valori[195][32];/*[32][29]*/
    char numb[11];

    double intervalloDest,intervalloOrig,LunghIntervallo,seed,SEME,pos=0,/*posizione=8000000000,*/posizione_finale=8000000000/*100*/; /*E' uno dei valori più alti possibili per un double.*/
    int i=0,j=0;
    int numeri=0,dentro=0,indice=0,indice_seme=0,numeri_semi=0,blocco,index=0;
    double x=1;
    /*char*ptr;*/


    read_file(valori);


    i=0,j=0;
    seed= seme[indice_seme];
    SEME= seed;
    indice_seme= indice_seme+2;
    x= intervallo_input(seme,20,index);
    printf("\nX: %.0f\n",x);

    while(x != 0){

        /*printf("\n\nX: %.0f, index: %d\n\n",x,index);*/
        /*printf("\n\nX: %d, index: %d\n\n",x,index);*/

        while(SEME <= x){

        blocco=0;

        if(valori[i][j] == '?'){
            i=0;
            j=0;
            numeri_semi++;

            if(seed < posizione_finale)
                posizione_finale= seed;

            seed= ++SEME;
            /*indice_seme++;*/

            printf("\n\n\n\n\n\n\n\nPOSIZIONE FINALE= %.0f, SEED= %.0f\n\n\n\n\n\n\n",posizione_finale,seed);
            /*printf("\n\n\n\n\n\n\n\nPOSIZIONE FINALE= %d, SEED: %d, X: %d\n\n\n\n\n\n\n",posizione_finale,seed,x);*/
        }

        printf("\nCarattere= %c",valori[i][j]);

        if(valori[i][j] == ':'){
            i++;
            j=0;

        /*printf("\nCarattere= %c",valori[i][j]);*/

            while((valori[i][j] >= 48 && valori[i][j] <= 57) || valori[i][j] == ' '){
                while(dentro == 0){
                    while(valori[i][j] != ' ' && valori[i][j] != '\n'){
                        numb[indice]= valori[i][j];
                        /*printf("\nNumeri= %c, I: %d, J: %d, numero: %d",valori[i][j],i,j,numeri);*/
                        indice++;
                        j++;
                    }
                    numeri++;

                    if(numeri == 1)
                        intervalloDest= atof(numb); /*Converte una stringa ASCII in un numero a virgola mobile o a virgola mobile doppia.*//*strtol(numb,&ptr,10);*/
                    else if(numeri == 2)
                        intervalloOrig= atof(numb); /*strtol(numb,&ptr,10);*/
                    else if(numeri == 3){
                        LunghIntervallo= atof(numb); /*strtol(numb,&ptr,10);*/
                        dentro=1;
                    }

                    clearArray(numb,indice);     /*function pulizia numb*/
                    indice=0;
                    j++;
                }
                /*printf("\nDest: %.0f, Origine: %.0f, Lunghezza Intervallo: %.0f, SEED: %.0f, X: %.0f, Index: %d\n",intervalloDest,intervalloOrig,LunghIntervallo,seed,x,index);*/
                /*printf("\nDest: %d, Origine: %d, Lunghezza Intervallo: %d, SEED: %d, X: %d, Index: %d\n",intervalloDest,intervalloOrig,LunghIntervallo,seed,x,index);*/
                numeri=0;
                dentro=0;

                /*Function che esegue i calcoli*/
                pos= calcoli(intervalloDest,intervalloOrig,LunghIntervallo,seed);
                /*printf("\nPOS: %.0f\n",pos);*/
                /*printf("\nPOS: %d\n",pos);*/

                if(pos != 0 && blocco == 0){
                    seed= pos;
                    blocco=1;
                    printf("\nPos: %.0f, Intervallorig: %.0f, I: %d, J: %d, INDEX: %d\n",pos,intervalloOrig,i,j,index);
                    /*printf("\nPos: %d, Posizione: %d, I: %d, J: %d\n",pos,seed,i,j);*/
                }

                i++;
                j=0;
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
    x= intervallo_input(seme,20,index);
    seed= seme[indice_seme];
    SEME= seed;
    indice_seme= indice_seme+2;
    printf("\nX: %.0f\n",x);
    /*printf("\n\nX: %.0f, index: %d\n\n",x,index);*/
    /*printf("\n\nX: %d, index: %d\n\n",x,index);*/
    }

    printf("\n\n\n\n\n\n\n\nPOSIZIONE FINALE= %.0f, SEED: %.0f\n\n\n\n\n\n\n",posizione_finale,seed);

    return 0;
}







/*Pulisce l'array di char che contiene i caratteri numerici che poi vengono convertiti in valori numerici dalla funzione atof.*/

void clearArray(char a[], int n)
{
    int i;

    for(i=0;i<n;i++)
        a[i]= ' ';
}



/*Esegue i calcoli: Calcola la lunghezza dell'intervallo di origine e verifica se il seed rientra in questo intervallo. Se si trova la sua posizione nel intervallo
  di destinazione.
*/

double calcoli(double x, double y, double z, double seed)
{
    double lunghezza_intervallo_origine= (y+z)-1;
    double a,valore_di_ritorno= 0;

    if(seed <= lunghezza_intervallo_origine && seed >= y){
        /*printf("\nDENTRO\n");*/
        if(x > y){
            a= x - y;
            valore_di_ritorno= seed + a;
        }
        else{
            a= y - x;
            valore_di_ritorno= seed - a;
        }
    }

    return valore_di_ritorno;
}





double intervallo_input(double a[], int n, int i)
{
    double b;

    if(i < n)
        return b= (a[i] + a[i+1]) - 1;
    else
        return 0;
}





/*Function che legge il file dato in input.*/

void read_file(char valori[][32/*29*/])
{
    int i=0,j=0;

    FILE*fp;

    fp=fopen("input.txt","r");

    /*fseek(fp,0,SEEK_SET);*/

    if(fp == NULL){
        printf("\nSi e' verificato un'errore\n");
        exit(1);
    }

    while(!feof(fp)){
        fscanf(fp,"%c",&valori[i][j]);
        printf("%c",valori[i][j]);

        if(valori[i][j] == '\n'){
            i++;
            j=0;
        }
        else
            j++;
    }

    fclose(fp);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
136887475 risposta troppo alta
19622155  risposta troppo bassa
63642705  non è la risposta giusta
25592814  non è la risposta giusta
26390496  non è la risposta giusta
109726392 non è la risposta giusta
*/


/*Al ciclo 2 come faccio a dirgli di non prendere il minimo già preso al ciclo precedente, ma di prendere l'altro valore minimo presente??? HO FATTO QUALCOSA SU QUESTO
  Poi save_value contiene tutti i valori di tutte le categorie, come gli dico di prendere il valore minimo solo di una determinata categoria??? HO FATTO QUALCOSA PER QUESTO USANSO inizio e fine*/
/*Controllare che oltre al minimo venga ritornato anche la sua lunghezza dell'intervallo.*/




void clearArray(char[], int);
double calcoli(double, double, double, double, double, int, int, double);
void dest_min(double*, double[], int, int, int);
void Min(double, double, double*, double*);
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
    double save_value[195];
    /*double orig[10];
    double dest[10];
    double inte[10];*/

    double intervalloDest,intervalloOrig,LunghIntervallo,seed,SEME,pos=0,/*posizione=8000000000,*/posizione_finale=8000000000/*100*/; /*E' uno dei valori più alti possibili per un double.*/
    int i=0,j=0;
    int numeri=0,dentro=0,indice=0,indice_seme=0,numeri_semi=0,blocco,index=0,contatore=0,categoria=0,ciclo=0,inizio,fine;
    double x=1, min=7000000000, lunghintervpreced, minimo=7000000000, MINIMO=7000000000;
    /*char*ptr;*/


    read_file(valori);


    i=0,j=0;
    seed= seme[indice_seme];
    SEME= seed;
    indice_seme= indice_seme+2;
    x= intervallo_input(seme,20,index);
    printf("\nX: %.0f\n",x);
    printf("\n\nSEED: %.0f\n\n",seed);

    while(x != 0){

        /*printf("\n\nX: %.0f, index: %d\n\n",x,index);*/
        /*printf("\n\nX: %d, index: %d\n\n",x,index);*/

        while(SEME <= x){

        /*blocco=0;*/

        if(valori[i][j] == '?'){
            i=0;
            j=0;
            numeri_semi++;
            categoria=0;
            lunghintervpreced=0;

            if(seed < posizione_finale)
                posizione_finale= seed;


            /*printf("\n\n\n\n\n\n\n\nPOSIZIONE FINALE= %d, SEED: %d, X: %d\n\n\n\n\n\n\n",posizione_finale,seed,x);*/

            if(contatore > 1){
                /*seed= ++SEME;
                indice_seme++;
                contatore=0;*/
                seed= SEME;
                contatore=0;
                ciclo++;
                printf("\n\n\n\n\n\n\n\nPOSIZIONE FINALE PROVVISORIA= %.0f, SEED: %.0f\n\n\n\n\n\n\n",posizione_finale,seed);
            }
            else{
                contatore=0;
                ciclo=0;
                printf("\n\n\n\n\n\n\n\nPOSIZIONE FINALE PROVVISORIA= %.0f, SEED: %.0f\n\n\n\n\n\n\n",posizione_finale,SEME);
                break;
            }
        }

        /*printf("\nCarattere= %c",valori[i][j]);*/

        if(valori[i][j] == ':'){
            /*printf("\n\nSEED: %.0f\n\n",seed);*/
            i++;
            j=0;
            categoria++;
            printf("\nCATEGORIA: %d\n",categoria);

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
                pos= calcoli(intervalloDest,intervalloOrig,LunghIntervallo,seed,x,categoria,blocco,lunghintervpreced);
                /*printf("\nPOS: %.0f\n",pos);*/

                if(pos != 0){

                    if(ciclo > 0){
                        if(categoria == 1){
                            inizio= 1;
                            fine= 37;
                            contatore_1++;
                        }
                        else if(categoria == 2){
                            inizio= 40;
                            fine= 58;
                            contatore_2++;
                        }
                        else if(categoria == 3){
                            inizio= 61;
                            fine= 69;
                            contatore_3++;
                        }
                        else if(categoria == 4){
                            inizio= 72;
                            fine= 97;
                            contatore_4++;
                        }
                        else if(categoria == 5){
                            inizio= 100;
                            fine= 145;
                            contatore_5++;
                        }
                        else if(categoria == 6){
                            inizio= 148;
                            fine= 172;
                            contatore_6++;
                        }
                        else if(categoria == 7){
                            inizio= 175;
                            fine= 194;
                            contatore_7++;
                        }

                        Min(pos,LunghIntervallo,&min,&lunghintervpreced);
                    }
                    else{
                        save_value[i]= pos;
                        Min(pos,LunghIntervallo,&min,&lunghintervpreced);
                    }
                    /*printf("\nMIN: %.0f\n",min);*/
                    /*seed= pos;*/
                    /*lunghintervpreced= LunghIntervallo;*/
                    printf("\nSalvataggio lunghezza intervallo: %.0f\n",lunghintervpreced);
                    blocco=1;

                    /*if(categoria == 1 && min != 7000000000){
                        contatore++;
                        printf("\nCONTATORE: %d\n\n",contatore);
                    }*/
                    /*printf("\nPos: %.0f, I: %d, J: %d, INDEX: %d\n",pos,i,j,index);*/
                    /*printf("\nPos: %d, Posizione: %d, I: %d, J: %d\n",pos,seed,i,j);*/
                }
                else
                    save_value[i]= 0;

                i++;
                j=0;
            }
            if(blocco == 1){
                if(ciclo > 0)
                    dest_min(&min,save_value,inizio,fine,ciclo);

                seed= min;
                /*lunghintervpreced= LIP;*/
                printf("\nSEED: %.0f\n",seed);
                min=7000000000;

                /*if(categoria == 1)
                    minimo= seed;*/
            }
            blocco=0;
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
    printf("\n\nSEED: %.0f\n\n",seed);
    /*printf("\nX: %.0f\n",x);*/
    /*printf("\n\nX: %.0f, index: %d\n\n",x,index);*/
    /*printf("\n\nX: %d, index: %d\n\n",x,index);*/
    }

    printf("\n\n\n\n\n\n\n\nPOSIZIONE FINALE= %.0f\n\n\n\n\n\n\n",posizione_finale);

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

double calcoli(double x, double y, double z, double seed, double seme_max, int categoria, int blocco, double lunghintervpreced)
{
    double lunghezza_intervallo_origine= (y+z)-1;
    double a,new_seed,valore_di_ritorno= 0;

    if(categoria > 1 /*&& blocco == 0*/){
        new_seed= seed + lunghintervpreced;
        seme_max= seed + lunghintervpreced;
        /*printf("\nSEED: %.0f, NEW_SED: %.0f, SEME_MAX: %.0f\n",seed,new_seed,seme_max);*/
    }
    else if(categoria <= 1)
        new_seed= seed;


    if((y <= seed && lunghezza_intervallo_origine >= new_seed) || (y >= seed && /*lunghezza_intervallo_origine*/y <= seme_max)){

        if(y >= seed && /*lunghezza_intervallo_origine*/y <= seme_max)
            printf("\nDENTRO, Y: %.0f, seed: %.0f, Lung_intervallo_precedente: %.0f, seme_max: %.0f\n",y,seed,lunghintervpreced,seme_max);

        if(y >= seed)
            seed= y;

        if(x > y){
            a= x - y;
            if((seed + a) >= x && ((seed + a) <= (x + z - 1))){
                valore_di_ritorno= seed + a;
                /*printf("\nValore di ritorno_1: %.0f\n",valore_di_ritorno);*/
            }
        }
        else{
            a= y - x;
            if((seed - a) >= x && ((seed - a) <= (x + z - 1))){
                valore_di_ritorno= seed - a;
                /*printf("\nValore di ritorno_2: %.0f\n",valore_di_ritorno);*/
            }
        }

        if(valore_di_ritorno != 0)
            printf("\nX: %.0f, Y: %.0f, Z: %.0f, SEED: %.0f, Valore di ritorno: %.0f\n",x,y,z,seed,valore_di_ritorno);
    }

    return valore_di_ritorno;
}




void dest_min(double*min, double save_value[], int inizio, int fine, int ciclo)
{
    int i,cont=0;
    double minimo;

    for(i=inizio;i<=fine;i++){
        if(save_value[i] == *min){
            save_value[i]= 7000000000;
            break;
        }
    }

    for(i=inizio;i<=fine;i++){
        if(save_value[i] != 0 && cont == 0){
            minimo= save_value[i];
            cont=1;
        }

        if(save_value[i] < minimo && save_value[i] != 0){
            minimo= save_value[i];
            /*printf("\n\nMINIMO2: %.0f\n\n",minimo);*/
        }
        /*printf("\n\nSAVE_VALUE: %.0f\n\n",save_value[i]);*/
    }

    *min= minimo;
}




void Min(double pos, double LunghIntervallo, double*min, double*lunghintervpreced)
{
    if(pos < *min){
        *min= pos;
        *lunghintervpreced= LunghIntervallo;
    }
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

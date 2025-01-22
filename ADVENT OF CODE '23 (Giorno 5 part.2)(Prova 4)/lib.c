void lunghezza_due_array(char*, char*, int*, int*);
void lung(int, int, int*, int*);
void LUNGHEZZA(int, int, int*);
int check(char*, int*, int, int);
int check2(int*, int*, int);
void calculation(int*, int, char*, int*, int);
void operazione_somma(int, int, char*, char*, int, int*, int*, int*, int);
void operazione_differenza(int, int, char*, char*, int*, int*, int*, int, int);
void Racc_Function(char*, char*, int*, int*, int, int, int, int, int*, char*, int*, int, int);
void comparazione_char(char*, char*, int*);



void clearArray(char[], int);
double calcoli(double x, double y, double z, double seed);
void conv_float_to_int(char*);
void calcoli_1(char*, char*, char*, char*, char*, int*);
/*double calcoli(char[], char[], char[], char[]);*/
/*int calcoli(int, int, int, int);*/
/*int intervallo_input(int[], int, int);*/
double intervallo_input(double[], int, int);
void read_file(char[][32/*29*/]);





/*FUNCTION*/

/*
void operazione_somma(int differenza1, int differenza2, char*a, char*b, int dim, int*numeri, int*somma, int*indice, int dim_numeri)
{
    int i,valore1,valore2;
    *indice=0;
    somma[*indice]= 0;
    *indice=1;

    for(i=0;i<dim;i++){
        if(differenza1 != 0 && i >= differenza1){
            valore1= check(&a[i],numeri,dim_numeri,*indice);
            valore2= check(&b[i-differenza1],numeri,dim_numeri,*indice);

            somma[*indice]= valore1+valore2;
            printf("\nSomma1: %d, valore1: %d, valore2: %d, I: %d\n",somma[*indice],valore1,valore2,i);
            (*indice)++;
        }
        else if(differenza2 != 0 && i >= differenza2){
            valore1= check(&a[i-differenza2],numeri,dim_numeri,*indice);
            valore2= check(&b[i],numeri,dim_numeri,*indice);

            somma[*indice]= valore1+valore2;
            printf("\nSomma2: %d, valore1: %d, valore2: %d, I: %d\n",somma[*indice],valore1,valore2,i);
            (*indice)++;
        }
        else{
            if(differenza1 > 0){
                printf("\nAAA: %s\n",a);
                valore1= check(&a[i],numeri,dim_numeri,*indice);
                somma[*indice]= valore1;
                printf("\nSomma3: %d\n",somma[*indice]);
                (*indice)++;
            }
            else if(differenza2 > 0){
                valore2= check(&b[i],numeri,dim_numeri,*indice);
                somma[*indice]= valore2;
                printf("\nSomma3: %d\n",somma[*indice]);
                (*indice)++;
            }
        }
    }
}*/




void operazione_somma(int differenza1, int differenza2, char*a, char*b, int dim, int*numeri, int*somma, int*indice, int dim_numeri)
{
    int i=0,j=0,valore1=0,valore2=0,dentro,dif;

    if(dim < 10){
        dif= 10-dim;
        for(i=0;i<dif;i++)
            somma[i]=0;
    }

    *indice=i;

    for(i=0;i<dim;i++){
        valore1=0,valore2=0;

        if(/*differenza1 > 0 && i == 0*/differenza1 > differenza2){
            /*printf("\nAAA: %s\n",a);*/
            valore1= check(&a[i],numeri,dim_numeri,*indice);
            somma[*indice]= valore1;
            /*printf("\nSomma3: %d\n",somma[*indice]);*/
            (*indice)++;
            /*i++;*/
            differenza1--;
            dentro=1;
        }
        else if(/*differenza2 > 0 && i == 0*/differenza2 > differenza1){
            valore2= check(&b[i],numeri,dim_numeri,*indice);
            somma[*indice]= valore2;
            /*printf("\nSomma3: %d\n",somma[*indice]);*/
            (*indice)++;
            /*i++;*/
            differenza2--;
            dentro=2;
        }


        /*if(differenza1 > differenza2){
            valore1= check(&a[i],numeri,dim_numeri,*indice);
            valore2= check(&b[i-differenza1],numeri,dim_numeri,*indice);

            somma[*indice]= valore1+valore2;
            printf("\nSomma1: %d, valore1: %d, valore2: %d, I: %d, Dim: %d\n",somma[*indice],valore1,valore2,i,dim);
            (*indice)++;
        }
        else if(differenza2 > differenza1){
            valore1= check(&a[i-differenza2],numeri,dim_numeri,*indice);
            valore2= check(&b[i],numeri,dim_numeri,*indice);

            somma[*indice]= valore1+valore2;
            printf("\nSomma2: %d, valore1: %d, valore2: %d, I: %d\n",somma[*indice],valore1,valore2,i);
            (*indice)++;
        }*/
        else if(differenza1 == differenza2){
            /*if(b[i] == '\0')
                break;*/
            if(dentro == 1){
                valore1= check(&a[i],numeri,dim_numeri,*indice);
                valore2= check(&b[j],numeri,dim_numeri,*indice);
                j++;
            }
            else if(dentro == 2){
                valore1= check(&a[j],numeri,dim_numeri,*indice);
                valore2= check(&b[i],numeri,dim_numeri,*indice);
                j++;
            }
            else{
                valore1= check(&a[i],numeri,dim_numeri,*indice);
                valore2= check(&b[i],numeri,dim_numeri,*indice);
            }

            somma[*indice]= valore1+valore2;
            /*printf("\nSomma4: %d, valore1: %d, valore2: %d, I: %d\n",somma[*indice],valore1,valore2,i);*/
            (*indice)++;
        }
    }
    /*printf("\n\n\nINDICE SOMMA: %d\n\n\n",*indice);*/
}








void operazione_differenza(int differenza1, int differenza2, char*a, char*b, int*numeri, int*somma, int*indice, int dim, int dim_numeri)
{
    int i=0,valore1=0,valore2=0,index,blocco=0,dif;

    if(dim < 10){
        dif= 10-dim;
        for(i=0;i<dif;i++)
            somma[i]=0;
    }

    index=dim;
    dim--;
    /*printf("\nINDEX: %d, DIM: %d\n",index,dim);*/
    *indice=dim;

    for(i=dim;i>=0;i--){

        if(differenza1 > differenza2){
            /*printf("\nDentro\n");*/

            valore1= check(&a[i],numeri,dim_numeri,*indice);
            valore2= check(&b[i-differenza1],numeri,dim_numeri,*indice);

            if(valore1 < valore2 && blocco == 0){
                valore1= valore1+10;
                somma[*indice]= valore1-valore2;
                if(a[i-1] > 48)
                    a[i-1]= a[i-1]-1;
                else{
                    a[i-1]= a[i-1] + 9;
                    a[i-2]= a[i-2]-1;
                    /*printf("\nECCCCCCCCCCCCCCOOOOOOOOOOOO\n");*/
                }
            }
            else if(valore1 >= valore2 && blocco == 0)
                somma[*indice]= valore1-valore2;
            else if(blocco == 1)
                somma[*indice]= valore1;

            if(i-differenza1 == 0)
                blocco=1;

            /*printf("\nSomma1: %d, valore1: %d, valore2: %d, I: %d, A[i]: %d, A[i-1]: %d, A[i-2]: %d, I: %d\n",somma[*indice],valore1,valore2,i,a[i],a[i-1],a[i-2],i);*/
            (*indice)--;
        }
        else if(differenza2 > differenza1){

            valore1= check(&a[i-differenza2],numeri,dim_numeri,*indice);
            valore2= check(&b[i],numeri,dim_numeri,*indice);

            if(valore1 < valore2 && blocco == 0){
                valore1= valore1+10;
                somma[*indice]= valore1-valore2;
                if(a[i-1] > 0)
                    a[i-1]= a[i-1]-1;
                else{
                    a[i-1]= a[i-1] + 9;
                    a[i-2]= a[i-2]-1;
                }
            }
            else if(valore1 >= valore2 && blocco == 0)
                somma[*indice]= valore1-valore2;
            else if(blocco == 1)
                somma[*indice]= valore1;

            if(i-differenza2 == 0)
                blocco=1;

            /*printf("\nSomma2: %d, valore1: %d, valore2: %d, I: %d\n",somma[*indice],valore1,valore2,i);*/
            (*indice)--;
        }
        else if(differenza2 == differenza1){

            valore1= check(&a[i],numeri,dim_numeri,*indice);
            valore2= check(&b[i],numeri,dim_numeri,*indice);

            if(valore1 < valore2){
                valore1= valore1+10;
                somma[*indice]= valore1-valore2;
                if(a[i-1] > 0)
                    a[i-1]= a[i-1]-1;
                else{
                    a[i-1]= a[i-1] + 9;
                    a[i-2]= a[i-2]-1;
                }
            }
            else
                somma[*indice]= valore1-valore2;

            /*printf("\nSomma4: %d, valore1: %d, valore2: %d, I: %d\n",somma[*indice],valore1,valore2,i);*/
            (*indice)--;
        }
    }
    *indice=index;
    /*printf("\n\n\nINDICE DIFFERENZA: %d\n\n\n",*indice);*/
}








/*
void operazione_differenza(int differenza1, int differenza2, char*a, char*b, int*numeri, int*somma, int*indice, int dim, int dim_numeri)
{
    int i,valore1,valore2,index,blocco=0;
    index=dim;
    dim--;
    printf("\nINDEX: %d, DIM: %d\n",index,dim);
    *indice=dim;

    for(i=dim;i>=0;i--){

        if(differenza1 > differenza2){
            printf("\nDentro\n");

            valore1= check(&a[i],numeri,dim_numeri,*indice);
            valore2= check(&b[i-differenza1],numeri,dim_numeri,*indice);

            if(valore1 < valore2 && blocco == 0){
                valore1= valore1+10;
                somma[*indice]= valore1-valore2;
                if(a[i-1] > 48)
                    a[i-1]= a[i-1]-1;
                else{
                    a[i-1]= ((a[i-1] + 10) - 1);
                    a[i-2]= a[i-2]-1;
                    printf("\nECCCCCCCCCCCCCCOOOOOOOOOOOO\n");
                }
            }
            else if(valore1 >= valore2 && blocco == 0)
                somma[*indice]= valore1-valore2;
            else if(blocco == 1)
                somma[*indice]= valore1;

            if(i-differenza1 == 0)
                blocco=1;

            printf("\nSomma1: %d, valore1: %d, valore2: %d, I: %d, A[i]: %d, A[i-1]: %d, A[i-2]: %d, I: %d\n",somma[*indice],valore1,valore2,i,a[i],a[i-1],a[i-2],i);
            (*indice)--;
        }
        else if(differenza2 > differenza1){

            valore1= check(&a[i-differenza2],numeri,dim_numeri,*indice);
            valore2= check(&b[i],numeri,dim_numeri,*indice);

            if(valore1 < valore2 && blocco == 0){
                valore1= valore1+10;
                somma[*indice]= valore1-valore2;
                if(a[i-1] > 0)
                    a[i-1]= a[i-1]-1;
                else{
                    a[i-1]= ((a[i-1] + 10) - 1);
                    a[i-2]= a[i-2]-1;
                }
            }
            else if(valore1 >= valore2 && blocco == 0)
                somma[*indice]= valore1-valore2;
            else if(blocco == 1)
                somma[*indice]= valore1;

            if(i-differenza2 == 0)
                blocco=1;

            printf("\nSomma2: %d, valore1: %d, valore2: %d, I: %d\n",somma[*indice],valore1,valore2,i);
            (*indice)--;
        }
        else if(differenza2 == differenza1){

            valore1= check(&a[i],numeri,dim_numeri,*indice);
            valore2= check(&b[i],numeri,dim_numeri,*indice);

            if(valore1 < valore2){
                valore1= valore1+10;
                somma[*indice]= valore1-valore2;
                if(a[i-1] > 0)
                    a[i-1]= a[i-1]-1;
                else{
                    a[i-1]= ((a[i-1] + 10) - 1);
                    a[i-2]= a[i-2]-1;
                }
            }
            else
                somma[*indice]= valore1-valore2;

            printf("\nSomma4: %d, valore1: %d, valore2: %d, I: %d\n",somma[*indice],valore1,valore2,i);
            (*indice)--;
        }
    }
    *indice=index;
    printf("\n\n\nINDICE DIFFERENZA: %d\n\n\n",*indice);
}
*/










void calculation (int*somma, int n, char*s, int*numeri, int dim_numeri)
{
    int i,valore,flag=0,index;
    s[n]= '\0';     /*Assegno all'ultima posizione il carattere di fine stringa*/
    /*printf("\nDIM: %d, N: %d\n",dim_numeri,n);*/

    /*for(i=0;i<n;i++)
        printf("SOMMA: %d\n",somma[i]);*/

    n--;
    /*printf("N: %d\n",n);*/

    for(i=n;i>=0;i--){
        /*printf("\nIndice: %d, Dimensione: %d\n",i,n);*/
        if(somma[i] >= 10 /*&& i-1 != 0 && (somma[i-1] + 1 <= 9)*/){
            somma[i]= somma[i]-10;
            somma[i-1]= somma[i-1]+1;
            /*printf("\nDENTROO1\n");*/
        }
        /*else if(somma[i] >= 10 && (somma[i-1] + 1 > 9)){
            somma[i]= somma[i]-10;
            somma[i-1]= 0;
            somma[i-2]= somma[i-2] + 1;
            printf("\nDENTROO2\n");
        }*/

        valore= check2(numeri,&somma[i],dim_numeri);
        s[i]= valore;

        /*printf("\nValore[%d]: %c\n",i,s[i]);*/

        /*else if(somma[i] >= 10 && i-1 == 0 && (somma[i-1] + somma[i] >= 10)){
            index=i;
            somma[i]= somma[i]-10;
            somma[i-1]= 0;
            somma[i-2]= 1;

            while(index >= 0){
                if(i > 0){
                    valore= check2(numeri,&somma[i],dim);
                    s[i]= valore;
                    i--;
                }
                else if(i == 0){
                    if(s[i] != 0){
                        valore= check2(numeri,&somma[i],dim);
                        s[i]= valore;
                        i--;
                    }
                    else if(s[i] == 0)
                        i--;
                }
            }
        }*/
        /*printf("\nVALORE: %d, INDICE: %d, SOMMA: %d\n",numeri[i],i,somma[i]);*/
        /*printf("somma[%d]: %d, s[%d]: %c, Valore: %d\n",i,somma[i],i,s[i],valore);*/
    }

    /*Ora nell'array somma devo considerare una posizione in più all'inizio dell'array nel caso in cui si presenti una somma 9+1= 10 il cui risultato sono
    DUE valori (1 e 0) e no uno solo. Ho già fatto una modifica all' *indice nella function operazione_somma.*/
}




/*Ritorna il valore numerico corrispondente (int) al carattere numerico (char)*/

int check(char*a, int*b, int n, int indice)
{
    int i;

    for(i=0;i<n;i++){
        /*printf("\nA: %c, B: %c, N: %d",a,b[i],n);*/
        if(*a == b[i])
            break;
    }
    /*printf("\nIIII: %d",i);*/
    return i;
}



/*Ritorna il carattere numerico (char) corrispondente al valore numerico (int)*/

int check2(int*a, int*b, int n)
{
    int i;

    for(i=0;i<n;i++){
        if(i == *b){
            break;
        }
    }
    /*printf("Numeri[%d]: %d\n",i,a[i]);*/
    return a[i];
}



/*Calcola la lunghezza dei due array di caratteri dati in input*/

void lunghezza_due_array(char*a, char*b, int*lung_a, int*lung_b)
{
    int i=0,blocco1=0,blocco2=0;
    *lung_a=0;
    *lung_b=0;

    while(a[i]!='\0' || b[i]!='\0'){
        if(blocco1 == 0){
            (*lung_a)++;
            if(a[i] == '\0'){
                blocco1=1;
                (*lung_a)--;
            }
        }
        if(blocco2 == 0){
            (*lung_b)++;
            if(b[i] == '\0'){
                blocco2=1;
                (*lung_b)--;
            }
        }
        i++;
    }
}



/*Ritorna quant è la differenza delle due lunghezze dei due array di char*/

void lung(int lung_a, int lung_b, int*differenza1, int*differenza2)
{
    if(lung_a > lung_b){
        *differenza1= lung_a-lung_b;
    }
    else /*if(lung_a < lung_b)*/{
        *differenza2= lung_b-lung_a;
    }
    /*else if(lung_a == lung_b){
        *differenza1=0;
        *differenza2=0;
    }*/

    /*printf("\nDIFFERENZA1: %d, DIFFERENZA2: %d. LUN_A: %d, LUN_B: %d\n",*differenza1, *differenza2,lung_a,lung_b);*/
}




/*Ritorna chi tra i due array di char 'a' e 'b' è più lungo*/

void LUNGHEZZA(int lung_a, int lung_b, int*lunghezza)
{
    if(lung_a > lung_b)
        *lunghezza= lung_a;
    else
        *lunghezza= lung_b;
}





void Racc_Function(char*origine,char*intervallo,int*lung_orig,int*lung_interv,int differenza1,int differenza2,int dim,int indice,int*numeri,char*seed,int*somma,int flag,int dim_numeri)
{
    *lung_orig=0, *lung_interv=0, differenza1=0, differenza2=0, dim=0, indice=0;

    lunghezza_due_array(origine,intervallo,lung_orig,lung_interv);

    /*printf("\n\nL1: %d, L2: %d\n\n",*lung_orig,*lung_interv);*/

    lung(*lung_orig,*lung_interv,&differenza1,&differenza2);

    /*printf("\nDifferenza1: %d, Differenza2: %d\n",differenza1,differenza2);*/

    LUNGHEZZA(*lung_orig,*lung_interv,&dim);

    /*printf("\nDim: %d, flag: %d\n",dim,flag);*/

    if(flag == 0)
        operazione_somma(differenza1,differenza2,origine,intervallo,dim,numeri,somma,&indice,dim_numeri);
    else
        operazione_differenza(differenza1,differenza2,origine,intervallo,numeri,somma,&indice,dim,dim_numeri);

    calculation(somma,indice,seed,numeri,dim_numeri);
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

    /*printf("\nOrigine: %.0f, Destinazione: %.0f, Intervallo: %.0f, seme: %.0f\n",y,x,z,seed);*/

    if(seed <= lunghezza_intervallo_origine && seed >= y){
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






void conv_float_to_int(char*str)
{
    int i;

    for(i=0;i<11;i++){
        if(str[i] == '.'){
            str[i]= '\0';
            break;
        }
        else if(i == 11)
            str[i]= '\0';
    }
}








void calcoli_1(char*destinazione/*x*/, char*origine/*y*/, char*intervallo/*z*/, char*str/*seed*/, char*valore_di_ritorno, int*dentro)
{
    int lung_orig=0, lung_interv=0, differenza1=0, differenza2=0, dim=0, indice=0, i, flag;
    int somma[20];
    int numeri[]={48,49,50,51,52,53,54,55,56,57};
    int dim_numeri= 10;
    char seed[11];

    *dentro=0;

    /*double lunghezza_intervallo_origine= (y+z)-1;*/


    /*Questa function esegue l'operazione (y+z)*/

    flag=0;

    /*printf("\nORIGINE: %s, INTERVALLO: %s\n",origine,intervallo);*/

    Racc_Function(origine,intervallo,&lung_orig,&lung_interv,differenza1,differenza2,dim,indice,numeri,seed,somma,flag,dim_numeri);

    printf("\n");

    for(i=0;seed[i]!='\0';i++)
        printf("%d-Valore1: %c\n",i+1,seed[i]);



    /*Questa function sottrae -1 al valore ottenuto al passaggio precedente (y+z)*/

    flag=1;
    /*char valore[11]={'0','0','0','0','0','0','0','0','0','1','\0'};*/
    char valore[2]={'1','\0'};
    char seed2[11];

    Racc_Function(seed,valore,&lung_orig,&lung_interv,differenza1,differenza2,dim,indice,numeri,seed2,somma,flag,dim_numeri);

    printf("\n");

    for(i=0;seed2[i]!='\0';i++)
        printf("%d-Valore2: %c\n",i+1,seed2[i]);





    /*double a,valore_di_ritorno= 0;

    printf("\nOrigine: %.0f, Destinazione: %.0f, Intervallo: %.0f, seme: %.0f\n",y,x,z,seed);

    if(seed <= lunghezza_intervallo_origine && seed >= y){
        if(x > y){
            a= x - y;
            valore_di_ritorno= seed + a;
        }
        else{
            a= y - x;
            valore_di_ritorno= seed - a;
        }
    }*/



    printf("\n\n\n\n\nCALCOLI:\n\n");

    char a[11];

    int L_1, L_2, ritorna, ritorna2, ritorna3, rit;

    lunghezza_due_array(str,seed2,&L_1,&L_2);

    lunghezza_due_array(origine,intervallo,&lung_orig,&lung_interv);

    comparazione_char(str,seed2,&ritorna);
    comparazione_char(str,origine,&ritorna2);

    printf("str: %s, seed2: %s, Origine: %s, Destinazione: %s, L_1: %d, L_2: %d, Lung_orig: %d, Lung_interv: %d,\nRitorna: %d, Ritorna2: %d\n",str,seed2,origine,destinazione,L_1,L_2,lung_orig,lung_interv,ritorna,ritorna2);

    /*if(L_1 <= lung_interv && L_1 >= lung_orig){*/
    if((ritorna == 2 || ritorna == 3) && (ritorna2 == 1 || ritorna2 == 3)){

        *dentro=1;

        comparazione_char(destinazione,origine,&rit);

        printf("\nRIT: %d\n",rit);

        if(rit == 1/*lung_interv > lung_orig*/){
            /*eseguo questa operazione: a= x - y;*/
            printf("\nENTRA NELL'IF\n");

            /*
            Errore: "cast pointer from integer of different size" se non uso l'asterisco per eseguire il cast.
            Il compilatore emette l' avviso "cast da intero a puntatore di dimensione diversa" ogni volta che il valore di un intero viene convertito in un
            puntatore, soprattutto quando la memoria allocata a un puntatore è inferiore alla memoria allocata a un tipo di dati intero. Ad esempio,
            se i puntatori in un sistema sono memorizzati in 16 bit, ma gli interi sono memorizzati in 8 bit, nella conversione data verrebbero persi un
            totale di 8 bit. Viene quindi lanciato un'avvertimento.
            Per questo uso l'aseterisco perchè la function è di tipo char, quindi 8 bit, ma voglio fare un cast a char di un'array di int (somma) che è di 32 bit,
            quindi 24 bit andrebbero persi. Per questo uso il puntatore.
            Perchè scrivendo solo (char) sto dicendo che voglio eseguire l'operazione di cast su UN solo valore di tipo char, ma io gli sto passando l'array somma
            che ha una dimensione di 11 valori, quindi uso char* per indicare un'array di char.
            Se gli passavo ad esempio una variabile int x, allora il cast sarebbe stato (char)x, perchè int x non è un'array ma una variabile che contiene UN solo
            valore di tipo int.
            */

            flag=1;
            clearArray((char*)somma,11);    /*operazione di cast*/
            Racc_Function(destinazione,origine,&lung_orig,&lung_interv,differenza1,differenza2,dim,indice,numeri,a,somma,flag,dim_numeri);

            /*eseguo questa operazione valore_di_ritorno= seed + a;*/
            flag=0;
            clearArray((char*)somma,11);
            Racc_Function(str,a,&lung_orig,&lung_interv,differenza1,differenza2,dim,indice,numeri,valore_di_ritorno,somma,flag,dim_numeri);
        }
        else if(rit == 2 || rit == 3){
            printf("\nENTRA NELL'ELSE\n");
            flag=1;
            clearArray((char*)somma,11);
            Racc_Function(origine,destinazione,&lung_orig,&lung_interv,differenza1,differenza2,dim,indice,numeri,a,somma,flag,dim_numeri);

            printf("\n\n");

            for(i=0;a[i]!='\0';i++)
                printf("%d-Valore2: %c\n",i+1,a[i]);

            /*eseguo questa operazione valore_di_ritorno= seed - a;*/
            comparazione_char(str,a,&ritorna3);     /*controllo per verificare che seed sia maggiore o almeno uguale ad 'a'. Altrimenti genererebbe un numero negativo*/

            if(ritorna3 == 1 || ritorna3 == 3){
                flag=1;
                clearArray((char*)somma,11);
                Racc_Function(str,a,&lung_orig,&lung_interv,differenza1,differenza2,dim,indice,numeri,valore_di_ritorno,somma,flag,dim_numeri);

                printf("\n\n");

                for(i=0;valore_di_ritorno[i]!='\0';i++)
                    printf("%d-Valore2: %c\n",i+1,valore_di_ritorno[i]);
            }
        }
    }
}




void comparazione_char(char*a, char*b, int*ritorna)
{
    int i=0,j=0;
    *ritorna=0;

    while(a[i] != '\0' || b[j] != '\0'){
        while(a[i] == 48 || b[j] == 48){
            if(a[i] == 48)
                i++;
            else if(b[j] == 48)
                j++;
            else if(a[i] == 48 && b[j] == 48){
                i++,j++;
            }
        }

        if(a[i] > b[j]){
            *ritorna=1;
            break;
        }
        else if(a[i] < b[j]){
            *ritorna=2;
            break;
        }
        else if(a[i] == b[j])
            *ritorna=3;

        i++;
        j++;
        /*printf("RRRRRRRRRRR: %d\n",*ritorna);*/
    }
}











/*
double calcoli(char x[], char y[], char z[], char seed[])
{
    double origine=atof(y),destinazione=atof(x),intervallo=atof(z),seme=atof(seed);
    double lunghezza_intervallo_origine= (origine+intervallo)-1;
    double a,valore_di_ritorno= 0;
    char*inter;

    printf("\nOrigine: %.0f, Destinazione: %.0f, Intervallo: %.0f, seme: %.0f\n",origine,destinazione,intervallo,seme);*/

    /*sprintf(inter,"%f",lunghezza_intervallo_origine);
    int lung_x=strlen(x);
    int lung_y=strlen(y);
    int lung_z=strlen(z);
    int lung_seed=strlen(seme);
    int lung_inter=strlen(inter);

    if(lung_seed <= lung_inter && lung_seed >= lung_y){
        if()
    }*/

    /*if(seme <= lunghezza_intervallo_origine && seme >= origine){
        if(destinazione > origine){
            a= destinazione - origine;
            valore_di_ritorno= seme + a;
            printf("\nA: %.0f, Valore di ritorno: %.0f\n",a,valore_di_ritorno);
        }
        else{
            a= origine - destinazione;
            valore_di_ritorno= seme - a;
            printf("\nA: %.0f, Valore di ritorno: %.0f\n",a,valore_di_ritorno);
        }
    }

    return valore_di_ritorno;
}*/





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

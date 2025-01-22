#include <stdio.h>
#include <stdlib.h>

void function(int[], int*, int);
void function_2(int[], int*, int);
void function_3(int[], int*, int);
void function_4(int[], int*, int);
void function_5(int[], int*, int);

void f1(int[], char, int*, int*, int*, int*, int*, int*, int*, int*, int*);

int somma(int[], int);

/*
    1) PROBLEMA CON numero romano, ad esempio: CCCXCIX (PENSO DI AVER RISOLTO RISOLTO).
    2) Controllare problemi con numeri romani errati.

    AL MOMENTO IL PROGRAMMA è IN GRADO DI CONVERTIRE I NUMERI DA ROMANO A DECIMALE FINO ALLA CIFRA 3999, poichè per i numeri più grandi si utilizza
    un trattino sopra le lettere per indicare la moltiplicazione per 1000, e nel codice ASCII non sono codificati questi tipi di caratteri.
    Viceversa da decimale a romano sono riuscito a trovare una soluzione (più o meno)

*/


int main()
{
    int a,n=50,i,j=0,conta_cifre=0;

    int scelta,risultato,stop=0,cont_X=0,cont_L=0,cont_C=0,cont_V=0,cont_I=0,cont_D=0,cont_M=0;
    char carattere;

    int binario[n];

    for(i=0;i<n;i++)
        binario[i]= 0;


    printf("Se si vuole convertire un numero da decimale a romano premere '0', viceversa premere '1'\n");
    scanf("%d",&scelta);

    i=0;

    if(scelta == 0)
        printf("\nInserire una cifra alla volta del numero che si vuole convertire. Per terminare inserire -1\n");
    else
        printf("\nInserire una cifra romana alla volta (in maiuscolo). Per terminare inserire il carattere 'Z'\n");

    while(a != -1 && carattere != 'Z'){
        /*printf("i: %d\n",i);*/
        if(scelta == 0)
            scanf("%d",&a);
        else
            scanf("%c",&carattere);

        fflush(stdin);


        if(a != -1 && carattere != 'Z'){
            if(scelta == 0){
                binario[i]= a;
                conta_cifre++;
                i++;
            }
            else if(scelta == 1 && stop == 0)
                f1(binario,carattere,&i,&cont_I,&cont_V,&cont_X,&cont_L,&cont_C,&cont_D,&cont_M,&stop);
            else if(stop == 1)
                break;
        }
    }

    printf("\n");




    if(conta_cifre > 0 && conta_cifre <= 1 /*|| entra == 1*/){                   /*Numeri composti da un'unica cifra*/
        function(binario,&j,scelta);
    }

    else if(conta_cifre > 1 /*|| entra > 1*/){
        /*while(j < conta_cifre-1){*/

        if(conta_cifre == 2 /*|| entra == 2*/){               /*Numeri composti da due cifre*/
            function_2(binario,&j,scelta);
        }
        else if(conta_cifre == 3){          /*Numeri composti da tre cifre*/
            function_3(binario,&j,scelta);
        }
        else if(conta_cifre == 4){          /*Numeri composti da quattro cifre*/
            function_4(binario,&j,scelta);
        }
        else if(conta_cifre == 5){          /*Numeri composti da quattro cifre*/
            function_5(binario,&j,scelta);
        }

        /*j++;
        function(binario,&j);*/

        /*}*/
    }

    if(scelta == 1){
        risultato= somma(binario,n);
        if(stop == 0){
            /*risultato= somma(binario,n);*/
            printf("\nConversione da numero Romano a Decimale: %d",risultato);
        }
        else
            printf("\nIl numero romano inserito e' scorretto!\n");
    }

    printf("\n");

    return 0;
}






void function(int binario[], int*j, int scelta)
{
    int i;

    if(binario[*j] > 0 && binario[*j] <= 3){
        for(i=1;i<=binario[*j];i++)
            printf("I");
    }
    else if(binario[*j] == 4){
        printf("IV");
    }
    else if(binario[*j] >= 5 && binario[*j] < 9){
        if(binario[*j] == 5){
            printf("V");
        }
        else if(binario[*j] > 5){
            printf("V");
                for(i=5;i<binario[*j];i++)
                    printf("I");
        }
    }
    else if(binario[*j] == 9)
        printf("IX");

    /*printf(" 1\n");*/
}



void function_2(int binario[], int*j, int scelta)
{
    int i;

    if(binario[*j] > 0 && binario[*j] <= 3){
        for(i=1;i<=binario[*j];i++)
            printf("X");
    }
    else if(binario[*j] == 4)
        printf("XL");
    else if(binario[*j] >= 5 && binario[*j] < 9){
        printf("L");
        for(i=6;i<=binario[*j];i++)
            printf("X");
    }
    else if(binario[*j] == 9)
        printf("XC");

    /*printf(" 2\n");*/

    (*j)++;
    function(binario,j,scelta);
}



void function_3(int binario[], int*j, int scelta)
{
    int i;

    if(binario[*j] > 0 && binario[*j] <= 3){
        for(i=1;i<=binario[*j];i++)
            printf("C");
    }
    else if(binario[*j] == 4)
        printf("CD");
    else if(binario[*j] >= 5 && binario[*j] <= 8){
        printf("D");
        for(i=6;i<=binario[*j];i++)
            printf("C");
    }
    else if(binario[*j] == 9)
        printf("CM");

    /*printf(" 3\n");*/

    (*j)++;
    function_2(binario,j,scelta);
}



void function_4(int binario[], int*j, int scelta)
{
    int i;

    if(binario[*j] > 0 && binario[*j] < 4){
        for(i=1;i<=binario[*j];i++)
            printf("M");
    }
    else if(binario[*j] >= 4){
        if(binario[*j] == 4)
            printf("IV");
        else if(binario[*j] >= 5 && binario[*j] < 9){
            printf("V");
            for(i=5;i<binario[*j];i++)
                printf("I");
        }
        else if(binario[*j] == 9)
            printf("IX");

        printf("_");
    }

    /*printf(" 4\n");*/

    (*j)++;
    function_3(binario,j,scelta);
}



void function_5(int binario[], int*j, int scelta)
{
    int i;

    if(binario[*j] > 0 && binario[*j] < 4){
        for(i=1;i<=binario[*j];i++)
            printf("X");
    }
    else if(binario[*j] == 4)
        printf("XL");
    else if(binario[*j] >= 5 && binario[*j] < 9){
        printf("L");
        for(i=5;i<binario[*j];i++)
            printf("X");
    }
    else if(binario[*j] == 9)
        printf("XC");

    printf("_");

    /*printf(" 5\n");*/

    (*j)++;
    function_4(binario,j,scelta);
}










/*FUNCTION PER CONVERTIRE DA ROMANO A DECIMALE*/

void f1(int binario[], char carattere, int*pos, int*conta_I, int*conta_V, int*conta_X, int*conta_L, int*conta_C, int*conta_D, int*conta_M, int*stop)
{
    if(carattere == 'I'){
        if(carattere == 'I' && *conta_I < 4){       /*Serve per stampare i numeri decimali da 1 a 3*/
            binario[*pos]= binario[*pos] + 1;
            (*conta_I)++;
            *stop=0;
        }
        if(*conta_I >= 4){
            *stop=1;
            printf("\nA\n");}

        *conta_V=0,*conta_X=0,*conta_L=0,*conta_C=0,*conta_D=0,*conta_M=0;
    }


    if(carattere == 'V'){
        if(binario[*pos] == 1 && *conta_V <= 1 && *conta_I == 1){       /*Serve per stampare il numero decimale 4*/
            binario[*pos]= 4;
            (*conta_V)++;
            (*pos)++;
            *stop=0;
        }
        else if(*conta_I == 0 && *conta_V <= 1 && (*pos == 0 || binario[(*pos)-1] >= 10)){  /*Serve per stampare i numeri decimali da 5 a 8*/
            binario[*pos]= 5;
            (*conta_V)++;
            (*pos)++;
            *stop=0;
        }
        else{ /*if(binario[*pos] != 10 && binario[*pos] != 80 && binario[*pos] != 4)*/
            *stop=1;
            printf("\nB\n");}

        if(*conta_V > 1)
            *stop=1;

        *conta_I=0,*conta_X=0,*conta_L=0,*conta_C=0,*conta_D=0,*conta_M=0;
    }



    if(carattere == 'X'){
        if(binario[*pos] == 1){          /*Converte il numero romano 9 in decimale*/
            binario[*pos]= 9;
            (*pos)++;
        }
        else if((binario[(*pos)-1] > 9 || binario[*pos] == 0) && *conta_X < 4){     /*Serve per stampare i numeri decimali da 10 a 39*/
            binario[*pos]= 10;
            (*conta_X)++;
            (*pos)++;
            *stop=0;
        }
        else{
            *stop=1;
            printf("\nC\n");}

        if(*conta_X >= 4)
            *stop=1;

        *conta_I=0,*conta_V=0,*conta_L=0,*conta_C=0,*conta_D=0,*conta_M=0;
    }


    if(carattere == 'L'){
        if(binario[(*pos)-1] == 10 && binario[(*pos)-2] != 10 && *conta_L <= 1){    /*Serve per stampare i valori da 40 a 49*/
            binario[*pos]= 30;
            (*conta_L)++;
            (*pos)++;
            *stop=0;
        }
        else if((binario[(*pos)-1] >= 100 || *pos == 0) && *conta_L <= 1){     /*Serve per stampare i numeri decimali da 50 a 89*/
            binario[*pos]= 50;
            (*conta_L)++;
            (*pos)++;
            *stop=0;
        }
        else{
            *stop=1;
            printf("\nD\n");}

        if(*conta_L > 1)
            *stop=1;

        *conta_I=0,*conta_V=0,*conta_X=0,*conta_C=0,*conta_D=0,*conta_M=0;
    }



    if(carattere == 'C'){
        if((binario[(*pos)-1] == 10 && *pos == 1) && *conta_C < 4){    /*Serve per stampare i valori da 90 a 100*/
            binario[*pos]= 80;
            (*conta_C)++;
            (*pos)++;
            *stop=0;
        }
        else if((binario[(*pos)-1] == 10 && binario[(*pos)-2] >= 100 && *pos > 1) && *conta_C < 4){
            binario[*pos]= 80;
            (*conta_C)++;
            (*pos)++;
            *stop=0;
        }
        else if((binario[(*pos)-1] >= 100 || *pos == 0) && *conta_C < 4){     /*Serve per stampare i numeri decimali da 100 a 399*/
            binario[*pos]= 100;
            (*conta_C)++;
            (*pos)++;
            *stop=0;
        }
        else{/*if(binario[(*pos)-1] != 0)*/
            *stop=1;
            printf("\nE\n");}

        if(*conta_C >= 4)
            *stop=1;

        *conta_I=0,*conta_V=0,*conta_X=0,*conta_L=0,*conta_D=0,*conta_M=0;
    }



    if(carattere == 'D'){
        if((binario[(*pos)-1] == 100 && *pos == 1) && *conta_D <= 1){    /*Serve per stampare i valori da 400 a 499*/
            binario[*pos]= 300;
            (*conta_D)++;
            (*pos)++;
            *stop=0;
        }
        else if((binario[(*pos)-1] == 100 && binario[(*pos)-2] >= 1000 && *pos > 1) && *conta_D <= 1){
            binario[*pos]= 300;
            (*conta_D)++;
            (*pos)++;
            *stop=0;
        }
        else if((binario[(*pos)-1] >= 1000 || *pos == 0) && *conta_D <= 1){     /*Serve per stampare i numeri decimali da 500 a 899*/
            binario[*pos]= 500;
            (*conta_D)++;
            (*pos)++;
            *stop=0;
        }
        else{
            *stop=1;
            printf("\nF\n");}

        if(*conta_D > 1)
            *stop=1;

        *conta_I=0,*conta_V=0,*conta_X=0,*conta_L=0,*conta_C=0,*conta_M=0;
    }




    if(carattere == 'M'){
        if((binario[(*pos)-1] == 100 && *pos == 1) && *conta_M < 4){    /*Serve per stampare i valori da 900 a 999*/
            binario[*pos]= 800;
            (*conta_M)++;
            (*pos)++;
            *stop=0;
        }
        else if((binario[(*pos)-1] == 100 && binario[(*pos)-2] >= 1000 && *pos > 1) && *conta_M < 4){
            binario[*pos]= 800;
            (*conta_M)++;
            (*pos)++;
            *stop=0;
        }
        else if((binario[(*pos)-1] >= 1000 || *pos == 0) && *conta_M < 4){     /*Serve per stampare i numeri decimali da 1000 a 3999*/
            binario[*pos]= 1000;
            (*conta_M)++;
            (*pos)++;
            *stop=0;
        }
        else{
            *stop=1;
            printf("\nG\n");}

        if(*conta_M >= 4)
            *stop=1;

        *conta_I=0,*conta_V=0,*conta_X=0,*conta_L=0,*conta_C=0,*conta_D=0;
    }

    /*printf("\nPOS: %d, J: %d, UNO: %d\n",*pos,*j,*uno);*/
}




int somma(int a[], int n)
{
    int s=0,i;

    for(i=0;i<n;i++){
        if(a[i] != 0)
            printf("\nA: %d\n",a[i]);

        s= s+a[i];
    }

    return s;
}

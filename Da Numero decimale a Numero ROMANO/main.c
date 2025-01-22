#include <stdio.h>
#include <stdlib.h>

void function(int[], int*);
void function_2(int[], int*);
void function_3(int[], int*);
void function_4(int[], int*);
void function_5(int[], int*);

/*
    1) Per il momento funziona fino alla cifra 3999. Dopo i numeri romani moltiplicano per mille usando "il trattino alto",
       ad esempio, 5000: V (con il trattino sopra la V);
       RISOLTO questo problema utilizzando il trattino basso (vedi function_4 e function_5) visto che il computer non riconosce il trattino alto
       poichè non è codificato nella tabella ASCII;

    2) Al momento il programma è in grado di passare da decimale a romano fino alla cifra 99999;

*/


int main()
{
    int a,n=9,i,j=0,conta_cifre=0;

    int binario[n];


    i=0;
    printf("Inserire una cifra alla volta del numero che si vuole convertire. Per terminare inserire -1\n");
    while(a != -1){
        scanf("%d",&a);

        if(a != -1){
            binario[i]= a;
            conta_cifre++;
        }

        i++;
    }

    printf("\n");




    if(conta_cifre <= 1){                   /*Numeri composti da un'unica cifra*/
        function(binario,&j);
    }

    else if(conta_cifre > 1){
        /*while(j < conta_cifre-1){*/

        if(conta_cifre == 2){               /*Numeri composti da due cifre*/
            function_2(binario,&j);
        }
        else if(conta_cifre == 3){          /*Numeri composti da tre cifre*/
            function_3(binario,&j);
        }
        else if(conta_cifre == 4){          /*Numeri composti da quattro cifre*/
            function_4(binario,&j);
        }
        else if(conta_cifre == 5){          /*Numeri composti da quattro cifre*/
            function_5(binario,&j);
        }

        /*j++;
        function(binario,&j);*/

        /*}*/
    }

    printf("\n");

    return 0;
}




void function(int binario[], int*j)
{
    int i;

    if(binario[*j] > 0 && binario[*j] <= 3){
        for(i=1;i<=binario[*j];i++)
            printf("I");
    }
    if(binario[*j] == 4){
        printf("IV");
    }
    if(binario[*j] >= 5 && binario[*j] < 9){
        if(binario[*j] == 5)
            printf("V");
        else if(binario[*j] > 5){
            printf("V");
            for(i=5;i<binario[*j];i++)
                printf("I");
        }
    }
    if(binario[*j] == 9)
        printf("IX");

    /*printf(" 1\n");*/
}



void function_2(int binario[], int*j)
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
    function(binario,j);
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



void function_4(int binario[], int*j)
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
    function_3(binario,j);
}



void function_5(int binario[], int*j)
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
    function_4(binario,j);
}


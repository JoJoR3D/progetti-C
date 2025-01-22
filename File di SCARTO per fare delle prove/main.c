#include <stdio.h>
#include <stdlib.h>

void clearArray(char[], int);
void lunghezza_due_array(char*, char*, int*, int*);
void lung(int, int, int*, int*);
void LUNGHEZZA(int, int, int*);
int check(char*, int*, int);
int check2(int*, int*, int);
void calcoli(int*, int, char*, int*, int);
void operazione_somma(int, int, char*, char*, int, int*, int*, int*);
void operazione_differenza(int, int, char*, char*, int*, int*, int*, int);

int main()
{
    /*double s=0;

    for(i=3082872446;i<3399552858;i++){
        printf("%.0f\n",s++);
    }*/

    /*char a[11];
    char b[11];

    clearArray(a,11);
    clearArray(b,11);*/

    /*char a[]={'2','1','7','\0'};
    char b[]={'2','5','\0'};*/

    char a[]={'3','0','8','2','8','7','2','4','4','6','\0'};
    char b[]={'3','1','6','6','8','0','4','1','2','\0'};
    int numeri[]={48,49,50,51,52,53,54,55,56,57};

    int operazione,lung_a,lung_b;

    printf("Inserire 0 se si vuole eseguire un'operazione di somma tra due array di caratteri,\naltrimenti 1 se si vuole eseguire una sotrrazione:\n");
    scanf("%d",&operazione);



    /*Calcola la lunghezza dei due array di caratteri dati in input*/

    lunghezza_due_array(a,b,&lung_a,&lung_b);

    printf("\nLunghezza array A: %d\nLunghezza array B: %d\n",lung_a,lung_b);



    int i,differenza1=0,differenza2=0,somma[20],indice,lunghezza;

    /*Ritorna quant è la differenza delle due lunghezze dei due array di char*/

    lung(lung_a,lung_b,&differenza1,&differenza2);

    printf("\nDifferenza1: %d\nDifferenza2: %d\n",differenza1,differenza2);



    /*Ritorna chi tra i due array di char 'a' e 'b' è più lungo*/

    LUNGHEZZA(lung_a,lung_b,&lunghezza);



    /*Questa prima function esegue l'operazione di somma e mi ritorna nell'array somma la somma di ogni numero in colonna dei due array di caratteri 'a' e 'b'*/
    /*La seconda function esegue l'operazione di sottrazione e mi ritorna nell'array somma la sottrazione di ogni numero in colonna dei due array di caratteri 'a' e 'b'*/

    if(operazione == 0)
        operazione_somma(differenza1,differenza2,a,b,lunghezza,numeri,somma,&indice);
    else
        operazione_differenza(differenza1,differenza2,a,b,numeri,somma,&indice,lunghezza);




    char seed[lunghezza];

    printf("\n\nINDICE: %d\n",indice);

    printf("\n\nValore finale:\n");

    /*Function che ritorna il valore finale della somma eseguita sopra*/

    calcoli(somma,indice,seed,numeri,lunghezza);

    printf("\n");

    for(i=0;seed[i]!='\0';i++)
        printf("%d-Valore: %c\n",i+1,seed[i]);

    return 0;
}



/*FUNCTION*/




void operazione_somma(int differenza1, int differenza2, char*a, char*b, int dim, int*numeri, int*somma, int*indice)
{
    int i,valore1,valore2;
    *indice=0;

    for(i=0;i<dim;i++){
        if(differenza1 != 0 && i >= differenza1){
            /*if(a[i] == '\0')
                break;*/
            valore1= check(&a[i],numeri,dim);
            valore2= check(&b[i-differenza1],numeri,dim);

            somma[*indice]= valore1+valore2;
            printf("\nSomma1: %d, valore1: %d, valore2: %d, I: %d\n",somma[*indice],valore1,valore2,i);
            (*indice)++;
        }
        else if(differenza2 != 0 && i >= differenza2){
            /*if(b[i] == '\0')
                break;*/
            valore1= check(&a[i-differenza2],numeri,dim);
            valore2= check(&b[i],numeri,dim);

            somma[*indice]= valore1+valore2;
            printf("\nSomma2: %d, valore1: %d, valore2: %d, I: %d\n",somma[*indice],valore1,valore2,i);
            (*indice)++;
        }
        else{
            if(differenza1 > 0){
                valore1= check(&a[i],numeri,dim);
                somma[*indice]= valore1;
                printf("\nSomma3: %d\n",somma[*indice]);
                (*indice)++;
            }
            else if(differenza2 > 0){
                valore2= check(&b[i],numeri,dim);
                somma[*indice]= valore2;
                printf("\nSomma3: %d\n",somma[*indice]);
                (*indice)++;
            }
        }
    }
}





void operazione_differenza(int differenza1, int differenza2, char*a, char*b, int*numeri, int*somma, int*indice, int dim)
{
    int i,valore1,valore2,index;
    index=dim;
    dim--;
    *indice=dim;

    for(i=dim;i>=0;i--){
        if(differenza1 != 0 && i >= differenza1){
            printf("\nDentro\n");
            /*if(a[i] == '\0')
                break;*/
            valore1= check(&a[i],numeri,dim);
            valore2= check(&b[i-differenza1],numeri,dim);

            if(valore1 < valore2){
                valore1= valore1+10;
                somma[*indice]= valore1-valore2;
                a[i-1]= a[i-1]-1;
            }
            else
                somma[*indice]= valore1-valore2;

            printf("\nSomma1: %d, valore1: %d, valore2: %d, I: %d\n",somma[*indice],valore1,valore2,i);
            (*indice)--;
        }
        else if(differenza2 != 0 && i >= differenza2){
            /*if(b[i] == '\0')
                break;*/
            valore1= check(&a[i-differenza2],numeri,dim);
            valore2= check(&b[i],numeri,dim);

            if(valore1 < valore2){
                valore1= valore1+10;
                somma[*indice]= valore1-valore2;
                a[i-1]= a[i-1]-1;
            }
            else
                somma[*indice]= valore1-valore2;

            printf("\nSomma2: %d, valore1: %d, valore2: %d, I: %d\n",somma[*indice],valore1,valore2,i);
            (*indice)--;
        }
        else{
            if(differenza1 > 0){
                valore1= check(&a[i],numeri,dim);
                somma[*indice]= valore1;
                printf("\nSomma3: %d\n",somma[*indice]);
                (*indice)--;
            }
            else if(differenza2 > 0){
                valore2= check(&b[i],numeri,dim);
                somma[*indice]= valore2;
                printf("\nSomma3: %d\n",somma[*indice]);
                (*indice)--;
            }
        }
    }
    *indice=index;
}





void calcoli(int*somma, int n, char*s, int*numeri, int dim)
{
    int i,valore;
    s[n]= '\0';     /*Assegno all'ultima posizione il carattere di fine stringa*/
    n--;
    /*printf("N: %d\n",n);*/

    for(i=n;i>=0;i--){
        if(somma[i] > 10){
            somma[i]= somma[i]-10;
            somma[i-1]= somma[i-1]+1;
        }
        valore= check2(numeri,&somma[i],dim);
        s[i]= valore;
        /*printf("somma[%d]: %d, s[%d]: %c, Valore: %d\n",i,somma[i],i,s[i],valore);*/
    }
}




/*Ritorna il valore numerico corrispondente (int) al carattere numerico (char)*/

int check(char*a, int*b, int n)
{
    int i;

    for(i=0;i<n;i++){
        if(*a == b[i])
            break;
    }
    return i;
}



/*Ritorna il carattere numerico (char) corrispondente al valore numerico (int)*/

int check2(int*a, int*b, int n)
{
    int i;

    for(i=0;i<n;i++){
        if(i == *b){
            printf("I: %d, B: %d, A[i]: %d\n",i,*b,a[i]);
            break;
        }
    }
    return a[i];
}



/*Calcola la lunghezza dei due array di caratteri dati in input*/

void lunghezza_due_array(char*a, char*b, int*lung_a, int*lung_b)
{
    int i,blocco1=0,blocco2=0;
    *lung_a=0;
    *lung_b=0;

    for(i=0;a[i]!='\0';i++){
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
    }
}



/*Ritorna quant è la differenza delle due lunghezze dei due array di char*/

void lung(int lung_a, int lung_b, int*differenza1, int*differenza2)
{
    if(lung_a > lung_b){
        *differenza1= lung_a-lung_b;
    }
    else{
        *differenza2= lung_b-lung_a;
    }
}



/*Ritorna chi tra i due array di char 'a' e 'b' è più lungo*/

void LUNGHEZZA(int lung_a, int lung_b, int*lunghezza)
{
    if(lung_a > lung_b)
        *lunghezza= lung_a;
    else
        *lunghezza= lung_b;
}




void clearArray(char a[], int n)
{
    int i;

    for(i=0;i<n;i++)
        a[i]= ' ';
}

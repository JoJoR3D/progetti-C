#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
    *
    *
    *
    *
    *
    VERSIONE NON DEFINITIVA.
    QUELLA DEFINITIVA E FUNZIONANTE SI CHIAMA: Cambia le posizioni delle parole in una stringa (1)
    *
    *
    *
    *
    *
*/





void swap_position(char*s,int n);
void swap(char*s,char*v);

int main()
{
    /*int*x=5;
    int*y=6;

    int*t=&x;

    printf("%d %d",&x,*t);*/

    char stringa[]= "Alice nel paese delle meraviglie con il gatto matto"/*"Corro e non mi importa"*//*"salto felice nella giungla"*/;
    int n;
    n= strlen(stringa);

    puts(stringa);

    swap_position(stringa,n);

    puts(stringa);

    int m=strlen(stringa);

    printf("\n%d %d",n,m);

    return 0;
}



void swap_position(char*s,int n)
{
    int fine=n-1,inizio=0,i,j,cont_1=0,dim_parola1=0,dim_parola2=0,DIM,fin,iniz,ciclo=0,conta_parola=0,conta_char_sx=0,conta_char_dx=n-1,cont,ripet_i=0,ripet_j=0;
    char t;
    int divide_in_due= (inizio+fine)/2;
    char*p= &s[0];


    while(inizio </*=*/ divide_in_due && fine >/*=*/ divide_in_due && fine < n){
        printf("I= %d, F= %d Divide: %d\n\n\n",inizio,fine,divide_in_due);
        i=inizio;
        j=fine;

        if(s[i]== ' ')
            i++;
        if(s[j]== ' ')
            j--;

        printf("\nPRIMA i:%d j:%d\n\n",i,j);



        while(s[i] != ' '){
            i++;
            dim_parola1++;}
        while(s[j] != ' '){
            j--;
            dim_parola2++;
            printf("\nDIM_PAROLA2= %d\n",dim_parola2);}

        printf("\nDOPO i:%d j:%d\n\n",i,j);

        i=i-1;
        j=j+1;

        cont_1=j;

        char*punt_inizio;
        punt_inizio= &s[i];

        char*punt_fine;
        punt_fine=&s[cont_1];

        printf("\n\nPuntatori = %d %d, %c %c %d %d %d\n\n",punt_inizio,punt_fine,*punt_inizio,*punt_fine,inizio,cont_1,&i);


        if(dim_parola1 < dim_parola2)
            DIM= dim_parola2-dim_parola1;
        else
            DIM= dim_parola1-dim_parola2;

        ripet_i=0;
        ripet_j=0;

        puts(s);

        printf("%d %d %d DIM:%d %d %d Inizio: %d, Fine: %d\n\n",i,j,cont_1,DIM,dim_parola1,dim_parola2,inizio,fine);

        while(inizio <= i &&/*||*/ fine >= j){
            /*if(inizio <= i && fine >= j){*/
                if(s[inizio] == ' ')
                    inizio++;

                swap(&s[inizio],&s[cont_1]);
                conta_char_sx++;
                conta_char_dx--;
                inizio++;
                fine--;
                cont_1++;
                printf("Inizio:%d fine:%d cont_1:%d i:%d j:%d\n",inizio,fine,cont_1,i,j);
            /*}*/
        }
        puts(s);


            if(inizio > i && inizio < divide_in_due && inizio != ' '){
                cont= inizio+DIM;
                while(ripet_i < DIM){
                printf("INIZIOOOO: %d FINEEEE: %d %c\n",inizio,fine,s[inizio+1]);
                /*if(inizio > i){*/
                    printf("CACCA1");
                    while(inizio < cont){
                        fin=cont_1;
                        iniz=inizio;
                        s[inizio]= s[cont_1];       /*Swap di una posizione di ogni carattere della stringa*/
                        puts(s);
                        while(fin >/*=*/ iniz+DIM-1/*2*/){
                            s[fin]= s[fin-1];
                            fin--;
                            puts(s);
                        }
                        inizio++;
                        cont_1++;
                        iniz++;
                        /*fine--;*/
                        conta_char_sx++;
                        printf("\n%d  %d %d %dCACCA100\n",inizio,fine,cont_1,fin);
                    }
                /*}*/
                ripet_i++;
            }
            fine--;
            int puntatore= punt_inizio-p;
            int new_punt= puntatore+DIM+1;
            s[new_punt]=' ';
            printf("\n\nRIPET: %d\n\n",ripet_i);
            puts(s);

    }



                else if(fine < j && fine > divide_in_due && fine != ' '){
                     int cont_f= cont_1;
                     cont_1=cont_1-DIM;
                     while(ripet_j < DIM){
                    /*int cont_f= cont_1+DIM*/;
                    ciclo=1;
                    printf("\n\nPIPIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII\n\n");

                    while(cont_1 < cont_f){
                        fin=cont_1+DIM;
                        iniz=inizio;
                        iniz=iniz+DIM-ciclo;

                        if(s[iniz] != ' '){
                            while(s[iniz] != ' ')
                                iniz++;
                        }

                        /*t= s[iniz];*/

                        printf("Iniz: %d cont_1: %d %c fin:%d iniz:%d\n",iniz,cont_1,t,fin,iniz);

                        while(iniz < fin-1){
                            s[iniz]= s[iniz+1];
                            puts(s);
                            iniz++;
                        }
                        /*s[cont_1+1]= t;*/

                        /*s[iniz]=' ';*/
                        /*inizio++;*/
                        /*s[n-1]= t;*/
                        cont_1++;
                        /*fine--;*/
                        ciclo++;
                        conta_char_dx--;
                        puts(s);
                        /*printf("\nCCCCC: %d %d %c %d %d\n",cont_1,cont_f,s[cont_1],fine,j);*/
                        int puntatore= punt_fine-p;
                        int new_punt= puntatore+dim_parola1-1;
                        s[new_punt]=' ';
                        printf("\n\npuntatore: %d, new_punt: %d\n\n",puntatore,new_punt);
                    }
                    /*s[cont_1]= t;*/
                    fine--;
                    printf("\nCCCCC: %d %d %c %d %d %c %d\n",cont_1,cont_f,s[cont_1],fine,j,t,ciclo);
                    ripet_j++;
                }
                /*int puntatore= punt_fine-p;
                int new_punt= puntatore+dim_parola1-1;
                s[new_punt]=' ';
                printf("\n\npuntatore: %d, new_punt: %d\n\n",puntatore,new_punt);*/
                }
                inizio=inizio+ciclo;
                puts(s);
            /*}*/
            /*inizio++;
            fine--;*/
            cont_1++;
            dim_parola1=0;
            dim_parola2=0;
            printf("Primo:%d Secondo:%d %d\n",inizio,fine,cont_1);
        /*}*/
        conta_parola++;
        printf("\nconta_char_sx: %d, conta_char_dx: %d\n",conta_char_sx,conta_char_dx);
        printf("\n");
    }
}


void swap(char*s,char*v)
{
    char t;
    t=*s;
    *s=*v;
    *v=t;
}

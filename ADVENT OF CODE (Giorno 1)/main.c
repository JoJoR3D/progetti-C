#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*int trova(char*, int[], int);*/


int main()
{
    char s[100];
    char a[3];
    char*secondo;
    char*v;
    char*ptr;

    int i,l,cont=0,blocco=0,ingresso=0,contatore=0,rit;


    FILE*fp;

    fp= fopen("input.txt","r");

    if(fp == NULL){
        printf("Errore\n");
        exit(1);
    }

    while(!feof(fp)){
        fscanf(fp,"%s",&s[0]);
        l=strlen(s);
        printf("%s\n",s);

        for(i=0;i<l;i++){
            if(s[i] >= 48 && s[i] <= 57){
                if(blocco == 0){
                    v=&s[i];
                    /*printf("V: %c\n",*v);*/
                    blocco=1;
                }
                else{
                    secondo=&s[i];
                    /*printf("Secondo: %c\n",*secondo);*/
                }

                ingresso++;
            }


            if(i == l-1 && ingresso > 1){
                /*printf("First\n");*/
                strncpy(&a[0],v,1);
                strncpy(&a[1],secondo,1);
                /*puts(a);*/
                rit= strtol(a,&ptr,10);
                printf("\n%d RIT: %d\n",cont,rit);
                contatore= contatore + rit;
                /*contatore= contatore + trova(a,b,numb);
                printf("%s, %d\n",a,contatore);
                puts(a);*/
            }
            else if(i == l-1 && ingresso == 1){
                /*printf("Second\n");*/
                strncpy(&a[0],v,1);
                strncpy(&a[1],v,1);
                /*printf("%c %c %c",a[0],a[1],a[2]);*/
                rit= strtol(a,&ptr,10);
                printf("\n%d RIT: %d\n",cont,rit);
                contatore= contatore + rit;
                /*contatore= contatore + trova(a,b,numb);
                printf("%s, %d\n",a,contatore);
                puts(a);*/
            }

            /*printf("\n\nCONTATORE: %d\n",contatore);*/
        }

        cont++;
        blocco=0,ingresso=0;
        /*sleep(4.0);*/
        printf("\n\n");
    }

    printf("\n\nCONTATORE: %d\n",contatore);

    fclose(fp);

    return 0;
}




/*
int trova(char*a, int b[], int n)
{
    int i=0;

    while(i < n){
        printf("carattere: %c indice: %d\n",a[0],i);
        if(a[0] == b[i])
            break;

        i++;
    }

    return i;
}
*/

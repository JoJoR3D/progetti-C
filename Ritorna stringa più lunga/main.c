#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char lunghezza(char[], char[]);

int main()
{
    char stringa1[20];
    char stringa2[20];

    puts("Inserire stringa1: ");
    gets(stringa1);

    printf("\n");

    puts("Inserire stringa2: ");
    gets(stringa2);

    printf("\n");

    int i;

    int strl1=strlen(stringa1);
    int strl2=strlen(stringa2);
    int acc=lunghezza(stringa1,stringa2);

    if(acc==1){
        printf("La prima stringa '");
        for(i=0;i<strl1;i++)
            printf("%c",stringa1[i]);                                           /*Stampa la stringa stringa1*/
        printf("' ha una dimensione maggiore rispetto alla seconda stringa '");

        for(i=0;i<strl2;i++)
            printf("%c",stringa2[i]);                                           /*Stampa la stringa stringa2*/
        printf("'.");
    }

    else{
        printf("La seconda stringa '");
        for(i=0;i<strl2;i++)
            printf("%c",stringa2[i]);                                          /*Stampa la stringa stringa2*/
        printf("' ha una dimensione maggiore rispetto alla prima stringa '");

        for(i=0;i<strl1;i++)
            printf("%c",stringa1[i]);                                          /*Stampa la stringa stringa1*/
        printf("'.");
    }


    return 0;
}


char lunghezza(char stringa1[], char stringa2[])
{
    if(strlen(stringa1) > strlen(stringa2))
        return 1;

    return 0;
}

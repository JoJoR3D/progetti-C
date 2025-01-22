#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lib.c"
#include "Prot.h"

/*CONVERTE TUTTA LA STRINGA IN MINUSCOLO*/


int main()
{
    int n=50;
    char String[n];
    char string;
    int i;

    gets(String);

    if(strlen(String) < n){
        for(i=0;i<strlen(String);i++){
            string= convert(String[i]);
            printf("%c",string);}
    }
    else
        printf("ERRORE la stringa e' troppo grande");

    return 0;
}

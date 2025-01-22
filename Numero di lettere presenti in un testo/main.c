#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void leggi_da_tastiera(char*s);
void visualizza(char*s);
int conta_lettere(char*s);

int main()
{
    int n=100;
    char stringa[n];

    printf("Inserire la stringa:\n");
    leggi_da_tastiera(stringa);

    printf("\nVisualizazzione della stringa immessa da tastiera:\n");
    visualizza(stringa);

    int num_di_lettere= conta_lettere(stringa);

    printf("\n\nil numero di lettere, spazi esclusi, presenti nella stringa e': %d\n",num_di_lettere);

    return 0;
}



void leggi_da_tastiera(char*s)
{
    gets(s);

    /*Invece di questo ciclo while e di int i e char c potevo semplicemente usare un gets(s).
      Ma non lo posso fare perchè inserisce anche caratteri a caso presenti nel buffer.

    int i=0;
    char c;

    while(c != '\n'){
        c=getchar();
        s[i]=c;
        i++;
    }
    */
}


void visualizza(char*s)
{
    int i=0;

    while(s[i] != '\0'){    /*Invece di questo ciclo while e di int i potevo semplicemente usare un puts(s)*/
        printf("%c",s[i]);
        i++;
    }
}


int conta_lettere(char*s)
{
    int i=0, conta=0;

    while(s[i] != '\0'){
        if(s[i] != ' ')
            conta++;
        i++;
    }
    return conta;
}


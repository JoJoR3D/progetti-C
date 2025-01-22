#include <stdio.h>
#include <stdlib.h>

/*
    L’utente inserisce una sequenza di caratteri, terminata dal carattere ‘#’. Il programma visualizza i
    caratteri, trasformando tutte le lettere minuscole in maiuscole.
    Eventuali caratteri diversi dalle lettere minuscole e dal ‘#’ devono essere visualizzati come ‘_’; il
    carattere ‘#’ deve essere anch’esso visualizzato.
*/


void caps_lock(char*);


int main()
{
    char Carattere;

    do{
        Carattere= getchar();
        caps_lock(&Carattere);
        printf("%c",Carattere);
    }while(Carattere != 35);

    return 0;
}



void caps_lock(char*c)
{
    if(*c>=97 && *c<=122)                         /*Nella Tabella ASCII tra 97 e 122 ci sono i caratteri minuscoli*/
        *c= *c - 32;                              /*Sottraendo 32 al carattere minuscolo ottengo il carattere maiuscolo*/
    else if(*c == 35 || (*c>=65 && *c<=90))       /*35 è il carattere cancelletto '#'. Oppure se il carattere è già maiuscolo. Tra 65 e 90 ci sono i caratteri maiuscoli*/
        *c= *c;
    else
        *c= 95;                                   /*95 è il carattere under score '_'*/
}

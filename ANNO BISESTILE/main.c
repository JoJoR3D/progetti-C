#include <stdio.h>
#include <stdlib.h>

/*
    Link che spiega come calcolare l'anno bisestile: https://learn.microsoft.com/it-it/office/troubleshoot/excel/determine-a-leap-year
*/

/*
    L’utente inserisce un anno ed il calcolatore verifica se è bisestile.
    Se l’utente inserisce un numero minore di zero il programma termina (senza ovviamente fare alcuna
    verifica); altrimenti, al termine della verifica, si ricomincia daccapo.
    Un anno è bisestile se è divisibile per 4.

    Tuttavia, c'è ancora un piccolo errore che deve essere tenuto in considerazione. Per eliminare questo errore, il calendario gregoriano stabilisce che un anno
    divisibile per 100 (ad esempio il 1900) è un anno bisestile solo se è anche divisibile per 400.
    Per questo motivo, gli anni successivi non sono anni bisestili:
    1700, 1800, 1900, 2100, 2200, 2300, 2500, 2600
    Questo perché sono equamente divisibili per 100 ma non per 400.
    I seguenti anni sono bisestili: 1600, 2000, 2400
*/


int bisestile(int*);


int main()
{
    int anno,result;
    printf("Inserire anno: ");
    scanf("%d",&anno);

    result= bisestile(&anno);

    while(anno >= 0){
        if(result != 0)
            printf("L'anno inserito NON e' bisestile\n");
        else if(result == 0)
            printf("L'anno inserito e' bisestile\n");

        printf("\nReinserire anno: ");
        scanf("%d",&anno);

        result= bisestile(&anno);
    }
    if(anno < 0)
        printf("FINE!\n");

    return 0;
}


int bisestile(int*Anno)
{
    int resto4;
    float resto100, resto400;

    resto4= *Anno%4;
    resto100= *Anno%100;
    resto400= *Anno%400;

    /*
        Spiegazione if/else:
        Ad esempio l'anno 1600 è bisestile perchè:
        1600%4= 0 (VERO) && 1600%100= 0 (FALSE) il risultato di questo AND restituisce FALSE (Prima è VERA seconda è FALSE), passiamo al OR
        1600%400= 0 (VERO). FALSE del operazione di prima e il VERO di questa operazione, secondo la tabella OR, restituisce VERO.
        Quindi questo if restituirà 0 (1600 è un anno bisestile).

        Altro esempio l'anno 2020 è bisestile perchè:
        2020%4= 0 (VERO) && 2020%100= 20 (VERO) il risultato di questo AND restituisce VERO (Prima è VERA seconda è VERA), passiamo al OR
        2020%400= 20 (FALSE). VERO del operazione di prima e il FALSE di questa operazione, secondo la tabella OR, restituisce VERO.
        Quindi questo if restituirà 0 (2020 è un anno bisestile).

        Altro esempio l'anno 2018 è bisestile perchè:
        2018%4= 2 (FALSE) && 2018%100= 18 (VERO) il risultato di questo AND restituisce FALSE (Prima è FALSE seconda è VERA), passiamo al OR
        2018%400= 18 (FALSE). FALSE del operazione di prima e il FALSE di questa operazione, secondo la tabella OR, restituisce FALSE.
        Quindi questo if restituirà 1 (2018 NON è un anno bisestile).
    */

    if((resto4 == 0 && resto100 != 0) || (resto400 == 0))
        return 0;
    else
        return 1;
}

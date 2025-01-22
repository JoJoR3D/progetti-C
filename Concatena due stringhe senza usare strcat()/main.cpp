#include <iostream>
#include <cstring>  /*cstring è uguale a string.h del linguaggio C, ma diciamo che è una versione per il C++*/


void concatenazione(char*, char*);


/*
    N.B:
    Se in stringa e stringa1 inserisco delle stringhe più lunghe rispetto a quelle inserite ora ("Ciao" e "Mondo"), senza indicare la dimensione dei due array di char,
    il progamma funziona, le due stringhe vengono concatenate, ma il programma non termina e va in segmentatio fault.
    Invece se inserisco la dimensione, ad esempio: char stringa[100] e char stringa2[100], funziona tutto e non va in segmentation fault.
    Questo perchè la stringa di destinazione deve contenere abbastanza spazio per contenere la stringa che già contiene più la stringa che verrà concatenata.

    N.B;
    Devo usare due array di stringhe e non due puntatori a char perchè, in quest ultimo caso, sarebbero due costanti stringhe le quali non possono essere modificate.
    char stringa[]= "Ciao";     SI!
    char stringa2[]= "Mondo!";  SI!

    char*stringa= "Ciao";     NO!
    char*stringa2= "Mondo!";  NO!
*/

/*
    N.B.
    Anche se il compilatore di Code::Blocks non da errore, questo codice è molto pericoloso, perchè la stringa s1 (stringa[]) ha come dimensione 5
    (considerando anche il terminatore), quindi nello stack di memoria, per s1 è sato allocato uno spazio di 5 byte.
    Ma quando andoamo a concatenare in s1 anche la stringa s2, andiamo ad occupare più spazio rispetto ai 6 byte dichiarati al momento della dichiarazione di s1.
    Quindi è come se stessimo scrivendo in un'area di memoria che non apartiene ad s1.
    Infatti alcuni compilatori, più smart, segnalano l'errore: "stack smashing detected".

    Per ovviare a questo problema basta dichiarare, in maniera statica o dinamica, una dimensione maggiore per s1 in modo che possa contenere senza problemi anche s2.
    Ad esempio: char s1[50]= "Ciao";
    In questo modo abbiamo allocato per s1 50 byte, quindi c'è spazio per aggiungere altri 44 byte (45 caratteri, consideranto già i 5 occupati dalla stringa: Ciao).
*/


int main()
{
    char stringa[]= "Ciao";
    char stringa2[]= "Mondo!";

    printf("Prima stringa: ");
    std::cout << stringa << std::endl;
    printf("Seconda stringa: ");
    std::cout << stringa2 << std::endl;
    printf("\n");

    printf("Lunghezza prima stringa: ");
    std::cout << strlen(stringa) << std::endl;
    printf("Lunghezza seconda stringa: ");
    std::cout << strlen(stringa2) << std::endl;
    printf("\n");

    concatenazione(stringa,stringa2);

    printf("\nStringa concatenata: ");
    std::cout << stringa << std::endl;
    printf("\nLunghezza Stringa concatenata: ");
    std::cout << strlen(stringa) << std::endl;  /*La lunghezza è 11 perchè bisogna considerare anche lo spazio che inserisco tra la stringa "Ciao" e la stringa "Mondo".*/

    return 0;
}




void concatenazione(char*s, char*t) /*char*s è la stringa di destinazione della concatenazione. Quindi concateno a *s la stringa *t.*/
{
    int lung1= strlen(s);           /*Lunghezza stringa*/
    int lung2= strlen(t);           /*Lunghezza stringa2*/
    int lung_tot= lung1+lung2+1;    /*Sommo la lunghezza delle due stringhe. +1 è per considerare anche il terminatore*/
    int i,j=-1;

    for(i=0;i<=lung_tot;i++){       /*i<=lung_tot perchè altrimenti, senza l'uguale, non copierebbe anche il terminatore*/
        if(i >= lung1){             /*i>=lung1 cioè quando i è >= al carattere terminatore della prima stringa*/
            if(i == lung1)          /*Quando i è == al carattere terminatore della prima stringa, sostituisci al terminatore il carattere 'spazio'*/
                *(s+i)= ' ';
            else{                   /*Dalle posizioni successive della prima stringa, inserisci, uno ad uno, i caratteri della seconda stringa iniziando da *(t+0) ovvero 'M'*/
                j++;                /*incremento l'indice j per accedere a tutti i caratteri della seconda stringa.*/
                *(s+i)= *(t+j);
            }
        }
        printf("%c\n",*(s+i));
    }
}

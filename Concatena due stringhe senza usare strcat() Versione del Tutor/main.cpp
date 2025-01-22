#include <iostream>
#include <cstring>


void concatenazione(char[], const char*);

/*
    Lez. Tutor Prog. II del 4-4-22
*/


/*
    N.B.
    Anche se il compilatore di Code::Blocks non da errore, questo codice è molto pericoloso, perchè la stringa s1 ha come dimensione 6
    (considerando anche il terminatore), quindi nello stack di memoria, per s1 è sato allocato uno spazio di 6 byte.
    Ma quando andoamo a concatenare in s1 anche la stringa s2, andiamo ad occupare più spazio rispetto ai 6 byte dichiarati al momento della dichiarazione di s1.
    Quindi è come se stessimo scrivendo in un'area di memoria che non apartiene ad s1.
    Infatti alcuni compilatori, più smart, segnalano l'errore: "stack smashing detected".

    Per ovviare a questo problema basta dichiarare, in maniera statica o dinamica, una dimensione maggiore per s1 in modo che possa contenere senza problemi anche s2.
    Ad esempio: char s1[50]= "Ciao ";
    In questo modo abbiamo allocato per s1 50 byte, quindi c'è spazio per aggiungere altri 44 byte (44 caratteri, consideranto già i 6 occupati dalla stringa: Ciao).
*/


int main()
{
    char s1[]= "Ciao ";
    const char*s2= "Mondo!";    /*Essendo s1 la stringa di destinazione della concatenazione, s2 posso dichiararla anche come costante stringa,
                                  perchè tanto non verrà modificata.
                                  Le stringhe costanti non possono essere modificate, per questo s1 è dichiarato come un array di stringhe. Perchè s1 dovrà contenere
                                  La stringa "Ciao " e la stringa contenuta in s2: "Mondo!"*/

    concatenazione(s1,s2);

    std::cout << s1 << std::endl;
    return 0;
}


void concatenazione(char s1[], const char*s2)
{
    int i;
    int s1len= strlen(s1), s2len= strlen(s2);

    for(i=0; i<=s2len; i++){
        s1[s1len+i]= *(s2+i);   /*Partendo dall'utlima posizione di s1 comincio ad assegnare i caratteri di s2, incrementando ogni volta l'indice i*/
    }
}

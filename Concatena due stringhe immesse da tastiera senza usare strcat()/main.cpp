#include <iostream>
#include <cstring>

using namespace std;

void concatenazione(char[], char[]);


int main()
{
    char s[50];
    printf("Inserisci prima stringa: ");
    gets(s);
    printf("Inserisci seconda stringa: ");
    char s1[50];
    gets(s1);

    printf("Stringa concatenata: ");
    concatenazione(s,s1);

    cout << s << endl;

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
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*N.B. SE CI SONO PIU' PAROLE CHE HANNO LA STESSA LUNGHEZZA MINIMA, LA FUNCTION MI RITORNA LA PRIMA PAROLA TROVATA CON LA LUNGHEZZA MINIMA.
  Ad esempio: trovo come parola di lunghezza minima: "al", poi trovo anche "io" e poi ancora "tu".
  La parla di lunghezza minima che mi viene ritronata dalla function 'lung_min' è la prima trovata ovvero: "al".*/


void lung_min(char*string, int dim, char*min);
int Strlen(char*s);
void Strcpy(char*s, char*t);

int main()
{
    char stringa[]= "Pappagallo ripete sempre quello che dico al meno che non taccio";  /*PROBLEMI CON LA STRINGA PIU' CORTA ALLA FINE.*/
    int dim= strlen(stringa),i;

    for(i=0;i<dim;i++)
        printf("%c",stringa[i]);
    printf("\n");

    char min[dim];

    lung_min(stringa,dim,min);

    printf("\nLa parola di lunghezza minima contenuta nel testo e': ");
    puts(min);

    return 0;
}



void lung_min(char*string, int dim, char*min)
{
    int i=0;

    for(i=0;i<dim;i++)
        min[i]=' ';         /*Senza nel array min c'erano simboli a caso. Cos' invece tutto l'array min è vuoto finchè non gli inserisco qualche stringa.*/

    Strcpy(min,string);     /*Copio nel array 'min' la prima parola del array 'string' ovvero: Pappagallo.*/
    printf("%d\n",Strlen(min));
    puts(min);


    for(i=0;i<dim;i++){
        /*printf("\nDIM= %d\n", i);*/
        if(string[i] == ' '){       /*1) Quando incontro uno spazio nell'array string*/
            printf("%c",string[i]); /*Questo printf posso anche non inserirlo. Lo metto solo per capire il processo passo passo cosa stampa.*/

            if(Strlen(&string[i+1]) < Strlen(min)){ /*2) Calcolo la lunghezza della parola, del array 'string', che inizia alla posizione i+1 e che termina finquando non vi è uno spazio o il terminatore; e la confronto con la lunghezza della parola contenuta nel array  'min' (al primo ciclo l'array 'min' contiene la parola: "Pappagallo").*/
                printf("\n%d %d\n",Strlen(&string[i+1]),Strlen(min));
                Strcpy(min,&string[i+1]); /*3) Se la lunghezza della parola dellì array 'string' è minore della lunghezza della parola del array 'min', allora copio la parola del array 'string' nel array 'min'.*/
                puts(min);                /*4) L'array 'min' ora contiene la parola di lunghezza minore dell'array 'string'. Si procede con i prossimi cicli per vedere se ci sono altre parole del array 'string' di lunghezza ancora più piccola rispetto alla parola copiata nel array 'min'.*/
            }
        }
    }
}




int Strlen(char*s)
{
    int i=0,cont=0;


    while(s[i]!= ' ' && s[i]!= '\0'){ /*Per calcolare la lunghezza di una parola del array 'stringa' prendo come riferimento, per far capire dove interrompe il conteggio, lo spazio (' ') oppure il terminatore nel caso arrivi a calcolare l'ultima parola del array 'stringa'.*/
        cont++;                       /*Ogni volta che incontro un nuovo carattere della parola di cui sto calcolando la lunghezza, incremento 'cont' finquando la parola non termina. La parola termina quando vi è uno spazio oppure perchè è l'ultima parola della stringa (quindi vi è il terminatore: '\0').*/
        i++;
    }

    return cont;
}




void Strcpy(char*s, char*t)
{
    int i=0;

    while(*(t+i)!=' ' && *(t+i)!='\0'){     /*Il carattere della stringa deve essere diverso sia da spazio (' ') e sia dal carattere terminatore ('\0). Se è uguale allo spazio o al terminatore termina il ciclo while.*/
        s[i]= t[i];                         /*Termina il ciclo perchè la tabella di verità del AND restituisce VERO solo quando entrambi le proposizioni sono vere, se una delle due è falsa oppure entrambe sono false, viene restituito FALSO.*/
        i++;
    }

    while(s[i] != '\0'){    /*Finito il ciclo for, partendo dal valore 'i' finale prodotto dal for, questo while serve per pulire l'array 'min' dei caratteri in eccesso dei Strcpy precedenti.*/
        s[i]= ' ';          /*Esempio: l'array 'min' conteneva la parola: "Pappagallo". Però è stata trovata una parola di lunghezza minore che deve essere copiata nel array 'min', è la nuova parola è: "al".*/
        i++;                /*Senza questo while, facendo la Strcpy di "al" nel array 'min' (che contiene la parola: "Pappagallo") il risultato sarebbe che ora nel array 'min' vi è la parola: "alppagallo".*/
    }                       /*Invece con questo while, viene copiato la parola "al" e poi puliti tutti i caratteri della parola precedente ("ppagallo") conenuta nel array 'min'.*/
}                           /*Fatto questo, stampando l'array 'min' ci verrà mostrato la stringa: "al".*/

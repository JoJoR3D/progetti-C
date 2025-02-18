#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct persona{
    char nome[10];
    char cognome[10];
};

typedef struct persona id;

struct partecipante{
    id utente;
    int codice;
};

typedef struct partecipante Participant;


/*void ord(Participant*utenti, int n);*/
/*void ord(Participant*utenti, int n);*/
void ord_sel_max_s(char*[], int);

int max_val_ind_s(char*[], int);

void scambiare_s(char**, char**);




int main()
{
    int i;
    Participant*users[2]={"Petrollo","Aiello"};
    /*char*cose[]={"Petrollo","Aiello"};*/
    int n=2;

    /*for(i=0;i<n;i++){
        scanf("%s",&users[i]->utente->nome);
        scanf("%s",&users[i]->utente->cognome);
        scanf("%d",&users[i]->codice);
    }*/

    /*for (i = 0; i < n; i++) {
        scanf("%s", users[i]->utente.nome);
        scanf("%s", users[i]->utente.cognome);
    }*/

    /*ord_sel_max_s(cose,n);*/
    ord_sel_max_s(&users[0]->utente.cognome, n);

    for (i = 0; i < n; i++)
        printf("%s %s\n", users[i]->utente.nome, users[i]->utente.cognome);

    /*for (i = 0; i < n; i++)
        printf("%s\n", cose[i]);*/

    return 0;
}


void ord_sel_max_s(char*stringhe[], int n)
{
    int i;

    for(i=n-1; i>0; i--){
        scambiare_s(&stringhe[i], &stringhe[max_val_ind_s(&stringhe[0], i+1)]);
    }
}


int max_val_ind_s(char*stringhe[], int n)
{
    int i, i_max;
    i_max= 0;

    for(i=1; i<n; i++){
        if(strcmp(stringhe[i], stringhe[i_max])>0)
            i_max= i;
    }
    return i_max;
}


void scambiare_s(char**s1, char**s2) /* ' **s1, **s2 ' � una variabile che contiene un indirizzo di un puntatore. Infatti non abbiamo necessit� di scambiare le stringhe, basta scambiare gli indirizzi delle stringhe, quindi scambia i puntatori.*/
{
    char *temp; /*E' un puntatore che punta a un array di stringa*/

    temp= *s2;  /*Assegno all'array di stringa temp l'indirizzo dell'array di strigna s2*/
    *s2= *s1;   /*Se scrivessi **s2 starei passando il dato contneuto all'indirizzo di memoria dell'array di stringa s2. Quindi scrivendo *s2 significa che il compilatore andr� all'indirizzo di memoria di s2 e assegner� a temp il suo indirizzo di memoria nel quale � presenta la stringa.*/
    *s1= temp;  /*Ricapitolando: *s1 � un indirizzo; **s1 � un dato*/
}

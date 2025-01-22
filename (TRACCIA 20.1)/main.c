#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct persona {
    char* nome;
    char* cognome;
};

typedef struct persona id;

struct partecipante {
    id* utente;
    int codice;
};

typedef struct partecipante Participant;


/*void ord(Participant*utenti, int n);*/
void scambiare_s(char* s1, char* s2);
int max_val_ind_s(char stringhe[], int n);
void ord_sel_max_s(char stringhe[], int n);




int main()
{
    int i, n = 2;
    id*users;
    Participant a[n];

    a[0].utente->nome= "Pippo";
    a[0].utente->cognome= "Barone";
    a[1].utente->nome= "Carlo";
    a[1].utente->cognome= "Arone";

    a->codice= 122;
    a->codice= 233;


    printf("%s %d\n",a[0].utente->nome, a->codice);


    /*for(i=0;i<n;i++){
        scanf("%s",users->utente->nome);
        scanf("%s",users->utente->cognome);
        scanf("%d",&users->codice);
    }*/

    /*for (i = 0; i < n; i++) {
        scanf("%s", &users[i].utente->nome);
        scanf("%s", &users[i].utente->cognome);
    }*/


    /*ord_sel_max_s(users->utente->cognome, n);


    for(i=0;i<n;i++)
        printf("%s %s\n",users[i].utente->nome, users[i].utente->cognome);
*/
    return 0;
}




void ord_sel_max_s(char stringhe[], int n)
{
    int i;

    for (i = n - 1; i > 0; i--) {
        scambiare_s(&stringhe[i], &stringhe[max_val_ind_s(&stringhe[0], i + 1)]);
    }
}




int max_val_ind_s(char stringhe[], int n)
{
    int i, i_max;
    i_max = 0;

    for (i = 1; i < n; i++) {
        if (strcmp(&stringhe[i], &stringhe[i_max]) > 0)
            i_max = i;
    }
    return i_max;
}




void scambiare_s(char* s1, char* s2) /* ' **s1, **s2 ' è una variabile che contiene un indirizzo di un puntatore. Infatti non abbiamo necessità di scambiare le stringhe, basta scambiare gli indirizzi delle stringhe, quindi scambia i puntatori.*/
{
    char temp; /*E' un puntatore che punta a un array di stringa*/

    temp = *s2;  /*Assegno all'array di stringa temp l'indirizzo dell'array di strigna s2*/
    *s2 = *s1;   /*Se scrivessi **s2 starei passando il dato contneuto all'indirizzo di memoria dell'array di stringa s2. Quindi scrivendo *s2 significa che il compilatore andrà all'indirizzo di memoria di s2 e assegnerà a temp il suo indirizzo di memoria nel quale è presenta la stringa.*/
    *s1 = temp;  /*Ricapitolando: *s1 è un indirizzo; **s1 è un dato*/
}

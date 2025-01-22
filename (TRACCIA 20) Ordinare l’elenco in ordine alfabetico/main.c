#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct persona{
    char*nome;
    char*cognome;
};

typedef struct persona id;

struct partecipante{
    id*utente;
    int codice;
};

typedef struct partecipante Participant;


void ord(Participant*utenti, int n);



int main()
{
    int i,n=2;
    id coso[n];
    Participant users[n];

    for(i=0;i<n;i++){
        scanf("%s",&users[i].utente->nome);
        scanf("%s",&users[i].utente->cognome);
        scanf("%d",&users[i].codice);
    }


    /*Participant users[2]= {{{"Giuseppe"},{"Marconi"},122},{{{"Luca"},{"Facchioni"},345}}};*/
    /*id Utenti[2]={{"Giuseppe","Marconi"},{"Luca","Facchioni"}};*/
    /*Participant users[2]= {{"Giuseppe","Marconi",122},{"Luca","Facchioni",345}};*/
    /*id*//*Participant users[2]= {{coso.nome="Giuseppe",coso.cognome="Marconi",122},{coso.nome="Luca",coso.cognome="Facchioni",345}};
    Participant Users[2];*/
    /*Participant*punt;
    printf("Indirizzo del puntatore punt %d\nIndirizzo della variabile punt %d\n",*punt,punt);
    punt= &users[0];
    printf("Indirizzo base del array users %d %d\n",*punt,&users[0]);*/

    /*scanf("%s",&users.nome);
    scanf("%s",&users.cognome);*/

    /*for(i=0;i<n;i++){
        scanf("%s",&users[i].nome);
        scanf("%s",&users[i].cognome);
        scanf("%d",&users[i].codice);
    }*/

    for(i=0;i<n;i++){
        printf("%s %s %d\n",users[i].utente->nome,users[i].utente->cognome,users[i].codice);
    }

    /*for(i=0;i<2;i++)
        printf("%s %d\n",*//* *(users+i)->utente */ /*(punt+i)->utente,(punt+i)->codice);*/ /* O *(punt+i)->utente (indirizzo del puntatore punt) oppure
                                                                                            (punt+i)->utente (Indirizzo della variabile punt) è la stessa cosa,
                                                                                             entrambi contangono lo stesso contenuto.
                                                                                       */

    /*for(i=0;i<2;i++)
        printf("%s %s\n",&(punt+i)->utente->nome, &(punt+i)->utente->cognome);*/

    /*ord(users,n);

    for(i=0;i<2;i++)
        printf("%s %d\n", (punt+i)->utente,(punt+i)->codice);*/

    return 0;
}



void ord(Participant*utenti, int n)
{
    int i;
    /*printf("%s",(utenti+i)->utente->cognome);*/
    for(i=0;i<1;i++){
        /*if((utenti+i)->utente->cognome < (utenti+i+1)->utente->cognome){
            printf("%s",(utenti+i)->utente->cognome);
            swap((utenti+i)->utente->nome,(utenti+i+1)->utente->nome);
            swap((utenti+i)->utente->cognome,(utenti+i+1)->utente->cognome);
        }*/
        if(strcmp((utenti+i)->utente->cognome,(utenti+i+1)->utente->cognome)<0){
            strcpy((utenti+i)->utente->nome,(utenti+i+1)->utente->nome);
        }
    }
}

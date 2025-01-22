#include <stdio.h>
#include <stdlib.h>


struct studente{
    char nome[10];
    char cognome[10];
    int voto[5];
    float MEDIA;
};


typedef struct studente Studente;



void Media(Studente[], int, int, float*);
float max_media(float[], int);






int main()
{
    /*Studente lista[3]={{"Giuseppe","Rossi",{27,20,14,18,30},0.0},
                        {"Giancarlo","Magalli",{29,28,20,21,24},0.0},
                        {"Anna","Capelli",{25,19,30,29,23},0.0}
    };*/

    Studente lista[3];

    int n=3;   /*Numero degli studenti*/
    int m=5;   /*Numero dei voti*/
    int i,j;

    for(i=0;i<n;i++){
        printf("Nome: ");
        gets(lista[i].nome);
        printf("Cognome: ");
        gets(lista[i].cognome);
            for(j=0;j<m;j++){
                printf("\n%d-Voto: ", j);
                scanf("%d", &lista[i].voto[j]);
        }
        printf("\n");
        fflush(stdin);    /*Concluso il ciclo 'j' pulisco il buffer per evitare errori al ciclo 'i' successivo. Senza, al secondo ciclo, mi da problemi nel inserire il nome e cognome*/
    }




    float media[3];

    Media(lista,n,m,media);    /*L'indirizzo base media lo potevo scrivere anche come &media[0] */ /*La function ritorna tutte le medie*/

    printf("\n");

    for(i=0;i<n;i++)
        printf("Media: %.1f, ", media[i]);   /*Stampa la media di tutti e tre gli studenti*/

    printf("\n\n\n");




    for(i=0;i<n;i++){
        printf("Nome: %s, Cognome: %s\n\n", lista[i].nome,  lista[i].cognome);
        printf("Voti: ");
            for(j=0;j<m;j++){
                printf("%d ", lista[i].voto[j]);    /* Con i=0 Stampa i voti da j=0 a j=4 di Giuseppe; Con i=1 Stampa i voti da j=0 a j=4 di Giancarlo; Con i=2 Stampa i voti da j=0 a j=4 di Anna*/
            }
            printf("\nMedia: %.1f", media[i]);
            printf("\n\n\n");
    }




    float M_media= max_media(media,n);          /*La function ritorna la media migliore*/

    printf("Lo studente o gli studenti con la media voti migliore sono:\n");
    for(i=0;i<n;i++){
        if(M_media==media[i])                   /*Poichè nel array media[i] le medie sono in ordine di studente del array lista (es.:la prima media corrsipsone al primo studente, e così via), Se ad esempio la media massima M_media è == a media[2] vuol dire che lo studente con la media massima è lo studente che si trova alla 3 riga del array lista.*/
            printf("%s, %s, %.1f\n", lista[i].nome,  lista[i].cognome, media[i]);    /*Altro esempio: Se la media massima M_media è == a media[0] vuol dire che lo studente con la media massima è lo studente che si trova alla 1 riga del array lista.*/
    }

    printf("\n");
    return 0;
}








void Media(Studente lista[], int n, int m, float*media)
{
    int i,j;
    float somma=0;

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            somma= somma + lista[i].voto[j];
        }
        media[i]= somma/m;        /* media[i] (che è un indirizzo) indica la posizione del array dove andare a stampare la media, e lo posso scrivere anche come *(media++) */
        somma=0;
    }
}



float max_media(float media[], int n)  /*Ritorna la media migliore*/
{
    int i;
    float max= media[0];

    for(i=1;i<n;i++){
        if(media[i] > max)
            max= media[i];
    }
    return max;
}


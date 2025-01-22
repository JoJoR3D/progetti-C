#include <stdio.h>
#include <stdlib.h>


struct studente{
    char nome[10];
    char cognome[10];
    int voto[1];
    float MEDIA;
};


typedef struct studente Studente;



float max_media(Studente[], int, int);





int main()
{
    Studente lista[3];

    int n=3;   /*Numero degli studenti*/
    int m=1;   /*Numero dei voti*/
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
        fflush(stdin);    /*Concluso il ciclo 'j' pulisco il buffer per evitare errori al ciclo 'i' successivo*/
    }

    printf("\n\n");



    for(i=0;i<n;i++){
        printf("Nome: %s, Cognome: %s\n\n", lista[i].nome,  lista[i].cognome);
        printf("Voto: ");
            for(j=0;j<m;j++){
                printf("%d ", lista[i].voto[j]);    /* Con i=0 Stampa il voto del primo studente; Con i=1 Stampa il voto del secondo studente, e così via.*/
            }
            printf("\n\n\n");
    }




    float M_media= max_media(lista,n,m);          /*La function ritorna la media migliore*/

    printf("Lo studente o gli studenti con il voto migliore sono:\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(M_media==lista[i].voto[j])                   /*Se il massimo ritornato da M_media è == al voto dello studente, mi stampa lo studente o gli studenti corrispondenti a quel voto*/
                printf("%s, %s, %d\n", lista[i].nome,  lista[i].cognome, lista[i].voto[j]);
            }
    }

    printf("\n");
    return 0;
}









float max_media(Studente lista[], int n, int m)  /*Ritorna il voto massimo tra i voti degli studenti*/
{
    int i,j;
    int max= lista[0].voto[0];

    for(i=1;i<n;i++){
        for(j=0;j<m;j++){
            if(lista[i].voto[j] > max)
                max= lista[i].voto[j];
        }
    }
    return max;
}

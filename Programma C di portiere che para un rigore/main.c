#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct calcio{
    char boll;
    char portiere;
};

typedef struct calcio Rigore;


int main()
{
    int nx, ny, nz, nc, i, j;


    Rigore x[5][5]={{' ',' ',' ',' ',' '},
                   {' ',' ',' ',' ',' '},
                   {' ',' ',' ',' ',' '}};



    srand(time(NULL));


    /*while(&x[nx][ny] != &x[nz][nc]){*/   /*NON POSSO USARE IL WHILE PERCHè AD OGNI CICLO, ANCHE SE PULISCO CON LE ISTRUZIONI DI SOTTO LE CASELLE OCCUPATE IN QUESTO CICLO DALLA PALLA E DAL PORTIERE,
                                             AL PROSSIMO CICLO NELLA STAMPA COMPARE SEMPRE IL SIMBOLO DI UNA CASA, E AD OGNI CICLO AUMENTANO QUESTI SIMBOLI.*/
    Rigore posizione;

    posizione.portiere= 'x';

    nx= rand()%5;
    ny= rand()%5;

    x[nx][ny]= posizione;


    printf("\n\nPosizione Portiere\n");
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            printf("%c ", x[i][j].portiere);
            }
        printf("\n");
    }



    Rigore booll;

    booll.boll= 'y';

    nz= rand()%5;
    nc= rand()%5;

    x[nz][nc]= booll;


    printf("\n\nPosizione Pallone\n");
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            printf("%c ", x[i][j].boll);

            }
        printf("\n");
    }


    /*printf("\n%c\n%c\n", posizione.portiere, booll.boll);*/

    printf("\nCoordinate Portiere: %d %d,   Coordinate Pallone: %d %d\n", nx,ny,nz,nc);

    printf("\n");

    if(&x[nx][ny] == &x[nz][nc])
        printf("Parato!");
    else
        printf("Goaaaaalllll");


    /*
    posizione.portiere= ' ';      Queste istruzioni servono per azzerare il contenuto di quelle posizioni dell'array al prossimo ciclo while
    booll.boll= ' ';
    x[nx][ny]= posizione;
    x[nz][nc]= booll;
    }*/

    return 0;
}

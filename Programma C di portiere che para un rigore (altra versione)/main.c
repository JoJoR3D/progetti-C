#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    int nx, ny, nz, nc, i, j;


    char x[5][5]={{' ',' ',' ',' ',' '},
                   {' ',' ',' ',' ',' '},
                   {' ',' ',' ',' ',' '}};



    srand(time(NULL));


    while(&x[nx][ny] != &x[nz][nc]){

        char portiere= 'x';

        nx= rand()%5;
        ny= rand()%5;

        x[nx][ny]= portiere;



        char boll= 'y';

        nz= rand()%5;
        nc= rand()%5;

        x[nz][nc]= boll;


        if(x[nx][ny] == x[nz][nc]){  /*Se le due coordinate sono uguali, per indicare graficamente che il rigore è stato parato, stampa il carattere 'o', invece di 'x' o 'y'*/
            x[nx][ny]= 'o';
        }


        printf("\n\nPOSIZIONE Portiere - Pallone\n");
        for(i=0;i<5;i++){
            for(j=0;j<5;j++){
                printf("%c ", x[i][j]);
                }
            printf("\n");
        }



        /*printf("\n%c\n%c\n", posizione.portiere, booll.boll);*/

        printf("\nCoordinate Portiere: %d %d,   Coordinate Pallone: %d %d\n", nx,ny,nz,nc);

        printf("\n");

        if(x[nx][ny] == x[nz][nc]) /*Ad esempio x[nx][ny]= x[2][1]= 'x'; e se poi dopo x[nz][nc]= x[2][1]= 'y'; ciò vuol dire che alla posizione con indice 2-1 troviamo sempre 'y', quindi è uguale e stampa: Parato!*/
            printf("Parato!");
        else
            printf("Goaaaaalllll"); /*Invece se x[nx][ny]= x[2][1]= 'x'; e se poi x[nx][ny]= x[3][3]= 'y'; sono due coordinate della matrice diverse dove la prima coordinata contiene 'x' e la seconda contiene 'y', quindi stampa: Goal*/



        x[nx][ny]= ' ';   /*Queste istruzioni servono per azzerare il contenuto di quelle posizioni dell'array al prossimo ciclo while*/
        x[nz][nc]= ' ';
        printf("\n\n");
    }

    return 0;
}

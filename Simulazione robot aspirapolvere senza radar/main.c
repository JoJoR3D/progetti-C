#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char a[20][20]= {{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*','*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
                    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*','*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
                    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*','*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
                    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*','*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
                    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*','*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
                    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*','*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
                    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*','*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
                    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*','*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
                    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*','*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
                    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*','*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
                    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*','*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
                    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*','*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
                    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*','*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
                    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*','*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
                    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*','*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
                    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*','*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
                    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*','*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
                    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*','*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
                    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*','*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
                    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*','*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}};

    int robotrg=0, robotcl=0, i, j /*acc=0*/;
    char chiave= 'o';

    srand(time(NULL));

    robotrg= rand()%20;
    robotcl= rand()%20;


    printf("\nPrima porzione della stanza\n\n");
    for(i=0;i<20;i++){
        a[0][0]='S';                /*Stazione di ricarica*/
        a[robotrg][robotcl]= 'o';   /*Il robot inizia a pulire partendo da un punto casuale della casa*/
        for(j=0;j<20;j++){
                printf("%c ",a[i][j]);}
        printf("\n");
    }

    printf("\n");
    while(a[0][0] != 'Z'){
        for(i=0;i<20;i++){
            a[0][0]='S';
            a[robotrg][robotcl]= 'o';      /*Partendo da quel punto inizia a pulire avanzando sulle righe e colonne successivie (indica che ha pulito quel punto con 'o'*/
            for(j=0;j<20;j++){
                printf("%c ",a[i][j]);}
            printf("\n");
        }
    printf("\n");

    robotcl++;

    if(a[19][19]=='o'){                 /*Arriva alla fine della stanza e lo indica facendo diventare la stazione 'Z'*/
        a[0][0]='Z';
    for(i=0;i<20;i++){
        for(j=0;j<20;j++){
                printf("%c ",a[i][j]);}
        printf("\n");
        }
    }

    }

    printf("\n\n\n");

    for(i=0;i<20;i++){                  /*Arrivato alla fine della stanza trova il punto da dove ha iniziato a pulire e da lì pulisce da quel punto fino alla stazione di ricarica*/
        for(j=0;j<20;j++){
            if(a[i][j]==chiave){
                robotrg=i;
                robotcl=j-1;
                }
        }
    }

    printf("\n");

    /*for(i=0;i<20;i++){
        for(j=0;j<20;j++){
            printf("%c ",a[i][j]);
            }
        printf("\n");
    }
*/

    for(i=robotrg;i>=0;i--){        /*Indica con 'o' i punti che sta pulendo e una volta arrivato alla stazione (lo indica con 'F'), termina la pulizia e vuol dire che ha pulito tutta la stanza*/
        for(j=robotcl;j>=0;j--){
            if(i==0 && j==0)
                a[i][j]='F';
            else
                a[i][j]='o';
                }
                robotcl=19;
    }

    printf("Seconda porzione della stanza\n\n");
    for(i=0;i<20;i++){
        for(j=0;j<20;j++){
            printf("%c ",a[i][j]);
            }
        printf("\n");
    }


    /*for(i=0;i<20;i++){
        for(j=0;j<20;j++){
            if(i==0 && j==0)
                printf("%c ",a[0][0]= 'c');
            if(a[i][j]!='o' && a[i][j]!='c')
                printf("%c ",a[i][j]= 'o');
            else if(a[i][j]=='o')
                printf("%c ",a[i][j]);
        }
        printf("\n");
    }*/


    return 0;
}



/*VEDERE

    printf("\n");
    while(a[0][0] != 'Z'){
        for(i=0;i<20;i++){
            acc=i;
            a[0][0]='S';
            a[robotrg][robotcl]= 'o';
            for(j=0;j<20;j++){
                if(j<19){
                    printf("%c ",a[i][j]);}
                    else if(j==19 && a[i][j]=='o'){
                        printf("%c ",a[i][j]);
                        printf("\n");
                        i++;
                        for(i=i;i<acc+2;i++){
                            for(j=19;j>=0;j--){
                                printf("%c ",a[i][j]);
                            }
                        }
                        j=20;
                    }
            }i++;
            printf("\n");
        }
    printf("\n");*/










/*
printf("\n");
    while(a[0][0] != 'Z'){
        for(i=0;i<20;i++){
            a[0][0]='S';
            a[robotrg][robotcl]= 'o';*/    /*Partendo da quel punto inizia a pulire avanzando sulle righe e colonne successivie (indica che ha pulito quel punto con 'o'*/
            /*for(j=0;j<20;j++){
                printf("%c ",a[i][j]);}
            printf("\n");
        }
    printf("\n");
*/

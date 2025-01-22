#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>     /*Libreria che contiene la function sleep()*/

void score(int*);


int main()
{
    int risultato;

    score(&risultato);      /*Chiamata della function score*/

    if(risultato == 0)
        printf("\nIl vincitore e' player_one!\n");
    else if(risultato == 1)
        printf("\nIl vincitore e' player_two!\n");
    else
        printf("\nPareggio!\n");

    return 0;
}



void score(int*dado)
{
    int i,j=0,P_1,P_2,cont_1=0,cont_2=0;

    srand(time(NULL));

    while(j<10){

        P_1= 5+rand()%11;   /*Genera numeri psudocasuali da 5 a 15. Se ad esempio viene generato il num. 10, 10%11= 10, 5+10= 15*/
        P_2= 5+rand()%11;   /*Se ad esempio viene generato il num. 11, 11%11= 0, 5+0= 5*/


        printf("Il player_one sta lanciando il dado");
        for(i=0;i<3;i++){
            printf(".");
            sleep(1);       /*Prima di stampare il '.' il programma si interrompe per 1 secondo e poi riparte per stampare il prossimo '.' Stampa tre punti.*/
        }
        printf("%d\n",P_1);

        printf("Il player_two sta lanciando il dado");
        for(i=0;i<3;i++){
            printf(".");
            sleep(1);
        }
        printf("%d\n",P_2);


        if(P_1 > P_2){
            printf("\nQuesto %d round se lo aggiudica player_one\n\n\n",j+1);
            cont_1++;
        }
        else if(P_1 < P_2){
            printf("\nQuesto %d round se lo aggiudica player_two\n\n\n",j+1);
            cont_2++;
        }
        else if(P_1 == P_2){
            printf("\nQuesto %d round termina in parita'\n\n\n",j+1);
            cont_1++;
            cont_2++;
        }

        j++;
    }


    if(cont_1 > cont_2)
        *dado= 0;

    else if(cont_1 < cont_2)
        *dado= 1;

    else if(cont_1 == cont_2)
        *dado= -1;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int find(char, char[][50], int);
int find_c(char, char[]);
int confronto(char[], char[][50], int);


/*Problema:

  1) Se ci sono più parole che iniziano con la stessa lettera, prenderà sempre la prima parola che inizia con quella lettera nel array di stringhe. RISOLTO!!!!

  2) Indicare il carattere iniziale della parola che si vuole generare. FATTO!!!!

  3) Completare l'else per generare una parola a caso.

  4) PROBLEMA CON LA PAROLA: "AMICIZIA", LO FA ANCHE CON "ANSIA" e altra parole. Penso di aver risolto ponendo al for interno (riga 84) la condizione di j<=0
     questo perchè non mi serve che scorra la parola, poiche lo farà lo strncmp.
*/


int main()
{
    char stringhe[][50]={"cassapanca",
                         "banana",
                         "pizzaiolo",
                         "fornello",
                         "fisarmonica",
                         "barchetta",
                         "acqua",
                         "amici",
                         "amicizia",
                         "amore",
                         "ansia",
                         "autobus",
                         "bacio",
                         "camera",
                         "cane",
                         "cellulare",
                         "computer"
                         "cravatta",
                         "macchina",
                         "mamma",
                         "mangiare",
                         "mare",
                         "mattina",
                         "papa",
                         "pasta",
                         "peccato",
                         "sonno",
                         "sorella",
                         "studiare",
                         "telefono",
                         "nonno",
                         "nonna"
                        };

    char alfabeto[]={'a','b','c','d','e','f','g','h','i','l','m','n','o','p','q','r','s','t','u','v','z'};
    char parola[50];
    int ricorrenza[strlen(alfabeto)];

    int i=0,j,vf,risposta,casuale,verificato=0,repeat=1,cont=0,indice_i=0,indice_j=0,n_caratteri=0,lunghezza=-1,blocco,ritenta=-1,pos,dim,b=0,flag=0;
    char carattere;

    for(j=0;j<50;j++)
        parola[j]= ' ';

    for(j=0;j<strlen(alfabeto);j++)
        ricorrenza[j]=-1;



    printf("Se si desidera generare una parola reale premere 1 altrimenti 0: ");
    scanf("%d",&vf);



    if(vf == 1){
        printf("\nSi desidera indicare l'inizale della parola? 1 per SI e 0 per NO: ");
        scanf("%d",&risposta);
        if(risposta == 1){
            while(ritenta == -1){
                fflush(stdin);
                printf("\nInserire carattere: ");
                scanf("%c",&carattere);
                ritenta=find(carattere,stringhe,32);
            }
            if(ritenta > -1){
                pos=find_c(carattere,alfabeto);
            }
        }
    }

    srand(time(NULL));
    if(risposta == 0){
        casuale= rand()%21;         /*Genera il primo carattere casuale.*/
        ricorrenza[i]= casuale;
    }
    else{
        printf("\n\nRITENTA: %d, %c\n\n",ritenta,alfabeto[pos]);
        casuale= pos;
        ricorrenza[i]= casuale;
    }
    printf("Carattere casuale: %c\n",alfabeto[casuale]);





    if(vf == 1){
        while(verificato == 0){
            parola[n_caratteri]= alfabeto[casuale];
            blocco=0;

            repeat=1;
            for(i=0;i<32;i++){                                                      /*32 è il numero di parole presenti nel array di stringhe*/
                for(j=0;j<=0;j++){
                    if(strncmp(&stringhe[i][j],&parola[0],n_caratteri+1)==0){       /*Compara la porzione di parola fin'ora trovata con la porzione di parola delle stringhe*/
                        indice_i=i;
                        indice_j=j;
                        lunghezza= strlen(&stringhe[indice_i][0]);
                        n_caratteri++;
                        blocco=1;

                        for(j=0;j<strlen(alfabeto);j++) /*Se il carattere è giusto, pone a -1 l'array ricorrenza e passa a trovare il prossimo carattere*/
                            ricorrenza[j]=-1;

                        printf("INDICE_i %d, INDICE_j %d\n",indice_i,indice_j);
                        printf("\nStringa: %s, Parola: %s, %d, Numeri caratteri: %d\n",&stringhe[indice_i][indice_j],&parola[0],i,n_caratteri);
                    }
                }

                if(blocco==1)
                    break;
            }

            while(repeat == 1){
                casuale= rand()%21;
                printf("Carattere casuale: %c\n",alfabeto[casuale]);
                for(j=0;j<strlen(alfabeto);j++){    /*Serve a controllare che non venga estratto sempre lo stesso carattere*/
                    if(casuale == ricorrenza[j])
                        cont++;
                }
                if(cont == 0){
                    for(j=0;j<strlen(alfabeto);j++){
                        if(ricorrenza[j] == -1){    /*Salva il carattere estratto nell'array ricorrenza*/
                            ricorrenza[j]= casuale;
                            break;
                        }
                    }
                    repeat=0;
                }
                else
                    cont=0;
            }


            for(j=0;j<strlen(alfabeto);j++)
                printf("%d: %d\n",j+1,ricorrenza[j]);


            if(lunghezza == n_caratteri){           /*Una volta trovata la parola, pongo verificato==1 per interrompere il ciclo*/
                verificato=1;
            }

            printf("VERIFICATO: %d\n",verificato);
        }
    }


    else{
        printf("\nIndicare la dimenzione della parola: ");
        scanf("%d",&dim);
        while(flag == 0){
            while(i < dim){
                parola[i]= alfabeto[casuale];
                i++;
                /*printf("CASUALE: %d: %c\n",casuale,alfabeto[casuale]);*/
                casuale= rand()%21;

            /*while((casuale == 0 || casuale == 4 || casuale == 8 || casuale == 12 || casuale == 18) && b == 0){
                casuale= rand()%21;
                printf("1\n");
                if(casuale == 0 || casuale == 4 || casuale == 8 || casuale == 12 || casuale == 18)
                    b=1;
            }
            while((casuale != 0 || casuale != 4 || casuale != 8 || casuale != 12 || casuale != 18) && b == 0){
                casuale= rand()%21;
                printf("2\n");
                if(casuale != 0 || casuale != 4 || casuale != 8 || casuale != 12 || casuale != 18){
                    b=1;
                    printf("B %d\n",b);}
            }
            b=0;*/
            }
            parola[i]= '\0';    /*Pongo il carattere terminatore al termine della parola generata casualmente, altrimenti strlen mi ritornerebbe sempre come lunghezza la dimensione dell'array.*/
            flag=confronto(parola,stringhe,32);
            if(flag == 0)
                i=0;
        }
    }

    puts(parola);
}



/*
    Questa function ha il compito di verificare che il carattere inserito dall'utente corrisponda almeno ad il carattere iniziale di una parola presente
    nell'arry stringhe.
*/


int find(char c, char s[][50], int n)
{
    int i,j,blocco=-1;

    for(i=0;i<n;i++){
        for(j=0;j<=0;j++){
            printf("\n\nSSSSSSSSSSSSSSSSSS: %s %d %d\n\n\n",&s[i][j],i,j);
            if(s[i][j] == c)
                blocco=i;
        }
        if(blocco > -1)
            break;
    }

    return blocco;
}



/*
    Se il carattere inserito dall'utente corrsiponde almeno ad un carattere iniziale di una parola dell'array stringhe (function precedente),
    questa function ha il compito di ritornare la posizione nell'array alfabeto del carattere inserito dall'utente, in modo da assegnare all'array parola il caratttere
    scelto dall'utente.
*/

int find_c(char c, char a[])
{
    int i,blocco=-1;
    int n=strlen(a);

    for(i=0;i<n;i++){
        if(a[i] == c){
            blocco=i;
            break;
        }
    }

    return blocco;
}




/*
    Il compito di questa function è quello di controllare che la parola generata casualmente abbia almeno un tot. di caratteri uguali a una parola
    dell'array stringhe di uguale lunghezza.

*/

int confronto(char parola[], char stringhe[][50], int n)
{
    int i,j,cont=0;

    for(i=0;i<n;i++){
        for(j=0;parola[j] != '\0';j++){
            /*printf("Stringhe: %d Parola: %d\n",strlen(&stringhe[i][0]),strlen(parola));*/
            if(strlen(&stringhe[i][0]) == strlen(parola)){
                if(stringhe[i][j] == parola[j])
                    cont++;
            }
        }
        if(strlen(parola) <=4){             /*La parola generata casualmente ha una lunghezza <=4*/
            if(cont >= 3){                  /*La parola generata casualmente deve avere almeno 3 caratteri uguali a una parola dell'array stringhe di uguale lunghezza.*/
                puts(&stringhe[i][0]);
                break;
            }
        }
        else if(strlen(parola) > 4 && strlen(parola) <= 5){
            if(cont >= 4){
                puts(&stringhe[i][0]);
                break;
            }
        }
        else if(strlen(parola) > 5){
            if(cont >= 5){
                puts(&stringhe[i][0]);
                break;
            }
        }
        cont=0;
    }

    return cont;
}



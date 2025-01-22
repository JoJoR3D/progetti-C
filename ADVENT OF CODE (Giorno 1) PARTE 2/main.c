#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char*s[]= {"one","two","three","four","five","six","seven","eight","nine"};
    char*numb[]= {"1","2","3","4","5","6","7","8","9"};
    char a[4];
    char*v;
    char*ptr;
    char t[100];
    int i=0,j=0,indice=0,cont=0,l,blocco=0,index,rit,contatore=0,ingresso=0,ricorda,numero=0;

    FILE*fp;

    fp= fopen("input.txt","r");

    if(fp == NULL){
        printf("Si e' verificato un'errore\n");
        exit(1);
    }

    while(!feof(fp)){
        fscanf(fp,"%s",t);  /*Leggo le stringhe del file uno alla volta fino all'ultima stringa*/
        puts(t);

        while(t[indice] != '\0'){
            l= strlen(&s[i][j]);
            index=i;

            while(j < l/*s[i][j] != '\0'*/){
                /*printf("Elenco: %c, Stringa: %c, Cont: %d, I: %d, J:%d, INDICE: %d, LUNGHEZZA: %d\n",t[indice],s[i][j],cont,i,j,indice,l);*/
                if(t[indice] == s[i][j]){
                    indice++;
                    j++;
                    cont++;
                    if(cont == 1)
                        ricorda=indice-1;
                }
                else if(t[indice] == numb[i][0]){   /*Identifica i caratteri numerici*/
                    index=i;
                    numero=1;
                    indice++;
                    break;
                }
                else if(cont > 0 && t[indice] != s[i][j]){
                    indice= ricorda;
                    if(i < 8)
                        i++;
                    else{           /*Arrivo a confrontare la stringa "nine" ma arrivato al secondo carattere ("i") mi accorgo che non è uguale alla stringa t.*/
                        i=0;
                        indice++;
                    }
                    j=0;
                    cont=0;
                    l= strlen(&s[i][j]);
                    index= i;
                }
                else if(i < 8 && t[indice] != s[i][j]){
                    i++;
                    j=0;
                    cont=0;
                    l= strlen(&s[i][j]);
                    index= i;
                }
                else if(i >= 8){
                    indice++;
                    cont=0;
                    i=0;
                    j=0;
                    index=i;
                    l= strlen(&s[i][j]);
                }

                if(t[indice] == '\0') /*Quando la stringa è terminata ma non ho trovato nessun numero, interrompo il ciclo perchè questa stringa non ha numeri.*/
                    break;
            }



            if((cont == l && blocco == 0) || (numero == 1 && blocco == 0)){
                /*printf("\nARRAY: %s\n",&numb[index][0]);*/
                strcpy(a,&numb[index][0]);
                blocco=1,cont=0,i=0,j=0,numero=0;
            }
            else if((cont == l && blocco == 1) || (numero == 1 && blocco == 1)){
                v= &numb[index][0];
                /*printf("\nPUNTATORE: %s\n",v);*/
                cont=0,i=0,j=0,ingresso++,numero=0;
            }
        }

        if(ingresso == 0 && blocco == 1) /*Quando nella stringa vi è un solo numero. Allora ho bisogno di ripetere quel numero.*/
            v= &a[0];

        if(blocco == 1){
            /*strcat(a,v);*/
            a[1]=*v;
            rit= strtol(a,&ptr,10);
            contatore= contatore + rit;
            printf("\nRIT: %d\n\n",rit);
        }

        i=0,j=0,blocco=0,cont=0,indice=0,ingresso=0;
    }

    printf("\n");

    fclose(fp);

    printf("CONTATORE: %d\n",contatore);

    return 0;
}

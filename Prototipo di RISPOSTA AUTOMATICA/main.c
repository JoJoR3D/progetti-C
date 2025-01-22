#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main()
{
    char prot_question[3][30]=  {
                                "ciao, come stai?",
                                "come va oggi?",
                                "come butta amico?"
                            };

    char prot_answer[3][30]=    {
                                "non c'e' male grazie",
                                "oggi non e' giornata",
                                "potrebbe andare meglio, grazie"
                            };

    int i=0,j=0,k=0,n=3,cont=0,cont_max=0,stringhe=0,pos=0;

    char user_question[50];
    gets(user_question);
    int lunghezza= strlen(user_question);
    /*printf("%d",lunghezza);*/
    printf("\n");


    /*Trova la domanda (prot_question) simile a quella inserita dall'utente (user_question). Ritorna il numero maggiore di caratteri trovati in una singola domanda*/

    while(i < lunghezza || stringhe < n){
        while(prot_question[k][j] != '\0'){
            if(user_question[i] == prot_question[k][j]){
                    /*printf("%c %c\n",user_question[i],prot_question[k][j]);*/
                    cont++;
                    pos=j;
                    break;
            }
            j++;
        }
        /*printf("i:%d j:%d cont:%d\n",i,j,cont);*/
        /*printf("%c\n",user_question[i]);*/
        /*printf("\n");*/

        i++;
        j=pos+1;

        if(i >= lunghezza && stringhe < n){
            if(cont > cont_max)
                cont_max= cont;

            stringhe++;
            k++;
            i=0;
            cont=0;
        }
    }

    /*printf("CONT_MAX %d\n\n", cont_max);*/




    /*Verifica che il numero di caratteri trovati sia almeno >= del totale di una domanda di prot_question. Se è così pone controllo==1.*/

    int l,controllo=0;
    i=0,j=0;
    while(i < n){
        l=strlen(&prot_question[i][j]);
        /*printf("%d\n",l);*/

        if(cont_max >= (l/2)){
            controllo=1;
            break;
        }
        i++;
    }




    /*Se controllo==1 stampa una risposta a caso tra quelle presenti in prot_answer.*/

    printf("\n");
    j=0;
    int num;
    if(controllo == 1){
        srand(time(NULL));
        num= rand()%3;
        /*printf("NUM %d\n",num);*/
        printf("%s\n",&prot_answer[num][j]);
    }
    else
        printf("Non so rispondere a questa tua domanda o affermazione\n");

    return 0;
}

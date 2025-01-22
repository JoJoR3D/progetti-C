#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void occ_lett(char*, char*, int, int, char*);


int main()
{
    char nome[]={"nunzia"};
    char alfab[]={'a','b','c','d','e','f','g','h','i','l','m','n','o','p','q','r','s','t','u','v','z','\0'};

    int dim_nome=strlen(nome),dim_alfab=strlen(alfab),i;
    printf("Lunghezza nome: %d\n",dim_nome);
    char array[dim_alfab];

    occ_lett(&nome[0],alfab,dim_nome,dim_alfab,&array[0]);

    printf("Numero di occorenze delle 21 lettere del alfabeto nel array di caratteri: ");
    for(i=0;i<dim_nome;i++)
        printf("%c",nome[i]);
    printf("\n\n");
    for(i=0;i<dim_alfab;i++)
        printf("%c: %d\n",alfab[i],array[i]);

    return 0;
}



void occ_lett(char*Nome, char*Alfab, int Dim_nome, int Dim_alfab, char*Array)
{
    int i,j,cont=0;


    for(i=0;i<Dim_alfab;i++){
        for(j=0;j<Dim_nome;j++){
            if(Nome[j] == Alfab[i])
                cont++;
        }
        Array[i]= cont;
        cont=0;
    }
}

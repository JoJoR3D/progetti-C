#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void occ_lett(char*, char*, int, int, char*, int*);


int main()
{
    char nome[]={'g','i','a','n','b','a','t','t','i','s','t','a','p','a','o','l','o','\0'};
    char alfab[]={'a','b','c','d','e','f','g','h','i','l','m','n','o','p','q','r','s','t','u','v','z','\0'};

    int dim_nome=strlen(nome),dim_alfab=strlen(alfab),i, num_tot_occorenze;
    printf("Lunghezza nome: %d\n",dim_nome);
    char array[dim_alfab];

    occ_lett(&nome[0],alfab,dim_nome,dim_alfab,&array[0],&num_tot_occorenze);

    printf("Numero di occorenze delle 21 lettere del alfabeto nel array di caratteri: ");
    for(i=0;i<dim_nome;i++)
        printf("%c",nome[i]);
    printf("\n\n");
    for(i=0;i<dim_alfab;i++)
        printf("%c: %d\n",alfab[i],array[i]);

    printf("\n\nNumero TOTALE di occorenze delle lettere del alfabeto nell'array di caratteri: ");
    for(i=0;i<dim_nome;i++)
        printf("%c",nome[i]);
    printf("= %d",num_tot_occorenze);

    return 0;
}



void occ_lett(char*Nome, char*Alfab, int Dim_nome, int Dim_alfab, char*Array, int*num_tot_occ)
{
    int i,j,cont=0;


    for(i=0;i<Dim_alfab;i++){
        for(j=0;j<Dim_nome;j++){
            if(*(Nome+j) == *(Alfab+i))  /* *(Nome+j) oppure Nome[j] è la stessa cosa*/
                cont++;
        }
        Array[i]= cont;
        *num_tot_occ= *num_tot_occ+cont;    /*Mi restituisce quante lettere del alfabeto sono presenti nel array di caratteri*/
        cont=0;
    }
}

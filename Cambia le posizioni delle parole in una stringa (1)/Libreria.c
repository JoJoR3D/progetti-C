void scambio(char*s,char*v);

/*
    Questa function sposta le parole della stringa.
*/


void swap_position(char*s,int n)
{
    int fine=n-1,inizio=0,i,j,cont_1=0,dim_parola1=0,dim_parola2=0,DIM,fin,iniz,cont,ripet_i=0,ripet_j=0,reset=0;
    int divide_in_due= (inizio+fine)/2;     /*Calcolo la metà della stringa oltre la quale nonbisogna arrivare.*/
    char*p= &s[0];


    while(inizio </*=*/ divide_in_due && fine >/*=*/ divide_in_due && fine < n){
        printf("I= %d, F= %d Divide: %d\n\n\n",inizio,fine,divide_in_due);
        i=inizio;
        j=fine;

        if(s[i]== ' ')              /*Incremento 'i' e decremento 'j' per fare in modo che rappresentino l'inizio (i) la fine (j) di una parola.*/
            i++;
        if(s[j]== ' ')
            j--;

        printf("\nPRIMA i:%d j:%d\n\n",i,j);



        while(s[i] != ' '){     /*inizio è l'indice del primo carattere di una parola; mentre 'i', grazie a questo ciclo, è l'indice del ultimo caratere della stessa parola.*/
            i++;
            dim_parola1++;      /*Conto anche la dimensione della parola*/
        }

        while(s[j] != ' '){     /*fine è l'indice del ultimo carattere di una parola; mentre 'j', grazie a questo ciclo, è l'indice del primo caratere della stessa parola.*/
            j--;
            dim_parola2++;      /*Conto anche la dimensione della parola*/
        }

        printf("\nDOPO i:%d j:%d\n\n",i,j);

        i=i-1;                  /*Decremento per fare in modo che 'i' sia l'indice del ultimo caratere della stessa parola.*/
        j=j+1;                  /*Incremento per fare in modo che 'j' sia l'indice del primo caratere della stessa parola.*/

        cont_1=j;

        char*punt_inizio;       /*Puntatore che mi serve quando scalo tutti i caratteri di tot posizioni.*/
        punt_inizio= &s[i];

        /*char*punt_fine;
        punt_fine=&s[cont_1];*/

        printf("\n\nPuntatori = %d %c %d %d %d\n\n",punt_inizio,*punt_inizio,inizio,cont_1,&i);


        if(dim_parola1 < dim_parola2)       /*Date due parole da scambiare, calcola la dimensione per vedere quali delle due è più lunga.*/
            DIM= dim_parola2-dim_parola1;
        else                                /*DIM mi serve per capire quanti cicli fare per scalare i caratteri della stringa.*/
            DIM= dim_parola1-dim_parola2;   /*Es. DIM= 2, farò un primo ciclo che scalerà di una posizione tutti i caratteri, poi sarà fatto un secondo ciclo che scalererà tutti i caratteri di un'altra posizione.*/

        ripet_i=0;
        ripet_j=0;

        puts(s);




        printf("%d %d %d DIM:%d %d %d Inizio: %d, Fine: %d\n\n",i,j,cont_1,DIM,dim_parola1,dim_parola2,inizio,fine);

        /*Inizio a scambiare carattere per carattere delle due parole*/

        if(i < divide_in_due && j > divide_in_due){     /*Se divide_in_due è= 20, e una parola ha il primo carattere all'indice 15 e l'ultimo carattere all'indice 24,*/
            while(inizio <= i &&/*||*/ fine >= j){      /*questa non verrà considerata e il programma terminerà. */
                reset=0;

                if(s[inizio] == ' ')
                    inizio++;

                if(s[cont_1] != ' '){
                    scambio(&s[inizio],&s[cont_1]);
                    inizio++;
                    /*fine--;*/
                    cont_1++;
                }
                else{
                    reset++;
                    inizio=inizio+reset;
                    printf("\n\nINizio: %d reset: %d\n\n",inizio,reset);
                }
                fine--;

                printf("Inizio:%d fine:%d cont_1:%d i:%d j:%d\n",inizio,fine,cont_1,i,j);
            }
            puts(s);
            inizio=inizio-reset;
            reset=0;



            /*Se inizio è > di 'i' vuol dire che la prima parola (i) non è stata completamente spostata mentre la seconda parola (j) si.*/

            if(inizio > i && inizio < divide_in_due && inizio != ' '){
                cont= inizio+DIM;

                while(ripet_i < DIM){
                    printf("INIZIOOOO: %d FINEEEE: %d %c\n",inizio,fine,s[inizio+1]);

                    printf("\nCACCA1\n");
                    while(inizio < cont){
                        fin=cont_1;
                        iniz=inizio;
                        s[inizio]= s[cont_1];
                        puts(s);
                        while(fin >/*=*/ iniz/*+DIM-1*//*2*/){  /*Questo ciclo while sposta di una posizione ogni carattere della stringa*/
                            s[fin]= s[fin-1];
                            fin--;
                            puts(s);
                        }
                        inizio++;
                        cont_1++;
                        iniz++;
                        /*fine--;*/
                        printf("\n%d  %d %d %dCACCA100\n",inizio,fine,cont_1,fin);
                    }
                    ripet_i++;
                }
                fine--;
                int puntatore= punt_inizio-p;
                int new_punt= puntatore+DIM+1;
                s[new_punt]=' ';
                printf("\n\nRIPET: %d\n\n",ripet_i);
                puts(s);

            }


            /*Se fine è < di 'j' vuol dire che la seconda parola (j) non è stata completamente spostata mentre la prima parola (i) si.*/

            else if(fine < j && fine > divide_in_due && fine != ' '){
                cont= inizio+DIM;
                int iniz_1=inizio;

                while(ripet_j < DIM){
                    printf("INIZIo: %d FINe: %d %c\n",inizio,fine,s[inizio+1]);

                    printf("\nCACCA2\n");
                    while(iniz_1 < cont){
                        fin=cont_1;
                        iniz=inizio;
                        s[cont_1]= s[inizio];
                        puts(s);
                        while(iniz <= cont_1){      /*Questo ciclo while sposta di una posizione ogni carattere della stringa*/
                            s[iniz]= s[iniz+1];
                            iniz++;
                            puts(s);
                        }
                        s[iniz-1]= ' ';
                        puts(s);
                        iniz_1++;
                        /*inizio++;*/
                        /*cont_1++;*/
                        /*iniz++;*/
                        /*fine--;*/
                        /*conta_char_sx++;*/
                        printf("\n%d  %d %d %d CACCA 2\n",inizio,fine,cont_1,fin);
                    }
                    ripet_j++;
                }
                fine=fine-DIM;
                /*inizio=inizio+DIM;*/
                /*int puntatore= punt_fine-p;
                int new_punt= puntatore+dim_parola1-1;
                s[new_punt]=' ';
                printf("\n\npuntatore: %d, new_punt: %d\n\n",puntatore,new_punt);*/
            }
        }
        else{                           /*Se una parola ha dei caratteri oltre divide_in_due tutto il programma terminerà impostando inizio e fine uguale a divide_in_due.*/
            inizio= divide_in_due;
            fine= divide_in_due;
        }

        puts(s);
        /*}*/
        /*inizio++;
        fine--;*/
        cont_1++;
        dim_parola1=0;
        dim_parola2=0;
        printf("\nPrimo:%d Secondo:%d %d\n",inizio,fine,cont_1);
        printf("\n");
    }
}




/*
    Questa function sposta i singoli caratteri delle parole della stringa.
*/

void scambio(char*s,char*v)
{
    char t;
    t=*s;
    *s=*v;
    *v=t;
}

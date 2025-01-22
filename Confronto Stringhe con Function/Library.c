
void confronto(char string[][50], int n, char*comper)
{
    int i,j;
    int m= strlen(&string[1][0]);   /* Passo alla variabile 'm' la lunghezza della stringa più lunga del array 2D di stringhe*/

    strcpy(comper,&string[0][0]);   /* La '&' perchè la strcpy ha come parametri (entrambi) un puntatore, quindi devo assegnargli l'indirizzo della stringa[i][j]. comper è giaà un indirizzo base, è l'indirizzo base del array comper*/
                                    /* L'indirizzo base comper lo posso scrivere anche come &comper[0] */
                                    /* Uso la è commerciale perchè per l'array 2D stringa non posso usare il suo nome come indirizzo base (cioè: stringa), ma devo usare l'indirizzo della stringa, usando la '&', perchè indico l'indice della riga e della colonna.....*/
                                    /*...oppure posso passare l'indirizzo della prima stringa: stringa[0], quindi: strcpy(comper,stringa[0]); */

    for(i=1;i<3;i++){
        for(j=0;j<m;j++){
                if(strlen(&string[i][j]) > strlen(&comper[0]))  /* La '&' perchè la strlen ha come parametro un puntatore (const char *_Str), quindi devo assegnargli l'indirizzo della stringa*/
                    strcpy(comper,&string[i][j]);           /* La '&' perchè la strcpy ha come parametri (entrambi) un puntatore, quindi devo assegnargli l'indirizzo della stringa[i][j]. comper è giaà un indirizzo base, è l'indirizzo base del array comper*/
        }                                                    /* Uso la è commerciale perchè per l'array 2D stringa non posso usare il suo nome come indirizzo base (cioè: stringa), ma devo usare l'indirizzo della stringa, usando la '&', perchè indico l'indice della riga e della colonna.....*/
    }                                                        /* ....oppure posso usare ad esempio il ciclo for di sotto in alternativa.*/
    /*
    for(i=1;i<3;i++){                                        In alternativa al ciclo for di sopra posso usare questo ciclo for.
        if(strlen(stringa[i]) > strlen(comper))              comper è l'indirizzo base del array comper; stringa[i] è l'indirizzo base di ogni riga dell'array 2D stringa.
            strcpy(comper,stringa[i]);
    }
    */
}

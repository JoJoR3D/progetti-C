#include <stdio.h>
#include <stdlib.h>


/*Devo fare la fusione fino al mediano di un elemento con un solo altro elemento, poi devo dare la fusione della coppia generata con l'altra coppia generata e così via (a tre a tre, a quattro a quattro, ecc.. e così via),
  terminata la parte a sinistra di mediano passo a quella a destra di mediano. Tutto nel array A senza usare l'array C*/


void merge(int*, int, int*);
void swap(int*, int*);
void fusione6(int*, int, int[], int, int*, int, int, int);




int main()
{
    int a[]={7,3,11,2,6,1,8,4};   /*L'algoritmo non funziona con n=8*/
    int n= 8, i;
    int c[n];

    for(i=0;i<n;i++)
        c[i]=0;

    for(i=0;i<n;i++)
        printf("%d\n",&a[i]);

    printf("\n");

    for(i=0;i<n;i++)
        printf("%d\n",&c[i]);


    merge(a,n,c);


    for(i=0;i<n;i++)
        printf("%d\n",a[i]);

    printf("\n");

    for(i=0;i<n;i++)
        printf("%d\n",c[i]);

    return 0;
}





void merge(int*a, int n, int*c)
{
    int i=0, j=0, med, new_dim, dim_c=0, z=2, ciclo=0;

    int inizio= 0;
    int fine= n-1;
    int mediano= (inizio+fine)/2;

    int coppia= 1;
    int dim_i= 1;
    int dim_j= 2;

/*
    int med_s= mediano-1;
    int med_d= mediano;
*/




    /*Perte di sinistra dell'array*/

    /*while(med_s > 1)                  Serve per scomporre l'array
    {
        inizio= 0;
        fine= med_s;
        med_s= (inizio+fine)/2;
        printf("%d",med_s);
    }*/




    /*
    while(j+1 < mediano){

        while(j < z){

            fusione6(&a[0],i+1,&a[0],j+2,c,i,j+1,dim_c);

            j=j+mediano, i=i+mediano;
            dim_c=dim_c+mediano;

            ciclo++;
            printf("%d Ciclo parte sinista\n\n", ciclo);
        }
        z=z+2;
        printf("\n\nJ %d\n\n",j);
    }
    */







    while(j+coppia < mediano /*new_dim*/){

        printf("%d Ciclo parte SINISTRA\n\n", ciclo);

        while(j/*+1*/ < mediano/*j < z*/){  /*CONSIDERA ANCHE L'ELEMENTO MEDIANO, METTENDO IL +1 NO MA SALTA IL CONFRONTO CON UN ELEMENTO DELLA P. DI SINISTRA*/

            if(ciclo == 0 && j+coppia < mediano)

                fusione6(&a[0],i+1,&a[0],j+2,c,i,j+1,dim_c); /*Es. al I°ciclo il primo &a[0] è 7, mentre il secondo &a[0] è 3.*/
                                                             /*Al secondo ciclo il primo &a[0] indica la porzione che include 3,7.
                                                               Il secondo &a[0] indica la porzione che include 2,11.
                                                               Poi non li prende a tre a tre perchè l'elemento j+coppia (seconda porzione) è ==mediano.*/
            else if(ciclo == 0 && j+coppia >= mediano)

                fusione6(&a[0],i+1,&a[0],mediano,c,i,j+1,dim_c);

            else if(ciclo != 0 && j+coppia < mediano)

                fusione6(&a[0],dim_i/*i+1*/,&a[0],dim_j/*j+2*/,c,i,j+2,dim_c);

            else if(ciclo != 0 && j+coppia >= mediano)

                fusione6(&a[0],dim_i/*i+1*/,&a[0],mediano/*j+2*/,c,i,j+2,dim_c);


            /*printf("\n\ni= %d j+1= %d\n\n", i,j+1);*/

            /*j=j+coppia, i=i+coppia;
            dim_c= dim_c+coppia;*/

            if(ciclo == 0 || ciclo == 1){
                j=j+2, i=i+2;
                dim_c= dim_c+2;
            }
            else
                i=j, j=j+coppia, dim_c=dim_c+coppia;



            /*printf("\n\ni= %d j+1= %d\n\n", i,j+1);*/
        }
        /*z=z+2;*/
        ciclo++;

        coppia= coppia+1;

        dim_i= dim_i+1;
        dim_j= dim_j+2;

        printf("\n\nCp:%d\n",coppia);

        for(i=0;i<mediano;i++){
            if(c[i] != 0)
                a[i]= c[i];
            printf("\n\n%d\n",a[i]);}


        if(ciclo == 0 || ciclo == 1){
            j= 0, i= 0, dim_c= 0;
        }
        else
            j= 0+coppia, i= 0, dim_c= 0;
    }





    /*med= mediano;

    for(i=0;i<n;i++){
        if(med < n){
            a[i]= a[med];
            med++;
            new_dim= i;
        }
        else
            a[i]= 0;
    }*/


















    /*Perte di destra dell'array*/

    /*while(med_d != n-2)
    {
        inizio= med_d;
        fine= n-1;
        med_d= (inizio+fine)/2;
        printf("\n%d",med_d);
    }*/

    i= mediano;
    j= mediano;
    dim_c= mediano;
    /*z=mediano+2;*/
    ciclo=0;
    coppia= 1;
    dim_i= mediano+1  /*3*/;
    dim_j= mediano+2  /*4*/;

    /*printf("\n\n");
    for(i=0;i<n;i++)
        printf("%d\n",a[i]);
     printf("\n\n");*/



    while(j+coppia < n /*new_dim*/){

        printf("%d Ciclo parte DESTRA\n\n", ciclo);

        while(j/*+1*/ < n/*j < z*/){

            if(ciclo == 0 && j+coppia < n)

                fusione6(&a[0],i+1,&a[0],j+2,c,i,j+1,dim_c);

            else if(ciclo == 0 && j+coppia >= n)

                fusione6(&a[0],i+1,&a[0],n,c,i,j+1,dim_c);

            else if(ciclo != 0 && j+coppia < n)

                fusione6(&a[0],dim_i/*i+1*/,&a[0],dim_j/*j+2*/,c,i,j+2,dim_c);

            else if(ciclo != 0 && j+coppia >= n)

                fusione6(&a[0],dim_i/*i+1*/,&a[0],n/*j+2*/,c,i,j+2,dim_c);


            /*printf("\n\ni= %d j+1= %d\n\n", i,j+1);*/

            /*j=j+coppia, i=i+coppia;
            dim_c= dim_c+coppia;*/

            if(ciclo == 0 || ciclo == 1){
                j=j+2, i=i+2;
                dim_c= dim_c+2;
            }
            else
                i=j, j=j+coppia, dim_c=dim_c+coppia;



            /*printf("\n\ni= %d j+1= %d\n\n", i,j+1);*/
        }
        /*z=z+2;*/
        ciclo++;


        coppia= coppia+1;

        dim_i= dim_i+1;
        dim_j= dim_j+2;

        printf("\n\nCp:%d\n",coppia);

        for(i=mediano;i<n;i++){
            if(c[i] != 0)
                a[i]= c[i];
            printf("\n\n%d\n",a[i]);}


        if(ciclo == 0 || ciclo == 1){
            j=mediano, i=mediano, dim_c= mediano;
        }
        else
            j=mediano+coppia, i=mediano, dim_c= mediano;
    }



    if(j+coppia >= n && j+coppia >= mediano){
        dim_c=0;
        fusione6(&a[0],mediano,&a[0],n,c,0,mediano,dim_c);
        printf("\n\nFINE\n\n");}

    /*if(j+1 >= n){

        for(i=0;i<n;i++)
            a[i]= c[i];

        i= mediano;
        j= mediano;
        dim_c= mediano;
        ciclo=0;

        while(j <= 2){

            fusione6(&a[0],i+2,&a[0],j+4,c,i,j+2,dim_c);

            j=j+2, i=i+2;
            dim_c= dim_c+4;
        }
    }*/
}




/*
void swap(int*a, int*b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
*/




void fusione6(int*a, int n_a, int b[], int n_b, int*c, int start, int end, int dim_c/*, int n**/)
{
    int i_a=start, i_b=end, i_c=dim_c;

    printf("\n\ni_a= %d i_b= %d i_c= %d n_a= %d n_b= %d\n", i_a,i_b,i_c,n_a,n_b);
    /*printf("\nPrimo %d Secondo %d\n", &a[i_a],&b[i_b]);*/
    printf("\nPrimo %d Secondo %d\n\n\n", a[i_a],b[i_b]);


    while(i_a < n_a && i_b < n_b /*&& i_b < n*/){
        if(a[i_a] < b[i_b]){
            c[i_c] = a[i_a++];
        }
        else{
            c[i_c] = b[i_b++];
        }
        i_c++;                  /*Posizione POSTFISSA (i_c++) del ++ prima si usa il valore e poi lo si incrementa. Posizione PREFISSA (++i_c) invece prima si incrementa e poi si usa il valore */
    }
    while(i_a < n_a /*&& i_b < n*/){
        c[i_c++] = a[i_a++];
    }

    while(i_b < n_b /*&& i_b < n*/){
        c[i_c++] = b[i_b++];
    }
}

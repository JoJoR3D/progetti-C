int trova(int[], int, int);
void selection_sort(int[], int);
int Min(int[], int, int);
void scambio(int*, int*);


/*Questa function controlla che il valore generato casualmente non sia già stato generato in precedenza. (1)
  Se il valore casuale ('x') non è mai stato generato allora lo salva nell'array 'a'. (2)
*/

int trova(int a[], int x, int n)
{
    int i,t=0;
    for(i=0;i<n;i++){           /*(1)*/
        if(x == a[i]){
            t= 1;
            break;
        }
    }

    if(t == 0){                 /*(2)*/
        for(i=0;i<n;i++){
            if(a[i] == 0){
                a[i]= x;
                break;
            }
        }
    }

    return t;
}




/*Questa function ad ogni ciclo riceve dalla function Min() la posizione del valore minimo dell'array. (1)
  Poi tramite la function scambio, il valore minimo (&a[var]) viene scambiato con il valore (&a[i]). (2)

  Ad esempio al ciclo i=0, la function Min() mi ritorna che il valore minimo si trova alla posizione 7 (indice 7 dell'array).
  Quindi tramite la function scambio(), viene scambiato il valore del ciclo &a[0] con il valore minimo presente alla posizione &a[7].

  N.B.
  Alla function Min() passo anche il valore di 'i', perchè ad ogni ciclo l'array si accorcia poichè i valori minimi trovati, di volta in volta, saranno ordinati
  a partire dall'inizio dell'array.
  Ad esempio abbiamo un array di dimensione n=10:
  1) al primo ciclo con i=0, l'array passato alla function Min() va da 0 a 9.
     Il valore minimo sarà trovato e poi messo tramite la function scambio() alla posizione a[0];
  2) al secondo ciclo con i=1, l'array passato alla function Min() va da 1 a 9.
     Il valore minimo sarà trovato e poi messo tramite la function scambio() alla posizione a[1];
  3) al terzo ciclo con i=2, l'array passato alla function Min() va da 2 a 9.
     Il valore minimo sarà trovato e poi messo tramite la function scambio() alla posizione a[2];

     e così via....
*/

void selection_sort(int a[], int n)
{
    int i=0,var;
    while(i < n){
        var=Min(&a[0],n,i);         /*(1)*/
        scambio(&a[i],&a[var]);     /*(2)*/
        i++;
    }
}




/*Questa function trova il valore minimo dell'array passato e mi ritorna la sua posizione.*/

int Min(int a[], int n, int iniz_array)
{
    int i,pos=iniz_array;

    /*printf("\n\n");
    for(i=iniz_array;i<n;i++){
        printf("%d %d\n",i,a[i]);
    }*/

    for(i=iniz_array;i<n;i++){
        if(a[i] < a[pos])
            pos= i;
    }

    /*printf("\nPos: %d\n",pos);*/

    return pos;
}




/*Questa function scambia i due valori passati.*/

void scambio(int*a, int*b)
{
    int t;
    t= *a;
    *a= *b;
    *b= t;
}

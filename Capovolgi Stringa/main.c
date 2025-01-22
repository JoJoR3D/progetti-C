#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void back(char*s,int n);
void swap(char*s,char*v);


int main()
{
    char stringa[]= "Corro e salto felice nel prato verde con il cielo blu";
    int n;
    n= strlen(stringa);

    back(stringa,n);

    printf("Stringa capovolta:\n\n");
    puts(stringa);

    return 0;
}


void back(char*s,int n)
{
    int fine=n-1,inizio=0;
    int divide_in_due= (inizio+fine)/2;

    while(inizio != divide_in_due){
        swap(&s[inizio],&s[fine]);
        inizio++;
        fine--;
    }
}


void swap(char*s,char*v)
{
    char t;
    t=*s;
    *s=*v;
    *v=t;
}

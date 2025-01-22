#include <iostream>

using namespace std;

int main()
{
    string mesi[]= {"Gennaio","Febbraio","Marzo","Aprile","Maggio","Giugno","Luglio","Agosto","Settembre","Ottobre","Novembre","Dicembre"};
    int num;

    do{
        printf("Inserisci il numero corrispondente al mese che vuoi visualizzare: ");
        scanf("%d",&num);

        if(num >= 1 && num <= 12){
            printf("Il mese corssipondente e': ");
            cout << mesi[num-1] << endl;
        }
        else
            cout << "ERRORE!" << endl;
    }while(num < 1 || num > 12);

    return 0;
}

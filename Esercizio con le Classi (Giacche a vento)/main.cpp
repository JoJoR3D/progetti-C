#include <iostream>
#include <ctime>

using namespace std;


class Giacche_Vento{

public:

    void random_open_close(int seme, int &cerniera){
        srand(seme);
        cerniera= 10+rand()%40;
        cout << "Percentuale apertura Cerniera: " << cerniera << "%" << endl;
    }

    void close(){
        cout << "La cerniera e' chiusa" << endl;
    }

    void open(){
        cout << "La cerniera e' aperta" << endl;
    }

    void Taglia(int taglia){
        cout << "Taglia: " << taglia << endl;
    }

    void nome(string s){
        printf("%s\n",&s[0]);
    }



private:

    int seme=100, taglia, cerniera=0;
    string s;
};




void win(int x, int y){

    if(x < y)
        cout << "Giacca2 ha un'apertura della cerniera maggiore (" << y << "%)" << endl;
    else
        cout << "Giacca1 ha un'apertura della cerniera maggiore (" << x << "%)" << endl;
}




int main()
{
    int seme,giacca1,giacca2;
    srand(time(NULL));
    seme=rand()%100;

    Giacche_Vento gv;

    gv.nome("Diesel");

    gv.Taglia(30);
    gv.close();
    gv.open();
    gv.random_open_close(seme,giacca1);

    printf("\n");
    seme=rand()%100;

    gv.nome("Dolce&Gabbana");

    gv.Taglia(40);
    gv.close();
    gv.open();
    gv.random_open_close(seme,giacca2);

    printf("\n");
    win(giacca1,giacca2);

    return 0;
}

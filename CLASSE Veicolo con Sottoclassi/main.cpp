#include <iostream>
#include <string>

using namespace std;


class Veicolo{          /*SUPERCLASSE*/
private:
    int numRuote, numPasseggeri;

public:
    int set_ruote(int numRuote){
        cout << "Numero ruote: " << numRuote << endl;
        return numRuote;
    };

    int set_pass(int numPasseggeri){
        cout << "Numero passeggeri: " << numPasseggeri << endl;
        return numPasseggeri;
    };

    void view(){                            /*OVERRIDE*/
        cout << "VEICOLO\n" << endl;
    };

    Veicolo(){};    /*COSTRUTTORE DI DEFAULT*/

    ~Veicolo(){};   /*DISTRUTTORE*/
};



class automobile : public Veicolo{          /*SOTTOCLASSE DELLA CLASSE BASE VEICOLO*/
private:
    string tipo_auto;

public:
    string set_tipo(string tipo_auto){
        cout << "Tipo auto: " << tipo_auto << endl;
        return tipo_auto;
    };

    void view(){                            /*OVERRIDE*/
        cout << "AUTOMOBILE\n" << endl;
    };

    automobile(){};     /*COSTRUTTORE DI DEFAULT*/

    ~automobile(){};    /*DISTRUTTORE*/
};




class camion : public Veicolo/*, public automobile*/{     /*SOTTOCLASSE DELLA CLASSE BASE VEICOLO*/
private:
    int peso_rimorchio;

public:
    int set_peso(int peso_rimorchio){
        cout << "Peso rimorchio: " << peso_rimorchio << " kg" << endl;
        return peso_rimorchio;
    };

    void view(){                        /*OVERRIDE*/
        cout << "CAMION\n" << endl;
    };

    camion(){};     /*COSTRUTTORE DI DEFAULT*/

    ~camion(){};    /*DISTRUTTORE*/
};





int main()
{
    Veicolo v;
    v.set_ruote(4);
    v.set_pass(2);
    v.view();

    automobile car;
    car.set_tipo("Fiat Panda");
    car.view();

    cout << "\n" << endl;

    camion c;
    c.set_peso(100);
    /*c.set_tipo("Iveco");*/
    c.set_ruote(6);
    c.set_pass(1);
    c.view();

    return 0;
}

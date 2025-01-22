#ifndef PROT_H_INCLUDED
#define PROT_H_INCLUDED

void lunghezza_due_array(char*, char*, int*, int*);
void lung(int, int, int*, int*);
void LUNGHEZZA(int, int, int*);
int check(char*, int*, int, int);
int check2(int*, int*, int);
void calculation(int*, int, char*, int*, int);
void operazione_somma(int, int, char*, char*, int, int*, int*, int*, int);
void operazione_differenza(int, int, char*, char*, int*, int*, int*, int, int);
void Racc_Function(char*, char*, int*, int*, int, int, int, int, int*, char*, int*, int, int);
void comparazione_char(char*, char*, int*);



void clearArray(char[], int);
double calcoli(double x, double y, double z, double seed);
void conv_float_to_int(char*);
void calcoli_1(char*, char*, char*, char*, char*, int*);
/*double calcoli(char[], char[], char[], char[]);*/
/*int calcoli(int, int, int, int);*/
/*int intervallo_input(int[], int, int);*/
double intervallo_input(double[], int, int);
void read_file(char[][32/*29*/]);

#endif // PROT_H_INCLUDED

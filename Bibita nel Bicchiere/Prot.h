#ifndef PROT_H_INCLUDED
#define PROT_H_INCLUDED

void riemp(int, int*, char[]);
int quant_riemp(int);
int lettura(int, char[]);
void write(int, char[]);
int read(char[]);
void visualizza(char*, int, int, int, int, int*, int*, char, char);
void cont_versa(char*, int, int , int, char, char);
/*void write_ciclo(int);*/
/*int read_ciclo();*/
void rewrite(char[]);

int find_name(char[]);
void view_name();
void write_name(char[]);
void new_player(char[]);
void write_score(char[]);
/*void let_name(char[], int*, int*);*/
/*void NewScore(int,int);*/

#endif // PROT_H_INCLUDED

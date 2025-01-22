#ifndef PROT_H_INCLUDED
#define PROT_H_INCLUDED

int Modpartita();
void scelta_1(char[], char[], int*, int*, int*, int*, int, int, int);
void scelta_2(char[], char[], int*, int*, int*, int*, int, int, int);
void riemp(int, int*, char[], char[], int, int, int, int*);
int quant_riemp(int, char[], char[]);
int lettura(int, char[]);
void write(int, char[]);
int read(char[]);
void visualizza(char*, int, int, int, int, int*, int*, char, char, char[]);
/*void cont_versa(char*, int, int , int, char, char, int*, int*, int);*/
void singolplayer(char*, int , int, int, char, char, int);
void multiplayer(char*, int, int, int, char, char, int*, int*, int, int);
void rewrite(char[]);
void function_finale(char*, char*, int, int, int, char, char);
void winnerIS();

int find_name(char[]);
void view_name();
void write_name(char[]);
void new_player(char[]);
void write_score(char[]);
int cont_num_nick(char[]);
void ripulisci_stringa(char[]);
void reinserire_nick(char[], int, int*, int*, int*, int*, int*);

void write_Npartita(char[]);
void crea_file(char[], char[]);
void Read(char[], char[]);
void file_Npartite_singol_player(char[], char[], int);
void file_Npartite_multi_player(char[], char[], char[], char[], int, int);

void back_string(char[], char[]);
int conf_string(char[], char[]);

#endif // PROT_H_INCLUDED

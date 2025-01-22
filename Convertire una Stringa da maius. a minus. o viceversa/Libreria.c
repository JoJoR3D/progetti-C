
int convertire(char Stringa) /*Converte un carattere da maiuscolo a minuscolo o viceversa*/
{
    return Stringa^32;      /*32 perché tra il codice ASCII di un carattere minuscolo e uno maiscolo o viceversa vi è una differenza di 32.*/
}                           /*Es.: 'a' codice ASCII=97; 'A' codice ASCII= 65; 97-65=32*/

                            /* ^ è il XOR= restituisce in uscita VERO (1) se e solo se gli ingressi sono diversi tra di loro. Se gli ingressi sono uguali restituisce FALSO (0).*/

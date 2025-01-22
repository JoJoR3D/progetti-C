
int convert(char stringa)
{
    char s= (stringa-32);   /*Sottraggo al codice ASCII del carattere ricevuto in input il valore 32*/
    if((int)s >= 65)        /*Se il carattere ricevuto è già maiuscolo, ritorno semplicemente questo carattere senza fare nulla*/
        return s;
    return stringa;         /*Se invece il carattere ricevuto è minuscolo, sottraggo al codice ASCII di quel carattere il valore 32 per ottenere
                              il codice ASCII corrispondente al carattere Maiuscolo.*/
}


/*

ESEMPIO:

'a' in codice ASCII è 97= 1100001 sottrazione
    codice ASCII di 32=   0100000 =

'A' in codice ASCCI è 65= 1000001

Precisando che nella tabella ASCII i caratteri MAIUSCOLI del alfabeto partano dal codice 65 fino al 90, mentre i caratteri MINUSCOLI del alfabeto partano dal codice 97 fino a 122.
Da un carattere Maiuscolo ad uno Minuscolo o viceversa c'è sempre una differenza di 32.
Ora visto che devo SOLO convertire tutta la stringa in MAIUSCOLO, se un carattere è già Maiuscolo non devo fare nulla, ecco perché ad esempio se alla function covert arriva
il carattere 'A' che è già maiuscolo (codice ASCII= 65), se sottraggo a 65 il valore 32 ottengo 33 che corrisponde al carattere '!'. Quindi se la function convert riceve un carattere già
Maiuscolo, non fa nulla e ritorna semplicemente quel carattere.



Tabella codice ASCII: https://www.oppo.it/tabelle/tabella_ascii.htm#:~:text=ASCII%20(si%20pronuncia%20%22askii%22,grafici%20e%20di%20lingue%20straniere.

*/

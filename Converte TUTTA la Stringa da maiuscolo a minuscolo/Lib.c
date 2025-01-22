
int convert(char stringa)
{
    return (stringa|32);    /*OR bit a bit*/
}


/*

ESEMPIO:

'A' in codice ASCII è 65= 1000001 OR
    codice ASCCII di 32=  0100000 =

'a' in codice ASCII è 97= 1100001 OR

L'OR bit a bit ritorna 1 in quelle posizioni in cui almeno una delle due variabili di partenza presenta 1 e
uno 0 in tutte le altre posizioni (ossia le posizioni in cui entrambe le variabili presentano '0').

Se il carattere che giunge in input alla function convert è già Minuscolo anche facendo l'operazione di OR con 32, questo carattere rimarrà invariato.
Esempio:

'a' in codice ASCII è 97= 1100001 OR
    codice ASCCII di 32=  0100000 =

'a' in codice ASCII è 97= 1100001

il carattere ricevuto è 'a' (minuscolo con codice ASCII 97), facendo l'OR con 32 rimane sempre 'a' (minuscolo con codice ASCII 97).



SITO per il bit a bit: https://it.wikipedia.org/wiki/Operazione_bit_a_bit

Tabella codice ASCII: https://www.oppo.it/tabelle/tabella_ascii.htm#:~:text=ASCII%20(si%20pronuncia%20%22askii%22,grafici%20e%20di%20lingue%20straniere.

*/

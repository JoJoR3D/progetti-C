
float oper(char segno, float a, float b)
{
    if(segno == '+')                          /*In base al segno inserito con lo scanf, eseguir� il giusto if. Es: se il segno inserito � '*' eseguir� la moltip. tra 'a' e 'b'*/
        return (a + b);

    else if(segno == '-')
        return (a - b);

    else if(segno == '*')
        return (a * b);

    else if(segno == '/')
        return (a / b);

    else if(segno == '^')
        return pow(a,b);                      /*Uso la funzione pow (che vuole in input due float) per calcolare la potenza. In questo caso 'a' � la base mentre 'b' � l'esponente*/

    else
        exit(1);                              /*Se si inserisce un segno diverso da quello indicato, il compilatoree ritorna: Process returned 1 */
}

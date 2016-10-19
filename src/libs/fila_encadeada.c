#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// declaracao do tipo de dado FILA
#include "tipofilaCLIENTE.h"


int main()
{
tipofila inicio,fim;
struct cliente x;
INIT(&inicio,&fim);

x.id=2;
strcpy(x.nome, "Joao");

ENQUEUE(&inicio,&fim,x);
if (DEQUEUE(&inicio,&fim,&x))
	printf("eliminado id= %d nome %s\n", x.id, x.nome);


system("pause");
}

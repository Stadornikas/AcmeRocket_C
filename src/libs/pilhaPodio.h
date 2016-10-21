#include "sucesso.h"

/* declaracao do no */
struct rank
{
	struct sucesso dado;   //tipo do elemento da pilha
	struct rank *prox;
};


/*Defini��o do tipo de dado pilha */
typedef struct rank* pilhaPodio;


//Fun��o que inicia a pilha
void INIT(pilhaPodio *topo)
{
	*topo = NULL;
}


//Verifica se o n� est� vazio
int IsEmpty(pilhaPodio topo){
	return topo == NULL ? 1 : 0;
}

//Adiciona um novo v� na pilha
void PUSH (pilhaPodio *topo, struct sucesso elem)
{
pilhaPodio novo;
novo = (pilhaPodio) malloc (sizeof(struct sucesso));
if (novo != NULL)
{
	novo->dado=elem;
	novo->prox=*topo;
	*topo = novo;
}
else
	printf("pilha cheia \n");
}


//Remove um elemento da pilha
int POP (pilhaPodio *topo, struct sucesso *elem)
{
pilhaPodio aux;
aux = *topo;
	if (!IsEmpty(*topo)) {
	     *elem=aux->dado;
	     *topo=aux->prox;
	     free(aux);
	     return(1);
	}
	else
	{
       printf("pilha vazia \n ");
       return(0);
    }
}


//LE O VALOR DO PRIMERIO ELEMENTO DA PILHA
int TOP(pilhaPodio topo, struct sucesso *elem)
{
	pilhaPodio aux;
	aux = topo;
	if(!IsEmpty(topo)){
		*elem = topo->dado;
		return(1);
	}else{
		printf("A pilha vazia ");
		return(0);
	}

}

int SHOW(pilhaPodio topo, int cont){
	int aux, val;
	if(topo->prox != NULL){
		printf("%d item da pilha: %d", cont, val) ;
		SHOW(topo->prox, cont + 1);
	}
	return 0;
}




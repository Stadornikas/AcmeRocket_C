#include "lancamento.h"

struct noLancamento { 
       struct lancamento dado;
       struct noLancamento *prox;
};

typedef struct noLancamento* tipofilaLancamento;

void INITLANC(tipofilaLancamento *inicio,tipofilaLancamento *fim)
{
	*inicio=NULL;
	*fim=NULL;
}

int IsEmptyLancamento(tipofilaLancamento inicio,tipofilaLancamento fim)
{
	if ((inicio==NULL) && (fim == NULL))
		return(1);
	else
		return(0);
}

void ENQUEUE(tipofilaLancamento *inicio,tipofilaLancamento *fim, struct lancamento v)
{
	tipofilaLancamento novo;
	novo =(tipofilaLancamento) malloc (sizeof(struct noLancamento));
	if (novo!=NULL)
		{
		novo->dado=v;
		novo->prox=NULL;
		if (IsEmptyLancamento(*inicio,*fim)){
		  *inicio=novo;
		}
		else
		{
		  (*fim)->prox=novo;
		}
	   *fim=novo;
	}
	else
		printf("overflow \n");
}


int DEQUEUE (tipofilaLancamento *inicio,tipofilaLancamento *fim, struct lancamento *v)
{
	tipofilaLancamento aux;
	aux = *inicio;
	if (!IsEmptyLancamento(*inicio,*fim))
	{
		 *v=(*inicio)->dado;
		 *inicio=(*inicio)->prox;

		 if(*inicio==NULL)  *fim=NULL;

		 free(aux);

		 return(1);
	}
	else
	{
		 printf("fila vazia \n ");
		 return(0);
	}
}


int ORDER(tipofilaLancamento *inicio,tipofilaLancamento *fim){
	
	tipofilaLancamento aux, aux2, aux3, auxProx;
	aux = (tipofilaLancamento) malloc(sizeof(struct lancamento));
	aux2 = (tipofilaLancamento) malloc(sizeof(struct lancamento));
	aux3 = (tipofilaLancamento) malloc(sizeof(struct lancamento));
	printf("Malloc /n");
	aux = *inicio;
	printf("Atrib /n");
	
	if(!IsEmptyLancamento(*inicio,*fim)){
		
		while(aux != NULL){
			printf("Antes if /n");
			auxProx = (*inicio)->prox;
			if((*inicio)->dado.distanciaAlvo < auxProx->dado.distanciaAlvo ){
				printf("Depois If /n");
				aux3 = (*inicio)->prox;
				printf("Atrib aux 3 /n");
				aux2 = (*inicio)->prox->prox;
				printf("Atrib aux 2 /n");
				(*inicio)->prox = (*inicio)->prox->prox->prox;
				printf("Suruba de prox /n");
				aux2 = aux3;
			}
			
			aux = aux->prox;
		}
	}
}


int PROXIMO(tipofilaLancamento *inicio){
	tipofilaLancamento aux;
	aux = *inicio;	
		if (aux!=NULL){
			return (1);
		}else{
			return (0);
		}
}

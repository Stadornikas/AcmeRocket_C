#include "lancamento.h"


typedef struct lancamento {
	char nomeEquipe[MAX];
	int tentativas;
	float distanciaAlvo;
	float tempoPropulsao;
	int situacao;
} lancamento;

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
tipofilaLancamento aux;
aux=(tipofilaLancamento) malloc (sizeof(struct noLancamento));
if (aux!=NULL)
	{
	aux->dado=v;
	aux->prox=NULL;
	if (IsEmpty(*inicio,*fim)){
	  *inicio=aux;
	  }
	else{
	  (*fim)->prox=aux;
	  }
   *fim=aux;
	}
else
	printf("overflow \n");
}


int DEQUEUE (tipofilaLancamento *inicio,tipofilaLancamento *fim, struct lancamento *v)
{
tipofilaLancamento aux;
aux = *inicio;
if (!IsEmpty(*inicio,*fim))
     {
     *v=(*inicio)->dado;
     *inicio=(*inicio)->prox;
     if(*inicio==NULL)
       *fim=NULL;
     free(aux);
     return(1);
     }
else
     {
     printf("fila vazia \n ");
     return(0);
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
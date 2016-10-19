
struct no { 
       int dado;
       struct no *prox;
};

typedef struct no* tipofila;

void INIT(tipofila *inicio,tipofila *fim)
{
*inicio=NULL;
*fim=NULL;
}

int IsEmpty(tipofila inicio,tipofila fim)
{
if ((inicio==NULL) && (fim == NULL))
  return(1);
else
  return(0);
}

void ENQUEUE(tipofila *inicio,tipofila *fim, int v)
{
tipofila aux;
aux=(tipofila) malloc (sizeof(struct no));
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


int DEQUEUE (tipofila *inicio,tipofila *fim, int *v)
{
tipofila aux;
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

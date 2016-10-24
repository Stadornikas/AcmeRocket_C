#include "lancamento.h"

struct noLancamento {
    struct lancamento dado;
    struct noLancamento *prox;
};

typedef struct noLancamento* tipofilaLancamento;

void INITLANC(tipofilaLancamento *inicio, tipofilaLancamento *fim) {
    *inicio = NULL;
    *fim = NULL;
}

int IsEmptyLancamento(tipofilaLancamento inicio, tipofilaLancamento fim) {
    if ((inicio == NULL) && (fim == NULL))
        return (1);
    else
        return (0);
}

void ENQUEUE(tipofilaLancamento *inicio, tipofilaLancamento *fim, struct lancamento v) {
    tipofilaLancamento novo;
    novo = (tipofilaLancamento) malloc(sizeof (struct noLancamento));
    if (novo != NULL) {
        novo->dado = v;
        novo->prox = NULL;
        if (IsEmptyLancamento(*inicio, *fim)) {
            *inicio = novo;
        } else {
            (*fim)->prox = novo;
        }
        *fim = novo;
    } else
        printf("overflow \n");
}

int DEQUEUE(tipofilaLancamento *inicio, tipofilaLancamento *fim, struct lancamento *v) {
    tipofilaLancamento aux;
    aux = *inicio;
    if (!IsEmptyLancamento(*inicio, *fim)) {
        *v = (*inicio)->dado;
        *inicio = (*inicio)->prox;

        if (*inicio == NULL) *fim = NULL;

        free(aux);

        return (1);
    } else {
        printf("fila vazia \n ");
        return (0);
    }
}

int ORDER(tipofilaLancamento *inicio, tipofilaLancamento *fim) {

    tipofilaLancamento aux, aux2, aux3;
    aux = *inicio;

    if (!IsEmptyLancamento(*inicio, *fim)) {

        while (aux != NULL) {

            if ((*inicio)->dado.distanciaAlvo < (*inicio)->prox->dado.distanciaAlvo) {
                aux3 = (*inicio)->prox;
                aux2 = (*inicio)->prox->prox;
                (*inicio)->prox = (*inicio)->prox->prox->prox;
                aux2 = aux3;
            }

            aux = aux->prox;
        }
    }
}

tipofilaLancamento COPY(tipofilaLancamento inicio) {
    if (inicio == NULL) return NULL;

    tipofilaLancamento aux;
    aux = (tipofilaLancamento) malloc(sizeof (struct noLancamento));
    if (aux != NULL) {
        aux->dado = inicio->dado;
        aux->prox = COPY(inicio->prox);
    } else {
        return NULL;
    }
    return aux;
}

int COUNT(tipofilaLancamento *inicio){
    tipofilaLancamento aux;
    aux = *inicio;
    int cont = 0;
    while(aux != NULL){
        cont++;
        aux = aux->prox;
    }
    return cont;
}

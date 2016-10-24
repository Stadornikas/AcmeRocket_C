#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "libs/tipofilaLancamento.h"
#include "libs/pilhaPodio.h"

int main() {
    setlocale(LC_ALL, "Portuguese");

    //definicoes da pilha
    pilhaPodio pilha;
    sucesso podio, aux;
    INIT(&pilha);

    //definicoes de listas
    tipofilaLancamento iniLancamento, fimLancamento, iniSucesso, fimSucesso, percorre;
    lancamento equipes, campeao, lancamentoOK;
    INITLANC(&iniLancamento, &fimLancamento);
    INITLANC(&iniSucesso, &fimSucesso);

    //definicoes de variaveis
    int x = 0, j = 0, contadorSucesso = 0, colocacao = 0, minEquipe = 0, ctrl = 0;
    float menorDistancia = 9999999, maiorTempoPropulcao = 0;
    char situacao, continuar = 's';


    printf("  ____                         _           _             \n");
    printf(" |  _ \\                       (_)         | |           \n");
    printf(" | |_) | ___ _ __ ___   __   ___ _ __   __| | ___        \n");
    printf(" |  _ < / _ \\ '_ ` _ \\  \\ \\ / / | '_ \\ / _` |/ _ \\ \n");
    printf(" | |_) |  __/ | | | | |  \\ V /| | | | | (_| | (_) |     \n");
    printf(" |____/ \\___|_| |_| |_|   \\_/ |_|_| |_|\\__,_|\\___/   \n");
    printf("               AO SISTEMA ACME ROCKET\n\n\n");
    printf(" ");
    printf("\n Cadastre 3 ou mais equipes para participarem da competição SpaceCup");
    printf("\n ");

    //Pega nomes das equipes
    do {
        //Insiro todos as equipes na fila Lancamento, iniciando os valores padrao.
        equipes.tentativas = 0;
        equipes.situacao = 0;

        printf("\n Digite nome da equipe a ser cadastrada:");
        fflush(stdin);
        fgets(equipes.nomeEquipe, MAX, stdin);

        if (strcmp(equipes.nomeEquipe, "") == 0 || strlen(equipes.nomeEquipe) == 0) {
            printf("\n Digite um nome valido \n");
        } else {
            ENQUEUE(&iniLancamento, &fimLancamento, equipes);
            minEquipe++;
            printf("\n Equipe %s cadastrada com sucesso \n", equipes.nomeEquipe);
        }

        printf("\n Deseja cadadastrar outra equipe?(s/n):");
        fflush(stdin);
        scanf("%c", &continuar);

        while (getchar() != '\n'); //Limpa o buffer de leitura

    } while (continuar == 's' || minEquipe < 3);


    percorre = iniLancamento;


    //Percorre a fila de equipes equanto conter itens na lista
    while (percorre != NULL) {
        //repete ate que todas as equipes tenham participado
        while (percorre->dado.tentativas <= 2 && percorre->dado.situacao == 0) {
            //Maximo de 3 tentativas por equipe
            for (x = 0; x < 3; x++) {
                printf("\n----------------------------------------------------------------------\n");
                printf("\nQual a situacao do %d lancamento da equipes %s?", x + 1, percorre->dado.nomeEquipe);
                printf("\nInforme (s) Sucesso (f) Falha: ");
                fflush(stdin);
                scanf(" %c", &situacao);

                switch (situacao) {
                    case 's':
                        percorre->dado.situacao = 1;

                        printf("\nDigite a distancia do alvo: ");
                        fflush(stdin);
                        scanf("%f", &percorre->dado.distanciaAlvo);

                        printf("Digite o tempo de propulsao: ");
                        fflush(stdin);
                        scanf("%f", &percorre->dado.tempoPropulsao);

                        percorre->dado.tentativas++;
                        break;

                    case 'f':
                        printf("Lancamento falhou \n");
                        percorre->dado.tentativas++;
                        if (percorre->dado.tentativas > 2) {
                            percorre->dado.situacao = -1;
                        }
                        break;

                } // END CASE

                // Insere na fila de sucesso as equipes com status 1
                if (percorre->dado.situacao == 1) {
                    ENQUEUE(&iniSucesso, &fimSucesso, percorre->dado);
                    contadorSucesso++;
                    break;
                }
            } //END FOR

        } //END WHILE

        //avanca item da lista para proxima iteracao
        percorre = percorre->prox;

    } // End While


    printf("\n######################################################");
    printf("\n#                                                    #");
    printf("\n#              EQUIPES CLASSIFICADAS                 #");
    printf("\n#                                                    #");
    printf("\n######################################################\n");

    while (getchar() != '\n'); //Limpa o buffer de leitura

    percorre = iniSucesso;
    
    while (percorre != NULL) {
        printf("\n Nome da equipe: %s ", percorre->dado.nomeEquipe);
        percorre = percorre->prox;
    }

    printf("\n Pressione ENTER para visualizar os campeoes");
    scanf("%c", &continuar);

    
    percorre = COPY(iniSucesso);

    
    // Enquanto nao encontrar campeoes
    while (colocacao < 3) {

        // Percorre fila de equipes que obtiveram sucesso
        for (j = 0; j < contadorSucesso; j++) {

            //Retira o lamcamento da fila para ser comparado com os demais lancamentos
            DEQUEUE(&iniSucesso, &fimSucesso, &lancamentoOK);

            //Pega sempre a menor distancia do alvo
            if (lancamentoOK.distanciaAlvo < menorDistancia) {
            	//Se encontrar algum menor que a atual menorDistancia o antigo campeao volta para a fila
				if(ctrl != 0){
					ENQUEUE(&iniSucesso, &fimSucesso, campeao);
				}
                menorDistancia = lancamentoOK.distanciaAlvo;
                maiorTempoPropulcao = lancamentoOK.tempoPropulsao;
                campeao = lancamentoOK;
                ctrl++;
                 
            } else if (lancamentoOK.distanciaAlvo == menorDistancia) {
                //Criterio de dempate = maior tempo de propulsao
                if (lancamentoOK.tempoPropulsao > maiorTempoPropulcao) {
                    maiorTempoPropulcao = lancamentoOK.tempoPropulsao;
                    campeao = lancamentoOK;
                }
            } else {
                //Caso nao seja menor volta para a fila
                ENQUEUE(&iniSucesso, &fimSucesso, lancamentoOK);
            }
           
            
        }// end for
        
        
       
        while (percorre != NULL) {
               
            if (percorre->dado.distanciaAlvo == campeao.distanciaAlvo && percorre->dado.tempoPropulsao == campeao.tempoPropulsao) {
                strcpy(podio.nomeEquipe, campeao.nomeEquipe);
                podio.distanciaAlvo = campeao.distanciaAlvo;
                podio.tempoPropulsao = campeao.tempoPropulsao;
                PUSH(&pilha, podio);
            }
            percorre = percorre->prox;
        }
        
        percorre = COPY(iniSucesso);
        
        menorDistancia = 999999;
        colocacao++;
        ctrl = 0;
    }//end while



    printf("\n######################################################");
    printf("\n#                                                    #");
    printf("\n#              RESULTADOS DA COMPETICAO              #");
    printf("\n#                                                    #");
    printf("\n######################################################\n");

    while (!IsEmpty(pilha)) {
        POP(&pilha, &aux);
        printf("\nEm %d Lugar: ", colocacao);
        printf("\nNome da Equipe: %s", aux.nomeEquipe);
        printf("\nDistancia do alvo: %0.2f \n", aux.distanciaAlvo);
        printf("\nTempo de propulsao: %0.2f \n", aux.tempoPropulsao);
        printf("\n");
        printf("\n");
        colocacao--;
    }


    printf("\n\nPressione um tecla para sair \n");

    system("pause");
    return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipoPilhaCHAR.h"

int main(){
	tipopilha pilha;
	char ler[50], comp[50];
	int i = 0;
	INIT(&pilha);
	
	printf("Digite uma palavra: ");
	gets(ler);
	
	for(i = 0; i < strlen(ler); i++){
		PUSH(&pilha, ler[i]);
	}
	
	i = 0 ;
	
	while (!IsEmpty(pilha)){
       POP(&pilha, &comp[i]);
       i++;
    }
    
    printf("\n Palavra digitada \n");
    puts(ler);
    
    printf("\n Palavra invertida \n");
    puts(comp);
    
    printf("\n\n");
    
    if( strcmp(ler, comp) == 0 ){
    	printf(" A palavra %s eh palindroma \n", ler);
	}else{
		printf(" A palavra %s nao eh palindroma \n", ler);
	}
	
	printf("\n\n");
	
	system("pause");
}

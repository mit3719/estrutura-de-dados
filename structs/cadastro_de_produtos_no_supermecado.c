/**
 * Escreva um programa que cadastre v�rios produtos. Em seguida,
 * imprima uma lista com o c�digo e nome de cada produto. Por �ltimo,
 * consute o pre�o de um produto atrav�s de seu c�digo 
 */
#include <stdio.h>

#define qtdP 2

typedef struct 
{
	long codigo;
	char nome[100];
	float preco;
}Produto;

int main()
{
	Produto produtos[qtdP];
	
	printf("Campos: codigo-do-produto, nome e preco\n");
	int i;
	for(i = 0 ;i < qtdP ;i++ ){
		printf("\nInforme os dados do produtos(%d): ", i+1);
		scanf("%ld %s %f", &produtos[i].codigo, produtos[i].nome, &produtos[i].preco);
	}
	int l;
	for(l = 0 ;l < qtdP ;l++ ){
                printf("\n%ld\t%s R$ %1.2f", produtos[l].codigo,
                        produtos[l].nome,produtos[l].preco);
        }
	long codigo_digitado;
	printf("\nInforme o codigo do produto: ");
	scanf("%ld", &codigo_digitado);
	
	int j;
	for(j = 0 ;j < qtdP ;j++ ){
		if(produtos[j].codigo == codigo_digitado)
			printf("\nPre�o: R$ %1.2f\n", produtos[j].preco);
	}
	return 0;
}
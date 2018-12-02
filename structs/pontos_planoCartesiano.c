/**
 * Escrevar um programa que leia 5 pontos. 
 * Em seguida imprima qual o ponto mais próximo do primeiro lido.
 */
#include <stdio.h>
#include <limits.h>//contém definição de INT_MAXX

#define qtdP 5

typedef struct 
{
	int x;
	int y;
}Ponto;

int main()
{
	Ponto p[qtdP];//p de pontos
	
	printf("Campos: x, y\n");
	int i;
	for(i = 0 ; i < qtdP ;i++ ){
		printf("\nInforme as coordernadas do ponto(%d): ", i+1);
		scanf("%d %d", &p[i].x, &p[i].y);
	}
	int menor_distancia_ao_quadrado = INT_MAX;//maior inteiro
	int ponto_mais_proximo = 1;
	
	int j;
	for(j = 0 ;j < qtdP ; j++){
		int distancia_ao_quadrado = ((p[i].x-p[0].x)*(p[i].x-p[0].x)+(p[i].y-p[0].y)*(p[i].y-p[0].y));
		
		if(distancia_ao_quadrado < menor_distancia_ao_quadrado){
			ponto_mais_proximo = i;
			menor_distancia_ao_quadrado = distancia_ao_quadrado;
		}	
	}
	printf("\nPonto mais proximo: (%d, %d)\n", p[ponto_mais_proximo].x, p[ponto_mais_proximo].y);
	return 0;
}
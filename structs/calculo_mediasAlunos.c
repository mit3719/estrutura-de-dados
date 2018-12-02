/**
 * Programa que cadastra o nome, matricula e 2 notas de varios alunos.
 * Em seguida imprima a matrícula, o nome e a média de cada um deles.
 */
#include <stdio.h>
#define QTD 3

typedef struct {
	int matricula;
	char nome[100];
	float nota1;
	float nota2;
}Aluno;

int main()
{
	Aluno alunos[QTD];
	int i;
	
	printf("Dados: nome, matricula, nota1, nota2\n");
	for(i = 0 ;i < QTD ;i++){
		printf("\nInforme os dados do aluno(%i): ", i+1);
		scanf("%s %i %f %f", alunos[i].nome, &alunos[i].matricula, &alunos[i].nota1, &alunos[i].nota2);
	}
	printf("\nMatricula\tNome\tMedia\n");
	for(i = 0 ;i < QTD ;i++)
	   	printf("%i\t%s\t%1.2f\n", alunos[i].matricula, alunos[i].nome, (alunos[i].nota1 + alunos[i].nota2)/2);
	
	return 0;
}
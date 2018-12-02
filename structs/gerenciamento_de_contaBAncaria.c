/**
 * Simulador de contas banc�rias, com as seguintes especifica��es
 * cada conta ter� o nome e o CPF do cliente associado a ela.
 * no ato da cria��o da conta o cliete precisar� fazer um dep�sito inicial.
 * Ap�s as contas serem criadas, o sistema dever� possibilitar realiza��es de saques ou dep�sitos nas contas.

Sempre que uma opera��o de saque ou dep�sito seja realizada, o sistema dever� imprimir o nome do titular e o saldo final da conta.

 */
#include <stdio.h>

#define QUANTIDADE_DE_CLIENTES 3
#define OPERACAO_SAQUE 1
#define OPERACAO_DEPOSITO 2

typedef struct  {
        char nome[256];
        long long cpf;
} Cliente;

typedef struct {
        long    numero_da_conta;
        long    cpf_do_cliente;
        double  saldo;
} Conta;

int main(){
  Cliente clientes[QUANTIDADE_DE_CLIENTES];
  Conta   contas[QUANTIDADE_DE_CLIENTES];

  printf("Campos: cpf nome deposito-inicial\n");
  long i;
  for(i=0; (i < QUANTIDADE_DE_CLIENTES); i++){
    printf("\nDados para abertura da conta(%ld): ",i+1);
    scanf("%Ld %s %lf",&clientes[i].cpf,clientes[i].nome,
      &contas[i].saldo);

    contas[i].numero_da_conta = i;
    contas[i].cpf_do_cliente = clientes[i].cpf;

    printf("\nCliente: %s Conta: %ld Saldo inicial: %1.2lf\n",
      clientes[i].nome, contas[i].numero_da_conta, contas[i].saldo);
  }

  int operacao; // como ainda n�o aprendemos a comparar strings,
                // vamos usar 'opera��o' como num�rico.
  long num_conta;
  double valor;
  int sair=0; // FALSE

  while (!sair){
    printf("\nInforme a opera��o: 1-Saque 2-Deposito 3-Sair: ");
    scanf("%d", &operacao);

    if (operacao == OPERACAO_SAQUE || operacao == OPERACAO_DEPOSITO){
      printf("\nInforme numero-da-conta e valor: ");
      scanf("%ld %lf", &num_conta, &valor);
      int i;
      for(i=0; (i < QUANTIDADE_DE_CLIENTES); i++){
        if (contas[i].numero_da_conta == num_conta) {
          if (operacao == OPERACAO_SAQUE){
            contas[i].saldo -= valor;
            printf("\nSAQUE: %1.2lf", valor);
          }
          if (operacao == OPERACAO_DEPOSITO){
            contas[i].saldo += valor;
            printf("\nDEPOSITO: %1.2lf", valor);
          }
          int j;
          for(j=0; j < QUANTIDADE_DE_CLIENTES; j++){
            if (clientes[j].cpf == contas[i].cpf_do_cliente)
              printf("\nCliente: %s Saldo atual: %1.2lf",
                clientes[j].nome, contas[i].saldo);
          }
        }
      }
    }else{
      sair = 1; // TRUE
    }
  }

  getchar();
  return 0;
}
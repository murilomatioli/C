/* Um banco está informatizando seu controle de clientes e contas. Num primeiro
momento o banco deseja guardar informações de no máximo 1000 clientes. Cada

cliente tem os seguintes dados: número do cliente, nome, idade, endereço, quan-
tidade de contas correntes. Cada cliente tem no máximo 5 contas correntes. As

informações de conta corrente são as seguintes: número do cliente, tempo em que
é cliente(em anos), saldo e número da conta.
Escreva um programa que leia as informações relacionadas a n clientes. Seu
algoritmo deve ler os dados até ser informado −1 no número do cliente. Após a
leitura dos dados, liste:
(a) os dados dos clientes e das contas para as contas com mais de 10 anos;
(b) os dados dos clientes que têm menos de 30 anos de idade;*/

#include <stdio.h>
#include <string.h>

typedef struct
{
    int id;
    int tempo;
    float saldo;
    int idConta;
} contaCorrente;

typedef struct
{
    int id;
    int idade;
    char nome[50];
    char endereco[100];
    contaCorrente contas[5];
} banco;

void cadastrarCliente(banco *clientes){
    clientes->id = 1;
    clientes->idade = 20;
    strcpy(clientes->nome, "murilo");
    strcpy(clientes->endereco, "Rua Euclides da Cunha 294, Nova Ilha");
    clientes->contas[0].id = 1;
    clientes->contas[0].tempo = 5;
    clientes->contas[0].saldo = 633.50;
    clientes->contas[0].idConta = 1;
}
void exibirCliente(banco *clientes) {
    // Exibir informações do cliente
    printf("Id cliente: %d\n", clientes->id);
    printf("Nome cliente: %s\n", clientes->nome);
    printf("Idade cliente: %d\n", clientes->idade);
    printf("Endereco cliente: %s\n", clientes->endereco);

    // Exibir informações da primeira conta associada ao cliente
    printf("\n--- Conta 1 ---\n");
    printf("Id da conta: %d\n", clientes->contas[0].id);
    printf("Tempo de existência: %d meses\n", clientes->contas[0].tempo);
    printf("Saldo da conta: %.2f\n", clientes->contas[0].saldo);
    printf("Id da conta corrente: %d\n", clientes->contas[0].idConta);
}

int main()
{
    banco clientes[1000];
    banco *Pclientes = &clientes[0];
    cadastrarCliente(Pclientes);
    exibirCliente(Pclientes);
    return 0;
}


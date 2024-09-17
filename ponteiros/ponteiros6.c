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

void cadastrarCliente(banco *clientes,int *PnumClientes){
    char nome[50], endereco[100];
    int idade;
    *PnumClientes +=1;
    int index = *PnumClientes - 1;
    clientes[index].id = *PnumClientes;
    printf("Informe a idade do cliente: ");
    scanf("%d", &idade);
    clientes[index].idade = idade;
    printf("Informe o nome do cliente: ");
    scanf(" %[^\n]", nome);
    printf("Informe o endereço do cliente: ");
    scanf(" %[^\n]", endereco);
    strcpy(clientes[index].nome, nome);
    strcpy(clientes[index].endereco, endereco);
    clientes[index].contas[0].id = 1;
    clientes[index].contas[0].tempo = 5;
    clientes[index].contas[0].saldo = 633.50;
    clientes[index].contas[0].idConta = 1;

}
void exibirCliente(banco *clientes, int *PnumClientes) {
    int localId = *PnumClientes - 1;
    // Exibir informações do cliente
    banco localClientes = clientes[localId];


    printf("Id cliente: %d\n", localClientes.id);
    printf("Nome cliente: %s\n", localClientes.nome);
    printf("Idade cliente: %d\n", localClientes.idade);
    printf("Endereco cliente: %s\n", localClientes.endereco);

    // Exibir informações da primeira conta associada ao cliente
    printf("\n--- Conta 1 ---\n");
    printf("Id da conta: %d\n", localClientes.contas[0].id);
    printf("Tempo de existência: %d meses\n", localClientes.contas[0].tempo);
    printf("Saldo da conta: %.2f\n", localClientes.contas[0].saldo);
    printf("Id da conta corrente: %d\n", localClientes.contas[0].idConta);

}

int main()
{
    int numClientes = 0;
    char op[2];
    int *PnumClientes = &numClientes;
    banco clientes[1000];
    banco *Pclientes = &clientes[0];
    int encerrar = 0;
    // 
    while(encerrar != -1){
        scanf("%s", op);
        if(strcmp("cadastrar", op) == 0){
            cadastrarCliente(Pclientes, PnumClientes);
        }
        if(strcmp("exibir", op) == 0){
            exibirCliente(Pclientes, PnumClientes);
        }
        if(strcmp("encerrar", op) == 0){
            encerrar = -1;
        }
    }
    printf("Numero de clientes: %d\n", *PnumClientes);
    
    return 0;
}


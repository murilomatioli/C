#include <stdio.h>
#include <string.h>

typedef struct
{
    int rga;
    char nome[50];
    float nota1;
    float nota2;
    float nota3;
} ficha;

void cadastrarAluno(ficha *aluno)
{
    scanf("%d %s %f %f %f", &aluno->rga, aluno->nome, &aluno->nota1, &aluno->nota2, &aluno->nota3);
}

int buscarRga(ficha *aluno, int idRga)
{
    int i;
    for(i = 0; i < 50;i++){
        if(aluno[i].rga == idRga){
            printf("Há um aluno com este RGA\n");       
            return i;
        }
    }
    printf("Não há ninguem com este RGA\n");
    return 0;
}

void removerAluno(ficha *aluno, int rga)
{
    int verif;
    verif = buscarRga(&aluno[0], rga);
    printf("\tAluno: '%s' removido\n", aluno[verif].nome);
    aluno[verif].rga = -1;
}

int main() {
    ficha alunos[50];
    char op[15];
    int index = 0, i, post, delet, update, get, fim, rga;
    do{
        printf("Escolha a operação [registrar, deletar, finalizar]: ");
        scanf("%s", op);
        post = strcmp(op, "registrar");
        fim = strcmp(op, "finalizar");
        delet = strcmp(op, "deletar");
        get = strcmp(op, "exibir");
        if(post == 0){
            printf("\tInforme os dados do aluno: ");
            cadastrarAluno(&alunos[index]);
            index++;
        }
        if(delet == 0){
            printf("\tInforme o RGA do aluno: ");
            scanf("%d", &rga);
            removerAluno(&alunos[0], rga);
            
        }
    }while(fim != 0);
    printf("Numero de alunos cadastrados: %d\n", index);
    for(i = 0; i < index; i++){
        if(alunos[i].rga > 0){
             printf("%d %s %.2f %.2f %.2f", alunos[i].rga, alunos[i].nome, alunos[i].nota1, alunos[i].nota2, alunos[i].nota3);    
            printf("\n");           
        }
    }


    return 0;
}
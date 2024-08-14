#include <stdio.h>
#include <string.h>

typedef struct
{
    int rga;
    char nome[50];
    float nota1;
    float nota2;
    float nota3;
    float media;
    int aprovado;
} ficha;

void cadastrarAluno(ficha *aluno)
{
    scanf("%d %s %f %f %f", &aluno->rga, aluno->nome, &aluno->nota1, &aluno->nota2, &aluno->nota3);
    aluno->media = (aluno->nota1 + aluno->nota2 + aluno->nota3) / 3;
    
    if(aluno->media >= 6.0){
        aluno->aprovado = 1;
    }else{
        aluno->aprovado = 0;
    }
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

float calcularMedia(ficha *aluno, int index){
    int countAp = 0, countRp = 0, i;
    float tdsAlunos = 0, smntAprovados = 0, smntReprovados = 0;
    for(i = 0; i < index; i++){
        if(aluno[i].rga > 0){
            tdsAlunos+=aluno[i].media;
            if(aluno[i].aprovado == 1){
                smntAprovados+=aluno[i].media;
                countAp++;
            }else{
                smntReprovados+=aluno[i].media;
                countRp++;
            }
        }
    }
    printf("\tMedia dos alunos aprovados: %.2f\n", smntAprovados / countAp);
    printf("\tMedia de todos os alunos: %.2f\n", tdsAlunos / index);
    printf("\tMedia dos alunos reprovados: %.2f\n", smntReprovados / countRp);
}

int main() {
    ficha alunos[50];
    char op[15];
    int index = 0, i, post, delet, update, get, fim, rga, aprovados = 0;
    do{
        printf("Escolha a operação [registrar, exibir, deletar, finalizar]: ");
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
            if(index <= 0){
                printf("Não há alunos cadastrados.\n");
            }else{
                printf("\tInforme o RGA do aluno: ");
                scanf("%d", &rga);
                removerAluno(&alunos[0], rga);
                index--;               
            }
        }
        if(get == 0){
            aprovados = 0;
            printf("\nNumero de alunos cadastrados: %d\n", index);
            calcularMedia(&alunos[0], index);
            for(i = 0; i < index; i++){
                if(alunos[i].rga > 0){
                    
                    if(alunos[i].aprovado == 1){
                        aprovados++;
                    }
                     printf("\t%d %s %.2f %.2f %.2f | Média: %.2f | Aprovado: %d", alunos[i].rga, alunos[i].nome, alunos[i].nota1, alunos[i].nota2, alunos[i].nota3, alunos[i].media, alunos[i].aprovado);    
                    printf("\n");           
                }
            }
            printf("\n");
        }
    }while(fim != 0);

    printf("Fim!");

    return 0;
}
#include <stdio.h>

typedef struct {
    int rga;
    char nome[50];
    float nota1;
    float nota2;
    float nota3;
    float media;
} ficha;

void cadastrarAluno(ficha *aluno){
    scanf("%d %s %f %f %f", &aluno->rga, aluno->nome, &aluno->nota1, &aluno->nota2, &aluno->nota3);
    aluno->media = (aluno->nota1 + aluno->nota2 + aluno->nota3) / 3;
}

int main() {
    ficha alunos[50];
    cadastrarAluno(&alunos[0]);
    printf("RGA: %d\nNOME: %s\nNOTA 1:%f\nNOTA 2: %f\nNOTA 3: %f\nMEDIA: %f", alunos[0].rga, alunos[0].nome, alunos[0].nota1, alunos[0].nota2, alunos[0].nota3, alunos[0].media);
    
    return 0;
}
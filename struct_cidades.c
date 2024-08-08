/*Escreva um algoritmo que leia informações de n cidades (nome, es-
tado e população). Ao final, liste todos as cidades do estado de Mato

Grosso do Sul e os dados da(s) cidade(s) que contém a maior po-
pulação. Considere n ≤ 1000.*/

#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[50];
    char estado[3];
    int pop;
} ficha;   

typedef struct
{
    char nomeM[50];
    char estadoM[3];
    int popM;
} fichaMaior;

int main() {
    ficha cidades[1000];
    fichaMaior maior;
    int i, n, mPop = 0;
    printf("Informe quantas cidades serão cadastradas: ");
    scanf("%d", &n);
    
    for(i = 0; i < n;i++){
        scanf("%s %s %d", cidades[i].nome, cidades[i].estado, &cidades[i].pop);
        if(cidades[i].pop > mPop){
            mPop = cidades[i].pop;
            strcpy(maior.nomeM, cidades[i].nome);
            strcpy(maior.estadoM, cidades[i].estado);
            maior.popM = cidades[i].pop;
        }
    }
     for(i = 0; i < n;i++){
        printf("%s %s %d\n", cidades[i].nome, cidades[i].estado, cidades[i].pop);
    }
    printf("Maior: %s %s %d", maior.nomeM, maior.estadoM, maior.popM);
    

    return 0;
}
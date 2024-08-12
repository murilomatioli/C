/*Escreva um programa que leia os dados de dois produtos (descrição, quantidade
em estoque, valor de venda) e depois mostre a descrição e o valor de venda dos
produtos em ordem decrescente da quantidade em estoque.*/

#include <stdio.h>

typedef struct {
    char desc[100];
    int qntd;
    float valor;
} ficha;

int main() {
    ficha produtos[2];
    int i;
    
    printf("Informe cadastre dois produtos, formato: QNTD || VALOR || DESCRICAO")
    for(i = 0; i < 2;i++){
        scanf("%d %f %[^\n]s", &produtos[i].qntd, &produtos[i].valor, produtos[i].desc);
    }

    if(produtos[0].qntd > produtos[1].qntd){
        for(i = 1; i >=0;i--){
            printf("%d %f %s", produtos[i].qntd, produtos[i].valor, produtos[i].desc);
            printf("\n");
        }  
    }else {
        for(i = 0; i < 2;i++){
            printf("%d %.2f %s", produtos[i].qntd, produtos[i].valor, produtos[i].desc);
            printf("\n");
        }
    }

    return 0;
}
/*Escreva um programa que leia uma data (dia, mês e ano) e mostre a próxima
data, isto é, a data que representa o dia seguinte à data fornecida. Não esqueça
dos anos bissextos. Lembre-se que um ano é bissexto se é divisível por 400 ou,
em caso negativo, se é divisível por 4 mas não por 100.*/

#include <stdio.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} data;
int eBissexto(int ano) {
    if(ano % 400 == 0){
        return 1; //é bissexto
    }else{
        if(ano % 4 == 0 && ano % 100 != 0){
            return 1; // é bissexto
        }else{
            return 0; //nao é bissexto
        }
    }
}
int diaSeguinte(data hoje){
    int limiteDia;
    data seguinte;
    seguinte.dia = hoje.dia;
    seguinte.mes = hoje.mes;
    seguinte.ano = hoje.ano;
    
    // printf("%d %d %d", hoje.dia, hoje.mes, hoje.ano);
    switch (hoje.mes) {
        case 1:
            limiteDia = 31;
            break;
        case 2:
            if(eBissexto(hoje.ano) == 1){
                limiteDia = 29;
            }else{
                limiteDia = 28;
            }
            break;
        case 3:
            limiteDia = 31;
            break;
        case 4:
            limiteDia = 30;
            break;
        case 5:
            limiteDia = 31;
            break;
        case 6:
            limiteDia = 30;
            break;
        case 7:
            limiteDia = 31;
            break;
        case 8:
            limiteDia = 31;
            break;
        case 9:
            limiteDia = 30;
            break;
        case 10:
            limiteDia = 31;
            break;
        case 11:
            limiteDia = 30;
            break;
        case 12: 
            limiteDia = 31;
            break;
        default:
            printf("Mes inválido\n");
            return 500;
            break;
    }
    seguinte.dia = seguinte.dia + 1;
    if(seguinte.dia > limiteDia){
        seguinte.dia = 1;
        seguinte.mes+=1;
    }
    if(seguinte.mes > 12){
        seguinte.mes = 1;
        seguinte.ano+=1;
    }
    printf("Dia seguinte: %d %d %d", seguinte.dia, seguinte.mes, seguinte.ano);
    
    return limiteDia;
}

int main() {
    data hoje;
    int aux;
    scanf("%d %d %d", &hoje.dia, &hoje.mes, &hoje.ano);
    
    if(diaSeguinte(hoje) == 500){
        printf("Erro.");
    }
    
    return 0;
}
#include <stdio.h>

void lerVetor(int tam,int *vetor){
    int i;
    for(i = 0; i < tam;i++){
        scanf("%d", (vetor + i));
        
    }
}
void imprimirVetor(int tam, int *vetor){
    int i;
    printf("Vetor: \n");

    for(i = 0; i < tam;i++){
        printf("%d ", *(vetor + i));
    }
}
void substituirValores(int tam, int *vetor){
    int i;
    for(i = 0; i < tam;i++){
        if(*(vetor + i) < 0){
            *(vetor + i) = 0;
        }
    }
}
int main()
{
    int tamanho;
    int vetor[50];
    int *Pvetor = &vetor[0];
    printf("Informe o tamanho do vetor: ");
    scanf("%d", &tamanho);

    lerVetor(tamanho, Pvetor);
    imprimirVetor(tamanho, Pvetor);
    substituirValores(tamanho, Pvetor);
    imprimirVetor(tamanho, Pvetor);

    return 0;
}

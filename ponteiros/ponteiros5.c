#include <stdio.h>

void multiplicarVetor(int *vetor, int tam){
    int i, mult;
    printf("Informe o multiplicador: ");
    scanf("%d", &mult);

    for(i = 0; i < tam;i++){
        *(vetor + i)*=mult;
    }
}
void imprimeVetor(int *vetor, int tam){
    int i;
    printf("Vetor: \n");
    for(i = 0; i < tam;i++){
        printf("%d ", *(vetor + i));
    }
}
void lerVetor(int *vetor, int tam){
    int i;
    for(i = 0; i < tam;i++){
        scanf("%d", (vetor + i));
    }
}


int main()
{
    int vetor[50], tamanho;
    int *Pvetor = &vetor[0];

    printf("Informe o tamanho do vetor: ");
    scanf("%d", &tamanho);
    lerVetor(Pvetor, tamanho);
    multiplicarVetor(Pvetor, tamanho);
    imprimeVetor(Pvetor, tamanho);

    return 0;
}

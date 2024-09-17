#include <stdio.h>

void imprimeVetor(int *vetor){
    int i;
    for(i = 0; i < 5;i++){
        printf("%d ", *(vetor + i));
    }
    printf("\n");
}

int main()
{
    int vetor[] = {1, 2, 10, 4, 5};
    int *Pvetor = &vetor[0];
    imprimeVetor(Pvetor);


    return 0;
}

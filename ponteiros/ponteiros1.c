#include <stdio.h>

int main()
{
    int x = 10; // cria variavel
    int *Px = &x; //cria um ponteiro que aponta para o endereço da variavel

    printf("Valor apontado: %d\n", *Px);
    printf("Endereço apontado: %p\n", Px);
    return 0;
}


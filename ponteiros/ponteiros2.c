#include <stdio.h>

int somar10(int valor){
    valor+=10;
    return valor;
}

int main()
{
    int x = 50;
    int *Px = &x;

    int resultado = somar10(*Px); //aplica o valor de x ao somar10
    printf("Resultado: %d\n", resultado);

    return 0;
}


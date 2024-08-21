#include <stdio.h>

float DIV(int x, int y)
{   
    printf("\tDIV: %d, %d\n", x, y);
    if(x < y){
        return 0;
    }else if(x == y){
        return 1;
    }else{
        return 1 + DIV(x - y, y);
    }
}

int main() {
    int x, y;
    printf("Informe x e y: ");
    scanf("%d %d", &x, &y);
    printf("\nDIV(%d, %d) = %.2f", x, y, DIV(x, y));
    return 0;
}
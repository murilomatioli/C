
#include <stdio.h>
void printTab(int tab)
{
    int i;
    for(i = 0; i < tab;i++){
        printf("\t");
    }
}

int h(int m, int n, int ntab)
{
    printf("\n");
    printTab(ntab);
    
    printf("h(%d, %d)", m, n);
    
    if(n == 1){
        return m + 1;
    }else if(m == 1){
        return n + 1;
    }else {
        return h(m, n - 1, ntab + 1) + h(m - 1, n, ntab + 1);
    }
}


int main() {
    int m, n;
    m = 4;
    n = 3;
    printf("\nh(%d, %d) = %d", m, n, h(m, n, 0));
    return 0;
}
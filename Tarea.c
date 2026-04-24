#include <stdio.h>
#define lim 5

int main() 
{
    int n1, n2, i;
    int v1[lim], v2[lim], v3[2*lim];
    printf("\nIngresa los elementos del vector 1:\n");
    for(i = 0; i < lim; i++) 
    { 
  
        scanf("%d",&n1;
    }

    // Leer vector 2
    printf("\nIngresa los elementos del vector 2:\n");
    for(i = 0; i < n2; i++) 
    {
        printf("v2[%d]: ", i);
        scanf("%d", &v2[i]);
    }

    // Copiar v1 a v3
    for(i = 0; i < n1; i++) 
    {
        v3[i] = v1[i];
    }

    // Copiar v2 a v3
    for(i = 0; i < n2; i++) {
        v3[n1 + i] = v2[i];
    }

    // Mostrar resultado
    printf("\nVector combinado:\n");
    for(i = 0; i < n1 + n2; i++) {
        printf("%d ", v3[i]);
    }

    return 0;
}

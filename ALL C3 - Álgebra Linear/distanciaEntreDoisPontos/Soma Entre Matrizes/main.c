#include <stdio.h>
#include <stdlib.h>

int main(){

    printf ("Digite o tamanho das matrizes que deseja somar: ");

    int m, n;
    scanf ("%d %d", &m, &n);

    printf ("\n");
    printf ("Digite os valores da matriz A:\n");

    int matriz_a[m][n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf ("%d", &matriz_a[i][j]);

    printf ("Digite os valores da matriz B:\n");

    int matriz_b[m][n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf ("%d", &matriz_b[i][j]);

    printf ("\n\n");
    printf ("Matriz Resultante:\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            printf ("%d%s", (matriz_a[i][j] + matriz_b[i][j]), j+1 != n ? " ":"\n");

    return 0;

}

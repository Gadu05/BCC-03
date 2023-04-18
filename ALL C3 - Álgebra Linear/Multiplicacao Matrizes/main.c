#include <stdio.h>
#include <stdlib.h>

int main(){

    printf ("Digite o tamanho da matriz A: ");

    int m, n;
    scanf ("%d %d", &m, &n);

    printf ("Digite a matriz A:\n");
    int matrizA[m][n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf ("%d", &matrizA[i][j]);

    printf ("Digite o tamanho da matriz B: ");

    int o, p;
    scanf ("%d %d", &o, &p);

    printf ("Digite a matriz B:\n");
    int matrizB[o][p];
    for (int i = 0; i < o; i++)
        for (int j = 0; j < p; j++)
            scanf ("%d", &matrizB[i][j]);

    if (m != p){
        printf ("\n\nEssas matrizes nao podem ser multiplicadas!");
        return 0;
    }

    int matriz_Resultado[m][p];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++)
            matriz_Resultado[i][j] = 0;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++)
            for (int x = 0; x < m; x++)
                matriz_Resultado[i][j] += matrizA[i][x] * matrizB[x][j];

    printf ("\nMatriz Resultante:\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++)
            printf ("%d%s", matriz_Resultado[i][j], j+1 != p ? " ":"\n");

    return 0;

}

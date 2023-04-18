#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese");

    printf ("Digite o número de variáveis: ");

    int n;
    scanf ("%d", &n);

    double matriz[n][n+1];
    double solucao[n];

    for (int i = 0; i < n; i++){

        printf ("\nDigite os valores da %dª equação: \n", i+1);

        for (int j = 0; j < n; j++){
            scanf ("%lf", &matriz[i][j]);
            fflush(stdin);
        }

        printf ("\nDigite o resultado desta equação: \n");
        scanf ("%lf", &matriz[i][n]);
        fflush(stdin);

    }

    for (int x = 0; x < n; x++){

        int linha_pivo = x;
        for (int i = x+1; i < n; i++)
            if (abs(matriz[i][x]) > abs(matriz[linha_pivo][x]))
                linha_pivo = i;

        if (linha_pivo != x){
            for (int j = x; j <= n; j++){

                double aux;

                aux = matriz[x][j];
                matriz[x][j] = matriz[linha_pivo][j];
                matriz[linha_pivo][j] = aux;

            }
        }

        for (int i = x+1; i < n; i++){

            double m = -matriz[i][x] / matriz[x][x];

            for (int j = x; j <= n; j++)
                matriz[i][j] += m * matriz[x][j];

        }

    }

    for (int i = n-1; i >= 0; i--){

        solucao[i] = matriz[i][n];

        for (int j = i+1; j < n; j++)
            solucao[i] -= matriz[i][j] * solucao[j];

        solucao[i] /= matriz[i][i];

    }

    printf ("\n\nSolução: {");
    for (int i = 0; i < n; i++)
        printf ("%.10lf%s", solucao[i], i != n-1 ? "; ":"}\n");

    return 0;

}

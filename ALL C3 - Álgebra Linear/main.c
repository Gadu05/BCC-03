#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

double distahciaAB(double pI[], double pF[], int dimensao);

int main(){

    setlocale(LC_ALL, "Portuguese");

    int dimensao;
    printf("Digite a dimensão dos pontos: ");
    scanf("%d", &dimensao);

    fflush(stdin);

    if (dimensao <= 0){
        printf("Digite uma dimensão válida.\n");
        getchar();
        return 0;
    }

    double pA[dimensao];
    printf("Digite as coordenadas do ponto A: ");
    for (int i = 0; i < dimensao; i++)
        scanf("%lf", &pA[i]);

    fflush(stdin);

    double pB[dimensao];
    printf("Digite as coordenadas do ponto B: ");
    for (int i = 0; i < dimensao; i++)
        scanf("%lf", &pB[i]);

    fflush(stdin);

    printf("A distância entre os pontos é de aproximadamente ");
    printf("%.2lf\n", distahciaAB(pA, pB, dimensao));

    getchar();
    return 0;

}

double distahciaAB(double *pI, double *pF, int dimensao){

    float soma = 0;
    for (int i = 0; i < dimensao; i++)
        soma += pow( (pF[i] - pI[i]), 2 );

    return sqrt(soma);

}

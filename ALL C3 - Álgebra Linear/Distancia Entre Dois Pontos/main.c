#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double distanciaAB(double pI[], double pF[], int d);

int main(){

    printf ("Digite a dimensao dos pontos: ");

    int dimensao;
    scanf ("%d", &dimensao);

    printf ("\n");
    printf ("Digite as coordenadas do ponto A: ");

    double pA[dimensao];
    for (int i = 0; i < dimensao; i++)
        scanf ("%lf", &pA[i]);

    printf ("Digite as coordenadas do ponto B: ");

    double pB[dimensao];
    for (int i = 0; i < dimensao; i++)
        scanf ("%lf", &pB[i]);

    printf ("\n");
    printf ("A distancia entre os dois pontos e de aproximadamente ");
    printf ("%.2lf\n", distanciaAB(pA, pB, dimensao));

}

double distanciaAB(double pI[], double pF[], int d){

    double soma = 0;

    for (int i = 0; i < d; i++)
        soma += pow( pF[i] - pI[i], 2 );

    return sqrt (soma);

}

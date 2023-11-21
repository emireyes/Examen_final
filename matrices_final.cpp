#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 50

void llenarMatriz(int matriz[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            matriz[i][j] = rand() % 10;
        }
    }
}

void imprimirMatriz(int matriz[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void multiplicarMatrices(int matrizA[N][N], int matrizB[N][N], int resultado[N][N]) {
    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            resultado[i][j] = 0;
            for (k = 0; k < N; k++) {
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
}

double medirTiempoMultiplicacion(int matrizA[N][N], int matrizB[N][N], int resultado[N][N], int iteraciones) {
    clock_t inicio = clock();
    for (int i = 0; i < iteraciones; ++i) {
        multiplicarMatrices(matrizA, matrizB, resultado);
    }
    clock_t fin = clock();

    return ((double)(fin - inicio)) / CLOCKS_PER_SEC * 1000.0 / iteraciones;
}

int main() {
    int matrizA[N][N];
    int matrizB[N][N];
    int resultado[N][N];

    srand(time(NULL));
    llenarMatriz(matrizA);
    llenarMatriz(matrizB);

    printf("Matriz A:\n");
    imprimirMatriz(matrizA);
    printf("Matriz B:\n");
    imprimirMatriz(matrizB);

    int iteraciones = 1000;  // Puedes ajustar el número de iteraciones según sea necesario
    double tiempoEjecucion = medirTiempoMultiplicacion(matrizA, matrizB, resultado, iteraciones);

    printf("Resultado de la multiplicacion:\n");
    imprimirMatriz(resultado);

    printf("Tiempo de ejecucion promedio de %d iteraciones: %.2f milisegundos\n", iteraciones, tiempoEjecucion);

    return 0;
}


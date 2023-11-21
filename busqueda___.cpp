#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int busquedaSecuencial(int arr[], int n, int objetivo) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == objetivo) {
            return i;  
        }
    }
    return -1;  
}

int busquedaBinaria(int arr[], int bajo, int alto, int objetivo) {
    while (bajo <= alto) {
        int medio = bajo + (alto - bajo) / 2;

        if (arr[medio] == objetivo) {
            return medio; 
        }

        if (arr[medio] < objetivo) {
            bajo = medio + 1;
        } else {
            alto = medio - 1;
        }
    }
    return -1;  
}

int main() {
    srand(time(NULL));

    int n = 50000;
    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }

    struct timespec inicio_secuencial, fin_secuencial, inicio_binaria, fin_binaria;
    double total_secuencial = 0;
    double min_secuencial = 999999999;
    double max_secuencial = 0;
    double total_binaria = 0;
    double min_binaria = 999999999;
    double max_binaria = 0;

    printf("Busqueda Secuencial:\n");
    for (int j = 0; j < 100; j++) {
        int objetivo_secuencial = arr[rand() % n];

        clock_gettime(CLOCK_MONOTONIC, &inicio_secuencial);
        busquedaSecuencial(arr, n, objetivo_secuencial);
        clock_gettime(CLOCK_MONOTONIC, &fin_secuencial);

        double tiempo_secuencial = (fin_secuencial.tv_sec - inicio_secuencial.tv_sec) * 1000.0; 
        tiempo_secuencial += (fin_secuencial.tv_nsec - inicio_secuencial.tv_nsec) / 1000000.0; 
        total_secuencial += tiempo_secuencial;

        if (tiempo_secuencial < min_secuencial) {
            min_secuencial = tiempo_secuencial;
        }
        if (tiempo_secuencial > max_secuencial) {
            max_secuencial = tiempo_secuencial;
        }
    }

    double promedio_secuencial = total_secuencial / 100;

    printf("Tiempo promedio: %f ms\n", promedio_secuencial);
    printf("Tiempo minimo: %f ms\n", min_secuencial);
    printf("Tiempo maximo: %f ms\n", max_secuencial);

    printf("\nBusqueda Binaria:\n");
    for (int k = 0; k < 100; k++) {
        int objetivo_binaria = arr[rand() % n];

        clock_gettime(CLOCK_MONOTONIC, &inicio_binaria);
        busquedaBinaria(arr, 0, n - 1, objetivo_binaria);
        clock_gettime(CLOCK_MONOTONIC, &fin_binaria);

        double tiempo_binaria = (fin_binaria.tv_sec - inicio_binaria.tv_sec) * 1000.0; 
        tiempo_binaria += (fin_binaria.tv_nsec - inicio_binaria.tv_nsec) / 1000000.0; 
        total_binaria += tiempo_binaria;

        if (tiempo_binaria < min_binaria) {
            min_binaria = tiempo_binaria;
        }
        if (tiempo_binaria > max_binaria) {
            max_binaria = tiempo_binaria;
        }
    }

    double promedio_binaria = total_binaria / 100;

    printf("Tiempo promedio: %f ms\n", promedio_binaria);
    printf("Tiempo minimo: %f ms\n", min_binaria);
    printf("Tiempo maximo: %f ms\n", max_binaria);

    return 0;
}


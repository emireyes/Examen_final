#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int busqueda_secuencial(int arr[], int n, int x) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

int busqueda_binaria(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int n = 50000;
    int arr[n];
    int i;
    for (i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    double total_time_secuencial = 0, total_time_binaria = 0;
    double tiempos_secuencial[100], tiempos_binaria[100];

    printf("Busqueda Secuencial\n");
    for (i = 0; i < 100; i++) {
        clock_t start_time = clock();
        int num = rand() % n + 1;
        int found_index = busqueda_secuencial(arr, n, num);
        clock_t end_time = clock();
        double elapsed_time = ((double)(end_time - start_time)) * 1000 / CLOCKS_PER_SEC;
        total_time_secuencial += elapsed_time;
        tiempos_secuencial[i] = elapsed_time;
        printf("Numero: %d Encontrado en posicion: %d Tiempo: %lf ms\n", num, found_index, elapsed_time);
    }

    printf("\nBusqueda Binaria\n");
    for (i = 0; i < 100; i++) {
        clock_t start_time = clock();
        int num = rand() % n + 1;
        int found_index = busqueda_binaria(arr, n, num);
        clock_t end_time = clock();
        double elapsed_time = ((double)(end_time - start_time)) * 1000 / CLOCKS_PER_SEC;
        total_time_binaria += elapsed_time;
        tiempos_binaria[i] = elapsed_time;
        printf("Numero: %d Encontrado en posicion: %d Tiempo: %lf ms\n", num, found_index, elapsed_time);
    }

    double promedio_secuencial = total_time_secuencial / 100;
    double promedio_binaria = total_time_binaria / 100;

    double min_secuencial = tiempos_secuencial[0];
    double max_secuencial = tiempos_secuencial[0];
    double min_binaria = tiempos_binaria[0];
    double max_binaria = tiempos_binaria[0];

    for (i = 1; i < 100; i++) {
        if (tiempos_secuencial[i] < min_secuencial)
            min_secuencial = tiempos_secuencial[i];
        if (tiempos_secuencial[i] > max_secuencial)
            max_secuencial = tiempos_secuencial[i];
        if (tiempos_binaria[i] < min_binaria)
            min_binaria = tiempos_binaria[i];
        if (tiempos_binaria[i] > max_binaria)
            max_binaria = tiempos_binaria[i];
    }

    printf("\nTiempo promedio de busqueda secuencial: %lf ms\n", promedio_secuencial);
    printf("Tiempo promedio de busqueda binaria: %lf ms\n", promedio_binaria);
    printf("Tiempo minimo de busqueda secuencial: %lf ms\n", min_secuencial);
    printf("Tiempo maximo de busqueda secuencial: %lf ms\n", max_secuencial);
    printf("Tiempo minimo de busqueda binaria: %lf ms\n", min_binaria);
    printf("Tiempo maximo de busqueda binaria: %lf ms\n", max_binaria);

    return 0;
}


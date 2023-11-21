#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }

        swap(&arr[i + 1], &arr[high]);

        quicksort(arr, low, i);
        quicksort(arr, i + 2, high);
    }
}

void bubblesort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void insertionsort(int arr[], int size) {
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}


double get_seconds() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (double)ts.tv_sec + (double)ts.tv_nsec / 1e9;
}

int main() {
    const int size = 10000;
    int arr[size];
    srand(time(NULL));

    printf("Arreglo original:\n");
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000;
        printf("%d ", arr[i]);
    }
    printf("\n\n");


    double quicksort_times[100];
    double quicksort_avg_time = 0.0;
    double quicksort_min_time = 1.0;  
    double quicksort_max_time = 0.0;

    int temp_arr[size];  

    for (int run = 0; run < 100; run++) {
        for (int j = 0; j < size; j++) {
            temp_arr[j] = arr[j];
        }

        double start = get_seconds();
        quicksort(temp_arr, 0, size - 1);
        double end = get_seconds();

        double cpu_time_used = end - start;
        quicksort_times[run] = cpu_time_used;

        quicksort_avg_time += cpu_time_used;

        if (cpu_time_used < quicksort_min_time) {
            quicksort_min_time = cpu_time_used;
        }

        if (cpu_time_used > quicksort_max_time) {
            quicksort_max_time = cpu_time_used;
        }

        printf("Quicksort time %d: %.4f seconds\n", run + 1, cpu_time_used);
    }

    quicksort_avg_time /= 100.0;

    printf("\nQuicksort Summary:\n");
    printf("Average Time: %.4f seconds\n", quicksort_avg_time);
    printf("Minimum Time: %.4f seconds\n", quicksort_min_time);
    printf("Maximum Time: %.4f seconds\n", quicksort_max_time);

 
    printf("\nArreglo ordenado:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", temp_arr[i]);
    }
    printf("\n");


    printf("\n------------------------\n");

   
    double bubblesort_times[100];
    double bubblesort_avg_time = 0.0;
    double bubblesort_min_time = 1.0;
    double bubblesort_max_time = 0.0;

    for (int run = 0; run < 100; run++) {
        for (int j = 0; j < size; j++) {
            temp_arr[j] = arr[j];
        }

        double start = get_seconds();
        bubblesort(temp_arr, size);
        double end = get_seconds();

        double cpu_time_used = end - start;
        bubblesort_times[run] = cpu_time_used;

        bubblesort_avg_time += cpu_time_used;

        if (cpu_time_used < bubblesort_min_time) {
            bubblesort_min_time = cpu_time_used;
        }

        if (cpu_time_used > bubblesort_max_time) {
            bubblesort_max_time = cpu_time_used;
        }

        printf("Bubblesort time %d: %.4f seconds\n", run + 1, cpu_time_used);
    }

    bubblesort_avg_time /= 100.0;

    printf("\nBubblesort Summary:\n");
    printf("Average Time: %.4f seconds\n", bubblesort_avg_time);
    printf("Minimum Time: %.4f seconds\n", bubblesort_min_time);
    printf("Maximum Time: %.4f seconds\n", bubblesort_max_time);

  
    printf("\nArreglo ordenado (Bubblesort):\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", temp_arr[i]);
    }
    printf("\n");


    printf("\n------------------------\n");

  
    double insertionsort_times[100];
    double insertionsort_avg_time = 0.0;
    double insertionsort_min_time = 1.0;
    double insertionsort_max_time = 0.0;

    for (int run = 0; run < 100; run++) {
        for (int j = 0; j < size; j++) {
            temp_arr[j] = arr[j];
        }

        double start = get_seconds();
        insertionsort(temp_arr, size);
        double end = get_seconds();

        double cpu_time_used = end - start;
        insertionsort_times[run] = cpu_time_used;

        insertionsort_avg_time += cpu_time_used;

        if (cpu_time_used < insertionsort_min_time) {
            insertionsort_min_time = cpu_time_used;
        }

        if (cpu_time_used > insertionsort_max_time) {
            insertionsort_max_time = cpu_time_used;
        }

        printf("Insertionsort time %d: %.4f seconds\n", run + 1, cpu_time_used);
    }

    insertionsort_avg_time /= 100.0;

    printf("\nInsertionsort Summary:\n");
    printf("Average Time: %.4f seconds\n", insertionsort_avg_time);
    printf("Minimum Time: %.4f seconds\n", insertionsort_min_time);
    printf("Maximum Time: %.4f seconds\n", insertionsort_max_time);

  
    printf("\nArreglo ordenado (Insertionsort):\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", temp_arr[i]);
    }
    printf("\n");

    return 0;
}

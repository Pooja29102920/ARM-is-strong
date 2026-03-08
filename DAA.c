#include <stdio.h>
#include <math.h>

void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(double arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] < arr[i]) {
        largest = l;
    }
    if (r < n && arr[r] < arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(double arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    // System Initialization
    int m, n;
    double l, h, alpha, beta, k;

    printf("Enter number of cores (M): ");
    scanf("%d", &m);
    printf("Enter number of tasks (N): ");
    scanf("%d", &n);

    double tasks[n];
    printf("Enter %d task compute units:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &tasks[i]);
    }

    printf("Enter hardware limits L and H: ");
    scanf("%lf %lf", &l, &h);
    printf("Enter alpha and beta parameters: ");
    scanf("%lf %lf", &alpha, &beta);
    printf("Enter power constant K: ");
    scanf("%lf", &k);

    // Frequency Optimization Phase
    double f_ideal = 1.0 / alpha;
    double f_final = f_ideal;
    if (f_final < l) {
        f_final = l;
    }
    if (f_final > h) {
        f_final = h;
    }

    // Task Pre-Processing Phase
    heapSort(tasks, n);

    // Greedy Scheduling Phase (LPT)
    double core_loads[m];
    for (int i = 0; i < m; i++) {
        core_loads[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int min_idx = 0;
        for (int j = 1; j < m; j++) {
            if (core_loads[j] < core_loads[min_idx]) {
                min_idx = j;
            }
        }
        core_loads[min_idx] += tasks[i];
    }

    // Performance Calculations
    double max_load = 0;
    for (int i = 0; i < m; i++) {
        if (core_loads[i] > max_load) {
            max_load = core_loads[i];
        }
    }

    double execution_time = max_load / (beta * f_final);
    double power = k * exp(alpha * f_final);
    double total_energy = m * power * execution_time;

    // Output Results
    printf("\n--- Core Conqueror 9000 Report ---\n");
    printf("Selected Frequency: %.2f GHz\n", f_final);
    printf("Total Makespan: %.2f seconds\n", execution_time);
    printf("Total Energy used: %.2f Joules\n", total_energy);

    return 0;
}


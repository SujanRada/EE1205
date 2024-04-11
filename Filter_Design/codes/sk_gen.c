#include <stdio.h>
#include <math.h>
#include <complex.h>

#define N 4
#define EPSILON 0.4
#define OMEGA_LP 1
#define PI 3.14159265358979323846

int main() {
    // Calculate B_k coefficient
    double B_k = asinh(1 / EPSILON) / N;

    // Initialize an array to store the poles
    double complex poles[2*N];

    // Calculate poles
    for (int k = 0; k < N; ++k) {
        double A_k = PI * (2*k + 1) / (2 * N);
        poles[k] = sinh(B_k) * sin(A_k) - I * cosh(B_k) * cos(A_k);
        poles[k + N] = -sinh(B_k) * sin(A_k) - I * cosh(B_k) * cos(A_k);
    }

    // Save poles to a .dat file
    FILE *file = fopen("poles.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    fprintf(file, "Real Part, Imaginary Part\n");
    for (int i = 0; i < 2*N; ++i) {
        fprintf(file, "%.4f, %.4f\n", creal(poles[i]), cimag(poles[i]));
    }
    fclose(file);

    printf("Poles saved to poles.txt file.\n");

    return 0;
}


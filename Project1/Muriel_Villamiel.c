#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdint.h>
#include <time.h>



int main() {

	int nExp;
	int nVal = 1;
	float A = 2.0f;
	float *X, *Y, *Z;

	printf("Enter the exponent of 2: ");
	if (scanf_s("%d", &nExp) != 1) {
		printf("Invalid input. Please enter an integer.\n");
		return 1; // Exiting due to invalid input
	}

	for (int j = 0; j < nExp; j++) {
		 nVal*= 2;
	}

	printf("value %d \n", nVal);

	X = (float*)malloc(nVal * sizeof(float));
	Y = (float*)malloc(nVal * sizeof(float));
	Z = (float*)malloc(nVal * sizeof(float));

	for (int i = 0; i < nVal; ++i) {
		if (i == 0) {
			X[i] = 1.0f;
			Y[i] = 11.0f;
		}

		if (i > 0) {
			X[i] = 1.0f + X[i - 1];
			Y[i] = 1.0f + Y[i - 1];
		}
	}

	clock_t start = clock();
	for (int i = 0; i < nVal; ++i) {
		Z[i] = (A * X[i]) + Y[i];
	}
	clock_t end = clock();
	double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

	printf("Result:\n");
	for (int i = 0; i < 10; ++i) {
		printf("%.2f ", Z[i]);
	}
	printf("\nExecution time: %f seconds\n", cpu_time_used);
	return 0;
}
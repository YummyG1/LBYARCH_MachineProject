#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdint.h>
#include <time.h>

extern float asmfunc(float A, float X, float Y);

void saxpy_c(float A, float X[], float Y[], float Z[], int n) {
	for (int i = 0; i < n; ++i) {
		Z[i] = (A * X[i]) + Y[i];
	}
}


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

	printf("Value of vectors: %d \n", nVal);

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
	saxpy_c(A, X, Y, Z, nVal);
	clock_t end = clock();
	double cpu_time_usedC = ((double)(end - start)) / CLOCKS_PER_SEC;

	printf("\nResult of C:\n");
	for (int i = 0; i < 10; ++i) {
		printf("%.2f ", Z[i]);
	}
	printf("\nExecution time of C: %f seconds\n", cpu_time_usedC);

	start = clock();
	for (int i = 0; i < nVal; ++i) {
		Z[i] = asmfunc(A, X[i], Y[i]);
	}
	end = clock();
	double cpu_time_usedASM = ((double)(end - start)) / CLOCKS_PER_SEC;

	printf("\nResult of ASM:\n");
	for (int i = 0; i < 10; ++i) {
		printf("%.2f ", Z[i]);
	}
	printf("\nExecution time of ASM: %f seconds\n", cpu_time_usedASM);




	// Free the dynamically allocated memory when done
	free(X);
	free(Y);
	free(Z);

	return 0;
}
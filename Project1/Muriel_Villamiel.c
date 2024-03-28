#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdint.h>
#include <time.h>

#define N 1073741823

extern void asmhello();

void saxpy_c(float A, float X[], float Y[], float Z[], int n) {
	for (int i = 0; i < n; ++i) {
		Z[i] = A * X[i] + Y[i];
	}
}


int main() {
	asmhello();

	int nExp;
	printf("Enter the exponent of 2: ");
	if (scanf_s("%d", &nExp) != 1) {
		printf("Invalid input. Please enter an integer.\n");
		return 1; // Exiting due to invalid input
	}
	int nVal = 1;
	for (int j = 0; j < nExp; j++) {
		 nVal*= 2;
	}

	printf("value %d", nVal);

	float A = 2.0f;
	float X[N], Y[N], Z[N];

	for (int i = 0; i < nVal; ++i) {
		X[i] = (float)rand() / RAND_MAX;
		Y[i] = (float)rand() / RAND_MAX;
	}

	saxpy_c(A, X, Y, Z, nVal);

	printf("Result:\n");
	for (int i = 0; i < 10; ++i) {
		printf("%.2f ", Z[i]);
	}
	printf("\n");

	return 0;
}
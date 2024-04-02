#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern float asmfunc(float A, float X, float Y);

void saxpy_c(float A, float X[], float Y[], float Z[], int n) {
	for (int i = 0; i < n; i++) {
		Z[i] = A * X[i] + Y[i];
	}
}


int main() {

	int nExp;
	int nVal = 1;
	float A = 2.0f;
	float *X, *Y, *Z;
	double cpu_time_usedC = 0;
	double cpu_time_usedC_overall = 0;
	double cpu_time_usedASM = 0;
	double cpu_time_usedASM_overall = 0;
	double cpu_time_used_C_avg = 0;
	double cpu_time_used_ASM_avg = 0;

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
		X[i] = 1.0f + i;
		Y[i] = 11.0f + i;
	}

	for (int i = 0; i < 30; i++)
	{
		clock_t start = clock();
			saxpy_c(A, X, Y, Z, nVal);
		clock_t end = clock();

		cpu_time_usedC = ((double)(end - start)) / CLOCKS_PER_SEC;
		cpu_time_usedC_overall += cpu_time_usedC;

	}

	cpu_time_used_C_avg = cpu_time_usedC_overall / 30;

	printf("\nFirst 10 results in C:\n");
	for (int i = 0; i < 10; ++i) 
	{
		printf("%.2f ", Z[i]);
	}

	printf("\nOverall execution time in C with a vector size of 2^%d: %f seconds\n", nExp, cpu_time_usedC_overall);
	printf("Average execution time in C: %f", cpu_time_used_C_avg);

	for (int i = 0; i < 30; i++) 
	{
		clock_t start = clock();
		for (int i = 0; i < nVal; i++) {
			Z[i] = asmfunc(A, X[i], Y[i]);
		clock_t end = clock();
		cpu_time_usedASM = ((double)(end - start)) / CLOCKS_PER_SEC;
		cpu_time_usedASM_overall += cpu_time_usedASM;

	}
	printf("\n");
	printf("\nFirst 10 results in ASM:\n");
	for (int i = 0; i < 10; ++i) {
		printf("%.2f ", Z[i]);
	}
	
	cpu_time_used_ASM_avg = cpu_time_usedASM_overall / 30;

	printf("\nOverall execution time in ASM with a vector size of 2^%d: %f seconds\n", nExp, cpu_time_usedASM_overall);
	printf("Average execution time in ASM: %f", cpu_time_used_ASM_avg);

	free(X);
	free(Y);
	free(Z);

	// Free the dynamically allocated memory when done


	return 0;
}
# LBYARCH MP#2 - DAXPY(A*X+Y)

Performed by Gabriel Muriel & Denis Leeroi Villamiel of LBYARCH S13

## Problem specifications:

Write the kernel in (1) C program and (2) an x86-64 assembly language.  The kernel is to perform SAXPY (A*X + Y) function.

*Required to use functional scalar SIMD registers

*Required to use functional scalar SIMD floating-point instructions

Input: Scalar variable n (integer) contains the length of the vector;  Scalar variable A is a single-precision float. Vectors X, Y and Z are single-precision float.

Process:  
Example:

A --> 2.0

x -> 1.0, 2.0, 3.0

y -> 11.0, 12.0, 13.0

(answer) z--> 13.0, 16.0, 19.0

Output: store result in vector Z.  Display the result of 1st ten elements of vector Z for all versions of kernel (i.e., C and x86-64).

## Repository Directory

Project1 - the main folder where the C and ASM source files are stored

asmfunc.asm - the file which includes the assembly code and logic; the callee

Muriel_Villamiel.c - the file that includes the C code; the caller

## Correctness/Sanity Check

*Note: The basis for the sanity check is the results from C

![correctness check](https://github.com/YummyG1/LBYARCH_MachineProject/assets/92982389/65507286-9f19-4f71-b5d2-866b8367908a)

## Debug vs. Release Mode - Execution Time Performance

### Debug Execution Time

| Vector Size |    C   |  x86-64  |
| ----------- | ------ | :------- |
| 2^20   | 0.002633 | 0.002667 |
| 2^24   | 0.043200 | 0.043067 |
| 2^28   | 0.682200 | 0.688167 |

### Release Execution Time

| Vector Size |    C   |  x86-64  |
| ----------- | ------ | :------- |
| 2^20   | 0.000167 | 0.001533 |
| 2^24   | 0.008300 | 0.024933 |
| 2^28   | 0.142033 | 0.399700 |

The primary finding that can be observed from the data above is that the execution times of the SAXPY function tend to be quicker in Release mode compared to Debug mode. Notably, across all results, the C kernel consistently demonstrates faster performance in every execution. This outcome is surprising, as it was initially anticipated that Assembly code, being a lower-level language than C, would show faster execution times for the SAXPY function. However, our data does not support this expectation.

## Sample Full Output

![example](https://github.com/YummyG1/LBYARCH_MachineProject/assets/92982389/3a99622b-3c3c-42af-bf68-1ac035648e42)




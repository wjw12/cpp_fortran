#include <iostream>
#include <vector>
#include <random>

using namespace std;

extern "C" void matmulvec(double *A, int *rows_A, int *cols_A, double *B, double *C);

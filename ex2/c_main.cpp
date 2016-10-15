#include "c_header.h"

void fill_vector(vector<double>& v) {
	default_random_engine eng(0);
	uniform_real_distribution<double> dist(0, 1);

	for(auto &a : v)
		a = dist(eng);

}

// print matrix v stored in column-major format
void print_matrix(vector<double> const &v, int rows, int cols) {
	for (int i=0; i<rows; i++) {
		for (int j=0; j<cols; j++)
			cout<< v[j*rows+i] << ' ';
		cout << endl;
	}
	cout << endl;
}

int main() {
	const int M=3, N=2; // dimension of matrix
	vector<double> A(M*N); // matrix A
	vector<double> B(N), C(M); // vector B, C

	fill_vector(A);
	fill_vector(B);

	// multiply A and B, save the result in C
	int rows_A=M;
	int cols_A=N;

	// pass the address of the first element in vector
	matmulvec(&A[0], &rows_A, &cols_A, &B[0], &C[0]);
	
	cout << "A = " << endl;
	print_matrix(A, M, N);
	cout << "B = " << endl;
	print_matrix(B, N, 1);
	cout << "C = " << endl;
	print_matrix(C, M, 1);

	return 0;
}


#include "c_header.h"

using namespace std;

int main(int argc, char** argv) {
	float f = 1;
	double d = 2;
	complex<double> c(1., 0.);
	test_sub(f, d, c);
	cout << f << ' ' << d << ' ' << c << endl;
	getchar();
	return 0;

}

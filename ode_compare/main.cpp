#include <cmath>
#include <ctime>
#include <random>
#include <boost/numeric/odeint.hpp>
#include <chrono>
#include "chrono_io"


using namespace boost::numeric::odeint;
using namespace std;

typedef std::vector<double> state_type;

typedef std::chrono::high_resolution_clock Clock;

typedef runge_kutta_cash_karp54< state_type > error_stepper_type;

typedef controlled_runge_kutta< error_stepper_type > controlled_stepper_type;

void ode_cpp(const int n, std::vector<double>& x, std::vector<double>& y);

extern "C" void ode_for(int* n, double *x, double *y);

struct func {
	void operator()(const state_type &x, state_type &dxdt, double t) const
	{
		dxdt[0] = cos(x[0]);
		dxdt[1] = x[0] + x[1]*x[1];
	}
};

void ode_cpp(const int n, std::vector<double>& x, std::vector<double>& y) {

	const double dt = 0.3;
	const double t_max = 100;
	state_type state(2);
	size_t steps;

	// solve the system
	for (int i = 0; i < n; i++) {
		state[0] = x[i];
		state[1] = y[i];
		steps = integrate_adaptive(make_controlled(1.0e-10, 1.0e-6, error_stepper_type()), func(), state, 0.0, t_max, dt);
		x[i] = state[0];
		y[i] = state[1];
	}
	
	return;
}

int main() {
	int n=10000;
	default_random_engine eng(0);
	uniform_real_distribution<double> uni(0, 1);
	vector<double> x(n), y(n);
	
	for(auto &a : x)
		a = uni(eng);
	for(auto &a : y)
		a = uni(eng);
	x[0] = 1;
	y[0] = 1;
	
	auto t1 = Clock::now();
	ode_cpp(n, x, y);
	auto t2 = Clock::now();
	
	cout << "It takes " << t2 - t1 << " with C++" << endl;
	cout << "x = " << x[0] << endl << "y = " << y[0] << endl;
	
	for(auto &a : x)
		a = uni(eng);
	for(auto &a : y)
		a = uni(eng);
	x[0] = 1;
	y[0] = 1;
	
	t1 = Clock::now();
	ode_for(&n, &x[0], &y[0]);
	t2 = Clock::now();
	
	cout << "It takes " << t2 - t1 << " with Fortran" << endl;
	cout << "x = " << x[0] << endl << "y = " << y[0] << endl;
	
	return 0;
	
}
#include<iostream>
#include<cmath>
#include<fstream>
#include<random>
#include<iomanip>
#define MAX_N 1e5
using namespace std;

const double PI = 4.0 * (4 * atan(1./5) - atan(1./239));
double f(double y){
	return pow(M_E, -(1.0/y - 1.0) * (1./y - 1.0)) * 1.0 / (y * y);
}

int main(void){
	random_device gen_seed;
	default_random_engine engine(gen_seed());
	uniform_real_distribution<> dist(0.0, 1.0);
	ofstream out{"montecarlo.dat"};
	double sum = 0.0;
	for(int i = 0; i < MAX_N; i++){
		sum += 2.0 * f(dist(engine)) / MAX_N;
		out << i << " " << sum << endl;
		cout << "\r[" << setw(7) << i + 1 << " / " << setw(8) << MAX_N << "]";
	}
	cout << endl << endl;
	cout << "Result" << endl;
	cout << "real sqrt(pi)\t\t\t\t" << setprecision(8) << sqrt(PI) << endl;
	cout << "simulated sqrt(pi)\t\t\t" << setprecision(8) << sum << endl;
	cout << "relatice error\t\t\t\t\t" << scientific << (sqrt(PI) - sum)/sqrt(PI) << endl;
}


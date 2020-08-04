#include<iostream>
#include<cmath>
#include<fstream>
#include<random>
#include<iomanip>
#define MAX_N 1e7


const double PI = 4.0 * (4 * std::atan(1./5) - std::atan(1./239));
double f(double y){
	return std::pow(M_E, -(1.0/y - 1.0) * (1./y - 1.0)) * 1.0 / (y * y);
}

int main(void){
	std::random_device gen_seed;
	std::default_random_engine engine(gen_seed());
	std::uniform_real_distribution<> dist(0.0, 1.0);
	std::ofstream out{"montecarlo.dat"};
	double sum = 0.0;

	for(int i = 0; i < MAX_N; i++){
		sum += 2.0 * f(dist(engine)) / MAX_N;
		out << i << " " << sum << std::endl;
		std::cout << "\r[" << std::setw(7) << i + 1 << " / " << std::setw(8) << MAX_N << "]";
	}
	std::cout << std::endl << std::endl;
	std::cout << "Result" << std::endl;
	std::cout << "real sqrt(pi)\t\t\t\t" << std::setprecision(8) << std::sqrt(PI) << std::endl;
	std::cout << "simulated sqrt(pi)\t\t\t" << std::setprecision(8) << sum << std::endl;
	std::cout << "relatice error\t\t\t\t\t" << std::scientific << (std::sqrt(PI) - sum)/std::sqrt(PI) << std::endl;
}


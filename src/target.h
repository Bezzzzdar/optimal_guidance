#pragma once
#include <memory>
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <random>
#include <exception>

constexpr double PI = 3.1415;

#define LINEAR_TRAJECTORY 0x01
#define COMPLEX_TRAJECTORY 0x02
#define ANGULAR_MANEUVERING 0x03
#define SINUS_MANEUVERING 0x04

/**********************************************************
*
*		Class for modeling ground maneuvering target  
* 
***********************************************************/
class Target
{
private:
	double x, y;
	// double x0 = 0;
	// double y0 = 0;
	// double v0 = 0;
	double z; // must always be 0
	double v = 100;
	// double a = 10;
	// double theta = 0.1;
	// double theta0 = theta;
	double omega = 2;
	// double omega0 = omega;
	double A = 5;
	// double R;

	std::vector<double> x_values;
	std::vector<double> y_values;
	std::vector<double> z_values;
	std::vector<double> v_values;
	std::vector<double> t_values;

	const char* output_file = ".\\values\\target_values.csv";

	int TRAJECTORY;

	void update_values(double t);
public:
	Target(double x0, double y0, int TRAJECTORY_FLAG);
	~Target();
	void update_position(double t);
	void dump_values();
};

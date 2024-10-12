#pragma once
#include <memory>
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <random>
#include <exception>

/**********************************************************
*
*		Class for modeling ground maneuvering target  
* 
***********************************************************/
class Target
{
private:
	double x, y;
	double z; // must always be 0
	double v, v_x, v_y;
	double a, a_x, a_y;

	std::vector<double> x_values;
	std::vector<double> y_values;
	std::vector<double> z_values;
	std::vector<double> v_values;
	std::vector<double> t_values;

	const char* output_file = ".\\values\\target_values.csv";

	std::random_device rd;

	void random_acceleration();
	void update_values(double t);
public:
	Target(double x0, double y0);
	~Target();
	void update_position(double t, double dt);
	void dump_values();
};

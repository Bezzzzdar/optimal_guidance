#pragma once
#include <memory>
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <random>

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

	std::ofstream out;
	const char* output_file = ".\\values\\target_values.csv";

	std::random_device rd;

public:
	Target(double x0, double y0);
	~Target();
	void update_values(double x, double y, double v, double t);
	void update_position(double t, double dt);
	void random_acceleration();
	void dump_values();
};

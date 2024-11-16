#pragma once
#include <memory>
#include <iostream>
#include <array>
#include <vector>
#include <fstream>
#include <cmath>
#include <exception>

constexpr double g = 9.81;

/*******************************************************************
*		
*					Typedef for state vector
* 
*******************************************************************/
typedef struct
{
	double V;
	double theta;
	double phi;
	double x;
	double y;
	double z;
} state_vector_t;

/*******************************************************************
*		
*				Typedef for control vector by overload
* 
*******************************************************************/
typedef struct
{
	double n_x;
	double n_y;
	double n_z;
} control_vector_t;

/*******************************************************************
*
*						Class for modeling uav  
* 
*******************************************************************/
class UAV
{
private:
	double P = 40000;
	double m = 10000;
	double m0 = m;
	double m_c = 200;
	state_vector_t *state_vector;
	control_vector_t *u;

	std::vector<double> x_values;
	std::vector<double> y_values;
	std::vector<double> z_values;
	std::vector<double> v_values;
	std::vector<double> theta_values;
	std::vector<double> phi_values;
	std::vector<double> t_values;

	const char* output_file = ".\\values\\uav_values.csv";

	void update_values(double t);

	/* Basic system of equations of motion of the UAV as a material point */
	double dv_dt();
	double dtheta_dt();
	double dphi_dt();
	double dx_dt();
	double dy_dt();
	double dz_dt();
	double dm_dt();

public:
	UAV(state_vector_t *state_vector0, control_vector_t *u0, double t);
	~UAV();
	int update_position(double t, double dt);
	void dump_values();
	
};


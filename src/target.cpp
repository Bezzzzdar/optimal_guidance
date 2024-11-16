#include "target.h"

void Target::update_values(double t)
{
	this->x_values.push_back(this->x);
	this->y_values.push_back(this->y);
	this->z_values.push_back(this->z);
	this->v_values.push_back(this->v);
	this->t_values.push_back(t);
}

Target::Target(double x0, double y0, int TRAJECTORY_FLAG)
{
	this->x = x0;
	this->y = y0;
	this->z = 0;

	this->TRAJECTORY = TRAJECTORY_FLAG;

	this->update_values(0); // target has initial speed == 0
}

Target::~Target()
{
}

void Target::update_position(double t)
{
	// if (this->TRAJECTORY == ANGULAR_MANEUVERING)
	// {
	// 	this->theta = this->theta0 + this->omega0 * t + (this->a * pow(t, 2))/2;
	// 	this->x = this->x0 + this->v * cos(this->theta) * t;
	// 	this->y = this->y0 + this->v * sin(this->theta) * t;
	// }
	// else if (this->TRAJECTORY == COMPLEX_TRAJECTORY)
	// {
	// 	this->R = 10 + 5 * sin(t);
	// 	this->theta = this->theta0 + this->omega0 * t + (this->a * pow(t, 2))/2;
	// 	this->x = this->R * cos(this->omega);
	// 	this->y = this->R * sin(this->omega);
	// }
	if (this->TRAJECTORY == SINUS_MANEUVERING)
	{
		this->x = this->v * t;
		this->y = this->A * sin(this->omega * t);
	}
	
	
	this->update_values(t);
}

void Target::dump_values()
{
	std::fstream file;
	file.open(this->output_file, std::ios::out | std::ios::app);
	if (!(file.is_open()))
	{
		throw std::exception("File isn't open!");
	}
	
	for (size_t i = 0; i < this->x_values.size(); ++i) {
		file << this->x_values[i] << "," << this->y_values[i] << "," << this->z_values[i] << "," << this->v_values[i] << "," << this->t_values[i] << "\n";
	}
	file.close();
}
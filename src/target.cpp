#include "target.h"

void Target::update_values(double x, double y, double v, double t)
{
	this->x = x;
	this->y = y;
	this->z = 0;
	this->v = v;

	this->x_values.push_back(x);
	this->y_values.push_back(y);
	this->z_values.push_back(z);
	this->v_values.push_back(v);
	this->t_values.push_back(t);
}

Target::Target(double x0, double y0)
{
	this->update_values(x0, y0, 0, 0); // target has initial speed == 0
}

Target::~Target()
{
}

void Target::random_acceleration()
{
	std::mt19937 gen(rd());
	std::normal_distribution<> dis(0, 0.01);

	this->a_x = dis(gen);
	this->a_y = dis(gen);
}

void Target::update_position(double t, double dt)
{
	random_acceleration();

	this->v_x = this->a_x * dt;
	this->v_y = this->a_y * dt;
	this->v = sqrt(pow(v_x, 2) + pow(v_y, 2));

	this->x += this->v_x * dt;
	this->y += this->v_y * dt;

	this->update_values(x, y, v, t);
}

void Target::dump_values()
{
	std::ofstream file;
	file.open(this->output_file);
	if (file.is_open())
	{
		std::cout << "file is open!" << std::endl;
		for (size_t i = 0; i < x_values.size(); ++i) {
			file << this->x_values[i] << "," << this->y_values[i] << "," << this->z_values[i] << "," << this->v_values[i] << "," << this->t_values[i] << "\n";
		}
	}
	else
	{
		std::cout << "file isn't open" << std::endl;
	}
	file.close();
}
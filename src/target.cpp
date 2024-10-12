#include "target.h"

void Target::update_values(double t)
{
	this->x_values.push_back(this->x);
	this->y_values.push_back(this->y);
	this->z_values.push_back(this->z);
	this->v_values.push_back(this->v);
	this->t_values.push_back(t);
}

Target::Target(double x0, double y0)
{
	this->x = x0;
	this->y = y0;
	this->z = 0;
	this->v = 0;

	this->update_values(0); // target has initial speed == 0
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
	std::cout << "file is open!" << std::endl;
	for (size_t i = 0; i < this->x_values.size(); ++i) {
		file << this->x_values[i] << "," << this->y_values[i] << "," << this->z_values[i] << "," << this->v_values[i] << "," << this->t_values[i] << "\n";
	}
	file.close();
}
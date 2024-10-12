#include "UAV.h"

void UAV::update_values(double t)
{
	this->v_values.push_back(this->state_vector->V);
	this->theta_values.push_back(this->state_vector->theta);
	this->phi_values.push_back(this->state_vector->phi);
	this->x_values.push_back(this->state_vector->x);
	this->y_values.push_back(this->state_vector->y);
	this->z_values.push_back(this->state_vector->z);
	
	this->t_values.push_back(t);
}

UAV::UAV(state_vector_t *state_vector0, control_vector_t *u0, double t)
{
	this->state_vector = state_vector0;
    this->u = u0;

    this->update_values(t);
}

UAV::~UAV()
{
}

void UAV::update_position(double t, double dt)
{
	this->state_vector->V += this->dv_dt() * dt;
	this->state_vector->theta += this->dtheta_dt() * dt;
	this->state_vector->phi += this->dphi_dt() * dt;
	this->state_vector->x += this->dx_dt() * dt;
	this->state_vector->y += this->dy_dt() * dt;
	this->state_vector->z += this->dz_dt() * dt;
	if (this->m < this->m0/2)
	{
		m = m0/2;
		this->P = 0;
	}
	else
	{
		this->m += this->dm_dt() * dt;
	}

	this->update_values(t);
	
}

void UAV::dump_values()
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

/*
* 	Basic system of equations of motion of the UAV as a material point
*/

double UAV::dv_dt()
{
	return g * (this->u->n_x - sin(this->state_vector->theta));
}

double UAV::dtheta_dt()
{
	return (g / this->state_vector->V) * (this->u->n_y - cos(this->state_vector->theta));
}

double UAV::dphi_dt()
{
	return -(g / this->state_vector->V) * (this->u->n_z / cos(this->state_vector->theta));
}

double UAV::dx_dt()
{
	return this->state_vector->V * cos(this->state_vector->theta) * cos(this->state_vector->phi);
}

double UAV::dy_dt()
{
	return this->state_vector->V * sin(this->state_vector->theta);
}

double UAV::dz_dt()
{
	return -(this->state_vector->V) * cos(this->state_vector->theta) * sin(this->state_vector->phi);
}

double UAV::dm_dt()
{
	return -(this->m_c);
}

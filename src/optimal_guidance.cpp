﻿// optimal_guidance.cpp: определяет точку входа для приложения.
//

#include "optimal_guidance.h"
#include "target.h"
#include "uav.h"

int main()
{
	int rc;
	state_vector_t state_vector0;
	state_vector0.V = 300;
	state_vector0.theta = 0.373;
	state_vector0.phi = 0.1;
	state_vector0.x = 0;
	state_vector0.y = 0;
	state_vector0.z = 0;

	control_vector_t u;
	u.n_x = 1; 
	u.n_y = 1; 
	u.n_z = 1; 

	const double dt = 0.1;
	double t = 0;

	UAV uav(&state_vector0, &u, t);
	Target target(0.0, 0.0, SINUS_MANEUVERING);

	while (t <= 100)
	{
		target.update_position(t);
		rc = uav.update_position(t, dt);
		if (rc == -1)
		{
			break;
		}
		t += dt;
	}

	return 0;
}

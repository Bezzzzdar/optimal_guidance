// optimal_guidance.cpp: определяет точку входа для приложения.
//

#include "optimal_guidance.h"
#include "target.h"
#include "uav.h"

using namespace std;

int main()
{
	state_vector_t state_vector0;
	state_vector0.V = 500;
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
	Target target(0.0, 0.0);

	while (t <= 100)
	{
		target.update_position(t, dt);
		t += dt;
	}
	target.dump_values();

	t = 0;
	while (t <= 100)
	{
		uav.update_position(t, dt);
		t += dt;
	}
	uav.dump_values();

	return 0;
}

// optimal_guidance.cpp: определяет точку входа для приложения.
//

#include "optimal_guidance.h"
#include "target.h"

using namespace std;

int main()
{
	Target target(0.0, 0.0);
	const double dt = 0.1;
	double t = 0;

	while (t <= 100)
	{
		target.update_position(t, dt);
		t += dt;
	}

	target.dump_values();
	return 0;
}

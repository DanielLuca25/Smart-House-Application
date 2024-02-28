#ifndef Pressure_H
#define Pressure_H
#include "ISensor.h"
#include <ctime>

class Pressure : public ISensor
{
public:
	double readSensor()
	{
		return generatePressure();
	}

private:
	double generatePressure()
	{
		srand(time(NULL));
		double f = (double)rand() / RAND_MAX;
		return 300 + f * 500;
	}
};

#endif
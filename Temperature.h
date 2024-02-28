#ifndef Temperature_H
#define Temperature_H
#include "ISensor.h"
#include <ctime>

class Temperature : public ISensor
{
public:
	double readSensor()
	{
		return generateTemperature();
	}

private:
	double generateTemperature()
	{
		srand(time(NULL));
		double f = (double)rand() / RAND_MAX;
		return -40 + f * 120;
	}
};

#endif



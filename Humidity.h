#ifndef Humidity_H
#define Humidity_H
#include "ISensor.h"
#include <ctime>

class Humidity : public ISensor
{
public:
	double readSensor()
	{
		return generateHumidity();
	}

private:
	double generateHumidity()
	{
		srand(time(NULL));
		double f = (double)rand() / RAND_MAX;
		return f * 100;
	}
};

#endif
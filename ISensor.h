#ifndef ISensor_H
#define ISensor_H
#include <iostream>
using namespace std;

class ISensor
{
public:
	virtual double readSensor() = 0;
};

#endif

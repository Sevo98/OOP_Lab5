#include <iostream>
#include "UniformDistanceCalculator.h"

void UniformDistanceCalculator::SetSpeed(double speed)
{
	if (speed < 0)
	{
		throw std::exception("Размер скидки должен быть от 0 до 100!");
	}
	this->_speed = speed;
}

double UniformDistanceCalculator::GetSpeed()
{
	return this->_speed;
}

double UniformDistanceCalculator::Calculate(double time)
{
	double distance = 0;
	distance = time * this->_speed;
	return distance;
}

UniformDistanceCalculator::UniformDistanceCalculator(double speed)
{
	SetSpeed(speed);
}

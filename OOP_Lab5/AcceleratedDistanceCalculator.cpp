#include <iostream>
#include "AcceleratedDistanceCalculator.h"

void AcceleratedDistanceCalculator::SetSpeed(double speed)
{
	if (speed < 0)
	{
		throw std::exception("Размер скидки должен быть от 0 до 100!");
	}
	this->_speed = speed;
}

void AcceleratedDistanceCalculator::SetAcceleration(double acceleration)
{
	this->_acceleration = acceleration;
}

double AcceleratedDistanceCalculator::GetSpeed()
{
	return this->_speed;
}

double AcceleratedDistanceCalculator::GetAcceleration()
{
	return this->_acceleration;
}

double AcceleratedDistanceCalculator::Calculate(double time)
{
	double distance = 0;
	distance = this->_speed * time + this->_acceleration * pow(time,2)/2;
	return distance;
}

AcceleratedDistanceCalculator::AcceleratedDistanceCalculator(double speed, double acceleration)
{
	SetSpeed(speed);
	SetAcceleration(acceleration);
}

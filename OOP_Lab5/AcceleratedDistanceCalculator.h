#pragma once
#include "DistanceCalculatorBase.h"
class AcceleratedDistanceCalculator : public DistanceCalculatorBase
{
	double _speed;
	double _acceleration;
public:
	void SetSpeed(double speed);
	void SetAcceleration(double speed);
	double GetSpeed();
	double GetAcceleration();
	double Calculate(double time) override;

	AcceleratedDistanceCalculator(double speed, double acceleration);
};


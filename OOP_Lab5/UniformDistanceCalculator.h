#pragma once
#include "DistanceCalculatorBase.h"
class UniformDistanceCalculator :  public DistanceCalculatorBase
{
	double _speed;
public:
	void SetSpeed(double speed);
	double GetSpeed();
	double Calculate(double time) override;

	UniformDistanceCalculator(double speed);
};


#include "_time.h"

Time::Time()
{
	isStop = false;
	basicQuantum = defaultQuantum;
	currentQuantum = defaultQuantum;
}

Time::Time(double quantum)
{
	isStop = false;
	basicQuantum = quantum;
	currentQuantum = quantum;
}

Time::~Time()
{
}

void Time::setTimeQuantum(double quantum)
{
	basicQuantum = quantum;
	currentQuantum = quantum;
}

void Time::increaseQuantum(double value)
{
	currentQuantum += value;
}

void Time::decreaseQuantum(double value)
{
	if ((currentQuantum - value) > 0)
	{
		currentQuantum -= value;
	}
}

void Time::resetQuantum()
{
	currentQuantum = basicQuantum;
}

void Time::stopTime()
{
	isStop = true;
}

void Time::resumeTime()
{
	isStop = false;
}

double Time::getBasicQuantum()
{
	return basicQuantum;
}
double Time::getCurrentQuantum()
{
	return currentQuantum;
}

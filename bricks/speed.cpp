#pragma once
#include "stdafx.h"
	
float Speed::rads(float g)
{
	return g*PI/180;
}
float Speed::grads(float r)
{
	return r*180/PI;
}

Speed::Speed(float m, float angle)
{
	_m = m;
	_angle = angle;
	_Vx = _m*cos(rads(_angle));
	_Vy = _m*sin(rads(_angle));
}

void Speed::setAngle(float angle)
{
	_angle = angle;
	_Vx = _m*cos(rads(_angle));
	_Vy = _m*sin(rads(_angle));
}

void Speed::setM(float m)
{
	_m = m;
	_Vx = _m*cos(rads(_angle));
	_Vy = _m*sin(rads(_angle));
}

void Speed::setVx(float newVx)
{
	_Vx = newVx;
	_angle = rads(acos(_Vx/_m));
}

void Speed::setVy(float newVy)
{
	_Vy = newVy;
	_angle = grads(asin(_Vy/_m));
}
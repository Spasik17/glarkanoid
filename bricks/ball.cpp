#pragma once
#include "stdafx.h"

Ball::Ball(Point * pos, Speed * vel, float r)
{
		_pos = new Point(pos->_x, pos->_y);
		_vel = new Speed(vel->_m, vel->_angle);
		_r = r;
}

void Ball::move()
{
	_pos->_x += _vel->_Vx;
	_pos->_y += _vel->_Vy;
}

void Ball::accel(float newm)
{
	_vel->setM(newm); 
}

void Ball::bounceSides()
{
	_vel->setVx(-(_vel->_Vx));
}

void Ball::bounceRoofs()
{
	_vel->setVy(-(_vel->_Vy));
}

void Ball::bounce(Speed normal)
{
	// d = d - 2s
}
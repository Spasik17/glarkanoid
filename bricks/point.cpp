#pragma once
#include "stdafx.h"

Point::Point(float x, float y){
	_x = x;
	_y = y;
};

void Point::setx(float x){
	_x = x;
};

void Point::sety(float y){
	_y = y;
};
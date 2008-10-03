#pragma once
#include "stdafx.h"

Paleta::Paleta(Point * pos, float w, float h, float v)
{
	_pos = new Point(pos->_x, pos->_y);
	_w = w;
	_h = h;
	_v = v;
};

void Paleta::left()
{
	_pos->setx(_pos->_x - _v);
};

void Paleta::right()
{
	_pos->setx(_pos->_x + _v);
};

void Paleta::crecer(float c)
{
	_w += c;
};

void Paleta::decrecer(float c)
{
	_w -= c;
};
#pragma once
#include "stdafx.h"

class Paleta
{
public:
	Point * _pos;	//posicion de la paleta
	float _h;		//altura de la paleta
	float _w;		//anchura de la paleta
	float _v;		//velocidad de la paleta

	Paleta(Point * pos, float w, float h, float v);
	//Mover la paleta a la izqierda
	void left();
	//Mover la pelota a la derecha
	void right();
	//Aumentar el tamaño de la pelota al golpear un bonus
	void crecer(float);
	//Disminuir el tamaño de la pelota al obtener un bonus bad
	void decrecer(float);
};

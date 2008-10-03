#pragma once
class Speed 
{
	public:
		float _Vx; //velocidad en X
		float _Vy;	//Velocidad en Y
		float _m;	//Magnitud
		float _angle;	//angulo de la velocidad

		Speed(float m, float angle);
		void setAngle(float newangle);
		void setM(float newm);
		void setVx(float);
		void setVy(float);

	private:
		float rads(float g);
		float grads(float r);
};
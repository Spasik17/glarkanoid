#pragma once
class Speed 
{
	public:
		float _Vx;		//velocidad en X
		float _Vy;		//Velocidad en Y
		float _m;		//Magnitud
		float _angle;	//Angulo de la velocidad

		Speed(float m, float angle);
		void setAngle(float newangle);
		void setM(float newm);
		void setVx(float);
		void setVy(float);
		Speed * project(Speed * proj);

	private:
		float rads(float g);
		float grads(float r);
		float dp(Speed * proj);	//producto punto
};
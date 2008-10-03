#pragma once
class Ball
{	
	public:
		float _r;	//radio de la pelota
		Point *_pos; //posicion de la pelota
		Speed *_vel;	//velocidad de la pelota
		
		Ball(Point *, Speed *, float);
		void move();

		void bounce(Speed collission);
		void bounceSides();
		void bounceRoofs();
		void accel(float newM);
};
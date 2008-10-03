// bricks.cpp : main project file.
#pragma once
#include "stdafx.h"

Point * inicioBall = new Point(0.0f , 0.0f);
Speed * vel = new Speed(0.6f, 45);
Ball * pelota = new Ball(inicioBall, vel, /*radio*/ 1.0f);

Point * inicioPaleta = new Point(0.0f, -8.0f);
Paleta * paleta = new Paleta(inicioPaleta, /*anchura*/2.0f, /*altura*/0.40f, /*velocidad*/0.5f);


float t=0.05; 

// movimiento de la base
float movX=0.0;

float rgb(float v)
{
	return v/255;
}


void dibujarPaleta() {
	glPushMatrix();
	glTranslatef(paleta->_pos->_x, paleta->_pos->_y, 0.0f);
	glBegin(GL_POLYGON);
		glVertex2f(-paleta->_w, paleta->_h);
		glVertex2f(paleta->_w, paleta->_h);
		glVertex2f(paleta->_w, -paleta->_h);
		glVertex2f(-paleta->_w, -paleta->_h);
	glEnd();
	glPopMatrix();
}

  void dibujarPelota()
  {
	 
   GLint i;
   static GLfloat circcoords[100][2];
   static GLint inited=0;

   if(inited==0){
      inited=1;
      for(i=0;i<100;i++){
         circcoords[i][0] = 0.2*cos(i*2*(3.14)/100);
         circcoords[i][1] = 0.2*sin(i*2*(3.14)/100);
      }
   }
   glBegin(GL_POLYGON);
      for(i=0;i<100;i++)
         glVertex2f(pelota->_pos->_x + circcoords[i][0], pelota->_pos->_y + circcoords[i][1]);
   glEnd();
  }



void display(){

	glClearColor(1.0f, 1.0f, 1.0f ,1.0f);				
	glClear(GL_COLOR_BUFFER_BIT);

		
	glLoadIdentity();


	glColor3f(0.0,0.0,1.0);
	dibujarPelota();
	glColor3f(0.0,0.0,0.0);
	

	dibujarPaleta();
	
	glutSwapBuffers();
}


void update(int v) {	
	if (pelota->_pos->_x >= 9.0 || pelota->_pos->_x <= -9.0) {
		if(pelota->_pos->_x >= 9.0 )
			pelota->_pos->setx(9.0);
		else
			pelota->_pos->setx(-9.0);

		pelota->bounceSides();
	}
	if (pelota->_pos->_y >= 12.0) {
		if( pelota->_pos->_y >= 12.0 )
			pelota->_pos->sety(12.0);
		pelota->bounceRoofs();
	}
	pelota->move();

	glutPostRedisplay();
	glutTimerFunc(5,update,0);
}

void cambioventana(int w, int h){

	float aspectratio;

	if (h==0)
		h=1;

	glViewport(0, 0, w, h);

    	glMatrixMode(GL_PROJECTION);
    	glLoadIdentity();


	aspectratio = (float) w / (float) h;
	if (w<=h) {
		glOrtho(-10, 10, -10/aspectratio, 10/aspectratio, 1.0, -1.0);

	}else{
		glOrtho(-10*aspectratio, 10*aspectratio, -10, 10, 1.0, -1.0);
	}
	glMatrixMode(GL_MODELVIEW);

}


void Keypress(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT:
			if(paleta->_pos->_x > -7.5)
				//movX-=0.5;
				paleta->left();
            break;
        case GLUT_KEY_RIGHT:
			if(paleta->_pos->_y < 7.5)
				//movX+=0.5;
				paleta->right();
            break;
    }
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE);  
	
	glutInitWindowSize (500, 650); 
    glutInitWindowPosition (10, 50);
	glutCreateWindow("Bricks");		

	glutDisplayFunc(display);
	glutReshapeFunc(cambioventana);
	glutTimerFunc (250, update, 0);
	glutSpecialFunc(Keypress);

	glutMainLoop();

    return 0;
}
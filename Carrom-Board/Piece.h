#pragma once
#include "DEngine.h"
class Piece: public Circle {
public:
	GLdouble vx, vy;
	GLdouble ax, ay;
	int type;
	GLdouble mass;
	static int count;
	int id;
	TextureManager image;

	Piece(int type):Circle(type==0?20:15) {
		id = count++;
		this->type = type;
		mass = radius * 10.0f;
		vx = vy = 0;
		ax = ay = 0;
		/*if (type == 0) image.setFile("assets//images//striker.png");
		else if (type == 1) image.setFile("assets//images//white.png");
		else if (type == 2) image.setFile("assets//images//black.png");*/
		
	}
	Piece(int type,int px,int py) :Circle(type == 0 ? 20 : 15,px,py) {
		id = count++;
		this->type = type;
		mass = radius * 10.0f;
		vx = vy = 0;
		ax = ay = 0;
	}
	void init() {
		{
			image.setFile("assets//images//queen.png");
			image.load();
		}
	}
	int getType() {
		return type;
	}
	void move(GLdouble);
	void reverseVx();
	void reverseVy();
	void setVx(GLdouble);
	void setVy(GLdouble);
	GLdouble getVx();
	GLdouble getVy();
	void setAx(GLdouble);
	void setAy(GLdouble);
	GLdouble getAx();
	GLdouble getAy();
	void collision(Piece &p);
	void draw() {
		cout << type << endl;
		 unsigned int texture = image.getTexture();
		//unsigned int texture = TextureManager::load("assets//images//queen.png");

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, type+1);

		glBegin(GL_POLYGON);
		GLdouble r = getRadius();
		GLdouble t, dt = 2 * PI / 100;
		glBegin(GL_POLYGON);
		for (t = 0; t <= 2 * PI + dt; t += dt)
		{
			GLdouble x = px + r * cos(t);
			GLdouble y = py + r * sin(t);
			//cout << (x - px + r) / (2 * r)<<" "<< (y - py + r) / (2 * r) << endl;
			glTexCoord2f((x - px + r) / (2 * r), (y - py + r) / (2 * r));
			glVertex2d(x, y);
		}
		glEnd();


		glBindTexture(GL_TEXTURE_2D, 0);
		glDisable(GL_TEXTURE_2D);
	}
};



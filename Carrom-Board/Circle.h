#ifndef __CIRCLE__
#define __CIRCLE__
#include "Object.h"
class Circle: public Object {
protected:
	GLdouble radius;
public:
	Circle();
	Circle(GLdouble);
	Circle(GLdouble, GLdouble, GLdouble);
	int getRadius();
	void setRadius(int);
	void save(ofstream& out);
	void load(ifstream& in);
	void draw();
	bool isPointInCircle(int, int);
	bool doCirclesOverlap(Circle c);
};
#endif
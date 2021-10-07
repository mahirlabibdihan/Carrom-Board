#ifndef __POINT__
#define __POINT__
#include "OpenGL.h"
#include <fstream>
using namespace std;
class Point {
protected:
	GLdouble px, py;
public:
	Point();
	Point(GLdouble x, GLdouble y);
	GLdouble getX();
	GLdouble getY();
	void setXY(GLdouble x, GLdouble y);
	void setX(GLdouble x);
	void setY(GLdouble y);
	void save(ofstream& out);
	void load(ifstream& in);
};
#endif
#include "Point.h"
Point::Point()
{
	this->px=this->py=0;
}
Point::Point(GLdouble x, GLdouble y)
{
	this->px=x;
	this->py=y;
}
GLdouble Point::getX()
{
	return px;
}
GLdouble Point::getY()
{
	return py;
}
void Point::setXY(GLdouble x, GLdouble y)
{
	this->px = x;
	this->py = y;
}
void Point::setX(GLdouble x)
{
	this->px = x;
}
void Point::setY(GLdouble y)
{
	this->py = y;
}
void Point::save(ofstream& out)
{
	out << px << " " << py << endl;
}
void Point::load(ifstream& in)
{
	in >> px >> py;
}
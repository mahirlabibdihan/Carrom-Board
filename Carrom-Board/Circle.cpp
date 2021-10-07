#define STB_IMAGE_IMPLEMENTATION
#include "Circle.h"
Circle::Circle() :Object() {
	this->radius = 0;
}
Circle::Circle(GLdouble radius) :Object() {
	this->radius = radius;
}
Circle::Circle(GLdouble radius,GLdouble px,GLdouble py) : Object(px,py) {
	this->radius = radius;
}
int Circle::getRadius()
{
	return radius;
}
void Circle::setRadius(int radius)
{
	this->radius = radius;
}
void Circle::save(ofstream& out)
{
	Object::save(out);
	out << this->radius << endl;
}
void Circle::load(ifstream& in)
{
	Object::load(in);
	in >> radius;
}
void Circle::draw()
{

}

bool Circle::isPointInCircle(int mx, int my) {
	return fabs((mx - getX()) * (mx - getX()) + (my - getY()) * (my - getY())) < (GLdouble)(getRadius() * getRadius());
}

bool Circle::doCirclesOverlap(Circle c) {
	GLdouble x1 = getX(), x2 = c.getX();
	GLdouble y1 = getY(), y2 = c.getY();
	GLdouble r1 = getRadius(), r2 = c.getRadius();
	return fabs((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) < (r1 + r2) * (r1 + r2);
}
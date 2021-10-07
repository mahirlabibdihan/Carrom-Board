#include "Piece.h"
#include "Carrom.h"
int Piece::count = 0;
void Piece::move(GLdouble dt) {
	ax = -vx * 0.9999;
	ay = -vy * 0.9999;

	// Update ball physics
	vx += ax * dt / 1000;
	vy += ay * dt / 1000;
	px += vx * dt / 1000;
	py += vy * dt / 1000;

	// Clamp velocity near zero
	if (fabs(vx * vx + vy * vy) < 1.0f)
	{
		vx = 0;
		vy = 0;
	}
}
void Piece::reverseVx() {
	vx = -vx;
}
void Piece::reverseVy() {
	vy = -vy;
}
void Piece::setVx(GLdouble vx) {
	this->vx = vx;
}
void Piece::setVy(GLdouble vy) {
	this->vy = vy;
}
GLdouble Piece::getVx() {
	return vx;
}
GLdouble Piece::getVy() {
	return vy;
}
void Piece::setAx(GLdouble) {
	this->ax = ax;
}
void Piece::setAy(GLdouble) {
	this->ay = ay;
}
GLdouble Piece::getAx() {
	return ax;
}
GLdouble Piece::getAy() {
	return ay;
}

void Piece::collision(Piece& p) {
	GLdouble x1 = this->getX(), x2 = p.getX();
	GLdouble y1 = this->getY(), y2 = p.getY();
	GLdouble r1 = this->getRadius(), r2 = p.getRadius();


	// Source: https://github.com/OneLoneCoder/videos/blob/master/OneLoneCoder_Balls1.cpp
	// Static collision
	// Distance between ball centers
	GLdouble fDistance = sqrtf((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

	// Calculate displacement required                 
	GLdouble fOverlap = (fDistance - r1 - r2) / 2.0;

	// Displace Current Ball away from collision
	x1 -= fOverlap * (x1 - x2) / fDistance;   
	y1 -= fOverlap * (y1 - y2) / fDistance;

	// Displace Target Ball away from collision
	x2 += fOverlap * (x1 - x2) / fDistance;
	y2 += fOverlap * (y1 - y2) / fDistance;

	this->setXY(x1, y1);
	p.setXY(x2, y2);



	// Dynamic Collision  
	fDistance = sqrtf((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

	// Normal
	GLdouble nx = (x2 - x1) / fDistance;
	GLdouble ny = (y2 - y1) / fDistance;

	// Tangent
	GLdouble tx = -ny;
	GLdouble ty = nx;

	// Dot Product Tangent
	GLdouble dpTan1 = this->vx * tx + this->vy * ty;
	GLdouble dpTan2 = p.vx * tx + p.vy * ty;

	// Dot Product Normal
	GLdouble dpNorm1 = this->vx * nx + this->vy * ny;
	GLdouble dpNorm2 = p.vx * nx + p.vy * ny;

	// Conservation of momentum in 1D
	GLdouble m1 = (dpNorm1 * (this->mass - p.mass) + 2.0f * p.mass * dpNorm2) / (this->mass + p.mass);
	GLdouble m2 = (dpNorm2 * (p.mass - this->mass) + 2.0f * this->mass * dpNorm1) / (this->mass + p.mass);

	// Update ball velocities
	this->vx = tx * dpTan1 + nx * m1;
	this->vy = ty * dpTan1 + ny * m1;
	p.vx = tx * dpTan2 + nx * m2;
	p.vy = ty * dpTan2 + ny * m2;

	

}
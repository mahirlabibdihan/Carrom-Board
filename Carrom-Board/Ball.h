#pragma once
#include "DEngine.h"
class Ball {
public:
	GLdouble x, y;
	GLdouble u, ux, vx, uy, vy, theta, r;
	Ball() {
		x = y = 0;
		u = 0;
		r = 30;
		theta = 270;
		ux = u * cos(PI * theta / 180);
		uy = u * sin(PI * theta / 180);
	}
};
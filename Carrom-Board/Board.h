#pragma once
#include "DEngine.h"
#include "Rectangle.h"
#include "TextureManager.h"
class Board:public Rectangle
{
	TextureManager image;
public:
	Board():Rectangle(){
		
	}
	void init() {
		image.setFile("assets//images//board.png");
		image.load();
		setWidth(700);
		setHeight(700);
		setXY(-width / 2, -height / 2);
	}
	void draw() {
		image.render(px, py, width, height);
	}
	GLdouble getUpperX() {
		return width / 2 - 25;
	}
	GLdouble getLowerX() {
		return -getUpperX();
	}

	GLdouble getUpperY() {
		return height / 2 - 25;
	}
	GLdouble getLowerY() {
		return -getUpperY();
	}
};


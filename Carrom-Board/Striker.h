#pragma once
#include "Piece.h"
class Striker: public Piece
{
	bool dragged;
public:
	Striker();
	Striker(GLdouble,GLdouble);
	void drag() {
		dragged = true;
	}
	void drop() {
		dragged = false;
	}
	bool isdragged() {
		return dragged;
	}
};


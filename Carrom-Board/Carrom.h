#pragma once
#include "DEngine.h"
#include "Piece.h"
#include "Striker.h"
#include "Board.h"
#include <vector>
using namespace std;

class Carrom :public DEngine {
	vector<Piece> pieces;
	Striker striker;
	Board board;
	GLdouble direction(GLdouble dx, GLdouble dy) {
		double Dir = (atan(fabs(dy / dx)) * 180) / PI;
		if (dx >= 0 && dy >= 0)
		{

		}
		else if (dx >= 0 && dy < 0)
		{
			Dir = 360 - Dir;
		}
		else if (dx < 0 && dy >= 0)
		{
			Dir = 180 - Dir;
		}
		else if (dx < 0 && dy < 0)
		{
			Dir = 180 + Dir;
		}
		return Dir;
	}
	Carrom() {
		
	}
	
	void wrap(Piece&);
	void draw();
	void update(GLdouble dt);
	void init();
	void mouseClick(int,int,int mx, int my);
	void mouseDrag(int mx, int my);
public:
	Board getBoard() {
		return board;
	}
	static DEngine* getSingleton() {
		if (!singletonInstance)
			singletonInstance = new Carrom();
		return singletonInstance;
	}
};

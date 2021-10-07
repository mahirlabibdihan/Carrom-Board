#ifndef __OBJECT__
#define __OBJECT__
#include "Point.h"
#include <fstream>
using namespace std;
class Object: public Point /*, public ColorManager */ {
public:
	Object():Point() {

	}
	Object(GLdouble px,GLdouble py) :Point(px,py) {

	}
	void save(ofstream& out)
	{
		Point::save(out);
		// ColorManager::save(out);
	}
	void load(ifstream& in)
	{
		Point::load(in);
		//ColorManager::load(in);
	}
};
#endif
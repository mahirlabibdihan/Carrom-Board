#ifndef __TEXTURE_MANAGER__
#define __TEXTURE_MANAGER__
#include "OpenGL.h"
#include <string>
#include <iostream>
class TextureManager{
	string filename;
	unsigned int texture;
	GLint width, height;
public:
	TextureManager()
	{
		texture = 0;
	}
	/*TextureManager(const TextureManager& t) {
		width = t.width;
		height = t.height;
		texture = t.texture;
		this->filename = new char[100];
		strcpy(this->filename, t.filename);
	}*/
	TextureManager(const char* filename)
	{
		(this->filename = filename);
	}
	~TextureManager()
	{
		// delete[] filename;
	}
	string getFile() {
		return filename;
	}
	void setFile(const char* filename) {
		
		(this->filename = filename);
		
	}
	unsigned int getTexture() {
		return this->texture;
	}
	void load();
	void render(GLdouble x, GLdouble y, GLint width, GLint height);

	static void init() {
		load("assets//images//striker.png");
		load("assets//images//white.png");
		load("assets//images//black.png");
		load("assets//images//queen.png");
	}
	static unsigned int load(const char* filename);
	static void render(GLdouble x, GLdouble y, GLint width, GLint height, const char* filename);
};
#endif
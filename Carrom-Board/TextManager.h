#ifndef __TEXT_MANAGER__
#define __TEXT_MANAGER__
class TextManager {
public:
	static void small(GLfloat x, GLfloat y, const char* str, void* font = GLUT_BITMAP_TIMES_ROMAN_24);
	static void small(GLfloat x, GLfloat y, string, void* font = GLUT_BITMAP_TIMES_ROMAN_24);
	// Draw Big texts
	static void big(GLfloat x, GLfloat y, const char* str, GLfloat size = 1.0, void* font = GLUT_STROKE_ROMAN);

	// Overloaded
	static void big(GLfloat x, GLfloat y, string str, GLfloat size = 1.0, void* font = GLUT_STROKE_ROMAN);
};
#endif
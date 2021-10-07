#include "Headers.h"
// Draw texts

void  TextManager::small(GLfloat x, GLfloat y, const char* str, void* font )	//GLUT_BITMAP_8_BY_13, GLUT_BITMAP_TIMES_ROMAN_24
{
	glRasterPos3d(x, y, 0);
	GLint i;
	for (i = 0; str[i]; i++) {
		glutBitmapCharacter(font, str[i]);
	}
}
void TextManager::small(GLfloat x, GLfloat y, string str, void* font)	//GLUT_BITMAP_8_BY_13, GLUT_BITMAP_TIMES_ROMAN_24
{
	glRasterPos3d(x, y, 0);
	GLint i;
	for (i = 0; str[i]; i++) {
		glutBitmapCharacter(font, str[i]);
	}
}
// Draw Big texts
void TextManager::big(GLfloat x, GLfloat y, const char* str, GLfloat size, void* font)
{
	glPushMatrix();
	glTranslatef(x, y, 0);
	glScalef(size, size, 1.0);
	GLint i;
	for (i = 0; str[i]; i++)
		glutStrokeCharacter(font, str[i]); // GLUT_STROKE_ROMAN  , GLUT_STROKE_MONO_ROMAN
	glPopMatrix();
}
// Overloaded
void TextManager::big(GLfloat x, GLfloat y, string str, GLfloat size, void* font)
{
	glPushMatrix();
	glTranslatef(x, y, 0);
	glScalef(size, size, 1.0);
	GLint i;
	for (i = 0; str[i]; i++)
		glutStrokeCharacter(font, str[i]); // GLUT_STROKE_ROMAN  , GLUT_STROKE_MONO_ROMAN
	glPopMatrix();
}
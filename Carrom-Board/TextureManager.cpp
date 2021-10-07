#include "Headers.h"
#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#endif



void TextureManager::load()
{
	cout << filename << endl;
	int width, height, bpp;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(filename.c_str(), &width, &height, &bpp, 4);

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, this->texture);

	cout << "->" << this->texture << endl;
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexImage2D(GL_TEXTURE_2D,
		0,
		GL_RGBA,
		width, height,
		0,
		GL_RGBA,
		GL_UNSIGNED_BYTE,
		data);

	cout << "->" << this->texture << endl;
	glBindTexture(GL_TEXTURE_2D, 0);
	stbi_image_free(data);
	cout << "->" << this->texture << endl;
	
}
unsigned int TextureManager::load(const char* filename)
{
  int width, height, bpp;
  unsigned int texture2;
  stbi_set_flip_vertically_on_load(true);
  unsigned char* data = stbi_load(filename, &width, &height, &bpp, 4);

  glGenTextures(1, &texture2);
  glBindTexture(GL_TEXTURE_2D, texture2);

  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

  glTexImage2D(GL_TEXTURE_2D,
               0,
               GL_RGBA,
               width, height,
               0,
               GL_RGBA,
               GL_UNSIGNED_BYTE,
               data);

  glBindTexture(GL_TEXTURE_2D, 0);
  stbi_image_free(data);

  return texture2;
}
void TextureManager::render(GLdouble x,GLdouble y, GLint width, GLint height)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, getTexture());

	glBegin(GL_QUADS);

	glTexCoord2f(0, 0);
	glVertex2f(x, y);

	glTexCoord2f(1, 0);
	glVertex2f(x + width, y);

	glTexCoord2f(1, 1);
	glVertex2f(x + width, y + height);

	glTexCoord2f(0, 1);
	glVertex2f(x, y + height);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);
}
void TextureManager::render(GLdouble x, GLdouble y, GLint width, GLint height, const char* filename)
{
	unsigned int texture = load(filename);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);

	glBegin(GL_QUADS);

	glTexCoord2f(0, 0);
	glVertex2f(x, y);

	glTexCoord2f(1, 0);
	glVertex2f(x + width, y);

	glTexCoord2f(1, 1);
	glVertex2f(x + width, y + height);

	glTexCoord2f(0, 1);
	glVertex2f(x, y + height);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);
}

/*	glGenTextures(1, &texture);

	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Load image
	GLint n;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* image = stbi_load(filename, &width, &height, &n, 0);
	if (image == NULL) cout << "ERROR LOADING IMAGE" << endl;
	if (n == 4)	// PNG
	{
		glTexImage2D(
			GL_TEXTURE_2D,
			0,
			GL_RGBA,
			width,
			height,
			0,
			GL_RGBA,
			GL_UNSIGNED_BYTE,
			image
		);
	}
	else if (n == 3)  // JPG
	{
		glTexImage2D(
			GL_TEXTURE_2D,
			0,
			GL_RGB,
			width,
			height,
			0,
			GL_RGB,
			GL_UNSIGNED_BYTE,
			image
		);
	}
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	stbi_image_free(image);
*/

unsigned int iLoadImage(char filename[])
{
	int width, height, bpp;

	unsigned int texture;

	BYTE* data(0);
	data = stbi_load(filename, &width, &height, &bpp, 4);

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D,
		0,
		GL_RGBA,
		width, height,
		0,
		GL_RGBA,
		GL_UNSIGNED_BYTE,
		data);

	stbi_image_free(data);

	return texture;
}

void iShowImage(int x, int y, int width, int height, unsigned int texture)
{

	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	glBegin(GL_QUADS);

		glTexCoord2f(0, 0);
		glVertex2f(x, y);

		glTexCoord2f(1, 0);
		glVertex2f(x + width, y);

		glTexCoord2f(1, -1);
		glVertex2f(x + width, y+height);

		glTexCoord2f(0, -1);
		glVertex2f(x, y + height);

	glEnd();

	glDisable(GL_TEXTURE_2D);
}

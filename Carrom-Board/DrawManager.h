#ifndef __DRAW_MANAGER__
#define __DRAW_MANAGER__
class DrawManager {
public:
	static void point(GLfloat x, GLfloat y, GLfloat size = 1.0)
	{
		int i, j;
		glPointSize(size);
		glBegin(GL_POINTS);
		glVertex2f(x, y);
		glEnd();
		glPointSize(1.0);
	}
	static void display(void)		// Display Callback
	{
		draw();
		glutSwapBuffers();
	}
	static void clear()	// Clears the screen
	{
		glClear(GL_COLOR_BUFFER_BIT);

	}

	static void line(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2)
	{
		glBegin(GL_LINE_STRIP);
		glVertex2f(x1, y1);
		glVertex2f(x2, y2);
		glEnd();
	}

	// Draw Circle
	static void circle(GLfloat x, GLfloat y, GLfloat r, GLint slices = 100)
	{
		// Draw circle filler
		GLfloat t, dt = 2 * PI / slices;
		glBegin(GL_LINE_STRIP);
		for (t = 0; t <= 2 * PI + dt; t += dt)
		{
			glVertex2f(x + r * cos(t), y + r * sin(t));
		}
		glEnd();
	}

	static void filledCircle(GLfloat x, GLfloat y, GLfloat r, GLint slices = 100)
	{
		// Draw circle filler
		GLfloat t, dt = 2 * PI / slices;
		glBegin(GL_POLYGON);
		for (t = 0; t <= 2 * PI + dt; t += dt)
		{
			glVertex2f(x + r * cos(t), y + r * sin(t));
		}
		glEnd();
	}

	// Draws a rectangle
	static void rectangle(GLfloat left, GLfloat bottom, GLfloat width, GLfloat height)
	{
		GLfloat x1, y1, x2, y2;
		x1 = left;
		y1 = bottom;
		x2 = x1 + width;
		y2 = y1 + height;

		glBegin(GL_LINE_STRIP);
		glVertex2f(x1, y1);
		glVertex2f(x2, y1);
		glVertex2f(x2, y2);
		glVertex2f(x1, y2);
		glVertex2f(x1, y1);
		glEnd();
	}
	static void filledRectangle(GLfloat left, GLfloat bottom, GLfloat width, GLfloat height)
	{
		GLfloat x1, y1, x2, y2;
		x1 = left;
		y1 = bottom;
		x2 = x1 + width;
		y2 = y1 + height;

		// Draw rectangle filler
		glBegin(GL_POLYGON);
		glVertex2f(x1, y1);
		glVertex2f(x2, y1);
		glVertex2f(x2, y2);
		glVertex2f(x1, y2);
		glVertex2f(x1, y1);
		glEnd();
	}

	static void polygon(double x[], double y[], int n)
	{
		int i;
		if (n < 3)return;
		glBegin(GL_LINE_LOOP);
		for (i = 0; i < n; i++) {
			glVertex2f(x[i], y[i]);
		}
		glEnd();
	}
	static void filledPolygon(double x[], double y[], int n)
	{
		int i;
		if (n < 3)return;
		glBegin(GL_POLYGON);
		for (i = 0; i < n; i++) {
			glVertex2f(x[i], y[i]);
		}
		glEnd();
	}

	static void draw();
};
#endif

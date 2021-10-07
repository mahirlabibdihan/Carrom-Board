#ifndef __D_ENGINE__
#define __D_ENGINE__
#include "Headers.h"
using namespace std;
class DEngine {
	
	GLdouble t, old_t;
	
	static void dReshapeCallback(int w, int h) {
		getSingleton()->dWindowHeight = h;
		getSingleton()->dWindowWidth = w;

		glViewport(0, 0, w, h);//resizing the window

		// Setup viewing volume
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		// L      R     B    T      N       F
		glOrtho( -w/2 , w/2 , -h/2 , h/2 , -w / 2, w / 2);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}
	static void dDisplayCallback() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
		getSingleton()->draw();
		glFlush();
	}
	static void dTimerCallback(int n) {
		singletonInstance->t = glutGet(GLUT_ELAPSED_TIME);
		getSingleton()->update(singletonInstance->t- singletonInstance->old_t);
		singletonInstance->old_t = singletonInstance->t;
		glutPostRedisplay();
		glutTimerFunc(n, dTimerCallback, n);
	}
	/*static void dMouseMoveCallback(int mx, int my) {
		getSingleton()->mouseMove(mx, getSingleton()->dWindowHeight - my);
		glFlush();
	}*/
	static void dMouseClickCallback(int button,int state,int mx, int my) {
		getSingleton()->mouseClick(button,state, mx - getSingleton()->dWindowWidth / 2, getSingleton()->dWindowHeight - my - getSingleton()->dWindowHeight/2);
		glFlush();
	}
	static void dMouseDragCallback(int mx, int my) {
		getSingleton()->mouseDrag(mx - getSingleton()->dWindowWidth/2, getSingleton()->dWindowHeight - my - getSingleton()->dWindowHeight/2);
		glFlush();
	}
	virtual void draw() = 0;
	virtual void init() = 0;
	virtual void update(GLdouble deltaTime)=0;
	//virtual void mouseMove(int mx, int my) = 0;
	virtual void mouseClick(int,int,int mx, int my) = 0;
	virtual void mouseDrag(int mx, int my) = 0;
	void dInit() {
		old_t = t = glutGet(GLUT_ELAPSED_TIME);
		init();
	}
protected:
	GLint dWindowHeight, dWindowWidth;
	class DMath {
	public:
		static GLdouble mySqrt(GLdouble n)
		{
			GLdouble l = 0.0, r = max(n, 1.0), m = 0;
			if (n < 0)
			{
				puts("Root of negative number not possible.");
				return 0;
			}
			while (r - l > .0000000001)
			{
				GLdouble temp = (l + r) / 2;
				if (m == temp) break;
				m = temp;
				if (m * m > n) r = m;
				else l = m;
			}

			return m;
		}

		static GLdouble thetaToRadian(GLdouble radian) {
			return (radian * PI) / 180;
		}
	};
	class DShape {
	public:
		static void circle(GLdouble x, GLdouble y, GLdouble r,bool border=false)
		{
			GLdouble t, dt = 2 * PI / 100;
			glBegin(GL_POLYGON);
			for (t = 0; t <= 2 * PI + dt; t += dt)
			{
				glVertex2d(x + r * cos(t), y + r * sin(t));
			}
			glEnd();

			if (border) {
				glColor3f(0, 0, 0);
				glBegin(GL_LINE_STRIP);
				for (t = 0; t <= 2 * PI + dt; t += dt)
				{
					glVertex2d(x + r * cos(t), y + r * sin(t));
				}
				glEnd();
			}
			
		}

		static void quad(GLdouble x, GLdouble y, GLdouble w, GLdouble h)
		{
			glBegin(GL_QUADS);
			glVertex2d(x, y);
			glVertex2d(x + w, y);
			glVertex2d(x + w, y + h);
			glVertex2d(x, y + h);
			glEnd();
		}
		static void point(GLdouble x, GLdouble y, GLdouble r = 1) {
			glPointSize(r);
			glBegin(GL_POINTS);
			glVertex2d(x, y);
			glEnd();
		}
		static void line(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2)
		{
			glBegin(GL_LINES);
			glVertex2d(x1, y1);
			glVertex2d(x2, y2);
			glEnd();
		}

	};
	static void dSetColor(GLfloat r, GLfloat g, GLfloat b) {
		r /= 255.0;
		g /= 255.0;
		b /= 255.0;
		glColor3f(r, g, b);
	}
	static DEngine* singletonInstance;
	DEngine() { 
		t = old_t = 0;
		dWindowHeight = dWindowWidth = 500;
		cout << "Created Engine" << endl;
	}
public:
	GLint dGetWindowWidth() {
		return dWindowWidth;
	}
	GLint dGetWindowHeight() {
		return dWindowHeight;
	}
	void run(int argc, char** argv);
	static DEngine* getSingleton() {
		return singletonInstance;
	}
};
#endif
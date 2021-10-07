#include "DEngine.h"
DEngine* DEngine::singletonInstance;

void DEngine::run(int argc, char** argv) {
	dWindowWidth = 700;
	dWindowHeight = 700;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(550, 150);
	glutInitWindowSize(dWindowWidth, dWindowHeight);
	glutCreateWindow("Carrom-Board");
	glutDisplayFunc(dDisplayCallback);
	glutReshapeFunc(dReshapeCallback);
	glutTimerFunc(100, dTimerCallback, 1);
	glutMouseFunc(dMouseClickCallback);
	glutMotionFunc(dMouseDragCallback);
	// glutPassiveMotionFunc(dMouseMoveCallback);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	glPointSize(3.0);
	glEnable(GL_POINT_SMOOTH);
	glLineWidth(3.0);
	glEnable(GL_LINE_SMOOTH);
	glutFullScreen();
	dInit();
	// glutSetCursor(GLUT_CURSOR_NONE);
	glutMainLoop();
}
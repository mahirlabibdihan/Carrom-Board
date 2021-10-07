#include "Headers.h"
GLint WindowManager::width;
GLint WindowManager::height;
GLint WindowManager::x;
GLint WindowManager::y;
void WindowManager::set()
 {
	// Setting position of GameManager::window
	setX(0);
	setY(0);

	// Setting GameManager::window bounspeed
	setHeight(GetSystemMetrics(SM_CYSCREEN));
	setWidth(GetSystemMetrics(SM_CXSCREEN));

	// Setting window background ColorManager
	ColorManager::setBG(BLACK);
}

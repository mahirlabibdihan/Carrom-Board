#ifndef __KEYBOARD_MANAGER__
#define __KEYBOARD_MANAGER__
class KeyboardManager {
	public:
	static void keyHandler(unsigned char, GLint, GLint);
	static void specialKeyHandler(GLint, GLint, GLint);
	static void keyboard(unsigned char);
	static void specialKeyboard(unsigned char);
};
#endif
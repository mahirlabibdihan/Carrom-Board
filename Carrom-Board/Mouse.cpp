#include "Carrom.h"

void Carrom::mouseClick(int button,int state,int mx, int my) {
	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN) {
			/*for (Piece p : pieces) {
				if (p.getVx() != 0 || p.getVy() != 0)
					return;
			}*/
			if (striker.getVx() != 0 || striker.getVy() != 0) return;
			if (striker.isPointInCircle(mx, my)) {
				striker.drag();
			}
		}
		else if(state == GLUT_UP){
			if (striker.isdragged()) {
				striker.drop();
			}
		}
	 }
}
void Carrom::mouseDrag(int mx, int my) {
	if (striker.isdragged()) {
		// striker.setXY(mx, my);
		striker.setVx(3.0f * (striker.getX() - mx));
		striker.setVy(3.0f * (striker.getY() - my));
	}
}
#include "Carrom.h"
#include "AudioManager.h"
#include "TextureManager.h"

void Carrom::wrap(Piece &p) {
	// Wrap the balls around screen
	if (p.getX() < board.getLowerX() + p.getRadius()) {
		p.setX(board.getLowerX() + p.getRadius());
		p.reverseVx();
	}
	if (p.getX() > board.getUpperX() - p.getRadius()) {
		p.setX(board.getUpperX() - p.getRadius());
		p.reverseVx();
	}
	if (p.getY() < board.getLowerY() + p.getRadius()) {
		p.setY(board.getLowerY() + p.getRadius());
		p.reverseVy();
	}
	if (p.getY() > board.getUpperY() - p.getRadius()) {
		p.setY(board.getUpperY() - p.getRadius());
		p.reverseVy();
	}
}
void Carrom::update(GLdouble dt) {
	// Move all pieces
	if (!striker.isdragged()) {
		striker.move(dt);
		wrap(striker);
	}
	for (Piece& p : pieces) {
		p.move(dt);
		wrap(p);
	}

	// Collision
	for (Piece& p : pieces) {
		if (striker.doCirclesOverlap(p)) {
			AudioManager::play("assets//sounds//collision.wav");
			striker.collision(p);
		}
		for (Piece& q : pieces) {
			if (p.id != q.id) {
				if (p.doCirclesOverlap(q)) {
					//AudioManager::play("assets//sounds//collision.wav");
					p.collision(q);
				}
			}
		}
	}

	// Pocket
	for (int i = 0; i < pieces.size(); i++) {
		Circle c(6);

		c.setXY(board.getLowerX()+22.5, board.getLowerY() + 22.5);
		if (c.isPointInCircle(pieces[i].getX(), pieces[i].getY())) {
			pieces.erase(pieces.begin() + i--);
			AudioManager::play("assets//sounds//drop.wav");
			continue;
		}
		c.setXY(board.getUpperX() - 22.5, board.getLowerY() + 22.5);
		if (c.isPointInCircle(pieces[i].getX(), pieces[i].getY())) {
			pieces.erase(pieces.begin() + i--);
			AudioManager::play("assets//sounds//drop.wav");
			continue;
		}
		c.setXY(board.getUpperX() - 22.5, board.getUpperY() - 22.5);
		if (c.isPointInCircle(pieces[i].getX(), pieces[i].getY())) {
			pieces.erase(pieces.begin() + i--);
			AudioManager::play("assets//sounds//drop.wav");
			continue;
		}
		c.setXY(board.getLowerX() + 22.5, board.getUpperY() - 22.5);
		if (c.isPointInCircle(pieces[i].getX(), pieces[i].getY())) {
			pieces.erase(pieces.begin() + i--);
			AudioManager::play("assets//sounds//drop.wav");
			continue;
		}
	}
}
void Carrom::init() {

	TextureManager::init();
	board.init();
	pieces.push_back(Piece(3, 0, 0));    // Queen
	striker.setXY(0, -dWindowHeight / 2 + board.getHeight() / 5);
	striker.init();


	// Black
	{
		GLdouble theta = 120;
		GLdouble r = 4.0 * pieces[0].getRadius();

		GLdouble x = 0, y = 0;
		x += r * cos(DMath::thetaToRadian(theta)), y += r * sin(DMath::thetaToRadian(theta));
		pieces.push_back(Piece(2, x, y));

		theta += 60;
		theta += 60;
		for (int i = 0; i < 5; i++, theta += 60) {
			cout << theta << endl;
			x += r * cos(DMath::thetaToRadian(theta)), y += r * sin(DMath::thetaToRadian(theta));
			pieces.push_back(Piece(2, x, y));
		}

		{
			GLdouble theta = 60;
			GLdouble r = 2.0 * pieces[0].getRadius();

			GLdouble x = 0, y = 0;
			x += r * cos(DMath::thetaToRadian(theta)), y += r * sin(DMath::thetaToRadian(theta));
			pieces.push_back(Piece(2, x, y));

			theta += 30;
			theta += 120;
			r = 2.0 * sqrt(3) * pieces[0].getRadius();
			for (int i = 0; i < 2; i++, theta += 120) {
				x += r * cos(DMath::thetaToRadian(theta)), y += r * sin(DMath::thetaToRadian(theta));
				pieces.push_back(Piece(2, x, y));
			}
		}
	}

	// White
	{
		GLdouble theta = 90;
		GLdouble r = 2.0 * sqrt(3) * pieces[0].getRadius();

		GLdouble x = 0, y = 0;
		x += r * cos(DMath::thetaToRadian(theta)), y += r * sin(DMath::thetaToRadian(theta));
		pieces.push_back(Piece(1, x, y));

		theta += 60;
		theta += 60;
		for (int i = 0; i < 5; i++, theta += 60) {
			x += r * cos(DMath::thetaToRadian(theta)), y += r * sin(DMath::thetaToRadian(theta));
			pieces.push_back(Piece(1, x, y));
		}

		{
			GLdouble theta = 120;
			GLdouble r = 2.0 * pieces[0].getRadius();

			GLdouble x = 0, y = 0;
			x += r * cos(DMath::thetaToRadian(theta)), y += r * sin(DMath::thetaToRadian(theta));
			pieces.push_back(Piece(1, x, y));

			theta += 30;
			theta += 120;
			r = 2.0 * sqrt(3) * pieces[0].getRadius();
			for (int i = 0; i < 2; i++, theta += 120) {
				x += r * cos(DMath::thetaToRadian(theta)), y += r * sin(DMath::thetaToRadian(theta));
				pieces.push_back(Piece(1, x, y));
			}
		}
	}
	for (Piece p : pieces) {
		p.init();
	}

}
void Carrom::draw() {

	board.draw();

	for (Piece p : pieces) {
			p.draw();
	}

	glPushMatrix();
	glTranslatef(striker.getX(), striker.getY(), 0);
	glRotatef(180 * atan2f(striker.getVy(), striker.getVx()) / PI, 0, 0, 1);
	dSetColor(50, 50, 50);
	if (striker.isdragged()) {
		glBegin(GL_POLYGON);
		//DShape::line(0, 0, striker.getRadius(), 0);
		glVertex2d(striker.getRadius(), -5);
		glVertex2d(striker.getRadius() + 10, 0);
		glVertex2d(striker.getRadius(), 5);
		glEnd();
	}
	glPopMatrix();

	striker.draw();
}

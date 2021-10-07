#include "Headers.h"
#include "Externs.h"
GLfloat deathOpacity = 0.1f, dp = .004f;
int frame, timebase, timeBrick, timeDeath, timeLevelUp;

void TimeManager::update(GLint t)		// Game screen update
{
	if (timebase == 0)
	{
		timeBrick = timebase = glutGet(GLUT_ELAPSED_TIME);
	}
	int time = glutGet(GLUT_ELAPSED_TIME);
	if (glutGet(GLUT_ELAPSED_TIME) - timebase > 1)
	{
		if (menu.getMenu() == MenuManager::GAME && !GameManager::isPaused())
		{
			for (int i = 0; i < balls.getTotal(); i++)
			{
				if (!balls.getCell(i).isOnPaddle())
				{
					CollisionManager::ballXpaddle(i);
				}
			}
			CollisionManager::paddleXpowerUp();
			CollisionManager::ballXbrick();
			CollisionManager::bulletXbrick();
			balls.update();
			powerUps.update();
			bullets.update();
			if (board.getX() > field.getX())
			{
				board.setX(board.getX() - 5);
			}

			if (glutGet(GLUT_ELAPSED_TIME) - timeBrick > 20)
			{
				bricks.update();
				timeBrick = glutGet(GLUT_ELAPSED_TIME);
				if (CollisionManager::isBallXPaddle)
				{
					paddle.setY(0);
					CollisionManager::isBallXPaddle = false;
				}
				else if (paddle.getY() == 0)
				{
					paddle.setY(20);
				}
				else if (paddle.getY() == 20)
				{
					paddle.setY(10);
				}
			}

			GameManager::incTimer();
		}
		else if (menu.getMenu() == MenuManager::DEATH)
		{
			if (1 - deathOpacity < 0.001f)
			{
				dp *= -1;
				GameManager::reset();
				GameManager::save();
			}
			deathOpacity += dp;
			if (deathOpacity<.001f && dp<0)
			{
				MouseManager::setXY(paddle.getX(), paddle.getY());
				menu.setMenu(MenuManager::GAME);
				deathOpacity = .1;
				dp *= -1;
			}
			if (glutGet(GLUT_ELAPSED_TIME) - timeBrick > 20)
			{
				bricks.update();
				timeBrick = glutGet(GLUT_ELAPSED_TIME);
			}
		}
		else if (menu.getMenu() == MenuManager::LEVEL_UP)
		{
			if (glutGet(GLUT_ELAPSED_TIME) - timeLevelUp > 1000)
			{
				menu.setMenu(MenuManager::GAME);
				LevelManager::levelUp();
			}
		}
		timebase = glutGet(GLUT_ELAPSED_TIME);
	}


	glutPostRedisplay();
	glutTimerFunc(t, update, t);
}
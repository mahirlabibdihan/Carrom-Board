
/*------------------------------------------------------------------------------ D R A W I N G S -------------------------------------------------------------------------------*/
#include "Headers.h"
#include "Externs.h"

void DrawManager::draw()
{
	clear();
	if (menu.getMenu() == MenuManager::MAIN)
	{
		menu.draw();
	}
	else if (menu.getMenu() == MenuManager::NAME_ENTRY)
	{
		menu.drawNameEntry();
		menu.drawBack();
	}
	else if (menu.getMenu() == MenuManager::CUSTOM_GAME)
	{
		menu.drawCustom();
		menu.drawBack();
	} 

	else if (menu.getMenu() == MenuManager::HIGH_SCORE)
	{
		menu.drawHighScore();
		menu.drawBack();
	}
	else if (menu.getMenu() == MenuManager::HELP_PAGE)
	{
		menu.drawHelp();
		menu.drawBack();
	}
	else if (menu.getMenu() == MenuManager::QUIT_GAME)
	{
		menu.drawQuit();
	}
	else if (menu.getMenu() == MenuManager::GAME_OVER)
	{
		menu.drawGameOver();
		if(LevelManager::getLevel()>0)menu.drawBack();
	}
	else if (menu.getMenu() == MenuManager::WINNER)
	{
		menu.drawWin();
		if (LevelManager::getLevel() > 0)menu.drawBack();
	}
	else if (menu.getMenu() == MenuManager::GAME || menu.getMenu() == MenuManager::DEATH)
	{
		menu.drawGame();
	}
	else if (menu.getMenu() == MenuManager::LEVEL_UP)
	{
		menu.drawLevelUp();
	}
	if (menu.getMenu() != MenuManager::GAME
		&& menu.getMenu() != MenuManager::DEATH 
		&& menu.getMenu() != MenuManager::LEVEL_UP 
		&& menu.getMenu() != MenuManager::QUIT_GAME 
		&& !(LevelManager::getLevel()==0&&(menu.getMenu()==MenuManager::GAME_OVER|| menu.getMenu() == MenuManager::WINNER)))
	{
		TextureManager::render(MouseManager::getX(), MouseManager::getY() - 35, "Data\\Image\\Mouse.png");
	}
		
}

/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

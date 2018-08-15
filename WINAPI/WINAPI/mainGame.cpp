#include "Game.h"
#include "mainGame.h"
#include "utill.h"
#include "background.h"
#include "block.h"
#include "mob.h"
#include "player.h"

background Background;
player	   Player;
block	   Block;

mainGame::mainGame()
{
}

mainGame::~mainGame()
{
}

//===========================================================================

HRESULT mainGame::init()
{
	GameNode::init(true);

	//===================================================================

	Background.backgroundInit();
	
	Player.marioInit();

	Block.blockInit();
	
	_pPlayer = new POINT;
	_pPlayer->x = WINSIZEX / 2 - 200;
	_pPlayer->y = WINSIZEY - 100;
	

	if (CAMERA->init(_pPlayer, Background.getClient(), Background.getWorld()) == false)
		return false;

	//===================================================================

	return S_OK;
}

void mainGame::release()
{
	GameNode::release();
}

void mainGame::update()
{
	GameNode::update();
	
	//===================================================================

	Player.marioUpdate();

	_pPlayer->x = Player.getmarioX();
	_pPlayer->y = Player.getmarioY();

	CAMERA->update();

	//===================================================================

}

void mainGame::render()
{
	//HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(getMemDC(), 0, 0, Background.getClient().right, Background.getClient().bottom, WHITENESS);

	//===================================================================

	Background.backgroundRender(getMemDC());
	
	Player.marioRender(getMemDC());

	Block.blockRender(getMemDC());

	
	TCHAR szTemp[100] = { 0, };
	_stprintf_s(szTemp, sizeof(szTemp), TEXT("pos %d, %d   target %d, %d"), CAMERA->getPosition()->x, CAMERA->getPosition()->y, CAMERA->getTargetPos()->x, CAMERA->getTargetPos()->y);
	TextOut(getMemDC(), 20, 20, szTemp, _tcslen(szTemp));
	

	//===================================================================
	this->getBackBuffer()->render(getHDC(), 0, 0);
}

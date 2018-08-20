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
	
	_pPlayerCoordinate = new POINT;
	_pPlayerCoordinate->x = WINSIZEX / 2 - 200;
	_pPlayerCoordinate->y = WINSIZEY - 100;


	if (CAMERA->init(_pPlayerCoordinate, Background.getClient(), Background.getWorld()) == false)
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

	_pPlayerCoordinate->x = Player.getmarioX();
	_pPlayerCoordinate->y = Player.getmarioY();

	Player.marioUpdate();
	
	CAMERA->update();

	Block.blockCollision(&Player);

	GetCursorPos(&_pt);

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
	_stprintf_s(szTemp, sizeof(szTemp), TEXT("pos %d, %d   target %d, %d  mouse %d, %d  block %d, %d, %d, %d"),
		CAMERA->getPosition()->x, CAMERA->getPosition()->y, CAMERA->getTargetPos()->x, CAMERA->getTargetPos()->y,
		_pt.x, _pt.y, Player.marioRect().left, Player.marioRect().top, Player.marioRect().right, Player.marioRect().bottom);
	TextOut(getMemDC(), 20, 20, szTemp, _tcslen(szTemp));
	

	//===================================================================
	this->getBackBuffer()->render(getHDC(), 0, 0);
}

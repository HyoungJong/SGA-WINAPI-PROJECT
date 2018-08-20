#include "Game.h"
#include "mainGame.h"
#include "util.h"
#include "background.h"
#include "block.h"
#include "mob.h"
#include "player.h"
#include "collision.h"

background Background;
player	   Player;
block	   Block;
mob		   Mob;
collision  Collision;

mainGame::mainGame()
{
}

mainGame::~mainGame()
{
}

//===========================================================================

HRESULT mainGame::init()
{
	gameNode::init(true);

	//===================================================================

	// 각 클래스 init
	Background.backgroundInit();
	Player.marioInit();
	Block.blockInit();
	Mob.mobInit();
	Collision.collsioninit();

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
	gameNode::release();
}

void mainGame::update()
{
	gameNode::update();

	//===================================================================

	// 카메라 업데이트
	_pPlayerCoordinate->x = Player.getmarioX();
	_pPlayerCoordinate->y = Player.getmarioY();
	CAMERA->update();


	// 각 클레스 업데이트
	Player.marioUpdate();
	Block.blockMove();
	Mob.mobUpdate();
	Collision.Collisions(&Player, &Block, &Mob);

	//===================================================================

}

void mainGame::render()
{
	PatBlt(getMemDC(), 0, 0, Background.getClient().right, Background.getClient().bottom, WHITENESS);

	//===================================================================

	// 각 클레스 렌더
	Background.backgroundRender(getMemDC());
	Player.marioRender(getMemDC());
	Block.blockRender(getMemDC());
	Mob.mobRender(getMemDC());
	
	/*
	// 텍스트 출력
	TCHAR szTemp[100] = { 0, };
	_stprintf_s(szTemp, sizeof(szTemp), TEXT("원하는 값  %d, %d"),
		(Mob.mushroomRect().left + Mob.mushroomRect().right) / 2, (Player.marioRect().left + Player.marioRect().right)/2);
	TextOut(getMemDC(), 20, 20, szTemp, _tcslen(szTemp));
	*/

	//===================================================================
	this->getBackBuffer()->render(getHDC(), 0, 0);
}

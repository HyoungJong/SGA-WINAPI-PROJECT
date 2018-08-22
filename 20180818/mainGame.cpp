#include "Game.h"
#include "mainGame.h"
#include "util.h"
#include "background.h"
#include "block.h"
#include "mob.h"
#include "player.h"
#include "collision.h"
#include "Effects.h"

background Background;
player	   Player;
block	   Block;
mob		   Mob;
collision  Collision;
Effects	   effects;

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
	Mob.mobRender(getMemDC());
	Block.blockRender(getMemDC());
	Player.marioRender(getMemDC());
	Block.blockRenderAfterPlayer(getMemDC());
	
	
	
	// 텍스트 출력
	
	TCHAR szTemp[100] = { 0, };
	_stprintf_s(szTemp, sizeof(szTemp), TEXT("원하는 값  %f, %f , %d, %d, %d, %d"),
		Player.getmarioX(), Player.getmarioY(), CAMERA->getPosition()->x, CAMERA->getPosition()->y,
		_pPlayerCoordinate->x, _pPlayerCoordinate->y);
	TextOut(getMemDC(), 20, 20, szTemp, _tcslen(szTemp));
	

	//===================================================================
	this->getBackBuffer()->render(getHDC(), 0, 0);
}

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

	// �� Ŭ���� init
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

	// ī�޶� ������Ʈ
	_pPlayerCoordinate->x = Player.getmarioX();
	_pPlayerCoordinate->y = Player.getmarioY();
	CAMERA->update();


	// �� Ŭ���� ������Ʈ
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

	// �� Ŭ���� ����
	Background.backgroundRender(getMemDC());
	Player.marioRender(getMemDC());
	Block.blockRender(getMemDC());
	Mob.mobRender(getMemDC());
	
	/*
	// �ؽ�Ʈ ���
	TCHAR szTemp[100] = { 0, };
	_stprintf_s(szTemp, sizeof(szTemp), TEXT("���ϴ� ��  %d, %d"),
		(Mob.mushroomRect().left + Mob.mushroomRect().right) / 2, (Player.marioRect().left + Player.marioRect().right)/2);
	TextOut(getMemDC(), 20, 20, szTemp, _tcslen(szTemp));
	*/

	//===================================================================
	this->getBackBuffer()->render(getHDC(), 0, 0);
}

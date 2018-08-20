#include "Game.h"
#include "StartScene.h"



StartScene::StartScene()
{
}


StartScene::~StartScene()
{
}


HRESULT StartScene::init()
{
	
	_rc = { 100,100,300,300 };
	return S_OK;
}

void StartScene::release()
{
	
}

void StartScene::update()
{
	
	_rc = { 100,100,300,300 };
}

void StartScene::render()
{
	//===================================================================

	Rectangle(getMemDC(), _rc.left, _rc.top, _rc.right, _rc.bottom);

	
}




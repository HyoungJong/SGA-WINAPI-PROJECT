#include "Game.h"
#include "background.h"
#include "Image.h"



background::background()
{
}


background::~background()
{
}

void background::backgroundInit()
{
	_background = IMAGEMANAGER->addImage(TEXT("BackGround"), TEXT("2STAGE.bmp"), 1424, 223, true, RGB(255, 0, 255));

	_rcWorld = { 0,0,1424,223 };
	_rcClient = { 0,0,WINSIZEX, WINSIZEY };
}

void background::backgroundRender(HDC _hdc)
{
	_background->render(_hdc, 0, 0, CAMERA->getPosition()->x, CAMERA->getPosition()->y, WINSIZEX, WINSIZEY);
}


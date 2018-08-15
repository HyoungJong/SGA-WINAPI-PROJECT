#include "Game.h"
#include "player.h"



player::player()
{
}


player::~player()
{
}

void player::marioInit()
{
	_mario = IMAGEMANAGER->addFrameImage(TEXT("Mario"), TEXT("MarioBasic.bmp"), 840, 156, 14, 2, true, RGB(255, 0, 255));

	// 초기 위치
	_mario->setX(20);
	_mario->setY(150);

	_marioIndex = 0;
	_marioCount = 0;
	_marioDirection = RIGHT;
}

void player::marioUpdate()
{
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_marioCount++;
		_marioDirection = RIGHT;
		_mario->setX(_mario->getX() + 6);
		if (_marioCount == 3)
		{
			_marioCount = 0;
			_marioIndex++;
		}			
		if (_marioIndex > 3)
			_marioIndex = 0;
		_mario->setFrameY(_marioDirection);
		_mario->setFrameX(_marioIndex);
	}

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_marioCount++;
		_marioDirection = LEFT;
		_mario->setX(_mario->getX() - 6);
		if (_marioCount == 3)
		{
			_marioCount = 0;
			_marioIndex--;
		}
		if (_marioIndex < 10)
			_marioIndex = 13;
		_mario->setFrameY(_marioDirection);
		_mario->setFrameX(_marioIndex);
	}

	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_mario->setY(_mario->getY() - 3);
	}

	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_mario->setY(_mario->getY() + 3);
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{

	}
	
}

void player::marioRender(HDC _hdc)
{
	IMAGEMANAGER->frameRender(TEXT("Mario"), _hdc, _mario->getX() - CAMERA->getPosition()->x, _mario->getY() - CAMERA->getPosition()->y, _mario->getFrameX(), _mario->getFrameY());
}

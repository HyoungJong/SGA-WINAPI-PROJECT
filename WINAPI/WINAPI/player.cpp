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
	_mario = IMAGEMANAGER->addFrameImage(TEXT("Mario"), TEXT("MarioBasic.bmp"), 420, 48, 12, 2, true, RGB(255, 0, 255));

	// 초기 위치
	_mario->setX(20);
	_mario->setY(150);

	_marioIndex = 6;
	_marioCount = 0;
	_marioMotion = 0;
}

void player::marioUpdate()
{
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_mario->setX(_mario->getX() + 2);
		_marioIndex++;
		if (_marioIndex < 6 || _marioIndex > 11)
			_marioIndex = 6;
		_mario->setFrameY(0);
		_mario->setFrameX(_marioIndex);
	}

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_mario->setX(_mario->getX() - 2);
		_marioIndex--;
		if (_marioIndex < 0 || _marioIndex > 5)
			_marioIndex = 5;
		_mario->setFrameY(0);
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
	/*
	_marioCount++;
	if (_marioCount % 10 == 0)
	{
		if (_marioDirection == LEFT)
		{
			if (_marioIndex <= 0)
				_marioIndex = 5;
			_marioIndex--;
			_mario->setFrameX(_marioIndex);
		}
		else if (_marioDirection == RIGHT)
		{
			if (_marioIndex >= _mario->getMaxFrameX())
				_marioIndex = 2;
			_marioIndex++;
			_mario->setFrameX(_marioIndex);
		}
		_marioCount = 0;
	}
	*/
}

void player::marioRender(HDC _hdc)
{
	IMAGEMANAGER->frameRender(TEXT("Mario"), _hdc, _mario->getX() - CAMERA->getPosition()->x, _mario->getY() - CAMERA->getPosition()->y, _mario->getFrameX(), _mario->getFrameY());
}

#include "Game.h"
#include "mainGame.h"
#include "Image.h"
#include "utill.h"
//test

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

	GetClientRect(g_hWnd, &_rcClient);

	//===================================================================

	_background = IMAGEMANAGER->addImage(TEXT("BackGround"), TEXT("space.bmp"), 1920, 1080, true, RGB(255, 0, 255));

	_siva = IMAGEMANAGER->addFrameImage(TEXT("SivaRun"), TEXT("Sivarun.bmp"), 440, 108, 8, 2, true, RGB(255, 0, 255));

	// 초기 위치
	_siva->setX(WINSIZEX / 2 - 200);
	_siva->setY(WINSIZEY - 100);

	_pPlayer = new POINT;
	_pPlayer->x = WINSIZEX / 2 - 200;
	_pPlayer->y = WINSIZEY - 100;

	_sivaIndex = 2;
	_sivaCount = 0;
	_sivaDirection = RIGHT;

	_rcWorld = { 0,0,1920,1080 };
	_rcClient = { 0,0,WINSIZEX, WINSIZEY };

	if (CAMERA->init(_pPlayer, _rcClient, _rcWorld) == false)
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

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_siva->setX(_siva->getX() + 3);
		_pPlayer->x += _sivaDirection = RIGHT;
		if (_sivaIndex < 2)
			_sivaIndex = 2;
		_siva->setFrameY(RIGHT);
	}

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_siva->setX(_siva->getX() - 3);
		_sivaDirection = LEFT;
		if (_sivaIndex > 5)
			_sivaIndex = 5;
		_siva->setFrameY(LEFT);
	}

	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_siva->setY(_siva->getY() - 3);
	}

	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_siva->setY(_siva->getY() + 3);
	}

	_sivaCount++;
	if (_sivaCount % 10 == 0)
	{
		if (_sivaDirection == LEFT)
		{
			if (_sivaIndex <= 0)
				_sivaIndex = 5;
			_sivaIndex--;
			_siva->setFrameX(_sivaIndex);
		}
		else if (_sivaDirection == RIGHT)
		{
			if (_sivaIndex >= _siva->getMaxFrameX())
				_sivaIndex = 2;
			_sivaIndex++;
			_siva->setFrameX(_sivaIndex);
		}
		_sivaCount = 0;
	}

	_pPlayer->x = _siva->getX();
	_pPlayer->y = _siva->getY();

	CAMERA->update();

	//===================================================================

}

void mainGame::render()
{
	//HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(getMemDC(), 0, 0, _rcClient.right, _rcClient.bottom, WHITENESS);

	//===================================================================

	_background->render(getMemDC(), 0, 0, CAMERA->getPosition()->x, CAMERA->getPosition()->y, WINSIZEX, WINSIZEY);

	IMAGEMANAGER->frameRender(TEXT("SivaRun"), getMemDC(), _siva->getX() - CAMERA->getPosition()->x, _siva->getY() - CAMERA->getPosition()->y, _siva->getFrameX(), _siva->getFrameY());

	//===================================================================
	this->getBackBuffer()->render(getHDC(), 0, 0);
}

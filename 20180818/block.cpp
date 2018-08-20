#include "Game.h"
#include "block.h"
#include "Image.h"
#include "player.h"


block::block()
{
}


block::~block()
{
}

void block::blockInit()
{
	// 구름 발판
	for (int i = 0; i < MAX_CLOUDNUM; i++)
	{
		_block[i] = IMAGEMANAGER->addFrameImage(TEXT("Cloud%d", i), TEXT("Image//구름발판.bmp"), 292, 94, 1, 1, true, RGB(255, 0, 255));
		_block[i]->setX(1370);
		_block[i]->setY(200 + (200 * i));
	}

	/*
	_block[0] = IMAGEMANAGER->addFrameImage(TEXT("Cloud0"), TEXT("Image//구름발판.bmp"), 292, 94, 1, 1, true, RGB(255, 0, 255));
	_block[0]->setX(1370);
	_block[0]->setY(200);

	_block[1] = IMAGEMANAGER->addFrameImage(TEXT("Cloud1"), TEXT("Image//구름발판.bmp"), 292, 94, 1, 1, true, RGB(255, 0, 255));
	_block[1]->setX(1370);
	_block[1]->setY(400);

	_block[2] = IMAGEMANAGER->addFrameImage(TEXT("Cloud2"), TEXT("Image//구름발판.bmp"), 292, 94, 1, 1, true, RGB(255, 0, 255));
	_block[2]->setX(1370);
	_block[2]->setY(600);
	*/
	// 아래 땅
	_groundblock[0] = { 0, 712, 1350, 800 };
	_groundblock[1] = { 1685, 712, 2700, 800 };
	_groundblock[2] = { 2832, 712, 3505, 800 };
	_groundblock[3] = { 3640, 712, 4113, 800 };
	_groundblock[4] = { 4245, 712, 6000, 800 };

	// 2 ~ 3번 땅 사이에 있는 기둥
	_groundblock[5] = { 2701, 285, 2831, 800 };

	// 구름으로 가린 구간 블럭
	_groundblock[6] = { 4921, 655, 5597, 712 };
	_groundblock[7] = { 4988, 598, 5260, 655 };
	_groundblock[8] = { 5392, 598, 5529, 655 };
	_groundblock[9] = { 5055, 541, 5260, 598 };
}

void block::blockMove()
{
	for (int i = 0; i < MAX_CLOUDNUM; i++)
	{
		_block[i]->setY(_block[i]->getY() - 1);

		if (_block[i]->getY() < 200)
			_block[i]->setY(1000);
	}
}

void block::blockRender(HDC _hdc)
{
	// 구름 발판
	
	for (int i = 0; i < 3; i++)
	{
		IMAGEMANAGER->frameRender(TEXT("Cloud%d", i), _hdc, _block[i]->getX() - CAMERA->getPosition()->x, _block[i]->getY() - CAMERA->getPosition()->y, _block[i]->getFrameX(), _block[i]->getFrameY());
	}

	/*
	IMAGEMANAGER->frameRender(TEXT("Cloud0"), _hdc, _block[0]->getX() - CAMERA->getPosition()->x, 
		_block[0]->getY() - CAMERA->getPosition()->y, _block[0]->getFrameX(), _block[0]->getFrameY());

	IMAGEMANAGER->frameRender(TEXT("Cloud1"), _hdc, _block[1]->getX() - CAMERA->getPosition()->x,
		_block[1]->getY() - CAMERA->getPosition()->y, _block[1]->getFrameX(), _block[1]->getFrameY());

	IMAGEMANAGER->frameRender(TEXT("Cloud2"), _hdc, _block[2]->getX() - CAMERA->getPosition()->x,
		_block[2]->getY() - CAMERA->getPosition()->y, _block[2]->getFrameX(), _block[2]->getFrameY());
		*/

	// 충돌체 크기 보기
	if (KEYMANAGER->isToggleKey('T'))
	{
		for (int i = 0; i < MAX_GROUNDBLOCKNUM; i++)
			Rectangle(_hdc, _groundblock[i].left - CAMERA->getPosition()->x, _groundblock[i].top - CAMERA->getPosition()->y,
				_groundblock[i].right - CAMERA->getPosition()->x, _groundblock[i].bottom - CAMERA->getPosition()->y);

		for (int i = 0; i < MAX_CLOUDNUM; i++)
			Rectangle(_hdc, blockRect(i).left - CAMERA->getPosition()->x, blockRect(i).top - CAMERA->getPosition()->y,
				blockRect(i).right - CAMERA->getPosition()->x, blockRect(i).bottom - CAMERA->getPosition()->y);
	}
	
}

RECT block::groundblockRect(int blocknum)
{
	return _groundblock[blocknum];
}

RECT block::blockRect(int blocknum)
{
	RECT temp = _block[blocknum]->boundingBox();
	return temp;
}

#include "Game.h"
#include "block.h"
#include "Image.h"



block::block()
{
}


block::~block()
{
}

void block::blockInit()
{
	_block = IMAGEMANAGER->addFrameImage(TEXT("Block"), TEXT("º®3°³.bmp"), 205, 65, 1, 1, false, RGB(255, 0, 255));

	_block->setX(1000);
	_block->setY(600);
}

void block::blockRender(HDC _hdc)
{
	IMAGEMANAGER->frameRender(TEXT("Block"), _hdc, _block->getX() - CAMERA->getPosition()->x, _block->getY() - CAMERA->getPosition()->y, _block->getFrameX(), _block->getFrameY());
}

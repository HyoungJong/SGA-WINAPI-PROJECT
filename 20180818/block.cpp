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
	_groundblock[10] = { 5876, 600, 5930, 712 };


	// 구름 발판
	_block[0] = IMAGEMANAGER->addFrameImage(TEXT("Cloud%d", 0), TEXT("Image//구름발판.bmp"), 292, 94, 1, 1, true, RGB(255, 0, 255));
	_block[0]->setX(1370);
	_block[0]->setY(200);

	_block[1] = IMAGEMANAGER->addFrameImage(TEXT("Cloud1"), TEXT("Image//구름발판.bmp"), 292, 94, 1, 1, true, RGB(255, 0, 255));
	_block[1]->setX(1370);
	_block[1]->setY(500);

	_block[2] = IMAGEMANAGER->addFrameImage(TEXT("Cloud2"), TEXT("Image//구름발판.bmp"), 292, 94, 1, 1, true, RGB(255, 0, 255));
	_block[2]->setX(1370);
	_block[2]->setY(800);

	// 3칸짜리 블럭
	_block[3] = IMAGEMANAGER->addFrameImage(TEXT("ThreeBlock%d",0), TEXT("Image//벽3개.bmp"), 205, 65, 1, 1, true, RGB(255, 0, 255));
	_block[3]->setX(2050);
	_block[3]->setY(590);

	_block[4] = IMAGEMANAGER->addFrameImage(TEXT("ThreeBlock1"), TEXT("Image//벽3개.bmp"), 205, 65, 1, 1, true, RGB(255, 0, 255));
	_block[4]->setX(2350);
	_block[4]->setY(460);

	_block[5] = IMAGEMANAGER->addFrameImage(TEXT("ThreeBlock2"), TEXT("Image//벽3개.bmp"), 205, 65, 1, 1, true, RGB(255, 0, 255));
	_block[5]->setX(2050);
	_block[5]->setY(330);

	_block[6] = IMAGEMANAGER->addFrameImage(TEXT("ThreeBlock3"), TEXT("Image//벽3개.bmp"), 205, 65, 1, 1, true, RGB(255, 0, 255));
	_block[6]->setX(3800);
	_block[6]->setY(590);

	// 포탈
	_block[7] = IMAGEMANAGER->addFrameImage(TEXT("Portal%d", 0), TEXT("Image//포탈.bmp"), 66, 99, 1, 1, true, RGB(255, 0, 255));
	_block[7]->setX(2120);
	_block[7]->setY(230);

	_block[8] = IMAGEMANAGER->addFrameImage(TEXT("Portal1"), TEXT("Image//포탈.bmp"), 66, 99, 1, 1, true, RGB(255, 0, 255));
	_block[8]->setX(2980); 
	_block[8]->setY(613);

	// 떨어지는 파란블럭
	_block[9] = IMAGEMANAGER->addFrameImage(TEXT("BlueBlock%d",0), TEXT("Image//파란바닥.bmp"), 68, 88, 1, 1, false, RGB(255, 0, 255));
	_block[9]->setX(3505);
	_block[9]->setY(712);

	_block[10] = IMAGEMANAGER->addFrameImage(TEXT("BlueBlock1"), TEXT("Image//파란바닥.bmp"), 68, 88, 1, 1, false, RGB(255, 0, 255));
	_block[10]->setX(3573);
	_block[10]->setY(712);

	// 떨어지는 초록색기둥
	_block[11] = IMAGEMANAGER->addFrameImage(TEXT("GreenCylinder"), TEXT("Image//초록색기둥.bmp"), 140, 406, 1, 1, true, RGB(255, 0, 255));
	_block[11]->setX(4108);
	_block[11]->setY(500);

	// 다음 스테이지로가는 문
	_block[12] = IMAGEMANAGER->addFrameImage(TEXT("ToTheNextStage"), TEXT("Image//다음스테이지로.bmp"), 205, 209, 1, 1, true, RGB(255, 0, 255));
	_block[12]->setX(5800);
	_block[12]->setY(508);

	// 가리는 구름
	_tent = IMAGEMANAGER->addFrameImage(TEXT("Tent"), TEXT("Image//구름장막.bmp"), 761, 475, 1, 1, true, RGB(255, 0, 255));
	_tent->setX(4921);
	_tent->setY(300);

	for(int i = 0; i < MAX_FALLINGBLOCKNUM; i++)
		_trapOn[i] = 0;
}


void block::blockMove()
{
	// 구름 발판 이동
	for (int i = 0; i < MAX_CLOUDNUM; i++)
	{
		_block[i]->setY(_block[i]->getY() - 3);
		
		if (_block[i]->getY() < 200)
			_block[i]->setY(1000);	
	}
	
	// 떨어지는 파란블럭
	for (int i = 9; i < 9 + MAX_FALLINGBLOCKNUM; i++)
	{
		if (_trapOn[i - 9] == 1)
		{
			_block[i]->setY(_block[i]->getY() + 30);

			if (_block[i]->getY() > 1500)
				_block[i]->setY(1500);
		}
	}
}

void block::blockRender(HDC _hdc)
{
	int i;
	// 구름 발판
	for (i = 0; i < MAX_CLOUDNUM; i++)
	{
		IMAGEMANAGER->frameRender(TEXT("Cloud%d", i), _hdc, _block[i]->getX() - CAMERA->getPosition()->x, _block[i]->getY() - CAMERA->getPosition()->y, _block[i]->getFrameX(), _block[i]->getFrameY());
	}

	// 3칸 블럭, 포탈, 떨어지는 파랑블럭, 떨어지는 초록색기둥
	for (; i < MAX_CLOUDNUM + MAX_THREEBLOCKNUM + MAX_PORTALNUM + MAX_FALLINGBLOCKNUM + MAX_TOTHENEXTSTAGE; i++)
	{
		if(i > 11)
			IMAGEMANAGER->frameRender(TEXT("ToTheNextStage"), _hdc, _block[i]->getX() - CAMERA->getPosition()->x, _block[i]->getY() - CAMERA->getPosition()->y, _block[i]->getFrameX(), _block[i]->getFrameY());
		else if(i > 10)
			IMAGEMANAGER->frameRender(TEXT("GreenCylinder"), _hdc, _block[i]->getX() - CAMERA->getPosition()->x, _block[i]->getY() - CAMERA->getPosition()->y, _block[i]->getFrameX(), _block[i]->getFrameY());
		else if(i > 8)
			IMAGEMANAGER->frameRender(TEXT("BlueBlock%d", i), _hdc, _block[i]->getX() - CAMERA->getPosition()->x, _block[i]->getY() - CAMERA->getPosition()->y, _block[i]->getFrameX(), _block[i]->getFrameY());
		else if(i > 6)
			IMAGEMANAGER->frameRender(TEXT("Portal%d", i), _hdc, _block[i]->getX() - CAMERA->getPosition()->x, _block[i]->getY() - CAMERA->getPosition()->y, _block[i]->getFrameX(), _block[i]->getFrameY());
		else
			IMAGEMANAGER->frameRender(TEXT("ThreeBlock%d", i), _hdc, _block[i]->getX() - CAMERA->getPosition()->x, _block[i]->getY() - CAMERA->getPosition()->y, _block[i]->getFrameX(), _block[i]->getFrameY());
	}

	// 충돌체 크기 보기
	if (KEYMANAGER->isToggleKey('T'))
	{
		for (int i = 0; i < MAX_GROUNDBLOCKNUM; i++)
			Rectangle(_hdc, _groundblock[i].left - CAMERA->getPosition()->x, _groundblock[i].top - CAMERA->getPosition()->y,
				_groundblock[i].right - CAMERA->getPosition()->x, _groundblock[i].bottom - CAMERA->getPosition()->y);

		for (int i = 0; i < MAX_CLOUDNUM + MAX_THREEBLOCKNUM + MAX_PORTALNUM + MAX_FALLINGBLOCKNUM; i++)
			Rectangle(_hdc, blockRect(i).left - CAMERA->getPosition()->x, blockRect(i).top - CAMERA->getPosition()->y,
				blockRect(i).right - CAMERA->getPosition()->x, blockRect(i).bottom - CAMERA->getPosition()->y);
	}
	
}

void block::blockRenderAfterPlayer(HDC _hdc)
{
	 //가리는 구름
	IMAGEMANAGER->frameRender(TEXT("Tent"), _hdc, _tent->getX() - CAMERA->getPosition()->x, _tent->getY() - CAMERA->getPosition()->y, _tent->getFrameX(), _tent->getFrameY());
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
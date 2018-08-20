#include "Game.h"
#include "mob.h"

mob::mob()
{
}


mob::~mob()
{
}

void mob::mobInit()
{
	_mushroom = IMAGEMANAGER->addFrameImage(TEXT("Mushroom"), TEXT("Image//버섯.bmp"), 246, 72, 3, 1, true, RGB(255, 0, 255));

	// 생성 위치
	_mushroom->setX(600);
	_mushroom->setY(600);

	_mushroomIndex = 0;
	_mushroomCount = 0;
	_mushroomMoveSpeed = 3;
	_mushroomisDead = false;
	_mushroomDeadTime = 0;
	_mushroomEnd = false;
}

void mob::mobUpdate()
{
	// 버섯이 살아있으면...
	if (_mushroomisDead == false)
	{
		// 버섯 이동
		_mushroom->setX(_mushroom->getX() + _mushroomMoveSpeed);

		// 버섯의 이동 범위안에서 왕복운동
		if (_mushroom->getX() > MushroomRight || _mushroom->getX() < MushroomLeft)
			_mushroomMoveSpeed = -_mushroomMoveSpeed;

		// 버섯 이미지 10프레임마다 변경
		_mushroomCount++;

		if (_mushroomCount == 10)
		{
			_mushroomCount = 0;

			_mushroomIndex++;
			if (_mushroomIndex > 1)
				_mushroomIndex = 0;

			_mushroom->setFrameX(_mushroomIndex);
		}

		// 중력 작용
		_mobGravity = 3.f;
		_mushroom->setY(_mushroom->getY() + _mobGravity);
	}

	// 버섯이 죽으면
	if (_mushroomEnd == false)
	{
		if (_mushroomisDead == true)
		{
			_mushroomDeadTime++;

			// 죽은 버섯 이미지
			_mushroomIndex = 2;
			_mushroom->setFrameX(_mushroomIndex);

			if (_mushroomDeadTime == 30)
			{
				IMAGEMANAGER->deleteImage(TEXT("Mushroom"));
				_mushroomEnd = true;
			}
		}
	}	
	
}

void mob::mobRender(HDC _hdc)
{
	if (_mushroomEnd == false)
	{
		// 적 렌더
		IMAGEMANAGER->frameRender(TEXT("Mushroom"), _hdc, _mushroom->getX() - CAMERA->getPosition()->x,
			_mushroom->getY() - CAMERA->getPosition()->y, _mushroom->getFrameX(), _mushroom->getFrameY());

		// 충돌체 크기 보기
		if (KEYMANAGER->isToggleKey('T'))
			Rectangle(_hdc, mushroomRect().left - CAMERA->getPosition()->x, mushroomRect().top - CAMERA->getPosition()->y,
				mushroomRect().right - CAMERA->getPosition()->x, mushroomRect().bottom - CAMERA->getPosition()->y);
	}
	
}

RECT mob::mushroomRect()
{
	// 충돌하는 버섯 크기의 사각형 설정
	_mushroomRect = { _mushroom->boundingBox().left + 5, _mushroom->boundingBox().top, 
		_mushroom->boundingBox().right - 5, _mushroom->boundingBox().bottom };

	return _mushroomRect;
}

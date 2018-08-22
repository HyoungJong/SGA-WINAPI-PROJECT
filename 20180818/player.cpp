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
	_mario = IMAGEMANAGER->addFrameImage(TEXT("Mario"), TEXT("Image//MarioBasic.bmp"), 840, 156, 14, 2, true, RGB(255, 0, 255));

	// 생성 위치
	_mario->setX(200);
	_mario->setY(200);

	// 움직임 방향에 관한거
	_marioIndex = 0;
	_marioCount = 0;
	_marioDirection = RIGHT;
	_mario->setFrameX(_marioIndex);

	// 점프에 관한거
	_marioJump = false;
	_marioJumpPower = 0.f;
	_marioGravity = 0.f;

	// 마리오 죽었는지 관한거
	_marioStart = true;
	_marioDead = false;
	_marioDeadTime = 0;
}

void player::marioUpdate()
{
	if (_marioStart == true)
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
			_mario->setY(_mario->getY() - 8);
		}

		if (KEYMANAGER->isStayKeyDown(VK_DOWN))
		{
			_mario->setY(_mario->getY() + 8);
		}

		if (_marioJump == false)
		{
			if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
			{
				_marioJump = true;
				_marioJumpPower = 9.0f;
			}
		}

		// 낙사했을 때
		if (_mario->getY() > 900)
		{
			marioEnd();
		}

		_marioGravity = 0.3f;
	}

	// 마리오 죽었을 때 모션
	marioEndMotion();
	
	// 마리오 점프파워 및 중력 작용 
	
	_marioJumpPower -= _marioGravity;
	_mario->setY(_mario->getY() - _marioJumpPower);
}

void player::marioRender(HDC _hdc)
{
	// 마리오 렌더
	IMAGEMANAGER->frameRender(TEXT("Mario"), _hdc, _mario->getX() - CAMERA->getPosition()->x, _mario->getY() - CAMERA->getPosition()->y, _mario->getFrameX(), _mario->getFrameY());

	// 충돌체 크기 보기
	if(KEYMANAGER->isToggleKey('T'))
		Rectangle(_hdc, _marioRect.left - CAMERA->getPosition()->x, _marioRect.top - CAMERA->getPosition()->y,
			_marioRect.right - CAMERA->getPosition()->x, _marioRect.bottom - CAMERA->getPosition()->y);
}

RECT player::marioRect()
{
	// 충돌하는 마리오 크기의 사각형 설정
	_marioRect = { _mario->marioboundingBox().left + 30, _mario->marioboundingBox().top - 5,
		_mario->marioboundingBox().right + 8, _mario->marioboundingBox().bottom - 35 };

	return _marioRect;
}

void player::marioEnd()
{
	_marioStart = false;
	_marioDead = true;
}

void player::marioEndMotion()
{
	if (_marioStart == false)
	{
		if (_marioDead == true)
		{
			_marioJumpPower = 13.f;
			_marioGravity = 0.2f;
			_marioDead = false;
		}

		_mario->setFrameX(MARIO_DEAD_IMAGE);
		_mario->setFrameY(RIGHT);
		_marioDeadTime++;

		if (_marioDeadTime == 120)
		{
			_marioDeadTime = 0;
			_marioStart = true;
			marioInit();

			_resetCamera = new POINT;
			_resetCamera->x = 0;
			_resetCamera->y = 0;
			CAMERA->setPosition(_resetCamera);
		}
	}
}

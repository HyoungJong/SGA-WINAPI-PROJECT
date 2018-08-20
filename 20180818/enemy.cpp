#include "Game.h"
#include "enemy.h"

enemy::enemy()
{
}

enemy::~enemy()
{
}

HRESULT enemy::init()
{
	return S_OK;
}

HRESULT enemy::init(const TCHAR * imageName, POINT pos)
{
	_curFrameX = _curFrameY = 0;

	_enemy = IMAGEMANAGER->findImage(imageName);

	_rc = RectMakeCenter(pos.x, pos.y, _enemy->getFrameWidth(), _enemy->getFrameHeight());

	return S_OK;
}

void enemy::release()
{
}

void enemy::update()
{


	// 프레임 렌더를 위한 프레임 이동
	_count++;
	if (_count % 2 == 0)
	{
		if (_curFrameX >= _enemy->getMaxFrameX())
			_curFrameX = 0;

		_enemy->setFrameX(_curFrameX);
		_curFrameX++;
		_count = 0;
	}
}

void enemy::render()
{
	_enemy->frameRender(getMemDC(), _rc.left, _rc.top, _curFrameX, _curFrameY);
}

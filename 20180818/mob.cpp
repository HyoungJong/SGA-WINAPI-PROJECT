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
	_mushroom = IMAGEMANAGER->addFrameImage(TEXT("Mushroom"), TEXT("Image//����.bmp"), 246, 72, 3, 1, true, RGB(255, 0, 255));

	// ���� ��ġ
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
	// ������ ���������...
	if (_mushroomisDead == false)
	{
		// ���� �̵�
		_mushroom->setX(_mushroom->getX() + _mushroomMoveSpeed);

		// ������ �̵� �����ȿ��� �պ��
		if (_mushroom->getX() > MushroomRight || _mushroom->getX() < MushroomLeft)
			_mushroomMoveSpeed = -_mushroomMoveSpeed;

		// ���� �̹��� 10�����Ӹ��� ����
		_mushroomCount++;

		if (_mushroomCount == 10)
		{
			_mushroomCount = 0;

			_mushroomIndex++;
			if (_mushroomIndex > 1)
				_mushroomIndex = 0;

			_mushroom->setFrameX(_mushroomIndex);
		}

		// �߷� �ۿ�
		_mobGravity = 3.f;
		_mushroom->setY(_mushroom->getY() + _mobGravity);
	}

	// ������ ������
	if (_mushroomEnd == false)
	{
		if (_mushroomisDead == true)
		{
			_mushroomDeadTime++;

			// ���� ���� �̹���
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
		// �� ����
		IMAGEMANAGER->frameRender(TEXT("Mushroom"), _hdc, _mushroom->getX() - CAMERA->getPosition()->x,
			_mushroom->getY() - CAMERA->getPosition()->y, _mushroom->getFrameX(), _mushroom->getFrameY());

		// �浹ü ũ�� ����
		if (KEYMANAGER->isToggleKey('T'))
			Rectangle(_hdc, mushroomRect().left - CAMERA->getPosition()->x, mushroomRect().top - CAMERA->getPosition()->y,
				mushroomRect().right - CAMERA->getPosition()->x, mushroomRect().bottom - CAMERA->getPosition()->y);
	}
	
}

RECT mob::mushroomRect()
{
	// �浹�ϴ� ���� ũ���� �簢�� ����
	_mushroomRect = { _mushroom->boundingBox().left + 5, _mushroom->boundingBox().top, 
		_mushroom->boundingBox().right - 5, _mushroom->boundingBox().bottom };

	return _mushroomRect;
}

#include "Game.h"
#include "spaceShip.h"
#include "ProgressBar.h"

spaceShip::spaceShip()
{
}

spaceShip::~spaceShip()
{
}

HRESULT spaceShip::init()
{
	_spaceShip = IMAGEMANAGER->addImage(TEXT("SpaceShip"), TEXT("Image\\rocket.bmp"), 52, 64, true, RGB(255, 0, 255));
	_spaceShip->setX(WINSIZEX / 2);
	_spaceShip->setY(WINSIZEY / 2 + 200);

	_currentHP = _maxHP = 100;

	_hpBar = new ProgressBar;
	_hpBar->Init(_spaceShip->getX(), _spaceShip->getY() - 20, 52, 10);
	_hpBar->setGauge(_currentHP, _maxHP);

	return S_OK;
}

void spaceShip::release()
{
}

void spaceShip::update()
{



	_hpBar->setX(_spaceShip->getX());
	_hpBar->setY(_spaceShip->getY() - 20);
	_hpBar->setGauge(_currentHP, _maxHP);
	_hpBar->Update();

}

void spaceShip::render()
{
	_spaceShip->render(getMemDC(), _spaceShip->getX(), _spaceShip->getY());
	_hpBar->Render(getMemDC());
}

void spaceShip::hitDamage(float damage)
{
	_currentHP -= damage;
}

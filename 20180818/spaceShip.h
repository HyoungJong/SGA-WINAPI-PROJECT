#pragma once
#include "gameNode.h"

class ProgressBar;

class spaceShip : public gameNode
{
private:
	Image *			_spaceShip;

	ProgressBar*	_hpBar;

	float			_currentHP, _maxHP;
public:
	spaceShip();
	virtual ~spaceShip();

	virtual HRESULT init();
	virtual void	release();
	virtual void	update();
	virtual void	render();

	void			hitDamage(float damage);


};


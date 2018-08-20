#pragma once

enum MoveLimit
{
	MushroomLeft = 600,
	MushroomRight = 1200,
};

class mob
{
private:
	Image *		_mushroom;

	int			_mushroomIndex, _mushroomCount, _mushroomMoveSpeed;
	RECT		_mushroomRect;

	bool		_mushroomisDead;
	bool		_mushroomEnd;
	int			_mushroomDeadTime;
	float		_mobGravity;


public:
	mob();
	~mob();

	void		mobInit();
	void		mobUpdate();
	void		mobRender(HDC _hdc);

	void		setmushroomX(float x) { _mushroom->setX(x); }
	float		getmushroomX() { return _mushroom->getX(); }

	void		setmushroomY(float y) { _mushroom->setY(y); }
	float		getmushroomY() { return _mushroom->getY(); }

	void		setmobGravity(float gravity) { _mobGravity = gravity; }
	float		getmobGravity() { return _mobGravity; }

	void		setmushroomisDead(float mushroomisDead) { _mushroomisDead = mushroomisDead; }
	bool		getmushroomisDead() { return _mushroomisDead; }

	RECT		mushroomRect();
};


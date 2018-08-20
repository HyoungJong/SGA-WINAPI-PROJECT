#pragma once

enum direction
{
	RIGHT,
	LEFT,
};
class player
{
private:
	Image*		_mario;
	int			_marioIndex, _marioCount, _marioDirection;
	RECT		_marioRect;

	bool		_marioJump;
	float		_marioJumpPower, _marioGravity;


public:
	player();
	~player();

	void		marioInit();
	void		marioUpdate();
	void		marioRender(HDC _hdc);

	void		setmarioX(float x) { _mario->setX(x); }
	float		getmarioX() { return _mario->getX(); }

	void		setmarioY(float y) { _mario->setX(y); }
	float		getmarioY() { return _mario->getY(); }

	RECT		marioRect();
};

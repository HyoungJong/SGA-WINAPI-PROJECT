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

	void		setmarioY(float y) { _mario->setY(y); }
	float		getmarioY() { return _mario->getY(); }

	void		setmarioJumpPower(float jumpPower) { _marioJumpPower = jumpPower; }
	float		getmarioJumpPower() { return _marioJumpPower; }

	void		setmarioGravity(float Gravity) { _marioGravity = Gravity; }
	float		getmarioGravity() { return _marioGravity; }

	void		setmarioJump(float Jump) { _marioJump = Jump; }
	bool		getmarioJump() { return _marioJump; }

	RECT		marioRect();
};

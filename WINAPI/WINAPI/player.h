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


public:
	player();
	~player();

	void		marioInit();
	void		marioUpdate();
	void		marioRender(HDC _hdc);
	float		getmarioX() { return _mario->getX(); }
	float		getmarioY() { return _mario->getY(); }
};

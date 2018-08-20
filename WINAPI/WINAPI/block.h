#pragma once

class player;

class block
{
private:
	Image * _block;

public:
	block();
	~block();

	void	blockInit();
	void	blockRender(HDC _hdc);
	void	blockCollision(player* target);
	RECT	blockBox();
};


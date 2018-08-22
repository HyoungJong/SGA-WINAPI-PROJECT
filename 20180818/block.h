#pragma once

class player;

#define MAX_GROUNDBLOCKNUM		11
#define MAX_CLOUDNUM			3
#define MAX_THREEBLOCKNUM		4
#define MAX_COLUMNNUM			1
#define MAX_PORTALNUM			2
#define MAX_FALLINGBLOCKNUM		3
#define MAX_TOTHENEXTSTAGE		1
#define MAX_TENTNUM				1

class block
{
private:
	RECT	_groundblock[MAX_GROUNDBLOCKNUM];
	Image * _block[MAX_CLOUDNUM + MAX_THREEBLOCKNUM + MAX_PORTALNUM + MAX_FALLINGBLOCKNUM + MAX_TOTHENEXTSTAGE];
	Image * _tent;

	int		_trapOn[MAX_FALLINGBLOCKNUM];

public:
	block();
	~block();

	void	blockInit();
	void	blockMove();
	void	blockRender(HDC _hdc);
	void	blockRenderAfterPlayer(HDC _hdc);

	RECT	groundblockRect(int blocknum);
	RECT	blockRect(int blocknum);

	void	setTrapOn(int num) { _trapOn[num] = 1; }
};


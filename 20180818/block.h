#pragma once

class player;

#define MAX_GROUNDBLOCKNUM		10
#define MAX_BLOCKNUM			10
#define MAX_CLOUDNUM			3
#define MAX_THREEBLOCKNUM		4
#define MAX_COLUMNNUM			1
#define MAX_PORTALNUM			2
#define MAX_FALLINGBLOCKNUM		2
#define MAX_TENTNUM				1

class block
{
private:
	RECT	_groundblock[MAX_GROUNDBLOCKNUM];
	Image * _block[MAX_BLOCKNUM];

public:
	block();
	~block();

	void	blockInit();
	void	blockMove();
	void	blockRender(HDC _hdc);

	RECT	groundblockRect(int blocknum);
	RECT	blockRect(int blocknum);
};


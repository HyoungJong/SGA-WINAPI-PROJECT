#pragma once
#include "gameNode.h"

class enemy : public gameNode
{
private:
	Image * _enemy;
	RECT	_rc;

	int		_curFrameX;
	int		_curFrameY;

	int		_count;

public:
	enemy();
	virtual ~enemy();

	HRESULT init();
	HRESULT init(const TCHAR* imageName, POINT pos);

	void release();
	void update();
	void render();

	inline RECT getRect() { return _rc; }
};


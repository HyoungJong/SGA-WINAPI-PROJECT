#pragma once
#include "gameNode.h"

class Ingame : public gameNode
{
private:

	RECT	_rc;

public:
	Ingame();
	~Ingame();

	virtual HRESULT init();
	virtual void	update();
	virtual void	render();
	virtual void	release();
};


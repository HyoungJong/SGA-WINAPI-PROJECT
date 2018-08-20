#pragma once
#include "gameNode.h"

class StartScene : public gameNode
{
private:

	RECT	_rc;

public:
	StartScene();
	~StartScene();

	virtual HRESULT init();
	virtual void	update();
	virtual void	render();
	virtual void	release();
};


#pragma once
#include "gameNode.h"

class Image;

class mainGame : public GameNode
{
private:
	//=============================================
	
	POINT*			_pPlayerCoordinate;
	POINT			_pt;
	LPARAM			lParam;

	//=============================================

public:
	mainGame();
	~mainGame();

	//=============================================

	//============================================
	virtual HRESULT init();
	virtual void	update();
	virtual void	render();
	virtual void	release();

};


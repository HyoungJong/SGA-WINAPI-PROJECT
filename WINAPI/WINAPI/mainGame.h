#pragma once
#include "gameNode.h"

class Image;

enum ST_DIR
{
	RIGHT,
	LEFT,
};

class mainGame : public GameNode
{
private:
	//=============================================
	
	
	
	POINT*			_pPlayer;

	

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


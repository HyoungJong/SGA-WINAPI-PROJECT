#pragma once
#include "gameNode.h"
#include "list"

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
	// ���
	Image*			_background;
	// ĳ����
	Image*			_siva;
	int				_sivaIndex, _sivaCount, _sivaDirection;
	POINT*			_pPlayer;

	RECT			_rcWorld;
	RECT			_rcClient;

	RECT			HWANGGYUSEOB;

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


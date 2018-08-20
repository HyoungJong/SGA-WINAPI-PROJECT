#pragma once
#include "gameNode.h"

class Animation;

class AnimationTest : public gameNode
{
private:
	Image*		_image;

	Animation* _ani1;
	Animation* _ani2;
	Animation* _ani3;

public:
	AnimationTest();
	~AnimationTest();

	HRESULT	init();
	void	release();
	void	update();
	void	render();
};


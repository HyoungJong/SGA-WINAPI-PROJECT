#pragma once

class Animation;

class Effects
{
private:
	Image *		_effect01;
	Image *		_effect02;
	Image *		_effect03;
	Image *		_effect04;

	Animation*	_ani1;
	Animation*	_ani2;
	Animation*	_ani3;
	Animation*	_ani4;

public:
	Effects();
	~Effects();

	void	init();
	void	release();
	void	update();
	void	render(HDC hdc);
};


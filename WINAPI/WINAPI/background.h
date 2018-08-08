#pragma once

class Image;

class background
{
private:
	// ¹è°æ
	Image*			_background;
	
	RECT			_rcWorld;
	RECT			_rcClient;
	
public:
	background();
	~background();
	
	void	backgroundInit();
	void	backgroundRender(HDC _hdc);
	RECT	getWorld() { return _rcWorld; }
	RECT	getClient() { return _rcClient; }
	
};


#pragma once
class block
{
private:
	Image * _block;


public:
	block();
	~block();

	void	blockInit();
	void	blockRender(HDC _hdc);
};


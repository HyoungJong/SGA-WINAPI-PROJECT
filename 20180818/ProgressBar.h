#pragma once

class ProgressBar
{
	RECT			_rcProgress;
	int				_x, _y;
	float			_width;

	Image*			_progressBarTop;
	Image*			_progressBarBottom;

public:
	ProgressBar();
	~ProgressBar();

	bool			Init(int x, int y, int width, int height);
	void			Release();
	void			Update();
	void			Render(HDC hdc);

	void			setGauge(float currentGauge, float maxGauge);

	void			setX(int x) { _x = x; }
	void			setY(int y) { _y = y; }
};


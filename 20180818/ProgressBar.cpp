#include "Game.h"
#include "ProgressBar.h"

ProgressBar::ProgressBar()
{
}

ProgressBar::~ProgressBar()
{
}

bool ProgressBar::Init(int x, int y, int width, int height)
{
	_x = x;
	_y = y;

	_rcProgress = RectMake(x, y, width, height);

	_progressBarTop = IMAGEMANAGER->addImage(TEXT("FrontBar"),
		TEXT("Image\\hpBarTop.bmp"), x, y, width, height, true, RGB(255, 0, 255));

	_progressBarBottom = IMAGEMANAGER->addImage(TEXT("BackBar"),
		TEXT("Image\\hpBarBottom.bmp"), x, y, width, height, true, RGB(255, 0, 255));

	_width = _progressBarTop->getWidth();

	return true;
}

void ProgressBar::Release()
{
}

void ProgressBar::Update()
{
	_rcProgress = RectMakeCenter(_x, _y, _progressBarTop->getWidth(), _progressBarTop->getHeight());
}

void ProgressBar::Render(HDC hdc)
{
	IMAGEMANAGER->render(TEXT("BackBar"), hdc, _rcProgress.left + _progressBarBottom->getWidth() / 2,
		_y + _progressBarBottom->getHeight() / 2, 0, 0, _progressBarBottom->getWidth(),
		_progressBarBottom->getHeight());

	IMAGEMANAGER->render(TEXT("FrontBar"), hdc, _rcProgress.left + _progressBarBottom->getWidth() / 2,
		_y + _progressBarBottom->getHeight() / 2, 0, 0, _progressBarBottom->getWidth(),
		_progressBarBottom->getHeight());
}

void ProgressBar::setGauge(float currentGauge, float maxGauge)
{
	_width = (currentGauge / maxGauge) * _progressBarBottom->getWidth();
}

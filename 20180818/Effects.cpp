#include "Game.h"
#include "Effects.h"
#include "Animation.h"



Effects::Effects()
{
}


Effects::~Effects()
{
}

void Effects::init()
{
	// �ִϸ��̼� ���
	_effect01 = IMAGEMANAGER->addFrameImage(TEXT("Effect01"), TEXT("Image//effect01.bmp"),
		960, 1536, 5, 8, true, RGB(255, 255, 255));
	_effect01 = IMAGEMANAGER->addFrameImage(TEXT("Effect02"), TEXT("Image//effect02.bmp"),
		960, 960, 5, 5, true, RGB(255, 255, 255));
	_effect01 = IMAGEMANAGER->addFrameImage(TEXT("Effect03"), TEXT("Image//effect03.bmp"),
		960, 768, 5, 4, true, RGB(255, 255, 255));
	_effect01 = IMAGEMANAGER->addFrameImage(TEXT("Effect04"), TEXT("Image//effect04.bmp"),
		960, 768, 5, 4, true, RGB(255, 255, 255));

	_ani1 = new Animation;
	_ani1->init(_effect01->getWidth(), _effect01->getHeight(),
		_effect01->getFrameWidth(), _effect01->getFrameHeight());
	_ani1->setPlayFrame(0, 20, false, true);
	_ani1->setFPS(1);

	// ����Ʈ �Ŵ��� ���
	EFFECTMANAGER->AddEffect(TEXT("Effect01"), TEXT("Image/effect01.bmp"), 960, 1536, 192, 192, 1, 1.0f, 10, RGB(255,255,255));
	EFFECTMANAGER->AddEffect(TEXT("Effect02"), TEXT("Image/effect02.bmp"), 960, 960, 192, 192, 1, 1.0f, 10, RGB(255, 255, 255));
	EFFECTMANAGER->AddEffect(TEXT("Effect03"), TEXT("Image/effect03.bmp"), 960, 768, 192, 192, 1, 1.0f, 10, RGB(255, 255, 255));
	EFFECTMANAGER->AddEffect(TEXT("Effect04"), TEXT("Image/effect04.bmp"), 960, 768, 192, 192, 1, 1.0f, 10, RGB(255, 255, 255));
}

void Effects::release()
{
}

void Effects::update()
{
	// �ִϸ��̼� ���
	if (KEYMANAGER->isOnceKeyDown('Q'))
		_ani1->start();

	_ani1->frameUpdate(TIMEMANAGER->getElapsedTime() * 30);

	// ����Ʈ �Ŵ��� ���
	EFFECTMANAGER->Play(TEXT("Effect01"), 100 - CAMERA->getPosition()->x, 500 - CAMERA->getPosition()->y);

	EFFECTMANAGER->Update();
}

void Effects::render(HDC hdc)
{
	// �ִϸ��̼� ���
	_effect01->aniRender(hdc, 300 - CAMERA->getPosition()->x, 500 - CAMERA->getPosition()->y, _ani1);

	TCHAR szTemp[100] = { 0, };
	_stprintf_s(szTemp, sizeof(szTemp), TEXT("���ϴ� ��  %d, %d"),
		_effect01->getWidth(), _effect01->getHeight());
	TextOut(hdc, 20, 20, szTemp, _tcslen(szTemp));

	// ����Ʈ �Ŵ��� ���
	EFFECTMANAGER->Render();
}

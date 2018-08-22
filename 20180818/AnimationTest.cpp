#include "Game.h"
#include "AnimationTest.h"
#include "Animation.h"

AnimationTest::AnimationTest()
{
}

AnimationTest::~AnimationTest()
{
}

HRESULT AnimationTest::init()
{
	_image = IMAGEMANAGER->addFrameImage(TEXT("CAMEL"), TEXT("Image\\camel.bmp"),
		300, 267, 4, 3, true, RGB(255, 0, 255));

	_ani1 = new Animation;
	_ani1->init(_image->getWidth(), _image->getHeight(),
		_image->getFrameWidth(), _image->getFrameHeight());
	_ani1->setDefPlayFrame(true, false);
	_ani1->setFPS(1);

	int arrAni[] = { 1, 10, 2, 9, 3, 6 };
	_ani2 = new Animation;
	_ani2->init(_image->getWidth(), _image->getHeight(),
		_image->getFrameWidth(), _image->getFrameHeight());
	_ani2->setPlayFrame(arrAni, 6, false);
	_ani2->setFPS(1);

	_ani3 = new Animation;
	_ani3->init(_image->getWidth(), _image->getHeight(),
		_image->getFrameWidth(), _image->getFrameHeight());
	_ani3->setPlayFrame(2, 8, false, true);
	_ani3->setFPS(1);


	
#ifdef _EFFECT // Effect Test
	EFFECTMANAGER->AddEffect(TEXT("Effect1"), TEXT("Image/effect5.bmp"), 740, 444, 148, 148, 1, 1.0f, 10);
	EFFECTMANAGER->AddEffect(TEXT("Effect2"), TEXT("Image/explosion.bmp"), 832, 62, 32, 62, 1, 1.0f, 10);
#endif // Effect Test

	return S_OK;
}

void AnimationTest::release()
{
}

void AnimationTest::update()
{
	if (KEYMANAGER->isOnceKeyDown('Q'))
		_ani1->start();
	if (KEYMANAGER->isOnceKeyDown('W'))
		_ani2->start();
	if (KEYMANAGER->isOnceKeyDown('E'))
		_ani3->start();

#ifdef _EFFECT // Effect Test
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		GetCursorPos(&g_ptMouse);
		ScreenToClient(g_hWnd, &g_ptMouse);
		EFFECTMANAGER->Play(TEXT("Effect1"), g_ptMouse);

	}

	if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
	{
		GetCursorPos(&g_ptMouse);
		ScreenToClient(g_hWnd, &g_ptMouse);
		EFFECTMANAGER->Play(TEXT("Effect2"), g_ptMouse);
	}

	EFFECTMANAGER->Update();
#endif // // Effect Test

	_ani1->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
	_ani2->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
	_ani3->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
}

void AnimationTest::render()
{
	_image->aniRender(getMemDC(), 100, 100, _ani1);
	_image->aniRender(getMemDC(), 100, 200, _ani2);
	_image->aniRender(getMemDC(), 100, 300, _ani3);

#ifdef _EFFECT // Effect Test
	EFFECTMANAGER->Render();
#endif // Effect Test
}


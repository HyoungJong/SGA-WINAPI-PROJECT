#include "Game.h"
#include "Ingame.h"
#include "StartScene.h"


Ingame::Ingame()
{
}


Ingame::~Ingame()
{
}


HRESULT Ingame::init()
{

	_rc = { 200,200,600,600 };
	SCENEMANAGER->ChangeScene(TEXT("StartGame"));
	return S_OK;
}

void Ingame::release()
{


}

void Ingame::update()
{
	_rc = { 200,200,600,600 };

	//SCENEMANAGER->AddScene(TEXT("StartGame"), new StartScene);

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		SCENEMANAGER->AddScene(TEXT("StartGame"), new StartScene);
		SCENEMANAGER->ChangeScene(TEXT("StartGame"));
	}
		

}

void Ingame::render()
{

	//===================================================================

	Rectangle(getMemDC(), 200, 200, 600, 600);
	//====================================================================

}




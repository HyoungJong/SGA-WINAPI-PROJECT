#include "Game.h"
#include "KeyManager.h"

KeyManager::KeyManager()
{
}

KeyManager::~KeyManager()
{
}

HRESULT KeyManager::init()
{
	this->getKeyDown().reset();  // 전체 값을 0으로 세팅
	this->getKeyUp().reset();    // 전체 값을 0으로 세팅

								 /*
								 for (int i = 0; i < KEYMAX; i++)
								 _keyDown[i] = 0;
								 */

	return S_OK;
}

void KeyManager::release()
{
}

bool KeyManager::isOnceKeyDown(int _key)
{
	// Return : 0x0000(이전, 현재 다 안눌림), 0x8000(이전에 안눌렀다 현재 눌림), 0x80001(이전에 눌렸다 현재도 눌림)
	//                 1000 0000    1000 0001
	if (GetAsyncKeyState(_key) & 0x8000) // GetAsyncKeyState()는 이전 상태와 현재 상태를 비교한 값을 리턴
	{
		if (!this->getKeyDown()[_key])
		{
			this->setKeyDown(_key, true);
			return true;
		}
	}
	else
		this->setKeyDown(_key, false);

	return false;
}

bool KeyManager::isOnceKeyUp(int _key)
{
	if (GetAsyncKeyState(_key) & 0x8000)
	{
		this->setKeyUp(_key, true);
	}
	else
	{
		if (this->getKeyUp()[_key])
		{
			this->setKeyUp(_key, false);
			return true;
		}
	}

	return false;
}

bool KeyManager::isStayKeyDown(int _key)
{
	if (GetAsyncKeyState(_key) && 0x8000)
		return true;

	return false;
}

bool KeyManager::isToggleKey(int _key)
{
	if (GetKeyState(_key) && 0x0001)  // 메세지 큐를 거침, Caps Lock 같은 키의 상태를 가져옴
		return true;

	return false;
}

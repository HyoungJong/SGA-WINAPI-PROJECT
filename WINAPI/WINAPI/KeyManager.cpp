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
	this->getKeyDown().reset();  // ��ü ���� 0���� ����
	this->getKeyUp().reset();    // ��ü ���� 0���� ����

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
	// Return : 0x0000(����, ���� �� �ȴ���), 0x8000(������ �ȴ����� ���� ����), 0x80001(������ ���ȴ� ���絵 ����)
	//                 1000 0000    1000 0001
	if (GetAsyncKeyState(_key) & 0x8000) // GetAsyncKeyState()�� ���� ���¿� ���� ���¸� ���� ���� ����
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
	if (GetKeyState(_key) && 0x0001)  // �޼��� ť�� ��ħ, Caps Lock ���� Ű�� ���¸� ������
		return true;

	return false;
}

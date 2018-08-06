#include "Game.h"
#include "GameNode.h"
#include "Image.h"

GameNode::GameNode()
{
}

GameNode::~GameNode()
{
}

HRESULT GameNode::init()
{
	_hdc = GetDC(g_hWnd);
	_managerInit = false;

	return S_OK;
}

HRESULT GameNode::init(bool bInit)
{
	_hdc = GetDC(g_hWnd);
	_managerInit = bInit;

	if (bInit)
	{
		SetTimer(g_hWnd, 1, 10, NULL);
		KEYMANAGER->init();
		IMAGEMANAGER->init();
	}

	return S_OK;
}

void GameNode::update()
{
	InvalidateRect(g_hWnd, NULL, false);
}

void GameNode::render()
{
}

void GameNode::render(HDC _hdc)
{

}

void GameNode::release()
{
	if (_managerInit)
	{
		KillTimer(g_hWnd, 1);
		KEYMANAGER->release();
		IMAGEMANAGER->release();
	}

	ReleaseDC(g_hWnd, _hdc);
	
}

LRESULT GameNode::MainProc(HWND _hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC			hdc;
	PAINTSTRUCT ps;

	switch (iMessage)
	{
	case WM_CREATE:
		break;

	case WM_TIMER:
		this->update();
		break;

	case WM_PAINT:
	{
		hdc = BeginPaint(_hWnd, &ps);
		this->render();
		EndPaint(_hWnd, &ps);
	}
	break;

	case WM_KEYDOWN:
	{
		switch (wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		case VK_LEFT:
			break;
		case VK_RIGHT:
			break;
		case VK_UP:
			break;
		case VK_DOWN:
			break;
		}
	}
	break;

	case WM_LBUTTONDOWN:
		g_ptMouse.x = static_cast<float>LOWORD(lParam);
		g_ptMouse.y = static_cast<float>HIWORD(lParam);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return (DefWindowProc(_hWnd, iMessage, wParam, lParam));
}




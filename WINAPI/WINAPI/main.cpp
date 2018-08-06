#include <Windows.h>
#include <tchar.h>
#include <stdio.h>
#include <time.h>

#include "Game.h"
#include"mainGame.h"



HINSTANCE	g_hInstance;
HWND		g_hWnd;
POINT		g_ptMouse;

//==============================================

mainGame	_mg;

//==============================================

LPCTSTR		_lpszClass = TEXT("Win32API");

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void setWindowsSize(int x, int y, int width, int height);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lPszCmdParam, int cmdShow)
{
	srand((unsigned)time(NULL));

	MSG							message;
	WNDCLASS					wndClass;

	g_hInstance = hInstance;


	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hInstance = hInstance;
	wndClass.lpfnWndProc = (WNDPROC)WndProc;
	wndClass.lpszClassName = _lpszClass;
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wndClass);

	g_hWnd = CreateWindow(
		_lpszClass,
		_lpszClass,
		WS_OVERLAPPEDWINDOW,
		WINSTARTX,
		WINSTARTY,
		WINSIZEX,
		WINSIZEY,
		NULL,
		(HMENU)NULL,
		hInstance,
		NULL
	);

	setWindowsSize(WINSTARTX, WINSTARTY, WINSIZEX, WINSIZEY);

	if (FAILED(_mg.init()))
		return false;

	ShowWindow(g_hWnd, cmdShow);

	while (GetMessage(&message, 0, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
	// 게임루프가 위치하고 게임루프안에서 mainGame의 update(), render()가 호출

	_mg.release();

	return message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	return _mg.MainProc(hWnd, iMessage, wParam, lParam);
}

void setWindowsSize(int x, int y, int width, int height)
{
	RECT winRect;
	winRect.left	= 0;
	winRect.top		= 0;
	winRect.right	= width;
	winRect.bottom	= height;

	// 윈도우 클라이언트 영역의 사이즈를 재조정
	AdjustWindowRect(&winRect, WS_CAPTION | WS_SYSMENU, false);

	SetWindowPos(g_hWnd, NULL, x, y, (winRect.right - winRect.left), (winRect.bottom - winRect.top), SWP_NOZORDER | SWP_NOMOVE);
}
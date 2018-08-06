#pragma once
#include <windows.h>
#include <tchar.h>
#include <stdio.h>

// 선 그리기
inline void LineMake(HDC _hdc, int _x1, int _y1, int _x2, int _y2)
{
	MoveToEx(_hdc, _x1, _y1, NULL);
	LineTo(_hdc, _x2, _y2);
}

// RECT 영역 만들기
inline RECT RectMake(int _x, int _y, int _width, int _height)
{
	RECT r = { _x, _y, _x + _width, _y + _height };
	return r;
}

// 점을 중심으로 RECT 영역 만들기
inline RECT RectMakeCenter(int _x, int _y, int _width, int _height)
{
	RECT r = { _x - (_width / 2), _y - (_height / 2), _x + (_width / 2), _y + (_height / 2) };
	return r;
}

// 원 그리기
inline void EllipseMake(HDC _hdc, int _x, int _y, int _width, int _height)
{
	Ellipse(_hdc, _x, _y, _x + _width, _y + _height);
}

// 점을 중심으로 원 그리기
inline void EllipseMakeCenter(HDC _hdc, int _x, int _y, int _width, int _height)
{
	Ellipse(_hdc, _x - (_width / 2), _y - (_height / 2), _x + (_width / 2), _y + (_height / 2));
}

// 사각형 그리기
inline void RectangleMake(HDC _hdc, int _x, int _y, int _width, int _height)
{
	Rectangle(_hdc, _x, _y, _x + _width, _y + _height);
}

// 점을 중심으로 사각형 그리기
inline void RectangleMakeCenter(HDC _hdc, int _x, int _y, int _width, int _height)
{
	Rectangle(_hdc, _x - (_width / 2), _y - (_height / 2), _x + (_width / 2), _y + (_height / 2));
}
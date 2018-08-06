#pragma once
#include <windows.h>
#include <tchar.h>
#include <stdio.h>

// �� �׸���
inline void LineMake(HDC _hdc, int _x1, int _y1, int _x2, int _y2)
{
	MoveToEx(_hdc, _x1, _y1, NULL);
	LineTo(_hdc, _x2, _y2);
}

// RECT ���� �����
inline RECT RectMake(int _x, int _y, int _width, int _height)
{
	RECT r = { _x, _y, _x + _width, _y + _height };
	return r;
}

// ���� �߽����� RECT ���� �����
inline RECT RectMakeCenter(int _x, int _y, int _width, int _height)
{
	RECT r = { _x - (_width / 2), _y - (_height / 2), _x + (_width / 2), _y + (_height / 2) };
	return r;
}

// �� �׸���
inline void EllipseMake(HDC _hdc, int _x, int _y, int _width, int _height)
{
	Ellipse(_hdc, _x, _y, _x + _width, _y + _height);
}

// ���� �߽����� �� �׸���
inline void EllipseMakeCenter(HDC _hdc, int _x, int _y, int _width, int _height)
{
	Ellipse(_hdc, _x - (_width / 2), _y - (_height / 2), _x + (_width / 2), _y + (_height / 2));
}

// �簢�� �׸���
inline void RectangleMake(HDC _hdc, int _x, int _y, int _width, int _height)
{
	Rectangle(_hdc, _x, _y, _x + _width, _y + _height);
}

// ���� �߽����� �簢�� �׸���
inline void RectangleMakeCenter(HDC _hdc, int _x, int _y, int _width, int _height)
{
	Rectangle(_hdc, _x - (_width / 2), _y - (_height / 2), _x + (_width / 2), _y + (_height / 2));
}
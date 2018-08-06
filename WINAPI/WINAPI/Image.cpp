#include "Game.h"
#include "Image.h"

#pragma comment (lib, "msimg32.lib")   // 라이브러리 불러오는 부분

Image::Image() : _imageInfo(NULL),
				_fileName(NULL),
				_trans(false),
				_transColor(RGB(0,0,0))
{
}

Image::~Image()
{
}

HRESULT Image::init(int width, int height)
{
	if (_imageInfo != NULL)
		release();

	HDC hdc = GetDC(g_hWnd);

	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_EMPTY;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, width, height);
	_imageInfo->hOldBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;

	_fileName = NULL;
	_trans = FALSE;
	_transColor = RGB(0, 0, 0);

	if (_imageInfo->hBit == NULL)
	{
		release();
		return E_FAIL;
	}

	ReleaseDC(g_hWnd, hdc);

	return S_OK;
}

// BOOL을 true로 하고 RGB 적으면 랜더안함
HRESULT Image::init(const TCHAR* fileName, int width, int height, BOOL trans, COLORREF transColor)
{
	if (_imageInfo != NULL)
		release();

	HDC hdc = GetDC(g_hWnd);

	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_EMPTY;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(g_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOldBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;

	size_t len = _tcslen(fileName);

	_fileName = new TCHAR[len + 1];
	_tcscpy_s(_fileName, len + 1, fileName);

	_trans = trans;
	_transColor = transColor;

	if (_imageInfo->hBit == NULL)
	{
		release();
		return E_FAIL;
	}

	ReleaseDC(g_hWnd, hdc);

	return S_OK;
}

// 새로 추가(2018.07.26)
HRESULT Image::init(const TCHAR * fileName, float x, float y, int width, int height, BOOL trans, COLORREF transColor)
{
	if (_imageInfo != NULL)
		release();

	HDC hdc = GetDC(g_hWnd);

	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_EMPTY;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(g_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOldBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->x = x;
	_imageInfo->y = y;
	_imageInfo->width = width;
	_imageInfo->height = height;

	size_t len = _tcslen(fileName);

	_fileName = new TCHAR[len + 1];
	_tcscpy_s(_fileName, len + 1, fileName);

	_trans = trans;
	_transColor = transColor;

	if (_imageInfo->hBit == NULL)
	{
		release();
		return E_FAIL;
	}

	ReleaseDC(g_hWnd, hdc);

	return S_OK;
}

HRESULT Image::init(const TCHAR * fileName, float x, float y, int width, int height, int frameX, int frameY, BOOL trans, COLORREF transColor)
{
	if (_imageInfo != NULL)
		release();

	HDC hdc = GetDC(g_hWnd);

	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_EMPTY;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(g_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOldBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->x = x;
	_imageInfo->y = y;
	_imageInfo->width = width;
	_imageInfo->height = height;
	_imageInfo->frameWidth = width / frameX;
	_imageInfo->frameHeight = height / frameY;
	_imageInfo->currentFrameX = 0;
	_imageInfo->currentFrameY = 0;
	_imageInfo->maxFrameX = frameX - 1;
	_imageInfo->maxFrameY = frameY - 1;

	size_t len = _tcslen(fileName);

	_fileName = new TCHAR[len + 1];
	_tcscpy_s(_fileName, len + 1, fileName);

	_trans = trans;
	_transColor = transColor;

	if (_imageInfo->hBit == NULL)
	{
		release();
		return E_FAIL;
	}

	ReleaseDC(g_hWnd, hdc);

	return S_OK;
}

HRESULT Image::init(const TCHAR * fileName, int width, int height, int frameX, int frameY, BOOL trans, COLORREF transColor)
{
	if (_imageInfo != NULL)
		release();

	HDC hdc = GetDC(g_hWnd);

	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_EMPTY;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(g_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOldBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;
	_imageInfo->frameWidth = width / frameX;
	_imageInfo->frameHeight = height / frameY;
	_imageInfo->currentFrameX = 0;
	_imageInfo->currentFrameY = 0;
	_imageInfo->maxFrameX = frameX - 1;
	_imageInfo->maxFrameY = frameY - 1;

	size_t len = _tcslen(fileName);

	_fileName = new TCHAR[len + 1];
	_tcscpy_s(_fileName, len + 1, fileName);

	_trans = trans;
	_transColor = transColor;

	if (_imageInfo->hBit == NULL)
	{
		release();
		return E_FAIL;
	}

	ReleaseDC(g_hWnd, hdc);

	return S_OK;
}
// 새로 추가(2018.07.26)

void Image::release()
{
	if (_imageInfo)
	{
		SelectObject(_imageInfo->hMemDC, _imageInfo->hOldBit);
		DeleteObject(_imageInfo->hBit);
		DeleteDC(_imageInfo->hMemDC);

		SAFE_DELETE(_imageInfo);
		SAFE_DELETE(_fileName);

		_trans = false;
		_transColor = RGB(0, 0, 0);
	}
}

// 특정 색상 없애기
void Image::setTransColor(BOOL trans, COLORREF transColor)
{
	_trans = trans;
	_transColor = transColor;
}

// 새로 추가(2018.07.26)
void Image::render(HDC hdc)
{
	if (_trans)
	{
		GdiTransparentBlt(
			hdc,
			_imageInfo->x,
			_imageInfo->y,
			_imageInfo->width,
			_imageInfo->height,
			_imageInfo->hMemDC,
			0, 0,
			_imageInfo->width,
			_imageInfo->height,
			_transColor);
	}
	else
	{
		BitBlt(hdc, _imageInfo->x, _imageInfo->y,
			_imageInfo->width,
			_imageInfo->height,
			_imageInfo->hMemDC,
			0, 0, SRCCOPY);
	}
}
// 새로 추가(2018.07.26)

void Image::render(HDC hdc, int destX, int destY)
{
	if (_trans)
	{
		GdiTransparentBlt(
			hdc,
			destX,
			destY,
			_imageInfo->width,
			_imageInfo->height,
			_imageInfo->hMemDC,
			0, 0,
			_imageInfo->width,
			_imageInfo->height,
			_transColor);
	}
	else
	{
		BitBlt(hdc, destX, destY,
			_imageInfo->width,
			_imageInfo->height,
			_imageInfo->hMemDC,
			0, 0, SRCCOPY);
	}
}

//							그려지는 대상의 좌표    얻어올 이미지의 좌표   얻어올 이미지의 크기
void Image::render(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight)
{
	if (_trans)
	{
		GdiTransparentBlt(
			hdc,					// 복사될 DC
			destX,					// 복사될 좌표 X
			destY,					// 복사될 좌표 Y
			sourWidth,				// 복사될 이미지 넓이
			sourHeight,				// 복사될 이미지 높이
			_imageInfo->hMemDC,
			sourX, sourY,			// 복사해올 좌표
			sourWidth,				// 복사해올 이미지 넓이
			sourHeight,				// 복사해올 이미지 높이
			_transColor);
	}
	else
	{
		BitBlt(hdc, destX, destY,
			sourWidth,
			sourHeight,
			_imageInfo->hMemDC,
			sourX, sourY,
			SRCCOPY);
	}
}

void Image::loopRender(HDC hdc, const LPRECT drawArea, int offsetX, int offsetY)
{
	static int nLoopCount = 0;
	static int nRenderCount = 1;

	// 화면 밖으로 나가면 보정해준다
	if (offsetX < 0)
		offsetX = _imageInfo->width + (offsetX % _imageInfo->width);

	if (offsetY < 0)
		offsetY = _imageInfo->height + (offsetY % _imageInfo->height);

	// 오프셋 영역을 받아올 변수
	int sourWidth;
	int sourHeight;

	// 그려주는 영역
	RECT rcDest;
	RECT rcSour;

	// 그려주는 영역을 잡아준다
	int drawAreaX = drawArea->left;
	int drawAreaY = drawArea->top;
	int drawAreaW = drawArea->right - drawAreaX;
	int drawAreaH = drawArea->bottom - drawAreaY;

	// Y축부터
	for (int y = 0; y < drawAreaH; y += sourHeight)
	{
		rcSour.top = (y + offsetY) % _imageInfo->height;
		rcSour.bottom = _imageInfo->height;

		sourHeight = rcSour.bottom - rcSour.top;

		// 그려주는 영역의 높이보다 Y축이 크다면
		if (y + sourHeight > drawAreaH)
		{
			rcSour.bottom -= (y + sourHeight) - drawAreaH;
			sourHeight = rcSour.bottom - rcSour.top;
		}

		// 화면 밖으로 나간 영역 만큼 뿌려줄 위치에 산정한다
		rcDest.top = y + drawAreaY;
		rcDest.bottom = rcDest.top + sourHeight;

		for (int x = 0; x < drawAreaW; x += sourWidth)
		{
			rcSour.left = (x + offsetX) % _imageInfo->width;
			rcSour.right = _imageInfo->width;

			sourWidth = rcSour.right - rcSour.left;

			// 그려주는 영역의 높이보다 x축이 크다면
			if (x + sourWidth > drawAreaW)
			{
				rcSour.right -= (x + sourWidth) - drawAreaW;
				sourWidth = rcSour.right - rcSour.left;
			}

			// 화면 밖으로 나간 영역 만큼 뿌려줄 위치에 산정한다
			rcDest.left = x + drawAreaX;
			rcDest.right = rcDest.left + sourWidth;

			render(hdc, 
				rcDest.left, rcDest.top,			// 그려지는 위치
				rcSour.left, rcSour.top,			// 얻어오는 위치
				rcSour.right - rcSour.left,			// 그려지는 이미지의 너비
				rcSour.bottom - rcSour.top);		// 그려지는 이미지의 높이

			nRenderCount++;
		}
	}

	nLoopCount++;
}

// 새로 추가(2018.07.26)
void Image::frameRender(HDC hdc, int destX, int destY)
{
	if (_trans)
	{
		GdiTransparentBlt(
			hdc,					// 복사될 DC
			destX,					// 복사될 좌표 X
			destY,					// 복사될 좌표 Y
			_imageInfo->frameWidth,				// 복사될 이미지 넓이
			_imageInfo->frameHeight,				// 복사될 이미지 높이
			_imageInfo->hMemDC,
			_imageInfo->currentFrameX * _imageInfo->frameWidth,
			_imageInfo->currentFrameY * _imageInfo->frameHeight,			// 복사해올 좌표
			_imageInfo->frameWidth,				// 복사해올 이미지 넓이
			_imageInfo->frameHeight,				// 복사해올 이미지 높이
			_transColor);
	}
	else
	{
		BitBlt(hdc, destX, destY,
			_imageInfo->frameWidth,
			_imageInfo->frameHeight,
			_imageInfo->hMemDC,
			_imageInfo->currentFrameX * _imageInfo->frameWidth,
			_imageInfo->currentFrameY * _imageInfo->frameHeight,
			SRCCOPY);
	}
}

void Image::frameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY)
{
	_imageInfo->currentFrameX = currentFrameX;
	_imageInfo->currentFrameY = currentFrameY;

	if (_trans)
	{
		GdiTransparentBlt(
			hdc,					// 복사될 DC
			destX,					// 복사될 좌표 X
			destY,					// 복사될 좌표 Y
			_imageInfo->frameWidth,				// 복사될 이미지 넓이
			_imageInfo->frameHeight,				// 복사될 이미지 높이
			_imageInfo->hMemDC,
			currentFrameX * _imageInfo->frameWidth,
			currentFrameY * _imageInfo->frameHeight,			// 복사해올 좌표
			_imageInfo->frameWidth,				// 복사해올 이미지 넓이
			_imageInfo->frameHeight,				// 복사해올 이미지 높이
			_transColor);
	}
	else
	{
		BitBlt(hdc, destX, destY,
			_imageInfo->frameWidth,
			_imageInfo->frameHeight,
			_imageInfo->hMemDC,
			currentFrameX * _imageInfo->frameWidth,
			currentFrameY * _imageInfo->frameHeight,
			SRCCOPY);
	}
}
// 새로 추가(2018.07.26)

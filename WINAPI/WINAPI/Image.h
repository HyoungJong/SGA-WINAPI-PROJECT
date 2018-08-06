#pragma once


class Image
{
	enum IMAGE_LOAD_KIND
	{
		LOAD_RESOURCE,	// 리소스(프로그램이 가지고 있는 자원)에서 불러옴
		LOAD_FILE,		// 파일에서 불러옴
		LOAD_EMPTY,		// 빈 비트맵에서 불러옴
		LOAD_END,
	};

	typedef struct tagImageInfo
	{
		DWORD	resID;			// 리소스 불러올 때 사용되는 레지스터 넘버
		HDC		hMemDC;			// 메모리 DC
		HBITMAP	hBit;			// 비트맵
		HBITMAP	hOldBit;		// 원래 DC에 등록되어있던 비트맵 핸들 저장용
		float	x;				// 이미지 x 좌표
		float	y;				// 이미지 y 좌표
		int		width;			// 이미지의 x쪽 크기
		int		height;			// 이미지의 y쪽 크기

		int		currentFrameX;	// 현재 프레임
		int		currentFrameY;
		int		maxFrameX;
		int		maxFrameY;
		int		frameWidth;
		int		frameHeight;
		BYTE	loadType;		// 이미지 불러올 타입
		RECT	boundingBox;

		tagImageInfo()
		{
			resID		= 0;
			hMemDC		= NULL;
			hBit		= NULL;
			hOldBit		= NULL;
			width		= 0;
			height		= 0;
			x = 0.f;
			y = 0.f;
			currentFrameX = 0;
			currentFrameY = 0;
			maxFrameX = 0;
			maxFrameY = 0;
			frameWidth = 0;
			frameHeight = 0;
			loadType = 0;
			boundingBox = RectMake(0, 0, 0, 0);
			loadType	= LOAD_RESOURCE;
		}

	}IMAGE_INFO, *LPIMAGE_INFO;
private:
	LPIMAGE_INFO		_imageInfo;		// 이미지 정보 구조체
	TCHAR*				_fileName;		// 이미지 파일 이름
	BOOL				_trans;			// 트랜스 컬러 유무
	COLORREF			_transColor;	// 컬러키

public:
	Image();
	~Image();

	HRESULT init(int width, int height);
	HRESULT init(const TCHAR* fileName, int width, int height, BOOL trans = FALSE, COLORREF transColor = FALSE);

	// 새로 추가(2018.07.26)
	HRESULT init(const TCHAR* fileName, float x, float y,
		int width, int height, 
		BOOL trans = FALSE, COLORREF transColor = FALSE);

	HRESULT init(const TCHAR* fileName, float x, float y, 
		int width, int height, int frameX, int frameY, 
		BOOL trans = FALSE, COLORREF transColor = FALSE);

	HRESULT init(const TCHAR* fileName,	int width, int height,
		int frameX, int frameY,
		BOOL trans = FALSE, COLORREF transColor = FALSE);
	// 새로 추가(2018.07.26)

	void release();

	void setTransColor(BOOL trans, COLORREF transColor);

	// 새로 추가(2018.07.26)
	void render(HDC hdc);
	// 새로 추가(2018.07.26)

	void render(HDC hdc, int destX, int destY);

	void render(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);

	void loopRender(HDC hdc, const LPRECT drawArea, int offsetX, int offsetY);

	inline HDC getMemDC() { return _imageInfo->hMemDC; }

	// 새로 추가(2018.07.26)
	void frameRender(HDC hdc, int destX, int destY);
	void frameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);
	// 새로 추가(2018.07.26)

	//========================================================================
	// 새로 추가(2018.07.26)
	inline void		setX(float x) { _imageInfo->x = x; }
	inline float	getX() { return _imageInfo->x; }

	inline void		setY(float y) { _imageInfo->y = y; }
	inline float	getY() { return _imageInfo->y; }

	inline void		setCenter(float x, float y)
	{
		_imageInfo->x = x - (_imageInfo->width / 2);
		_imageInfo->y = y - (_imageInfo->height / 2);
	}

	inline float	getCenterX()
	{
		return _imageInfo->maxFrameX <= 0 ? _imageInfo->x + (_imageInfo->width / 2) : 
			_imageInfo->x + (_imageInfo->frameWidth / 2);
	}

	inline float	getCenterY()
	{
		return _imageInfo->maxFrameY <= 0 ? _imageInfo->y + (_imageInfo->height / 2) :
			_imageInfo->y + (_imageInfo->frameHeight / 2);
	}

	inline int getWidth() { return _imageInfo->width; }
	inline int getHeight() { return _imageInfo->height; }

	inline RECT boundingBox()
	{
		RECT	rc = RectMake(int(_imageInfo->x),
			int(_imageInfo->y),
			int(_imageInfo->frameWidth),
			int(_imageInfo->frameHeight));

		return rc;
	}

	inline void setFrameX(int frameX)
	{
		_imageInfo->currentFrameX = frameX;
		if (frameX > _imageInfo->maxFrameX)
			_imageInfo->currentFrameX = _imageInfo->maxFrameX;
	}

	inline void setFrameY(int frameY)
	{
		_imageInfo->currentFrameY = frameY;
		if (frameY > _imageInfo->maxFrameY)
			_imageInfo->currentFrameY = _imageInfo->maxFrameY;
	}

	inline int getMaxFrameX() { return _imageInfo->maxFrameX; }
	inline int getMaxFrameY() { return _imageInfo->maxFrameY; }

	inline int getFrameX() { return _imageInfo->currentFrameX; }
	inline int getFrameY() { return _imageInfo->currentFrameY; }

	inline int getFrameWidth() { return _imageInfo->frameWidth; }
	inline int getFrameHeight() { return _imageInfo->frameHeight; }
};


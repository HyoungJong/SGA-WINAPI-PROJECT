#pragma once


class Image
{
	enum IMAGE_LOAD_KIND
	{
		LOAD_RESOURCE,	// ���ҽ�(���α׷��� ������ �ִ� �ڿ�)���� �ҷ���
		LOAD_FILE,		// ���Ͽ��� �ҷ���
		LOAD_EMPTY,		// �� ��Ʈ�ʿ��� �ҷ���
		LOAD_END,
	};

	typedef struct tagImageInfo
	{
		DWORD	resID;			// ���ҽ� �ҷ��� �� ���Ǵ� �������� �ѹ�
		HDC		hMemDC;			// �޸� DC
		HBITMAP	hBit;			// ��Ʈ��
		HBITMAP	hOldBit;		// ���� DC�� ��ϵǾ��ִ� ��Ʈ�� �ڵ� �����
		float	x;				// �̹��� x ��ǥ
		float	y;				// �̹��� y ��ǥ
		int		width;			// �̹����� x�� ũ��
		int		height;			// �̹����� y�� ũ��

		int		currentFrameX;	// ���� ������
		int		currentFrameY;
		int		maxFrameX;
		int		maxFrameY;
		int		frameWidth;
		int		frameHeight;
		BYTE	loadType;		// �̹��� �ҷ��� Ÿ��
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
	LPIMAGE_INFO		_imageInfo;		// �̹��� ���� ����ü
	TCHAR*				_fileName;		// �̹��� ���� �̸�
	BOOL				_trans;			// Ʈ���� �÷� ����
	COLORREF			_transColor;	// �÷�Ű

public:
	Image();
	~Image();

	HRESULT init(int width, int height);
	HRESULT init(const TCHAR* fileName, int width, int height, BOOL trans = FALSE, COLORREF transColor = FALSE);

	// ���� �߰�(2018.07.26)
	HRESULT init(const TCHAR* fileName, float x, float y,
		int width, int height, 
		BOOL trans = FALSE, COLORREF transColor = FALSE);

	HRESULT init(const TCHAR* fileName, float x, float y, 
		int width, int height, int frameX, int frameY, 
		BOOL trans = FALSE, COLORREF transColor = FALSE);

	HRESULT init(const TCHAR* fileName,	int width, int height,
		int frameX, int frameY,
		BOOL trans = FALSE, COLORREF transColor = FALSE);
	// ���� �߰�(2018.07.26)

	void release();

	void setTransColor(BOOL trans, COLORREF transColor);

	// ���� �߰�(2018.07.26)
	void render(HDC hdc);
	// ���� �߰�(2018.07.26)

	void render(HDC hdc, int destX, int destY);

	void render(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);

	void loopRender(HDC hdc, const LPRECT drawArea, int offsetX, int offsetY);

	inline HDC getMemDC() { return _imageInfo->hMemDC; }

	// ���� �߰�(2018.07.26)
	void frameRender(HDC hdc, int destX, int destY);
	void frameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);
	// ���� �߰�(2018.07.26)

	//========================================================================
	// ���� �߰�(2018.07.26)
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


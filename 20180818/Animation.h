#pragma once
class Animation
{
public:
	typedef vector<POINT>	vFrameList;
	typedef vector<int>		vPlayList;

private:
	vFrameList				_frameList;
	vPlayList				_playList;

	int						_frameNum;
	int						_frameWidth;
	int						_frameHeight;

	bool					_loop;
	bool					_play;

	float					_frameUpdateSec;
	float					_elapsedSec;

	unsigned int			_nowPlayIndex;

public:
	Animation();
	~Animation();

	bool	init(int totalW, int totalH, int frameW, int frameH);
	bool	init(Image* image);

	void	release();

	void	setDefPlayFrame(bool reverse = false, bool loop = false);
	void	setPlayFrame(int* playArr, int arrLen, bool loop = false);
	void    setPlayFrame(int start, int end, bool reverse = false, bool loop = false);

	void    setFPS(int framePerSec);

	void	frameUpdate(float elapsedTime);

	void	start();
	void	stop();
	void	pause();
	void	resume();

	inline bool		isPlay() { return _play; }
	inline POINT	getFramePos() { return _frameList[_playList[_nowPlayIndex]]; }
	inline int		getFrameWidth() { return _frameWidth; }
	inline int		getFrameHeight() { return _frameHeight; }
};


#pragma once

class Timer
{
private:
	bool			_isHardware;			// QPF���� ���� ���ο� ���� flag
	float			_timeScale;				// ������ �ð���(����) = delta Time 
	float			_timeElapsed;			// �ð��帧-> tickCount 

	//__int64 : 64��Ʈ ���� = long long

	__int64			_curTime;				// ���� ��ȣ�� ������ ��
	__int64			_lastTime;				// cpu�� ��ȣ�� ������ ������������ ����
	__int64			_periodFrequency;		// cpu Ŭ��? 

	unsigned long	_frameRate;				// ������ �ӵ�
	unsigned long	_FPSframeCount;			// ������ ī����

	float			_FPSTimeElapsed;		// �������� �ð� �帧
	float			_worldTime;				// �����ϵ� �� ��� �ð�

public:
	Timer();
	~Timer();

	HRESULT			init();
	void			tick(float lockFPS = 0.0f);
	unsigned long	getFrameRate(TCHAR* str = NULL);

	inline float	getElapsedTime() const { return _timeElapsed; }
	inline float    getWorldTime() const { return _worldTime; }
};


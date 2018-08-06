#pragma once


class Camera : public singletonBase<Camera>
{
	POINT*	ptTarget;	// 타겟의 위치 정보
	POINT*	ptPos;		// 카메라의 위치 정보

	RECT	rcClient;	// 클라이언트 영역의 정보
	RECT	rcWorld;	// 월드(전체배경) 영역의 정보

public:
	Camera();
	~Camera();

	void	setTargetPos(POINT* _pt) { ptTarget = _pt; }
	void	setPosition(POINT* _pt) { ptPos = _pt; }

	const POINT* getTargetPos() { return ptTarget; }
	const POINT* getPosition() { return ptPos; }

	void	setClientRect(const RECT& _rc) { rcClient = _rc; }
	void	setWorldRect(const RECT& _rc) { rcWorld = _rc; }

	const RECT& getClientRect() const { return rcClient; }
	const RECT& getWorldRect() const { return rcWorld; }

	bool operator==(const POINT* pObj) { return ptTarget == pObj; }
	bool operator!=(const POINT* pObj) { return ptTarget != pObj; }

	bool init(POINT* _pt, const RECT& _client, const RECT& _world);

	void update();
};


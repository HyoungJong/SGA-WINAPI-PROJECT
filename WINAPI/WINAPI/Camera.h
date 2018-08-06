#pragma once


class Camera : public singletonBase<Camera>
{
	POINT*	ptTarget;	// Ÿ���� ��ġ ����
	POINT*	ptPos;		// ī�޶��� ��ġ ����

	RECT	rcClient;	// Ŭ���̾�Ʈ ������ ����
	RECT	rcWorld;	// ����(��ü���) ������ ����

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


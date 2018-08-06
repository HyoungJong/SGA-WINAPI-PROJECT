#include "Game.h"
#include "Camera.h"



Camera::Camera()
{
}


Camera::~Camera()
{
	SAFE_DELETE(ptPos);
}

bool Camera::init(POINT * _pt, const RECT & _client, const RECT & _world)
{
	if (_pt == NULL)
		return false;

	ptTarget = _pt;

	rcClient = _client;
	rcWorld = _world;

	ptPos = new POINT;
	ptPos->x = 0;
	ptPos->y = 0;

	return true;
}

void Camera::update()
{
	if (ptTarget == NULL)
	{
		ptPos->x = 0;
		ptPos->y = 0;
		return;
	}

	// 카메라 위치는 중앙에 타겟, 클라이언트 절반을 기준
	if (ptTarget->x > rcClient.right / 2)
		ptPos->x = ptTarget->x - rcClient.right / 2;
	if (ptTarget->y > rcClient.bottom / 2)
		ptPos->y = ptTarget->y - rcClient.bottom / 2;

	// 월드를 벗어나지 않게 조절
	if (ptPos->x < 0)
		ptPos->x = 0;
	if (ptPos->y < 0)
		ptPos->y = 0;
	if (ptPos->x > rcWorld.right - rcClient.right)
		ptPos->x = rcWorld.right - rcClient.right;
	if (ptPos->y > rcWorld.bottom - rcClient.bottom)
		ptPos->y = rcWorld.bottom - rcClient.bottom;


}

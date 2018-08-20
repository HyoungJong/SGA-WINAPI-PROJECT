#pragma once
#include "singletonBase.h"

class gameNode;

class SceneManager : public singletonBase<SceneManager>
{
private:
	// Ŭ���� static ������ ����...
	static gameNode* currentScene;  // ���� ��
	static gameNode* readyScene;	// �ٲ� ��(��� ��)

	map<string, gameNode*> sceneList;

public:
	SceneManager();
	~SceneManager();

	void Init();
	void Release();
	void Update();
	void Render(HDC hdc);

	gameNode* AddScene(string sceneName, gameNode* scene);

	bool ChangeScene(string sceneName);
};


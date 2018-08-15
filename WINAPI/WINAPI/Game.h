#pragma once
#include "commonMacroFunction.h"

// �ý��� ��� �߰� �κ�
#include <tchar.h>
#include <list>
#include <string>
#include <math.h>
#include <map>

using std::string;
using std::map;

//=========================================================================
// ���� ���� ���
#include "randomFunction.h"
#include "KeyManager.h"
#include "ImageManager.h"
#include "Camera.h"
#include "Image.h"



// ��ũ��
#define WINSTARTX 50
#define WINSTARTY 50
#define WINSIZEX  800
#define WINSIZEY  600

// ���� ��ũ�� ������ �߰� �κ�
#define IMAGEMANAGER	ImageManager::getSingleton()
#define KEYMANAGER		KeyManager::getSingleton()
#define RND				randomFunction::getSingleton()
#define CAMERA			Camera::getSingleton()

#define SAFE_DELETE(p) {if(p) { delete(p); (p) = NULL; }}
#define SAFE_RELEASE(p) {if(p) { (p)->release(); (p) = NULL; }}


// EXTERN �߰� �κ�
extern HWND			g_hWnd;
extern HINSTANCE	g_hInstance;
extern POINT		g_ptMouse;
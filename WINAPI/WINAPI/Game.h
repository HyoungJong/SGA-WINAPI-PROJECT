#pragma once
#include "commonMacroFunction.h"

// 시스템 헤더 추가 부분
#include <tchar.h>
#include <list>
#include <string>
#include <math.h>
#include <map>

using std::string;
using std::map;

//=========================================================================
// 유저 정의 헤더
#include "randomFunction.h"
#include "KeyManager.h"
#include "ImageManager.h"
#include "Camera.h"
#include "Image.h"



// 매크로
#define WINSTARTX 50
#define WINSTARTY 50
#define WINSIZEX  800
#define WINSIZEY  600

// 각종 매크로 디파인 추가 부분
#define IMAGEMANAGER	ImageManager::getSingleton()
#define KEYMANAGER		KeyManager::getSingleton()
#define RND				randomFunction::getSingleton()
#define CAMERA			Camera::getSingleton()

#define SAFE_DELETE(p) {if(p) { delete(p); (p) = NULL; }}
#define SAFE_RELEASE(p) {if(p) { (p)->release(); (p) = NULL; }}


// EXTERN 추가 부분
extern HWND			g_hWnd;
extern HINSTANCE	g_hInstance;
extern POINT		g_ptMouse;
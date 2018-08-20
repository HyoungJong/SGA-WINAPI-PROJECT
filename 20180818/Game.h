#pragma once
#pragma warning (disable : 4996)

// <Windows.h> 는 이 안에 있음
#include "commonMacroFunction.h"	

// 시스템 헤더 추가 부분
#include <tchar.h>
#include <math.h>
#include <string>
#include <vector>
#include <list>
#include <map>

using namespace std;
//using std::string;
//using std::list;
//using std::map;


// 사용자 정의 헤더 추가 부분
#include "randomFunction.h"
#include "timerManager.h"
#include "KeyManager.h"
#include "ImageManager.h"
#include "EffectManager.h"
#include "SceneManager.h"
#include "txtData.h"
#include "Camera.h"
#include "Image.h"
#include "util.h"

// 빌드 옵션
#define _TEST_MODE
#define _EFFECT

// 매크로
#define WINSTARTX		50
#define WINSTARTY		50
#define WINSIZEX		800
#define WINSIZEY		600


// 각종 매크로 디파인 추가 부분
#define IMAGEMANAGER	ImageManager::getSingleton()
#define KEYMANAGER		KeyManager::getSingleton()
#define RND				randomFunction::getSingleton()
#define CAMERA			Camera::getSingleton()
#define TXTDATA			txtData::getSingleton()
#define TIMEMANAGER		timerManager::getSingleton()
#define EFFECTMANAGER	EffectManager::getSingleton() 
#define SCENEMANAGER    SceneManager::getSingleton()

#define SAFE_DELETE(p)	{ if(p) { delete(p); (p) = NULL; }}
#define SAFE_RELEASE(p) { if(p) { (p)->release(); (p) = NULL; }}

// EXTERN 선언한 변수 추가 부분
extern HWND			g_hWnd;
extern HINSTANCE	g_hInstance;
extern POINT		g_ptMouse;

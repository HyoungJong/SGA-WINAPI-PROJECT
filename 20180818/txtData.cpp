#include "Game.h"
#include "txtData.h"

txtData::txtData()
{
}

txtData::~txtData()
{
}

HRESULT txtData::init()
{
	return S_OK;
}

void txtData::release()
{
}

void txtData::txtSave(const TCHAR * saveFileName, vector<string> vStr)
{
	HANDLE	file;
	TCHAR	str[128];
	DWORD	write;

	_tcsncpy_s(str, 128, vectorArrayCombine(vStr), 126);
	file = CreateFile(saveFileName, GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file, str, 128, &write, NULL);
	CloseHandle(file);
}

TCHAR * txtData::vectorArrayCombine(vector<string> vArray)
{
	TCHAR str[128];
	ZeroMemory(str, sizeof(str));
	
	for (int i = 0; i < vArray.size(); i++)
	{
		_tcsncat_s(str, 128, vArray[i].c_str(), 126);

		if (i + 1 < vArray.size())
			_tcscat(str, ",");
	}
	
	return str;
}

vector<string> txtData::txtLoad(const TCHAR * loadFileName)
{
	HANDLE	file;
	TCHAR	str[128];
	DWORD	read;
	file = CreateFile(loadFileName, GENERIC_READ, FALSE, NULL, OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, str, 128, &read, NULL);

	CloseHandle(file);

	return charArraySeparation(str);
}

vector<string> txtData::charArraySeparation(TCHAR charArray[])
{
	vector<string> vArray;

	TCHAR* temp;
	const TCHAR* seperator = TEXT(",");
	TCHAR* token;

	token = _tcstok(charArray, seperator);
	vArray.push_back(token);

	while (NULL != (token = _tcstok(NULL, seperator)))
	{
		vArray.push_back(token);
	}

	return vArray;
}

bool txtData::INIFilePathSetting()
{
	TCHAR szTemp[MAX_PATH] = { 0, };
	GetModuleFileName(NULL, szTemp, MAX_PATH);

	string strTemp(szTemp, szTemp + _tcslen(szTemp));

	size_t size = strTemp.rfind(TEXT("\\"), strTemp.size());
	string::iterator it = strTemp.begin();
	string::iterator itEnd = it + size;

	strTemp.assign(it, itEnd);

	strPath = strTemp;

	return true;
}

string txtData::GetINIFileInfo(const TCHAR * pszSection, const TCHAR * pszKey, const TCHAR * pszFile)
{
	size_t nsize = 0;

	INIMap_it it = mINIData.find(make_pair<string, string>(pszSection, pszKey));
	if (it != mINIData.end())
		return (it->second);

	INIFilePathSetting();

	string strTemp;
	string strTempPath = strPath + TEXT("\\") + pszFile;

	TCHAR szTemp[100] = { 0, };
	GetPrivateProfileString(pszSection, pszKey, TEXT("None"), szTemp,
		sizeof(szTemp), strTempPath.c_str());

	//GetPrivateProfileInt
	//GetPrivateProfileStruct

	if (!_tcscmp(strTemp.c_str(), TEXT("None")))
		return TEXT("None");
	else
		strTemp = szTemp;

	// 여기는 순서가 잘 못 되었으니 추후 각자 수정.
	mINIData.insert(INIMap::value_type(make_pair<string, string>(pszSection, pszKey), strTemp));

	return string();
}

void txtData::SetINIFileInfo(const TCHAR * pszSection, const TCHAR * pszKey, const TCHAR * pszData, const TCHAR * pszFile)
{
	INIFilePathSetting();

	string strTempPath = strPath + TEXT("\\") + pszFile;

	if (!WritePrivateProfileString(pszSection, pszKey, pszData, strTempPath.c_str()))
	{
		// 실패 처리.....각자...

	}
}

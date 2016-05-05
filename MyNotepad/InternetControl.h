#pragma once

typedef LPVOID HINTERNET;
#define READ_SIZE 1024

class CInternetControl
{
public:
	CInternetControl(void);
	~CInternetControl(void);
	BOOL InternetReadData(IN PTCHAR szUrl,OUT PTCHAR* szResult);
	VOID InternetClearData(PTCHAR pData);
private:
	HINTERNET m_hInter;


};


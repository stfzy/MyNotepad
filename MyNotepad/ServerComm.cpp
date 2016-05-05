#include "StdAfx.h"
#include "ServerComm.h"
#include "InternetControl.h"
#include "impl.h"
CServerComm::CServerComm(void)
{
	m_InterNetCon = new CInternetControl;
}


CServerComm::~CServerComm(void)
{
	if(m_InterNetCon)
		delete m_InterNetCon;
}

bool CServerComm::RegesiterUser(PTCHAR ptszUsername,PTCHAR ptszPassword,PTCHAR ptszPasswordReplay,PTCHAR ptszEmail)
{
	return true;
}
 
bool CServerComm::LoginServer(PTCHAR ptszUsername,PTCHAR ptszPassword)
{
#define TEST_FILE_PATH "d:\\netdata.txt"
#define CONFIG_NAME _T("MyNotePad.config")
 
	PTCHAR pBuffer =NULL; 
	TCHAR szLoginUrl[1024] = {0},szServerUrl[1024] = {0},szLocalPath[1024];
	GetCurrentDirectory(1024,szLocalPath);
	if(GetLastError() != 0)
		return false;

	_tcscat_s(szLocalPath,1024,L"\\");
	_tcscat_s(szLocalPath,1024,CONFIG_NAME);

	GetPrivateProfileString(_T("config"),_T("serverurl"),_T(""),szServerUrl,1024,szLocalPath);

	if(GetLastError() != 0)
		return false;

	_stprintf_s(szLoginUrl,1024,_T("%s?username=%s&password=%s"),szServerUrl,ptszUsername,ptszPassword);

	if(m_InterNetCon->InternetReadData(szLoginUrl,&pBuffer))
	{
		FILE * pf; 
		fopen_s(&pf,TEST_FILE_PATH,"ab+"); 
		fwrite(pBuffer,strlen((char*)(pBuffer)),1,pf); 
		fclose(pf);
		delete[] pBuffer;
		//TODO: 判断账号密码的正确性
		return true;
	}
	else
	{
		return false;
	}
}

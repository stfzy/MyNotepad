#include "StdAfx.h"
#include "ServerComm.h"
#include "commfunc.h"
#include "md5/MD5.h"
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
#pragma region �û�ע��
bool CServerComm::RegesiterUser(PTCHAR ptszUsername,PTCHAR ptszPassword,PTCHAR ptszPasswordReplay,PTCHAR ptszEmail, int& iErroCode, PTCHAR erroMsg)
{
	PTCHAR pBuffer =NULL; 
	TCHAR szLoginUrl[1024] = {0},szServerUrl[1024] = {0},szLocalPath[1024];
	//��֤���������Ƿ�same
	if(_tcscmp(ptszPasswordReplay,ptszPassword) != 0)
	{
		_tcscpy_s(erroMsg,MAX_PATH,regPassNotSameErro);
		return false;
	}
	//������md5����
	char szMd5Pass[33] = {0};
	Md5Encode(ptszPassword,szMd5Pass); 
	//��ȡ��ǰĿ¼
	GetCurrentDirectory(1024,szLocalPath);
	if(GetLastError() != 0)
		return false;

	//�����ܺ��MD5ת��Ϊunicode�ַ�
	WCHAR * md5Pass = ANSIToUnicode(szMd5Pass);
	_tcscat_s(szLocalPath,1024,L"\\");
	_tcscat_s(szLocalPath,1024,CONFIG_NAME);

	//��ȡ�����ַ
	GetPrivateProfileString(_T("config"),_T("serverurlregi"),_T(""),szServerUrl,1024,szLocalPath); 
	if(GetLastError() != 0)
	{
		_tcscpy_s(erroMsg,MAX_PATH,configErroMsg); 
		return false; 
	}
	_stprintf_s(szLoginUrl,1024,REGI_PARAM,szServerUrl,ptszUsername,md5Pass,ptszEmail);
	delete[] md5Pass;
	//���������ȡ��ִ
	if(m_InterNetCon->InternetReadData(szLoginUrl,&pBuffer))
	{
		int iStatus;
		if(GetStatusAndErroCode((char*)pBuffer,&iStatus,&iErroCode))
		{
			if(iStatus == 0)
			{
				_tcscpy_s(erroMsg,MAX_PATH,regiErroCode[iErroCode]); 
				return false;
			}
		}
		_tcscpy_s(erroMsg,MAX_PATH,regSuccessMsg);
		return true;
	}
	else
	{ 
		_tcscpy_s(erroMsg,MAX_PATH,commErroMsg);
		return false;
	} 
	return true;
}
#pragma endregion �û�ע��

#pragma region ��¼������  
bool CServerComm::LoginServer(PTCHAR ptszUsername,PTCHAR ptszPassword, int& iErroCode, PTCHAR erroMsg)
{ 
	PTCHAR pBuffer =NULL; 
	TCHAR szLoginUrl[1024] = {0},szServerUrl[1024] = {0},szLocalPath[1024];
	
	//������md5����
	char szMd5Pass[33] = {0};
	Md5Encode(ptszPassword,szMd5Pass); 
	//��ȡ��ǰĿ¼
	GetCurrentDirectory(1024,szLocalPath);
	if(GetLastError() != 0)
		return false;

	//�����ܺ��MD5ת��Ϊunicode�ַ�
	WCHAR * md5Pass = ANSIToUnicode(szMd5Pass);
	_tcscat_s(szLocalPath,1024,L"\\");
	_tcscat_s(szLocalPath,1024,CONFIG_NAME);

	//��ȡ�����ַ
	GetPrivateProfileString(_T("config"),_T("serverurllogin"),_T(""),szServerUrl,1024,szLocalPath); 
	if(GetLastError() != 0)
	{
		_tcscpy_s(erroMsg,MAX_PATH,configErroMsg); 
		return false; 
	}
	_stprintf_s(szLoginUrl,1024,LOGIN_PARAM,szServerUrl,ptszUsername,md5Pass);
	delete[] md5Pass;
	//���������ȡ��ִ
	if(m_InterNetCon->InternetReadData(szLoginUrl,&pBuffer))
	{
		int iStatus;
		if(GetStatusAndErroCode((char*)pBuffer,&iStatus,&iErroCode))
		{
			if(iStatus == 0)
			{
				_tcscpy_s(erroMsg,MAX_PATH,logErroCode[iErroCode]); 
				return false;
			}
		}
		_tcscpy_s(erroMsg,MAX_PATH,logSuccessMsg);
		return true;
	}
	else
	{ 
		_tcscpy_s(erroMsg,MAX_PATH,commErroMsg);
		return false;
	} 
}
#pragma endregion ��¼������
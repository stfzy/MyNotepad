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
#pragma region 用户注册
bool CServerComm::RegesiterUser(PTCHAR ptszUsername,PTCHAR ptszPassword,PTCHAR ptszPasswordReplay,PTCHAR ptszEmail, int& iErroCode, PTCHAR erroMsg)
{
	PTCHAR pBuffer =NULL; 
	TCHAR szLoginUrl[1024] = {0},szServerUrl[1024] = {0},szLocalPath[1024];
	//验证两次密码是否same
	if(_tcscmp(ptszPasswordReplay,ptszPassword) != 0)
	{
		_tcscpy_s(erroMsg,MAX_PATH,regPassNotSameErro);
		return false;
	}
	//将密码md5加密
	char szMd5Pass[33] = {0};
	Md5Encode(ptszPassword,szMd5Pass); 
	//获取当前目录
	GetCurrentDirectory(1024,szLocalPath);
	if(GetLastError() != 0)
		return false;

	//将加密后的MD5转换为unicode字符
	WCHAR * md5Pass = ANSIToUnicode(szMd5Pass);
	_tcscat_s(szLocalPath,1024,L"\\");
	_tcscat_s(szLocalPath,1024,CONFIG_NAME);

	//获取请求地址
	GetPrivateProfileString(_T("config"),_T("serverurlregi"),_T(""),szServerUrl,1024,szLocalPath); 
	if(GetLastError() != 0)
	{
		_tcscpy_s(erroMsg,MAX_PATH,configErroMsg); 
		return false; 
	}
	_stprintf_s(szLoginUrl,1024,REGI_PARAM,szServerUrl,ptszUsername,md5Pass,ptszEmail);
	delete[] md5Pass;
	//发送请求读取回执
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
#pragma endregion 用户注册

#pragma region 登录服务器  
bool CServerComm::LoginServer(PTCHAR ptszUsername,PTCHAR ptszPassword, int& iErroCode, PTCHAR erroMsg)
{ 
	PTCHAR pBuffer =NULL; 
	TCHAR szLoginUrl[1024] = {0},szServerUrl[1024] = {0},szLocalPath[1024];
	
	//将密码md5加密
	char szMd5Pass[33] = {0};
	Md5Encode(ptszPassword,szMd5Pass); 
	//获取当前目录
	GetCurrentDirectory(1024,szLocalPath);
	if(GetLastError() != 0)
		return false;

	//将加密后的MD5转换为unicode字符
	WCHAR * md5Pass = ANSIToUnicode(szMd5Pass);
	_tcscat_s(szLocalPath,1024,L"\\");
	_tcscat_s(szLocalPath,1024,CONFIG_NAME);

	//获取请求地址
	GetPrivateProfileString(_T("config"),_T("serverurllogin"),_T(""),szServerUrl,1024,szLocalPath); 
	if(GetLastError() != 0)
	{
		_tcscpy_s(erroMsg,MAX_PATH,configErroMsg); 
		return false; 
	}
	_stprintf_s(szLoginUrl,1024,LOGIN_PARAM,szServerUrl,ptszUsername,md5Pass);
	delete[] md5Pass;
	//发送请求读取回执
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
#pragma endregion 登录服务器
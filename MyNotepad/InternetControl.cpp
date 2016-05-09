#include "StdAfx.h"
#include "InternetControl.h"
#include <wininet.h>
#pragma comment(lib,"Wininet.lib")
CInternetControl::CInternetControl(void)
{
	DWORD dwFlags;
	InternetGetConnectedState(&dwFlags, 0);     //获取当前网络连接信息
	 
	if(!(dwFlags & INTERNET_CONNECTION_PROXY))
	{
		m_hInter = InternetOpen(_T("MyNotepad"),INTERNET_OPEN_TYPE_PRECONFIG_WITH_NO_AUTOPROXY,NULL,NULL,0);
	}
	else
	{
		m_hInter = InternetOpen(_T("MyNotepad"),INTERNET_OPEN_TYPE_PRECONFIG,NULL,NULL,0);
	}


	if(!m_hInter)
	{
		throw GetLastError();
	}
}


CInternetControl::~CInternetControl(void)
{
	if(m_hInter)
		InternetCloseHandle(m_hInter);

}

BOOL CInternetControl::InternetReadData(IN PTCHAR szUrl,OUT PTCHAR* szResult)
{
	BOOL bRet = FALSE;
	TCHAR szHeaders[] =_T("");//_T("Accept: Accept-Language: zh-cn/r/nAccept-Encoding: gzip, deflate/r/nUser-Agent: Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.0; MyIE2; .NET CLR 1.1.4322)");
	HINTERNET hInterOpenUrl = InternetOpenUrl(m_hInter,szUrl,szHeaders,_tcslen(szHeaders),INTERNET_FLAG_DONT_CACHE | INTERNET_FLAG_PRAGMA_NOCACHE | INTERNET_FLAG_RELOAD,0);//打开网址 get数据
  
	if(hInterOpenUrl)//如果成功
	{
		BOOL bReadRet;
		DWORD dwRead;
		PCHAR pBuffer = NULL;
		//DWORD dwByteToRead = 0; 
		//DWORD dwSizeOfRq = 8; 
		//DWORD dwBytes = 0;
	
// 		if (!HttpQueryInfo(hInterOpenUrl, HTTP_QUERY_CONTENT_LENGTH |HTTP_QUERY_FLAG_NUMBER,
// 			(LPVOID)&dwByteToRead, &dwSizeOfRq, NULL))
// 		{
// 			DWORD dwErro = GetLastError();
// 			InternetCloseHandle(hInterOpenUrl);
// 			return FALSE;
// 		}
		DWORD dwSize = 0,dwOffset = 0;
		pBuffer = new CHAR[READ_SIZE];
		if(!pBuffer)
		{
			InternetCloseHandle(hInterOpenUrl);
			return FALSE;
		}
		ZeroMemory(pBuffer,READ_SIZE);
		dwSize = READ_SIZE;
	
		
		do 
		{  
			bReadRet = InternetReadFile(hInterOpenUrl,pBuffer+dwOffset,READ_SIZE,&dwRead);
			if(!bReadRet)
			{	
				break;
			}

			if(dwRead>0)
			{
				dwSize+=READ_SIZE;
				dwOffset+=dwRead;
				char * szTmp = new CHAR[dwSize];
				if(!szTmp)
				{
					InternetCloseHandle(hInterOpenUrl);
					delete[] pBuffer;
					return FALSE;
				}
				ZeroMemory(szTmp,dwSize);
				memcpy(szTmp,pBuffer,dwOffset);
				delete[] pBuffer;
				pBuffer = szTmp; 
			}

			if(dwRead== 0)
				break;

		} while (TRUE);
		
		*szResult = (PTCHAR)pBuffer;
		InternetCloseHandle(hInterOpenUrl);
		bRet = bReadRet;
	}
	
	return bRet;
}

VOID CInternetControl::InternetClearData(PTCHAR pData)
{
	if(pData)
		delete[] pData;
}

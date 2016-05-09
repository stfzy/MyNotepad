#include "StdAfx.h"
#include "md5/MD5.h"
#include "json.h"
#ifdef _DEBUG
#pragma comment(lib,"json/json_vc71_libmtd.lib")
#else
#pragma comment(lib,"json/json_vc71_libmt.lib")
#endif


wchar_t* Utf82Unicode(const char* utf, size_t *unicode_number)  
{  
	if(!utf || !strlen(utf))  
	{  
		*unicode_number = 0;  
		return NULL;  
	}  
	int dwUnicodeLen = MultiByteToWideChar(CP_UTF8,0,utf,-1,NULL,0);  
	size_t num = dwUnicodeLen*sizeof(wchar_t);  
	wchar_t *pwText = (wchar_t*)malloc(num);  
	memset(pwText,0,num);  
	MultiByteToWideChar(CP_UTF8,0,utf,-1,pwText,dwUnicodeLen);  
	*unicode_number = dwUnicodeLen - 1;  
	return pwText;  
}  
wchar_t* ANSIToUnicode( char* str )
{
	int  len = 0;
	len = strlen(str)+1;
	int  unicodeLen = ::MultiByteToWideChar( CP_ACP,
		0,
		str,
		-1,
		NULL,
		0 ); 
	wchar_t *  pUnicode; 
	pUnicode = new  wchar_t[unicodeLen+1]; 
	memset(pUnicode,0,(unicodeLen+1)*sizeof(wchar_t)); 
	::MultiByteToWideChar( CP_ACP,
		0,
		str,
		-1,
		(LPWSTR)pUnicode,
		unicodeLen ); 

	return  pUnicode; 
}
char * Unicode2Ansi(wchar_t* unicodeStr)
{
	char*     pElementText;
	int    iTextLen;
	// wide char to multi char
	iTextLen = WideCharToMultiByte( CP_ACP,
		0,
		unicodeStr,
		-1,
		NULL,
		0,
		NULL,
		NULL );
	pElementText = new char[iTextLen + 1];
	memset( ( void* )pElementText, 0, sizeof( char ) * ( iTextLen + 1 ) );
	::WideCharToMultiByte( CP_ACP,
		0,
		unicodeStr,
		-1,
		pElementText,
		iTextLen,
		NULL,
		NULL );

	return pElementText;
}
void Encode(unsigned char* data,int datalen,char * datamd5)
{ 
	unsigned char decrypt[16] ;
	int i;
	MD5_CTX md5;
	MD5Init(&md5);
	MD5Update(&md5, data, datalen);
	MD5Final(&md5, decrypt);
	for (i = 0; i < 16; i++)
	{
		sprintf_s(&datamd5[i*2],3,"%02x", decrypt[i]); 
	} 
} 
void Md5Encode(PTCHAR  beEncode,char* encoded)
{ 
	char * passAnsi = Unicode2Ansi(beEncode);
	Encode((unsigned char*)passAnsi,strlen(passAnsi),encoded);
	delete [] passAnsi;
}
bool GetStatusAndErroCode(char* jsonData,int * iSta,int* ierroCode)
{ 
	Json::Reader reader;  
	Json::Value root;  
	if(jsonData)
	{
		if(iSta&&ierroCode)
		{
			*iSta = *ierroCode = 0;
			if (reader.parse(jsonData, root))  // reader将Json字符串解析到root，root将包含Json里所有子元素   
			{   
				//std::string upload_id = root["uploadid"].asString();  // 访问节点，upload_id = "UP000000"   
				//int code = root["code"].asInt();    // 访问节点，code = 100  
				*iSta = root["status"].asInt();    // 访问节点，code = 100   
				*ierroCode = root["errocode"].asInt();
				return true;
			}   
		}  
	}
	return false;
}




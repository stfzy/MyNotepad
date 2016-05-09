



//数据加解密
void Md5Encode(PTCHAR  beEncode,char* encoded);
void Encode(unsigned char* data,int datalen,char * datamd5);
bool GetStatusAndErroCode(char* jsonData,int * iSta,int* ierroCode);

wchar_t* Utf82Unicode(const char* utf, size_t *unicode_number)   ;
wchar_t* ANSIToUnicode( char* str ) ;
char * Unicode2Ansi(wchar_t* unicodeStr);
 
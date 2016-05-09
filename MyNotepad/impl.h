
#include <map>
using namespace std;
/*
1.注册：
http://localhost:8080/MyBook/loginController/register.do?bkname=&bkpassword=&bkemail=   
返回： 成功：{status:1,errocode:0}  失败：{status:0,errocode:}  0：用户名已存在 1.邮箱已存在 2.用户名和邮箱都存在 3.未知错误
2.用户登录：http://localhost:8080/MyBook/loginController/login.do?username=&pass=
返回：成功：{status:1,errocode:0} 失败{status:0,errocode:}  0：用户名不存在 1.密码不正确 2.未知错误
3.修改密码
http://localhost:8080/MyBook/loginController/updatePass.do?username=&pass=&passNew=
返回：成功：{status:1,errocode:0} 失败：{status:0,errocode:} 0：用户名不存在1：密码不正确 2.密码设置失败

*/
#define TEST_FILE_PATH "d:\\netdata.txt"
#define CONFIG_NAME _T("MyNotePad.config") 
#define LOGIN_PARAM _T("%s?username=%s&password=%s")
#define REGI_PARAM _T("%s?bkname=%s&bkpassword=%s&bkemail=%s")

TCHAR regiErroCode[][260] = 
{
	{_T("用户名已存在")},
	{_T("邮箱已存在")},
	{_T("用户名和邮箱都存在")},
	{_T("未知错误")}
};
TCHAR changepassErroCode[][260] = 
{
	{_T("用户名不存在")},
	{_T("原始密码不正确")},
	{_T("密码设置失败")} 
};
TCHAR logErroCode[][260] = 
{
	{_T("用户名不存在")},
	{_T("密码不正确")},
	{_T("未知错误")}	 
};
TCHAR logSuccessMsg[] = _T("登录成功！");
TCHAR regSuccessMsg[] = _T("注册成功！");

TCHAR commErroMsg[] = _T("未知错误！请检查你的网络配置！");
TCHAR configErroMsg[] = _T("读取配置文件出错！");
TCHAR regPassNotSameErro[] = _T("两次输入的密码不同！");


enum NOTE_STATUS
{
	NOTE_LOGIN_SUCCESS = 0,  //登录成功
	NOTE_LOGIN_FAILED,       //登录失败
	NOTE_REGISTER_SUCCESS,   //注册成功
	NOTE_REGISTER_FAILED     //注册失败
};
struct stru_TAG
{
	int iTagId;
	CString cstrTagName;
};
struct stru_CLASS
{
	int iClassId;
	CString cstrClassName;
	stru_CLASS * cstrSonClass;
};
struct stru_NOTE
{ 
	int iNoteId;
	CString cstrNoteTitle;
	CString cstrNoteData;
	int iAssociationTagId;
	int iAssociationNoteId;
	tm tmNoteLastModify;
};
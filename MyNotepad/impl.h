
#include <map>
using namespace std;
/*
1.ע�᣺
http://localhost:8080/MyBook/loginController/register.do?bkname=&bkpassword=&bkemail=   
���أ� �ɹ���{status:1,errocode:0}  ʧ�ܣ�{status:0,errocode:}  0���û����Ѵ��� 1.�����Ѵ��� 2.�û��������䶼���� 3.δ֪����
2.�û���¼��http://localhost:8080/MyBook/loginController/login.do?username=&pass=
���أ��ɹ���{status:1,errocode:0} ʧ��{status:0,errocode:}  0���û��������� 1.���벻��ȷ 2.δ֪����
3.�޸�����
http://localhost:8080/MyBook/loginController/updatePass.do?username=&pass=&passNew=
���أ��ɹ���{status:1,errocode:0} ʧ�ܣ�{status:0,errocode:} 0���û���������1�����벻��ȷ 2.��������ʧ��

*/
#define TEST_FILE_PATH "d:\\netdata.txt"
#define CONFIG_NAME _T("MyNotePad.config") 
#define LOGIN_PARAM _T("%s?username=%s&password=%s")
#define REGI_PARAM _T("%s?bkname=%s&bkpassword=%s&bkemail=%s")

TCHAR regiErroCode[][260] = 
{
	{_T("�û����Ѵ���")},
	{_T("�����Ѵ���")},
	{_T("�û��������䶼����")},
	{_T("δ֪����")}
};
TCHAR changepassErroCode[][260] = 
{
	{_T("�û���������")},
	{_T("ԭʼ���벻��ȷ")},
	{_T("��������ʧ��")} 
};
TCHAR logErroCode[][260] = 
{
	{_T("�û���������")},
	{_T("���벻��ȷ")},
	{_T("δ֪����")}	 
};
TCHAR logSuccessMsg[] = _T("��¼�ɹ���");
TCHAR regSuccessMsg[] = _T("ע��ɹ���");

TCHAR commErroMsg[] = _T("δ֪������������������ã�");
TCHAR configErroMsg[] = _T("��ȡ�����ļ�����");
TCHAR regPassNotSameErro[] = _T("������������벻ͬ��");


enum NOTE_STATUS
{
	NOTE_LOGIN_SUCCESS = 0,  //��¼�ɹ�
	NOTE_LOGIN_FAILED,       //��¼ʧ��
	NOTE_REGISTER_SUCCESS,   //ע��ɹ�
	NOTE_REGISTER_FAILED     //ע��ʧ��
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
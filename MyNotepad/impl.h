
#include <map>
using namespace std;
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
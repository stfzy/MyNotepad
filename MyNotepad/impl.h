
#include <map>
using namespace std;
enum NOTE_STATUS
{
	NOTE_LOGIN_SUCCESS = 0,  //µÇÂ¼³É¹¦
	NOTE_LOGIN_FAILED,       //µÇÂ¼Ê§°Ü
	NOTE_REGISTER_SUCCESS,   //×¢²á³É¹¦
	NOTE_REGISTER_FAILED     //×¢²áÊ§°Ü
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
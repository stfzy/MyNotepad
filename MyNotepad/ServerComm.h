#pragma once
class CInternetControl;
class CServerComm
{
private:
	CInternetControl * m_InterNetCon;
public:
	CServerComm(void);
	~CServerComm(void);

	//��¼ע��
	bool LoginServer(PTCHAR ptszUsername,PTCHAR ptszPassword);
	bool RegesiterUser(PTCHAR ptszUsername,PTCHAR ptszPassword,PTCHAR ptszPasswordReplay,PTCHAR ptszEmail);
	
	//��ȫ�������
	bool GetStartPass();
	bool SetStartPass();
	bool ChangeStartPass();

	//������
	bool GetClass();
	bool AddClass();
	bool DelClass();
	bool ChangeClassName();
	bool ChangeClassPos();

	//�������
	bool GetNote();
	bool AddNote();
	bool DelNote();
	bool ChangeNotePos();
	bool SaveNoteData();
	bool AddTagToNote();
	bool DelTagToNote();
	bool AddLinkToNote();
	bool DelLinkToNote();
	
	//��ǩ����
	bool GetTagNote();
	bool GetTag();
	bool AddTag();
	bool DelTag();
	bool ChangeTag();

	//��������
	bool SearchNoteByTag();
	bool SearchNoteByDate();
	bool SearchNoteByName();
	
	//��������
	bool GetTODONote();
	bool AddTODONote();
	bool DelTODONote();
	bool ChangeTODONote();
	bool SaveTODONoteData();
	bool ChangeTODONoteStatus();
	bool SetRemindRoutine();
};


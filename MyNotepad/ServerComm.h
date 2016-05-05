#pragma once
class CInternetControl;
class CServerComm
{
private:
	CInternetControl * m_InterNetCon;
public:
	CServerComm(void);
	~CServerComm(void);

	//登录注册
	bool LoginServer(PTCHAR ptszUsername,PTCHAR ptszPassword);
	bool RegesiterUser(PTCHAR ptszUsername,PTCHAR ptszPassword,PTCHAR ptszPasswordReplay,PTCHAR ptszEmail);
	
	//安全密码管理
	bool GetStartPass();
	bool SetStartPass();
	bool ChangeStartPass();

	//类别管理
	bool GetClass();
	bool AddClass();
	bool DelClass();
	bool ChangeClassName();
	bool ChangeClassPos();

	//事项管理
	bool GetNote();
	bool AddNote();
	bool DelNote();
	bool ChangeNotePos();
	bool SaveNoteData();
	bool AddTagToNote();
	bool DelTagToNote();
	bool AddLinkToNote();
	bool DelLinkToNote();
	
	//标签管理
	bool GetTagNote();
	bool GetTag();
	bool AddTag();
	bool DelTag();
	bool ChangeTag();

	//查找事项
	bool SearchNoteByTag();
	bool SearchNoteByDate();
	bool SearchNoteByName();
	
	//待办事项
	bool GetTODONote();
	bool AddTODONote();
	bool DelTODONote();
	bool ChangeTODONote();
	bool SaveTODONoteData();
	bool ChangeTODONoteStatus();
	bool SetRemindRoutine();
};


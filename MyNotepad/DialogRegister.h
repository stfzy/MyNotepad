#pragma once


// CDialogRegister �Ի���

class CDialogRegister : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogRegister)

public:
	CDialogRegister(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDialogRegister();

// �Ի�������
	enum { IDD = IDD_REGISTER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString edit_uname;
	CString edit_pass;
	CString edit_repass;
	CString edit_email;
};

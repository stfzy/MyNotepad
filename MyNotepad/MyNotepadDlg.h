
// MyNotepadDlg.h : ͷ�ļ�
//

#pragma once


// CMyNotepadDlg �Ի���
class CMyNotepadDlg : public CDialogEx
{
// ����
public:
	CMyNotepadDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MYNOTEPAD_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString edit_uname;
	CString edit_passwd;
	afx_msg void OnBnClickedButton2();
};

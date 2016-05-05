
// MyNotepadDlg.h : 头文件
//

#pragma once


// CMyNotepadDlg 对话框
class CMyNotepadDlg : public CDialogEx
{
// 构造
public:
	CMyNotepadDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MYNOTEPAD_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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

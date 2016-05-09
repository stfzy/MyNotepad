// DialogRegister.cpp : 实现文件
//

#include "stdafx.h"
#include "MyNotepad.h"
#include "DialogRegister.h"
#include "afxdialogex.h"
#include "MyNotepadDlg.h"
#include "ServerComm.h"

// CDialogRegister 对话框

IMPLEMENT_DYNAMIC(CDialogRegister, CDialogEx)

CDialogRegister::CDialogRegister(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialogRegister::IDD, pParent)
	, edit_uname(_T(""))
	, edit_pass(_T(""))
	, edit_repass(_T(""))
	, edit_email(_T(""))
{
	CMyNotepadDlg * DengluDlg = (CMyNotepadDlg *)pParent;
	 

}

CDialogRegister::~CDialogRegister()
{
}

void CDialogRegister::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, edit_uname);
	DDX_Text(pDX, IDC_EDIT2, edit_pass);
	DDX_Text(pDX, IDC_EDIT3, edit_repass);
	DDX_Text(pDX, IDC_EDIT4, edit_email);
}


BEGIN_MESSAGE_MAP(CDialogRegister, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDialogRegister::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDialogRegister 消息处理程序


void CDialogRegister::OnBnClickedButton1()
{
	UpdateData(TRUE);
	int iErroCode;
	TCHAR szErroMsg[MAX_PATH];
	if(g_cServerComm.RegesiterUser(edit_uname.GetBuffer(),edit_pass.GetBuffer(),edit_repass.GetBuffer(),edit_email.GetBuffer(),iErroCode,szErroMsg))
	{
		MessageBox(szErroMsg);
	}
	else
	{ 
		MessageBox(szErroMsg);
	}
	 
}

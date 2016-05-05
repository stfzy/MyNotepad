// DialogRegister.cpp : 实现文件
//

#include "stdafx.h"
#include "MyNotepad.h"
#include "DialogRegister.h"
#include "afxdialogex.h"
#include "MyNotepadDlg.h"

// CDialogRegister 对话框

IMPLEMENT_DYNAMIC(CDialogRegister, CDialogEx)

CDialogRegister::CDialogRegister(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialogRegister::IDD, pParent)
{
	CMyNotepadDlg * DengluDlg = (CMyNotepadDlg *)pParent;
	MessageBox(DengluDlg->edit_uname);

}

CDialogRegister::~CDialogRegister()
{
}

void CDialogRegister::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogRegister, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDialogRegister::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDialogRegister 消息处理程序


void CDialogRegister::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	MessageBox(_T("注册成功！"));
}

// DialogRegister.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyNotepad.h"
#include "DialogRegister.h"
#include "afxdialogex.h"
#include "MyNotepadDlg.h"

// CDialogRegister �Ի���

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


// CDialogRegister ��Ϣ�������


void CDialogRegister::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	MessageBox(_T("ע��ɹ���"));
}

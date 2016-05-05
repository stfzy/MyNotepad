
// MyNotepadDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyNotepad.h"
#include "MyNotepadDlg.h"
#include "afxdialogex.h"
#include "InternetControl.h"
#include "DialogRegister.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMyNotepadDlg �Ի���




CMyNotepadDlg::CMyNotepadDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMyNotepadDlg::IDD, pParent)
	, edit_uname(_T(""))
	, edit_passwd(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyNotepadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, edit_uname);
	DDX_Text(pDX, IDC_EDIT2, edit_passwd);
}

BEGIN_MESSAGE_MAP(CMyNotepadDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMyNotepadDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMyNotepadDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMyNotepadDlg ��Ϣ�������

BOOL CMyNotepadDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��
	//  
	 

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMyNotepadDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMyNotepadDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMyNotepadDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


wchar_t* Utf82Unicode(const char* utf, size_t *unicode_number)  
{  
	if(!utf || !strlen(utf))  
	{  
		*unicode_number = 0;  
		return NULL;  
	}  
	int dwUnicodeLen = MultiByteToWideChar(CP_UTF8,0,utf,-1,NULL,0);  
	size_t num = dwUnicodeLen*sizeof(wchar_t);  
	wchar_t *pwText = (wchar_t*)malloc(num);  
	memset(pwText,0,num);  
	MultiByteToWideChar(CP_UTF8,0,utf,-1,pwText,dwUnicodeLen);  
	*unicode_number = dwUnicodeLen - 1;  
	return pwText;  
}  

 #pragma region ��¼������ 

bool LoginServer(PTCHAR pUname,PTCHAR pPass)
{ 
#define TEST_FILE_PATH "d:\\netdata.txt"
#define CONFIG_NAME _T("MyNotePad.config")
 
	CInternetControl cic;
	PTCHAR pBuffer =NULL; 
	TCHAR szLoginUrl[1024] = {0},szServerUrl[1024] = {0},szLocalPath[1024];
	GetCurrentDirectory(1024,szLocalPath);
	if(GetLastError() != 0)
		return false;
	
	_tcscat_s(szLocalPath,1024,L"\\");
	_tcscat_s(szLocalPath,1024,CONFIG_NAME);

	GetPrivateProfileString(_T("config"),_T("serverurl"),_T(""),szServerUrl,1024,szLocalPath);
	
	if(GetLastError() != 0)
		return false;
	 

	_stprintf_s(szLoginUrl,1024,_T("%s?bkname=%s&bkpassword=%s&bkimageurl="),szServerUrl,pUname,pPass);
  
	if(cic.InternetReadData(szLoginUrl,&pBuffer))
	{
		FILE * pf; 
		fopen_s(&pf,TEST_FILE_PATH,"ab+"); 
		fwrite(pBuffer,strlen((char*)(pBuffer)),1,pf); 
		fclose(pf);
		delete[] pBuffer;
		//TODO: �ж��˺��������ȷ��
		return true;
	}
	else
	{
		return false;
	}
}
#pragma endregion ��¼������


void CMyNotepadDlg::OnBnClickedButton1()
{  
	UpdateData(TRUE);
	CInternetControl cic;
// 	PTCHAR pData = NULL;
// 	PTCHAR pTest = _T("http://192.168.1.105:8080/MyBook/loginController/register.do?bkname=&bkpassword=&bkemail=&bkimageurl=");
// 	cic.InternetReadData(_T("http://www.qq.com"),&pData );
// 	cic.InternetClearData(pData);
  
	if(LoginServer(edit_uname.GetBuffer(),edit_passwd.GetBuffer()))
	{
		//TODO: ��¼�ɹ�
		MessageBox(_T("��¼�ɹ�"));

	}
	else
	{
		//TODO: ��¼ʧ�� 
		MessageBox(_T("��¼ʧ�ܣ�������룺1\r\n�����˺������Ƿ���ȷ��"),_T("��¼ʧ��!"),MB_OK|MB_ICONERROR);

	}
	 
	
}


void CMyNotepadDlg::OnBnClickedButton2()
{
	UpdateData(TRUE);
	CDialogRegister RegiDialog(this);
	RegiDialog.DoModal();

}

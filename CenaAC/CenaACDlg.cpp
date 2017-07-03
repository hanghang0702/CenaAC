
// CenaACDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CenaAC.h"
#include "CenaACDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

void AddLog(CEdit &log, const CString &Text) {
	CString t;
	log.GetWindowTextW(t);
	log.SetWindowTextW(t + Text);
}
// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
public:
	int chs;
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
	chs = 0;
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCenaACDlg �Ի���



CCenaACDlg::CCenaACDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CENAAC_DIALOG, pParent)
	, m_log()
	, m_uname()
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCenaACDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SAVEAS, m_floder);
	//  DDX_Control(pDX, IDC_USERNAME, m_uname);
	//  DDX_Control(pDX, IDC_LOG, m_log);
	//  DDX_Text(pDX, IDC_LOG, m_log);
	//  DDX_Text(pDX, IDC_USERNAME, m_uname);
	//  DDX_Control(pDX, IDC_LOG, m_log);
	//  DDX_Control(pDX, IDC_USERNAME, m_uname);
	DDX_Control(pDX, IDC_LOG2, m_log);
	//  DDX_Control(pDX, IDC_USERNAME, m_uname);
	//  DDX_Control(pDX, IDC_LOG2, m_prob);
	//  DDX_Control(pDX, IDC_PROb, m_prov);
	DDX_Control(pDX, IDC_PROb, m_prob);
	DDX_Control(pDX, IDC_CHECK1, m_chk);
	DDX_Control(pDX, IDC_LOG2, m_log);
	DDX_Control(pDX, IDOK, m_b);
	DDX_Control(pDX, IDC_CHECK3, m_sub);
	DDX_Control(pDX, IDC_USERNAME3, m_in);
	//  DDX_Control(pDX, IDCANCEL, m_out);
	DDX_Control(pDX, IDC_USERNAME2, m_uname);
	DDX_Control(pDX, IDC_USERNAME, m_out);
}

BEGIN_MESSAGE_MAP(CCenaACDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &CCenaACDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &CCenaACDlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_SAVEAS, &CCenaACDlg::OnEnChangeMfceditbrowse1)
	ON_EN_CHANGE(IDC_SAVEAS, &CCenaACDlg::OnEnChangeSaveas)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CCenaACDlg ��Ϣ��������

BOOL CCenaACDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵������ӵ�ϵͳ�˵��С�

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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ����Ӷ���ĳ�ʼ������
	m_log.SetWindowTextW(CString("[CenaAC 2.0 By ������]\r\n��ʼ������...��ϡ�\r\n"));
	m_uname.SetWindowTextW(CString("CxjyAcOIer"));
	m_floder.SetWindowTextW(CString("C:\\"));
	m_prob.SetWindowTextW(CString("test1;test2"));
	m_chk.SetCheck(1);
	m_chk.EnableWindow(0);
	m_sub.SetCheck(1);
	m_in.SetWindowTextW(CString("in"));
	m_out.SetWindowTextW(CString("out"));
	gen = false;
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CCenaACDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի���������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCenaACDlg::OnPaint()
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
HCURSOR CCenaACDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCenaACDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}

void CCenaACDlg::Process() {}
BOOL WStringToString(const std::wstring &wstr, std::string &str)
{
	int nLen = (int)wstr.length();
	str.resize(nLen, ' ');

	int nResult = WideCharToMultiByte(CP_ACP, 0, (LPCWSTR)wstr.c_str(), nLen, (LPSTR)str.c_str(), nLen, NULL, NULL);

	if (nResult == 0)
	{
		return FALSE;
	}

	return TRUE;
}

DWORD _stdcall Process(LPVOID pParam){
	CCenaACDlg* p = (CCenaACDlg*)pParam;
	p->m_b.SetWindowTextW(CString("ִ����..."));
	CString dir, x, pl,f; int chs;
	chs = p->m_sub.GetCheck();
	p->m_floder.GetWindowTextW(dir); 
	p->m_uname.GetWindowTextW(x);
	p->m_prob.GetWindowTextW(pl);
	if (dir[dir.GetLength() - 1] != '\\') dir += '\\';
	dir += x;
	AddLog(p->m_log, CString("\r\n[������־]\r\n\t���浽��") + dir + "\r\n");
	Sleep(500);
	AddLog(p->m_log, CString("\t��Ŀ�б���") + pl + "\r\n");
	Sleep(700);
	AddLog(p->m_log, CString("\t���ڽ�����Ŀ�б�"));
	for (int i = 1; i <= 3; i++) {
		Sleep(500);
		AddLog(p->m_log, CString("."));
	}
	AddLog(p->m_log, CString("�����ɹ���\r\n"));
	Sleep(700);
	CString plist[500], cur = ""; int cnt = 0;
	pl += ";";
	for (int i = 0; i < pl.GetLength(); i++) {
		if (pl[i] == ';') {
			plist[++cnt] = cur;
			cur = "";
		}
		else cur += pl[i];
	}
	AddLog(p->m_log, CString("\t���ڴ���Ŀ¼��") + dir);
	for (int i = 1; i <= 3; i++) {
		Sleep(500);
		AddLog(p->m_log, CString("."));
	}
	CString TT = (CString("mkdir \"") + dir + CString("\""));
	std::wstring temp = TT.GetBuffer(0);
	std::string cmd;
	WStringToString(temp, cmd);
	CString inf, ouf;
	p->m_in.GetWindowTextW(inf);
	p->m_out.GetWindowTextW(ouf);
	system((cmd.c_str()));
	AddLog(p->m_log, CString("�ɹ���\r\n"));
	for (int i = 1; i <= cnt; i++) {
		AddLog(p->m_log, CString("\t���ڴ�����Ŀ[") + plist[i] + CString("]"));
		for (int j = 1; j <= 3; j++) {
			Sleep(500);
			AddLog(p->m_log, CString("."));
		}
		CString tmp = "const",fpath="";
		if (chs) tmp += "  SourcePath:string='" + plist[i] + "\\" + plist[i] + "';", fpath = dir + "\\" + plist[i] + "\\" + plist[i] + ".pas";
		else tmp += "  SourcePath:string='" + plist[i] + "';", fpath = dir + "\\" + plist[i] + ".pas";
		tmp += "  InputFile:string='" + plist[i] + "." + inf + "'; OutputFile:string='" + plist[i] + "." + ouf + "';";
		if (chs) {
			CString tdir = dir + "\\" + plist[i];
			string f;
			WStringToString(wstring(tdir), f);
			f = "mkdir \"" + f+"\"";
			system(f.c_str());
		}
		CString code = tmp + p->m_pascode;
		CStdioFile fl;
		fl.Open(fpath, CFile::typeText | CFile::modeCreate | CFile::modeWrite);
		fl.WriteString(code);
		fl.Close();
		AddLog(p->m_log, CString("�ɹ���\r\n"));
	}
	AddLog(p->m_log, CString("������ϣ�\r\n"));
	p->m_b.SetWindowTextW(CString("���ɣ�"));
	p->gen = false;
	return 0;
}
void CCenaACDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	if (gen) {
		MessageBox(CString("�Ѿ���ʼ���ɲ�����"));
		return;
	}
	gen = true;
	proc = CreateThread(NULL, 0, ::Process, this, 0, NULL);
}


void CCenaACDlg::OnEnChangeMfceditbrowse1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CCenaACDlg::OnEnChangeSaveas()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}




void CCenaACDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	if (nIDEvent == 1) {
		
		KillTimer(1);
	}
	CDialogEx::OnTimer(nIDEvent);
}
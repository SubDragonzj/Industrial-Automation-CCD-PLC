
// cameraDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "camera.h"
#include "cameraDlg.h"
#include "afxdialogex.h"

#include "halconcpp.h"
using namespace HalconCpp;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CcameraDlg 对话框



CcameraDlg::CcameraDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CAMERA_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcameraDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CcameraDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CcameraDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CcameraDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CcameraDlg 消息处理程序

BOOL CcameraDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CcameraDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CcameraDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CcameraDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


volatile BOOL m_bRun;
volatile BOOL m_bShowFlag;
void CcameraDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CWnd * pWnd = AfxGetApp()->GetMainWnd();
	if (m_bShowFlag)
	{
		m_bRun = TRUE;
	}
	else
	{
		hThread = CreateThread(NULL,
			0,
			(LPTHREAD_START_ROUTINE)ThreadFunc,
			this, //传入主窗口指针
			0,
			&ThreadID);
	}
}

void ThreadFunc(LPVOID lpParam)
{
	//指针转换
	CcameraDlg * pMainWindow;
	pMainWindow = (CcameraDlg *)lpParam; //强制转化为主窗口指针
	HTuple HWindowID;
	CRect Rect;
	CWnd * pWnd = pMainWindow->GetDlgItem(IDC_STATIC);
	HWindowID = (Hlong)pWnd->m_hWnd;
	pWnd->GetWindowRect(&Rect);

	//打开窗口，设置宽高
	OpenWindow(0, 0, Rect.Width(), Rect.Height(), HWindowID, "visible", "", &(pMainWindow->m_HWindowID));

	//显示相机捕捉的图像
	OpenFramegrabber("GigEVision2", 0, 0, 0, 0, 0, 0, "progressive", -1, "default",
		-1, "false", "default", "d47c443017eb_OMRONSENTECH_STCMBA503POE", 0, -1, &(pMainWindow->hv_AcqHandle));

	GrabImageStart(pMainWindow->hv_AcqHandle, -1);
	ClearWindow(pMainWindow->m_HWindowID);
	GrabImage(&(pMainWindow->ho_Image), pMainWindow->hv_AcqHandle);
	GetImagePointer1((pMainWindow->ho_Image), NULL, NULL, &(pMainWindow->m_ImageWidth), &(pMainWindow->m_ImageHeight));
	SetPart(pMainWindow->m_HWindowID, 0, 0, pMainWindow->m_ImageHeight - 1, pMainWindow->m_ImageWidth - 1);
	m_bShowFlag = TRUE;//设置运行状态
	m_bRun = TRUE;

	while (m_bShowFlag)
	{
		if (m_bRun)
		{
			GrabImageAsync(&(pMainWindow->ho_Image), pMainWindow->hv_AcqHandle, -1);
			DispObj(pMainWindow->ho_Image, pMainWindow->m_HWindowID);
			Sleep(50);
		}
	}
	ClearWindow(pMainWindow->m_HWindowID);
	CloseFramegrabber(pMainWindow->hv_AcqHandle);
	CloseWindow(pMainWindow->m_HWindowID);
	ExitThread(0);
}


void CcameraDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_bRun = FALSE;
	m_bShowFlag = FALSE;
}

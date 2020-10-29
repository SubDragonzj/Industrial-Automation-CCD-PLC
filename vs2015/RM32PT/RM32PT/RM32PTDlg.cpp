// RM32PTDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "RM32PT.h"
#include "RM32PTDlg.h"
#include "afxdialogex.h"

#include "PCI_DMC.h"
#include "PCI_DMC_Err.h"

#include <iostream>

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


// CRM32PTDlg 对话框



CRM32PTDlg::CRM32PTDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_RM32PT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRM32PTDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CRM32PTDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CRM32PTDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_CHECK1, &CRM32PTDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_BUTTON2, &CRM32PTDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CRM32PTDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CRM32PTDlg 消息处理程序

BOOL CRM32PTDlg::OnInitDialog()
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

void CRM32PTDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CRM32PTDlg::OnPaint()
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
HCURSOR CRM32PTDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



/* PCI-DMC */
const unsigned short cstMaxCardNum = 16;
/*Global*/
I16 gDMCExistCards = 0;
U16 gDMCCardNo, gpDMCCardNoList[cstMaxCardNum] = { 0 };
U16 gpDeviceInfo[cstMaxCardNum], gpNodeID[32] = { 0 }, gNodeNum;
U16 SlotID;
U32 gpSlaveTable[cstMaxCardNum][4];
U16 PortNoX = 0, PortNoY = 1;

void CRM32PTDlg::OnBnClickedButton1()//初始化按钮
{
	// TODO: 在此添加控件通知处理程序代码

	/* gDMCExistCards 变数会被填入 PC 上 PCI-DMC-01 的数量*/
	_DMC_01_open(&gDMCExistCards);

	unsigned short i, CardNo;
	for (i = 0; i<gDMCExistCards; i++)
	{
		/* 取得 PC 上第 i 张适配卡号，卡号即 Switch 指拨开关对应的数值*/
		_DMC_01_get_CardNo_seq(i, &CardNo);
		gpDMCCardNoList[i] = CardNo;
		gDMCCardNo = CardNo;

		_DMC_01_pci_initial(gDMCCardNo); // 初始化适配卡
		_DMC_01_initial_bus(gDMCCardNo); // 通讯协议初始化

		/*显示 Card No */
		SetDlgItemInt(IDC_STATIC2, CardNo);
	}
}


void CRM32PTDlg::OnBnClickedButton2()//搜索卡按钮
{
	// TODO: 在此添加控件通知处理程序代码

	unsigned int i = 0, lMask = 0x1;

	_DMC_01_start_ring(gDMCCardNo, 0);
	SlotID = _DMC_01_get_device_table(gDMCCardNo, &gpDeviceInfo[gDMCCardNo]);
	_DMC_01_get_node_table(gDMCCardNo, &gpSlaveTable[gDMCCardNo][0]);

	gNodeNum = 0;
	for (i = 0; i<32; i++)
	{
		if ((gpSlaveTable[gDMCCardNo][0] >> i) & lMask)
		{
			gpNodeID[gNodeNum] = (unsigned short)(i + 1);
			gNodeNum++;
		}
	}
	/*显示 Node ID */
	SetDlgItemInt(IDC_STATIC3, gNodeNum);
	/*显示 Slot ID */
	SetDlgItemInt(IDC_STATIC4, SlotID);
}


void CRM32PTDlg::OnBnClickedButton3()//断开按钮
{
	// TODO: 在此添加控件通知处理程序代码
	
	unsigned short i;

	for (i = 0; i<gDMCExistCards; i++) {
		_DMC_01_reset_card(gpDMCCardNoList[i]);
	}
	_DMC_01_close();

	CString str;
	str = "";
	SetDlgItemText(IDC_STATIC2, str);
	SetDlgItemText(IDC_STATIC3, str);
	SetDlgItemText(IDC_STATIC4, str);
}


BOOL m_bRun;
DWORD WINAPI ThreadFunc(PVOID pParam)
{
	m_bRun = TRUE;
	while (m_bRun)
	{
		U16 rt;
		U16 input_value[8] = { 0 };

		_DMC_01_get_rm_input_value(gDMCCardNo, gNodeNum, SlotID, PortNoX, &input_value[0]);
		rt = input_value[0];

		if (rt == 7) //左右启动
		{
			_DMC_01_set_rm_output_active(gDMCCardNo, gNodeNum, SlotID, 1);
			_DMC_01_set_rm_output_value(gDMCCardNo, gNodeNum, SlotID, PortNoY, 1);
		}
		if (rt == 0) //急停
		{
			_DMC_01_set_rm_output_active(gDMCCardNo, gNodeNum, SlotID, 1);
			_DMC_01_set_rm_output_value(gDMCCardNo, gNodeNum, SlotID, PortNoY, 0);
		}
	}
	ExitThread(0);
}


void CRM32PTDlg::OnBnClickedCheck1()//启动按钮
{
	// TODO: 在此添加控件通知处理程序代码

	int state = ((CButton *)GetDlgItem(IDC_CHECK1))->GetCheck(); //获取check按钮状态

	if (state == 1)
	{
		CreateThread(NULL, 0, ThreadFunc, NULL, 0, NULL);
	}
	if (state == 0)
	{
		m_bRun = FALSE;
		_DMC_01_set_rm_output_active(gDMCCardNo, gNodeNum, SlotID, 1);
		_DMC_01_set_rm_output_value(gDMCCardNo, gNodeNum, SlotID, PortNoY, 0);
	}
}
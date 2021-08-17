
// LangClickButtonDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "LangClickButton.h"
#include "LangClickButtonDlg.h"
#include "afxdialogex.h"

#include "Python.h"

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


// CLangClickButtonDlg 对话框



CLangClickButtonDlg::CLangClickButtonDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LANGCLICKBUTTON_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLangClickButtonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CLangClickButtonDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON3, &CLangClickButtonDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CLangClickButtonDlg 消息处理程序

BOOL CLangClickButtonDlg::OnInitDialog()
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

void CLangClickButtonDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLangClickButtonDlg::OnPaint()
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
HCURSOR CLangClickButtonDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




BOOL m_bRun;
int Clicked1 = 0;
DWORD WINAPI ThreadFunc(PVOID pParam)
{
	//调用Python代码
	Py_Initialize();
	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path.append('./py/')");
	PyObject* pModule = PyImport_ImportModule("run");
	PyObject* pFunc1 = PyObject_GetAttrString(pModule, "WriteBool");
	PyObject* pFunc2 = PyObject_GetAttrString(pModule, "ReadBool");

	CLangClickButtonDlg *pDlg = (CLangClickButtonDlg *)pParam;

	m_bRun = TRUE;
	while (m_bRun)
	{
		PyObject* pArgs = PyTuple_New(1);
		PyTuple_SetItem(pArgs, 0, Py_BuildValue("s", "V130.1"));
		PyObject* pReturn = PyEval_CallObject(pFunc2, pArgs);
		int nResult;
		PyArg_Parse(pReturn, "i", &nResult);
		if (nResult == 1)
		{
			CString str;
			str = "复位完成";
			pDlg->SetDlgItemText(IDC_STATIC3, str);

			m_bRun = FALSE;
			Clicked1 = 0;
			break;
		}
	}
	return 0;
}

BOOL CLangClickButtonDlg::PreTranslateMessage(MSG * pMsg)
{
	if (Clicked1 == 0)
	{
		if (pMsg->message == WM_LBUTTONDOWN)//拦截鼠标左键按下消息
		{
			//调用Python代码
			Py_Initialize();
			PyRun_SimpleString("import sys");
			PyRun_SimpleString("sys.path.append('./py/')");
			PyObject* pModule = PyImport_ImportModule("run");
			PyObject* pFunc1 = PyObject_GetAttrString(pModule, "WriteBool");
			PyObject* pFunc2 = PyObject_GetAttrString(pModule, "ReadBool");

			if (pMsg->hwnd == GetDlgItem(IDC_BUTTON1)->m_hWnd)//判断按下的位置是否为目标button
			{
				PyObject* pArgs1 = PyTuple_New(2);
				PyTuple_SetItem(pArgs1, 0, Py_BuildValue("s", "V100.0")); //Y轴+
				PyTuple_SetItem(pArgs1, 1, Py_BuildValue("i", 1));
				PyEval_CallObject(pFunc1, pArgs1);
				
				/*
				Py_Initialize();

				PyRun_SimpleString("import sys");
				PyRun_SimpleString("sys.path.append('./')");

				PyRun_SimpleString("import run");
				PyRun_SimpleString("run.WriteBool('V100.0', 1)");
				Py_Finalize();
				*/
			}
			if (pMsg->hwnd == GetDlgItem(IDC_BUTTON2)->m_hWnd)
			{
				PyObject* pArgs1 = PyTuple_New(2);
				PyTuple_SetItem(pArgs1, 0, Py_BuildValue("s", "V100.1")); //Y轴-
				PyTuple_SetItem(pArgs1, 1, Py_BuildValue("i", 1));
				PyEval_CallObject(pFunc1, pArgs1);
			}
			if (pMsg->hwnd == GetDlgItem(IDC_BUTTON3)->m_hWnd)
			{
				PyObject* pArgs1 = PyTuple_New(2);
				PyTuple_SetItem(pArgs1, 0, Py_BuildValue("s", "V130.0")); //复位
				PyTuple_SetItem(pArgs1, 1, Py_BuildValue("i", 1));
				PyEval_CallObject(pFunc1, pArgs1);

				CString str;
				str = "复位中...";
				SetDlgItemText(IDC_STATIC3, str);

				PyObject* pArgs2 = PyTuple_New(2);
				PyTuple_SetItem(pArgs2, 0, Py_BuildValue("s", "V130.1"));
				PyTuple_SetItem(pArgs2, 1, Py_BuildValue("i", 0));
				PyEval_CallObject(pFunc1, pArgs2);

				Clicked1++;
				if (Clicked1 == 1)
				{
					CreateThread(NULL, NULL, ThreadFunc, this, 0, NULL);
				}
			}

			if (pMsg->hwnd == GetDlgItem(IDC_BUTTON4)->m_hWnd)
			{
				PyObject* pArgs1 = PyTuple_New(2);
				PyTuple_SetItem(pArgs1, 0, Py_BuildValue("s", "V110.0")); //X轴+
				PyTuple_SetItem(pArgs1, 1, Py_BuildValue("i", 1));
				PyEval_CallObject(pFunc1, pArgs1);

				PyObject* pArgs2 = PyTuple_New(2);
				PyTuple_SetItem(pArgs2, 0, Py_BuildValue("s", "V120.0"));
				PyTuple_SetItem(pArgs2, 1, Py_BuildValue("i", 1));
				PyEval_CallObject(pFunc1, pArgs2);
			}
			if (pMsg->hwnd == GetDlgItem(IDC_BUTTON5)->m_hWnd)
			{
				PyObject* pArgs1 = PyTuple_New(2);
				PyTuple_SetItem(pArgs1, 0, Py_BuildValue("s", "V110.1")); //X轴-
				PyTuple_SetItem(pArgs1, 1, Py_BuildValue("i", 1));
				PyEval_CallObject(pFunc1, pArgs1);

				PyObject* pArgs2 = PyTuple_New(2);
				PyTuple_SetItem(pArgs2, 0, Py_BuildValue("s", "V120.1"));
				PyTuple_SetItem(pArgs2, 1, Py_BuildValue("i", 1));
				PyEval_CallObject(pFunc1, pArgs2);
			}
		}

		else if (pMsg->message == WM_LBUTTONUP) //鼠标左键抬起
		{
			//调用Python代码
			Py_Initialize();
			PyRun_SimpleString("import sys");
			PyRun_SimpleString("sys.path.append('./py/')");
			PyObject* pModule = PyImport_ImportModule("run");
			PyObject* pFunc1 = PyObject_GetAttrString(pModule, "WriteBool");
			PyObject* pFunc2 = PyObject_GetAttrString(pModule, "ReadBool");

			if (pMsg->hwnd == GetDlgItem(IDC_BUTTON1)->m_hWnd)
			{
				PyObject* pArgs1 = PyTuple_New(2);
				PyTuple_SetItem(pArgs1, 0, Py_BuildValue("s", "V100.0"));
				PyTuple_SetItem(pArgs1, 1, Py_BuildValue("i", 0));
				PyEval_CallObject(pFunc1, pArgs1);
			}
			if (pMsg->hwnd == GetDlgItem(IDC_BUTTON2)->m_hWnd)
			{
				PyObject* pArgs1 = PyTuple_New(2);
				PyTuple_SetItem(pArgs1, 0, Py_BuildValue("s", "V100.1"));
				PyTuple_SetItem(pArgs1, 1, Py_BuildValue("i", 0));
				PyEval_CallObject(pFunc1, pArgs1);
			}

			if (pMsg->hwnd == GetDlgItem(IDC_BUTTON4)->m_hWnd)
			{
				PyObject* pArgs1 = PyTuple_New(2);
				PyTuple_SetItem(pArgs1, 0, Py_BuildValue("s", "V110.0")); //X轴+
				PyTuple_SetItem(pArgs1, 1, Py_BuildValue("i", 0));
				PyEval_CallObject(pFunc1, pArgs1);

				PyObject* pArgs2 = PyTuple_New(2);
				PyTuple_SetItem(pArgs2, 0, Py_BuildValue("s", "V120.0"));
				PyTuple_SetItem(pArgs2, 1, Py_BuildValue("i", 0));
				PyEval_CallObject(pFunc1, pArgs2);
			}
			if (pMsg->hwnd == GetDlgItem(IDC_BUTTON5)->m_hWnd)
			{
				PyObject* pArgs1 = PyTuple_New(2);
				PyTuple_SetItem(pArgs1, 0, Py_BuildValue("s", "V110.1")); //X轴-
				PyTuple_SetItem(pArgs1, 1, Py_BuildValue("i", 0));
				PyEval_CallObject(pFunc1, pArgs1);

				PyObject* pArgs2 = PyTuple_New(2);
				PyTuple_SetItem(pArgs2, 0, Py_BuildValue("s", "V120.1"));
				PyTuple_SetItem(pArgs2, 1, Py_BuildValue("i", 0));
				PyEval_CallObject(pFunc1, pArgs2);
			}
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}


void CLangClickButtonDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
}

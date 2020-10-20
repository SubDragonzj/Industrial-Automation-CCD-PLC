
// cameraDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "camera.h"
#include "cameraDlg.h"
#include "afxdialogex.h"

#include "halconcpp.h"
using namespace HalconCpp;

#include <fstream>
#include <iostream>
#include <io.h>
#include "Python.h"
using namespace std;

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
	//声明halcon的变量
	HObject ho_Image;
	HTuple  hv_AcqHandle, hv_CameraParameters, hv_CameraPose;
	HTuple  hv_AmplitudeThreshold, hv_RoiWidthLen2, hv_LineRowStart_Measure_01_0;
	HTuple  hv_LineColumnStart_Measure_01_0, hv_LineRowEnd_Measure_01_0;
	HTuple  hv_LineColumnEnd_Measure_01_0, hv_TmpCtrl_Row, hv_TmpCtrl_Column;
	HTuple  hv_TmpCtrl_Dr, hv_TmpCtrl_Dc, hv_TmpCtrl_Phi, hv_TmpCtrl_Len1;
	HTuple  hv_TmpCtrl_Len2, hv_MsrHandle_Measure_01_0, hv_LineRowStart_Measure_01_1;
	HTuple  hv_LineColumnStart_Measure_01_1, hv_LineRowEnd_Measure_01_1;
	HTuple  hv_LineColumnEnd_Measure_01_1, hv_MsrHandle_Measure_01_1;
	HTuple  hv_LineRowStart_Measure_01_2, hv_LineColumnStart_Measure_01_2;
	HTuple  hv_LineRowEnd_Measure_01_2, hv_LineColumnEnd_Measure_01_2;
	HTuple  hv_MsrHandle_Measure_01_2, hv_LineRowStart_Measure_01_3;
	HTuple  hv_LineColumnStart_Measure_01_3, hv_LineRowEnd_Measure_01_3;
	HTuple  hv_LineColumnEnd_Measure_01_3, hv_MsrHandle_Measure_01_3;
	HTuple  hv_Row_Measure_01_0, hv_Column_Measure_01_0, hv_Amplitude_Measure_01_0;
	HTuple  hv_Distance_Measure_01_0, hv_Row_Measure_01_1, hv_Column_Measure_01_1;
	HTuple  hv_Amplitude_Measure_01_1, hv_Distance_Measure_01_1;
	HTuple  hv_Row_Measure_01_2, hv_Column_Measure_01_2, hv_Amplitude_Measure_01_2;
	HTuple  hv_Distance_Measure_01_2, hv_Row_Measure_01_3, hv_Column_Measure_01_3;
	HTuple  hv_Amplitude_Measure_01_3, hv_Distance_Measure_01_3;
	HTuple  hv_Column_World_Measure_01_0, hv_Row_World_Measure_01_0;
	HTuple  hv_TmpCtrl_Length, hv_TmpCtrl_RowFrom, hv_TmpCtrl_ColumnFrom;
	HTuple  hv_TmpCtrl_RowTo, hv_TmpCtrl_ColumnTo, hv_Distance_World_Measure_01_0;
	HTuple  hv_Column_World_Measure_01_1, hv_Row_World_Measure_01_1;
	HTuple  hv_Distance_World_Measure_01_1, hv_Column_World_Measure_01_2;
	HTuple  hv_Row_World_Measure_01_2, hv_Distance_World_Measure_01_2;
	HTuple  hv_Column_World_Measure_01_3, hv_Row_World_Measure_01_3;
	HTuple  hv_Distance_World_Measure_01_3;


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


	//Measure 01: Initialize calibration
	hv_CameraParameters.Clear();
	hv_CameraParameters[0] = "area_scan_division";
	hv_CameraParameters[1] = 1.37727;
	hv_CameraParameters[2] = 31.7944;
	hv_CameraParameters[3] = 2.1972e-006;
	hv_CameraParameters[4] = 2.2e-006;
	hv_CameraParameters[5] = 361.524;
	hv_CameraParameters[6] = -499.362;
	hv_CameraParameters[7] = 2592;
	hv_CameraParameters[8] = 1944;
	hv_CameraPose.Clear();
	hv_CameraPose[0] = 0.00989773;
	hv_CameraPose[1] = 0.0163173;
	hv_CameraPose[2] = 6.86213;
	hv_CameraPose[3] = 358.601;
	hv_CameraPose[4] = 3.04897;
	hv_CameraPose[5] = 359.151;
	hv_CameraPose[6] = 0;
	//Measure 01: Prepare measurement
	hv_AmplitudeThreshold = 40;
	hv_RoiWidthLen2 = 5;
	SetSystem("int_zooming", "true");
	//Measure 01: Coordinates for line Measure 01 [0]
	hv_LineRowStart_Measure_01_0 = 283.283;
	hv_LineColumnStart_Measure_01_0 = 918.513;
	hv_LineRowEnd_Measure_01_0 = 500.794;
	hv_LineColumnEnd_Measure_01_0 = 1144.36;
	//Measure 01: Convert coordinates to rectangle2 type
	hv_TmpCtrl_Row = 0.5*(hv_LineRowStart_Measure_01_0 + hv_LineRowEnd_Measure_01_0);
	hv_TmpCtrl_Column = 0.5*(hv_LineColumnStart_Measure_01_0 + hv_LineColumnEnd_Measure_01_0);
	hv_TmpCtrl_Dr = hv_LineRowStart_Measure_01_0 - hv_LineRowEnd_Measure_01_0;
	hv_TmpCtrl_Dc = hv_LineColumnEnd_Measure_01_0 - hv_LineColumnStart_Measure_01_0;
	hv_TmpCtrl_Phi = hv_TmpCtrl_Dr.TupleAtan2(hv_TmpCtrl_Dc);
	hv_TmpCtrl_Len1 = 0.5*(((hv_TmpCtrl_Dr*hv_TmpCtrl_Dr) + (hv_TmpCtrl_Dc*hv_TmpCtrl_Dc)).TupleSqrt());
	hv_TmpCtrl_Len2 = hv_RoiWidthLen2;
	//Measure 01: Create measure for line Measure 01 [0]
	//Measure 01: Attention: This assumes all images have the same size!
	GenMeasureRectangle2(hv_TmpCtrl_Row, hv_TmpCtrl_Column, hv_TmpCtrl_Phi, hv_TmpCtrl_Len1,
		hv_TmpCtrl_Len2, 2592, 1944, "nearest_neighbor", &hv_MsrHandle_Measure_01_0);
	//Measure 01: Coordinates for line Measure 01 [1]
	hv_LineRowStart_Measure_01_1 = 279.885;
	hv_LineColumnStart_Measure_01_1 = 2002.57;
	hv_LineRowEnd_Measure_01_1 = 283.283;
	hv_LineColumnEnd_Measure_01_1 = 2478.58;
	//Measure 01: Convert coordinates to rectangle2 type
	hv_TmpCtrl_Row = 0.5*(hv_LineRowStart_Measure_01_1 + hv_LineRowEnd_Measure_01_1);
	hv_TmpCtrl_Column = 0.5*(hv_LineColumnStart_Measure_01_1 + hv_LineColumnEnd_Measure_01_1);
	hv_TmpCtrl_Dr = hv_LineRowStart_Measure_01_1 - hv_LineRowEnd_Measure_01_1;
	hv_TmpCtrl_Dc = hv_LineColumnEnd_Measure_01_1 - hv_LineColumnStart_Measure_01_1;
	hv_TmpCtrl_Phi = hv_TmpCtrl_Dr.TupleAtan2(hv_TmpCtrl_Dc);
	hv_TmpCtrl_Len1 = 0.5*(((hv_TmpCtrl_Dr*hv_TmpCtrl_Dr) + (hv_TmpCtrl_Dc*hv_TmpCtrl_Dc)).TupleSqrt());
	hv_TmpCtrl_Len2 = hv_RoiWidthLen2;
	//Measure 01: Create measure for line Measure 01 [1]
	//Measure 01: Attention: This assumes all images have the same size!
	GenMeasureRectangle2(hv_TmpCtrl_Row, hv_TmpCtrl_Column, hv_TmpCtrl_Phi, hv_TmpCtrl_Len1,
		hv_TmpCtrl_Len2, 2592, 1944, "nearest_neighbor", &hv_MsrHandle_Measure_01_1);
	//Measure 01: Coordinates for line Measure 01 [2]
	hv_LineRowStart_Measure_01_2 = 1374.23;
	hv_LineColumnStart_Measure_01_2 = 939.361;
	hv_LineRowEnd_Measure_01_2 = 1567.95;
	hv_LineColumnEnd_Measure_01_2 = 1120.04;
	//Measure 01: Convert coordinates to rectangle2 type
	hv_TmpCtrl_Row = 0.5*(hv_LineRowStart_Measure_01_2 + hv_LineRowEnd_Measure_01_2);
	hv_TmpCtrl_Column = 0.5*(hv_LineColumnStart_Measure_01_2 + hv_LineColumnEnd_Measure_01_2);
	hv_TmpCtrl_Dr = hv_LineRowStart_Measure_01_2 - hv_LineRowEnd_Measure_01_2;
	hv_TmpCtrl_Dc = hv_LineColumnEnd_Measure_01_2 - hv_LineColumnStart_Measure_01_2;
	hv_TmpCtrl_Phi = hv_TmpCtrl_Dr.TupleAtan2(hv_TmpCtrl_Dc);
	hv_TmpCtrl_Len1 = 0.5*(((hv_TmpCtrl_Dr*hv_TmpCtrl_Dr) + (hv_TmpCtrl_Dc*hv_TmpCtrl_Dc)).TupleSqrt());
	hv_TmpCtrl_Len2 = hv_RoiWidthLen2;
	//Measure 01: Create measure for line Measure 01 [2]
	//Measure 01: Attention: This assumes all images have the same size!
	GenMeasureRectangle2(hv_TmpCtrl_Row, hv_TmpCtrl_Column, hv_TmpCtrl_Phi, hv_TmpCtrl_Len1,
		hv_TmpCtrl_Len2, 2592, 1944, "nearest_neighbor", &hv_MsrHandle_Measure_01_2);
	//Measure 01: Coordinates for line Measure 01 [3]
	hv_LineRowStart_Measure_01_3 = 1476.19;
	hv_LineColumnStart_Measure_01_3 = 1304.19;
	hv_LineRowEnd_Measure_01_3 = 1771.87;
	hv_LineColumnEnd_Measure_01_3 = 1314.61;
	//Measure 01: Convert coordinates to rectangle2 type
	hv_TmpCtrl_Row = 0.5*(hv_LineRowStart_Measure_01_3 + hv_LineRowEnd_Measure_01_3);
	hv_TmpCtrl_Column = 0.5*(hv_LineColumnStart_Measure_01_3 + hv_LineColumnEnd_Measure_01_3);
	hv_TmpCtrl_Dr = hv_LineRowStart_Measure_01_3 - hv_LineRowEnd_Measure_01_3;
	hv_TmpCtrl_Dc = hv_LineColumnEnd_Measure_01_3 - hv_LineColumnStart_Measure_01_3;
	hv_TmpCtrl_Phi = hv_TmpCtrl_Dr.TupleAtan2(hv_TmpCtrl_Dc);
	hv_TmpCtrl_Len1 = 0.5*(((hv_TmpCtrl_Dr*hv_TmpCtrl_Dr) + (hv_TmpCtrl_Dc*hv_TmpCtrl_Dc)).TupleSqrt());
	hv_TmpCtrl_Len2 = hv_RoiWidthLen2;
	//Measure 01: Create measure for line Measure 01 [3]
	//Measure 01: Attention: This assumes all images have the same size!
	GenMeasureRectangle2(hv_TmpCtrl_Row, hv_TmpCtrl_Column, hv_TmpCtrl_Phi, hv_TmpCtrl_Len1,
		hv_TmpCtrl_Len2, 2592, 1944, "nearest_neighbor", &hv_MsrHandle_Measure_01_3);


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


			//Measure 01: Execute measurements
			MeasurePos(pMainWindow->ho_Image, hv_MsrHandle_Measure_01_0, 1, hv_AmplitudeThreshold, "all",
				"all", &hv_Row_Measure_01_0, &hv_Column_Measure_01_0, &hv_Amplitude_Measure_01_0,
				&hv_Distance_Measure_01_0);
			MeasurePos(pMainWindow->ho_Image, hv_MsrHandle_Measure_01_1, 1, hv_AmplitudeThreshold, "all",
				"all", &hv_Row_Measure_01_1, &hv_Column_Measure_01_1, &hv_Amplitude_Measure_01_1,
				&hv_Distance_Measure_01_1);
			MeasurePos(pMainWindow->ho_Image, hv_MsrHandle_Measure_01_2, 1, hv_AmplitudeThreshold, "all",
				"all", &hv_Row_Measure_01_2, &hv_Column_Measure_01_2, &hv_Amplitude_Measure_01_2,
				&hv_Distance_Measure_01_2);
			MeasurePos(pMainWindow->ho_Image, hv_MsrHandle_Measure_01_3, 1, hv_AmplitudeThreshold, "all",
				"all", &hv_Row_Measure_01_3, &hv_Column_Measure_01_3, &hv_Amplitude_Measure_01_3,
				&hv_Distance_Measure_01_3);
			//Measure 01: Transform to world coordinates
			//Measure 01: Calibrate positions for Measure 01 [0]
			ImagePointsToWorldPlane(hv_CameraParameters, hv_CameraPose, hv_Row_Measure_01_0,
				hv_Column_Measure_01_0, 0.001, &hv_Column_World_Measure_01_0, &hv_Row_World_Measure_01_0);
			//Measure 01: Calibrate distances
			hv_TmpCtrl_Length = hv_Row_World_Measure_01_0.TupleLength();
			if (0 != (hv_TmpCtrl_Length>0))
			{
				TupleSelectRange(hv_Row_World_Measure_01_0, 0, hv_TmpCtrl_Length - 2, &hv_TmpCtrl_RowFrom);
				TupleSelectRange(hv_Column_World_Measure_01_0, 0, hv_TmpCtrl_Length - 2, &hv_TmpCtrl_ColumnFrom);
				TupleSelectRange(hv_Row_World_Measure_01_0, 1, hv_TmpCtrl_Length - 1, &hv_TmpCtrl_RowTo);
				TupleSelectRange(hv_Column_World_Measure_01_0, 1, hv_TmpCtrl_Length - 1, &hv_TmpCtrl_ColumnTo);
				DistancePp(hv_TmpCtrl_RowFrom, hv_TmpCtrl_ColumnFrom, hv_TmpCtrl_RowTo, hv_TmpCtrl_ColumnTo,
					&hv_Distance_World_Measure_01_0);
			}
			//Measure 01: Calibrate positions for Measure 01 [1]
			ImagePointsToWorldPlane(hv_CameraParameters, hv_CameraPose, hv_Row_Measure_01_1,
				hv_Column_Measure_01_1, 0.001, &hv_Column_World_Measure_01_1, &hv_Row_World_Measure_01_1);
			//Measure 01: Calibrate distances
			hv_TmpCtrl_Length = hv_Row_World_Measure_01_1.TupleLength();
			if (0 != (hv_TmpCtrl_Length>0))
			{
				TupleSelectRange(hv_Row_World_Measure_01_1, 0, hv_TmpCtrl_Length - 2, &hv_TmpCtrl_RowFrom);
				TupleSelectRange(hv_Column_World_Measure_01_1, 0, hv_TmpCtrl_Length - 2, &hv_TmpCtrl_ColumnFrom);
				TupleSelectRange(hv_Row_World_Measure_01_1, 1, hv_TmpCtrl_Length - 1, &hv_TmpCtrl_RowTo);
				TupleSelectRange(hv_Column_World_Measure_01_1, 1, hv_TmpCtrl_Length - 1, &hv_TmpCtrl_ColumnTo);
				DistancePp(hv_TmpCtrl_RowFrom, hv_TmpCtrl_ColumnFrom, hv_TmpCtrl_RowTo, hv_TmpCtrl_ColumnTo,
					&hv_Distance_World_Measure_01_1);
			}
			//Measure 01: Calibrate positions for Measure 01 [2]
			ImagePointsToWorldPlane(hv_CameraParameters, hv_CameraPose, hv_Row_Measure_01_2,
				hv_Column_Measure_01_2, 0.001, &hv_Column_World_Measure_01_2, &hv_Row_World_Measure_01_2);
			//Measure 01: Calibrate distances
			hv_TmpCtrl_Length = hv_Row_World_Measure_01_2.TupleLength();
			if (0 != (hv_TmpCtrl_Length>0))
			{
				TupleSelectRange(hv_Row_World_Measure_01_2, 0, hv_TmpCtrl_Length - 2, &hv_TmpCtrl_RowFrom);
				TupleSelectRange(hv_Column_World_Measure_01_2, 0, hv_TmpCtrl_Length - 2, &hv_TmpCtrl_ColumnFrom);
				TupleSelectRange(hv_Row_World_Measure_01_2, 1, hv_TmpCtrl_Length - 1, &hv_TmpCtrl_RowTo);
				TupleSelectRange(hv_Column_World_Measure_01_2, 1, hv_TmpCtrl_Length - 1, &hv_TmpCtrl_ColumnTo);
				DistancePp(hv_TmpCtrl_RowFrom, hv_TmpCtrl_ColumnFrom, hv_TmpCtrl_RowTo, hv_TmpCtrl_ColumnTo,
					&hv_Distance_World_Measure_01_2);
			}
			//Measure 01: Calibrate positions for Measure 01 [3]
			ImagePointsToWorldPlane(hv_CameraParameters, hv_CameraPose, hv_Row_Measure_01_3,
				hv_Column_Measure_01_3, 0.001, &hv_Column_World_Measure_01_3, &hv_Row_World_Measure_01_3);
			//Measure 01: Calibrate distances
			hv_TmpCtrl_Length = hv_Row_World_Measure_01_3.TupleLength();
			if (0 != (hv_TmpCtrl_Length>0))
			{
				TupleSelectRange(hv_Row_World_Measure_01_3, 0, hv_TmpCtrl_Length - 2, &hv_TmpCtrl_RowFrom);
				TupleSelectRange(hv_Column_World_Measure_01_3, 0, hv_TmpCtrl_Length - 2, &hv_TmpCtrl_ColumnFrom);
				TupleSelectRange(hv_Row_World_Measure_01_3, 1, hv_TmpCtrl_Length - 1, &hv_TmpCtrl_RowTo);
				TupleSelectRange(hv_Column_World_Measure_01_3, 1, hv_TmpCtrl_Length - 1, &hv_TmpCtrl_ColumnTo);
				DistancePp(hv_TmpCtrl_RowFrom, hv_TmpCtrl_ColumnFrom, hv_TmpCtrl_RowTo, hv_TmpCtrl_ColumnTo,
					&hv_Distance_World_Measure_01_3);
			}


			if (hv_Distance_World_Measure_01_0 > 0 &
				hv_Distance_World_Measure_01_1 > 0 &
				hv_Distance_World_Measure_01_2 > 0 &
				hv_Distance_World_Measure_01_3 > 0)
			{
				//在静态文本框中显示测量数据
				CString str0, str1, str2, str3;
				str0.Format(_T("%.4f"), double(hv_Distance_World_Measure_01_0));
				str1.Format(_T("%.4f"), double(hv_Distance_World_Measure_01_1));
				str2.Format(_T("%.4f"), double(hv_Distance_World_Measure_01_2));
				str3.Format(_T("%.4f"), double(hv_Distance_World_Measure_01_3));
				pMainWindow->SetDlgItemText(IDC_STATIC2, str0);
				pMainWindow->SetDlgItemText(IDC_STATIC3, str1);
				pMainWindow->SetDlgItemText(IDC_STATIC4, str2);
				pMainWindow->SetDlgItemText(IDC_STATIC5, str3);


				//调用Python代码
				Py_Initialize();
				PyRun_SimpleString("import sys");
				PyRun_SimpleString("sys.path.append('./')");

				PyObject* pModule = PyImport_ImportModule("run");
				PyObject* pFunc1 = PyObject_GetAttrString(pModule, "ReadBool");
				PyObject* pFunc2 = PyObject_GetAttrString(pModule, "WriteInt32");
				PyObject* pFunc3 = PyObject_GetAttrString(pModule, "WriteBool");

				PyObject* pArgs = PyTuple_New(1);
				PyTuple_SetItem(pArgs, 0, Py_BuildValue("s", "M30.0"));
				PyObject* pReturn = PyEval_CallObject(pFunc1, pArgs);
				int nResult;
				PyArg_Parse(pReturn, "i", &nResult);
				if (nResult == 1)
				{
					int pause1, pause2;
					double distance0 = double(hv_Distance_World_Measure_01_0);
					double distance1 = double(hv_Distance_World_Measure_01_1);
					double distance2 = double(hv_Distance_World_Measure_01_2);
					double distance3 = double(hv_Distance_World_Measure_01_3);

					pause1 = (int)(((distance0 - distance1) / 2) * 1000);
					pause2 = (int)(((distance2 - distance3) / 2) * 1000);

					PyObject* pArgs1 = PyTuple_New(2);
					PyObject* pArgs2 = PyTuple_New(2);
					PyTuple_SetItem(pArgs1, 0, Py_BuildValue("s", "V510"));
					PyTuple_SetItem(pArgs1, 1, Py_BuildValue("i", pause1));
					PyTuple_SetItem(pArgs2, 0, Py_BuildValue("s", "V520"));
					PyTuple_SetItem(pArgs2, 1, Py_BuildValue("i", pause2));
					PyEval_CallObject(pFunc2, pArgs1);
					PyEval_CallObject(pFunc2, pArgs2);

					PyObject* pArgs3 = PyTuple_New(2);
					PyTuple_SetItem(pArgs3, 0, Py_BuildValue("s", "M30.0"));
					PyTuple_SetItem(pArgs3, 1, Py_BuildValue("i", 0));
					PyEval_CallObject(pFunc3, pArgs3);
				}
				Py_Finalize();
			}
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


// cameraDlg.h : 头文件
//

#pragma once
#include "halconcpp.h"
using namespace HalconCpp;


// CcameraDlg 对话框
class CcameraDlg : public CDialogEx
{
// 构造
public:
	CcameraDlg(CWnd* pParent = NULL);	// 标准构造函数

	HObject  ho_Image;
	HTuple  hv_AcqHandle;
	HTuple m_HWindowID;
	HTuple m_FGHandle, m_ImageWidth, m_ImageHeight;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CAMERA_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

	HANDLE hThread;
	DWORD ThreadID;


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
	afx_msg void OnBnClickedButton2();
};

void ThreadFunc(LPVOID lpParam);

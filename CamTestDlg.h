// CamTestDlg.h : header file
//
//{{AFX_INCLUDES()

//}}AFX_INCLUDES

#if !defined(AFX_CAMTESTDLG_H__03CA8BD6_1E3D_4D4C_88D8_7DCDAF7A0B0E__INCLUDED_)
#define AFX_CAMTESTDLG_H__03CA8BD6_1E3D_4D4C_88D8_7DCDAF7A0B0E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SerialPort.h"  //这是后来我自己添加的
#include "State.h"	// 自己添加的
//#include "State.h"	// 自己添加的
#include "MyAboutDlg.h"	// 



//#define COLUMN 80  
//#define ROW 40
//#define PIXEL_SUM COLUMN*ROW
/////////////////////////////////////////////////////////////////////////////
// CCamTestDlg dialog

class CCamTestDlg : public CDialog
{
// Construction
public:
	CString machine_code;
	BOOL md5check();
	BOOL md5_right;
//	void drawbianmaqi(int bianmaqi);    同一窗口绘图功能，取消

	CSerialPort m_SerialPort; //CSerailPort类对象

	CCamTestDlg(CWnd* pParent = NULL);	// standard constructor
	
// Dialog Data
	//{{AFX_DATA(CCamTestDlg)
	enum { IDD = IDD_CAMTEST_DIALOG };
	UINT	m_yuzhi;
	UINT	m_long;
	UINT	m_width;
	UINT	m_bianmaqi;
	UINT	m_duoji;
	UINT	m_dianji;
	UINT	m_z1;
	UINT	m_z2;
	UINT	m_z3;
	UINT	m_z4;
	UINT	m_send_dianji;
	UINT	m_send_duoji;
	UINT	m_send_z1;
	UINT	m_send_z2;
	UINT	m_send_z3;
	UINT	m_send_z4;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCamTestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void shishicanshu();
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCamTestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg LONG OnComm(WPARAM ch, LPARAM port);//自己加的
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnButton2();
	afx_msg void OnButton1();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	afx_msg void OnNew();
	afx_msg void OnButtonSend();
	afx_msg void OnAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	CState *pDlg;
	CMyAboutDlg *pMyAboutDlg;
private:
	void draw();
	void FillBitmapInfo();
	struct
	{
		BITMAPINFOHEADER bmiHeader;
		RGBQUAD quad[256];
	}m_BitmapInfo;
	int init_Comm(int port,CString BaudRate);
    BYTE image_data[320*320];
	BYTE image_data2[320*320];
	BYTE canshu_data[10];

	BOOL imageshow;		//图像复选判断
	BOOL canshushow;   //实时参数复选判断
	BOOL rerecive;
	BOOL flag_serial;


};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAMTESTDLG_H__03CA8BD6_1E3D_4D4C_88D8_7DCDAF7A0B0E__INCLUDED_)

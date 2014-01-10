// MyAboutDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CamTest.h"
#include "MyAboutDlg.h"
#include "CamTestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyAboutDlg dialog


CMyAboutDlg::CMyAboutDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyAboutDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyAboutDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMyAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyAboutDlg)
	DDX_Control(pDX, IDC_EDIT1, m_code);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMyAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CMyAboutDlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyAboutDlg message handlers

void CMyAboutDlg::OnButton1() 
{
ShellExecute(NULL, NULL, _T("http://xiaohaizhu.taobao.com"), NULL,NULL, SW_SHOWNORMAL);  
}

BOOL CMyAboutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_code.SetWindowText("ÄúµÄ»úÆ÷Âë:"+((CCamTestDlg*)GetParent())->machine_code);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

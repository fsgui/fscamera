// State.cpp : implementation file
//

#include "stdafx.h"
#include "CamTest.h"
#include "State.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CState dialog


CState::CState(CWnd* pParent /*=NULL*/)
	: CDialog(CState::IDD, pParent)
{
	//{{AFX_DATA_INIT(CState)
	//}}AFX_DATA_INIT
}


void CState::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CState)
	DDX_Control(pDX, IDC_3, m_3);
	DDX_Control(pDX, IDC_2, m_2);
	DDX_Control(pDX, IDC_1, m_1);
	DDX_Control(pDX, IDC_X, m_dx);
	DDX_Control(pDX, IDC_DIANJIMAX, m_dianjimax);
	DDX_Control(pDX, IDC_DUOJIMAX, m_duojimax);
	DDX_Control(pDX, IDC_DUOJIMIN, m_duojimin);
	DDX_Control(pDX, IDC_OUMUMAX, m_oumumax);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CState, CDialog)
	//{{AFX_MSG_MAP(CState)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON1, OnButtonChange)
	ON_BN_CLICKED(IDC_REBEGIN, OnRebegin)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	ON_BN_CLICKED(IDC_CLOSE, OnClose)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CState message handlers

/*void CState::DrawCtrl()
{
		CWnd   *pWnd=GetDlgItem(IDC_SpeedPWM); 
        CDC   *pControlDC=pWnd-> GetDC(); 
        pWnd-> Invalidate(); 
        pWnd-> UpdateWindow(); 
        pControlDC-> SelectStockObject(BLACK_BRUSH); 
        pControlDC-> Rectangle(0,0,10,10); 
        pWnd-> ReleaseDC(pControlDC); 
}*/


BOOL CState::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_x=0;
	m_y=5100;
	m_x_oumu=0;
	m_y_oumu=0;
	m_x_dianjipwm=0;
	m_y_dianjipwm=0;
	m_drawflag=1;
	//后来添加
	n_dx=5;
	n_duojimin=0;
	n_duojimax=65536;
	n_dianjimax=65536;
	n_oumumax=65536;
	//设置文本框初值
	m_dx.SetWindowText("5");
	m_duojimin.SetWindowText("0");
	m_duojimax.SetWindowText("65536");
	m_dianjimax.SetWindowText("65536");
	m_oumumax.SetWindowText("65536");

	
	return TRUE; 
}

void CState::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	// Do not call CDialog::OnPaint() for painting messages
}

void CState::OnRebegin() 
{
	// TODO: Add your control notification handler code here
	Invalidate();
	m_x=0;
	m_x_oumu=0;
	m_x_dianjipwm=0;
	
//drawduoji(125);

}

void CState::drawduoji(int duoji)
{
	float y;
	if(m_drawflag==1)
	{
	CWnd *pWnd=GetDlgItem(IDC_STATIC_DUOJI);
	CDC *pDC=pWnd->GetDC();
	
	CRect rc;
	pWnd->GetClientRect(rc);//设置区域
	
	
	CPen pen(0,2,RGB(255,0,0));
	CPen *oldpen=pDC->SelectObject(&pen);//为dc选取画笔
	
	pDC->MoveTo(m_x,m_y);
	//转换pwm值
	y=(n_duojimax-n_duojimin)/float(rc.Height());
	y=(duoji-n_duojimin)/y;

	m_y=int(y);
	m_x=m_x+n_dx;
	if(m_x>rc.Width())
	{	
		m_x=0;
//		m_y=0;
		Invalidate();
		pDC->MoveTo(m_x,m_y);
	}
	
	pDC->LineTo(m_x,m_y);
	
	pDC->SelectObject(oldpen);
	pWnd->ReleaseDC(pDC);
	}
}

void CState::OnStop() 
{
	// TODO: Add your control notification handler code here
	if(m_drawflag==1)
	{m_drawflag=0;
	GetDlgItem(IDC_STOP)-> SetWindowText( "心电图");}
	else
	{	m_drawflag=1;
	GetDlgItem(IDC_STOP)-> SetWindowText( "停止");}
}

void CState::drawdianjipwm(int dianjipwm)
{
	float y;
	if(m_drawflag==1)
	{
	CWnd *pWnd=GetDlgItem(IDC_STATIC_DIANJIPWM);
	CDC *pDC=pWnd->GetDC();
	
	CRect rc;
	pWnd->GetClientRect(rc);//设置区域
	
	
	CPen pen(0,2,RGB(255,0,0));
	CPen *oldpen=pDC->SelectObject(&pen);//为dc选取画笔
	
	pDC->MoveTo(m_x_dianjipwm,m_y_dianjipwm);
	//转换pwm值
	y=n_dianjimax/float(rc.Height());
	y=(dianjipwm)/y;

	m_y_dianjipwm=int(y);
	m_x_dianjipwm=m_x_dianjipwm+n_dx;
	if(m_x_dianjipwm>rc.Width())
	{	
		m_x_dianjipwm=0;
//		m_y_dianjipwm=0;
		Invalidate();
		pDC->MoveTo(m_x_dianjipwm,m_y_dianjipwm);
	}
	
	pDC->LineTo(m_x_dianjipwm,m_y_dianjipwm);
	
	pDC->SelectObject(oldpen);
	pWnd->ReleaseDC(pDC);
	}
}

void CState::drawoumu(int oumu)
{
float y;
	if(m_drawflag==1)
	{
	CWnd *pWnd=GetDlgItem(IDC_STATIC_OUMU);
	CDC *pDC=pWnd->GetDC();
	
	CRect rc;
	pWnd->GetClientRect(rc);//设置区域
	
	
	CPen pen(0,2,RGB(255,0,0));
	CPen *oldpen=pDC->SelectObject(&pen);//为dc选取画笔
	
	pDC->MoveTo(m_x_oumu,m_y_oumu);
	y=n_oumumax/float(rc.Height());
	y=(oumu)/y;
	m_y_oumu=int(y);
	m_x_oumu=m_x_oumu+n_dx;
	if(m_x_oumu>rc.Width())
	{	
		m_x_oumu=0;
//		m_y_oumu=0;
		Invalidate();
		pDC->MoveTo(m_x_oumu,m_y_oumu);
	}
	
	pDC->LineTo(m_x_oumu,m_y_oumu);
	
	pDC->SelectObject(oldpen);
	pWnd->ReleaseDC(pDC);
	}
}

void CState::OnButtonChange() 
{	
	CString s_dx,s_duojimin,s_duojimax,s_dianjimax,s_oumumax;
	m_dx.GetWindowText(s_dx); 
	m_duojimin.GetWindowText(s_duojimin); 
	m_duojimax.GetWindowText(s_duojimax); 
	m_dianjimax.GetWindowText(s_dianjimax);
	m_oumumax.GetWindowText(s_oumumax);

	n_dx=atoi(s_dx);
	n_duojimin=atoi(s_duojimin);   //将字符串转换为数字
	n_duojimax=atoi(s_duojimax);
	n_dianjimax=atoi(s_dianjimax);
	n_oumumax=atoi(s_oumumax);
}


void CState::OnClose() 
{
	SendMessage(WM_CLOSE);
}

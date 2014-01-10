#if !defined(AFX_STATE_H__A9D62F2F_A1D4_4F65_9EDE_749DE4BA2FBA__INCLUDED_)
#define AFX_STATE_H__A9D62F2F_A1D4_4F65_9EDE_749DE4BA2FBA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// State.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CState dialog

class CState : public CDialog
{
// Construction
public:
	int m_y_dianjipwm;
	int m_x_dianjipwm;
	int m_y_oumu;
	int m_x_oumu;
	void drawoumu(int oumu);
	void drawdianjipwm(int dianjipwm);
	BOOL m_drawflag;
	void drawduoji(int duoji);
	int m_y;
	int m_x;
	int m_test;
	int n_dx;
	int n_duojimin;
	int n_duojimax;
	int n_dianjimax;
	int n_oumumax;


	CState(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CState)
	enum { IDD = IDD_DIALOG1 };

	CEdit	m_3;
	CEdit	m_2;
	CEdit	m_1;
	CEdit	m_dx;
	CEdit	m_dianjimax;
	CEdit	m_duojimax;
	CEdit	m_duojimin;
	CEdit	m_oumumax;

		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CState)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CState)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnButtonChange();
	afx_msg void OnRebegin();
	afx_msg void OnStop();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATE_H__A9D62F2F_A1D4_4F65_9EDE_749DE4BA2FBA__INCLUDED_)

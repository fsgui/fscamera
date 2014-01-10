// CamTestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CamTest.h"
#include "CamTestDlg.h"
#include "State.h"
#include "md5.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCamTestDlg dialog

CCamTestDlg::CCamTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCamTestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCamTestDlg)
	m_yuzhi = 128;
	m_long = 20;
	m_width = 20;
	m_bianmaqi = 0;
	m_duoji = 0;
	m_dianji = 0;
	m_z1 = 0;
	m_z2 = 0;
	m_z3 = 0;
	m_z4 = 0;
	m_send_dianji = 0;
	m_send_duoji = 0;
	m_send_z1 = 0;
	m_send_z2 = 0;
	m_send_z3 = 0;
	m_send_z4 = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCamTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCamTestDlg)
	DDX_Text(pDX, IDC_EDIT_YUZHI, m_yuzhi);
	DDX_Text(pDX, IDC_EDIT_LONG, m_long);
	DDX_Text(pDX, IDC_EDIT_WIDTH, m_width);
	DDX_Text(pDX, IDC_EDIT_BIANMAQI, m_bianmaqi);
	DDX_Text(pDX, IDC_EDIT_DUOJI, m_duoji);
	DDX_Text(pDX, IDC_EDIT_DIANJI, m_dianji);
	DDX_Text(pDX, IDC_EDIT_Z1, m_z1);
	DDX_Text(pDX, IDC_EDIT_Z2, m_z2);
	DDX_Text(pDX, IDC_EDIT_Z3, m_z3);
	DDX_Text(pDX, IDC_EDIT_Z4, m_z4);
	DDX_Text(pDX, IDC_SEND_DIANJI, m_send_dianji);
	DDX_Text(pDX, IDC_SEND_DUOJI, m_send_duoji);
	DDX_Text(pDX, IDC_SEND_Z1, m_send_z1);
	DDX_Text(pDX, IDC_SEND_Z2, m_send_z2);
	DDX_Text(pDX, IDC_SEND_Z3, m_send_z3);
	DDX_Text(pDX, IDC_SEND_Z4, m_send_z4);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCamTestDlg, CDialog)
	//{{AFX_MSG_MAP(CCamTestDlg)
	ON_WM_SYSCOMMAND()
	ON_MESSAGE(WM_COMM_RXCHAR, OnComm)  //这是我自己加的
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_NEW, OnNew)
	ON_BN_CLICKED(IDC_BUTTON_SEND, OnButtonSend)
	ON_BN_CLICKED(IDC_ABOUT, OnAbout)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCamTestDlg message handlers

BOOL CCamTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	CComboBox *combo;
	combo=(CComboBox *)GetDlgItem(IDC_COM);
	combo->AddString("COM1");
	combo->AddString("COM2");
	combo->AddString("COM3");
	combo->AddString("COM4");
	combo->AddString("COM5");
	combo->AddString("COM6");
	combo->AddString("COM7");
	combo->AddString("COM8");
	combo->AddString("COM9");
	combo->SetCurSel(0);

	combo=(CComboBox *)GetDlgItem(IDC_BAUD);
	combo->AddString("9600");
	combo->AddString("19200");
	combo->AddString("38400");
	combo->AddString("43000");
	combo->AddString("56000");
	combo->AddString("57600");
	combo->AddString("115200");
	combo->SetCurSel(0);
	((CButton *)GetDlgItem(IDC_CHECK_IMAGE))->SetCheck(TRUE);
	FillBitmapInfo();


	//后来添加
	flag_serial=0;
	pDlg=new CState();
	pDlg->Create(IDD_DIALOG1,this);

	//md5检测
	md5_right=1;//关闭加密
	// md5_right=md5check();//加密
	if(md5_right==0)
	AfxGetMainWnd()-> SetWindowText( "FS智能车调试工具（摄像头试用版）——http://xiaohaizhu.taobao.com"); 



	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCamTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCamTestDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCamTestDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCamTestDlg::OnOK() 
{
	// TODO: Add extra validation here
	
//	CDialog::OnOK();
}


void CCamTestDlg::OnButton2() 
{
	// 获取波特率
	CComboBox *comboBox=(CComboBox *)GetDlgItem(IDC_BAUD);
	CString BaudRate;
	comboBox->GetWindowText(BaudRate);
	int nBaudRate=atoi(BaudRate);

	//获取端口号
	comboBox=(CComboBox *)GetDlgItem(IDC_COM);
	int port=comboBox->GetCurSel()+1;
	
	//判断复选 
	UpdateData(TRUE); //读入编辑框中的数据？
	FillBitmapInfo();//位图头部要改
	imageshow=IsDlgButtonChecked(IDC_CHECK_IMAGE);
	canshushow=IsDlgButtonChecked(IDC_CHECK_CANSHU);

//控件初始化	init_Comm(port,BaudRate);

	if(m_SerialPort.InitPort(this, port, nBaudRate,'N',8,1,EV_RXFLAG | EV_RXCHAR,512))
	{
		m_SerialPort.StartMonitoring();
		flag_serial=1;
	GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);//打开串口按钮失效
	GetDlgItem(IDC_BUTTON3)->EnableWindow(1);

	GetDlgItem(IDC_CHECK_CANSHU)->EnableWindow(FALSE);//复选框失效
	GetDlgItem(IDC_CHECK_IMAGE)->EnableWindow(FALSE);//复选框失效
	}
	else
	{
		AfxMessageBox("不爽，没有发现此串口或被占用");
	}


	

}



LONG CCamTestDlg::OnComm(WPARAM ch, LPARAM port)
{

	static CString str="";
	static unsigned char count=0;
	static unsigned int i=0;

	CString temp;
	CEdit *edit;
	edit=(CEdit *)GetDlgItem(IDC_EDIT1);



	if (rerecive==1)//如果点过关闭按钮，此标记变量置1.所有一切重新开始。  电机打开串口，变量又置0，if不执行
	{str="";count=0;i=0;rerecive=0;}
	
//只图像
	if((imageshow==1)&&(canshushow==0))
	{


			if ((ch==0xaa) && (count==0)) {count++;}
			if ((ch==0xbb) && (count==1)) {count++;}
			if ((ch==0xcc) && (count==2)) {count++;edit->SetWindowText("起始验证字符正确，开始接受图像");return 0;}  //分隔符 0xAA, 0xBB, 0xCC
			if (count==3)
			{
			 //图像采集NOT完成
				

				if (i<m_long*m_width)
				{   
					image_data[i]=ch;
					if(image_data[i]<m_yuzhi)
						image_data2[i]=0;
					else image_data2[i]=255;
					temp=str;
					str.Format(" %02X%s",ch,temp);
					str=str.Mid(0,380);
					i++;
					//显示传送中的数据
					edit->SetWindowText("正在接收图像"+str);//显示16进制数据               
				} 
				if(i==m_long*m_width)   //接受完图像
				{
   				   draw();//显示原始图像 显示二值化图像
				   str="";//字符串清零
				   i=0;   //计数清零
				   count=0;  //标志清零
				}
			}
	}

//只参数
		if((imageshow==0)&&(canshushow==1))
		{
		

			if ((ch==0xaa) && (count==0))	{count++;}
			if ((ch==0xbb) && (count==1)) {count++;}
			if ((ch==0xcc) && (count==2)) {count++;edit->SetWindowText("起始验证字符正确，开始接受实时参数");return 0;}  //分隔符 0xAA, 0xBB, 0xCC
			if (count==3)
			{
			 //
				
				if (i<10){   
					canshu_data[i]=ch;
					temp=str;
					str.Format(" %02X%s",ch,temp);
					str=str.Mid(0,380);
					i++;
					//显示传送中的数据
					edit->SetWindowText("正在接收实时参数"+str);//显示16进制数据  
				
				} 
				if (i==10)   //接受完参数
				{
   			        
					shishicanshu();
				    str="";//字符串清零
				    i=0;   //计数清零
				    count=0;  //标志清零
				}
	
			}

		}

		
		


//图像+参数
		if((imageshow==1)&&(canshushow==1))
		{
		

			if ((ch==0xaa) && (count==0))	{count++;}
			if ((ch==0xbb) && (count==1)) {count++;}
			if ((ch==0xcc) && (count==2)) {count++;edit->SetWindowText("起始验证字符正确，开始接受图像和实时参数");return 0;}  //分隔符 0xAA, 0xBB, 0xCC
			if (count==3)
			{
			 //图像采集NOT完成
				
				if (i<(m_long*m_width)){   
					image_data[i]=ch;
					temp=str;
					str.Format(" %02X%s",ch,temp);
					str=str.Mid(0,380);
					i++;
					//显示传送中的数据
					edit->SetWindowText("正在接收图像和参数"+str);//显示16进制数据               
				}
				else if(i>=(m_long*m_width)&&i<=(m_long*m_width+9))
				{
					canshu_data[i-m_long*m_width]=ch;
					temp=str;
					str.Format(" %02X%s",ch,temp);
					str=str.Mid(0,380);
					i++;
					//显示传送中的数据
					edit->SetWindowText("正在接收图像和参数"+str);//显示16进制数据    
				}
				if(i==m_long*m_width+10)   //接受完数据
				{
				   shishicanshu();
   				   draw();//显示原始图像 显示实时参数
				   str="";//字符串清零
				   i=0;   //计数清零
				   count=0;  //标志清零
				}
	
			}

		}

return 0;

}

void CCamTestDlg::FillBitmapInfo()	
{
	m_BitmapInfo.bmiHeader.biBitCount=8;
	m_BitmapInfo.bmiHeader.biClrImportant=m_BitmapInfo.bmiHeader.biClrUsed=0;
	m_BitmapInfo.bmiHeader.biCompression=0;
	m_BitmapInfo.bmiHeader.biHeight=m_width;
	m_BitmapInfo.bmiHeader.biPlanes=1;
	m_BitmapInfo.bmiHeader.biSize=sizeof(BITMAPINFOHEADER);
	m_BitmapInfo.bmiHeader.biSizeImage=0;
	m_BitmapInfo.bmiHeader.biWidth=m_long;
	m_BitmapInfo.bmiHeader.biXPelsPerMeter=m_BitmapInfo.bmiHeader.biYPelsPerMeter=0;	
	for   (int i=0;i <256;i++)
	{
		m_BitmapInfo.quad[i].rgbRed=BYTE(i);
		m_BitmapInfo.quad[i].rgbBlue=BYTE(i);
		m_BitmapInfo.quad[i].rgbGreen=BYTE(i);
		m_BitmapInfo.quad[i].rgbReserved=BYTE(0);
	} 
}

void CCamTestDlg::draw()
{
	CDC *pDC;
	pDC=GetDlgItem(IDC_CAM)->GetDC();
	StretchDIBits(pDC->GetSafeHdc(),0,0,320,320,0,0,m_long,m_width,image_data,(PBITMAPINFO) &m_BitmapInfo,DIB_RGB_COLORS,SRCCOPY);
if(md5_right==1)
{
	//绘二值图
	pDC=GetDlgItem(IDC_BINARY)->GetDC();
	StretchDIBits(pDC->GetSafeHdc(),0,0,320,320,0,0,m_long,m_width,image_data2,(PBITMAPINFO) &m_BitmapInfo,DIB_RGB_COLORS,SRCCOPY);
}
	
}

void CCamTestDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	for (unsigned int i=0;i<m_long*m_width;i++)
	{
		image_data[i]=0;
	}
	draw();
}

void CCamTestDlg::OnButton3() 
{
	m_SerialPort.ClosePort();//关闭串口
	flag_serial=0;
	rerecive=1;
	GetDlgItem(IDC_BUTTON2)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(0);	

		GetDlgItem(IDC_CHECK_CANSHU)->EnableWindow(1);//复选框失效
	GetDlgItem(IDC_CHECK_IMAGE)->EnableWindow(1);//复选框失效
	
}



void CCamTestDlg::OnButton4()    
{
	 PostQuitMessage(0);
	/* //保存图像代码
	CString FileName;
	CFileDialog dlg(FALSE,_T("bmp"),_T("Temp.bmp"),OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,_T("Bitmap Files (*.bmp)|*.bmp|All Files (*.*)|*.*||"),this);
	if (dlg.DoModal()==IDOK)
	{
		FileName=dlg.GetPathName();
		HANDLE hf=CreateFile(FileName,GENERIC_WRITE,FILE_SHARE_READ,NULL,CREATE_ALWAYS,NULL,NULL);
		if (hf==INVALID_HANDLE_VALUE) return;
		BITMAPFILEHEADER bfh;
		memset(&bfh,0,sizeof(bfh));
		bfh.bfType=0x4D42;
		bfh.bfSize=sizeof(BITMAPFILEHEADER)+sizeof(m_BitmapInfo)+m_long*m_width;
		bfh.bfReserved1=0;
		bfh.bfReserved2=0;
		bfh.bfOffBits=sizeof(BITMAPFILEHEADER)+sizeof(m_BitmapInfo);
		DWORD dwWritten=0;
		WriteFile(hf,&bfh,sizeof(bfh),&dwWritten,NULL);
		WriteFile(hf,&m_BitmapInfo,sizeof(m_BitmapInfo),&dwWritten,NULL);
		WriteFile(hf,image_data,sizeof(image_data),&dwWritten,NULL);
		CloseHandle(hf);
	}*/

}




						



void CCamTestDlg::shishicanshu()
{
	m_bianmaqi=canshu_data[0]*256+canshu_data[1];
	m_dianji=canshu_data[2]*256+canshu_data[3];
	m_duoji=canshu_data[4]*256+canshu_data[5];
	m_z1=canshu_data[6];
	m_z2=canshu_data[7];
	m_z3=canshu_data[8];
	m_z4=canshu_data[9];
	UpdateData(FALSE);//呈现在编辑框中
	//drawbianmaqi(m_bianmaqi);//显示速度曲线！
	if(md5_right==1){
	pDlg->drawduoji(m_duoji);	      //画图  舵机pwm
	pDlg->drawdianjipwm(m_dianji);	  //画图  电机pwm
	pDlg->drawoumu(m_bianmaqi);	          //画图  欧姆龙
	}
	CString temp;
	temp.Format("%04d",m_duoji);        //绘图窗口 编辑框显示电机舵机值
	pDlg->m_1.SetWindowText(temp);
	temp.Format("%04d",m_dianji);
	pDlg->m_2.SetWindowText(temp);
	temp.Format("%04d",m_bianmaqi);
	pDlg->m_3.SetWindowText(temp);
}

/*void CCamTestDlg::drawbianmaqi(int bianmaqi)
{
   float y;
	if(m_drawflag==1)
	{
	CWnd *pWnd=GetDlgItem(IDC_BIANMAQI);
	CDC *pDC=pWnd->GetDC();
	
	CRect rc;
	pWnd->GetClientRect(rc);//设置区域
	
	
	CPen pen(0,2,RGB(255,0,0));
	CPen *oldpen=pDC->SelectObject(&pen);//为dc选取画笔
	
	pDC->MoveTo(m_x_bianmaqi,m_y_bianmaqi);
	y=n_bianmaqimax/float(rc.Height());
	y=(bianmaqi)/y;
	m_y_bianmaqi=int(y);
	m_x_bianmaqi=m_x_bianmaqi+n_dx;
	if(m_x_bianmaqi>rc.Width())
	{	
		m_x_bianmaqi=0;

        GetDlgItem(IDC_BIANMAQI)-> RedrawWindow();
	
		//InvalidateRect(rc,TRUE);
//		Invalidate();
		pDC->MoveTo(m_x_bianmaqi,m_y_bianmaqi);
	}
	pDC->LineTo(m_x_bianmaqi,m_y_bianmaqi);
	
	pDC->SelectObject(oldpen);
	pWnd->ReleaseDC(pDC);
	}
}*/





void CCamTestDlg::OnNew() 
{
	pDlg->ShowWindow(SW_SHOW);	
}

void CCamTestDlg::OnButtonSend() 
{
 unsigned char buf[12];
 CString str;
 CEdit *edit;
edit=(CEdit *)GetDlgItem(IDC_EDIT1);
	if(!flag_serial) //检查串口是否打开
	{
		AfxMessageBox("串口没有打开");
		return; 
	}
	else{
	UpdateData(TRUE); //读入编辑框中的数据	
	buf[0]=0xaa;
	buf[1]=0xbb;
	buf[2]=0xcc;
	buf[3]=m_send_dianji/256;
	buf[4]=m_send_dianji%256;
	buf[5]=m_send_duoji/256;
	buf[6]=m_send_duoji%256;
	buf[7]=m_send_z1%256;
	buf[8]=m_send_z2%256;
	buf[9]=m_send_z3%256;
	buf[10]=m_send_z4%256;
	m_SerialPort.WriteToPort(buf,11);

	str.Format("%s%02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X","发送数据：",buf[0],buf[1],buf[2],buf[3],buf[4],buf[5],buf[6],buf[7],buf[8],buf[9],buf[10],buf[11]);
	edit->SetWindowText("正在接收图像"+str);//显示16进制数据 
	}

}

void CCamTestDlg::OnAbout() 
{
		pMyAboutDlg=new CMyAboutDlg();
	pMyAboutDlg->Create(IDD_DIALOG2,this);
  	pMyAboutDlg->ShowWindow(SW_SHOW);
	
}

BOOL CCamTestDlg::md5check()
{
LPCTSTR lpRootPathName = "c:\\";          // root directory
	LPTSTR lpVolumeNameBuffer = new char[12];        // volume name buffer
	DWORD nVolumeNameSize = 12 ;          // length of name buffer
	DWORD lpVolumeSerialNumber;     // volume serial number
	DWORD lpMaximumComponentLength; // maximum file name length
	DWORD lpFileSystemFlags;      // file system options
	LPTSTR lpFileSystemNameBuffer = new char[10];   // file system name buffer
	DWORD nFileSystemNameSize = 10;         // length of file system name buffer
	GetVolumeInformation(lpRootPathName,lpVolumeNameBuffer,nVolumeNameSize,
	&lpVolumeSerialNumber,&lpMaximumComponentLength,
	&lpFileSystemFlags,lpFileSystemNameBuffer,nFileSystemNameSize);

	CString str;
	str.Format("%lx",lpVolumeSerialNumber);//获取真实机器码
	
//要CString 转char*
	str="626"+str;   //626+机器码   伪装
    char *ch_str = new char[str.GetLength() + 1];
    strncpy(ch_str,str, str.GetLength() + 1);
	machine_code=MD5String(ch_str);  //真实机器码md5加密，显示在客户界面上的
//需要释放一次
	CString str2=machine_code+"xyz";//xyz你设置的加密字符
	char *ch_str2 = new char[str2.GetLength() + 1];
    strncpy(ch_str2,str2, str2.GetLength() + 1);

	CString md5_str2;
	md5_str2=MD5String(ch_str2);  //加密算法，理论上他们不可能生成 md5(machinecode+"xyz")

	//释放空间
	delete ch_str;
	delete ch_str2;

	//获取配置文件密钥
	CString code1,code2,code3;
	CString des="";
	::GetCurrentDirectory(100,des.GetBuffer(100));
	des.ReleaseBuffer();
	des+="\\config.ini";//获取文件路径

	GetPrivateProfileString("CODE","code1","nocode",code1.GetBufferSetLength(40),40,des);
	code1.ReleaseBuffer();
	GetPrivateProfileString("CODE","code2","nocode",code2.GetBufferSetLength(40),40,des);
	code2.ReleaseBuffer();
	GetPrivateProfileString("CODE","code3","nocode",code3.GetBufferSetLength(40),40,des);
	code3.ReleaseBuffer();

	if(md5_str2==code1||md5_str2==code2||md5_str2==code3)
		return 1;
	else	
		return 0;
}

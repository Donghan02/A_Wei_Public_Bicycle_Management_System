
// CS20200360222Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "CS20200360222.h"
#include "CS20200360222Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 各类变量的定义
CStringArray ID;
CStringArray Address;
CStringArray TD;
CStringArray DIS;
CStringArray Status;
CStringArray Latitude;
CStringArray Longitude;
CStringArray StationName;
int flag1 = 0;
int InServiceStationNum = 0;
int NotInServiceStationNum = 0;
int InServiceDocks = 0;
int NotInServiceDocks = 0;
int TotalStationNum = 0;
int TotalDocksNum = 0;

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


// CCS20200360222Dlg 对话框



CCS20200360222Dlg::CCS20200360222Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CS20200360222_DIALOG, pParent)
	, ShowID(_T(""))
	, ShowName(_T(""))
	, ShowAddress(_T(""))
	, ShowTotalDocks(_T(""))
	, ShowEnableDocks(_T(""))
	, LTT(_T(""))
	, LATT(_T(""))
	, ISSN(_T(""))
	, NUSSN(_T(""))
	, ISDN(_T(""))
	, NISDN(_T(""))
	, ISBN(_T(""))
	, USBN(_T(""))
	, NISBN(_T(""))
	, TTSN(_T(""))
	, DST(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCS20200360222Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, StationSearchBox, SSB);
	DDX_Control(pDX, FirstStationBox, FSB);
	DDX_Control(pDX, EndStationBox, ESB);
	DDX_Control(pDX, StationList, SL);
	DDX_Text(pDX, IDStationID, ShowID);
	DDX_Text(pDX, IDStationAddress, ShowAddress);
	DDX_Text(pDX, IDTotalDocks, ShowTotalDocks);
	DDX_Text(pDX, IDEnableDocks, ShowEnableDocks);
	DDX_Text(pDX, IDLongitude, LTT);
	DDX_Text(pDX, IDLatitude, LATT);
	DDX_Control(pDX, IDMAP, MAP);
	DDX_Text(pDX, IDISSN, ISSN);
	DDX_Text(pDX, IDNISSN, NUSSN);
	DDX_Text(pDX, IDISDN, ISDN);
	DDX_Text(pDX, IDNISDN, NISDN);
	DDX_Text(pDX, IDISBN, ISBN);
	DDX_Text(pDX, IDUBN, USBN);
	DDX_Text(pDX, IDNISBN, NISBN);
	DDX_Text(pDX, IDTTSN, TTSN);
	DDX_Text(pDX, IDDistance, DST);
	DDX_Control(pDX, UserCurrentBox, UCB);
	DDX_Control(pDX, UserHistoryBox, UHB);
}

BEGIN_MESSAGE_MAP(CCS20200360222Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ImportButton, &CCS20200360222Dlg::OnBnClickedImportbutton)
	ON_LBN_SELCHANGE(StationList, &CCS20200360222Dlg::OnLbnSelchangeStationlist)
	ON_CBN_SELCHANGE(StationSearchBox, &CCS20200360222Dlg::OnCbnSelchangeStationsearchbox)
	ON_BN_CLICKED(StationSearchButon, &CCS20200360222Dlg::OnBnClickedStationsearchbuton)
	ON_EN_CHANGE(IDStatus, &CCS20200360222Dlg::OnEnChangeStatus)
	ON_BN_CLICKED(StationShowButton, &CCS20200360222Dlg::OnBnClickedStationshowbutton)
	ON_BN_CLICKED(IDClear, &CCS20200360222Dlg::OnBnClickedClear)
	ON_BN_CLICKED(IDShowData, &CCS20200360222Dlg::OnBnClickedShowdata)
	ON_BN_CLICKED(LengthSearchButton, &CCS20200360222Dlg::OnBnClickedLengthsearchbutton)
	ON_BN_CLICKED(UCurrentButton, &CCS20200360222Dlg::OnBnClickedUcurrentbutton)
	ON_CBN_SELCHANGE(UserCurrentBox, &CCS20200360222Dlg::OnCbnSelchangeUsercurrentbox)
	ON_BN_CLICKED(UHistoryButton, &CCS20200360222Dlg::OnBnClickedUhistorybutton)
	ON_BN_CLICKED(IDC_BUTTON6, &CCS20200360222Dlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// CCS20200360222Dlg 消息处理程序

BOOL CCS20200360222Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	//用户列表初始化
	UCB.AddString(TEXT("哆啦A梦"));
	UCB.AddString(TEXT("大熊"));
	UCB.AddString(TEXT("静香"));
	UCB.AddString(TEXT("胖虎"));
	UCB.AddString(TEXT("小夫"));
	UHB.AddString(TEXT("哆啦A梦"));
	UHB.AddString(TEXT("大熊"));
	UHB.AddString(TEXT("静香"));
	UHB.AddString(TEXT("胖虎"));
	UHB.AddString(TEXT("小夫"));

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCS20200360222Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCS20200360222Dlg::OnPaint()
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
HCURSOR CCS20200360222Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CCS20200360222Dlg::ClearScreen()  // 清屏函数
{
	CBitmap bitmap;  // CBitmap对象，用于加载位图   
	HBITMAP hBmp;    // 保存CBitmap加载的位图的句柄   

	bitmap.LoadBitmap(IDB_BITMAP1);  // 将位图IDB_BITMAP1加载到bitmap   
	hBmp = (HBITMAP)bitmap.GetSafeHandle();  // 获取bitmap加载位图的句柄   
	MAP.SetBitmap(hBmp);    // 复原位图
}

void CCS20200360222Dlg::PaintPoint(int num)  // 显示站点信息的画点函数
{
	CDC* pDC;
	pDC = MAP.GetDC();
	CPen pen;
	pen.CreatePen(1, 10, RGB(47, 31, 228));
	pDC->SelectObject(&pen);
	int x = ((87.8 + _wtof(Longitude[num])) * 1460.0), y = ((42.1 - _wtof(Latitude[num])) * 1960.0); // 坐标放大
	pDC->MoveTo(x, y);
	pDC->LineTo(x, y);  // 画一个点
	pDC->TextOutW(0, 0, StationName[num]);  // 显示站点名字
	ReleaseDC(pDC);
}

void CCS20200360222Dlg::PaintPointWithoutMessage(int num, int i, int j, int k, int size)  // 不显示站点信息并且可自定义点颜色和大小的画点函数
{
	CDC* pDC;
	pDC = MAP.GetDC();
	CPen pen;
	pen.CreatePen(1, size, RGB(i, j, k));
	pDC->SelectObject(&pen);
	int x = ((87.8 + _wtof(Longitude[num])) * 1460.0), y = ((42.1 - _wtof(Latitude[num])) * 1960.0); // 坐标放大
	pDC->MoveTo(x, y);
	pDC->LineTo(x, y);  // 画一个点
	ReleaseDC(pDC);
}

void CCS20200360222Dlg::PaintLine(int x1,int y1 ,int x2,int y2)
{
	CDC* pDC;
	pDC = MAP.GetDC();
	CPen pen;
	pen.CreatePen(1, 3, RGB(183, 97, 207));
	pDC->SelectObject(&pen);
	pDC->TextOutW(x1 + 10, y1 - 20, TEXT("起点"));  // 显示“起点”
	pDC->TextOutW(x2 + 10, y2 - 20, TEXT("终点"));  // 显示“终点”
	int xdifference = x1 - x2;
	int ydifference = y1 - y2;
	int x_10_n = abs(xdifference) / 10;
	int x_10_n_r = abs(xdifference) % 10;
	int y_10_n = abs(ydifference) / 10;
	int y_10_n_r = abs(ydifference) % 10;
	int tx1 = x1, ty1 = y1, tx2 = x1, ty2 = y1;
	if (xdifference < 0)  // 根据曼哈顿距离画线 
	{
		if (ydifference < 0)  // 根据起点与终点在位图中的上下左右关系进行分类
		{
			if (x_10_n > y_10_n)
			{
				for (int i = 0; i < y_10_n; i++)
				{
					tx2 = tx1 + 10;
					ty2 = ty1;
					pDC->MoveTo(tx1, ty1);
					pDC->LineTo(tx2, ty2);
					Sleep(200);
					tx1 = tx2;
					ty1 = ty2;
					tx2 = tx1;
					ty2 = ty1 + 10;
					pDC->MoveTo(tx1, ty1);
					pDC->LineTo(tx2, ty2);
					Sleep(200);
					tx1 = tx2;
					ty1 = ty2;
				}
				tx2 = tx1;
				ty2 = ty1 + y_10_n_r;
				pDC->MoveTo(tx1, ty1);
				pDC->LineTo(tx2, ty2);
				Sleep(200);
				pDC->MoveTo(tx2, ty2);
				pDC->LineTo(x2, y2);
				Sleep(200);
			}
			else
			{
				for (int i = 0; i < x_10_n; i++)
				{
					tx2 = tx1 + 10;
					ty2 = ty1;
					pDC->MoveTo(tx1, ty1);
					pDC->LineTo(tx2, ty2);
					Sleep(200);
					tx1 = tx2;
					ty1 = ty2;
					tx2 = tx1;
					ty2 = ty1 + 10;
					pDC->MoveTo(tx1, ty1);
					pDC->LineTo(tx2, ty2);
					Sleep(200);
					tx1 = tx2;
					ty1 = ty2;
				}
				tx2 = tx1 + x_10_n_r;
				ty2 = ty1;
				pDC->MoveTo(tx1, ty1);
				pDC->LineTo(tx2, ty2);
				Sleep(200);
				pDC->MoveTo(tx2, ty2);
				pDC->LineTo(x2, y2);
				Sleep(200);
			}
		}
		else
		{
			if (x_10_n > y_10_n)
			{
				for (int i = 0; i < y_10_n; i++)
				{
					tx2 = tx1 + 10;
					ty2 = ty1;
					pDC->MoveTo(tx1, ty1);
					pDC->LineTo(tx2, ty2);
					Sleep(200);
					tx1 = tx2;
					ty1 = ty2;
					tx2 = tx1;
					ty2 = ty1 - 10;
					pDC->MoveTo(tx1, ty1);
					pDC->LineTo(tx2, ty2);
					Sleep(200);
					tx1 = tx2;
					ty1 = ty2;
				}
				tx2 = tx1;
				ty2 = ty1 - y_10_n_r;
				pDC->MoveTo(tx1, ty1);
				pDC->LineTo(tx2, ty2);
				Sleep(200);
				pDC->MoveTo(tx2, ty2);
				pDC->LineTo(x2, y2);
				Sleep(200);
			}
			else
			{
				for (int i = 0; i < x_10_n; i++)
				{
					tx2 = tx1 + 10;
					ty2 = ty1;
					pDC->MoveTo(tx1, ty1);
					pDC->LineTo(tx2, ty2);
					Sleep(200);
					tx1 = tx2;
					ty1 = ty2;
					tx2 = tx1;
					ty2 = ty1 - 10;
					pDC->MoveTo(tx1, ty1);
					pDC->LineTo(tx2, ty2);
					Sleep(200);
					tx1 = tx2;
					ty1 = ty2;
				}
				tx2 = tx1 + x_10_n_r;
				ty2 = ty1;
				pDC->MoveTo(tx1, ty1);
				pDC->LineTo(tx2, ty2);
				Sleep(200);
				pDC->MoveTo(tx2, ty2);
				pDC->LineTo(x2, y2);
				Sleep(200);
			}
		}
	}
	else
	{
		if (ydifference < 0)
		{
			if (x_10_n > y_10_n)
			{
				for (int i = 0; i < y_10_n; i++)
				{
					tx2 = tx1 - 10;
					ty2 = ty1;
					pDC->MoveTo(tx1, ty1);
					pDC->LineTo(tx2, ty2);
					Sleep(200);
					tx1 = tx2;
					ty1 = ty2;
					tx2 = tx1;
					ty2 = ty1 + 10;
					pDC->MoveTo(tx1, ty1);
					pDC->LineTo(tx2, ty2);
					Sleep(200);
					tx1 = tx2;
					ty1 = ty2;
				}
				tx2 = tx1;
				ty2 = ty1 + y_10_n_r;
				pDC->MoveTo(tx1, ty1);
				pDC->LineTo(tx2, ty2);
				Sleep(200);
				pDC->MoveTo(tx2, ty2);
				pDC->LineTo(x2, y2);
				Sleep(200);
			}
			else
			{
				for (int i = 0; i < x_10_n; i++)
				{
					tx2 = tx1 - 10;
					ty2 = ty1;
					pDC->MoveTo(tx1, ty1);
					pDC->LineTo(tx2, ty2);
					Sleep(200);
					tx1 = tx2;
					ty1 = ty2;
					tx2 = tx1;
					ty2 = ty1 + 10;
					pDC->MoveTo(tx1, ty1);
					pDC->LineTo(tx2, ty2);
					Sleep(200);
					tx1 = tx2;
					ty1 = ty2;
				}
				tx2 = tx1 - x_10_n_r;
				ty2 = ty1;
				pDC->MoveTo(tx1, ty1);
				pDC->LineTo(tx2, ty2);
				Sleep(200);
				pDC->MoveTo(tx2, ty2);
				pDC->LineTo(x2, y2);
				Sleep(200);
			}
		}
		else
		{
			if (x_10_n > y_10_n)
			{
				for (int i = 0; i < y_10_n; i++)
				{
					tx2 = tx1 - 10;
					ty2 = ty1;
					pDC->MoveTo(tx1, ty1);
					pDC->LineTo(tx2, ty2);
					Sleep(200);
					tx1 = tx2;
					ty1 = ty2;
					tx2 = tx1;
					ty2 = ty1 - 10;
					pDC->MoveTo(tx1, ty1);
					pDC->LineTo(tx2, ty2);
					Sleep(200);
					tx1 = tx2;
					ty1 = ty2;
				}
				tx2 = tx1;
				ty2 = ty1 - y_10_n_r;
				pDC->MoveTo(tx1, ty1);
				pDC->LineTo(tx2, ty2);
				Sleep(200);
				pDC->MoveTo(tx2, ty2);
				pDC->LineTo(x2, y2);
				Sleep(200);
			}
			else
			{
				for (int i = 0; i < x_10_n; i++)
				{
					tx2 = tx1 - 10;
					ty2 = ty1;
					pDC->MoveTo(tx1, ty1);
					pDC->LineTo(tx2, ty2);
					Sleep(200);
					tx1 = tx2;
					ty1 = ty2;
					tx2 = tx1;
					ty2 = ty1 - 10;
					pDC->MoveTo(tx1, ty1);
					pDC->LineTo(tx2, ty2);
					Sleep(200);
					tx1 = tx2;
					ty1 = ty2;
				}
				tx2 = tx1 - x_10_n_r;
				ty2 = ty1;
				pDC->MoveTo(tx1, ty1);
				pDC->LineTo(tx2, ty2);
				Sleep(200);
				pDC->MoveTo(tx2, ty2);
				pDC->LineTo(x2, y2);
				Sleep(200);
			}
		}
	 }

	ReleaseDC(pDC); 
	/*int tx1 = x1, tx2, ty1 = y1, ty2;
	int num = rand() % 7;  // 模拟途经站点数量
	for (int i = 0; i < num; i++)
	{
		int randnum = rand() % 589;  // 模拟途经站点
		PaintPointWithoutMessage(randnum, 54, 197, 193, 8);
		tx2 = ((87.8 + _wtof(Longitude[randnum])) * 1460.0);
		ty2 = ((42.1 - _wtof(Latitude[randnum])) * 1960.0);
		pDC->MoveTo(tx1, ty1);
		pDC->LineTo(tx2, ty2);
		tx1 = tx2;
		ty1 = ty2;
		Sleep(600);
	}
	pDC->MoveTo(tx1, ty1);
	pDC->LineTo(x2, y2);  
	ReleaseDC(pDC);*/
}

void CCS20200360222Dlg::OnBnClickedImportbutton()
{
	// TODO: 在此添加控件通知处理程序代码
	CString defaultDir = L"D:\\";  // 默认打开文件路径
	CString fileName = L"";  // 默认打开文件名
	CString Filter = L"文件(*.txt; *.csv)|*.txt; *.csv;||";  // 文件过滤类型
	CFileDialog importfiledlg( TRUE, defaultDir, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, Filter, NULL);
	INT_PTR result = importfiledlg.DoModal();  // 弹出导入框并记录导入结果
	if (result == IDOK)
	{
		fileName = importfiledlg.GetPathName();
		CStdioFile f;
		CFileException e;
		if (!f.Open(fileName, CFile::modeRead, &e))
		{
			TRACE(_T("QAQ 文件打不开噢 %d\n"), e.m_cause);
		}

		CString str = NULL;
		f.ReadString(str);
		int i = 0;
		while (str != "" && i++ < 589) 
		{
			SL.AddString(str);  // 将导入的所有数据显示在站点信息总览中
			f.ReadString(str);
		}
		int pos = 0;
		int next_pos = 0;
		int line = 0;
		int case_id = 0;
		CString temp;
		CString s;
		while (line < 589)
		{
			// 数据初始化
			case_id = 0;
			pos = 0;
			next_pos = 0;
			ASSERT(line < 589);  // 行数超过589时报错
			SL.GetText(line, s);
			while (case_id < 8)
			{
				next_pos = s.Find(',', pos);  // 从当前逗号出现的位置开始寻找下一个‘，’出现的位置存入next_pos
				temp = s.Mid(pos, next_pos - pos); // 截取从当前逗号位置pos开始到下个逗号出现位置间的字符串并存入temp
				pos = next_pos + 1;                 // 当前逗号位置更新
				switch (case_id)
				{
					case 0:
						ID.Add(temp);
						break;
					case 1:
						StationName.Add(temp);
						ESB.AddString(temp);
						FSB.AddString(temp);
						SSB.AddString(temp);  // 将站点名字导入到各个查询列表中
						break;
					case 2:
						Address.Add(temp);
						break;
					case 3:
						TD.Add(temp);
						TotalDocksNum += _wtoi(temp);
						break;
					case 4:
						DIS.Add(temp);
						InServiceDocks += _wtoi(temp);
						break;
					case 5:
						Status.Add(temp);
						if (temp == "In Service")  InServiceStationNum++;
						break;
					case 6:
						Latitude.Add(temp);
						break;
					case 7:
						Longitude.Add(temp);
						break;
				}
				case_id++;
			}
			line++;
			TotalStationNum++;
		}
		MessageBox(_T("好耶！导入成功了！"));
		flag1 = 1;
		NotInServiceStationNum = TotalStationNum - InServiceStationNum;
		NotInServiceDocks = TotalDocksNum - InServiceDocks;
	}
}



void CCS20200360222Dlg::OnLbnSelchangeStationlist()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CCS20200360222Dlg::OnCbnSelchangeStationsearchbox()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CCS20200360222Dlg::OnBnClickedStationsearchbuton()
{
	// TODO: 在此添加控件通知处理程序代码
	if (flag1 == 0)
	{
		MessageBox(_T("在查询具体站点前要先导入所有站点的数据噢！"));
	}
	else
	{
		CString temp;  // 用于临时存放字符串
		int tempID = SSB.GetCurSel();  // 得到下拉框当前选项的ID
		if (tempID == -1)
		{
			MessageBox(_T("查询前请先选择需要查询的站点噢！"));  // 警告
		}
		else
		{
			SSB.GetLBText(tempID, temp);  // 得到下拉框当前ID下的内容并存入temp中
			int num = SSB.FindStringExact(0, temp);  // 得到对应内容的索引
			// 各个控件的信息显示
			GetDlgItem(IDStationID)->SetWindowText(ID[num]); 
			GetDlgItem(IDStationAddress)->SetWindowText(Address[num]);
			GetDlgItem(IDTotalDocks)->SetWindowText(TD[num]);
			GetDlgItem(IDEnableDocks)->SetWindowText(DIS[num]);
			GetDlgItem(IDStatus)->SetWindowText(Status[num]);
			GetDlgItem(IDLongitude)->SetWindowText(Longitude[num]);
			GetDlgItem(IDLatitude)->SetWindowText(Latitude[num]);

			ClearScreen();

			// 地图内站点显示
			PaintPoint(num);
		}
	}
}


void CCS20200360222Dlg::OnEnChangeStatus()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}





void CCS20200360222Dlg::OnBnClickedStationshowbutton()
{
	// TODO: 在此添加控件通知处理程序代码
	 
	// 显示所有站点

	if (flag1 == 0)
	{
		MessageBox(_T("在查询站点分布前要先导入所有站点的数据噢！"));  // 提醒
	}
	else
	{
		ClearScreen();

		for (int num = 0; num < 589; num++)
		{
			PaintPointWithoutMessage(num, 226, 61, 160, 5);
		}
	}
	
	
}


void CCS20200360222Dlg::OnBnClickedClear()
{
	// TODO: 在此添加控件通知处理程序代码

	// 清屏

	ClearScreen();
}


void CCS20200360222Dlg::OnBnClickedShowdata()
{
	// TODO: 在此添加控件通知处理程序代码

	if (flag1 == 0)
	{
		MessageBox(_T("在更新信息前要先导入所有站点的数据噢！没有所有站点的数据又怎么更新信息嘛！"));  // 提醒
	}
	else
	{
		int randnum = rand() % 3000; // 生成一个随机数来模拟使用中的单车
		CString temp;  // 定义一个临时的变量来存放转化后的字符串
		temp.Format(_T("%d"), InServiceStationNum);  // 将整型转化为字符串
		GetDlgItem(IDISSN)->SetWindowText(temp);
		temp.Format(_T("%d"), NotInServiceStationNum);
		GetDlgItem(IDNISSN)->SetWindowText(temp);
		temp.Format(_T("%d"), TotalStationNum);
		GetDlgItem(IDTTSN)->SetWindowText(temp);
		temp.Format(_T("%d"), InServiceDocks);
		GetDlgItem(IDISDN)->SetWindowText(temp);
		temp.Format(_T("%d"), NotInServiceDocks);
		GetDlgItem(IDNISDN)->SetWindowText(temp);
		temp.Format(_T("%d"), InServiceDocks - randnum);
		GetDlgItem(IDISBN)->SetWindowText(temp);
		temp.Format(_T("%d"), randnum);
		GetDlgItem(IDUBN)->SetWindowText(temp);
		temp.Format(_T("%d"), NotInServiceDocks);
		GetDlgItem(IDNISBN)->SetWindowText(temp);
	}
	
}


void CCS20200360222Dlg::OnBnClickedLengthsearchbutton()
{
	// TODO: 在此添加控件通知处理程序代码

	if (flag1 == 0)
	{
		MessageBox(_T("在查询距离前要先导入所有站点的数据噢！"));  // 提醒
	}
	else
	{
		CString temp1,temp2,temp3;  // 用于临时存放字符串
		int tempID1 = FSB.GetCurSel();  // 得到起始站点下拉框当前选项的ID
		int tempID2 = ESB.GetCurSel();  // 得到目标站点下拉框当前选项的ID
		int distance; // 存放距离
		if (tempID1 == -1 || tempID2 == -1)
		{
			MessageBox(_T("查询两个站点的距离前请先选择需要查询的两个站点噢！"));  // 警告
		}
		else
		{
			FSB.GetLBText(tempID1, temp1);  // 得到起始站点下拉框当前ID下的内容并存入temp1中
			int num1 = FSB.FindStringExact(0, temp1);  // 得到对应内容的索引
			ESB.GetLBText(tempID2, temp2);  // 得到起始站点下拉框当前ID下的内容并存入temp1中
			int num2 = ESB.FindStringExact(0, temp2);  // 得到对应内容的索引
			distance = (fabs(_wtof(Longitude[num1]) - _wtof(Longitude[num2])) * 1460 + fabs(_wtof(Latitude[num1]) - _wtof(Latitude[num2])) * 1960) / 5.0 ;
			ClearScreen(); // 清屏
			PaintPointWithoutMessage(num1, 29, 222, 57, 13);  // 画出两个点
			PaintPointWithoutMessage(num2, 224, 105, 27, 13);
			// 将两个点连起来
			CDC* pDC;
			pDC = MAP.GetDC();
			CPen pen;
			pen.CreatePen(1, 3, RGB(183, 97, 207));
			pDC->SelectObject(&pen);
			int x1 = ((87.8 + _wtof(Longitude[num1])) * 1460.0), y1 = ((42.1 - _wtof(Latitude[num1])) * 1960.0); // 坐标放大
			int x2 = ((87.8 + _wtof(Longitude[num2])) * 1460.0), y2 = ((42.1 - _wtof(Latitude[num2])) * 1960.0); // 坐标放大
			pDC->TextOutW(x1 + 10, y1 - 20, TEXT("起点"));  // 显示“起点”
			pDC->TextOutW(x2 + 10, y2 - 20, TEXT("终点"));  // 显示“终点”
			pDC->MoveTo(x1, y1);
			pDC->LineTo(x2, y2);
			ReleaseDC(pDC);
			temp3.Format(_T("%d"), distance);  // 将整型转化为字符串
			GetDlgItem(IDDistance)->SetWindowText(temp3);
		}
	}
}


void CCS20200360222Dlg::OnBnClickedUcurrentbutton()
{
	// TODO: 在此添加控件通知处理程序代码

	if (flag1 == 0)
	{
		MessageBox(_T("在查询距离前要先导入所有站点的数据噢！"));  // 提醒
	}
	else
	{
		CString temp;  // 用于临时存放字符串
		int tempID = UCB.GetCurSel();  // 得到下拉框当前选项的ID
		if (tempID == -1 )
		{
			MessageBox(_T("在查询用户当前状态前请先选择需要查询的用户噢！！"));  // 警告
		}
		else
		{
			int randnum = rand() % 589;

			// 清理位图
			ClearScreen();

			//描点
			PaintPoint(randnum);
		}
	}
	
}


void CCS20200360222Dlg::OnCbnSelchangeUsercurrentbox()
{
	// TODO: 在此添加控件通知处理程序代码
	
}


void CCS20200360222Dlg::OnBnClickedUhistorybutton()
{
	// TODO: 在此添加控件通知处理程序代码
	// 清屏
	ClearScreen();
	int tempID = UHB.GetCurSel();  // 得到下拉框当前选项的ID
	if (tempID == -1)
	{
		MessageBox(_T("在查询用户当前状态前请先选择需要查询的用户噢！！"));  // 警告
	}
	else
	{
		int flag2 = 0;
		int num1, num2;
		int x1, y1, x2, y2;
		while (flag2 == 0)  // 生成两个x距离与y距离相差不大并且距离不至于太近的两个随机点
		{
			num1 = rand() % 589;
			num2 = rand() % 589;
			if (num1 == num2)
			{
				num2 = num2 % 100;
			}
			x1 = ((87.8 + _wtof(Longitude[num1])) * 1460.0), y1 = ((42.1 - _wtof(Latitude[num1])) * 1960.0);
			x2 = ((87.8 + _wtof(Longitude[num2])) * 1460.0), y2 = ((42.1 - _wtof(Latitude[num2])) * 1960.0);
			int xdifference = x1 - x2;
			int ydifference = y1 - y2;
			if (abs(ydifference - xdifference) < 30 && abs(ydifference) > 100  && abs(xdifference) > 100 )
			{
				flag2 = 1;
			}
		}
		
		// 显示站点名字
		GetDlgItem(IDBeginStation)->SetWindowText(StationName[num1]);
		GetDlgItem(IDEndStation)->SetWindowTextW(StationName[num2]);
		// 以不同颜色描绘站点
		PaintPointWithoutMessage(num1, 29, 222, 57,13);
		PaintPointWithoutMessage(num2, 224, 105, 27, 13);
		// 画线显示运动轨迹
		PaintLine(x1, y1, x2, y2);
	}
}


void CCS20200360222Dlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	system("start explorer https://github.com/Donghan02/A_Wei_Public_Bicycle_Management_System.git");  // 跳转到github
}

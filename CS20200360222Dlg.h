
// CS20200360222Dlg.h: 头文件
//

#pragma once


// CCS20200360222Dlg 对话框
class CCS20200360222Dlg : public CDialogEx
{
// 构造
public:
	CCS20200360222Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CS20200360222_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


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
	afx_msg void OnBnClickedImportbutton();
	CComboBox SSB;
	CComboBox FSB;
	CComboBox ESB;
	CListBox SL;
	afx_msg void OnLbnSelchangeStationlist();
private:
	CString ShowID;
public:
	CString ShowName;
	CString ShowAddress;
	CString ShowTotalDocks;
	CString ShowEnableDocks;
	afx_msg void OnCbnSelchangeStationsearchbox();
	afx_msg void OnBnClickedStationsearchbuton();
	afx_msg void OnEnChangeStatus();
	CString LTT;
	CString LATT;
	afx_msg void OnStnClickedLongtitude();
	CStatic MAP;
	afx_msg void OnStnClickedLongitude();
	CString ISSN;
	CString NUSSN;
	CString ISDN;
	CString NISDN;
	CString ISBN;
	CString USBN;
	CString NISBN;
	afx_msg void OnBnClickedStationshowbutton();
	afx_msg void OnBnClickedClear();
	afx_msg void OnBnClickedShowdata();
	CString TTSN;
	afx_msg void OnBnClickedLengthsearchbutton();
	CString DST;
	afx_msg void OnBnClickedUcurrentbutton();
	CComboBox UCB;
	afx_msg void OnCbnSelchangeUsercurrentbox();
	CComboBox UHB;
	void ClearScreen();
	void PaintPoint(int);
	void PaintPointWithoutMessage(int, int, int, int, int);
	void PaintLine(int, int, int, int);
	afx_msg void OnBnClickedUhistorybutton();
	afx_msg void OnBnClickedButton6();
};

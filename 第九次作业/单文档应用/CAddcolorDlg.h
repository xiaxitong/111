#pragma once


// CAddcolorDlg 对话框

class CAddcolorDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddcolorDlg)

public:
	CAddcolorDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CAddcolorDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_COLOR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	int m_nOperator;
	CComboBox m_Operator;
	afx_msg void OnCbnSelchangeCombo();
};

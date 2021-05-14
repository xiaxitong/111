// CAddcolorDlg.cpp: 实现文件
//

#include "pch.h"
#include "第九次作业.h"
#include "CAddcolorDlg.h"
#include "afxdialogex.h"


// CAddcolorDlg 对话框

IMPLEMENT_DYNAMIC(CAddcolorDlg, CDialogEx)

CAddcolorDlg::CAddcolorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_COLOR, pParent)
	, m_nOperator(0)
{

}

CAddcolorDlg::~CAddcolorDlg()
{
}

void CAddcolorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_CBIndex(pDX, IDC_COMBO, m_nOperator);
	DDX_Control(pDX, IDC_COMBO, m_Operator);
}


BEGIN_MESSAGE_MAP(CAddcolorDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAddcolorDlg::OnBnClickedOk)
	ON_CBN_SELCHANGE(IDC_COMBO, &CAddcolorDlg::OnCbnSelchangeCombo)
END_MESSAGE_MAP()


// CAddcolorDlg 消息处理程序


void CAddcolorDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CAddcolorDlg::OnCbnSelchangeCombo()
{
	// TODO: 在此添加控件通知处理程序代码
}

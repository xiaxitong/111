
// 第九次作业View.cpp: C第九次作业View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第九次作业.h"
#endif

#include "第九次作业Doc.h"
#include "第九次作业View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "CAddcolorDlg.h"


// C第九次作业View

IMPLEMENT_DYNCREATE(C第九次作业View, CView)

BEGIN_MESSAGE_MAP(C第九次作业View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FONTDLG_MENU, &C第九次作业View::OnFontdlgMenu)
	ON_COMMAND(ID_SELECT_COLOR, &C第九次作业View::OnSelectColor)
END_MESSAGE_MAP()

// C第九次作业View 构造/析构

C第九次作业View::C第九次作业View() noexcept
{
	// TODO: 在此处添加构造代码

}

C第九次作业View::~C第九次作业View()
{
}

BOOL C第九次作业View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第九次作业View 绘图

void C第九次作业View::OnDraw(CDC* pDC)//DC是一种包含设备信息的数据结构，也是一个关于如何绘制图形的方法的集合。所以在进行绘制时，要先得到DC的指针，即pDC
{
	C第九次作业Doc* pDoc = GetDocument();//GetDocument();函数用于返回与视图相关联的文档对象的指针，利用这个指针可以访问文档类以及派生类的公有成员
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	//改变字体的原理是用新的字体对象替换先前的相同类型的对象
	//CFont newFont;
	//CFont* pOldFont;
	CFont* pfntOld = (CFont*)pDC->SelectObject(&m_font);
	pDC->SetTextColor(m_TextColor);
//	newFont.CreatePointFont(180, _T("行书"));
//	pOldFont = (CFont*)pDC->SelectObject(&newFont);//SelectObject()函数返回的是被取代对象的句柄，也就是说原来的字体依然存在。
//	pDC->SetTextColor(RGB(25,255,0));//RGB内的三个位置分别代表红，绿，蓝三个颜色，数值在0——255之间
	pDC->TextOut(50, 50, _T("人间理想"));
//	pDC->SelectObject(pOldFont);//恢复原来的字体
//	pDC->SetTextColor(RGB(0, 100, 99));
	pDC->SelectObject(pfntOld);
	pDC->TextOut(50, 100, _T("利威尔！"));
	

}


// C第九次作业View 打印

BOOL C第九次作业View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C第九次作业View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C第九次作业View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C第九次作业View 诊断

#ifdef _DEBUG
void C第九次作业View::AssertValid() const
{
	CView::AssertValid();
}

void C第九次作业View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第九次作业Doc* C第九次作业View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第九次作业Doc)));
	return (C第九次作业Doc*)m_pDocument;
}
#endif //_DEBUG


// C第九次作业View 消息处理程序


void C第九次作业View::OnFontdlgMenu()
{
	// TODO: 在此添加命令处理程序代码
	CFontDialog dlgFont;//通用字体对话框,系统自带，不用添加
	if (dlgFont.DoModal() == IDOK)
	{
		LOGFONT LogFnt; 
		m_font.DeleteObject();//释放之前与m_font关联的对象资源
		dlgFont.GetCurrentFont(&LogFnt);//使用选定字体的LOGFONT创建新的字体
		m_font.CreatePointFontIndirect(&LogFnt);//创建字体的函数,该方法通过LOGFONT结构体创建字体
	//	m_TextColor = dlgFont.GetColor();
		RedrawWindow();//立即更新窗口
	}
}


void C第九次作业View::OnSelectColor()
{
	// TODO: 在此添加命令处理程序代码
	CAddcolorDlg cdlg;
	if (cdlg.DoModal() == IDOK)
	{
		if (cdlg.m_nOperator == 0)
			m_TextColor = RGB(255, 0, 0);
		if (cdlg.m_nOperator == 1)
			m_TextColor = RGB(0, 255, 0);
		if (cdlg.m_nOperator == 2)
			m_TextColor = RGB(0, 0, 255);
	}
	RedrawWindow();//立即更新窗口
}

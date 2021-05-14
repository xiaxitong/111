
// 第九次作业View.h: C第九次作业View 类的接口
//

#pragma once


class C第九次作业View : public CView
{
protected: // 仅从序列化创建
	C第九次作业View() noexcept;
	DECLARE_DYNCREATE(C第九次作业View)

// 特性
public:
	C第九次作业Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	CFont m_font;//字体
	COLORREF m_TextColor;//字体颜色
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~C第九次作业View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFontdlgMenu();
	afx_msg void OnSelectColor();
};

#ifndef _DEBUG  // 第九次作业View.cpp 中的调试版本
inline C第九次作业Doc* C第九次作业View::GetDocument() const
   { return reinterpret_cast<C第九次作业Doc*>(m_pDocument); }
#endif


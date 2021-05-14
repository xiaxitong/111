
// 第九次作业.h: 第九次作业 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"       // 主符号


// C第九次作业App:
// 有关此类的实现，请参阅 第九次作业.cpp
//

class C第九次作业App : public CWinApp
{
public:
	C第九次作业App() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C第九次作业App theApp;

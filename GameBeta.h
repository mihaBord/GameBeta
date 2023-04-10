
// GameBeta.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CGameBetaApp:
// Сведения о реализации этого класса: GameBeta.cpp
//

class CGameBetaApp : public CWinApp
{
public:
	CGameBetaApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CGameBetaApp theApp;

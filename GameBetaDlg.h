
// GameBetaDlg.h: файл заголовка
//

#pragma once
//#include "Uzbuve.h"
#include <cstring>

// Диалоговое окно CGameBetaDlg
class CGameBetaDlg : public CDialogEx
{
// Создание
public:
	CGameBetaDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GAMEBETA_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();

	afx_msg void OnEnChangeEdit1();
	int m_Area;
	int m_Dal2;
	int m_Dal3;
	int m_Min5;
	afx_msg void OnBnClickedBut2();
	afx_msg void OnBnClickedBut3();
	afx_msg void OnBnClickedBut5();	
	afx_msg void OnEnChangeEdit6();
	CString m_kokss;
	afx_msg void OnEnChangeEdit7();
	CString tryyt;
	afx_msg void OnBnClickedButton4();
	CString m_str_dal2;
	CString m_str_dal3;
	CString m_str_min5;
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit5();
	int m_gajeni;
	afx_msg void OnBnClickedRestart();
	
	int m_spel1;
	int m_spel2;
	int speletais;
	CString m_1_S_aile;
	CString m_2_S_aile;
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit4();
	CString m_Testt;
	int m_Start;
	afx_msg void OnBnClickedButton2();
};

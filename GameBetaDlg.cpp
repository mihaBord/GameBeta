
// GameBetaDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "GameBeta.h"
#include "GameBetaDlg.h"
#include "afxdialogex.h"
#include "Uzbuve.h"
#include <iostream>
#include <fstream>



using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
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


// Диалоговое окно CGameBetaDlg



CGameBetaDlg::CGameBetaDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GAMEBETA_DIALOG, pParent)
	, m_Area(60)
	, m_Dal2(0)
	, m_Dal3(0)
	, m_Min5(0)
	, speletais(1)
	, m_kokss(_T(""))
	, tryyt(_T(""))
	, m_str_dal2(_T("1"))
	, m_str_dal3(_T("1"))
	, m_str_min5(_T("1"))
	, m_gajeni(0)
	, m_spel1(0)
	, m_spel2(0)
	, m_1_S_aile(_T("Speletais:"))
	, m_2_S_aile(_T("Dators:"))
	, m_Testt(_T(""))
	, m_Start(60)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGameBetaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Area);
	DDX_Text(pDX, IDC_VERT2, m_Dal2);
	DDX_Text(pDX, IDC_VERT3, m_Dal3);
	DDX_Text(pDX, IDC_VERT5, m_Min5);


	DDX_Text(pDX, IDC_EDIT8, tryyt);
	DDX_Text(pDX, IDC_EDIT2, m_str_dal2);
	DDX_Text(pDX, IDC_EDIT3, m_str_dal3);
	DDX_Text(pDX, IDC_EDIT4, m_str_min5);
	DDX_Text(pDX, IDC_EDIT5, m_gajeni);

	DDX_Text(pDX, IDC_EDIT6, m_spel1);
	DDX_Text(pDX, IDC_EDIT7, m_spel2);
	DDX_Text(pDX, IDC_EDIT9, m_1_S_aile);
	DDX_Text(pDX, IDC_EDIT10, m_2_S_aile);

	DDX_Text(pDX, IDC_EDIT13, m_Start);
}

BEGIN_MESSAGE_MAP(CGameBetaDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CGameBetaDlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT1, &CGameBetaDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUT2, &CGameBetaDlg::OnBnClickedBut2)
	ON_BN_CLICKED(IDC_BUT3, &CGameBetaDlg::OnBnClickedBut3)
	ON_BN_CLICKED(IDC_BUT5, &CGameBetaDlg::OnBnClickedBut5)
	
	
	ON_BN_CLICKED(IDC_BUTTON4, &CGameBetaDlg::OnBnClickedButton4)
	ON_EN_CHANGE(IDC_EDIT2, &CGameBetaDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT5, &CGameBetaDlg::OnEnChangeEdit5)
	ON_BN_CLICKED(IDC_Restart, &CGameBetaDlg::OnBnClickedRestart)
	ON_EN_CHANGE(IDC_EDIT3, &CGameBetaDlg::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &CGameBetaDlg::OnEnChangeEdit4)
	ON_BN_CLICKED(IDC_BUTTON2, &CGameBetaDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// Обработчики сообщений CGameBetaDlg

BOOL CGameBetaDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
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

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CGameBetaDlg::OnSysCommand(UINT nID, LPARAM lParam)
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


void CGameBetaDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); 

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		

		if (m_Area % 2 == 0) {
			m_Dal2 = m_Area / 2;
			m_str_dal2 = (_T("Var"));
		}
		else {
			m_str_dal2 = (_T("Nevar sadalit"));
			m_Dal2 = 0;
		}
		if (m_Area % 3 == 0) {
			m_str_dal3 = (_T("Var"));
			m_Dal3 = m_Area / 3;
		}
		else {
			m_str_dal3 = (_T("Nevar sadalit"));
			m_Dal3 = 0;
		}
		m_Min5 = m_Area - 5;
		m_str_min5 = (_T("Var"));
		UpdateData(FALSE);
		CDialogEx::OnPaint();

	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CGameBetaDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CGameBetaDlg::OnBnClickedOk()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialogEx::OnOK();
}


void CGameBetaDlg::OnEnChangeEdit1()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}


void CGameBetaDlg::OnBnClickedBut2()
{
	// Speletaja Gajens
	if (m_Area > 0) {
		if (m_Area % 2 == 0) {
			m_Area = m_Area / 2;
			if (m_gajeni % 2 == 0) {
				m_spel1 = m_Area;
			}
			else {
				m_spel2 = m_Area;
			}
			if (m_Area > 5) {
				if (m_Area % 2 == 0) {
					m_Dal2 = m_Area / 2;
					m_str_dal2 = (_T("Var"));
				}
				else {
					m_str_dal2= (_T("Nevar sadalit"));
					m_Dal2 = 0;
				}
				if (m_Area % 3 == 0) {
					m_str_dal3 = (_T("Var"));
					m_Dal3 = m_Area / 3;
				}
				else {
					m_str_dal3 = (_T("Nevar sadalit"));
					m_Dal3 = 0;
				}
				m_Min5 = m_Area - 5;
				m_str_min5 = (_T("Var"));
				m_gajeni++;
				UpdateData(FALSE);
			}
			else {

				m_gajeni++;
				if (m_gajeni % 2 == 0 && speletais == 0) {
					
					tryyt = (_T("End dators vine"));
				}
				else {
					if (m_gajeni % 2 != 0 && speletais != 0) {
						tryyt = (_T("End dators vine"));
					}
					else {
						tryyt = (_T("End speletais vine"));
						MessageBox(_T("Tu Uzvarei"), _T("Wow Paveicas"), MB_ICONEXCLAMATION);
					}

				}
				m_Area = 0;
				m_Min5 = 0;
				m_Dal3 = 0;
				m_Dal2 = 0;
				UpdateData(FALSE);
			}
		}
		//datora gajems
		if (m_Area > 5) {
			m_Area = (logika(m_Area));
			if (m_gajeni % 2 == 0) {
				m_spel1 = m_Area;
			}
			else {
				m_spel2 = m_Area;
			}
			if (m_Area > 5) {
				if (m_Area % 2 == 0) {
					m_Dal2 = m_Area / 2;
					m_str_dal2 = (_T("Var"));
				}
				else {
					m_str_dal2 = (_T("Nevar sadalit"));
					m_Dal2 = 0;
				}
				if (m_Area % 3 == 0) {
					m_str_dal3 = (_T("Var"));
					m_Dal3 = m_Area / 3;
				}
				else {
					m_str_dal3 = (_T("Nevar sadalit"));
					m_Dal3 = 0;
				}
				m_Min5 = m_Area - 5;
				m_str_min5 = (_T("Var"));
				m_gajeni++;
				UpdateData(FALSE);

			}
			else {

				m_gajeni++;
				if (m_gajeni % 2 == 0 && speletais == 0) {
					tryyt = (_T("End dators vine"));
					MessageBox(_T("Dators Uzvareja"), _T("Neveicas"), MB_ICONEXCLAMATION);
				}
				else {
					if (m_gajeni % 2 != 0 && speletais != 0) {
						tryyt = (_T("End dators vine"));
						MessageBox(_T("Dators Uzvareja"), _T("Neveicas"), MB_ICONEXCLAMATION);
					}
					else {
						tryyt = (_T("End speletais vine"));
						MessageBox(_T("Tu Uzvarei"), _T("Wow Paveicas"), MB_ICONEXCLAMATION);
					}

				}
				m_Area = 0;
				m_Min5 = 0;
				m_Dal3 = 0;
				m_Dal2 = 0;
				UpdateData(FALSE);
			}
		}
		else {


			if (m_gajeni % 2 == 0 && speletais == 0) {
				tryyt = (_T("End dators vine"));
				MessageBox(_T("Dators Uzvareja"), _T("Neveicas"), MB_ICONEXCLAMATION);
			}
			else {
				if (m_gajeni % 2 != 0 && speletais != 0) {
					tryyt = (_T("End dators vine"));
					MessageBox(_T("Dators Uzvareja"), _T("Neveicas"), MB_ICONEXCLAMATION);
				}
				else {
					tryyt = (_T("End speletais vine"));
					MessageBox(_T("Tu Uzvarei"), _T("Wow Paveicas"), MB_ICONEXCLAMATION);
				}

			}
			m_Area = 0;
			m_Min5 = 0;
			m_Dal3 = 0;
			m_Dal2 = 0;
			UpdateData(FALSE);
		}
	}
}


void CGameBetaDlg::OnBnClickedBut3()
{
	// Speletaja Gajens
	if (m_Area > 0) {
		if (m_Area % 3 == 0) {
			m_Area = m_Area / 3;
			if (m_gajeni % 2 == 0) {
				m_spel1 = m_Area;
			}
			else {
				m_spel2 = m_Area;
			}
			if (m_Area > 5) {
				if (m_Area % 2 == 0) {
					m_Dal2 = m_Area / 2;
					m_str_dal2 = (_T("Var"));
				}
				else {
					m_str_dal2 = (_T("Nevar sadalit"));
					m_Dal2 = 0;
				}
				if (m_Area % 3 == 0) {
					m_str_dal3 = (_T("Var"));
					m_Dal3 = m_Area / 3;
				}
				else {
					m_str_dal3 = (_T("Nevar sadalit"));
					m_Dal3 = 0;
				}
				m_Min5 = m_Area - 5;
				m_str_min5 = (_T("Var"));
				m_gajeni++;
				UpdateData(FALSE);
			}
			else {

				m_gajeni++;
				if (m_gajeni % 2 == 0 && speletais == 0) {
					tryyt = (_T("End dators vine"));
				}
				else {
					if (m_gajeni % 2 != 0 && speletais != 0) {
						tryyt = (_T("End dators vine"));
					}
					else {
						tryyt = (_T("End speletais vine"));
						MessageBox(_T("Tu Uzvarei"), _T("Wow Paveicas"), MB_ICONEXCLAMATION);
					}

				}
				m_Area = 0;
				m_Min5 = 0;
				m_Dal3 = 0;
				m_Dal2 = 0;
				UpdateData(FALSE);
			}
		}
		//datora gajens
		if (m_Area > 5) {
			m_Area = (logika(m_Area));
			if (m_gajeni % 2 == 0) {
				m_spel1 = m_Area;
			}
			else {
				m_spel2 = m_Area;
			}
			if (m_Area > 5) {
				if (m_Area % 2 == 0) {
					m_Dal2 = m_Area / 2;
					m_str_dal2 = (_T("Var"));
				}
				else {
					m_str_dal2 = (_T("Nevar sadalit"));
					m_Dal2 = 0;
				}
				if (m_Area % 3 == 0) {
					m_str_dal3 = (_T("Var"));
					m_Dal3 = m_Area / 3;
				}
				else {
					m_str_dal3 = (_T("Nevar sadalit"));
					m_Dal3 = 0;
				}
				m_Min5 = m_Area - 5;
				m_str_min5 = (_T("Var"));
				m_gajeni++;
				UpdateData(FALSE);

			}
			else {

				m_gajeni++;
				if (m_gajeni % 2 == 0 && speletais == 0) {
					tryyt = (_T("End dators vine"));
					MessageBox(_T("Dators Uzvareja"), _T("Neveicas"), MB_ICONEXCLAMATION);
				}
				else {
					if (m_gajeni % 2 != 0 && speletais != 0) {
						tryyt = (_T("End dators vine"));
						MessageBox(_T("Dators Uzvareja"), _T("Neveicas"), MB_ICONEXCLAMATION);
					}
					else {
						tryyt = (_T("End speletais vine"));
						MessageBox(_T("Tu Uzvarei"), _T("Wow Paveicas"), MB_ICONEXCLAMATION);
					}

				}
				m_Area = 0;
				m_Min5 = 0;
				m_Dal3 = 0;
				m_Dal2 = 0;
				UpdateData(FALSE);
			}
		}
		else {


			if (m_gajeni % 2 == 0 && speletais == 0) {
				tryyt = (_T("End dators vine"));
				MessageBox(_T("Dators Uzvareja"), _T("Neveicas"), MB_ICONEXCLAMATION);
			}
			else {
				if (m_gajeni % 2 != 0 && speletais != 0) {
					tryyt = (_T("End dators vine"));
					MessageBox(_T("Dators Uzvareja"), _T("Neveicas"), MB_ICONEXCLAMATION);
				}
				else {
					tryyt = (_T("End speletais vine"));
					MessageBox(_T("Tu Uzvarei"), _T("Wow Paveicas"), MB_ICONEXCLAMATION);
				}

			}
			m_Area = 0;
			m_Min5 = 0;
			m_Dal3 = 0;
			m_Dal2 = 0;
			UpdateData(FALSE);
		}
	}
}


void CGameBetaDlg::OnBnClickedBut5()
{
	// Speletaja Gajens
	if (m_Area > 0) {
		m_Area = m_Area - 5;
		if (m_gajeni % 2 == 0) {
			m_spel1 = m_Area;
		}
		else {
			m_spel2 = m_Area;
		}
		if (m_Area > 5) {
			if (m_Area % 2 == 0) {
				m_Dal2 = m_Area / 2;
				m_str_dal2 = (_T("Var"));
			}
			else {
				m_str_dal2 = (_T("Nevar sadalit"));
				m_Dal2 = 0;
			}
			if (m_Area % 3 == 0) {
				m_str_dal3 = (_T("Var"));
				m_Dal3 = m_Area / 3;
			}
			else {
				m_str_dal3 = (_T("Nevar sadalit"));
				m_Dal3 = 0;
			}
			m_Min5 = m_Area - 5;
			m_str_min5 = (_T("Var"));
			m_gajeni++;
			UpdateData(FALSE);

		}
		else {

			m_gajeni++;
			if (m_gajeni % 2 == 0 && speletais == 0) {
				tryyt = (_T("End dators vine"));
				//MessageBox(_T("Dators Uzvareja"), _T("Neveicas"), MB_ICONEXCLAMATION);
			}
			else {
				if (m_gajeni % 2 != 0 && speletais != 0) {
					tryyt = (_T("End dators vine"));
					//MessageBox(_T("Dators Uzvareja"), _T("Neveicas"), MB_ICONEXCLAMATION);
				}
				else {
					tryyt = (_T("End speletais vine"));
					MessageBox(_T("Tu Uzvarei"), _T("Wow Paveicas"), MB_ICONEXCLAMATION);
				}

			}
			m_Area = 0;
			m_Min5 = 0;
			m_Dal3 = 0;
			m_Dal2 = 0;
			UpdateData(FALSE);
		}
		//datora gajens
		if (m_Area > 5) {
			m_Area = (logika(m_Area));
			if (m_gajeni % 2 == 0) {
				m_spel1 = m_Area;
			}
			else {
				m_spel2 = m_Area;
			}
			if (m_Area > 5) {
				if (m_Area % 2 == 0) {
					m_Dal2 = m_Area / 2;
					m_str_dal2 = (_T("Var"));
					UpdateData(FALSE);
				}
				else {
					m_str_dal2 = (_T("Nevar sadalit"));
					m_Dal2 = 0;
				}
				if (m_Area % 3 == 0) {
					m_str_dal3 = (_T("Var"));
					UpdateData(FALSE);
					m_Dal3 = m_Area / 3;
				}
				else {
					m_str_dal3 = (_T("Nevar sadalit"));
					m_Dal3 = 0;
				}
				m_Min5 = m_Area - 5;
				m_str_min5 = (_T("Var"));
				
				m_gajeni++;
				UpdateData(FALSE);

			}
			else {

				m_gajeni++;
				if (m_gajeni % 2 == 0 && speletais == 0) {
					tryyt = (_T("End dators vine"));
					MessageBox(_T("Dators Uzvareja"), _T("Neveicas"), MB_ICONEXCLAMATION);
				}
				else {
					if (m_gajeni % 2 != 0 && speletais != 0) {
						tryyt = (_T("End dators vine"));
						MessageBox(_T("Dators Uzvareja"), _T("Neveicas"), MB_ICONEXCLAMATION);
					}
					else {
						tryyt = (_T("End speletais vine"));
						MessageBox(_T("Tu Uzvarei"), _T("Wow Paveicas"), MB_ICONEXCLAMATION);
					}

				}
				m_Area = 0;
				m_Min5 = 0;
				m_Dal3 = 0;
				m_Dal2 = 0;
				UpdateData(FALSE);
			}
		}
		else {


			if (m_gajeni % 2 == 0 && speletais == 0) {
				tryyt = (_T("End dators vine"));
				MessageBox(_T("Dators Uzvareja"), _T("Neveicas"), MB_ICONEXCLAMATION);
			}
			else {
				if (m_gajeni % 2 != 0 && speletais != 0) {
					tryyt = (_T("End dators vine"));
					MessageBox(_T("Dators Uzvareja"), _T("Neveicas"), MB_ICONEXCLAMATION);
				}
				else {
					tryyt = (_T("End speletais vine"));
					MessageBox(_T("Tu Uzvarei"), _T("Wow Paveicas"), MB_ICONEXCLAMATION);
				}

			}
			m_Area = 0;
			m_Min5 = 0;
			m_Dal3 = 0;
			m_Dal2 = 0;
			UpdateData(FALSE);
		}
	}
}





void CGameBetaDlg::OnEnChangeEdit6()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	//m_koks2 = "asdasd";
	// TODO:  Добавьте код элемента управления
}


void CGameBetaDlg::OnEnChangeEdit7()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	m_kokss = (_T(""));
	UpdateData(FALSE);
	// TODO:  Добавьте код элемента управления
}


void CGameBetaDlg::OnBnClickedButton4()
{
	//Restart kur iesaka speli Dators
	UpdateData(TRUE);
	m_Area = m_Start;
	tryyt = (_T(""));
	speletais=0;
	m_1_S_aile = (_T("Dators:"));
	m_2_S_aile = (_T("Speletais:"));
	m_gajeni = 0;
	m_Min5 = m_Area - 5;
	m_Dal3 = m_Area / 3;
	m_Dal2 = m_Area / 2;
	UpdateData(FALSE);


	m_Area=(logika(m_Area));
	if (m_gajeni % 2 == 0) {
		m_spel1 = m_Area;
	}
	else {
		m_spel2 = m_Area;
	}
	if (m_Area > 5) {
		if (m_Area % 2 == 0) {
			m_Dal2 = m_Area / 2;
			m_str_dal2 = (_T("Var"));
		}
		else {
			m_str_dal2 = (_T("Nevar sadalit"));
			m_Dal2 = 0;
		}
		if (m_Area % 3 == 0) {
			m_str_dal3 = (_T("Var"));
			m_Dal3 = m_Area / 3;
		}
		else {
			m_str_dal3 = (_T("Nevar sadalit"));
			m_Dal3 = 0;
		}
		m_Min5 = m_Area - 5;
		m_str_min5 = (_T("Var"));

		m_gajeni++;
		UpdateData(FALSE);

	}
	else {

		m_gajeni++;
		
		m_Area = 0;
		m_Min5 = 0;
		m_Dal3 = 0;
		m_Dal2 = 0;
		UpdateData(FALSE);
	}
	
}


void CGameBetaDlg::OnEnChangeEdit2()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}


void CGameBetaDlg::OnEnChangeEdit5()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}


void CGameBetaDlg::OnBnClickedRestart()
{
	//Restart kur iesaka speli Speletais
	UpdateData(TRUE);
	m_Area = m_Start;
	speletais = 1;
	m_2_S_aile = (_T("Dators:"));
	m_1_S_aile = (_T("Speletais:"));
	tryyt = (_T(""));
	m_gajeni=0;
	m_Min5 = m_Area-5;
	m_Dal3 = m_Area/3;
	m_Dal2 = m_Area/2;
	m_spel1 = 0;
	m_spel2 = 0;
	UpdateData(FALSE);
	
}


void CGameBetaDlg::OnEnChangeEdit3()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}


void CGameBetaDlg::OnEnChangeEdit4()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}


void CGameBetaDlg::OnBnClickedButton2()
{
	//Koka saglabašana koks.txt FAILA
	UpdateData(TRUE);
	map<int, set<int>> Koks2;
	revers("koks.txt", m_Area, test(Koks2, m_Start));
	

}

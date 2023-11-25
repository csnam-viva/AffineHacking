
// AffineHackingDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "AffineHacking.h"
#include "AffineHackingDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


int inver(int key1, int mod);

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CAffineHackingDlg 대화 상자



CAffineHackingDlg::CAffineHackingDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_AFFINEHACKING_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAffineHackingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAffineHackingDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CAffineHackingDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CAffineHackingDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CAffineHackingDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_RSA_DH, &CAffineHackingDlg::OnBnClickedRsaDh)
END_MESSAGE_MAP()


	// CAffineHackingDlg 메시지 처리기

	BOOL CAffineHackingDlg::OnInitDialog()
	{
		CDialogEx::OnInitDialog();

		// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

		// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

		// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
		//  프레임워크가 이 작업을 자동으로 수행합니다.
		SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
		SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

		// TODO: 여기에 추가 초기화 작업을 추가합니다.

		return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
	}

	void CAffineHackingDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

	// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
	//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
	//  프레임워크에서 이 작업을 자동으로 수행합니다.

	void CAffineHackingDlg::OnPaint()
	{
		if (IsIconic())
		{
			CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

			SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

			// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
			int cxIcon = GetSystemMetrics(SM_CXICON);
			int cyIcon = GetSystemMetrics(SM_CYICON);
			CRect rect;
			GetClientRect(&rect);
			int x = (rect.Width() - cxIcon + 1) / 2;
			int y = (rect.Height() - cyIcon + 1) / 2;

			// 아이콘을 그립니다.
			dc.DrawIcon(x, y, m_hIcon);
		}
		else
		{
			CDialogEx::OnPaint();
		}
	}

	// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
	//  이 함수를 호출합니다.
	HCURSOR CAffineHackingDlg::OnQueryDragIcon()
	{
		return static_cast<HCURSOR>(m_hIcon);
	}



	void CAffineHackingDlg::OnBnClickedButton1()
	{
		int x;
		int y;
		for ( x = 1; x < 100; x++)
		{
			for (y = 0; y < 100; y++) 
			{

				if (((14 * x + y) % 26) == 10)
				{
					TRACE("A: %d  %d\n", x, y);
				}
				if (((15 * x + y) % 26) == 13)
				{
					TRACE("B: %d  %d\n", x, y);
				}
				if (((18 * x + y) % 26) == 22)
				{
					TRACE("C: %d  %d\n", x, y);
				}
			}
		}
	}



	void CAffineHackingDlg::OnBnClickedButton2()
	{
		int  a1 = inver(3, 26);
		TRACE("a1 = %d\n", a1);
		//BKFG  01, 10, 05, 06  
		int s1[4] = { 01,10, 05,06 };
		int k1 = 3;
		int k2 = 20;

		for (int i = 0; i< 4; i++)
		{
			 /*int p1 = (s1[i] - k2) * ( 1 / pow(k1,abs(-1)) ) % 26;*/

			if ((s1[i] - k2) < 0) 
					s1[i] += 26;
			 int p1 = (s1[i] - k2) * a1 % 26;
			 TRACE(" %d, %d, %d   \n",  s1[i], a1, p1);

		}
		
		

	}

	int inver(int key1, int mod)
		//곱셈 암호를 복호화 해주기 위해 함수의 역함수 a를 26과 서로소인 수이며 a^-1*a(mod26)=1을 만들어주기 위해 선언한 함수
	{
		int i;
		for (i = 1; i <= 25; i += 2)//i는 1에서 25까지 홀수번호로 올라감.key1을 입력을 26과 서로소인 수(13을 제외한 홀수)를 입력하기 때문에 홀수로 받음.(mod26이 1이 나오게 하기 위해)
			if (key1 * i % mod == 1)
				break; // i가 a^-1*a(mod26)=1이 될 때 까지 반복 후 탈출
		return i; //이 때의 i 값을 반환
	}

	void CAffineHackingDlg::OnBnClickedButton3()
	{
		float durigMin = pow(2, 32) / pow(10, 7);
		TRACE("durigMin sec %5.2f  min=  %5.2f \n", durigMin, durigMin /60);

		float durigMin2 = pow(2, 64) / pow(10, 7);
		TRACE("durigMin2 sec %5.2f  min=  %5.2f\n", durigMin2, durigMin2 / (60*60*24*365));
	}


	void CAffineHackingDlg::OnBnClickedRsaDh()
	{
		
		int r = 2;
		int p = 11;

		for (int b = 0; b < 20; b++)
		{
			double result = pow(r, b);
			if ((int)pow(r, b) % p == 3 )
			{
				TRACE("-------------------------------------\n");
				TRACE("b%02d:  pow(%d, %d) mod %d = %d , %5.0f \n", b, r, b, p, (int)result % p, result);
				TRACE("-------------------------------------\n");
			}
			else {
				
				TRACE("b%02d:  pow(%d, %d) mod %d = %d , %5.0f \n", b, r, b, p, (int)result % p, result);
			}
			


		}

	}

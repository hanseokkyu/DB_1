
// DB_1Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "DB_1.h"
#include "DB_1Dlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDB_1Dlg 대화 상자




CDB_1Dlg::CDB_1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDB_1Dlg::IDD, pParent)
	, exam_combo_value(_T(""))			// exam value 값 저장
	, pos_combo_value(_T(""))			//pos value 값 저장
	, child_aec_value(_T(""))			//child_aec 값 저장
	, small_aec_value(_T(""))			//small_aec_value 값 저장
	, med_aec_value(_T(""))				//med_aec_value 값 저장	
	, large_aec_value(_T(""))			//large_aec_value 값 저장	
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_nxGenId = 0;
}

void CDB_1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_EDIT13, m_path);
	DDX_Control(pDX, IDC_COMBO1, exam_1);
	DDX_Control(pDX, IDC_COMBO2, pos_1);
	DDX_CBString(pDX, IDC_COMBO1, exam_combo_value);
	DDX_CBString(pDX, IDC_COMBO2, pos_combo_value);
	DDX_Control(pDX, IDC_COMBO3, child_aec_combo);
	DDX_Control(pDX, IDC_COMBO4, small_aec_combo);
	DDX_Control(pDX, IDC_COMBO5, med_aec_combo);
	DDX_Control(pDX, IDC_COMBO6, large_aec_combo);
	DDX_Control(pDX, IDC_EDIT1, child_kv_edit);
	DDX_Control(pDX, IDC_EDIT2, child_ma_edit);
	DDX_Control(pDX, IDC_EDIT3, child_time_edit);
	DDX_Control(pDX, IDC_EDIT4, small_kv_edit);
	DDX_Control(pDX, IDC_EDIT5, small_ma_edit);
	DDX_Control(pDX, IDC_EDIT6, small_time_edit);
	DDX_Control(pDX, IDC_EDIT7, med_kv_edit);
	DDX_Control(pDX, IDC_EDIT8, med_ma_edit);
	DDX_Control(pDX, IDC_EDIT9, med_time_edit);
	DDX_Control(pDX, IDC_EDIT11, large_ma_edit);
	DDX_Control(pDX, IDC_EDIT10, large_kv_edit);
	DDX_Control(pDX, IDC_EDIT12, large_time_edit);
	DDX_CBString(pDX, IDC_COMBO3, child_aec_value);
	DDX_CBString(pDX, IDC_COMBO4, small_aec_value);
	DDX_CBString(pDX, IDC_COMBO5, med_aec_value);
	DDX_CBString(pDX, IDC_COMBO6, large_aec_value);
	DDX_Control(pDX, IDC_CHECK1, child_field_1);
	DDX_Control(pDX, IDC_CHECK2, child_field_2);
	DDX_Control(pDX, IDC_CHECK3, child_field_3);
	DDX_Control(pDX, IDC_CHECK4, small_field_1);
	DDX_Control(pDX, IDC_CHECK5, small_field_2);
	DDX_Control(pDX, IDC_CHECK6, small_field_3);
	DDX_Control(pDX, IDC_CHECK7, med_field_1);
	DDX_Control(pDX, IDC_CHECK8, med_field_2);
	DDX_Control(pDX, IDC_CHECK9, med_field_3);
	DDX_Control(pDX, IDC_CHECK10, large_field_1);
	DDX_Control(pDX, IDC_CHECK11, large_field_2);
	DDX_Control(pDX, IDC_CHECK12, large_field_3);
}

BEGIN_MESSAGE_MAP(CDB_1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CDB_1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDB_1Dlg::OnBnClickedButton2)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CDB_1Dlg::OnCbnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CDB_1Dlg::OnCbnSelchangeCombo2)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_RADIO1, IDC_RADIO2, &CDB_1Dlg::detCh)
	ON_CBN_SELCHANGE(IDC_COMBO3, &CDB_1Dlg::OnCbnSelchangeCombo3)
	ON_CBN_SELCHANGE(IDC_COMBO4, &CDB_1Dlg::OnCbnSelchangeCombo4)
	ON_CBN_SELCHANGE(IDC_COMBO5, &CDB_1Dlg::OnCbnSelchangeCombo5)
	ON_CBN_SELCHANGE(IDC_COMBO6, &CDB_1Dlg::OnCbnSelchangeCombo6)
END_MESSAGE_MAP()


// CDB_1Dlg 메시지 처리기

BOOL CDB_1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_pDb = new DXDBSqlite;     //  생성
	m_pAprDb = new DXDBSqlite;	//	생성


	child_aec_combo.InsertString(0,"OFF");		
	child_aec_combo.InsertString(0,"ON");
	child_aec_combo.SetCurSel(0);
	
	
	small_aec_combo.InsertString(0,"OFF");
	small_aec_combo.InsertString(0,"ON");
	small_aec_combo.SetCurSel(0);

	med_aec_combo.InsertString(0,"OFF");
	med_aec_combo.InsertString(0,"ON");
	med_aec_combo.SetCurSel(0);
	
	large_aec_combo.InsertString(0,"OFF");
	large_aec_combo.InsertString(0,"ON");
	large_aec_combo.SetCurSel(0);



	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}



void CDB_1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CDB_1Dlg::OnPaint()
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
HCURSOR CDB_1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CDB_1Dlg::ConnectDB()      //   db 연결
{
	CString str;
	if (m_pDb->Connect(strFolderPath, NULL, NULL))
    {
		m_bDBConnect = TRUE;
		str = "Exam DB connect \r\n";
	}
	else
	{
		m_bDBConnect = FALSE;
		str.Format("Exam DB disconnect \r\n", strFolderPath);
	}
	AfxMessageBox(str);
}


void CDB_1Dlg::OnBnClickedButton1()			//db 경로 찾기 버튼 클릭
{
	CString  wc;
	Pos		ppos;
	Pos_exam ppos_exam;
	CString str;

	m_strDBPath = "D:";			//폴더 경로 지정
	CFolderPickerDialog Picker(m_strDBPath, OFN_FILEMUSTEXIST, NULL, 0);
	if (Picker.DoModal() == IDOK)
	{
		strFolderPath = Picker.GetPathName();		//선택시 경로 변경
	}
	strFolderPath = strFolderPath + "\\exam.db";		//경로에 db폴더 추가
	m_path.SetWindowTextA(strFolderPath);
	ConnectDB();		//  db 연결
	exam_combox();		//exam 콤보상자에 exam값 추가
	

}

void CDB_1Dlg::pos_id()				//exam값과 pos 갑에 해당하는 id값 출력
{
	CString  wc;
	Pos		ppos;
	CString str;
	try
	{
		wc.Format("WHERE exam='%s' AND pos='%s'", exam_value, pos_value);		
		m_pDb->queryPos_id(wc, &ppos);	//exam값과 pos 값에 해당하는 값  출력
	}
	catch (CString& )
   {
	  str.Format("%s",pos_value);
	  AfxMessageBox(str);
   }
	pos_id_value = ppos.id;				//exam과 pos에 해당하는 값에  id값 출력

}

void CDB_1Dlg::exam_combox()				//exam   콤보상자 값 추가
{
	CString  wc;
	Pos_exam ppos_exam;
	CString str;

	try
	{
		m_pDb->queryPos_exam(wc, &ppos_exam);		//exam 값 Pos_exam구조체에 복사
		exam_1.InsertString(0,ppos_exam.exam51);		//exam  값 추가하는 부분
		exam_1.InsertString(0,ppos_exam.exam50);
		exam_1.InsertString(0,ppos_exam.exam49);
		exam_1.InsertString(0,ppos_exam.exam48);
		exam_1.InsertString(0,ppos_exam.exam47);
		exam_1.InsertString(0,ppos_exam.exam46);
		exam_1.InsertString(0,ppos_exam.exam45);
		exam_1.InsertString(0,ppos_exam.exam44);
		exam_1.InsertString(0,ppos_exam.exam43);
		exam_1.InsertString(0,ppos_exam.exam42);
		exam_1.InsertString(0,ppos_exam.exam41);
		exam_1.InsertString(0,ppos_exam.exam40);
		exam_1.InsertString(0,ppos_exam.exam39);
		exam_1.InsertString(0,ppos_exam.exam38);
		exam_1.InsertString(0,ppos_exam.exam37);
		exam_1.InsertString(0,ppos_exam.exam36);
		exam_1.InsertString(0,ppos_exam.exam35);
		exam_1.InsertString(0,ppos_exam.exam34);
		exam_1.InsertString(0,ppos_exam.exam33);
		exam_1.InsertString(0,ppos_exam.exam32);
		exam_1.InsertString(0,ppos_exam.exam31);
		exam_1.InsertString(0,ppos_exam.exam30);
		exam_1.InsertString(0,ppos_exam.exam29);
		exam_1.InsertString(0,ppos_exam.exam28);
		exam_1.InsertString(0,ppos_exam.exam27);
		exam_1.InsertString(0,ppos_exam.exam26);
		exam_1.InsertString(0,ppos_exam.exam25);
		exam_1.InsertString(0,ppos_exam.exam24);
		exam_1.InsertString(0,ppos_exam.exam23);
		exam_1.InsertString(0,ppos_exam.exam22);
		exam_1.InsertString(0,ppos_exam.exam21);
		exam_1.InsertString(0,ppos_exam.exam20);
		exam_1.InsertString(0,ppos_exam.exam19);
		exam_1.InsertString(0,ppos_exam.exam18);
		exam_1.InsertString(0,ppos_exam.exam17);
		exam_1.InsertString(0,ppos_exam.exam16);
		exam_1.InsertString(0,ppos_exam.exam15);
		exam_1.InsertString(0,ppos_exam.exam14);
		exam_1.InsertString(0,ppos_exam.exam13);
		exam_1.InsertString(0,ppos_exam.exam12);
		exam_1.InsertString(0,ppos_exam.exam11);
		exam_1.InsertString(0,ppos_exam.exam10);
		exam_1.InsertString(0,ppos_exam.exam9);
		exam_1.InsertString(0,ppos_exam.exam8);
		exam_1.InsertString(0,ppos_exam.exam7);
		exam_1.InsertString(0,ppos_exam.exam6);
		exam_1.InsertString(0,ppos_exam.exam5);
		exam_1.InsertString(0,ppos_exam.exam4);
		exam_1.InsertString(0,ppos_exam.exam3);
		exam_1.InsertString(0,ppos_exam.exam2);
		exam_1.InsertString(0,ppos_exam.exam1);


	}
	catch (CString& )			//연결 안될때 ex) sql문 오류시
   {
	   str.Format("disconnct");
	   AfxMessageBox(str);
   }
	
}


void CDB_1Dlg::pos_combox()			//exam값에 맞는pos 콤보상자 값 추가
{
	CString  wc;
	Pos_pos ppos_pos;
	CString str;

	try
	{
		wc.Format("WHERE exam='%s'", exam_value);		//sql문에 저장
		m_pDb->queryPos_pos(wc, &ppos_pos);				//pos 값 Pos_pos에 저장
		pos_1.ResetContent();			// 콤보상자 값 초기화
		if(ppos_pos.pos10 != "")								//값 존재 안할시 종료
			pos_1.InsertString(0,ppos_pos.pos10);			//pos 값 추가하는 부분
		if(ppos_pos.pos9 != "")
			pos_1.InsertString(0,ppos_pos.pos9);
		if(ppos_pos.pos8 != "")
			pos_1.InsertString(0,ppos_pos.pos8);
		if(ppos_pos.pos7 != "")
			pos_1.InsertString(0,ppos_pos.pos7);
		if(ppos_pos.pos6 != "")
			pos_1.InsertString(0,ppos_pos.pos6);
		if(ppos_pos.pos5 != "")
			pos_1.InsertString(0,ppos_pos.pos5);
		if(ppos_pos.pos4 != "")
			pos_1.InsertString(0,ppos_pos.pos4);
		if(ppos_pos.pos3 != "")
			pos_1.InsertString(0,ppos_pos.pos3);
		if(ppos_pos.pos2 != "")
			pos_1.InsertString(0,ppos_pos.pos2);
		if(ppos_pos.pos1 != "")
			pos_1.InsertString(0,ppos_pos.pos1);
	}
	catch (CString& )
   {
	  str.Format("disconnct");
	  AfxMessageBox(str);
   }
}

void CDB_1Dlg::OnBnClickedButton2()				//update 과정
{

	UINT nCheck1 = child_field_1.GetState();		// aec_field_child_field값 상태
	UINT nCheck2 = child_field_2.GetState();		
	UINT nCheck3 = child_field_3.GetState();

	UINT nCheck4 = small_field_1.GetState();		// aec_field_small_field값 상태
	UINT nCheck5 = small_field_2.GetState();
	UINT nCheck6 = small_field_3.GetState();

	UINT nCheck7 = med_field_1.GetState();			// aec_field_med_field값 상태
	UINT nCheck8 = med_field_2.GetState();
	UINT nCheck9 = med_field_3.GetState();

	UINT nCheck10 = large_field_1.GetState();		// aec_field_large_field값 상태
	UINT nCheck11 = large_field_2.GetState();
	UINT nCheck12 = large_field_3.GetState();

	if(nCheck1 == BST_CHECKED && nCheck2 == BST_CHECKED && nCheck3 == BST_CHECKED)		//child다 클릭
	{
		child_field_value = "111";
	}
	else if(nCheck1 == BST_UNCHECKED && nCheck2 == BST_UNCHECKED && nCheck3 == BST_UNCHECKED)	//child다 클릭  x
	{
		child_field_value = "000";
	}
	else if(nCheck1 == BST_UNCHECKED && nCheck2 == BST_UNCHECKED && nCheck3 == BST_CHECKED)	//child다 클릭  x
	{
		child_field_value = "001";
	}
	else if(nCheck1 == BST_CHECKED && nCheck2 == BST_UNCHECKED && nCheck3 == BST_UNCHECKED)	//child2,3번 클릭 x
	{
		child_field_value = "010";
	}
	else if(nCheck1 == BST_UNCHECKED && nCheck2 == BST_CHECKED && nCheck3 == BST_UNCHECKED)	//child다 클릭  x
	{
		child_field_value = "100";
	}
	else if(nCheck1 == BST_CHECKED && nCheck2 == BST_CHECKED && nCheck3 == BST_UNCHECKED)	//child3번 클릭 x
	{
		child_field_value = "110";
	}
	else if(nCheck1 == BST_CHECKED && nCheck2 == BST_UNCHECKED && nCheck3 == BST_CHECKED)	//child3번 클릭 x
	{
		child_field_value = "011";
	}
	else if(nCheck1 == BST_UNCHECKED && nCheck2 == BST_CHECKED && nCheck3 == BST_CHECKED)	//child3번 클릭 x
	{
		child_field_value = "101";
	}
	
	if(nCheck4 == BST_CHECKED && nCheck5 == BST_CHECKED && nCheck6 == BST_CHECKED)		//child다 클릭
	{
		small_field_value = "111";
	}
	else if(nCheck4 == BST_UNCHECKED && nCheck5 == BST_UNCHECKED && nCheck6 == BST_UNCHECKED)	//child다 클릭  x
	{
		small_field_value = "000";
	}
	else if(nCheck4 == BST_UNCHECKED && nCheck5 == BST_UNCHECKED && nCheck6 == BST_CHECKED)	//child다 클릭  x
	{
		small_field_value = "001";
	}
	else if(nCheck4 == BST_CHECKED && nCheck5 == BST_UNCHECKED && nCheck6 == BST_UNCHECKED)	//child2,3번 클릭 x
	{
		small_field_value = "010";
	}
	else if(nCheck4 == BST_UNCHECKED && nCheck5 == BST_CHECKED && nCheck6 == BST_UNCHECKED)	//child다 클릭  x
	{
		small_field_value = "100";
	}
	else if(nCheck4 == BST_CHECKED && nCheck5 == BST_CHECKED && nCheck6 == BST_UNCHECKED)	//child3번 클릭 x
	{
		small_field_value = "110";
	}
	else if(nCheck4 == BST_CHECKED && nCheck5 == BST_UNCHECKED && nCheck6 == BST_CHECKED)	//child3번 클릭 x
	{
		small_field_value = "011";
	}
	else if(nCheck4 == BST_UNCHECKED && nCheck5 == BST_CHECKED && nCheck6 == BST_CHECKED)	//child3번 클릭 x
	{
		small_field_value = "101";
	}

	if(nCheck7 == BST_CHECKED && nCheck8 == BST_CHECKED && nCheck9 == BST_CHECKED)		//child다 클릭
	{
		med_field_value = "111";
	}
	else if(nCheck7 == BST_UNCHECKED && nCheck8 == BST_UNCHECKED && nCheck9 == BST_UNCHECKED)	//child다 클릭  x
	{
		med_field_value = "000";
	}
	else if(nCheck7 == BST_UNCHECKED && nCheck8 == BST_UNCHECKED && nCheck9 == BST_CHECKED)	//child다 클릭  x
	{
		med_field_value = "001";
	}
	else if(nCheck7 == BST_CHECKED && nCheck8 == BST_UNCHECKED && nCheck9 == BST_UNCHECKED)	//child2,3번 클릭 x
	{
		med_field_value = "010";
	}
	else if(nCheck7 == BST_UNCHECKED && nCheck8 == BST_CHECKED && nCheck9 == BST_UNCHECKED)	//child다 클릭  x
	{
		med_field_value = "100";
	}
	else if(nCheck7 == BST_CHECKED && nCheck8 == BST_CHECKED && nCheck9 == BST_UNCHECKED)	//child3번 클릭 x
	{
		med_field_value = "110";
	}
	else if(nCheck7 == BST_CHECKED && nCheck8 == BST_UNCHECKED && nCheck9 == BST_CHECKED)	//child3번 클릭 x
	{
		med_field_value = "011";
	}
	else if(nCheck7 == BST_UNCHECKED && nCheck8 == BST_CHECKED && nCheck9 == BST_CHECKED)	//child3번 클릭 x
	{
		med_field_value = "101";
	}

	if(nCheck10 == BST_CHECKED && nCheck11 == BST_CHECKED && nCheck12 == BST_CHECKED)		//child다 클릭
	{
		large_field_value = "111";
	}
	else if(nCheck10 == BST_UNCHECKED && nCheck11 == BST_UNCHECKED && nCheck12 == BST_UNCHECKED)	//child다 클릭  x
	{
		large_field_value = "000";
	}
	else if(nCheck10 == BST_UNCHECKED && nCheck11 == BST_UNCHECKED && nCheck12 == BST_CHECKED)	//child다 클릭  x
	{
		large_field_value = "001";
	}
	else if(nCheck10 == BST_CHECKED && nCheck11 == BST_UNCHECKED && nCheck12 == BST_UNCHECKED)	//child2,3번 클릭 x
	{
		large_field_value = "010";
	}
	else if(nCheck10 == BST_UNCHECKED && nCheck11 == BST_CHECKED && nCheck12 == BST_UNCHECKED)	//child다 클릭  x
	{
		large_field_value = "100";
	}
	else if(nCheck10 == BST_CHECKED && nCheck11 == BST_CHECKED && nCheck12 == BST_UNCHECKED)	//child3번 클릭 x
	{
		large_field_value = "110";
	}
	else if(nCheck10 == BST_CHECKED && nCheck11 == BST_UNCHECKED && nCheck12 == BST_CHECKED)	//child3번 클릭 x
	{
		large_field_value = "011";
	}
	else if(nCheck10 == BST_UNCHECKED && nCheck11 == BST_CHECKED && nCheck12 == BST_CHECKED)	//child3번 클릭 x
	{
		large_field_value = "101";
	}

	update();			//값 업데이트 하기

}



void CDB_1Dlg::OnCbnSelchangeCombo1()			//exam값 변경하기
{
	UpdateData();
	exam_value = exam_combo_value;
	CString str;
	pos_combox();			//exam값에 맞는pos 콤보상자 값 추가
}


void CDB_1Dlg::detCh(UINT uID)			//detch값 변경하기
{

	switch (uID)				
	{
		case IDC_RADIO1:
			detCh_change = "T";
			break;
		case IDC_RADIO2:
			detCh_change = "W";
			break;
	}

}

void CDB_1Dlg::update()					//값 업데이트 하기
{
	CString str;
	XGen     xGen1;			//child
	XGen     xGen2;			//small
	XGen     xGen3;			//med
	XGen     xGen4;			//large
	CString  wc;
	wc.Format("");		//sql
	m_pDb->queryXGen(wc, &xGen1);       //generator XGen값 저장



	child_kv_edit.GetWindowTextA(kv_change1);		//child_edit box에 값 입력
	child_ma_edit.GetWindowTextA(ma_change1);
	child_time_edit.GetWindowTextA(time_change1);

	small_kv_edit.GetWindowTextA(kv_change2);		//small_edit box에 값 입력
	small_ma_edit.GetWindowTextA(ma_change2);
	small_time_edit.GetWindowTextA(time_change2);

	med_kv_edit.GetWindowTextA(kv_change3);			//med_edit box에 값 입력
	med_ma_edit.GetWindowTextA(ma_change3);
	med_time_edit.GetWindowTextA(time_change3);

	large_kv_edit.GetWindowTextA(kv_change4);		//large_edit box에 값 입력
	large_ma_edit.GetWindowTextA(ma_change4);
	large_time_edit.GetWindowTextA(time_change4);
	

	xGen1.detCh.Format("%s",detCh_change);
	xGen1.kVp.Format("%s",kv_change1);				//저장 부분
	xGen1.tubeCurmA.Format("%s",ma_change1);		//저장 부분
	xGen1.expTimems.Format("%s",time_change1);		//저장 부분
	xGen1.expmAs.Format("%s",child_expmAs_value);	
	xGen1.AEC.Format("%s",child_aec_combo_value);	
	xGen1.AECField.Format("%s",child_field_value);	
	xGen1.AECDens.Format("%s",child_AECDens_value);
	xGen1.AECScr.Format("%s",child_AECScr_value);
	xGen1.posId.Format("%s",xGen1.posId);


	xGen2.detCh.Format("%s",detCh_change);
	xGen2.kVp.Format("%s",kv_change2);				//저장 부분
	xGen2.tubeCurmA.Format("%s",ma_change2);		//저장 부분
	xGen2.expTimems.Format("%s",time_change2);		//저장 부분
	xGen2.expmAs.Format("%s",med_expmAs_value);	
	xGen2.AEC.Format("%s",small_aec_combo_value);
	xGen2.AECField.Format("%s",small_field_value);
	xGen2.AECDens.Format("%s",small_AECDens_value);
	xGen2.AECScr.Format("%s",small_AECScr_value);
	xGen2.posId.Format("%s",xGen1.posId);

	xGen3.detCh.Format("%s",detCh_change);
	xGen3.kVp.Format("%s",kv_change3);				//저장 부분
	xGen3.tubeCurmA.Format("%s",ma_change3);		//저장 부분
	xGen3.expTimems.Format("%s",time_change3);		//저장 부분
	xGen3.expmAs.Format("%s",med_expmAs_value);	
	xGen3.AEC.Format("%s",med_aec_combo_value);
	xGen3.AECField.Format("%s",med_field_value);
	xGen3.AECDens.Format("%s",med_AECDens_value);
	xGen3.AECScr.Format("%s",med_AECScr_value);
	xGen3.posId.Format("%s",xGen1.posId);

	xGen4.detCh.Format("%s",detCh_change);
	xGen4.kVp.Format("%s",kv_change4);				//저장 부분
	xGen4.tubeCurmA.Format("%s",ma_change4);		//저장 부분
	xGen4.expTimems.Format("%s",time_change4);		//저장 부분
	xGen4.expmAs.Format("%s",large_expmAs_value);	
	xGen4.AEC.Format("%s",large_aec_combo_value);
	xGen4.AECField.Format("%s",large_field_value);
	xGen4.AECDens.Format("%s",large_AECDens_value);
	xGen4.AECScr.Format("%s",large_AECScr_value);
	xGen4.posId.Format("%s",xGen1.posId);

	try 
   {
	   m_pDb->updateGenerator_L(&xGen4);		// large값 업데이트
	   m_pDb->updateGenerator_M(&xGen3);		// med값 업데이트
	   m_pDb->updateGenerator_S(&xGen2);		// small값 업데이트
	   m_pDb->updateGenerator_C(&xGen1);		// child값 업데이트
	   
	   
	   
	  
	  
	  str.Format("update");		
	  AfxMessageBox(str);

   }
   catch (CString& )
   {
	  str.Format("not update");
	  AfxMessageBox(str);
   }

}

void CDB_1Dlg::gener()			//pos 콤보상자 값
{
	
	pCheck1 =(CButton *)GetDlgItem(IDC_RADIO1);
	pCheck2 =(CButton *)GetDlgItem(IDC_RADIO2);

	CString  wc;
	CString  aec_combo;
	CString str;
	XGen     xGen;
	CString bSize = "M";			//초기설정값
	try
	{
		wc.Format("WHERE posId='%s'", pos_id_value);    //id는 일치하니까
		m_pDb->queryXGen(wc, &xGen);			//pos_id_value에 해당하는 c,s,m,l 불러오기
		for(int i = 0; i<4;i++)
		{
			wc.Format("WHERE bSize='%s' AND posId = '%s'", bSize,pos_id_value);		//m값과pos_id_value에 해당하는 값만 출력
			m_pDb->queryXGen(wc, &xGen);

			if(xGen.detCh == "T")				//detch 판별
			{
				detCh_change = "T";
				pCheck1->SetCheck(TRUE);
				pCheck2->SetCheck(FALSE);

			}
			else
			{
				detCh_change = "S";
				pCheck1->SetCheck(FALSE);
				pCheck2->SetCheck(TRUE);
			}

			if(bSize == "C")				//사이즈 판별
		{
			if(xGen.AEC == "1")				//aec 판별
			{
				child_aec_combo_value = "1";
				child_aec_combo.SetCurSel(0);
			}
			else
			{
				child_aec_combo_value = "0";
				child_aec_combo.SetCurSel(1);
			}
			if(xGen.AECField == "111")			//aec_field값 판별
			{
				child_field_1.SetCheck(1);
				child_field_2.SetCheck(1);
				child_field_3.SetCheck(1);
			}
			else if(xGen.AECField == "011")
			{
				child_field_1.SetCheck(1);
				child_field_2.SetCheck(0);
				child_field_3.SetCheck(1);
			}
			else if(xGen.AECField == "101")
			{
				child_field_1.SetCheck(0);
				child_field_2.SetCheck(1);
				child_field_3.SetCheck(1);
			}
			else if(xGen.AECField == "110")
			{
				child_field_1.SetCheck(1);
				child_field_2.SetCheck(1);
				child_field_3.SetCheck(0);
			}
			else if(xGen.AECField == "010")
			{
				child_field_1.SetCheck(1);
				child_field_2.SetCheck(0);
				child_field_3.SetCheck(0);
			}
			else if(xGen.AECField == "000")
			{
				child_field_1.SetCheck(0);
				child_field_2.SetCheck(0);
				child_field_3.SetCheck(0);
			}
			else if(xGen.AECField == "001")
			{
				child_field_1.SetCheck(0);
				child_field_2.SetCheck(0);
				child_field_3.SetCheck(1);
			}
			else if(xGen.AECField == "100")
			{
				child_field_1.SetCheck(0);
				child_field_2.SetCheck(1);
				child_field_3.SetCheck(0);
			}
			child_expmAs_value = xGen.expmAs;
			child_AECDens_value = xGen.AECDens;
			child_AECScr_value = xGen.AECScr;
			SetDlgItemText(IDC_EDIT1,xGen.kVp);				//값 출력하기
			SetDlgItemText(IDC_EDIT2,xGen.tubeCurmA);
			SetDlgItemText(IDC_EDIT3,xGen.expTimems);
			bSize = "S";
		}
			else if(bSize == "S")				//사이즈 판별	
		{
			if(xGen.AEC == "1")					//aec 판별
			{
				small_aec_combo_value = "1";
				small_aec_combo.SetCurSel(0);
			}
			else
			{
				small_aec_combo_value = "0";
				small_aec_combo.SetCurSel(1);
			}
			if(xGen.AECField == "111")			//aec_field값 판별
			{
				small_field_1.SetCheck(1);
				small_field_2.SetCheck(1);
				small_field_3.SetCheck(1);
			}
			else if(xGen.AECField == "101")
			{
				small_field_1.SetCheck(0);
				small_field_2.SetCheck(1);
				small_field_3.SetCheck(1);
			}
			else if(xGen.AECField == "110")
			{
				small_field_1.SetCheck(1);
				small_field_2.SetCheck(1);
				small_field_3.SetCheck(0);
			}
			else if(xGen.AECField == "010")
			{
				small_field_1.SetCheck(1);
				small_field_2.SetCheck(0);
				small_field_3.SetCheck(0);
			}
			else if(xGen.AECField == "000")
			{
				small_field_1.SetCheck(0);
				small_field_2.SetCheck(0);
				small_field_3.SetCheck(0);
			}
			else if(xGen.AECField == "001")
			{
				small_field_1.SetCheck(0);
				small_field_2.SetCheck(0);
				small_field_3.SetCheck(3);
			}
			else if(xGen.AECField == "100")
			{
				small_field_1.SetCheck(0);
				small_field_2.SetCheck(2);
				small_field_3.SetCheck(0);
			}
			small_expmAs_value = xGen.expmAs;
			small_AECDens_value = xGen.AECDens;
			small_AECScr_value = xGen.AECScr;

			SetDlgItemText(IDC_EDIT4,xGen.kVp);			//값 출력하기
			SetDlgItemText(IDC_EDIT5,xGen.tubeCurmA);
			SetDlgItemText(IDC_EDIT6,xGen.expTimems);
			bSize = "L";
		}
			else if(bSize == "M")					//사이즈 판별
		{
			if(xGen.AEC == "1")						//aec 판별
			{
				med_aec_combo_value = "1";
				med_aec_combo.SetCurSel(0);
			}
			else
			{
				med_aec_combo_value = "0";
				med_aec_combo.SetCurSel(1);
			}
			if(xGen.AECField == "111")			//aec_field값 판별
			{
				med_field_1.SetCheck(1);
				med_field_2.SetCheck(1);
				med_field_3.SetCheck(1);
			}
			else if(xGen.AECField == "101")
			{
				med_field_1.SetCheck(0);
				med_field_2.SetCheck(1);
				med_field_3.SetCheck(1);
			}
			else if(xGen.AECField == "110")
			{
				med_field_1.SetCheck(1);
				med_field_2.SetCheck(1);
				med_field_3.SetCheck(0);
			}
			else if(xGen.AECField == "010")
			{
				med_field_1.SetCheck(1);
				med_field_2.SetCheck(0);
				med_field_3.SetCheck(0);
			}
			else if(xGen.AECField == "000")
			{
				med_field_1.SetCheck(0);
				med_field_2.SetCheck(0);
				med_field_3.SetCheck(0);
			}
			else if(xGen.AECField == "001")
			{
				med_field_1.SetCheck(0);
				med_field_2.SetCheck(0);
				med_field_3.SetCheck(3);
			}
			else if(xGen.AECField == "100")
			{
				med_field_1.SetCheck(0);
				med_field_2.SetCheck(2);
				med_field_3.SetCheck(0);
			}
			med_expmAs_value = xGen.expmAs;
			med_AECDens_value = xGen.AECDens;
			med_AECScr_value = xGen.AECScr;
			SetDlgItemText(IDC_EDIT7,xGen.kVp);				//값 출력하기
			SetDlgItemText(IDC_EDIT8,xGen.tubeCurmA);
			SetDlgItemText(IDC_EDIT9,xGen.expTimems);
			bSize = "C";
		}
			else if(bSize == "L")					//사이즈 판별
		{
			if(xGen.AEC == "1")						//aec 판별
			{
				large_aec_combo_value = "1";
				large_aec_combo.SetCurSel(0);		
			}
			else
			{
				large_aec_combo_value = "0";
				large_aec_combo.SetCurSel(1);
			}
			if(xGen.AECField == "111")				//aec_field값 판별
			{
				large_field_1.SetCheck(1);
				large_field_2.SetCheck(1);
				large_field_3.SetCheck(1);
			}
			else if(xGen.AECField == "101")
			{
				large_field_1.SetCheck(0);
				large_field_2.SetCheck(1);
				large_field_3.SetCheck(1);
			}
			else if(xGen.AECField == "110")
			{
				large_field_1.SetCheck(1);
				large_field_2.SetCheck(1);
				large_field_3.SetCheck(0);
			}
			else if(xGen.AECField == "010")
			{
				large_field_1.SetCheck(1);
				large_field_2.SetCheck(0);
				large_field_3.SetCheck(0);
			}
			else if(xGen.AECField == "000")
			{
				large_field_1.SetCheck(0);
				large_field_2.SetCheck(0);
				large_field_3.SetCheck(0);
			}
			else if(xGen.AECField == "001")
			{
				large_field_1.SetCheck(0);
				large_field_2.SetCheck(0);
				large_field_3.SetCheck(3);
			}
			else if(xGen.AECField == "100")
			{
				large_field_1.SetCheck(0);
				large_field_2.SetCheck(2);
				large_field_3.SetCheck(0);
			}
			large_expmAs_value = xGen.expmAs;
			large_AECDens_value = xGen.AECDens;
			large_AECScr_value = xGen.AECScr;
			SetDlgItemText(IDC_EDIT10,xGen.kVp);			//값 출력하기
			SetDlgItemText(IDC_EDIT11,xGen.tubeCurmA);
			SetDlgItemText(IDC_EDIT12,xGen.expTimems);
		}

		}

	}
	catch (CString& )
   {
	  str.Format("disconnct");
	  AfxMessageBox(str);
   }
}



void CDB_1Dlg::OnCbnSelchangeCombo2()				//pos값 변경시
{
	UpdateData();									//pos변경값 불러오기						
	CString  wc;
	CString str;
	pos_value = pos_combo_value;					//pos값 저장
	
	pos_id();			//pos_id_value 출력 sql 다 포함		id값 구하기 
	gener();		//pos_id_value 출력 sql 다 포함			id에 맞는 gen값 불러오기
		
}



void CDB_1Dlg::OnCbnSelchangeCombo3()				//aec값
{
	UpdateData();
	if(child_aec_value == "OFF")
	{
		child_aec_combo_value = "1";
	}
	else
	{
		child_aec_combo_value = "0";
	}
}


void CDB_1Dlg::OnCbnSelchangeCombo4()			//aec값
{
	UpdateData();
	if(small_aec_value == "OFF")
	{
		small_aec_combo_value = "1";
	}
	else
	{
		small_aec_combo_value = "0";
	}
}


void CDB_1Dlg::OnCbnSelchangeCombo5()				//aec값
{
	UpdateData();
	if(med_aec_value == "OFF")
	{
		med_aec_combo_value = "1";
	}
	else
	{
		med_aec_combo_value = "0";
	}
}


void CDB_1Dlg::OnCbnSelchangeCombo6()				//aec값
{
	UpdateData();
	if(large_aec_value == "OFF")
	{
		large_aec_combo_value = "1";
	}
	else
	{
		large_aec_combo_value = "0";
	}
}

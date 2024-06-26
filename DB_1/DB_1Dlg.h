
// DB_1Dlg.h : 헤더 파일
//

#pragma once
#pragma comment(lib,"sqlite3.lib")
#include "sqlite3.h"
#include "DXDBSqlite.h"
#include "afxwin.h"







// CDB_1Dlg 대화 상자
class CDB_1Dlg : public CDialogEx
{
// 생성입니다.
public:
	CDB_1Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.
	BOOL m_bCheck_HFGconnect, m_bDBConnect, m_bCheck_HFGRX, m_bLDR, m_bPatDBConnect, m_bAdrDBConnect;

	CString m_strDBPath, m_strHFGRXMsg, m_strLANMsg, m_strDBMsg, m_strLDRMsg;
	CString strFolderPath;
	DXDBSqlite*       m_pDb;
	DXDBSqlite*       m_pAprDb;
	CButton *pCheck1;
	CButton *pCheck2;
	

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DB_1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;
	int m_nxGenId;	

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	bool openDB();
public:
	afx_msg void OnBnClickedButton1();		//db 경로 찾기 버튼 클릭
	afx_msg void detCh(UINT uID);			//detch값 변경하기	
	
	void ConnectDB(void);			//   db 연결
	void exam_combox();				//exam   콤보상자 값 추가
	void pos_combox();				//exam값에 맞는pos 콤보상자 값 추가
	void pos_id();					//exam값과 pos 갑에 해당하는 id값 출력
	void gener();					//pos 콤보상자 값
	void update();					//값 업데이트 하기
private:
	CString m_strExamination, m_strPosition;

public:

	CEdit m_path;			
	afx_msg void OnBnClickedButton2();		//update 과정
	CComboBox exam_1;
	CComboBox pos_1;
	CString exam_combo_value;
	afx_msg void OnCbnSelchangeCombo1();	//exam값 변경하기
	CString pos_combo_value;
	afx_msg void OnCbnSelchangeCombo2();	//pos값 변경하기
	CComboBox child_aec_combo;
	CComboBox small_aec_combo;
	CComboBox med_aec_combo;
	CComboBox large_aec_combo;
	
	CEdit child_kv_edit;
	CEdit child_ma_edit;
	CEdit child_time_edit;
	CEdit small_kv_edit;
	CEdit small_ma_edit;
	CEdit small_time_edit;
	CEdit med_kv_edit;
	CEdit med_ma_edit;
	CEdit med_time_edit;
	CEdit large_ma_edit;
	CEdit large_kv_edit;
	CEdit large_time_edit;
	CString child_aec_value;
	CString small_aec_value;
	CString med_aec_value;
	CString large_aec_value;
	afx_msg void OnCbnSelchangeCombo3();		//aec값
	afx_msg void OnCbnSelchangeCombo4();		//aec값
	afx_msg void OnCbnSelchangeCombo5();		//aec값
	afx_msg void OnCbnSelchangeCombo6();		//aec값
	CButton child_field_1;
	CButton child_field_2;
	CButton child_field_3;
	CButton small_field_1;
	CButton small_field_2;
	CButton small_field_3;
	CButton med_field_1;
	CButton med_field_2;
	CButton med_field_3;
	CButton large_field_1;
	CButton large_field_2;
	CButton large_field_3;
};

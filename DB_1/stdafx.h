
// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 및 프로젝트 관련 포함 파일이 
// 들어 있는 포함 파일입니다.

#pragma once

#ifndef _SECURE_ATL
#define _SECURE_ATL 1
#endif

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // 일부 CString 생성자는 명시적으로 선언됩니다.

// MFC의 공통 부분과 무시 가능한 경고 메시지에 대한 숨기기를 해제합니다.
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC 핵심 및 표준 구성 요소입니다.
#include <afxext.h>         // MFC 확장입니다.


#include <afxdisp.h>        // MFC 자동화 클래스입니다.

extern CString exam_value;
extern CString pos_value;

extern CString child_expmAs_value;
extern CString child_AECDens_value;
extern CString child_AECScr_value;

extern CString small_expmAs_value;
extern CString small_AECDens_value;
extern CString small_AECScr_value;

extern CString med_expmAs_value;
extern CString med_AECDens_value;
extern CString med_AECScr_value;

extern CString large_expmAs_value;
extern CString large_AECDens_value;
extern CString large_AECScr_value;

extern CString child_aec_combo_value;			//전역변수 설정
extern CString small_aec_combo_value;
extern CString med_aec_combo_value;
extern CString large_aec_combo_value;

extern CString child_field_value;
extern CString small_field_value;
extern CString med_field_value;
extern CString large_field_value;

extern CString pos_id_value;
extern int pos_id_value_int;

extern CString detCh_change;


extern CString kv_change1;
extern CString kv_change2;
extern CString kv_change3;
extern CString kv_change4;

extern CString ma_change1;
extern CString ma_change2;
extern CString ma_change3;
extern CString ma_change4;

extern CString time_change1;
extern CString time_change2;
extern CString time_change3;
extern CString time_change4;



#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // Internet Explorer 4 공용 컨트롤에 대한 MFC 지원입니다.
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // Windows 공용 컨트롤에 대한 MFC 지원입니다.
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // MFC의 리본 및 컨트롤 막대 지원









#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif



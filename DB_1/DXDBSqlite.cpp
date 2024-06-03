#include "StdAfx.h"
#include "DXDBSqlite.h"
#include<ctime>
#include<string>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#pragma comment(lib, "sqlite3.lib")


DXDBSqlite::DXDBSqlite(void)
{
	m_pDb = NULL;
}


DXDBSqlite::~DXDBSqlite(void)
{
	Disconnect();
}

BOOL DXDBSqlite::Connect(LPCTSTR dbName, LPCTSTR user, LPCTSTR pwd)		//db랑 연결
{
   CString  dbPath;
   dbPath.Format(_T("%s"),dbPath);		//경로

   getDBPath(dbName, dbPath);	//경로 복사

   if (sqlite3_open(dbPath, &m_pDb) == SQLITE_OK)	//존재시 오픈
   {
      setBusyHandler(m_pDb);		
      return TRUE;
   }
   m_pDb = NULL;
   return FALSE;
}

void DXDBSqlite::getDBPath(LPCTSTR dbName, CString& dbPath)			//db경로 불러오기
{
   if (!_dbDir.IsEmpty())
      dbPath.Format(_T("%s\\%s.db"), _dbDir, dbName);
   else
      dbPath = dbName;
}

int busy_handler(void*, int )
{
   Sleep(1);
   return TRUE;    
}

void DXDBSqlite::setBusyHandler(sqlite3* pdb)
{
   sqlite3_busy_handler(pdb, busy_handler, NULL);
}

void DXDBSqlite::Disconnect()			//연결 종료
{
   if (m_pDb != NULL) 
   {
      if (sqlite3_close(m_pDb) == SQLITE_OK) 
      {
         m_pDb = NULL;
         return;
      }
   }
   else
      return ;


   CString  msg;
   msg.Format(_T("disconnect"));
   throw msg;
}

BOOL DXDBSqlite::IsConnValid() const
{
   return (m_pDb != NULL);
}

void DXDBSqlite::close(void *pStmt)			//닫기
{

   if (sqlite3_finalize((sqlite3_stmt*)pStmt) == SQLITE_OK)
      return;


   CString  msg;
   msg.Format(_T("close"));
   throw msg;
}


void* DXDBSqlite::OpenPos_id(LPCTSTR wc)		//pos에 있는 id 값 불러오기

{
   CString  sql = CString(			//select id from pos 
      "SELECT id "
      "FROM pos ") +
      wc;

   return openQuery(sql, _T("Fail"));

}



BOOL DXDBSqlite::queryPos_id(LPCTSTR wc, Pos* ppos)			//pos에 있는 id 값 불러오기
{
	BOOL  bResult;

   sqlite3_stmt *res = (sqlite3_stmt*)OpenPos_id(wc);       // sql 적용
   bResult = FetchPos_id(res, 0, ppos);							//id 값 저장
   close(res);

   return bResult;
}



BOOL DXDBSqlite::FetchPos_id(const void* res, int row, Pos* ppos)     // id만 저장
{
   sqlite3_stmt* pStmt = (sqlite3_stmt*)res;

   int   i = 0;
   if (sqlite3_step(pStmt) == SQLITE_ROW)  
   {
      ppos->id =         sqlite3_column_text(pStmt, i++);		
      return TRUE;
   }
   return FALSE;
}





BOOL DXDBSqlite::queryPos_exam(LPCTSTR wc,  Pos_exam* ppos_exam)		//exam 값 불러오기
{
   BOOL  bResult;

   sqlite3_stmt *res = (sqlite3_stmt*)OpenPos_exam(wc);       // sql 적용 , pos에서 중복없는 exam값 불러오기
   bResult = FetchPos_exam(res, 0, ppos_exam);					// 구조체에 exam값 저장
   close(res);		// 닫기

   return bResult;
}


BOOL DXDBSqlite::queryPos_pos(LPCTSTR wc,  Pos_pos* ppos_pos)		//pos값 불러오기
{
   BOOL  bResult;

   sqlite3_stmt *res = (sqlite3_stmt*)OpenPos_pos(wc);       // sql 적용, pos에서 중복없는 pos값 불러오기
   bResult = FetchPos_pos(res, 0, ppos_pos);				// 구조체에 pos값 저장
   close(res);

   return bResult;
}


void* DXDBSqlite::OpenPos_exam(LPCTSTR wc)			//pos에서 중복없는 exam값 불러오기

{
   CString  sql = CString(
      "SELECT DISTINCT exam "			//select DISTINCT exam from pos
      "FROM pos ") +
      wc;

   return openQuery(sql, _T("Fail"));

}


void* DXDBSqlite::OpenPos_pos(LPCTSTR wc)			//pos에서 중복없는 pos값 불러오기

{
   CString  sql = CString(
      "SELECT DISTINCT pos "				//select DISTINCT pos from pos where exam 값
      "FROM pos ") +
      wc;

   return openQuery(sql, _T("Fail"));

}


BOOL DXDBSqlite::FetchPos_exam(const void* res, int row, Pos_exam* ppos_exam)      // 콤보상자에 exam값만 호출하기
{
   sqlite3_stmt* pStmt = (sqlite3_stmt*)res;

   int   i = 0;
   CString ex;
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam1 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam2 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam3 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam4 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam5 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam6 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam7 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam8 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam9 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam10 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam11 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam12 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam13 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam14 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam15 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam16 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam17 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam18 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam19 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam20 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam21 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam22 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam23 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam24 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam25 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam26 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam27 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam28 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam29 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam30 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam31 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam32 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam33 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam34 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam35 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam36 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam37 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam38 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam39 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam40 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam41 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam42 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam43 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam44 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam45 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam46 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam47 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam48 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam49 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam50 =         sqlite3_column_text(pStmt, i);
   }
   if (sqlite3_step(pStmt) == SQLITE_ROW)
   {
	   ppos_exam->exam51 =         sqlite3_column_text(pStmt, i);
   }
   return FALSE;
}


BOOL DXDBSqlite::FetchPos_pos(const void* res, int row, Pos_pos* ppos_pos)      // 콤보상자에 pos값만 출력하기
{
   sqlite3_stmt* pStmt = (sqlite3_stmt*)res;
   int   i = 0;
   CString ex;

   if (sqlite3_step(pStmt) == SQLITE_ROW)  
   {
      ppos_pos->pos1 =         sqlite3_column_text(pStmt, i);
   }
   ex = ppos_pos->pos1;
   if(ex == "")
	   return FALSE;
   if (sqlite3_step(pStmt) == SQLITE_ROW)  
   {
      ppos_pos->pos2 =         sqlite3_column_text(pStmt, i);
	  
   }
   ex = ppos_pos->pos2;
   if(ex == "")
	   return FALSE;
   if (sqlite3_step(pStmt) == SQLITE_ROW)  
   {
      ppos_pos->pos3 =         sqlite3_column_text(pStmt, i);
	  
   }
   ex = ppos_pos->pos3;
   if(ex == "")
	   return FALSE;
   if (sqlite3_step(pStmt) == SQLITE_ROW)  
   {
      ppos_pos->pos4 =         sqlite3_column_text(pStmt, i);
	  
   }
   ex = ppos_pos->pos4;
   if(ex == "")
	   return FALSE;
   if (sqlite3_step(pStmt) == SQLITE_ROW)  
   {
      ppos_pos->pos5 =         sqlite3_column_text(pStmt, i);

   }
   ex = ppos_pos->pos5;
   if(ex == "")
	   return FALSE;
   if (sqlite3_step(pStmt) == SQLITE_ROW)  
   {
      ppos_pos->pos6 =         sqlite3_column_text(pStmt, i);
   }
   ex = ppos_pos->pos6;
   if(ex == "")
	   return FALSE;
   if (sqlite3_step(pStmt) == SQLITE_ROW)  
   {
      ppos_pos->pos7 =         sqlite3_column_text(pStmt, i);
	  
   }
   ex = ppos_pos->pos7;
   if(ex == "")
	   return FALSE;
   if (sqlite3_step(pStmt) == SQLITE_ROW)  
   {
      ppos_pos->pos8 =         sqlite3_column_text(pStmt, i);
   }
   ex = ppos_pos->pos8;
   if(ex == "")
	   return FALSE;
   if (sqlite3_step(pStmt) == SQLITE_ROW)  
   {
      ppos_pos->pos9 =         sqlite3_column_text(pStmt, i);
   }
   ex = ppos_pos->pos9;
   if(ex == "")
	   return FALSE;
   if (sqlite3_step(pStmt) == SQLITE_ROW)  
   {
      ppos_pos->pos10 =         sqlite3_column_text(pStmt, i);
   }
   ex = ppos_pos->pos10;
   if(ex == "")
	   return FALSE;
}

BOOL DXDBSqlite::queryXGen(LPCTSTR wc, XGen* pXGen)		//pos에 있는 id 값 불러오기
{
   BOOL  bResult;

   sqlite3_stmt*   res = (sqlite3_stmt*)OpenXGen(wc);			//sql문
   bResult = FetchXGen(res, 0, pXGen);							// 값 pXGen에 저장하기
   close(res);   // db 닫기

   return bResult;
}


void* DXDBSqlite::OpenXGen(LPCTSTR wc)			// gen에서 값 가져오기

{
   CString  sql = CString(
      "SELECT id,bSize,detCh,kVp,tubeCurmA,expTimems,expmAs,AEC,AECField,AECDens,AECScr,SID,posId "
      "FROM generator ") +				
      wc;							//where posid = ...

   return openQuery(sql, _T("Fail"));
}

BOOL DXDBSqlite::FetchXGen(const void* res, int row, XGen* pXGen)		// 값 pXGen에 저장하기
{
   

   sqlite3_stmt* pStmt = (sqlite3_stmt*)res;

   int   i = 0;
   if (sqlite3_step(pStmt) == SQLITE_ROW)				//size등 해당 값 불러오기
   {
	  pXGen->id         = sqlite3_column_text(pStmt, i++);
	  pXGen->bSize      = sqlite3_column_text(pStmt, i++);
      pXGen->detCh      = sqlite3_column_text(pStmt, i++);		//  db에서 받아옴 ->이동하면서
      pXGen->kVp        = sqlite3_column_text(pStmt, i++);		//  db에서 받아옴 ->이동하면서
      pXGen->tubeCurmA  = sqlite3_column_text(pStmt, i++);
      pXGen->expTimems  = sqlite3_column_text(pStmt, i++);
	  pXGen->expmAs     = sqlite3_column_text(pStmt, i++);
      pXGen->AEC        = sqlite3_column_text(pStmt, i++);
      pXGen->AECField   = sqlite3_column_text(pStmt, i++);
	  pXGen->AECDens    = sqlite3_column_text(pStmt, i++);
      pXGen->AECScr     = sqlite3_column_text(pStmt, i++);
      pXGen->SID_DB        = sqlite3_column_text(pStmt, i++);
	  pXGen->posId		= sqlite3_column_text(pStmt, i++);
      return TRUE;
   }
   return FALSE;
}



void DXDBSqlite::updateGenerator_C(const XGen* pXGen)    //child 업데이트 부분			
{
   CString     sql;
   XGen        xGenIns;
   CTime     curtime;
   curtime = CTime::GetCurrentTime();   // 시간
   CString	   csTime;
   csTime.Format(_T("%4d-%02d-%02d %02d:%02d:%02d"), curtime.GetYear(), curtime.GetMonth(), curtime.GetDay(), curtime.GetHour(), curtime.GetMinute(), curtime.GetSecond());  // 시간 관련
   CString bSize = "C";

   EmptyToNullXGen(pXGen, &xGenIns);    // pXGen->xGenIns에 값을 복사

   sql.Format(_T("UPDATE generator SET "
      "detch='%s',"
      "kvp=%s,"
      "tubecurma=%s,"
      "exptimems=%s,"
	  "expmas=%s,"
      "aec='%s',"
      "aecfield='%s',"
	  "aecdens=%s,"
	  "aecscr='%s',"
      "insdt='%s'"
      "WHERE bSize='%s' AND posId = '%s'"),
      xGenIns.detCh,
      xGenIns.kVp,
      xGenIns.tubeCurmA,
      xGenIns.expTimems,
	  child_expmAs_value,
      xGenIns.AEC,
      xGenIns.AECField,
	  child_AECDens_value,
      child_AECScr_value,
	  csTime,
	  bSize,
      pos_id_value);	//  where id = 값pos_id_value

   save_exec(sql, _T("Failed to update"));
}

void DXDBSqlite::updateGenerator_S(const XGen* pXGen)     //small 업데이트 부분
{
   CString     sql;
   XGen        xGenIns;
   CTime     curtime;
   curtime = CTime::GetCurrentTime();   // 시간
   CString	   csTime;
   csTime.Format(_T("%4d-%02d-%02d %02d:%02d:%02d"), curtime.GetYear(), curtime.GetMonth(), curtime.GetDay(), curtime.GetHour(), curtime.GetMinute(), curtime.GetSecond());  // 시간 관련
   CString bSize = "S";

   EmptyToNullXGen(pXGen, &xGenIns);    // pXGen->xGenIns에 값을 복사

   sql.Format(_T("UPDATE generator SET "
      "detch='%s',"
      "kvp=%s,"
      "tubecurma=%s,"
      "exptimems=%s,"
	  "expmas=%s,"
      "aec='%s',"
      "aecfield='%s',"
	  "aecdens=%s,"
	  "aecscr='%s',"
      "insdt='%s'"
      "WHERE bSize='%s' AND posId = '%s'"),
      xGenIns.detCh,
      xGenIns.kVp,
      xGenIns.tubeCurmA,
      xGenIns.expTimems,
	  small_expmAs_value,
      xGenIns.AEC,
      xGenIns.AECField,
	  small_AECDens_value,
      small_AECScr_value,
	  csTime,
	  bSize,
      pos_id_value);	//  where id = 값pos_id_value

   save_exec(sql, _T("Failed to update"));
}

void DXDBSqlite::updateGenerator_M(const XGen* pXGen)     //med 업데이트 부분
{
   CString     sql;
   XGen        xGenIns;
   CTime     curtime;
   curtime = CTime::GetCurrentTime();   // 시간
   CString	   csTime;
   csTime.Format(_T("%4d-%02d-%02d %02d:%02d:%02d"), curtime.GetYear(), curtime.GetMonth(), curtime.GetDay(), curtime.GetHour(), curtime.GetMinute(), curtime.GetSecond());  // 시간 관련
   CString bSize = "M";

   EmptyToNullXGen(pXGen, &xGenIns);    // pXGen->xGenIns에 값을 복사

   sql.Format(_T("UPDATE generator SET "
      "detch='%s',"
      "kvp=%s,"
      "tubecurma=%s,"
      "exptimems=%s,"
	  "expmas=%s,"
      "aec='%s',"
      "aecfield='%s',"
	  "aecdens=%s,"
	  "aecscr='%s',"
      "insdt='%s'"
      "WHERE bSize='%s' AND posId = '%s'"),
      xGenIns.detCh,
      xGenIns.kVp,
      xGenIns.tubeCurmA,
      xGenIns.expTimems,
	  med_expmAs_value,
      xGenIns.AEC,
      xGenIns.AECField,
	  med_AECDens_value,
      med_AECScr_value,
	  csTime,
	  bSize,
      pos_id_value);	//  where id = 값pos_id_value

   save_exec(sql, _T("Failed to update"));
}

void DXDBSqlite::updateGenerator_L(const XGen* pXGen)     //large 업데이트 부분
{
   CString     sql;
   XGen        xGenIns;
   CTime     curtime;
   curtime = CTime::GetCurrentTime();   // 시간
   CString	   csTime;
   csTime.Format(_T("%4d-%02d-%02d %02d:%02d:%02d"), curtime.GetYear(), curtime.GetMonth(), curtime.GetDay(), curtime.GetHour(), curtime.GetMinute(), curtime.GetSecond());  // 시간 관련
   CString bSize = "L";

   EmptyToNullXGen(pXGen, &xGenIns);    // pXGen->xGenIns에 값을 복사

   sql.Format(_T("UPDATE generator SET "
      "detch='%s',"
      "kvp=%s,"
      "tubecurma=%s,"
      "exptimems=%s,"
	  "expmas=%s,"
      "aec='%s',"
      "aecfield='%s',"
	  "aecdens=%s,"
	  "aecscr='%s',"
      "insdt='%s'"
      "WHERE bSize='%s' AND posId = '%s'"),
      xGenIns.detCh,
      xGenIns.kVp,
      xGenIns.tubeCurmA,
      xGenIns.expTimems,
	  large_expmAs_value,
      xGenIns.AEC,
      xGenIns.AECField,
	  large_AECDens_value,
      large_AECScr_value,
	  csTime,
	  bSize,
      pos_id_value);	//  where id = 값pos_id_value

   save_exec(sql, _T("Failed to update"));
}

char* DXDBSqlite::escapeString(LPCTSTR from)
{

   return sqlite3_mprintf("%q", from);
}

void DXDBSqlite::EmptyToNullText(LPCTSTR sin, CString& sout)
{
   char* buf;

   if (!isEmpty(sin)) 
   {
      buf = escapeString(sin);
      sout.Format(_T("%s"), buf);
      sqlite3_free(buf);
   }
   else
      sout = "NULL";
}

void DXDBSqlite::save_exec(LPCTSTR sql, LPCTSTR errMsg)

{
   char*    err_msg;

   int   ret;
   if ((ret = sqlite3_exec(m_pDb, sql, NULL, NULL, &err_msg)) == SQLITE_OK)
      return;

   CString  msg;
   msg.Format(_T("%s\n%s: %s"), errMsg, err_msg, sql);
   sqlite3_free(err_msg);
   throw msg;
}

void* DXDBSqlite::openQuery(LPCTSTR sql, LPCTSTR errMsg)
{
   sqlite3_stmt*  pStmt = NULL;
   const char*    pTail = NULL;

   int n = sqlite3_prepare_v2(m_pDb, sql, lstrlen(sql), &pStmt, &pTail);

   if (n == SQLITE_OK)
      return pStmt;


   sqlite3_finalize(pStmt);

   CString  msg;
   msg.Format(_T("%s: %s"), errMsg, sqlite3_errmsg(m_pDb));
   throw msg;
}

BOOL DXDBSqlite::fetchQuery(const void* pVoid, int row, CString* pData, int nData)
{

   IsConnValid();
   CString str;

   sqlite3_stmt *pStmt = (sqlite3_stmt*)pVoid;
   int   ret;

   if ((ret = sqlite3_step(pStmt)) == SQLITE_ROW) 
   {
      for (int iCol = 0; iCol < nData; ++iCol) 
      {
         pData[iCol] = sqlite3_column_text(pStmt, iCol);
      }
      return TRUE;
   }

   if (ret == SQLITE_DONE)
      return FALSE;


   sqlite3_finalize(pStmt);
   str.Format(_T("[DB8]-%s"), sqlite3_errmsg(m_pDb));
   throw CString(str);
}
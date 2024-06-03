#if !defined(AFX_DXDBPG_H__88357BEA_240A_4B06_BF10_0A78CB7F1E71__INCLUDED_)
#define AFX_DXDBPG_H__88357BEA_240A_4B06_BF10_0A78CB7F1E71__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif

#include "DXDB.h"
#pragma warning(push,3)
#include "sqlite3.h"
#pragma warning(pop)


class DXDBSqlite :
	public DXDB
{
public:
	DXDBSqlite(void);
	virtual ~DXDBSqlite(void);


	BOOL              Connect(LPCTSTR db, LPCTSTR user, LPCTSTR pwd);			//db랑 연결
	void              Disconnect();												//db랑 연결 해제
	BOOL              IsConnValid() const;
	void              getDBPath(LPCTSTR dbName, CString& dbPath);				////db랑 경로
	char*             escapeString(LPCTSTR from);
	void              EmptyToNullText(LPCTSTR sin, CString& sout);

	void*             OpenPos_id(LPCTSTR wc = NULL);							//pos에 있는 id 값 불러오기
	BOOL              FetchPos_id(const void* respg, int row, Pos* ppos);		// id만 저장
	BOOL              queryPos_id(LPCTSTR wc, Pos* ppos);						//pos에 있는 id 값 불러오기



	void*             OpenPos_exam(LPCTSTR wc = NULL);							//pos에서 중복없는 exam값 불러오기
	BOOL              FetchPos_exam(const void* respg, int row, Pos_exam* ppos_exam);	// 콤보상자에 exam값만 호출하기
	BOOL			  queryPos_exam(LPCTSTR wc, Pos_exam* ppos_exam);				//exam 값 불러오기

	void*             OpenPos_pos(LPCTSTR wc = NULL);								//pos에서 중복없는 pos값 불러오기
	BOOL              FetchPos_pos(const void* respg, int row, Pos_pos* ppos_pos);	// 콤보상자에 pos값만 호출하기
	BOOL			  queryPos_pos(LPCTSTR wc, Pos_pos* ppos_pos);					//pos 값 불러오기


	void*             OpenXGen(LPCTSTR wc = NULL);									// gen에서 값 가져오기	
	BOOL              FetchXGen(const void *respg, int row, XGen* pXGen);			// 값 pXGen에 저장하기
	BOOL              queryXGen(LPCTSTR wc, XGen* pXGen);							//pos에 있는 id 값 불러오기
	void              updateGenerator_C(const XGen* pXGen);							//child값  업데이트
	void              updateGenerator_S(const XGen* pXGen);							//small값  업데이트
	void              updateGenerator_M(const XGen* pXGen);							//med값  업데이트
	void              updateGenerator_L(const XGen* pXGen);							//large값  업데이트

	void*             openQuery(LPCTSTR sql, LPCTSTR errMsg);						//쿼리 열기
	BOOL              fetchQuery(const void* respg, int row, CString* pData, int nData);		//저장
	void              close(void *res);				//닫기
	void              save_exec(LPCTSTR sql, LPCTSTR errMsg = NULL);



protected:
   sqlite3*          m_pDb;
   CString           _dbDir;

   void              setBusyHandler(sqlite3* pdb);

};

#endif
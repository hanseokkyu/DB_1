#if !defined(AFX_DXDB_H__85DDA5F1_F9A9_459F_BDBF_4D8818D93AA3__INCLUDED_)
#define AFX_DXDB_H__85DDA5F1_F9A9_459F_BDBF_4D8818D93AA3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif

#pragma warning(disable: 4100)


class Exam
{
public:
   CString  id;
   CString  exam;
   CString  anaRgn;
   CString  bPart;
};

class Pos_exam       //pos에 exam 이름
{
public:
	CString exam1;
	CString exam2;
	CString exam3;
	CString exam4;
	CString exam5;
	CString exam6;
	CString exam7;
	CString exam8;
	CString exam9;
	CString exam10;
	CString exam11;
	CString exam12;
	CString exam13;
	CString exam14;
	CString exam15;
	CString exam16;
	CString exam17;
	CString exam18;
	CString exam19;
	CString exam20;
	CString exam21;
	CString exam22;
	CString exam23;
	CString exam24;
	CString exam25;
	CString exam26;
	CString exam27;
	CString exam28;
	CString exam29;
	CString exam30;
	CString exam31;
	CString exam32;
	CString exam33;
	CString exam34;
	CString exam35;
	CString exam36;
	CString exam37;
	CString exam38;
	CString exam39;
	CString exam40;
	CString exam41;
	CString exam42;
	CString exam43;
	CString exam44;
	CString exam45;
	CString exam46;
	CString exam47;
	CString exam48;
	CString exam49;
	CString exam50;
	CString exam51;
	CString exam52;
};

class Pos_pos      //pos에 pos 값
{
public:
	CString  pos1;
	CString  pos2;
	CString  pos3;
	CString  pos4;
	CString  pos5;
	CString  pos6;
	CString  pos7;
	CString  pos8;
	CString  pos9;
	CString  pos10;
};



class Pos
{
public:
   CString  id;
   CString  pos;
   CString  posDicom;
   CString  exam;
   CString  roi;
   CString  vCode;
   CString  APRId;
};

class XGen
{
public:
   CString  id;
   CString  bSize;
   CString  detCh;
   CString  kVp;
   CString  tubeCurmA;
   CString  expTimems;
   CString  expmAs;
   CString  AEC;
   CString  AECField;
   CString  AECDens;
   CString  AECScr;
   CString  focalSpot;
   CString  SID_DB;
   CString  uGy;
   CString  posId;
};





class DXDB
{
public:
	DXDB(void);
	virtual ~DXDB(void);
	static char patSize[4];
	static char detCh[2];
	virtual void   EmptyToNullText(LPCTSTR sin, CString& sout);
	void           EmptyToNullInt(LPCTSTR sin, CString& sout);

protected:
   void           EmptyToNullXGen(const XGen* pImaXGen, XGen* pImaXGenIns);
};

inline BOOL    isEmpty(LPCTSTR str)
{
   return (lstrlen(str) == 0);
}


#endif
#include "StdAfx.h"
#include "DXDB.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

char DXDB::patSize[4] = { 'C', 'S', 'M', 'L' };
char DXDB::detCh[2] = { 'T', 'W' };


DXDB::DXDB(void)
{
}


DXDB::~DXDB(void)
{
}

void DXDB::EmptyToNullText(LPCTSTR sin, CString& sout)
{
//   //ASSERT(sin != NULL);

   if (!isEmpty(sin))
      sout.Format(_T("%s"),sin);
   else
      sout = "NULL";
}

void DXDB::EmptyToNullInt(LPCTSTR sin, CString& sout)
{
//   //ASSERT(sin != NULL);

   if (!isEmpty(sin))
	   sout.Format(_T("%s"),sin);
   else
      sout = "NULL";
}

void DXDB::EmptyToNullXGen(const XGen* pXGen, XGen* pXGenIns) 
{
   EmptyToNullText(pXGen->detCh,      pXGenIns->detCh);
   EmptyToNullInt(pXGen->kVp,         pXGenIns->kVp);
   EmptyToNullInt(pXGen->tubeCurmA,   pXGenIns->tubeCurmA);
   EmptyToNullInt(pXGen->expTimems,   pXGenIns->expTimems);
   EmptyToNullInt(pXGen->expmAs,	  pXGenIns->expmAs);
   EmptyToNullText(pXGen->AEC,        pXGenIns->AEC);
   EmptyToNullText(pXGen->AECField,   pXGenIns->AECField);
   EmptyToNullText(pXGen->AECDens,   pXGenIns->AECDens);
   EmptyToNullText(pXGen->AECScr,   pXGenIns->AECScr);
   EmptyToNullText(pXGen->posId,   pXGenIns->posId);


}
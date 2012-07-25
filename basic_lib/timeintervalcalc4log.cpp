/********************************************************************
    created:    2012-07-25 00:35:15
    file path:  F:\code\zlib\basic_lib\timeintervalcalc4log.cpp
    author:     zapline<278998871@qq.com>
*********************************************************************/

#include "stdafx.h"
#include "timeintervalcalc4log.h"


void CTimeIntervalCalcDoLog::DoAfterCalc( double dfTimeInterval )
{
    wprintf(L"<PERF>%s(%fms)", m_strLogText, dfTimeInterval);
}

CTimeIntervalCalcDoLog::CTimeIntervalCalcDoLog()
    : m_strLogText(L"")
{

}

void CTimeIntervalCalcDoLog::SetLogText( const CString& strLogText )
{
    m_strLogText = strLogText;
}

CTimeIntervalCalc4Log::CTimeIntervalCalc4Log()
    
{
    SetTimeIntervalCalcDo(&m_Do);
}

CTimeIntervalCalc4Log::~CTimeIntervalCalc4Log()
{

}

void CTimeIntervalCalc4Log::SetLogText( const CString& strLogText )
{
    m_Do.SetLogText(strLogText);
}

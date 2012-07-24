/********************************************************************
    created:    2012-07-23 22:53:49
    file path:  F:\code\zlib\basic_lib\timeinterval.cpp
    author:     zapline<278998871@qq.com>
*********************************************************************/

#include "stdafx.h"
#include "timeinterval.h"
#include <iostream>

void CTimeInterval::Start()
{
    m_dwTimeBegin = ::GetTickCount();
}

BOOL CTimeInterval::Stop( double& dfTimeInterval )
{
    dfTimeInterval = ::GetTickCount() - m_dwTimeBegin;
    return TRUE;
}

CTimeInterval::CTimeInterval()
{
    m_dwTimeBegin = ::GetTickCount();
}

CTimeInterval::~CTimeInterval()
{

}

void CTimeIntervalEx::Start()
{
    if (m_bSuccess)
    {
        m_bSuccess = ::QueryPerformanceCounter(&m_TimeBegin);
    }
}

BOOL CTimeIntervalEx::Stop( OUT double& dfTimeInterval )
{
    if (m_bSuccess)
    {
        LARGE_INTEGER timeEnd = { 0 };
        m_bSuccess = ::QueryPerformanceCounter(&timeEnd);
        if (m_bSuccess)
        {
            dfTimeInterval = double(timeEnd.QuadPart - m_TimeBegin.QuadPart) 
                / m_Freq.QuadPart * 1000.0;
            return TRUE;
        }
    }
    return FALSE;
}

CTimeIntervalEx::CTimeIntervalEx()
{
    m_TimeBegin.QuadPart = 0;
    m_bSuccess = ::QueryPerformanceFrequency(&m_Freq);
}

CTimeIntervalEx::~CTimeIntervalEx()
{

}

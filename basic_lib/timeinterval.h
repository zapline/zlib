/********************************************************************
    created:    2012-07-23 22:53:45
    file path:  F:\code\zlib\basic_lib\timeinterval.h
    author:     zapline<278998871@qq.com>
*********************************************************************/

#include "itimeinterval.h"

#ifndef _TIMEINTERVAL_H_
#define _TIMEINTERVAL_H_

///> 使用GetTickCount计时，一般精度
class CTimeInterval : public ITimeInterval
{
public:
    CTimeInterval();
    virtual ~CTimeInterval();

public:
    virtual BOOL Stop(OUT double& dfTimeInterval);
    virtual void Start();

private:
    DWORD m_dwTimeBegin; ///> 开始计时的时间
};

///> 使用QueryPerformanceCounter计时，高精度
class CTimeIntervalEx : public ITimeInterval
{
public:
    CTimeIntervalEx();
    virtual ~CTimeIntervalEx();

public:
    virtual BOOL Stop(OUT double& dfTimeInterval);
    virtual void Start();

private:
    LARGE_INTEGER m_Freq; ///>时钟频率
    LARGE_INTEGER m_TimeBegin; ///> 开始计时的时间
    BOOL m_bSuccess; ///> 是否成功
};

#endif
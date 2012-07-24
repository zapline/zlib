/********************************************************************
    created:    2012-07-23 22:53:45
    file path:  F:\code\zlib\basic_lib\timeinterval.h
    author:     zapline<278998871@qq.com>
*********************************************************************/

#include "itimeinterval.h"

#ifndef _TIMEINTERVAL_H_
#define _TIMEINTERVAL_H_

///> ʹ��GetTickCount��ʱ��һ�㾫��
class CTimeInterval : public ITimeInterval
{
public:
    CTimeInterval();
    virtual ~CTimeInterval();

public:
    virtual BOOL Stop(OUT double& dfTimeInterval);
    virtual void Start();

private:
    DWORD m_dwTimeBegin; ///> ��ʼ��ʱ��ʱ��
};

///> ʹ��QueryPerformanceCounter��ʱ���߾���
class CTimeIntervalEx : public ITimeInterval
{
public:
    CTimeIntervalEx();
    virtual ~CTimeIntervalEx();

public:
    virtual BOOL Stop(OUT double& dfTimeInterval);
    virtual void Start();

private:
    LARGE_INTEGER m_Freq; ///>ʱ��Ƶ��
    LARGE_INTEGER m_TimeBegin; ///> ��ʼ��ʱ��ʱ��
    BOOL m_bSuccess; ///> �Ƿ�ɹ�
};

#endif
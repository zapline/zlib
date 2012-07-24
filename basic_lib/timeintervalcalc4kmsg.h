/********************************************************************
    created:    2012-07-25 01:02:54
    file path:  F:\code\zlib\basic_lib\timeintervalcalc4kmsg.h
    author:     zapline<278998871@qq.com>
*********************************************************************/

#include "timeintervalcalc.h"

#ifndef _TIMEINTERVALCALC4KMSG_H_
#define _TIMEINTERVALCALC4KMSG_H_

class CTimeIntervalCalcDoKMsg : public ITimeIntervalCalcDo
{
public:
    virtual void DoAfterCalc( double dfTimeInterval );

public:
    CTimeIntervalCalcDoKMsg();
    void SetLogText(const CString& strLogText);
private:
    ///> 日志内容
    CString m_strLogText;
};

class CTimeIntervalCalc4KMsg : public CTimeIntervalCalc
{
public:
    CTimeIntervalCalc4KMsg();
    virtual ~CTimeIntervalCalc4KMsg();

public:
    void SetLogText(const CString& strLogText);

private:
    ///> 计时完毕写日志
    CTimeIntervalCalcDoKMsg m_Do;
};

#endif
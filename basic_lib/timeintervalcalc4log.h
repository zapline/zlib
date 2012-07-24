/********************************************************************
    created:    2012-07-25 00:35:21
    file path:  F:\code\zlib\basic_lib\timeintervalcalc4log.h
    author:     zapline<278998871@qq.com>
*********************************************************************/

#include "timeintervalcalc.h"

#ifndef _TIMEINTERVALCALC4LOG_H_
#define _TIMEINTERVALCALC4LOG_H_

#define PERF_BEGIN() \
    CTimeIntervalCalc4Log* pTimePerfLog = new CTimeIntervalCalc4Log; \

#define PERF_END(fmt, ...) \
    do \
    { \
        CString strTimePerf; \
        strTimePerf.Format(fmt,  __VA_ARGS__); \
        if (pTimePerfLog) \
        { \
            pTimePerfLog->SetLogText(strTimePerf); \
            delete pTimePerfLog; \
            pTimePerfLog = NULL; \
        } \
    } while (false);

class CTimeIntervalCalcDoLog : public ITimeIntervalCalcDo
{
public:
    virtual void DoAfterCalc( double dfTimeInterval );

public:
    CTimeIntervalCalcDoLog();
    void SetLogText(const CString& strLogText);
private:
    ///> 日志内容
    CString m_strLogText;
};

class CTimeIntervalCalc4Log : public CTimeIntervalCalc
{
public:
    CTimeIntervalCalc4Log();
    virtual ~CTimeIntervalCalc4Log();

public:
    void SetLogText(const CString& strLogText);

private:
    ///> 计时完毕写日志
    CTimeIntervalCalcDoLog m_Do;
};

#endif
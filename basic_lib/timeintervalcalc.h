/********************************************************************
* @file      : timeintervalcalc.h
* @author    : zapline <zhuxianzhang@kingsoft.com>
* @date      : 2012/07/24 13:52
* @brief     : 时间间隔计算
*********************************************************************/

#ifndef _TIMEINTERVALCALC_H_
#define _TIMEINTERVALCALC_H_

#include "timeinterval.h"

///> 指定计时后要做什么
class ITimeIntervalCalcDo
{
public:
    virtual void DoAfterCalc(double dfTimeInterval) = 0;
};

class CTimeIntervalCalc
{
public:
    CTimeIntervalCalc(BOOL bHignPrecision = TRUE);
    virtual ~CTimeIntervalCalc();
    void SetTimeIntervalCalcDo(ITimeIntervalCalcDo* piTimeIntervalCalcDo);

protected:
    ///> 指定计时后要做什么
    ITimeIntervalCalcDo* m_piTimeIntervalCalcDo;
    ///> 计时器
    ITimeInterval* m_piTimeInterval;
};

#endif
/********************************************************************
* @file      : timeintervalcalc.h
* @author    : zapline <zhuxianzhang@kingsoft.com>
* @date      : 2012/07/24 13:52
* @brief     : 时间间隔计算
*********************************************************************/

#ifndef _TIMEINTERVALCALC_H_
#define _TIMEINTERVALCALC_H_

#include "timeinterval.h"

class CTimeIntervalCalc
{
public:
    CTimeIntervalCalc(BOOL bHignPrecision = TRUE);
    virtual ~CTimeIntervalCalc();

public:
    virtual void DoBeforeCalc() = 0;
    virtual void DoAfterCalc(double dfTimeInterval) = 0;

protected:
    ITimeInterval* m_iTimeInterval;
};

#endif
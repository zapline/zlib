/********************************************************************
* @file      : timeintervalcalc.h
* @author    : zapline <zhuxianzhang@kingsoft.com>
* @date      : 2012/07/24 13:52
* @brief     : ʱ��������
*********************************************************************/

#ifndef _TIMEINTERVALCALC_H_
#define _TIMEINTERVALCALC_H_

#include "timeinterval.h"

///> ָ����ʱ��Ҫ��ʲô
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
    ///> ָ����ʱ��Ҫ��ʲô
    ITimeIntervalCalcDo* m_piTimeIntervalCalcDo;
    ///> ��ʱ��
    ITimeInterval* m_piTimeInterval;
};

#endif
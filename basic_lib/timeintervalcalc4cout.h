/********************************************************************
* @file      : timeintervalcalc4cout.h
* @author    : zapline <zhuxianzhang@kingsoft.com>
* @date      : 2012/07/24 14:32
* @brief     : 
*********************************************************************/

#include "timeintervalcalc.h"

#ifndef _TIMEINTERVALCALC4COUT_H_
#define _TIMEINTERVALCALC4COUT_H_

class CTimeIntervalCalcDoCout : public ITimeIntervalCalcDo
{
public:
    virtual void DoAfterCalc( double dfTimeInterval );
};

class CTimeIntervalCalc4Cout : public CTimeIntervalCalc
{
public:
    CTimeIntervalCalc4Cout();
    virtual ~CTimeIntervalCalc4Cout();

private:
    CTimeIntervalCalcDoCout m_Do;
};

#endif

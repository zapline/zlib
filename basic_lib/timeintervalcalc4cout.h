/********************************************************************
* @file      : timeintervalcalc4cout.h
* @author    : zapline <zhuxianzhang@kingsoft.com>
* @date      : 2012/07/24 14:32
* @brief     : 
*********************************************************************/

#include "timeintervalcalc.h"

#ifndef _TIMEINTERVALCALC4COUT_H_
#define _TIMEINTERVALCALC4COUT_H_

class CTimeIntervalCalc4Out : public CTimeIntervalCalc
{
public:
    CTimeIntervalCalc4Out();
    virtual ~CTimeIntervalCalc4Out();

public:
    virtual void DoBeforeCalc();
    virtual void DoAfterCalc(double dfTimeInterval);
};

#endif
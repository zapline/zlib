/********************************************************************
* @file      : timeintervalcalc.cpp
* @author    : zapline <zhuxianzhang@kingsoft.com>
* @date      : 2012/07/24 14:03
* @brief     : 
*********************************************************************/

#include "stdafx.h"
#include "timeintervalcalc.h"

CTimeIntervalCalc::CTimeIntervalCalc(BOOL bHignPrecision)
{
    DoBeforeCalc();
    if (bHignPrecision)
    {
        m_iTimeInterval = new CTimeIntervalEx;
    }
    else
    {
        m_iTimeInterval = new CTimeInterval;
    }
    if (m_iTimeInterval)
    {
        m_iTimeInterval->Start();
    }
}

CTimeIntervalCalc::~CTimeIntervalCalc()
{
    if (m_iTimeInterval)
    {
        double dfTime = 0.0;
        if (m_iTimeInterval->Stop(dfTime))
        {
            DoAfterCalc(dfTime);
        }
        delete m_iTimeInterval;
    }
}

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
    if (bHignPrecision)
    {
        m_piTimeInterval = new CTimeIntervalEx;
    }
    else
    {
        m_piTimeInterval = new CTimeInterval;
    }
    if (m_piTimeInterval)
    {
        m_piTimeInterval->Start();
    }
}

CTimeIntervalCalc::~CTimeIntervalCalc()
{
    if (m_piTimeInterval)
    {
        double dfTime = 0.0;
        if (m_piTimeInterval->Stop(dfTime))
        {
            if (m_piTimeIntervalCalcDo)
            {
                m_piTimeIntervalCalcDo->DoAfterCalc(dfTime);
            }
        }
        delete m_piTimeInterval;
    }
}

void CTimeIntervalCalc::SetTimeIntervalCalcDo( 
    ITimeIntervalCalcDo* piTimeIntervalCalcDo )
{
    m_piTimeIntervalCalcDo = piTimeIntervalCalcDo;
}

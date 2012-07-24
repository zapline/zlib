/********************************************************************
* @file      : timeintervalcalc4cout.cpp
* @author    : zapline <zhuxianzhang@kingsoft.com>
* @date      : 2012/07/24 14:36
* @brief     : 
*********************************************************************/

#include "stdafx.h"
#include <iostream>
#include "timeintervalcalc4cout.h"

CTimeIntervalCalc4Cout::CTimeIntervalCalc4Cout()
{
    SetTimeIntervalCalcDo(&m_Do);
}

CTimeIntervalCalc4Cout::~CTimeIntervalCalc4Cout()
{

}

void CTimeIntervalCalcDoCout::DoAfterCalc( double dfTimeInterval )
{
    std::cout<<dfTimeInterval<<std::endl;
}

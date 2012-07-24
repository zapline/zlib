/********************************************************************
* @file      : timeintervalcalc4cout.cpp
* @author    : zapline <zhuxianzhang@kingsoft.com>
* @date      : 2012/07/24 14:36
* @brief     : 
*********************************************************************/

#include "stdafx.h"
#include <iostream>
#include "timeintervalcalc4cout.h"

CTimeIntervalCalc4Out::CTimeIntervalCalc4Out()
{

}

CTimeIntervalCalc4Out::~CTimeIntervalCalc4Out()
{

}

void CTimeIntervalCalc4Out::DoAfterCalc( double dfTimeInterval )
{
    std::cout<<dfTimeInterval<<std::endl;
}

void CTimeIntervalCalc4Out::DoBeforeCalc()
{
    ;
}

/********************************************************************
    created:    2012.4.16  22:28
    file path:  E:\ZLib\basic_lib\test_time.cpp
    author:     zapline<278998871@qq.com>
*********************************************************************/

#include "stdafx.h"
#include "test_include.h"
#include "test_time.h"
#include "time_unit.h"
#include "AppPath.h"

void test_CheckExpired()
{
    CString strPathFile(L"c:\\windows\\system32\\explorer.exe");
    BOOL bExpired = TIME_UNIT::CheckExpired(strPathFile);
    if (bExpired)
        wcout<<strPathFile.GetString()<<L" expired"<<endl;
    else
        wcout<<strPathFile.GetString()<<L" no expired"<<endl;

    strPathFile = CAppPath::Instance().GetCurrentPath();
    bExpired = TIME_UNIT::CheckExpired(strPathFile);
    if (bExpired)
        wcout<<strPathFile.GetString()<<L" expired"<<endl;
    else
        wcout<<strPathFile.GetString()<<L" no expired"<<endl;
}
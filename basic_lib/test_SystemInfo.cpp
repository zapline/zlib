/********************************************************************
    created:    2012.4.17  14:28
    file path:  E:\ZLib\basic_lib\test_SystemInfo.cpp
    author:     zapline<278998871@qq.com>
*********************************************************************/

#include "stdafx.h"
#include "test_include.h"
#include "test_system.h"
#include "SystemInfo.h"

void test_SystemInfo()
{
    cout<<SYSTEM_INFO_N::GetDisplayCount()<<endl;
    cout<<SYSTEM_INFO_N::NumberOfProcessors()<<endl;
}
/********************************************************************
    created:    2012.4.17  12:36
    file path:  E:\ZLib\basic_lib\test_OSVersion.cpp
    author:     zapline<278998871@qq.com>
*********************************************************************/

#include "stdafx.h"
#include "test_include.h"
#include "test_system.h"
#include "OSVersion.h"

void test_OSVersion()
{
    wcout<<COSVersion::Instance().GetOsName().GetString()<<endl;
}
/********************************************************************
    created:    2012.4.16  21:54
    file path:  E:\ZLib\basic_lib\test_AppPath.cpp
    author:     zapline<278998871@qq.com>
*********************************************************************/

#include "stdafx.h"
#include "test_include.h"
#include "test_path.h"
#include "AppPath.h"

void test_AppPath()
{
    wcout<<CAppPath::Instance().GetCurrentDir().GetString()<<endl;
    wcout<<CAppPath::Instance().GetCurrentPath().GetString()<<endl;
}
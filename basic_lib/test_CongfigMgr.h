/********************************************************************
    created:    2012.4.16  12:31
    file path:  E:\ZLib\basic_lib\test_CongfigMgr.h
    author:     zapline<278998871@qq.com>
*********************************************************************/

#pragma once

#include "ConfigMgr.h"
#include "test_include.h"

void test_ConfigMgr()
{
    CConfigMgr::Set_CFG_VALUE_AUTO_ONCE_EXAM(5);
    CConfigMgr::Set_VALUE_AUTO_EXAM(100);
    cout<<CConfigMgr::Get_CFG_VALUE_AUTO_ONCE_EXAM()<<CConfigMgr::Get_VALUE_AUTO_EXAM()<<endl;

}
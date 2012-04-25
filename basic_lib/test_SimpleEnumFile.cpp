/********************************************************************
    created:    2012.4.13  11:48
    file path:  E:\ZLib\basic_lib\test_SimpleEnumFile.cpp
    author:     zapline<278998871@qq.com>
*********************************************************************/

#include "test_file.h"
#include "SimpleEnumFile.h"
#include <iostream>
#include <string>
using namespace std;

void test_SimpleEnumFile()
{
    CSimpleEnumFile SimpleEnum(L"c:\\");
    cout<<SimpleEnum.GetDirCount()<<endl;
    wcout<<SimpleEnum.GetFileFullPath(1).GetString()<<endl;
}
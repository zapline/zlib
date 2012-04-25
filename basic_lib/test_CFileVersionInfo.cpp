/********************************************************************
    created:    2012.4.13  12:04
    file path:  E:\ZLib\basic_lib\test_CFileVersionInfo.cpp
    author:     zapline<278998871@qq.com>
*********************************************************************/

#include "stdafx.h"
#include "FileVersionInfo.h"
#include "test_file.h"
#include <iostream>
using namespace std;

void test_CFileVersionInfo()
{
    CFileVersionInfo FileVer;
    FileVer.Create(L"c:\\windows\\explorer.exe");
    wcout<<FileVer.GetFileVersion().GetString()<<endl;
    wcout<<FileVer.GetCompanyName().GetString()<<endl;
    wcout<<FileVer.GetFileDescription().GetString()<<endl;
}
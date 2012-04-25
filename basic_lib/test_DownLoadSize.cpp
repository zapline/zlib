/********************************************************************
    created:    2012.4.16  21:22
    file path:  E:\ZLib\basic_lib\test_DownLoadSize.cpp
    author:     zapline<278998871@qq.com>
*********************************************************************/

#include "stdafx.h"
#include "test_include.h"
#include "test_string.h"
#include "DownLoadSize.h"


void test_DownLoadSize()
{
    CString strTemp(L"1.1 MB");
    cout<<CDownLoadSize::GetSizeInt(strTemp)<<endl;

    strTemp = L"1.1 KB";
    cout<<CDownLoadSize::GetSizeInt(strTemp)<<endl;

    CDownLoadSize::GetSizeStr(12345, strTemp);
    wcout<<strTemp.GetString()<<endl;
}
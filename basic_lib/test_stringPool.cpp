/********************************************************************
    created:    2012.4.25  15:04
    file path:  E:\zlib\basic_lib\test_stringPool.cpp
    author:     zapline<278998871@qq.com>
*********************************************************************/

#include "stdafx.h"
#include "test_string.h"
#include "test_include.h"
#include "StringPool.h"
#include "TinyXmlStringPool.h"
#include "AppPath.h"

void testStringPool()
{
    CStringPool<int, wstring> Pool1;
    Pool1.Add(1, L"2");
    Pool1.Add(3, L"222");
    wcout<<Pool1.Count()<<endl;
    wstring sTemp;
    Pool1.Get(3, sTemp);
    wcout<<sTemp<<endl;

    CTinyXmlStringPool Pool2;
    CStringA strPathFile( CAppPath::Instance().GetCurrentDir() );
    strPathFile += "..\\..\\document\\test_stringpool.xml";
    string sPath = strPathFile;
    Pool2.LoadXmlFile(sPath);
    string sTemp2;
    Pool2.Get(1, sTemp2);
    cout<<sTemp2<<endl;
    Pool2.Get(2, sTemp2);
    cout<<sTemp2<<endl;
}
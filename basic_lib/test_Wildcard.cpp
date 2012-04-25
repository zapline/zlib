/********************************************************************
    created:    2012.4.15  19:23
    file path:  E:\ZLib\basic_lib\test_Wildcard.cpp
    author:     zapline<278998871@qq.com>
*********************************************************************/

#include "stdafx.h"
#include "test_include.h"
#include "test_string.h"
#include "Wildcard.h"


void test_Wildcard()
{
    CWildcard wc;
    wc.SetPattern(L"1.1.*", false);
    cout<<wc.IsMatch(L"1.2.1.1");
    cout<<wc.IsMatch(L"1.1.1.1");
    cout<<wc.IsMatch(L"1.1.2.1");
    cout<<wc.IsMatch(L"1.2.2.1.1.1");
    wc.SetPattern(L"*2.1*", false);
    cout<<wc.IsMatch(L"1.2.1.1");
    cout<<wc.IsMatch(L"1.1.1.1");
    cout<<wc.IsMatch(L"1.1.2.1");
    cout<<wc.IsMatch(L"1.2.2.1.1.1");
}
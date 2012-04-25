/********************************************************************
    created:    2012.4.17  11:11
    file path:  E:\ZLib\basic_lib\test_http.cpp
    author:     zapline<278998871@qq.com>
*********************************************************************/

#include "stdafx.h"
#include "test_include.h"
#include "test_net.h"
#include "URLEncode.h"
#include "HttpHelper.h"

#define MAXSIZE 1024*300

void test_HttpHelper()
{
    CHttpHelper httpHelper;
    CString strURL(L"http://code.ijinshan.com/source/source.html");
    CURLEncode encoder;
    strURL = encoder.URLEncode(strURL);

    char buff[MAXSIZE + 1];
    memset(buff, 0, MAXSIZE + 1);
    BOOL bRet = httpHelper.GetUrlInfo(strURL, buff, MAXSIZE);
    if (bRet)
    {
        CString sUnicode = CA2W(buff, CP_UTF8);
        CStringA strData(sUnicode);
        cout<<strData.GetString()<<endl;
    }
}
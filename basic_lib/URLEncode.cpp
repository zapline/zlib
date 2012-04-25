/********************************************************************
    created:    2012.4.16  14:02
    file path:  e:\ZLib\basic_lib\URLEncode.cpp
    author:     zapline<278998871@qq.com>
*********************************************************************/

#include "stdafx.h"
#include "URLEncode.h"
#include <atlutil.h>


CURLEncode::CURLEncode(void)
{
}


CURLEncode::~CURLEncode(void)
{
}

CString CURLEncode::URLEncode( const wchar_t* lpURL )
{
    CString strTemp;
    TCHAR* pszURLEncode = strTemp.GetBuffer(1024);
    DWORD dwLength = 0;
    AtlEscapeUrl(lpURL, pszURLEncode, &dwLength, 1024);
    if (pszURLEncode != NULL)
    {
        strTemp.ReleaseBuffer(1024);
    }
    else
        strTemp.Empty();

    return strTemp;
}

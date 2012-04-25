/********************************************************************
    created:    2012.4.16  21:19
    file path:  e:\ZLib\basic_lib\DownLoadSize.cpp
    author:     zapline<278998871@qq.com>
*********************************************************************/

#include "stdafx.h"
#include "DownLoadSize.h"


CDownLoadSize::CDownLoadSize(void)
{
}


CDownLoadSize::~CDownLoadSize(void)
{
}

void CDownLoadSize::GetSizeStr(__int64 nSize, CString& str)
{
    float fSize;

    if (nSize > 1024*1024*1024)
    {
        fSize = (float)nSize / (1024*1024*1024);
        str.Format(L"%1.1f GB", fSize);
    }
    else if (nSize > 1024*1024)
    {
        fSize = (float)nSize / (1024*1024);
        str.Format(L"%1.1f MB", fSize);
    }
    else if (nSize > 1024)
    {
        fSize = (float)nSize / 1024;
        str.Format(L"%1.1f KB", fSize);
    }
    else
    {
        str.Format(L"%d B", nSize);
    }
}


__int64 CDownLoadSize::GetSizeInt(CString& str)
{
    // 这里暂时处理比较简单 只支持1.1 MB这种格式
    __int64 iSize = 0;
    int nPos = str.Find(' ');
    double nSize = _wtof(str.Left(nPos));

    str.MakeUpper();
    if (str.Find('G') > 0 || str.Find('g') > 0)
    {
        iSize = static_cast<__int64>(nSize * 1024*1024*1024);
    }
    else if (str.Find('M') > 0 || str.Find('m') > 0)
    {
        iSize = static_cast<__int64>(nSize * 1024*1024);
    }
    else if (str.Find('K') > 0 || str.Find('k') > 0)
    {
        iSize = static_cast<__int64>(nSize * 1024);
    }

    return iSize;
}
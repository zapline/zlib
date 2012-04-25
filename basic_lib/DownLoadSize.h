/********************************************************************
    created:    2012.4.16  21:17
    file path:  e:\ZLib\basic_lib\DownLoadSize.h
    author:     zapline<278998871@qq.com>
*********************************************************************/

#pragma once
class CDownLoadSize
{
public:
    CDownLoadSize(void);
    ~CDownLoadSize(void);

    static void CDownLoadSize::GetSizeStr(__int64 nSize, CString& str);

    static __int64 CDownLoadSize::GetSizeInt(CString& str);
};


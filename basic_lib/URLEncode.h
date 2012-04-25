/********************************************************************
    created:    2012.4.16  14:02
    file path:  e:\ZLib\basic_lib\URLEncode.h
    author:     zapline<278998871@qq.com>
*********************************************************************/

#pragma once
class CURLEncode
{
public:
    CURLEncode(void);
    ~CURLEncode(void);

    static CString URLEncode(const wchar_t* lpURL);
};


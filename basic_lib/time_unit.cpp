/********************************************************************
    created:    2012.4.16  22:25
    file path:  E:\ZLib\basic_lib\time_unit.cpp
    author:     zapline<278998871@qq.com>
*********************************************************************/

#include "stdafx.h"
#include "time_unit.h"

namespace TIME_UNIT
{
    BOOL CheckExpired(CString& strFile, int nHours)
    {
        HANDLE hFile = CreateFile(
            strFile, 
            GENERIC_READ, 
            FILE_SHARE_READ|FILE_SHARE_WRITE,
            NULL,
            OPEN_EXISTING,
            FILE_ATTRIBUTE_NORMAL,
            NULL);
        if (hFile == INVALID_HANDLE_VALUE)
            return TRUE;

        if (GetFileSize(hFile, NULL) == 0)
            return TRUE;

        FILETIME ftCreate, ftModify, ftAccess, ftLocal;
        SYSTEMTIME sysTime, curTime;

        GetLocalTime(&curTime);
        GetFileTime(hFile, &ftCreate, &ftAccess, &ftModify);
        CloseHandle(hFile);

        FileTimeToLocalFileTime(&ftModify, &ftLocal); 
        FileTimeToSystemTime(&ftLocal, &sysTime);

        if (curTime.wYear > sysTime.wYear || curTime.wMonth > sysTime.wMonth)
            return TRUE;

        int nTime = (curTime.wDay - sysTime.wDay) * 24 + (curTime.wHour - sysTime.wHour);
        if ( nTime < nHours)
            return FALSE;

        return TRUE;
    }
}
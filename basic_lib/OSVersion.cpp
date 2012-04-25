/********************************************************************
    created:    2012.4.17  12:17
    file path:  e:\ZLib\basic_lib\OSVersion.cpp
    author:     zapline<278998871@qq.com>
*********************************************************************/

#include "stdafx.h"
#include "OSVersion.h"


COSVersion::COSVersion(void)
{
    ZeroMemory(&m_VersionInfo, sizeof(OSVERSIONINFO));
    m_VersionInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
    GetVersionEx(&m_VersionInfo);
}


COSVersion::~COSVersion(void)
{
}

const OSVERSIONINFO& COSVersion::GetOSVersionInfo()
{
    return m_VersionInfo;
}

BOOL COSVersion::IsWinXp()
{
    return ( (m_VersionInfo.dwMajorVersion == 5)
        && (m_VersionInfo.dwMinorVersion > 0) );
}

BOOL COSVersion::IsWinXpOrLater()
{
    return ( (m_VersionInfo.dwMajorVersion > 5)
        || IsWinXp() );
}

BOOL COSVersion::IsWinVista()
{
    return ( (m_VersionInfo.dwMajorVersion == 6) 
        && (m_VersionInfo.dwMinorVersion == 0) );
}

BOOL COSVersion::IsWinVistaOrLater()
{
    return (m_VersionInfo.dwMajorVersion > 5);
}

BOOL COSVersion::IsWin7()
{
    return ( (m_VersionInfo.dwMajorVersion == 6)
        && (m_VersionInfo.dwMinorVersion == 1) );
}

BOOL COSVersion::IsWin8()
{
    return ( (m_VersionInfo.dwMajorVersion == 6)
        && (m_VersionInfo.dwMinorVersion == 2) );
}

CString COSVersion::GetOsName()
{
    CString strName(L"Unknow");
    if (m_VersionInfo.dwPlatformId == VER_PLATFORM_WIN32_NT)
    {
        if ((m_VersionInfo.dwMajorVersion == 5) && (m_VersionInfo.dwMinorVersion == 0))
        {
            strName = L"Win2000";
        }
        else if ((m_VersionInfo.dwMajorVersion == 5) && (m_VersionInfo.dwMinorVersion > 0))
        {
            strName = L"WinXP";
        }
        else if ((m_VersionInfo.dwMajorVersion == 6) && (m_VersionInfo.dwMinorVersion == 0))
        {
            strName = L"WinVista";
        }
        else if ((m_VersionInfo.dwMajorVersion == 6) && (m_VersionInfo.dwMinorVersion == 1))
        {
            strName = L"Win7";
        }
        else if ((m_VersionInfo.dwMajorVersion == 6) && (m_VersionInfo.dwMinorVersion == 2))
        {
            strName = L"Win8";
        }
    }
    else if (m_VersionInfo.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS)
    {
        if ((m_VersionInfo.dwMajorVersion == 4) && (m_VersionInfo.dwMinorVersion < 90))
        {
            strName = L"Win98";
        }
        if ((m_VersionInfo.dwMajorVersion == 4) && (m_VersionInfo.dwMinorVersion >= 90))
        {
            strName = L"WinMe";
        }
    }
    return strName;
}

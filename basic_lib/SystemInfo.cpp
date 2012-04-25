/********************************************************************
    created:    2012.4.17  14:21
    file path:  E:\ZLib\basic_lib\SystemInfo.cpp
    author:     zapline<278998871@qq.com>
*********************************************************************/

#include "stdafx.h"
#include "SystemInfo.h"

namespace SYSTEM_INFO_N
{
    void GetServicePackLevel(int* major, int* minor) 
    {
        static bool checked_version = false;
        static int service_pack_major = -1;
        static int service_pack_minor = -1;

        if (!major || !minor)
            return;

        if (!checked_version) 
        {
            OSVERSIONINFOEX version_info = {0};
            version_info.dwOSVersionInfoSize = sizeof(version_info);
            GetVersionEx(reinterpret_cast<OSVERSIONINFOW*>(&version_info));
            service_pack_major = version_info.wServicePackMajor;
            service_pack_minor = version_info.wServicePackMinor;
            checked_version = true;
        }

        *major = service_pack_major;
        *minor = service_pack_minor;
    }

    //////////////////////////////////////////////////////////////////////////

    int NumberOfProcessors() 
    {
        SYSTEM_INFO info;
        GetSystemInfo(&info);
        return static_cast<int>(info.dwNumberOfProcessors);
    }

    //////////////////////////////////////////////////////////////////////////

    __int64 AmountOfPhysicalMemory() 
    {
        MEMORYSTATUSEX memory_info;
        memory_info.dwLength = sizeof(memory_info);
        if (!GlobalMemoryStatusEx(&memory_info)) 
        {
            return 0;
        }

        __int64 rv = static_cast<__int64>(memory_info.ullTotalPhys);
        if (rv < 0)
            rv = 0x7FFFFFFFFFFFFFFF;
        return rv;
    }

    //////////////////////////////////////////////////////////////////////////

    __int64 AmountOfFreeDiskSpace(const std::wstring& path) 
    {
        ULARGE_INTEGER available, total, free;
        if (!GetDiskFreeSpaceExW(path.c_str(), &available, &total, &free)) 
        {
            return -1;
        }
        __int64 rv = static_cast<__int64>(available.QuadPart);
        if (rv < 0)
            rv = 0x7FFFFFFFFFFFFFFF;
        return rv;
    }

    //////////////////////////////////////////////////////////////////////////

    void GetOsVersion(
        unsigned int *major_version,
        unsigned int *minor_version
        )
    {
        OSVERSIONINFO info = {0};
        info.dwOSVersionInfoSize = sizeof(info);
        GetVersionEx(&info);

        if (major_version)
            *major_version = info.dwMajorVersion;

        if (minor_version)
            *minor_version = info.dwMinorVersion;
    }

    //////////////////////////////////////////////////////////////////////////

    int GetDisplayCount() 
    {
        return GetSystemMetrics(SM_CMONITORS);
    }

    //////////////////////////////////////////////////////////////////////////

    typedef BOOL (WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);

    BOOL IsX64System()
    {
#ifndef _AMD64_
        BOOL retval = FALSE;
        BOOL bIsWow64 = FALSE;
        BOOL fRetCode;
        LPFN_ISWOW64PROCESS fnIsWow64Process = NULL;

        fnIsWow64Process = (LPFN_ISWOW64PROCESS)GetProcAddress(
            GetModuleHandle(TEXT("kernel32")), "IsWow64Process");
        if (!fnIsWow64Process)
            goto clean0;

        fRetCode = fnIsWow64Process(GetCurrentProcess(), &bIsWow64);
        if (!fRetCode)
            goto clean0;

        retval = bIsWow64;

clean0:
        return retval;
#else
        return TRUE;
#endif
    }
}
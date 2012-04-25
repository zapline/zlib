/********************************************************************
    created:    2012.4.17  14:20
    file path:  E:\ZLib\basic_lib\SystemInfo.h
    author:     zapline<278998871@qq.com>
*********************************************************************/

#pragma once
#include <string>

namespace SYSTEM_INFO_N
{
    // 获得ServicePack的版本
    void GetServicePackLevel(int* major, int* minor);

    // 获得CPU的个数
    int NumberOfProcessors();

    // 获得物理内存的总量
    __int64 AmountOfPhysicalMemory();

    // 获得磁盘空闲的总量
    __int64 AmountOfFreeDiskSpace(const std::wstring& path);

    // 获得操作系统的版本号
    void GetOsVersion(unsigned int *major, unsigned int *minor);

    // 获得显示器的个数
    int GetDisplayCount();

    // 判断是64位操作系统
    BOOL IsX64System();
}
/********************************************************************
    created:    2012.4.17  14:20
    file path:  E:\ZLib\basic_lib\SystemInfo.h
    author:     zapline<278998871@qq.com>
*********************************************************************/

#pragma once
#include <string>

namespace SYSTEM_INFO_N
{
    // ���ServicePack�İ汾
    void GetServicePackLevel(int* major, int* minor);

    // ���CPU�ĸ���
    int NumberOfProcessors();

    // ��������ڴ������
    __int64 AmountOfPhysicalMemory();

    // ��ô��̿��е�����
    __int64 AmountOfFreeDiskSpace(const std::wstring& path);

    // ��ò���ϵͳ�İ汾��
    void GetOsVersion(unsigned int *major, unsigned int *minor);

    // �����ʾ���ĸ���
    int GetDisplayCount();

    // �ж���64λ����ϵͳ
    BOOL IsX64System();
}
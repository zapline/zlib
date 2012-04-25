/********************************************************************
    created:    2012.4.17  14:35
    file path:  E:\ZLib\basic_lib\test_MemoryFile.cpp
    author:     zapline<278998871@qq.com>
*********************************************************************/

#include "stdafx.h"
#include "test_include.h"
#include "test_file.h"
#include "MemoryFile.h"

void test_MemoryFile()
{
    CMemoryFile memFile;
    BYTE s1[] = "12345";
    BYTE s2[] = "aaaaaaaa";
    DWORD dwNum = 5;
    memFile.WriteFile(s1, dwNum, &dwNum);
    cout<< dwNum << endl;

    dwNum = 8;
    memFile.WriteFile(s2, dwNum, &dwNum);
    cout<< dwNum << endl;

    BYTE s3[1024] = { 0 };
    DWORD dwRead = 1024;
    memFile.SetFilePointer(0, FILE_BEGIN);
    memFile.ReadFile(s3, dwRead, &dwRead);
    cout<< (char *)s3 << dwRead << endl;
}
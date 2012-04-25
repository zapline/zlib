/********************************************************************
    created:    2012.4.24  12:20
    file path:  E:\ZLib\basic_lib\test_unzip.cpp
    author:     zapline<278998871@qq.com>
*********************************************************************/

#include "stdafx.h"
#include "test_include.h"
#include "test_unzip.h"
#include "unzip\UnZip.h"

void test_unzip()
{
    wstring sFilePath;
    sFilePath = L"c:\\1.zip";

    HZIP hz = OpenZip((void *)sFilePath.c_str(), 0, 2);
    if( hz == NULL )
    {
        cout<<"Error opening zip file"<<endl;
        return;
    }
    ZIPENTRY ze; 
    int i; 
    if( FindZipItem(hz, L"1.txt", true, &i, &ze) != 0 )
    {
        cout<<"Could not find ziped file"<<endl;
        return;
    }
    DWORD dwSize = ze.unc_size;
    if( dwSize == 0 ) 
    {
        cout<<"File is empty";
        return;
    }
    if ( dwSize > 4096*1024 ) 
    {
        cout<<"File too large";
        return;
    }
    BYTE* pByte = new BYTE[ dwSize + 1 ];
    ZeroMemory(pByte, dwSize + 1);
    int res = UnzipItem(hz, i, pByte, dwSize, 3);
    if( res != 0x00000000 && res != 0x00000600)
    {
        delete[] pByte;
        CloseZip(hz);
        cout<<"Could not unzip file";
        return;
    }
    CloseZip(hz);
    cout<<pByte<<endl;
    delete[] pByte;
}
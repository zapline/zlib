/********************************************************************
    created:    2012.4.5  0:27
    file path:  E:\ZLib\basic_lib\test_aes.h
    author:     zapline<278998871@qq.com>
*********************************************************************/

#include "aes\aes.h"
#include <iostream>
using namespace std;

void testaes()
{
    AES aes;
    const unsigned char sKey[] = "1111111111111111";
    const unsigned char sData[] = "zapline";
    unsigned char sOut[32] = {0};
    unsigned char sOut2[32] = {0};
    aes.SetParameters(128);
    aes.StartEncryption(sKey);
    aes.Encrypt(sData, sOut, 2);

    for (int i = 0; i < 32; i++)
    {
        cout << hex << sOut[i];
    }

    aes.StartDecryption(sKey);
    aes.Decrypt(sOut, sOut2, 2);
    cout << sOut2;
}
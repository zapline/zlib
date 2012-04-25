/********************************************************************
    created:    2012.4.5  18:26
    file path:  E:\ZLib\basic_lib\test_lock.h
    author:     zapline<278998871@qq.com>
*********************************************************************/

#include "lockhelper/LockHelper.h"
#include <iostream>
using namespace std;

int g_i = 0;
CLock g_lock;
void test_lock();

static DWORD WINAPI thread_test(LPVOID lpParam)
{
    for (int i = 0; i < 5; i++)
    {
        g_i++;
        cout << g_i << endl;
    }
    return 0;
}

static DWORD WINAPI thread_test2(LPVOID lpParam)
{
    CObjectLock objLocker( &g_lock );
    for (int i = 0; i < 5; i++)
    {
        g_i++;
        cout << g_i << endl;
    }
    return 0;
}

void thread_create(int method)
{
    HANDLE hThread = NULL;
    if (method == 1)
    {
        hThread = ::CreateThread(
            NULL,
            0,
            thread_test,
            0,
            0,
            NULL);
    }
    else if (method == 2)
    {
        hThread = ::CreateThread(
            NULL,
            0,
            thread_test2,
            0,
            0,
            NULL);
    }
    if (hThread)
    {
        ::CloseHandle(hThread);
    }
}

void test_lock()
{
    for (int j = 0; j < 10; j++)
    {
        thread_create(1);
    }
    Sleep(2000);
    for (int j = 0; j < 10; j++)
    {
        thread_create(2);
    }
}

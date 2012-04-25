/********************************************************************
    created:    2012.4.7  21:36
    file path:  e:\ZLib\basic_lib\ProgressBar.h
    author:     zapline<278998871@qq.com>
*********************************************************************/

#pragma once
#include <windows.h>
#include "BasicObject.h"

class IProgessCallback : public Interface
{
public:
    virtual DWORD GetRealValue() = 0;

    virtual void OnDisplayValue(LPVOID lpData) = 0;

    virtual void OnProgressEnd() = 0;
};

class CProgressBar
{
public:
    CProgressBar(void);
    ~CProgressBar(void);

    void ProgressBegin(HWND hWnd, DWORD dwStart = 0, DWORD dwStartMax = 100);

private:
    static void __stdcall Stub_OnTimerTick(
        HWND hWnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime );

    void OnProgressTimerTick();

    virtual DWORD GetRealValue() = 0;

    virtual void OnDisplayValue(DWORD dwValue) = 0;

    virtual void OnProgressEnd() = 0;

private:
    DWORD m_dwMaxValue;
    DWORD m_dwCurrentValue;
    HWND m_hWnd;
};


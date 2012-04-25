/********************************************************************
    created:    2012.4.7  22:13
    file path:  e:\ZLib\basic_lib\NumberProgressBarTest.h
    author:     zapline<278998871@qq.com>
*********************************************************************/
#pragma once
#include "OperaterProgressBar.h"

class CNumberProgressBarTest : public IProgessCallback
{
public:
    CNumberProgressBarTest(void);
    ~CNumberProgressBarTest(void);

    virtual DWORD GetRealValue();
    virtual void OnDisplayValue(LPVOID lpData);
    virtual void OnProgressEnd();

    void Test();

    COperaterProgressBar m_Bar;
};


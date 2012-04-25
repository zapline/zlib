/********************************************************************
    created:    2012.4.7  21:56
    file path:  e:\ZLib\basic_lib\OperaterProgressBar.h
    author:     zapline<278998871@qq.com>
*********************************************************************/

#pragma once
#include "ProgressBar.h"

class COperaterProgressBar : public CProgressBar
{
public:
    COperaterProgressBar(void);
    ~COperaterProgressBar(void);

    void SetCallback(IProgessCallback *pCallback);

private:
    virtual DWORD GetRealValue();

    virtual void OnDisplayValue(DWORD dwValue);

    virtual void OnProgressEnd();

protected:
    IProgessCallback *m_pCallback;
};


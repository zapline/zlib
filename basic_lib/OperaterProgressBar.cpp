/********************************************************************
    created:    2012.4.7  22:03
    file path:  e:\ZLib\basic_lib\OperaterProgressBar.cpp
    author:     zapline<278998871@qq.com>
*********************************************************************/

#include "OperaterProgressBar.h"

COperaterProgressBar::COperaterProgressBar(void)
    : m_pCallback(NULL)
{
}


COperaterProgressBar::~COperaterProgressBar(void)
{
}

void COperaterProgressBar::SetCallback( IProgessCallback *pCallback )
{
    m_pCallback = pCallback;
}

DWORD COperaterProgressBar::GetRealValue()
{
    if (m_pCallback)
    {
        return m_pCallback->GetRealValue();
    }
    return 0;
}

void COperaterProgressBar::OnDisplayValue( DWORD dwValue )
{
    static char XShow[20] = {'-'};
    static int XStatusN = 0;
    const char XStatus[] = "/-\\|";
    if (m_pCallback)
    {
        static DWORD i = 0;
        DWORD nRealValue = dwValue / 5;
        XShow[nRealValue] = XStatusN++;
        if (nRealValue > 0)
        {
            XShow[nRealValue - 1] = '+';
        }
        XStatusN = XStatusN > 3 ? XStatusN % 4 : XStatusN;
        m_pCallback->OnDisplayValue((LPVOID)XShow);
    }
}

void COperaterProgressBar::OnProgressEnd()
{
    if (m_pCallback)
    {
        m_pCallback->OnProgressEnd();
    }
}

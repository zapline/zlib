/********************************************************************
    created:    2012.4.7  21:42
    file path:  e:\ZLib\basic_lib\ProgressBar.cpp
    author:     zapline<278998871@qq.com>
*********************************************************************/

#include "ProgressBar.h"


CProgressBar::CProgressBar(void)
    : m_dwMaxValue(0)
    , m_dwCurrentValue(0)
    , m_hWnd(NULL)
{
}


CProgressBar::~CProgressBar(void)
{
}

void __stdcall CProgressBar::Stub_OnTimerTick(
    HWND hWnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime )
{
    CProgressBar *pThis = (CProgressBar *)(idEvent);
    pThis->OnProgressTimerTick();
}

void CProgressBar::ProgressBegin(
    HWND hWnd, DWORD dwStart /* = 0 */, DWORD dwStartMax /* = 100 */ )
{
    m_dwMaxValue = dwStartMax;
    m_dwCurrentValue = dwStart;

    m_hWnd = hWnd;
    SetTimer(m_hWnd, (UINT_PTR)this, 100, Stub_OnTimerTick);
}

void CProgressBar::OnProgressTimerTick()
{
    m_dwCurrentValue = GetRealValue();

    if( m_dwCurrentValue >= m_dwMaxValue )
    {
        m_dwCurrentValue = m_dwMaxValue;
        KillTimer(m_hWnd, (UINT_PTR)this);
        OnProgressEnd();
    }

    OnDisplayValue((DWORD)m_dwCurrentValue);
}
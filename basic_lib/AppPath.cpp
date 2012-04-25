/********************************************************************
    created:    2012.4.16  21:46
    file path:  e:\ZLib\basic_lib\AppPath.cpp
    author:     zapline<278998871@qq.com>
*********************************************************************/

#include "stdafx.h"
#include "AppPath.h"


CAppPath::CAppPath(void)
    : m_bInited(FALSE)
{
}


CAppPath::~CAppPath(void)
{
}

void CAppPath::_Init()
{
    if ( !m_bInited )
    {
        TCHAR tszPath[MAX_PATH];
        ::GetModuleFileName( NULL, tszPath, MAX_PATH );
        m_CurrentPath = tszPath;

        int nPos = m_CurrentPath.ReverseFind('\\');
        if (nPos > 0)
            m_CurrentDir = m_CurrentPath.Left(nPos + 1);

        m_bInited = TRUE;
    }
}

CString CAppPath::GetCurrentPath()
{
    _Init();
    return m_CurrentPath;
}

CString CAppPath::GetCurrentDir()
{
    _Init();
    return m_CurrentDir;
}
